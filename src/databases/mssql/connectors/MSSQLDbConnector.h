//
// Created by victor on 12/26/20.
//

#ifndef DBCRUDGEN_CPP_MSSQLDBCONNECTOR_H
#define DBCRUDGEN_CPP_MSSQLDBCONNECTOR_H

#include "MSSQLDbConnParams.h"
#include <sql.h>
#include <sqlext.h>
#include <cstring>

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class MSSQLDbConnector {
            private:
                SQLHENV hEnv = nullptr;
                SQLHDBC hDbc = nullptr;
                dbcrudgen::db::mssql::MSSQLDbConnParams &connParams;
            public:

                explicit MSSQLDbConnector(dbcrudgen::db::mssql::MSSQLDbConnParams &params) : connParams(params) {
                }

                dbcrudgen::db::mssql::MSSQLDbConnParams &getConnParams() const {
                    return connParams;
                }

                /**
                 * Get database environment handle
                 * @return
                 */
                SQLHENV getHEnv() const {
                    return hEnv;
                }

                /**
                 * Get Database Connection Handle
                 * @return
                 */
                SQLHDBC getHDbc() const {
                    if (hDbc == nullptr) {
                        std::cout << "first check -- null" << std::endl;
                    }
                    return hDbc;
                }

                /**
                 * Allocate environment
                 * @return
                 */
                SQLRETURN allocateEnvironmentHandle() {

                    SQLRETURN allocReturn = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);

                    switch (allocReturn) {
                        case SQL_SUCCESS:
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            return true;
                        case SQL_INVALID_HANDLE:
                            return false;
                        case SQL_ERROR:
                            printErrorDiagInfo(SQL_HANDLE_ENV, hEnv);
                            return false;
                        default:
                            std::cout << "FAILED :: Allocate Environment :: " << allocReturn << std::endl;
                            return false;
                    }

                }

                /**
                 * Allocate environment handle
                 * https://docs.microsoft.com/en-us/sql/odbc/reference/syntax/sqlsetenvattr-function?view=sql-server-ver15
                 * @return
                 */
                bool allocateEnvironment() {

                    SQLRETURN setEnvReturn = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0);

                    switch (setEnvReturn) {
                        case SQL_SUCCESS:
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            return true;
                        case SQL_INVALID_HANDLE:
                            return false;
                        case SQL_ERROR:
                            printErrorDiagInfo(SQL_HANDLE_ENV, hEnv);
                            return false;
                        default:
                            std::cout << "Failed :: Sent Env Attr" << std::endl;
                            return false;
                    }
                }

                /**
                 * Allocate connection handle
                 * @return
                 */
                bool allocateConnectionHandle() {

                    SQLRETURN allocHandle = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

                    switch (allocHandle) {
                        case SQL_SUCCESS:
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            return true;
                        case SQL_INVALID_HANDLE:
                            return false;
                        case SQL_ERROR:
                            printErrorDiagInfo(SQL_HANDLE_DBC, hDbc);
                            return false;
                        default:
                            std::cout << "FAILED :: Set Allocation Handle" << std::endl;
                            return false;
                    }
                }

                bool createConnection() {
                    std::string dbConnStr = getConnParams().getConnStr();
                    SQLCHAR *connStr = (SQLCHAR *) dbConnStr.c_str();
                    SQLRETURN connResult = SQLDriverConnect(hDbc, nullptr, connStr, SQL_NTS, nullptr,
                                                            0, nullptr, SQL_DRIVER_COMPLETE);
                    switch (connResult) {
                        case SQL_SUCCESS:
                        case SQL_SUCCESS_WITH_INFO:
                            return true;
                        case SQL_INVALID_HANDLE:
                        case SQL_ERROR:
                            printErrorDiagInfo(SQL_HANDLE_DBC, hDbc);
                        default:
                            std::cout << "FAILED :: Create Connection" << std::endl;
                            return false;

                    }
                }

                /**
                 * Open database connection
                 * @return
                 */
                bool openConnection() {
                    if (allocateEnvironmentHandle()) {
                        if (allocateEnvironment()) {
                            if (allocateConnectionHandle()) {
                                if (createConnection()) {
                                    return true;
                                }
                            }
                        }
                    }
                    return false;
                }

                /**
                 * Close SQL Server Connection
                 */
                void closeConnection() {
                    disconnect();
                    freeConnectionHandle();
                    freeEnvironmentHandle();
                }

                ~MSSQLDbConnector() {
                    //closeConnection(); -- DO NOT close the connection
                };
            private:

                /**
                 * Print SQL Error
                 * @param handleType
                 * @param sqlHandle
                 * @param recNumber
                 */
                void printErrorDiagInfo(SQLSMALLINT handleType, SQLHANDLE sqlHandle, SQLSMALLINT recNumber = 1) {
                    SQLCHAR sqlState[10];
                    SQLINTEGER nativeError;
                    SQLCHAR messageTxt[256];
                    SQLSMALLINT length;
                    SQLGetDiagRec(handleType, sqlHandle, recNumber, sqlState, &nativeError, messageTxt,
                                  sizeof(messageTxt), &length);
                    std::cerr << "SQL state: " << sqlState << " Native error: " << nativeError << " Message text: "
                              << messageTxt << std::endl;
                }

                void disconnect() {
                    SQLDisconnect(hDbc);
                }

                bool freeConnectionHandle() {
                    if (hDbc != nullptr) {
                        SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
                    }
                    return hDbc == nullptr;
                }

                bool freeEnvironmentHandle() {
                    if (hEnv != nullptr) {
                        SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
                    }
                    return hEnv == nullptr;
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MSSQLDBCONNECTOR_H
