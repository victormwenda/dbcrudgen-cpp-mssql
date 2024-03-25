#Cmake version
cmake_minimum_required(VERSION 3.24.2)

#Project name
project(dbcrudgen_cpp)

#Project path
set(PROJECT_DIR ${PROJECT_SOURCE_DIR}) #Replace with the path to your project

set(SYS_ARCH ${CMAKE_SYSTEM_PROCESSOR})

#Set build type
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MESSAGE_LOG_LEVEL Debug)

#Set development environment
set(DEV_ENV LINUX_DEBIAN)


#-----------------------------------------------------------------------------------------------------------------------
# LINKER FLAGS
#-----------------------------------------------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)


# MSSQL CONFIGURATIONS -------------------------------------------------------------------------------------------------
set(ODBC_LIBS "")
set(ODBC_HEADERS "")


# OTHER LIBS  ----------------------------------------------------------------------------------------------------------
set(OTHER_LIBS_PATH "")

#-----------------------------------------------------------------------------------------------------------------------
# WINDOWS BUILD ENVIRONMENT
#-----------------------------------------------------------------------------------------------------------------------

if (WIN32)

    # ------------------------------------ MSSQL ----------------------------------------------------------------------#

    set(ODBC_HEADERS ${PROJECT_DIR}/include/db-conn/windows/msodbc/ODBC-Specification/Windows/inc)
    set(ODBC_LIBS_DIR ${PROJECT_DIR}/include/db-conn/windows/msodbc/ODBC/180/KeyFile/1033)
    set(ODBC_LIBS ${ODBC_LIBS_DIR}/sqlodbc_keyfile.dll)

    message(${PROJECT_DIR}\\include/db-conn\\windows\\msodbc\\ODBC-Specification\\Windows\\inc)

endif (WIN32)

#-----------------------------------------------------------------------------------------------------------------------
# LINUX BUILD ENVIRONMENT
#-----------------------------------------------------------------------------------------------------------------------


if (LINUX)

    set(OTHER_LIBS_PATH ${PROJECT_DIR}/lib/linux/others/)

    # ------------------------------------ MSSQL ----------------------------------------------------------------------#

    set(ODBC_HEADERS ${PROJECT_DIR}/include/db-conn/linux/msodbc/msodbcsql18/include/)
    set(ODBC_LIBS_DIR ${PROJECT_DIR}/lib/microsoft/msodbcsql18/lib64)
    #set(ODBC_LIBS ${ODBC_LIBS_DIR}/libmsodbcsql-18.1.so.2.1)
    set(ODBC_LIBS odbc)

endif (LINUX)

#-----------------------------------------------------------------------------------------------------------------------
# MACOS BUILD ENVIRONMENT
#-----------------------------------------------------------------------------------------------------------------------

if (APPLE)

    #Includes/Headers
    set(ODBC_HEADERS
           # ${PROJECT_DIR}/include/connectors/macos/msodbcsql18/18.3.2.1/include/msodbcsql18/msodbcsql.h
            ${PROJECT_DIR}/include/connectors/macos/unixODBC-2.2.12/include
    )

    # Libs
    set(ODBC_LIBS ${PROJECT_DIR}/lib/macos/msodbcsql/13.1.9.2/lib/libmsodbcsql.13.dylib)

endif (APPLE)

#-----------------------------------------------------------------------------------------------------------------------
# ALL CONFIGURATIONS
#-----------------------------------------------------------------------------------------------------------------------

# MSSQL CONFIGURATIONS
include_directories(${ODBC_HEADERS})

#-----------------------------------------------------------------------------------------------------------------------
# SOURCE FILES
#-----------------------------------------------------------------------------------------------------------------------

set(SOURCE_FILES

        src/main.cpp

        src/databases/generic/Column.h
        src/databases/generic/Connection.h
        src/databases/generic/Database.h
        src/databases/generic/Flavor.h
        src/databases/generic/Table.h
        src/databases/generic/User.h

        ##############################################################################################################
        # MSSQL DATABASE SOURCE FILES
        ##############################################################################################################

        src/databases/mssql/builder/MSSQLDatabaseModelBuilder.h
        src/databases/mssql/connectors/MSSQLDbConnParams.h
        src/databases/mssql/connectors/MSSQLDbConnector.h
        src/databases/mssql/decomposer/MSSQLDatabaseDecomposer.h
        src/databases/mssql/decomposer/MSSQLDatabasePreparedDecomposer.h
        src/databases/mssql/decomposer/SpColumnsDecomposer.h
        src/databases/mssql/decomposer/SpTablesDecomposer.h
        src/databases/mssql/decomposer/SysDatabasesDecomposer.h
        src/databases/mssql/executor/MSSQLColBinder.h
        src/databases/mssql/executor/MSSQLQueryExecutor.h
        src/databases/mssql/executor/MSSQLResultSet.h
        src/databases/mssql/models/MSSQLDatabaseModel.h
        src/databases/mssql/models/MSSQLDatabaseSchemas.h
        src/databases/mssql/parsers/MSSQLDatabaseFlattener.h
        src/databases/mssql/scaffolding/queries/MSSQLQueries.h
        src/databases/mssql/scaffolding/entities/SysDatabases.h
        src/databases/mssql/scaffolding/sp/SpColumns.h
        src/databases/mssql/scaffolding/sp/SpTables.h

        ##############################################################################################################
        # SQL GENERIC SOURCE FILES
        ##############################################################################################################
        src/databases/sql/columns/TableColumn.h

        src/databases/sql/connectors/DatabaseConnector.h
        src/databases/sql/connectors/DatabaseConnection.h

        src/databases/sql/dsl/DataType.h

        src/databases/sql/exceptions/DatabaseError.h

        src/databases/sql/models/SQLDatabaseSchemas.h
        src/databases/sql/models/DatabaseSchemas.h
        src/databases/sql/models/DatabaseTable.h

        src/databases/sql/parsers/Tags.h

        src/databases/utils/DatabaseUtils.h

        ##############################################################################################################
        # IO
        ##############################################################################################################

        src/io/FilesReader.h
        src/io/FilesWriter.h
        src/io/FilesManager.h

        ##############################################################################################################
        # LANGUAGE CORE
        ##############################################################################################################
        src/lang/dsl/LanguageDSL.h
        src/lang/dsl/LanguageFilesProperties.h
        src/lang/dsl/CPPLangDSL.h
        src/lang/parser/LangTemplateParser.h

        ##############################################################################################################
        # ORM
        ##############################################################################################################
        src/orm/cli/CliParser.h
        src/orm/cli/DatabaseCrudActions.h

        src/orm/codegen/Databases.h
        src/orm/codegen/Languages.h
        src/orm/codegen/Frameworks.h

        src/orm/codegen/ProjectCodeGen.h

        src/orm/codegen/cpp/CppProjectCodeGen.h

        src/orm/creators/ProjectCreator.h


        src/orm/creators/cpp/CppProjectCreator.h

        src/orm/parsers/SyntaxParser.h
        src/orm/parsers/cpp/CppMYSQLParser.h


        src/orm/parsers/cpp/CppMYSQLSCRUDParser.h


        src/orm/projects/CppProjectModel.h

        src/orm/projects/ProjectModel.h

        src/orm/templates/FileSourceCodeTemplate.h
        src/orm/templates/SourceCodeTemplate.h
        src/orm/templates/StringSourceCodeTemplate.h
        src/orm/templates/TemplateFiles.h


        src/orm/templates/cpp/CppClassTableModelTemplate.h
        src/orm/templates/cpp/CppCtorInitializersTemplate.h
        src/orm/templates/cpp/CppClassTemplate.h
        src/orm/templates/cpp/CppPropertyGetterTemplate.h
        src/orm/templates/cpp/CppPropertySetterTemplate.h
        src/orm/templates/cpp/CppPropertyGetterSetterTemplate.h
        src/orm/templates/cpp/CppClassTableSCRUDTemplate.h
        src/orm/templates/cpp/CppStructTableColumnModelTemplate.h
        src/orm/templates/cpp/CppVariableTemplate.h
        src/orm/templates/cpp/CppTemplateFiles.h

        src/orm/templates/mssql/MSSQLStrTemplates.h

        src/orm/utils/StringUtils.h)

#GoogleTest
#add_subdirectory(include/google/googletest)

#GoogleBenchmark
#add_subdirectory(include/google/benchmark)

#Create executable
add_executable(dbcrudgen_cpp ${SOURCE_FILES})

#-----------------------------------------------------------------------------------------------------------------------
# LIBRARY LINKING
#-----------------------------------------------------------------------------------------------------------------------

#Link with GoogleTest
#target_link_libraries(dbcrudgen_cpp gtest gtest_main pthread)

#Link with GoogleMock
#target_link_libraries(dbcrudgen_cpp gmock gmock_main pthread) - Disable Google Mock

#Link with GoogleBenchmark
#target_link_libraries(dbcrudgen_cpp benchmark) - Disable Google Benchmark

#Link SQLite3 libs
target_link_libraries(dbcrudgen_cpp sqlite3)

#Link MysqlCpp libs
target_link_libraries(dbcrudgen_cpp ${MYSQL_LIBS})

#Link the Oracle libs
target_link_libraries(dbcrudgen_cpp ${OCCI_LIBS})

#Link with ODBC drivers
target_link_libraries(dbcrudgen_cpp ${ODBC_LIBS})

#Copy the template resources
file(COPY res/templates DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

