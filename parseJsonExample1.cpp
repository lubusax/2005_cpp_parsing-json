#include <string>
#include <iostream>
#include <json/json.h>

using namespace std;

void decode()
{
    string text ="{ \"people\": [{\"id\": 1, \"name\":\"MIKE\",\"surname\":\"TAYLOR\"}, {\"id\": 2, \"name\":\"TOM\",\"surname\":\"JERRY\"} ]}";
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse( text, root );
    if ( !parsingSuccessful )
    {
        cout << "Error parsing the string" << endl;
    }

    const Json::Value mynames = root["people"];

    for ( int index = 0; index < mynames.size(); ++index )
    {
        cout << mynames[index] << endl;
    }
}

int main()
{
  decode();
  return 1;
}