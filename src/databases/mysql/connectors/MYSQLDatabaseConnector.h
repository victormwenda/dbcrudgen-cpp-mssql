//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/4/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H
#define DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H


#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

#include "../../sql/connectors/DatabaseConnector.h"
#include "MYSQLDatabaseConnectionParams.h"

namespace dbcrudgen {
    namespace db {
        namespace mysql {
            //
            // MYSQLDatabaseConnector
            // //
            class MYSQLDatabaseConnector : public DatabaseConnector {

            private:
                MYSQLDatabaseConnectionParams connectionParams;
                sql::Driver *driver;
                sql::Connection *connection;
            public:
                explicit MYSQLDatabaseConnector(MYSQLDatabaseConnectionParams &connectionParams)
                        : connectionParams{connectionParams} {

                    connection = nullptr;

                    driver = get_driver_instance();
                }

                MYSQLDatabaseConnectionParams &getConnectionParams() {
                    return connectionParams;
                }


                /**
                * Get the database driver
                * @return
                */
                sql::Driver &getDriver() {
                    if (driver == nullptr) {
                        driver = get_driver_instance();
                    }
                    return *driver;
                }

                /**
                * Get the connection
                * @return
                */
                sql::Connection &getConnection() {
                    return *connection;
                }

                /**
                 * Create a statement
                 * @return
                 */
                sql::Statement &createStatement() {
                    return *connection->createStatement();
                }

                /**
                 * Executes the sql query
                 * @param sql
                 * @return result set
                 */
                sql::ResultSet &executeQuery(const sql::SQLString &sql) {
                    return *createStatement().executeQuery(sql);
                }

                /**
                 * Open database connection
                 * @return true if connected, false otherwise
                 */
                bool open() override {

                    const sql::SQLString &host = connectionParams.getHost();
                    const sql::SQLString &user = connectionParams.getUsername();
                    const sql::SQLString &password = connectionParams.getPassword();
                    const sql::SQLString &schemas = connectionParams.getSchemas();

                    connection = driver->connect(host, user, password);

                    bool connected = connection->isValid();

                    if (connected) {
                        if (schemas != "") {
                            connection->setSchema(schemas);
                        }
                    }

                    return connected;
                }

                /**
                 * Check if connection is open
                 * @return
                 */
                bool isOpen() override {
                    return connection->isValid();
                }

                /**
                 * Close database connection
                 * @return
                 */
                bool close() override {
                    connection->close();
                    return connection->isClosed();
                }

                /**
                 * on Error occurred
                 * @param errorLevel
                 * @param errorMessage
                 * @param logError
                 */
                void onError(const std::string &errorLevel, const std::string &errorMessage, bool logError) override {
                    DatabaseConnector::onError(errorLevel, errorMessage, logError);


                }

                bool getAutoCommit() {
                    return connection->getAutoCommit();
                }

                void enableAutoCommit() {
                    setAutoCommit(true);
                }

                void disableAutoCommit() { setAutoCommit(false); }

                void setAutoCommit(bool autoCommit) {
                    connection->setAutoCommit(autoCommit);
                }

                void clearWarnings() { connection->clearWarnings(); }

                void commit() { return connection->commit(); }

                std::string getCatalog() {
                    return connection->getCatalog();
                }

                std::string getClientInfo() { return connection->getClientInfo(); }

                std::string getClientOption(const std::string &optionName) {
                    return connection->getClientOption(optionName);
                }

                std::string getClientOption(const std::string &optionName, void *optionValue) {
                    connection->getClientOption(optionName, optionValue);
                }

                std::string setClientOption(const std::string &optionName, const std::string &optionValue) {
                    connection->setClientOption(optionName, optionValue);
                }

                std::string setClientOption(const std::string &optionName, void *optionValue) {
                    connection->setClientOption(optionName, optionValue);
                }

                sql::DatabaseMetaData *getDatabaseMetadata() { return connection->getMetaData(); }

                void nativeSQL(const std::string &rawSQL) {
                    connection->nativeSQL(rawSQL);
                }

                void prepareStatement(std::string sql) { connection->prepareStatement(sql); };

                void prepareStatement(std::string sql, int autoGeneratedKeys) {
                    connection->prepareStatement(sql, autoGeneratedKeys);
                };

                void prepareStatement(std::string sql, int *columnIndexes) {
                    connection->prepareStatement(sql, columnIndexes);
                };

                void prepareStatement(std::string sql, int resultSetType, int resultSetConcurrency) {
                    connection->prepareStatement(sql, resultSetType, resultSetConcurrency);
                };

                void prepareStatement(std::string sql, int resultSetType, int resultSetConcurrency,
                                      int resultSetHoldability) {
                    connection->prepareStatement(sql, resultSetType, resultSetConcurrency, resultSetHoldability);
                };

                void prepareStatement(std::string sql, std::string columnNames) {
                    sql::SQLString columnNamesPtr = sql::SQLString{columnNames};
                    connection->prepareStatement(sql, &columnNamesPtr);
                };


                void setReadOnly(bool readOnly) {
                    connection->setReadOnly(readOnly);
                }

                void setHoldability(int holdability) {
                    connection->setHoldability(holdability);
                }

                void releaseSavePoint(sql::Savepoint &savepoint) {
                    connection->releaseSavepoint(&savepoint);
                }

                void rollback() {
                    connection->rollback();

                }

                void rollback(sql::Savepoint &savepoint) {
                    connection->rollback(&savepoint);
                }

                void setSavePoint() { connection->setSavepoint(); }

                void setSavePoint(const std::string &name) {
                    connection->setSavepoint(name);
                }

                void setSchema(const std::string &schema) {
                    connection->setSchema(schema);
                }


                void setTransactionIsolation(sql::transaction_isolation isolation) {
                    connection->setTransactionIsolation(isolation);
                }

                ~MYSQLDatabaseConnector() {
                    if (isOpen()) { close(); }
                }
            };

        }
    }
}


#endif //DBCRUDGEN_CPP_MYSQLDATABASECONNECTOR_H
