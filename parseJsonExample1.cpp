#include <string>
#include <iostream>
#include <fstream>
#include <json/json.h>

//using namespace std;

void decode()
{
    Json::Value root;
    Json::Reader reader;
    const char * file = "thingsGate.json";
    std::fstream inFile1 {file,std::ios::in};
    bool parsingSuccessful = reader.parse(inFile1, root );
    inFile1.close();
    if ( !parsingSuccessful )
    {
        std::cout << "Error parsing the string" << std::endl;
    }

    const Json::Value displayCustomizing = root["thingsGate"]["display"]["customizing"];
    
    //std::cout << thingsGate.size() << std::endl;

    // for ( int index = 0; index < thingsGate.size(); ++index )
    // {
    //     std::cout << thingsGate[index] << std::endl;
    // }

    const Json::Value   activeScreenOption 
                        = displayCustomizing["screen"]["active"];
    int i               = activeScreenOption.asLargestInt();
    std::cout << 
        displayCustomizing["screen"]["options"][i]
             << std::endl;

    // Json::StyledStreamWriter writer;
    // file = "output1.json";
    // std::fstream outFile1 {file,std::ios::out};
    // //outFile1.open();
    // writer.write(outFile1,root);
    // outFile1.close();
}



int main()
{
  decode();
  return 1;
}