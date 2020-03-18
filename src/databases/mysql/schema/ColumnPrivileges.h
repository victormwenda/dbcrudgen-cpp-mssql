//
// Created by vrwanda on 3/6/20.
//

#ifndef DBCRUDGEN_CPP_COLUMNPRIVILEGES_H
#define DBCRUDGEN_CPP_COLUMNPRIVILEGES_H

#include <string>

namespace dbcrudgen {
    namespace mysql {
        class ColumnPrivileges {

        private:
            std::string grantee;
            std::string tableCatalog;
            std::string tableSchema;
            std::string tableName;
            std::string columnName;
            std::string privilegeType;
            std::string isGrantable;

        public:

            static constexpr const char *TABLE_NAME = "COLUMN_PRIVILEGES";

            struct COLUMNS {
                struct GRANTEE {
                    static constexpr const char *NAME = "GRANTEE";
                    static const int INDEX = 1;
                };
                struct TABLE_CATALOG {
                    static constexpr const char *NAME = "TABLE_CATALOG";
                    static const int INDEX = 2;
                };
                struct TABLE_SCHEMA {
                    static constexpr const char *NAME = "TABLE_SCHEMA";
                    static const int INDEX = 3;
                };
                struct TABLE_NAME {
                    static constexpr const char *NAME = "TABLE_NAME";
                    static const int INDEX = 4;
                };
                struct COLUMN_NAME {
                    static constexpr const char *NAME = "COLUMN_NAME";
                    static const int INDEX = 5;
                };
                struct PRIVILEGE_TYPE {
                    static constexpr const char *NAME = "PRIVILEGE_TYPE";
                    static const int INDEX = 6;
                };
                struct IS_GRANTABLE {
                    static constexpr const char *NAME = "IS_GRANTABLE";
                    static const int INDEX = 7;
                };
            };

            ColumnPrivileges(std::string &grantee, std::string &tableCatalog, std::string &tableSchema,
                             std::string &tableName,
                             std::string &columnName, std::string &privilegeType, std::string &isGrantable) : grantee{
                    grantee},
                                                                                                              tableCatalog{
                                                                                                                      tableCatalog},
                                                                                                              tableSchema{
                                                                                                                      tableSchema},
                                                                                                              tableName{
                                                                                                                      tableName},
                                                                                                              columnName{
                                                                                                                      columnName},
                                                                                                              privilegeType{
                                                                                                                      privilegeType},
                                                                                                              isGrantable{
                                                                                                                      isGrantable} {}

            // Get the value of grantee
            const std::string &getGrantee() const {
                return grantee;
            }

            // Get the value of tableCatalog
            const std::string &getTableCatalog() const {
                return tableCatalog;
            }

            // Get the value of tableSchema
            const std::string &getTableSchema() const {
                return tableSchema;
            }

            // Get the value of tableName
            const std::string &getTableName() const {
                return tableName;
            }

            // Get the value of columnName
            const std::string &getColumnName() const {
                return columnName;
            }

            // Get the value of privilegeType
            const std::string &getPrivilegeType() const {
                return privilegeType;
            }

            // Get the value of isGrantable
            const std::string &getIsGrantable() const {
                return isGrantable;
            }

            /**
            * Returns the table name 'COLUMN_PRIVILEGES';
            */
            static const char *getDatabaseTableName() {
                return TABLE_NAME;
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_COLUMNPRIVILEGES_H
