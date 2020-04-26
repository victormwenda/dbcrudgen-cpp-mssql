//
// Created by victor on 3/23/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELPROJECTMODEL_H
#define DBCRUDGEN_CPP_LARAVELPROJECTMODEL_H

#include "PHPMYSQLProjectModel.h"
#include "../codegen/Frameworks.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelProjectModel : public PHPProjectModel {

        private:
            std::string controllersDir;
            std::string modelsDir;
            std::string viewsDir;
            std::string routesDir;
            std::string assetsDir;
            std::string jsDir;
            std::string cssDir;
            std::string webRoutesFile;
            std::string apiRoutesFile;
            std::string apiVersion;

        public:

            /**
            * PHP MYSQL Project Model
            *
            * @param projectName
            * @param workspaceDir
            * @param generatedCodeDir
            */
            LaravelProjectModel(std::string &projectName, std::string &workspaceDir, std::string &controllersDir,
                                std::string &modelsDir, std::string &viewsDir, std::string &routesDir,
                                std::string assetsDir, std::string jsDir, std::string cssDir,
                                std::string &webRoutesFile, std::string &apiRoutesFile, std::string &apiVersion)
                    : PHPProjectModel{projectName, workspaceDir, assetsDir, jsDir, cssDir},
                      controllersDir{controllersDir}, modelsDir{modelsDir}, viewsDir{viewsDir}, routesDir{routesDir},
                      assetsDir{assetsDir}, jsDir{jsDir}, cssDir{cssDir},
                      webRoutesFile{webRoutesFile}, apiRoutesFile{apiRoutesFile}, apiVersion{apiVersion} {}


            std::string getFramework() override {
                return std::string{Frameworks::PHP::LARAVEL};
            }

            const std::string &getControllersDir() const {
                return controllersDir;
            }

            const std::string &getModelsDir() const {
                return modelsDir;
            }

            const std::string &getViewsDir() const {
                return viewsDir;
            }

            const std::string &getRoutesDir() const {
                return routesDir;
            }

            const std::string &getWebRoutesFile() const {
                return webRoutesFile;
            }

            const std::string &getApiRoutesFile() const {
                return apiRoutesFile;
            }

            const std::string &getApiVersion() const {
                return apiVersion;
            }

            /**
             * Get the full path to Controllers directory
             * @return
             */
            std::string getControllersFullDir() {
                return getProjectDir() + "/" + getControllersDir();
            }

            /**
             * Get the full path to Models directory
             * @return
             */
            std::string getModelsFullDir() {
                return getProjectDir() + "/" + getModelsDir();
            }

            /**
            * Get the full path to Views directory
            * @return
            */
            std::string getViewsFullDir() {
                return getProjectDir() + "/" + getViewsDir();
            }

            /**
             * Get the full path to API's directory
             * @return
             */
            std::string getRoutesFullDir() {
                return getProjectDir() + "/" + getRoutesDir();
            }

            /**
             * Get the full path to API's directory
             * @return
             */
            std::string getWebRouteFilePath() {
                return getRoutesFullDir() + "/" + getWebRoutesFile();
            }

            /**
             * Get the full path to API's directory
             * @return
             */
            std::string getApiRouteFilePath() {
                return getRoutesFullDir() + "/" + getApiRoutesFile();
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_LARAVELPROJECTMODEL_H
