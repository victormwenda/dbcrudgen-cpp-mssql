//
// Created by victor on 3/15/20.
//

#ifndef DBCRUDGEN_CPP_SYNTAXPARSER_H
#define DBCRUDGEN_CPP_SYNTAXPARSER_H

#include <string>
#include "../utils/StringUtils.h"

namespace dbcrudgen {
    namespace orm {
        class SyntaxParser {
        public:

            /**
            * Create C++ header name
            * @param name
            * @return
            */
            static std::string parseProjectNameToHeaderName(std::string name) {

                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity

                int index = 0;
                while (index < name.length()) {

                    if (!isalpha(name[index])) {
                        name[index] = '_';
                    } else {
                        name[index] = toupper(name[index]);
                    }

                    index++;
                }

                return name;
            }

            /**
            * Create C++ header name
            * @param name
            * @return
            */
            static std::string parseClassNameToHeaderName(std::string name) {

                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity

                int index = 0;
                while (index < name.length()) {

                    if (!isalpha(name[index])) {
                        name[index] = '_';
                    } else {
                        name[index] = toupper(name[index]);
                    }

                    index++;
                }

                return name;
            }

            /**
             * Create C++ Class name
             * @param name
             * @return
             */
            static std::string toCppClassName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createClassNameCamelCase(name);
            }

            /**
             * Create C++ method name
             * @param name
             * @return
             */
            static std::string toCppMethodName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createMethodNameCamelCase(name);
            }

            /**
            * Create C++ Variable name
            * @param name
            * @return
            */
            static std::string toCppVariableName(std::string name) {
                //TODO :: Validate name is not reserved, if reserved, add prefix or suffix impurity
                return StringUtils::createVariableNameCamelCase(name);
            }

        };
    }
}
#endif //DBCRUDGEN_CPP_SYNTAXPARSER_H
