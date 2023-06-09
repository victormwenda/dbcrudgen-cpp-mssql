//
// Created by victor on 7/6/20.
//

#ifndef DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
#define DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H


#include "JavaParser.h"
#include "../../../databases/utils/DatabaseUtils.h"

namespace dbcrudgen {
    namespace orm {
        class SpringBootApplicationParser : public JavaParser {
        public:

            /**
            * substitute project details
            * @param model
            * @param sbAppClassSrc
            */
            static void substituteProjectDetails(const SpringBootProjectModel &model, std::string &sbAppClassSrc) {

                StringUtils::replace(sbAppClassSrc, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(sbAppClassSrc, "${SB_APPLICATION_PACKAGE}", model.getSBAppClassPkg());
                StringUtils::replace(sbAppClassSrc, "${CONTROLLERS_PACKAGE}", model.getControllersPkg());
                StringUtils::replace(sbAppClassSrc, "${DAOS_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(sbAppClassSrc, "${ENTITIES_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(sbAppClassSrc, "${REPOSITORIES_PACKAGE}", model.getRepositoriesPkg());
                StringUtils::replace(sbAppClassSrc, "${SERVICES_PACKAGE}", model.getBzLogicPkg());
                StringUtils::replace(sbAppClassSrc, "${CLASS_NAME}", model.getSBAppClassName());

            }

            /**
             * Substitute controller details
             * @param model
             * @param ctrlSource
             * @param ctrlClass
             * @param entityClass
             * @param bzLogicClass
             * @param apiResName
             * @return
             */
            static std::string
            substituteControllerDetails(const SpringBootProjectModel &model, const dbcrudgen::db::generic::Table &table,
                                        const db::generic::Column &column, std::string ctrlSource,
                                        const std::string &ctrlClass,
                                        const std::string &entityClass,
                                        const std::string &bzLogicClass, const std::string &modelClass,
                                        const std::string &apiResName) {

                std::string tableClassName = JavaParser::toJavaClassName(table.getTableName());
                std::string tablePkgName = StringUtils::to_lower(tableClassName);
                std::string requestsPksName = model.getHttpReqPkg() + '.' + tablePkgName;
                std::string responsesPksName = model.getHttpResPkg() + '.' + tablePkgName;

                StringUtils::replace(ctrlSource, "${PROJECT_PACKAGE}", model.getPackageName());

                StringUtils::replace(ctrlSource, "${CONTROLLER_PACKAGE}", model.getControllersPkg());
                StringUtils::replace(ctrlSource, "${CONTROLLER_CLASS}", ctrlClass);

                StringUtils::replace(ctrlSource, "${BZLOGIC_PACKAGE}", model.getBzLogicPkg());
                StringUtils::replace(ctrlSource, "${BZLOGIC_CLASS}", bzLogicClass);
                std::string bzLogicObject = toJavaVariableLocal(bzLogicClass);
                StringUtils::replace(ctrlSource, "${BZLOGIC_OBJECT}", bzLogicObject);


                StringUtils::replace(ctrlSource, "${MODEL_PACKAGE}", model.getModelsPkg());
                StringUtils::replace(ctrlSource, "${MODEL_CLASS}", modelClass);
                std::string modelObject = toJavaVariableLocal(modelClass);
                StringUtils::replace(ctrlSource, "${MODEL_OBJECT}", modelObject);
                StringUtils::replace(ctrlSource, "${MODEL_OBJECT_SETTER}", tableClassName);

                StringUtils::replace(ctrlSource, "${TABLE_CLASS}", tableClassName);
                std::string tableObject = toJavaVariableLocal(tableClassName);
                StringUtils::replace(ctrlSource, "${TABLE_OBJECT}", tableObject);
                StringUtils::replace(ctrlSource, "${REQUEST_TABLE_PACKAGE}", requestsPksName);
                StringUtils::replace(ctrlSource, "${RESPONSE_TABLE_PACKAGE}", responsesPksName);

                StringUtils::replace(ctrlSource, "${PK_COLUMN_NAME}", column.getColumnName());
                StringUtils::replace(ctrlSource, "${PK_COLUMN_DATATYPE}",
                                     toJavaPrimitiveDataTypeFromSQL(column.getDataType()));

                std::string methodGetter = "get";
                methodGetter = methodGetter.append(toJavaClassName(column.getColumnName()));
                StringUtils::replace(ctrlSource, "${PK_METHOD_GETTER}", methodGetter);

                StringUtils::replace(ctrlSource, "${RESOURCE-NAME}", apiResName);
                return ctrlSource;
            }

            /**
             * Substitute controller details
             * @param model
             * @param table
             * @param column
             * @param ctrlSource
             * @param ctrlClass
             * @param entityClass
             * @param trxClass
             * @param modelClass
             * @param repoClass
             * @param httpReqPostClass
             * @param httpReqPutClass
             * @param apiResName
             * @return
             */
            static std::string
            substituteDbServiceDetails(const SpringBootProjectModel &model, const dbcrudgen::db::generic::Table &table,
                                       const db::generic::Column &column, std::string ctrlSource,
                                       const std::string &entityClass, const std::string &trxClass,
                                       const std::string &modelClass, const std::string &repoClass,
                                       const std::string &httpReqPostClass, const std::string &httpReqPutClass
            ) {

                std::string tableClassName = JavaParser::toJavaClassName(table.getTableName());
                std::string tablePkgName = StringUtils::to_lower(tableClassName);
                std::string requestsPksName = model.getHttpReqPkg() + '.' + tablePkgName;
                std::string responsesPksName = model.getHttpResPkg() + '.' + tablePkgName;

                StringUtils::replace(ctrlSource, "${PROJECT_PACKAGE}", model.getPackageName());

                StringUtils::replace(ctrlSource, "${DAOS_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(ctrlSource, "${DAO_CLASS}", trxClass);


                StringUtils::replace(ctrlSource, "${REPOSITORY_PACKAGE}", model.getRepositoriesPkg());
                StringUtils::replace(ctrlSource, "${REPOSITORY_CLASS}", repoClass);
                std::string repoObject = toJavaVariableLocal(repoClass);
                StringUtils::replace(ctrlSource, "${REPOSITORY_OBJECT}", repoObject);


                StringUtils::replace(ctrlSource, "${ENTITY_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(ctrlSource, "${ENTITY_CLASS}", entityClass);
                std::string entityObject = toJavaVariableLocal(entityClass);
                StringUtils::replace(ctrlSource, "${ENTITY_OBJECT}", entityObject);

                StringUtils::replace(ctrlSource, "${MODEL_PACKAGE}", model.getModelsPkg());
                StringUtils::replace(ctrlSource, "${MODEL_CLASS}", modelClass);
                std::string modelObject = toJavaVariableLocal(modelClass);
                StringUtils::replace(ctrlSource, "${MODEL_OBJECT}", modelObject);

                StringUtils::replace(ctrlSource, "${TABLE_CLASS}", tableClassName);
                StringUtils::replace(ctrlSource, "${REQUEST_TABLE_PACKAGE}", requestsPksName);
                StringUtils::replace(ctrlSource, "${RESPONSE_TABLE_PACKAGE}", responsesPksName);

                StringUtils::replace(ctrlSource, "${POST_REQUEST_CLASS}", httpReqPostClass);
                std::string postClassObject = toJavaVariableLocal(httpReqPostClass);
                StringUtils::replace(ctrlSource, "${POST_REQUEST_OBJECT}", postClassObject);

                StringUtils::replace(ctrlSource, "${PUT_REQUEST_CLASS}", httpReqPutClass);
                std::string putClassObject = toJavaVariableLocal(httpReqPutClass);
                StringUtils::replace(ctrlSource, "${PUT_REQUEST_OBJECT}", putClassObject);

                StringUtils::replace(ctrlSource, "${PK_OBJECT}", column.getColumnName());
                StringUtils::replace(ctrlSource, "${PK_COLUMN_DATATYPE}",
                                     toJavaPrimitiveDataTypeFromSQL(column.getDataType()));


                return ctrlSource;
            }

            /**
             * Create business logic source file
             * @param model
             * @param table
             * @param column
             * @param bzLogicSource
             * @param bzLogicClass

             * @param trxClass
             * @param modelClass
             * @param repoClass
             * @param httpReqPostClass
             * @param httpReqPutClass
             * @param apiResName
             * @return
             */
            static std::string
            substituteBusinessLogicServiceDetails(const SpringBootProjectModel &model,
                                                  const dbcrudgen::db::generic::Table &table,
                                                  const db::generic::Column &column, std::string bzLogicSource,
                                                  const std::string &bzLogicClass, const std::string &trxClass,
                                                  const std::string &modelClass, const std::string &entityClass,
                                                  const std::string &httpReqPostClass,
                                                  const std::string &httpReqPutClass) {

                std::string tableClassName = JavaParser::toJavaClassName(table.getTableName());
                std::string tablePkgName = StringUtils::to_lower(tableClassName);
                std::string requestsPksName = model.getHttpReqPkg() + '.' + tablePkgName;
                std::string responsesPksName = model.getHttpResPkg() + '.' + tablePkgName;

                StringUtils::replace(bzLogicSource, "${PROJECT_PACKAGE}", model.getPackageName());

                StringUtils::replace(bzLogicSource, "${BZLOGIC_PACKAGE}", model.getBzLogicPkg());
                StringUtils::replace(bzLogicSource, "${BZLOGIC_CLASS}", bzLogicClass);


                StringUtils::replace(bzLogicSource, "${DAOS_PACKAGE}", model.getTransactionsPkg());
                StringUtils::replace(bzLogicSource, "${DAO_CLASS}", trxClass);
                std::string trxObject = toJavaVariableLocal(trxClass);
                StringUtils::replace(bzLogicSource, "${DAO_OBJECT}", trxObject);

                StringUtils::replace(bzLogicSource, "${MODEL_PACKAGE}", model.getModelsPkg());
                StringUtils::replace(bzLogicSource, "${MODEL_CLASS}", modelClass);
                std::string modelObject = toJavaVariableLocal(modelClass);
                StringUtils::replace(bzLogicSource, "${MODEL_OBJECT}", modelObject);

                StringUtils::replace(bzLogicSource, "${ENTITY_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(bzLogicSource, "${ENTITY_CLASS}", entityClass);
                std::string entityObject = toJavaVariableLocal(entityClass);
                StringUtils::replace(bzLogicSource, "${ENTITY_OBJECT}", entityObject);

                StringUtils::replace(bzLogicSource, "${TABLE_CLASS}", tableClassName);
                StringUtils::replace(bzLogicSource, "${REQUEST_TABLE_PACKAGE}", requestsPksName);
                StringUtils::replace(bzLogicSource, "${RESPONSE_TABLE_PACKAGE}", responsesPksName);

                StringUtils::replace(bzLogicSource, "${POST_REQUEST_CLASS}", httpReqPostClass);
                std::string postClassObject = toJavaVariableLocal(httpReqPostClass);
                StringUtils::replace(bzLogicSource, "${POST_REQUEST_OBJECT}", postClassObject);

                StringUtils::replace(bzLogicSource, "${PUT_REQUEST_CLASS}", httpReqPutClass);
                std::string putClassObject = toJavaVariableLocal(httpReqPutClass);
                StringUtils::replace(bzLogicSource, "${PUT_REQUEST_OBJECT}", putClassObject);

                StringUtils::replace(bzLogicSource, "${PK_OBJECT}", column.getColumnName());
                StringUtils::replace(bzLogicSource, "${PK_COLUMN_DATATYPE}",
                                     toJavaPrimitiveDataTypeFromSQL(column.getDataType()));

                std::string methodGetter = "get";
                methodGetter = methodGetter.append(toJavaClassName(column.getColumnName()));
                StringUtils::replace(bzLogicSource, "${PK_METHOD_GETTER}", methodGetter);


                return bzLogicSource;
            }

            /**
            * Substitute http req class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpReqClassDetails(const SpringBootProjectModel &model, std::string &pkgName,
                                          std::string httpReqClsSource,
                                          const std::string &httpReqClsName, const std::string &modelClass) {
                StringUtils::replace(httpReqClsSource, "${CLASS_NAME}", httpReqClsName);
                StringUtils::replace(httpReqClsSource, "${VISIBILITY}", "public");
                StringUtils::replace(httpReqClsSource, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(httpReqClsSource, "${HTTP_REQ_PACKAGE}", model.getHttpReqPkg());
                StringUtils::replace(httpReqClsSource, "${TABLE_PACKAGE}", pkgName);
                return httpReqClsSource;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpResClassDetails(const dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                          const dbcrudgen::db::generic::Table &table,

                                          std::string httpResClsSource, const std::string &httpResClsName,
                                          const std::string &modelClass) {
                std::string tmpClassName = JavaParser::toJavaClassName(table.getTableName());
                std::string pkgName = StringUtils::to_lower(tmpClassName);

                StringUtils::replace(httpResClsSource, "${CLASS_NAME}", httpResClsName);
                StringUtils::replace(httpResClsSource, "${VISIBILITY}", "public");
                StringUtils::replace(httpResClsSource, "${PROJECT_PACKAGE}", projectModel.getPackageName());
                StringUtils::replace(httpResClsSource, "${HTTP_RES_PACKAGE}", projectModel.getHttpResPkg());
                StringUtils::replace(httpResClsSource, "${TABLE_PACKAGE}", pkgName);
                StringUtils::replace(httpResClsSource, "${MODEL_PACKAGE}", projectModel.getModelsPkg());
                StringUtils::replace(httpResClsSource, "${MODEL_CLASS}", modelClass);
                StringUtils::replace(httpResClsSource, "${TABLE_CLASS}", tmpClassName);

                std::string modelObject = toJavaVariableLocal(modelClass);
                StringUtils::replace(httpResClsSource, "${MODEL_OBJECT}", modelObject);

                return httpResClsSource;
            } /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpResWithListClassDetails(const dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                                  const dbcrudgen::db::generic::Table &table,

                                                  std::string httpResClsSource, const std::string &httpResClsName,
                                                  const std::string &modelClass) {
                std::string tmpClassName = JavaParser::toJavaClassName(table.getTableName());
                std::string pkgName = StringUtils::to_lower(tmpClassName);

                StringUtils::replace(httpResClsSource, "${CLASS_NAME}", httpResClsName);
                StringUtils::replace(httpResClsSource, "${VISIBILITY}", "public");
                StringUtils::replace(httpResClsSource, "${PROJECT_PACKAGE}", projectModel.getPackageName());
                StringUtils::replace(httpResClsSource, "${HTTP_RES_PACKAGE}", projectModel.getHttpResPkg());
                StringUtils::replace(httpResClsSource, "${TABLE_PACKAGE}", pkgName);
                StringUtils::replace(httpResClsSource, "${MODEL_PACKAGE}", projectModel.getModelsPkg());
                StringUtils::replace(httpResClsSource, "${MODEL_CLASS}", modelClass);
                StringUtils::replace(httpResClsSource, "${TABLE_CLASS}", tmpClassName);

                std::string modelObject = toJavaVariableLocal(modelClass);
                StringUtils::replace(httpResClsSource, "${MODEL_OBJECT}", modelObject);

                return httpResClsSource;
            }

            /**
            * Substitute models class details
            * @param model
            * @return
            */
            static std::string
            substituteModelClassDetails(const dbcrudgen::orm::SpringBootProjectModel &projectModel,
                                        std::string modelClsSrc, const std::string &modelClassName) {
                StringUtils::replace(modelClsSrc, "${CLASS_NAME}", modelClassName);
                StringUtils::replace(modelClsSrc, "${VISIBILITY}", "public");
                StringUtils::replace(modelClsSrc, "${PROJECT_PACKAGE}", projectModel.getPackageName());
                StringUtils::replace(modelClsSrc, "${MODELS_PACKAGE}", projectModel.getModelsPkg());
                return modelClsSrc;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteHttpRequestInstanceVariables(std::string &httpReqSource, const std::string &httpReqInstanceVars) {
                StringUtils::replace(httpReqSource, "${INSTANCE_VARIABLES}", httpReqInstanceVars);
                return httpReqSource;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteModelInstanceVariables(std::string &modelSource, const std::string &instanceVars) {
                StringUtils::replace(modelSource, "${INSTANCE_VARIABLES}", instanceVars);
                return modelSource;
            }

            /**
            * Substitute model setters
            * @param model
            * @return
            */
            static std::string
            substituteModelGetterSetters(std::string &modelSource, const std::string &modelGetterSetters) {
                StringUtils::replace(modelSource, "${GETTER_SETTER_METHODS}", modelGetterSetters);
                return modelSource;
            }

            /**
            * Substitute model getters
            * @param model
            * @return
            */
            static std::string
            substituteModelGetters(std::string &modelSource, const std::string &modelGetters) {
                StringUtils::replace(modelSource, "${GETTER_METHODS}", modelGetters);
                return modelSource;
            }

            /**
            * Substitute http res class details
            * @param model
            * @return
            */
            static std::string
            substituteRepoClassDetails(const SpringBootProjectModel &model, std::string &repoClsSource,
                                       const std::string &repoClass, const std::string &entityClass) {
                StringUtils::replace(repoClsSource, "${PROJECT_PACKAGE}", model.getPackageName());
                StringUtils::replace(repoClsSource, "${SB_REPOSITORIES_PACKAGE}", model.getRepositoriesPkg());
                StringUtils::replace(repoClsSource, "${ENTITIES_PACKAGE}", model.getEntitiesPkg());
                StringUtils::replace(repoClsSource, "${CLASS_NAME}", repoClass);
                StringUtils::replace(repoClsSource, "${ENTITY_CLASS}", entityClass);
                return repoClsSource;
            }

            static std::string
            substituteRepoPrimaryKeyCol(std::string &repoSource, const std::string &pkDataType) {
                StringUtils::replace(repoSource, "${PK_DATATYPE}", pkDataType);
                return repoSource;
            }


            static std::string
            parseApplicationProperties(const SpringBootProjectModel &model, const db::generic::Database &database,
                                       std::string &propertiesSrc) {
                const db::generic::Connection &connection = database.getConnection();
                const std::string &dbHost = connection.getHost();
                const std::string &user = connection.getUser();
                int port = connection.getPort();
                const std::string &dbName = connection.getDatabase();
                const db::generic::Flavor &flavor = database.getFlavor();
                const std::string &password = connection.getPassword();
                std::string connStr = dbcrudgen::db::DatabaseUtils::genDbConnStrJava(flavor, dbHost, port, user,
                                                                                     password, dbName);

                const std::string dbType = dbcrudgen::db::DatabaseUtils::getDbType(flavor);
                const std::string hibernateDialect = dbcrudgen::db::DatabaseUtils::getHibernateDialect(flavor);

                StringUtils::replace(propertiesSrc, "${SERVER_PORT}", std::to_string(model.getServerPort()));
                StringUtils::replace(propertiesSrc, "${DATABASE_DRIVER}", getDatabaseDriver(flavor));
                StringUtils::replace(propertiesSrc, "${DATABASE_CONNECTION_STRING}", connStr);
                StringUtils::replace(propertiesSrc, "${DATABASE_USER}", user);
                StringUtils::replace(propertiesSrc, "${USER_PASSWORD}", password);
                StringUtils::replace(propertiesSrc, "${DATABASE_TYPE}", dbType);
                StringUtils::replace(propertiesSrc, "${HIBERNATE_DIALECT}", hibernateDialect);


                return propertiesSrc;
            }

            static void
            substituteTrxClassPostRequestEntityData(std::string &trxServiceSource, const std::string &modelData) {
                StringUtils::replace(trxServiceSource, "${ENTITY_DATA_FROM_POST_REQUEST}", modelData);
            }

            static void
            substituteTrxClassPutRequestEntityData(std::string &trxServiceSource, const std::string &modelData) {
                StringUtils::replace(trxServiceSource, "${ENTITY_DATA_FROM_PUT_REQUEST}", modelData);
            }

            static void substituteTrxClassModelData(std::string &trxDaoSource, const std::string &entityData) {
                StringUtils::replace(trxDaoSource, "${MODEL_DATA_FROM_ENTITY}", entityData);
            }

            static void
            substituteBzLogicServiceModelData(std::string &serviceClassSource, const std::string &entityData) {
                StringUtils::replace(serviceClassSource, "${MODEL_DATA_FROM_ENTITY}", entityData);
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_SPRINGBOOTAPPLICATIONPARSER_H
