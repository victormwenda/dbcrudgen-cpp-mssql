//
// Created by victor on 12/26/20.
//

#ifndef DBCRUDGEN_CPP_MSSQLQUERYEXECUTOR_H
#define DBCRUDGEN_CPP_MSSQLQUERYEXECUTOR_H

#include "MSSQLColBinder.h"
#include "MSSQLResultSet.h"

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class MSSQLQueryExecutor {
            private:
                SQLHDBC hDbc;
                SQLHSTMT hSmt;
            public:

                /**
                 * MSSQL Query Executor
                 */
                MSSQLQueryExecutor() {
                    hDbc = nullptr;
                    hSmt = nullptr;
                }

                /**
                 * MSSQL Query Executor
                 * @param hDbc
                 */
                explicit MSSQLQueryExecutor(const SQLHDBC &hDbc) : hDbc{hDbc} {
                    hSmt = nullptr;
                    createStatementHandle();
                }

                /**
                 * Create statement handle
                 * @return
                 */
                bool createStatementHandle() {
                    SQLRETURN allocReturn = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hSmt);
                    switch (allocReturn) {
                        case SQL_SUCCESS:
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            return true;
                        case SQL_INVALID_HANDLE:
                            return false;
                        case SQL_ERROR:
                            printErrorDiagInfo(SQL_HANDLE_STMT, hDbc, 1);
                            return false;
                        default:
                            std::cerr << "FAILED :: Allocate Statement Handle :: Error code: " << allocReturn
                                      << std::endl;
                            return false;
                    }
                }

                /**
                 * Free statement handle
                 */
                void freeStatementHandle() {
                    SQLFreeHandle(SQL_HANDLE_STMT, hSmt);
                }

                /**
                 * Prepare statement
                 * @param statement
                 * @return
                 */
                bool prepareStatement(const std::string &statement) {
                    auto *query = (SQLWCHAR *) statement.c_str();

                    SQLRETURN prepareStmt = SQLPrepareW(hSmt, query, SQL_NTS);

                    switch (prepareStmt) {
                        case SQL_SUCCESS:
                            return true;
                        case SQL_SUCCESS_WITH_INFO:
                            return true;
                        case SQL_INVALID_HANDLE:
                            return false;
                        case SQL_ERROR:
                            printErrorDiagInfo(SQL_HANDLE_STMT, hSmt, 1);
                            return false;
                        default:
                            std::cerr << "FAILED :: Prepare statement :: " << prepareStmt << std::endl;
                            return false;
                    }

                }

                /**
                 * Print SQL Error
                 * @param handleType
                 * @param sqlHandle
                 * @param recNumber
                 */
                static void printErrorDiagInfo(SQLSMALLINT handleType, SQLHANDLE sqlHandle, SQLSMALLINT recNumber = 1) {
                    SQLWCHAR sqlState[10];
                    SQLINTEGER nativeError;
                    SQLWCHAR messageTxt[256];
                    SQLSMALLINT length;
                    SQLGetDiagRecW(handleType, sqlHandle, recNumber, sqlState, &nativeError, messageTxt,
                                  sizeof(messageTxt), &length);
                    std::cerr << "SQL state: " << sqlState << " Native error: " << nativeError << " Message text: "
                              << messageTxt << std::endl;
                    std::cout << std::endl;
                }

                /**
                 * Execute query
                 * @param sqlQuery
                 */
                void
                execQuery(const std::string &sqlQuery, std::vector<MSSQLColBinder> &colBindings,
                          std::vector<dbcrudgen::db::mssql::MSSQLResultSet> &resultSet) {

                    bool prepStmt = prepareStatement(sqlQuery);

                    if (prepStmt) {
                        SQLRETURN execReturnInt = SQLExecDirectW(hSmt, (SQLWCHAR *) sqlQuery.c_str(), SQL_NTS);

                        switch (execReturnInt) {
                            case SQL_SUCCESS:
                                break;
                            case SQL_SUCCESS_WITH_INFO:
                                break;
                            case SQL_INVALID_HANDLE:
                                break;
                            case SQL_ERROR:
                                printErrorDiagInfo(SQL_HANDLE_STMT, hSmt, 1);
                                break;
                            default:
                                std::cout << "FAILED :: Exec Query : " << execReturnInt << std::endl;
                        }

                        for (MSSQLColBinder &colBinder: colBindings) {
                            SQLRETURN bindColReturnInt = SQLBindCol(hSmt, colBinder.columnIndex,
                                                                    colBinder.dataType,
                                                                    colBinder.columnValue,
                                                                    colBinder.columnValueLength,
                                                                    colBinder.ptrLengthBufferOrIndicator);
                            switch (bindColReturnInt) {
                                case SQL_SUCCESS:
                                    break;
                                case SQL_SUCCESS_WITH_INFO:
                                    break;
                                case SQL_INVALID_HANDLE:
                                    break;
                                case SQL_ERROR:
                                    printErrorDiagInfo(SQL_HANDLE_STMT, hSmt, 1);
                                    break;
                                default:
                                    std::cout << "FAILED :: Bind Column " << colBinder.columnName << std::endl;
                            }
                        }

                        //Fetch data from database
                        while (SQLRETURN fetchReturnInt = SQLFetch(hSmt) == SQL_SUCCESS) {

                            for (MSSQLColBinder &colBinding: colBindings) {

                                //Add fetched data to result set
                                resultSet.emplace_back(
                                        MSSQLResultSet{colBinding.columnIndex, colBinding.columnName,
                                                       colBinding.dataType, colBinding.columnValue});
                            }

                            switch (fetchReturnInt) {
                                case SQL_SUCCESS:
                                    break;
                                case SQL_SUCCESS_WITH_INFO:
                                    break;
                                case SQL_INVALID_HANDLE:
                                    break;
                                case SQL_ERROR:
                                    printErrorDiagInfo(SQL_HANDLE_STMT, hSmt, 1);
                                    break;
                                default:
                                    std::cout << "FAILED :: Cannot fetch data in " << execReturnInt << std::endl;
                            }
                        }

                    }
                }

                ~MSSQLQueryExecutor() {
                    //freeStatementHandle(); - DO NOT free database Handle.
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MSSQLQUERYEXECUTOR_H
