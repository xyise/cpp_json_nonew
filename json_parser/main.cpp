// This is a simple example of how to use the json_nonew library
#include <iostream>
#include <sstream>
#include <string>
#include "json_nonew.h"

using namespace json_nonew;

int main()
{

    JsonNoNew json;
    json.add<std::string>("name", "John");
    json.add<int>("age", 25);

    std::cout << json.get<std::string>("name") << std::endl;
    std::cout << json.get<int>("age") << std::endl;

    JsonNoNew json2;
    json2.add<std::string>("name", "Johnny");
    json2.add<int>("age", 3);

    JsonNoNew json3;
    json3.add<std::string>("name", "Baby");
    json3.add<int>("age", 1);
    json3.add<double>("weight", 10.5);

    json2.add<JsonNoNew>("grand son", json3);
    json2.add<double>("height", 0.75);

    json.add<JsonNoNew>("son", json2);
    json.add<double>("height", 1.75);

    std::cout << json.get<JsonNoNew>("son").get<std::string>("name") << std::endl;

    std::cout << json << std::endl;

    std::stringstream sstrm;
    sstrm << json;
    std::string txt = sstrm.str();

    JsonNoNew json_parsed = JsonNoNew::parse(txt);
    std::cout << "PARSED" << std::endl;
    std::cout << json_parsed << std::endl;
    std::cout << "DONE" << std::endl;
    std::cout << json_parsed.get<JsonNoNew>("son").get<std::string>("name") << std::endl;

    std::string my_json_txt = "{ \n\
        \"name\":   \"John\", \n\
        \"age\":  25, \n\
        \"son\": \t { \n\
            \"name\":    \"Johnny\", \n\
            \"age\": 3,   \"grand son\": {\n\
                \"name\": \"Baby\", \n\
                \"age\": 1, \t \n\
                \"weight\": \t 10.5\n\
                }, \n\
            \"height\": \t 0.75 \n\
            }, \n\
        \"height\": 1.75}";
    JsonNoNew json_parsed2 = JsonNoNew::parse(my_json_txt);
    std::cout << json_parsed2 << std::endl;

    // vectors
    json_parsed2.add<std::vector<int>>("lucky", std::vector<int>({1, 2, 3}));
    json_parsed2.add<std::vector<double>>("doubles", std::vector<double>({12.3, 22.3, 3.0}));
    json_parsed2.get<JsonNoNew>("son").add<std::vector<std::string>>("toys", std::vector<std::string>({"car", "ball", "doll"}) );
    json_parsed2.add<std::vector<std::string>>("empty", std::vector<std::string>());
    std::cout << json_parsed2 << std::endl;

    std::stringstream sstrm2;
    sstrm2 << json_parsed2;
    std::string txt2 = sstrm2.str();    

    JsonNoNew json_parsed3 = JsonNoNew::parse(txt2);
    std::cout << json_parsed3 << std::endl;


    std::cout << "son is a key: " << json_parsed2.has_key("son") << std::endl;
    std::cout << "daughter is not a key: " << json_parsed2.has_key("daughter") << std::endl;
    std::cout << "empty is empty: " << json_parsed2.is_empty_vector("empty") << std::endl;
    std::cout << "double is not empty: " << json_parsed2.is_empty_vector("doubles") << std::endl;

    return 0;
}