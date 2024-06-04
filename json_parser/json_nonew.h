#ifndef JSON_NONEW_H
#define JSON_NONEW_H

#include <map>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

/**
 * @namespace json_nonew
 * @brief A namespace that contains classes and functions for parsing and manipulating JSON data without using the `new` operator.
 */
namespace json_nonew
{
    // Forward declaration of JsonNoNew class
    class JsonNoNew;

    // Define a variant type that can hold different types of JSON values
    typedef std::variant<int, double, std::string, std::vector<int>, std::vector<double>, std::vector<std::string>, JsonNoNew> MyJsonValue;

    // Define a type for string constant iterator
    typedef std::string::const_iterator sci_t;

    /**
     * @class JsonNoNew
     * @brief A class that represents a JSON object. It can parse JSON strings and store them in a map.
     */
    class JsonNoNew
    {
    private:
        // Map to store JSON key-value pairs
        std::map<std::string, MyJsonValue> json;

        // Private static method to parse a JSON string
        static JsonNoNew _parse(const std::string &txt, sci_t &it);

    public:
        // Default constructor
        JsonNoNew();

        // Constructor that takes a map of JSON key-value pairs
        JsonNoNew(std::map<std::string, MyJsonValue>);

        // Method to add a key-value pair to the JSON object
        template <typename T>
        void add(std::string key, T value);

        // Method to get the value associated with a key in the JSON object
        template <typename T>
        T &get(const std::string &key);

        // Method to check if a key exists in the JSON object
        bool has_key(const std::string &key);

        // Method to check if the value associated with a key is an empty vector
        bool is_empty_vector(const std::string &key);

        // Static method to parse a JSON string and return a JsonNoNew object
        static JsonNoNew parse(const std::string &txt);

        // Overload the << operator to print the JSON object
        friend std::ostream &operator<<(std::ostream &os, const JsonNoNew &my_json);
    };
}

#include "json_nonew.tcc"

#endif