//
// Created by victor on 3/14/20.
//

#ifndef DBCRUDGEN_CPP_CPPTEMPLATEFILES_H
#define DBCRUDGEN_CPP_CPPTEMPLATEFILES_H

#include "../TemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class CppTemplateFiles : TemplateFiles {
        public:
            static constexpr const char *CLASS_TEMPLATE = "templates/cpp/class.mdl";
            static constexpr const char *CLASS_TABLE_TEMPLATE = "templates/cpp/class_table.mdl";
            static constexpr const char *CLASS_TABLE_MODEL_COLUMN_METADATA_TEMPLATE = "templates/cpp/class_table_model_column_metadata.mdl";


            static constexpr const char *METHOD_TEMPLATE = "templates/cpp/method.mdl";

            static constexpr const char *PROPERTY_GETTER = "templates/cpp/property_getter.mdl";
            static constexpr const char *PROPERTY_SETTER = "templates/cpp/property_setter.mdl";
            static constexpr const char *PROPERTY_GETTER_SETTER = "templates/cpp/property_getter_setter.mdl";

            static constexpr const char *VARIABLE_TEMPLATE = "templates/cpp/variable.mdl";
            static constexpr const char *CTOR_PROPERTY_INITIALIZER_TEMPLATE = "templates/cpp/ctor_property_initializer.mdl";

            struct MYSQL {
                static constexpr const char *DATABASE_CONNECTOR = "templates/cpp/mysql/connector.mdl";

                static constexpr const char *CLASS_SCRUD = "templates/cpp/mysql/scrud.mdl";

                static constexpr const char *METHOD_SCRUD_QUERY_ALL_RECORDS = "templates/cpp/mysql/scrud_query_all_records.mdl";
                static constexpr const char *METHOD_SCRUD_QUERY_RECORD_NATIVE = "templates/cpp/mysql/scrud_query_record_native.mdl";
                static constexpr const char *METHOD_SCRUD_QUERY_RECORDS_NATIVE = "templates/cpp/mysql/scrud_query_records_native.mdl";
                static constexpr const char *METHOD_SCRUD_QUERY_RECORD_WITH_ID = "templates/cpp/mysql/scrud_query_record_with_id.mdl";
                static constexpr const char *METHOD_SCRUD_QUERY_RECORD_WITH_MODEL = "templates/cpp/mysql/scrud_query_record_with_model.mdl";

                static constexpr const char *METHOD_SCRUD_DELETE_WITH_ID = "templates/cpp/mysql/scrud_delete_records_id.mdl";
                static constexpr const char *METHOD_SCRUD_DELETE_WITH_MODEL = "templates/cpp/mysql/scrud_delete_records_model.mdl";
                static constexpr const char *METHOD_SCRUD_DELETE_WITH_NATIVE = "templates/cpp/mysql/scrud_delete_records_native.mdl";

                static constexpr const char *METHOD_SCRUD_INSERT_WITH_MODEL = "templates/cpp/mysql/scrud_insert_records_model.mdl";
                static constexpr const char *METHOD_SCRUD_INSERT_WITH_NATIVE = "templates/cpp/mysql/scrud_insert_records_native.mdl";

                static constexpr const char *METHOD_SCRUD_UPDATE_WITH_ID = "templates/cpp/mysql/scrud_update_records_id.mdl";
                static constexpr const char *METHOD_SCRUD_UPDATE_WITH_MODEL = "templates/cpp/mysql/scrud_records_model.mdl";
                static constexpr const char *METHOD_SCRUD_UPDATE_WITH_NATIVE = "templates/cpp/mysql/scrud_update_records_native.mdl";

            };
            struct ORACLE {
                static constexpr const char *DATABASE_CONNECTOR = "templates/cpp/oracle/connector.mdl";
            };
            struct SQLITE {
                static constexpr const char *DATABASE_CONNECTOR = "templates/cpp/sqlite/connector.mdl";
            };
        };

    }
}
#endif //DBCRUDGEN_CPP_CPPTEMPLATEFILES_H
