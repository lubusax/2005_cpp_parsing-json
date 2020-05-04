#include <string>
#include <iostream>
#include <fstream>
#include <json/json.h>

//using namespace std;

void decode()
{
    //std::string text ="{ \"people\": [{\"id\": 1, \"name\":\"MIKE\",\"surname\":\"TAYLOR\"}, {\"id\": 2, \"name\":\"TOM\",\"surname\":\"JERRY\"} ]}";
    Json::Value root;
    Json::Reader reader;
    const char * file = "output1.json";
    std::fstream inFile1 {file,std::ios::in};
    bool parsingSuccessful = reader.parse(inFile1, root );
    inFile1.close();
    if ( !parsingSuccessful )
    {
        std::cout << "Error parsing the string" << std::endl;
    }

    const Json::Value mynames = root["people"];
    
    std::cout << mynames.size() << std::endl;

    for ( int index = 0; index < mynames.size(); ++index )
    {
        std::cout << mynames[index]["id"] << std::endl;
    }
    std::cout << mynames << std::endl;

    Json::StyledStreamWriter writer;
    file = "output1.json";
    std::fstream outFile1 {file,std::ios::out};
    //outFile1.open();
    writer.write(outFile1,root);
    outFile1.close();
}



int main()
{
  decode();
  return 1;
}