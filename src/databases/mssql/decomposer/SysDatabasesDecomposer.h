//
// Created by victor on 9/1/21.
//

#ifndef DBCRUDGEN_CPP_SYSDATABASESDECOMPOSER_H
#define DBCRUDGEN_CPP_SYSDATABASESDECOMPOSER_H

#include "../executor/MSSQLQueryExecutor.h"
#include "../scaffolding/entities/SysDatabases.h"

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class SysDatabasesDecomposer {
            private:
                dbcrudgen::db::mssql::MSSQLQueryExecutor executor;
            public:
                SysDatabasesDecomposer() = default;

                explicit SysDatabasesDecomposer(dbcrudgen::db::mssql::MSSQLQueryExecutor &executor)
                        : executor{executor} {
                }

                /**
                * Get all Sys databases
                * @return
                */
                std::vector<SysDatabases> getSysDatabases() {
                    std::vector<MSSQLColBinder> colBindings;
                    std::vector<SysDatabases> sysDatabases;

                    {
                        SQLCHAR name[255];
                        SQLLEN name_indicator;
                        std::string columnName{SysDatabases::COLUMNS::NAME::NAME_};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::NAME::INDEX, SQL_C_CHAR, columnName, name, 255,
                                               &name_indicator});
                    }

                    {
                        SQLINTEGER database_id;
                        SQLLEN database_id_indicator;
                        std::string columnName{SysDatabases::COLUMNS::DATABASE_ID::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::DATABASE_ID::INDEX, SQL_INTEGER, columnName,
                                               &database_id, sizeof(database_id), &database_id_indicator});
                    }

                    {
                        SQLINTEGER source_database_id;
                        SQLLEN source_database_id_indicator;
                        std::string columnName{SysDatabases::COLUMNS::SOURCE_DATABASE_ID::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::SOURCE_DATABASE_ID::INDEX, SQL_INTEGER,
                                               columnName, &source_database_id, sizeof(source_database_id),
                                               &source_database_id_indicator});
                    }

                    {
                        SQLCHAR owner_sid[255];
                        SQLLEN owner_sid_indicator;
                        std::string columnName{SysDatabases::COLUMNS::OWNER_SID::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::OWNER_SID::INDEX, SQL_C_CHAR, columnName,
                                               owner_sid, 255, &owner_sid_indicator});
                    }

                    {
                        SQLCHAR create_date[255];
                        SQLLEN create_date_indicator;
                        std::string columnName{SysDatabases::COLUMNS::CREATE_DATE::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::CREATE_DATE::INDEX, SQL_C_CHAR, columnName,
                                               create_date, 255, &create_date_indicator});
                    }

                    {
                        SQLCHAR compatibility_level[255];
                        SQLLEN compatibility_level_indicator;
                        std::string columnName{SysDatabases::COLUMNS::COMPATIBILITY_LEVEL::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::COMPATIBILITY_LEVEL::INDEX, SQL_C_CHAR,
                                               columnName, compatibility_level, 255, &compatibility_level_indicator});
                    }

                    {
                        SQLCHAR collation_name[255];
                        SQLLEN collation_name_indicator;
                        std::string columnName{SysDatabases::COLUMNS::COLLATION_NAME::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::COLLATION_NAME::INDEX, SQL_C_CHAR, columnName,
                                               collation_name, 255, &collation_name_indicator});
                    }

                    {
                        SQLINTEGER user_access;
                        SQLLEN user_access_indicator;
                        std::string columnName{SysDatabases::COLUMNS::USER_ACCESS::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::USER_ACCESS::INDEX, SQL_INTEGER, columnName,
                                               &user_access, sizeof(user_access), &user_access_indicator});
                    }

                    {
                        SQLCHAR user_access_desc[255];
                        SQLLEN user_access_desc_indicator;
                        std::string columnName{SysDatabases::COLUMNS::USER_ACCESS_DESC::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::USER_ACCESS_DESC::INDEX, SQL_C_CHAR, columnName,
                                               user_access_desc, 255, &user_access_desc_indicator});
                    }

                    {
                        SQLINTEGER is_read_only;
                        SQLLEN is_read_only_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_READ_ONLY::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_READ_ONLY::INDEX, SQL_INTEGER, columnName,
                                               &is_read_only, sizeof(is_read_only), &is_read_only_indicator});
                    }

                    {
                        SQLINTEGER is_auto_close_on;
                        SQLLEN is_auto_close_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_AUTO_CLOSE_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_AUTO_CLOSE_ON::INDEX, SQL_C_BIT, columnName,
                                               &is_auto_close_on, sizeof(is_auto_close_on),
                                               &is_auto_close_on_indicator});
                    }

                    {
                        SQLINTEGER is_auto_shrink_on;
                        SQLLEN is_auto_shrink_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_AUTO_SHRINK_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_AUTO_SHRINK_ON::INDEX, SQL_C_BIT, columnName,
                                               &is_auto_shrink_on, sizeof(is_auto_shrink_on),
                                               &is_auto_shrink_on_indicator});
                    }

                    {
                        SQLINTEGER state;
                        SQLLEN state_indicator;
                        std::string columnName{SysDatabases::COLUMNS::STATE::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::STATE::INDEX, SQL_INTEGER, columnName, &state,
                                               255,
                                               &state_indicator});
                    }

                    {
                        SQLCHAR state_desc[255];
                        SQLLEN state_desc_indicator;
                        std::string columnName{SysDatabases::COLUMNS::STATE_DESC::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::STATE_DESC::INDEX, SQL_C_CHAR, columnName,
                                               state_desc, 255, &state_desc_indicator});
                    }

                    {
                        SQLINTEGER is_in_standby;
                        SQLLEN is_in_standby_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_IN_STANDBY::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_IN_STANDBY::INDEX, SQL_C_BIT, columnName,
                                               &is_in_standby, sizeof(is_in_standby), &is_in_standby_indicator});
                    }

                    {
                        SQLINTEGER is_cleanly_shutdown;
                        SQLLEN is_cleanly_shutdown_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_CLEANLY_SHUTDOWN::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_CLEANLY_SHUTDOWN::INDEX, SQL_C_BIT,
                                               columnName, &is_cleanly_shutdown, sizeof(is_cleanly_shutdown),
                                               &is_cleanly_shutdown_indicator});
                    }

                    {
                        SQLINTEGER is_supplemental_logging_enabled;
                        SQLLEN is_supplemental_logging_enabled_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_SUPPLEMENTAL_LOGGING_ENABLED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_SUPPLEMENTAL_LOGGING_ENABLED::INDEX,
                                               SQL_C_BIT, columnName, &is_supplemental_logging_enabled,
                                               sizeof(is_supplemental_logging_enabled),
                                               &is_supplemental_logging_enabled_indicator});
                    }

                    {
                        SQLCHAR snapshot_isolation_state[255];
                        SQLLEN snapshot_isolation_state_indicator;
                        std::string columnName{SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE::INDEX, SQL_C_CHAR,
                                               columnName, snapshot_isolation_state, 255,
                                               &snapshot_isolation_state_indicator});
                    }

                    {
                        SQLCHAR snapshot_isolation_state_desc[255];
                        SQLLEN snapshot_isolation_state_desc_indicator;
                        std::string columnName{SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE_DESC::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE_DESC::INDEX, SQL_C_CHAR,
                                               columnName, snapshot_isolation_state_desc, 255,
                                               &snapshot_isolation_state_desc_indicator});
                    }

                    {
                        SQLINTEGER is_read_committed_snapshot_on;
                        SQLLEN is_read_committed_snapshot_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_READ_COMMITTED_SNAPSHOT_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_READ_COMMITTED_SNAPSHOT_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_read_committed_snapshot_on,
                                               sizeof(is_read_committed_snapshot_on),
                                               &is_read_committed_snapshot_on_indicator});
                    }

                    {
                        SQLCHAR recovery_model[255];
                        SQLLEN recovery_model_indicator;
                        std::string columnName{SysDatabases::COLUMNS::RECOVERY_MODEL::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::RECOVERY_MODEL::INDEX, SQL_C_CHAR, columnName,
                                               recovery_model, 255, &recovery_model_indicator});
                    }

                    {
                        SQLCHAR recovery_model_desc[255];
                        SQLLEN recovery_model_desc_indicator;
                        std::string columnName{SysDatabases::COLUMNS::RECOVERY_MODEL_DESC::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::RECOVERY_MODEL_DESC::INDEX, SQL_C_CHAR,
                                               columnName, recovery_model_desc, 255, &recovery_model_desc_indicator});
                    }

                    {
                        SQLCHAR page_verify_option[255];
                        SQLLEN page_verify_option_indicator;
                        std::string columnName{SysDatabases::COLUMNS::PAGE_VERIFY_OPTION::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::PAGE_VERIFY_OPTION::INDEX, SQL_C_CHAR, columnName,
                                               page_verify_option, 255, &page_verify_option_indicator});
                    }

                    {
                        SQLCHAR page_verify_option_desc[255];
                        SQLLEN page_verify_option_desc_indicator;
                        std::string columnName{SysDatabases::COLUMNS::PAGE_VERIFY_OPTION_DESC::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::PAGE_VERIFY_OPTION_DESC::INDEX, SQL_C_CHAR,
                                               columnName, page_verify_option_desc, 255,
                                               &page_verify_option_desc_indicator});
                    }

                    {
                        SQLINTEGER is_auto_create_stats_on;
                        SQLLEN is_auto_create_stats_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_auto_create_stats_on, sizeof(is_auto_create_stats_on),
                                               &is_auto_create_stats_on_indicator});
                    }

                    {
                        SQLINTEGER is_auto_create_stats_incremental_on;
                        SQLLEN is_auto_create_stats_incremental_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_INCREMENTAL_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_INCREMENTAL_ON::INDEX,
                                               SQL_C_BIT, columnName, &is_auto_create_stats_incremental_on,
                                               sizeof(is_auto_create_stats_incremental_on),
                                               &is_auto_create_stats_incremental_on_indicator});
                    }

                    {
                        SQLINTEGER is_auto_update_stats_on;
                        SQLLEN is_auto_update_stats_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_auto_update_stats_on, sizeof(is_auto_update_stats_on),
                                               &is_auto_update_stats_on_indicator});
                    }

                    {
                        SQLINTEGER is_auto_update_stats_async_on;
                        SQLLEN is_auto_update_stats_async_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ASYNC_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ASYNC_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_auto_update_stats_async_on,
                                               sizeof(is_auto_update_stats_async_on),
                                               &is_auto_update_stats_async_on_indicator});
                    }

                    {
                        SQLINTEGER is_ansi_null_default_on;
                        SQLLEN is_ansi_null_default_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_ANSI_NULL_DEFAULT_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_ANSI_NULL_DEFAULT_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_ansi_null_default_on, sizeof(is_ansi_null_default_on),
                                               &is_ansi_null_default_on_indicator});
                    }

                    {
                        SQLINTEGER is_ansi_nulls_on;
                        SQLLEN is_ansi_nulls_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_ANSI_NULLS_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_ANSI_NULLS_ON::INDEX, SQL_C_BIT, columnName,
                                               &is_ansi_nulls_on, sizeof(is_ansi_nulls_on),
                                               &is_ansi_nulls_on_indicator});
                    }

                    {
                        SQLINTEGER is_ansi_padding_on;
                        SQLLEN is_ansi_padding_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_ANSI_PADDING_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_ANSI_PADDING_ON::INDEX, SQL_C_BIT, columnName,
                                               &is_ansi_padding_on, sizeof(is_ansi_padding_on),
                                               &is_ansi_padding_on_indicator});
                    }

                    {
                        SQLINTEGER is_ansi_warnings_on;
                        SQLLEN is_ansi_warnings_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_ANSI_WARNINGS_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_ANSI_WARNINGS_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_ansi_warnings_on, sizeof(is_ansi_warnings_on_indicator),
                                               &is_ansi_warnings_on_indicator});
                    }

                    {
                        SQLINTEGER is_arithabort_on;
                        SQLLEN is_arithabort_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_ARITHABORT_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_ARITHABORT_ON::INDEX, SQL_C_BIT, columnName,
                                               &is_arithabort_on, sizeof(is_arithabort_on),
                                               &is_arithabort_on_indicator});
                    }

                    {
                        SQLINTEGER is_concat_null_yields_null_on;
                        SQLLEN is_concat_null_yields_null_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_CONCAT_NULL_YIELDS_NULL_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_CONCAT_NULL_YIELDS_NULL_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_concat_null_yields_null_on,
                                               sizeof(is_concat_null_yields_null_on),
                                               &is_concat_null_yields_null_on_indicator});
                    }

                    {
                        SQLINTEGER is_numeric_roundabort_on;
                        SQLLEN is_numeric_roundabort_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_NUMERIC_ROUNDABORT_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_NUMERIC_ROUNDABORT_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_numeric_roundabort_on, sizeof(is_numeric_roundabort_on),
                                               &is_numeric_roundabort_on_indicator});
                    }

                    {
                        SQLINTEGER is_quoted_identifier_on;
                        SQLLEN is_quoted_identifier_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_QUOTED_IDENTIFIER_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_QUOTED_IDENTIFIER_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_quoted_identifier_on, sizeof(is_quoted_identifier_on),
                                               &is_quoted_identifier_on_indicator});
                    }

                    {
                        SQLINTEGER is_recursive_triggers_on;
                        SQLLEN is_recursive_triggers_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_RECURSIVE_TRIGGERS_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_RECURSIVE_TRIGGERS_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_recursive_triggers_on, sizeof(is_recursive_triggers_on),
                                               &is_recursive_triggers_on_indicator});
                    }

                    {
                        SQLINTEGER is_cursor_close_on_commit_on;
                        SQLLEN is_cursor_close_on_commit_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_CURSOR_CLOSE_ON_COMMIT_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_CURSOR_CLOSE_ON_COMMIT_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_cursor_close_on_commit_on,
                                               sizeof(is_cursor_close_on_commit_on),
                                               &is_cursor_close_on_commit_on_indicator});
                    }

                    {
                        SQLINTEGER is_local_cursor_default;
                        SQLLEN is_local_cursor_default_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_LOCAL_CURSOR_DEFAULT::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_LOCAL_CURSOR_DEFAULT::INDEX, SQL_C_BIT,
                                               columnName, &is_local_cursor_default, sizeof(is_local_cursor_default),
                                               &is_local_cursor_default_indicator});
                    }

                    {
                        SQLINTEGER is_fulltext_enabled;
                        SQLLEN is_fulltext_enabled_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_FULLTEXT_ENABLED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_FULLTEXT_ENABLED::INDEX, SQL_C_BIT,
                                               columnName, &is_fulltext_enabled, sizeof(is_fulltext_enabled),
                                               &is_fulltext_enabled_indicator});
                    }

                    {
                        SQLINTEGER is_trustworthy_on;
                        SQLLEN is_trustworthy_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_TRUSTWORTHY_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_TRUSTWORTHY_ON::INDEX, SQL_C_BIT, columnName,
                                               &is_trustworthy_on, sizeof(is_trustworthy_on),
                                               &is_trustworthy_on_indicator});
                    }

                    {
                        SQLINTEGER is_db_chaining_on;
                        SQLLEN is_db_chaining_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_DB_CHAINING_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_DB_CHAINING_ON::INDEX, SQL_C_BIT, columnName,
                                               &is_db_chaining_on, sizeof(is_db_chaining_on),
                                               &is_db_chaining_on_indicator});
                    }

                    {
                        SQLINTEGER is_parameterization_forced;
                        SQLLEN is_parameterization_forced_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_PARAMETERIZATION_FORCED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_PARAMETERIZATION_FORCED::INDEX, SQL_C_BIT,
                                               columnName, &is_parameterization_forced,
                                               sizeof(is_parameterization_forced),
                                               &is_parameterization_forced_indicator});
                    }

                    {
                        SQLINTEGER is_master_key_encrypted_by_server;
                        SQLLEN is_master_key_encrypted_by_server_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_MASTER_KEY_ENCRYPTED_BY_SERVER::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_MASTER_KEY_ENCRYPTED_BY_SERVER::INDEX,
                                               SQL_C_BIT, columnName, &is_master_key_encrypted_by_server,
                                               sizeof(is_master_key_encrypted_by_server),
                                               &is_master_key_encrypted_by_server_indicator});
                    }

                    {
                        SQLINTEGER is_query_store_on;
                        SQLLEN is_query_store_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_QUERY_STORE_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_QUERY_STORE_ON::INDEX, SQL_C_BIT, columnName,
                                               &is_query_store_on, sizeof(is_query_store_on),
                                               &is_query_store_on_indicator});
                    }

                    {
                        SQLINTEGER is_published;
                        SQLLEN is_published_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_PUBLISHED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_PUBLISHED::INDEX, SQL_C_BIT, columnName,
                                               &is_published, sizeof(is_published), &is_published_indicator});
                    }

                    {
                        SQLINTEGER is_subscribed;
                        SQLLEN is_subscribed_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_SUBSCRIBED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_SUBSCRIBED::INDEX, SQL_C_BIT, columnName,
                                               &is_subscribed, sizeof(is_subscribed), &is_subscribed_indicator});
                    }

                    {
                        SQLINTEGER is_merge_published;
                        SQLLEN is_merge_published_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_MERGE_PUBLISHED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_MERGE_PUBLISHED::INDEX, SQL_C_BIT, columnName,
                                               &is_merge_published, sizeof(is_merge_published),
                                               &is_merge_published_indicator});
                    }

                    {
                        SQLINTEGER is_distributor;
                        SQLLEN is_distributor_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_DISTRIBUTOR::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_DISTRIBUTOR::INDEX, SQL_C_BIT, columnName,
                                               &is_distributor, sizeof(is_distributor), &is_distributor_indicator});
                    }

                    {
                        SQLINTEGER is_sync_with_backup;
                        SQLLEN is_sync_with_backup_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_SYNC_WITH_BACKUP::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_SYNC_WITH_BACKUP::INDEX, SQL_C_BIT,
                                               columnName, &is_sync_with_backup, sizeof(is_sync_with_backup),
                                               &is_sync_with_backup_indicator});
                    }

                    {
                        SQLCHAR service_broker_guid[255];
                        SQLLEN service_broker_guid_indicator;
                        std::string columnName{SysDatabases::COLUMNS::SERVICE_BROKER_GUID::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::SERVICE_BROKER_GUID::INDEX, SQL_C_CHAR,
                                               columnName, service_broker_guid, 255, &service_broker_guid_indicator});
                    }

                    {
                        SQLINTEGER is_broker_enabled;
                        SQLLEN is_broker_enabled_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_BROKER_ENABLED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_BROKER_ENABLED::INDEX, SQL_C_BIT, columnName,
                                               &is_broker_enabled, sizeof(is_broker_enabled),
                                               &is_broker_enabled_indicator});
                    }

                    {
                        SQLCHAR log_reuse_wait[255];
                        SQLLEN log_reuse_wait_indicator;
                        std::string columnName{SysDatabases::COLUMNS::LOG_REUSE_WAIT::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::LOG_REUSE_WAIT::INDEX, SQL_C_CHAR, columnName,
                                               log_reuse_wait, 255, &log_reuse_wait_indicator});
                    }

                    {
                        SQLCHAR log_reuse_wait_desc[255];
                        SQLLEN log_reuse_wait_desc_indicator;
                        std::string columnName{SysDatabases::COLUMNS::LOG_REUSE_WAIT_DESC::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::LOG_REUSE_WAIT_DESC::INDEX, SQL_C_CHAR,
                                               columnName, log_reuse_wait_desc, 255, &log_reuse_wait_desc_indicator});
                    }

                    {
                        SQLINTEGER is_date_correlation_on;
                        SQLLEN is_date_correlation_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_DATE_CORRELATION_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_DATE_CORRELATION_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_date_correlation_on, sizeof(is_date_correlation_on),
                                               &is_date_correlation_on_indicator});
                    }

                    {
                        SQLINTEGER is_cdc_enabled;
                        SQLLEN is_cdc_enabled_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_CDC_ENABLED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_CDC_ENABLED::INDEX, SQL_C_BIT, columnName,
                                               &is_cdc_enabled, sizeof(is_cdc_enabled), &is_cdc_enabled_indicator});
                    }

                    {
                        SQLINTEGER is_encrypted;
                        SQLLEN is_encrypted_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_ENCRYPTED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_ENCRYPTED::INDEX, SQL_C_BIT, columnName,
                                               &is_encrypted, sizeof(is_encrypted), &is_encrypted_indicator});
                    }

                    {
                        SQLINTEGER is_honor_broker_priority_on;
                        SQLLEN is_honor_broker_priority_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_HONOR_BROKER_PRIORITY_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_HONOR_BROKER_PRIORITY_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_honor_broker_priority_on,
                                               sizeof(is_honor_broker_priority_on),
                                               &is_honor_broker_priority_on_indicator});
                    }

                    {
                        SQLCHAR replica_id[255];
                        SQLLEN replica_id_indicator;
                        std::string columnName{SysDatabases::COLUMNS::REPLICA_ID::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::REPLICA_ID::INDEX, SQL_C_CHAR, columnName,
                                               replica_id, 255, &replica_id_indicator});
                    }

                    {
                        SQLCHAR group_database_id[255];
                        SQLLEN group_database_id_indicator;
                        std::string columnName{SysDatabases::COLUMNS::GROUP_DATABASE_ID::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::GROUP_DATABASE_ID::INDEX, SQL_C_CHAR, columnName,
                                               group_database_id, 255, &group_database_id_indicator});
                    }

                    {
                        SQLCHAR resource_pool_id[255];
                        SQLLEN resource_pool_id_indicator;
                        std::string columnName{SysDatabases::COLUMNS::RESOURCE_POOL_ID::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::RESOURCE_POOL_ID::INDEX, SQL_C_CHAR, columnName,
                                               resource_pool_id, 255, &resource_pool_id_indicator});
                    }

                    {
                        SQLCHAR default_language_lcid[255];
                        SQLLEN default_language_lcid_indicator;
                        std::string columnName{SysDatabases::COLUMNS::DEFAULT_LANGUAGE_LCID::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::DEFAULT_LANGUAGE_LCID::INDEX, SQL_C_CHAR,
                                               columnName, default_language_lcid, 255,
                                               &default_language_lcid_indicator});
                    }

                    {
                        SQLCHAR default_language_name[255];
                        SQLLEN default_language_name_indicator;
                        std::string columnName{SysDatabases::COLUMNS::DEFAULT_LANGUAGE_NAME::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::DEFAULT_LANGUAGE_NAME::INDEX, SQL_C_CHAR,
                                               columnName, default_language_name, 255,
                                               &default_language_name_indicator});
                    }

                    {
                        SQLCHAR default_fulltext_language_lcid[255];
                        SQLLEN default_fulltext_language_lcid_indicator;
                        std::string columnName{SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_LCID::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_LCID::INDEX, SQL_C_CHAR,
                                               columnName, default_fulltext_language_lcid, 255,
                                               &default_fulltext_language_lcid_indicator});
                    }

                    {
                        SQLCHAR default_fulltext_language_name[255];
                        SQLLEN default_fulltext_language_name_indicator;
                        std::string columnName{SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_NAME::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_NAME::INDEX, SQL_C_CHAR,
                                               columnName, default_fulltext_language_name, 255,
                                               &default_fulltext_language_name_indicator});
                    }

                    {
                        SQLINTEGER is_nested_triggers_on;
                        SQLLEN is_nested_triggers_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_NESTED_TRIGGERS_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_NESTED_TRIGGERS_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_nested_triggers_on, sizeof(is_nested_triggers_on),
                                               &is_nested_triggers_on_indicator});
                    }

                    {
                        SQLINTEGER is_transform_noise_words_on;
                        SQLLEN is_transform_noise_words_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_TRANSFORM_NOISE_WORDS_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_TRANSFORM_NOISE_WORDS_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_transform_noise_words_on,
                                               sizeof(is_transform_noise_words_on),
                                               &is_transform_noise_words_on_indicator});
                    }

                    {
                        SQLCHAR two_digit_year_cutoff[255];
                        SQLLEN two_digit_year_cutoff_indicator;
                        std::string columnName{SysDatabases::COLUMNS::TWO_DIGIT_YEAR_CUTOFF::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::TWO_DIGIT_YEAR_CUTOFF::INDEX, SQL_C_CHAR,
                                               columnName, two_digit_year_cutoff, 255,
                                               &two_digit_year_cutoff_indicator});
                    }

                    {
                        SQLCHAR containment[255];
                        SQLLEN containment_indicator;
                        std::string columnName{SysDatabases::COLUMNS::CONTAINMENT::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::CONTAINMENT::INDEX, SQL_C_CHAR, columnName,
                                               containment, 255, &containment_indicator});
                    }

                    {
                        SQLCHAR containment_desc[255];
                        SQLLEN containment_desc_indicator;
                        std::string columnName{SysDatabases::COLUMNS::CONTAINMENT_DESC::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::CONTAINMENT_DESC::INDEX, SQL_C_CHAR, columnName,
                                               containment_desc, 255, &containment_desc_indicator});
                    }

                    {
                        SQLCHAR target_recovery_time_in_seconds[255];
                        SQLLEN target_recovery_time_in_seconds_indicator;
                        std::string columnName{SysDatabases::COLUMNS::TARGET_RECOVERY_TIME_IN_SECONDS::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::TARGET_RECOVERY_TIME_IN_SECONDS::INDEX,
                                               SQL_C_CHAR, columnName, target_recovery_time_in_seconds, 255,
                                               &target_recovery_time_in_seconds_indicator});
                    }

                    {
                        SQLCHAR delayed_durability[255];
                        SQLLEN delayed_durability_indicator;
                        std::string columnName{SysDatabases::COLUMNS::DELAYED_DURABILITY::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::DELAYED_DURABILITY::INDEX, SQL_C_CHAR, columnName,
                                               delayed_durability, 255, &delayed_durability_indicator});
                    }

                    {
                        SQLCHAR delayed_durability_desc[255];
                        SQLLEN delayed_durability_desc_indicator;
                        std::string columnName{SysDatabases::COLUMNS::DELAYED_DURABILITY_DESC::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::DELAYED_DURABILITY_DESC::INDEX, SQL_C_CHAR,
                                               columnName, delayed_durability_desc, 255,
                                               &delayed_durability_desc_indicator});
                    }

                    {
                        SQLINTEGER is_memory_optimized_elevate_to_snapshot_on;
                        SQLLEN is_memory_optimized_elevate_to_snapshot_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_MEMORY_OPTIMIZED_ELEVATE_TO_SNAPSHOT_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_MEMORY_OPTIMIZED_ELEVATE_TO_SNAPSHOT_ON::INDEX,
                                               SQL_C_BIT, columnName, &is_memory_optimized_elevate_to_snapshot_on,
                                               sizeof(is_memory_optimized_elevate_to_snapshot_on),
                                               &is_memory_optimized_elevate_to_snapshot_on_indicator});
                    }

                    {
                        SQLINTEGER is_federation_member;
                        SQLLEN is_federation_member_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_FEDERATION_MEMBER::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_FEDERATION_MEMBER::INDEX, SQL_C_BIT,
                                               columnName, &is_federation_member,
                                               sizeof(is_federation_member), &is_federation_member_indicator});
                    }

                    {
                        SQLINTEGER is_remote_data_archive_enabled;
                        SQLLEN is_remote_data_archive_enabled_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_REMOTE_DATA_ARCHIVE_ENABLED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_REMOTE_DATA_ARCHIVE_ENABLED::INDEX, SQL_C_BIT,
                                               columnName, &is_remote_data_archive_enabled,
                                               sizeof(is_remote_data_archive_enabled),
                                               &is_remote_data_archive_enabled_indicator});
                    }

                    {
                        SQLINTEGER is_mixed_page_allocation_on;
                        SQLLEN is_mixed_page_allocation_on_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_MIXED_PAGE_ALLOCATION_ON::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_MIXED_PAGE_ALLOCATION_ON::INDEX, SQL_C_BIT,
                                               columnName, &is_mixed_page_allocation_on,
                                               sizeof(is_mixed_page_allocation_on),
                                               &is_mixed_page_allocation_on_indicator});
                    }

                    {
                        SQLINTEGER is_temporal_history_retention_enabled;
                        SQLLEN is_temporal_history_retention_enabled_indicator;
                        std::string columnName{SysDatabases::COLUMNS::IS_TEMPORAL_HISTORY_RETENTION_ENABLED::NAME};
                        colBindings.emplace_back(
                                MSSQLColBinder{SysDatabases::COLUMNS::IS_TEMPORAL_HISTORY_RETENTION_ENABLED::INDEX,
                                               SQL_C_BIT, columnName, &is_temporal_history_retention_enabled,
                                               sizeof(is_temporal_history_retention_enabled),
                                               &is_temporal_history_retention_enabled_indicator});
                    }


                    std::vector<MSSQLResultSet> resultSet{};
                    SQLWCHAR *query = (SQLWCHAR *) u"SELECT * FROM SYS.DATABASES;";
                    executor.execQuery(query, colBindings, resultSet);

                    std::string name;
                    int database_id;
                    int source_database_id;
                    std::string owner_sid;
                    std::string create_date;
                    int compatibility_level;
                    std::string collation_name;
                    int user_access;
                    std::string user_access_desc;
                    bool is_read_only;
                    bool is_auto_close_on;
                    bool is_auto_shrink_on;
                    int state;
                    std::string state_desc;
                    bool is_in_standby;
                    bool is_cleanly_shutdown;
                    bool is_supplemental_logging_enabled;
                    int snapshot_isolation_state;
                    std::string snapshot_isolation_state_desc;
                    bool is_read_committed_snapshot_on;
                    int recovery_model;
                    std::string recovery_model_desc;
                    int page_verify_option;
                    std::string page_verify_option_desc;
                    bool is_auto_create_stats_on;
                    bool is_auto_create_stats_incremental_on;
                    bool is_auto_update_stats_on;
                    bool is_auto_update_stats_async_on;
                    bool is_ansi_null_default_on;
                    bool is_ansi_nulls_on;
                    bool is_ansi_padding_on;
                    bool is_ansi_warnings_on;
                    bool is_arithabort_on;
                    bool is_concat_null_yields_null_on;
                    bool is_numeric_roundabort_on;
                    bool is_quoted_identifier_on;
                    bool is_recursive_triggers_on;
                    bool is_cursor_close_on_commit_on;
                    bool is_local_cursor_default;
                    bool is_fulltext_enabled;
                    bool is_trustworthy_on;
                    bool is_db_chaining_on;
                    bool is_parameterization_forced;
                    bool is_master_key_encrypted_by_server;
                    bool is_query_store_on;
                    bool is_published;
                    bool is_subscribed;
                    bool is_merge_published;
                    bool is_distributor;
                    bool is_sync_with_backup;
                    std::string service_broker_guid;
                    bool is_broker_enabled;
                    int log_reuse_wait;
                    std::string log_reuse_wait_desc;
                    bool is_date_correlation_on;
                    bool is_cdc_enabled;
                    bool is_encrypted;
                    bool is_honor_broker_priority_on;
                    std::string replica_id;
                    std::string group_database_id;
                    int resource_pool_id;
                    int default_language_lcid;
                    std::string default_language_name;
                    int default_fulltext_language_lcid;
                    std::string default_fulltext_language_name;
                    bool is_nested_triggers_on;
                    bool is_transform_noise_words_on;
                    int two_digit_year_cutoff;
                    int containment;
                    std::string containment_desc;
                    int target_recovery_time_in_seconds;
                    int delayed_durability;
                    std::string delayed_durability_desc;
                    bool is_memory_optimized_elevate_to_snapshot_on;
                    bool is_federation_member;
                    bool is_remote_data_archive_enabled;
                    bool is_mixed_page_allocation_on;
                    bool is_temporal_history_retention_enabled;

                    int loopTracker = 0;
                    for (const dbcrudgen::db::mssql::MSSQLResultSet &data: resultSet) {
                        loopTracker++;
                        void *colValue = data.getColumnValue();

                        switch (data.getColumnIndex()) {
                            case SysDatabases::COLUMNS::NAME::INDEX:
                                name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DATABASE_ID::INDEX:
                                database_id = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::SOURCE_DATABASE_ID::INDEX:
                                source_database_id = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::OWNER_SID::INDEX:
                                owner_sid = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::CREATE_DATE::INDEX:
                                create_date = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::COMPATIBILITY_LEVEL::INDEX:
                                compatibility_level = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::COLLATION_NAME::INDEX:
                                collation_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::USER_ACCESS::INDEX:
                                user_access = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::USER_ACCESS_DESC::INDEX:
                                user_access_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_READ_ONLY::INDEX:
                                is_read_only = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_CLOSE_ON::INDEX:
                                is_auto_close_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_SHRINK_ON::INDEX:
                                is_auto_shrink_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::STATE::INDEX:
                                state = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::STATE_DESC::INDEX:
                                state_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_IN_STANDBY::INDEX:
                                is_in_standby = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_CLEANLY_SHUTDOWN::INDEX:
                                is_cleanly_shutdown = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_SUPPLEMENTAL_LOGGING_ENABLED::INDEX:
                                is_supplemental_logging_enabled = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE::INDEX:
                                snapshot_isolation_state = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::SNAPSHOT_ISOLATION_STATE_DESC::INDEX:
                                snapshot_isolation_state_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_READ_COMMITTED_SNAPSHOT_ON::INDEX:
                                is_read_committed_snapshot_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::RECOVERY_MODEL::INDEX:
                                recovery_model = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::RECOVERY_MODEL_DESC::INDEX:
                                recovery_model_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::PAGE_VERIFY_OPTION::INDEX:
                                page_verify_option = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::PAGE_VERIFY_OPTION_DESC::INDEX:
                                page_verify_option_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_ON::INDEX:
                                is_auto_create_stats_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_CREATE_STATS_INCREMENTAL_ON::INDEX:
                                is_auto_create_stats_incremental_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ON::INDEX:
                                is_auto_update_stats_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_AUTO_UPDATE_STATS_ASYNC_ON::INDEX:
                                is_auto_update_stats_async_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ANSI_NULL_DEFAULT_ON::INDEX:
                                is_ansi_null_default_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ANSI_NULLS_ON::INDEX:
                                is_ansi_nulls_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ANSI_PADDING_ON::INDEX:
                                is_ansi_padding_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ANSI_WARNINGS_ON::INDEX:
                                is_ansi_warnings_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ARITHABORT_ON::INDEX:
                                is_arithabort_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_CONCAT_NULL_YIELDS_NULL_ON::INDEX:
                                is_concat_null_yields_null_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_NUMERIC_ROUNDABORT_ON::INDEX:
                                is_numeric_roundabort_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_QUOTED_IDENTIFIER_ON::INDEX:
                                is_quoted_identifier_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_RECURSIVE_TRIGGERS_ON::INDEX:
                                is_recursive_triggers_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_CURSOR_CLOSE_ON_COMMIT_ON::INDEX:
                                is_cursor_close_on_commit_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_LOCAL_CURSOR_DEFAULT::INDEX:
                                is_local_cursor_default = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_FULLTEXT_ENABLED::INDEX:
                                is_fulltext_enabled = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_TRUSTWORTHY_ON::INDEX:
                                is_trustworthy_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_DB_CHAINING_ON::INDEX:
                                is_db_chaining_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_PARAMETERIZATION_FORCED::INDEX:
                                is_parameterization_forced = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_MASTER_KEY_ENCRYPTED_BY_SERVER::INDEX:
                                is_master_key_encrypted_by_server = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_QUERY_STORE_ON::INDEX:
                                is_query_store_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_PUBLISHED::INDEX:
                                is_published = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_SUBSCRIBED::INDEX:
                                is_subscribed = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_MERGE_PUBLISHED::INDEX:
                                is_merge_published = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_DISTRIBUTOR::INDEX:
                                is_distributor = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_SYNC_WITH_BACKUP::INDEX:
                                is_sync_with_backup = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::SERVICE_BROKER_GUID::INDEX:
                                service_broker_guid = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_BROKER_ENABLED::INDEX:
                                is_broker_enabled = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::LOG_REUSE_WAIT::INDEX:
                                log_reuse_wait = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::LOG_REUSE_WAIT_DESC::INDEX:
                                log_reuse_wait_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_DATE_CORRELATION_ON::INDEX:
                                is_date_correlation_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_CDC_ENABLED::INDEX:
                                is_cdc_enabled = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_ENCRYPTED::INDEX:
                                is_encrypted = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_HONOR_BROKER_PRIORITY_ON::INDEX:
                                is_honor_broker_priority_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::REPLICA_ID::INDEX:
                                replica_id = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::GROUP_DATABASE_ID::INDEX:
                                group_database_id = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::RESOURCE_POOL_ID::INDEX:
                                resource_pool_id = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DEFAULT_LANGUAGE_LCID::INDEX:
                                default_language_lcid = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DEFAULT_LANGUAGE_NAME::INDEX:
                                default_language_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_LCID::INDEX:
                                default_fulltext_language_lcid = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DEFAULT_FULLTEXT_LANGUAGE_NAME::INDEX:
                                default_fulltext_language_name = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_NESTED_TRIGGERS_ON::INDEX:
                                is_nested_triggers_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_TRANSFORM_NOISE_WORDS_ON::INDEX:
                                is_transform_noise_words_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::TWO_DIGIT_YEAR_CUTOFF::INDEX:
                                two_digit_year_cutoff = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::CONTAINMENT::INDEX:
                                containment = *reinterpret_cast<int *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::CONTAINMENT_DESC::INDEX:
                                containment_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::TARGET_RECOVERY_TIME_IN_SECONDS::INDEX:
                                target_recovery_time_in_seconds = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DELAYED_DURABILITY::INDEX:
                                delayed_durability = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::DELAYED_DURABILITY_DESC::INDEX:
                                delayed_durability_desc = *reinterpret_cast<std::string *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_MEMORY_OPTIMIZED_ELEVATE_TO_SNAPSHOT_ON::INDEX:
                                is_memory_optimized_elevate_to_snapshot_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_FEDERATION_MEMBER::INDEX:
                                is_federation_member = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_REMOTE_DATA_ARCHIVE_ENABLED::INDEX:
                                is_remote_data_archive_enabled = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_MIXED_PAGE_ALLOCATION_ON::INDEX:
                                is_mixed_page_allocation_on = *reinterpret_cast<bool *>(colValue);
                                break;
                            case SysDatabases::COLUMNS::IS_TEMPORAL_HISTORY_RETENTION_ENABLED::INDEX:
                                is_temporal_history_retention_enabled = *reinterpret_cast<bool *>(colValue);
                                break;
                        }

                        if (loopTracker == colBindings.size()) {
                            SysDatabases sysDatabase{name, database_id, source_database_id, owner_sid, create_date,
                                                     compatibility_level, collation_name, user_access, user_access_desc,
                                                     is_read_only, is_auto_close_on, is_auto_shrink_on, state,
                                                     state_desc,
                                                     is_in_standby, is_cleanly_shutdown,
                                                     is_supplemental_logging_enabled,
                                                     snapshot_isolation_state, snapshot_isolation_state_desc,
                                                     is_read_committed_snapshot_on, recovery_model, recovery_model_desc,
                                                     page_verify_option, page_verify_option_desc,
                                                     is_auto_create_stats_on,
                                                     is_auto_create_stats_incremental_on, is_auto_update_stats_on,
                                                     is_auto_update_stats_async_on, is_ansi_null_default_on,
                                                     is_ansi_nulls_on, is_ansi_padding_on, is_ansi_warnings_on,
                                                     is_arithabort_on, is_concat_null_yields_null_on,
                                                     is_numeric_roundabort_on, is_quoted_identifier_on,
                                                     is_recursive_triggers_on, is_cursor_close_on_commit_on,
                                                     is_local_cursor_default, is_fulltext_enabled, is_trustworthy_on,
                                                     is_db_chaining_on, is_parameterization_forced,
                                                     is_master_key_encrypted_by_server, is_query_store_on, is_published,
                                                     is_subscribed, is_merge_published, is_distributor,
                                                     is_sync_with_backup,
                                                     service_broker_guid, is_broker_enabled, log_reuse_wait,
                                                     log_reuse_wait_desc, is_date_correlation_on, is_cdc_enabled,
                                                     is_encrypted, is_honor_broker_priority_on, replica_id,
                                                     group_database_id, resource_pool_id, default_language_lcid,
                                                     default_language_name, default_fulltext_language_lcid,
                                                     default_fulltext_language_name, is_nested_triggers_on,
                                                     is_transform_noise_words_on, two_digit_year_cutoff, containment,
                                                     containment_desc, target_recovery_time_in_seconds,
                                                     delayed_durability,
                                                     delayed_durability_desc,
                                                     is_memory_optimized_elevate_to_snapshot_on,
                                                     is_federation_member, is_remote_data_archive_enabled,
                                                     is_mixed_page_allocation_on,
                                                     is_temporal_history_retention_enabled};
                            sysDatabases.emplace_back(sysDatabase);
                            loopTracker = 0;
                        }


                    }
                    return sysDatabases;
                }

                ~SysDatabasesDecomposer() {}
            };
        }
    }
}

#endif //DBCRUDGEN_CPP_SYSDATABASESDECOMPOSER_H
