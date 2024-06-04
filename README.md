# cpp_json_nonew

C++ json parser without dynamic memory allocation. std::variant is used to store the different types of json values.

This repo contains a reduced-version json parser that parses a json string and store the content in a map.
    * stores integers, doubles, strings, vectors of integers, doubles, strings and other json objects.
    * parses json strings and store them in an object.
    * converts a json object to a string.

Notes:
    * gcc in Linux is required to run `make` to compile the code.
    * C++ 17 is required. Only the standard library (std) is used. No external libraries are used.
    * No dynamic memory allocation is used. The standard library containers utilised in the implementation should have move semantics, so that the memory should not be copied when the objects are moved.
    * While exceptions are thrown when the json string is invalid, the parser may not be able to detect all invalid json strings.

