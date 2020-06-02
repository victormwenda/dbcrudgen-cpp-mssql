//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 7/1/17.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_STRINGUTILS_H
#define DBCRUDGEN_CPP_STRINGUTILS_H


#include <iostream>
#include <vector>
#include <cstring>

//
// StringUtils
// //
class StringUtils {
public:
    /**
     * Recursively Replaces the tag in the model with the value
     * @param subject string being manipulated
     * @param search string to search
     * @param value string to replace with
     * @return
     */
    static std::string replace(std::string &subject, const std::string &search, const std::string &value) {

        std::size_t firstPosition = subject.find(search);

        if (firstPosition != std::string::npos) {

            subject.replace(firstPosition, search.length(), value);

            return replace(subject, search, value);
        }

        return subject;
    }

    /**
     * Returns if a string contains another string
     * @param subject string to be searched
     * @param search value to be searched
     * @param position position to start from
     * @return
     */
    static bool contains(const std::string &subject, const std::string &search, size_t position = 0) {
        return subject.find(search, position) != std::string::npos;
    }

    /**
     * Splits the provided strings into a string vector
     * @param subject
     * @param delimiter
     * @return
     */
    static std::vector<std::string> split(const std::string &subject, const std::string &delimiter) {
        std::vector<std::string> parts;

        size_t lastPosition = 0;
        size_t currentPosition = 0;

        while ((currentPosition = subject.find(delimiter, lastPosition)) != std::string::npos) {
            std::string text = subject.substr(lastPosition, currentPosition - lastPosition);
            parts.push_back(text);
            lastPosition = ++currentPosition;
        }

        if (subject.find(delimiter) != std::string::npos && (lastPosition != subject.length())) {
            parts.push_back(subject.substr(lastPosition));
        }

        return parts;
    }

    /**
     * Create an all caps header name
     * @param name
     * @return
     */
    static std::string createCapsHeaderName(std::string name) {

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
     * Create a camel case class name
     * @param name
     * @return
     */
    static std::string createClassNameCamelCase(std::string name) {

        name = to_lower(name);
        name[0] = toupper(name[0]);

        std::string class_name;
        std::vector<std::string> parts = split(name.c_str(), "_");

        if (parts.size() == 0) {
            name = to_lower(name);
            name[0] = toupper(name[0]);
            return name;
        }

        for (std::string &part : parts) {

            part = to_lower(part);

            char firstChar = part[0];

            if (isalpha(firstChar) && islower(firstChar)) {
                part[0] = toupper(firstChar);
            }

            class_name += part;
        }

        name = class_name;

        return name;
    }

    /**
     * Create a camel case method name
     * @param name
     * @return
     */
    static std::string createMethodNameCamelCase(std::string name) {

        //Make the first letter upper case
        name[0] = toupper(name[0]);

        //convert all letters after first letter to small letters
        int index = 1;
        while (index < name.length()) {
            name[index] = tolower(name[index]);
            index++;
        }

        std::string method_name;
        std::vector<std::string> parts = split(name.c_str(), "_");

        if (parts.size() == 0) {
            return name;
        }


        int partsIndex = 0;

        for (std::string &part : parts) {

            if (partsIndex == 0) {
                method_name += part;
                partsIndex++;
                continue;
            }

            char partsFirstChar = part[0];

            if (isalpha(partsFirstChar) && islower(partsFirstChar)) {
                part[0] = toupper(partsFirstChar);
            }

            partsIndex++;
            method_name += part;
        }

        name = method_name;

        return name;
    }

    /**
     * Create a camel case variable name
     * @param name
     * @return
     */
    static std::string createVariableNameCamelCase(std::string name) {

        //convert all letters to small letters
        int index = 0;
        while (index < name.length()) {
            name[index] = tolower(name[index]);
            index++;
        }

        std::string variable_name;
        std::vector<std::string> parts = split(name.c_str(), "_");

        if (parts.size() == 0) {
            return name;
        }

        int partsIndex = 0;

        for (std::string &part : parts) {

            if (partsIndex == 0) {
                variable_name += part;
                partsIndex++;
                continue;
            }

            char partsFirstChar = part[0];

            if (isalpha(partsFirstChar) && islower(partsFirstChar)) {
                part[0] = toupper(partsFirstChar);
            }

            partsIndex++;
            variable_name += part;
        }

        name = variable_name;
        return name;
    }

    /**
     * Convert text to upper
     * @param text
     * @return
     */
    static std::string to_upper(std::string text) {

        int index = 0;

        while (index < text.size()) {
            text[index] = toupper(text[index]);
            index++;
        }

        return text;
    }

    /**
     * Convert text to lower
     * @param text
     * @return
     */
    static std::string to_lower(std::string text) {
        int index = 0;

        while (index < text.size()) {
            text[index] = tolower(text[index]);
            index++;
        }

        return text;
    }

    /**
     * Convert text to snake case
     * @param name
     * @return
     */
    static std::string toSnakeCase(std::string name) {
        std::string snake_case;
        int index = 0;

        while (index < name.size()) {

            if (isupper(name[index])) {

                if (snake_case.empty()) {
                    snake_case.append(1, tolower(name[index]));
                } else {
                    snake_case.append("_").append(1, tolower(name[index]));
                }
            } else {
                snake_case.append(1, name[index]);
            }

            index++;
        }

        return snake_case;
    }

    /**
     * Convert text to kebab case
     * Kebab case contains lower case words separated with hyphens.
     * Also called caterpillar case
     * @param name
     * @return
     */
    static std::string toKebabCase(std::string name) {
        std::string snake_case;
        int index = 0;

        while (index < name.size()) {

            if (name[index] == '_') {
                snake_case.append("-");
                index++;
                continue;
            }

            if (isupper(name[index])) {

                if (snake_case.empty()) {
                    snake_case.append(1, tolower(name[index]));
                } else {
                    snake_case.append("-").append(1, tolower(name[index]));
                }
            } else {
                snake_case.append(1, name[index]);
            }


            index++;
        }

        return snake_case;
    }

    /**
     * Create a camel case name
     * @param name
     * @return
     */
    static std::string toCamelCase(std::string name) {

        name = to_lower(name);
        name[0] = toupper(name[0]);

        std::string class_name;
        std::vector<std::string> parts = split(name.c_str(), "_");

        if (parts.size() == 0) {
            name = to_lower(name);
            name[0] = toupper(name[0]);
            return name;
        }

        for (std::string &part : parts) {

            part = to_lower(part);

            char firstChar = part[0];

            if (isalpha(firstChar) && islower(firstChar)) {
                part[0] = toupper(firstChar);
            }

            class_name += part;
        }

        name = class_name;

        return name;
    }

    /**
     * Create a pascal case name
     * @param name
     * @return
     */
    static std::string toPascalCase(std::string name) {

        name = to_lower(name);
        name[0] = toupper(name[0]);

        std::string class_name;
        std::vector<std::string> parts = split(name.c_str(), "_");

        if (parts.size() == 0) {
            name = to_lower(name);
            name[0] = toupper(name[0]);
            return name;
        }

        for (std::string &part : parts) {

            part = to_lower(part);

            char firstChar = part[0];

            if (isalpha(firstChar) && islower(firstChar)) {
                part[0] = toupper(firstChar);
            }

            class_name += part;
        }

        name = class_name;

        return name;
    }

    /**
     * Convert text to space separated title case
     * @param name
     * @return
     */
    static std::string toTitle(std::string name) {
        std::string title;
        int index = 0;

        while (index < name.size()) {

            if (index == 0) {
                title.append(1, toupper(name[index]));
            } else {
                if (name[index] == '_' || name[index] == '-') {
                    title.append(1, toupper(' '));

                    if (index - name.length() - 1) {
                        title.append(1, toupper(name[++index]));
                    }
                } else {
                    title.append(1, name[index]);
                }
            }
            index++;
        }

        return title;
    }
};


#endif //DBCRUDGEN_CPP_STRINGUTILS_H
