#include <string>
#include <iostream>
#include <json/json.h>

//using namespace std;

void decode()
{
    std::string text ="{ \"people\": [{\"id\": 1, \"name\":\"MIKE\",\"surname\":\"TAYLOR\"}, {\"id\": 2, \"name\":\"TOM\",\"surname\":\"JERRY\"} ]}";
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse( text, root );
    if ( !parsingSuccessful )
    {
        std::cout << "Error parsing the string" << std::endl;
    }

    const Json::Value mynames = root["people"];
    
    std::cout << mynames.size() << std::endl;

    for ( int index = 0; index < mynames.size(); ++index )
    {
        std::cout << mynames[index] << std::endl;
    }

// Json::Value value1;
// value1 = mynames.get("name", "default");
//     std::cout << value1 << std::endl;

}



int main()
{
  decode();
  return 1;
}