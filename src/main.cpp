#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "databases/generic/Database.h"
#include "databases/mssql/executor/MSSQLQueryExecutor.h"
#include "databases/mssql/connectors/MSSQLDbConnParams.h"
#include "databases/mssql/connectors/MSSQLDbConnector.h"
#include "databases/mssql/executor/MSSQLColBinder.h"
#include "databases/mssql/decomposer/MSSQLDatabaseDecomposer.h"


void mssqlDevelopment();

int main(int argc, char **argv) {

    mssqlDevelopment();

    return EXIT_SUCCESS;
}

void mssqlDevelopment() {
    std::string host = "127.0.0.1";
    int port = 1433;
    std::string database = "dbcrudgen";
    std::string user = "SA";
    std::string password = "Root@3358";

    dbcrudgen::db::mssql::MSSQLDbConnParams connParams{host, port, database, user, password};
    dbcrudgen::db::mssql::MSSQLDbConnector connector{connParams};
    dbcrudgen::db::mssql::MSSQLDatabaseDecomposer decomposer{connector};


    // Get Databases
    const std::vector<dbcrudgen::db::mssql::SysDatabases> &sysDatabases = decomposer.getSysDatabases();
    std::cout << "Database Id\t"
              << "Database Name\t"
              << "Created On\t"
              << "Collation Name\t"
              << std::endl;

    for (auto &database: sysDatabases) {
        std::cout << database.getDatabaseId() << "\t"
                  << database.getName() << "\t"
                  << database.getCreateDate() << "\t"
                  << database.getCollationName() << "\t"
                  << std::endl;
    }


    std::string tableName = "all_columns";
    std::vector<dbcrudgen::db::mssql::SpTables> tables = decomposer.getTables();

    std::cout << "TableQualifier\t"
              << "TableOwner\t"
              << "TableName\t"
              << "TableType\t"
              << "Remarks\t"
              << std::endl;

    for (dbcrudgen::db::mssql::SpTables &table: tables) {
        std::cout << table.getTableQualifier() << "\t"
                  << table.getTableOwner() << "\t"
                  << table.getTableName() << "\t"
                  << table.getTableType() << "\t"
                  << table.getRemarks() << "\t"
                  << std::endl;
    }

    /*std::vector<std::string> items{std::string{"name"}, std::string{"database_id"}, std::string{"source_database_id"}, std::string{"owner_sid"}, std::string{"create_date"}, std::string{"compatibility_level"}, std::string{"collation_name"}, std::string{"user_access"}, std::string{"user_access_desc"}, std::string{"is_read_only"}, std::string{"is_auto_close_on"}, std::string{"is_auto_shrink_on"}, std::string{"state"}, std::string{"state_desc"}, std::string{"is_in_standby"}, std::string{"is_cleanly_shutdown"}, std::string{"is_supplemental_logging_enabled"}, std::string{"snapshot_isolation_state"}, std::string{"snapshot_isolation_state_desc"}, std::string{"is_read_committed_snapshot_on"}, std::string{"recovery_model"}, std::string{"recovery_model_desc"}, std::string{"page_verify_option"}, std::string{"page_verify_option_desc"}, std::string{"is_auto_create_stats_on"}, std::string{"is_auto_create_stats_incremental_on"}, std::string{"is_auto_update_stats_on"}, std::string{"is_auto_update_stats_async_on"}, std::string{"is_ansi_null_default_on"}, std::string{"is_ansi_nulls_on"}, std::string{"is_ansi_padding_on"}, std::string{"is_ansi_warnings_on"}, std::string{"is_arithabort_on"}, std::string{"is_concat_null_yields_null_on"}, std::string{"is_numeric_roundabort_on"}, std::string{"is_quoted_identifier_on"}, std::string{"is_recursive_triggers_on"}, std::string{"is_cursor_close_on_commit_on"}, std::string{"is_local_cursor_default"}, std::string{"is_fulltext_enabled"}, std::string{"is_trustworthy_on"}, std::string{"is_db_chaining_on"}, std::string{"is_parameterization_forced"}, std::string{"is_master_key_encrypted_by_server"}, std::string{"is_query_store_on"}, std::string{"is_published"}, std::string{"is_subscribed"}, std::string{"is_merge_published"}, std::string{"is_distributor"}, std::string{"is_sync_with_backup"}, std::string{"service_broker_guid"}, std::string{"is_broker_enabled"}, std::string{"log_reuse_wait"}, std::string{"log_reuse_wait_desc"}, std::string{"is_date_correlation_on"}, std::string{"is_cdc_enabled"}, std::string{"is_encrypted"}, std::string{"is_honor_broker_priority_on"}, std::string{"replica_id"}, std::string{"group_database_id"}, std::string{"resource_pool_id"}, std::string{"default_language_lcid"}, std::string{"default_language_name"}, std::string{"default_fulltext_language_lcid"}, std::string{"default_fulltext_language_name"}, std::string{"is_nested_triggers_on"}, std::string{"is_transform_noise_words_on"}, std::string{"two_digit_year_cutoff"}, std::string{"containment"}, std::string{"containment_desc"}, std::string{"target_recovery_time_in_seconds"}, std::string{"delayed_durability"}, std::string{"delayed_durability_desc"}, std::string{"is_memory_optimized_elevate_to_snapshot_on"}, std::string{"is_federation_member"}, std::string{"is_remote_data_archive_enabled"}, std::string{"is_mixed_page_allocation_on"}, std::string{"is_temporal_history_retention_enabled"},};


    for (int i = 0; i < items.size(); i++) {
        std::string item = items[i];
        std::string nameUpper = item;
        std::transform(nameUpper.begin(), nameUpper.end(), nameUpper.begin(), ::toupper);
        std::cout << "struct " << nameUpper << "{"
                  << "static constexpr const char *NAME = " << "\"" << item << "\";"
                  << "static const int INDEX = " << i+1 << ";"
                  << "};"<< std::endl;
    }*/
}
