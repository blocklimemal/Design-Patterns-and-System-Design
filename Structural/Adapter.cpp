// The idea behind the adapter pattern is to access the two compatible things 
// like conevrt XML -> JSON // define a adapter that convert XML to json
// Two methods
// mutiple inheritance(Not available in all programming languages) and Structural method
#include <iostream>
#include <string>
using namespace std ;

class XML
{
    public:
        string Request()
        {
            return "Hello -World" ;
        }
};
class JSON
{
    public:
     string Specificreq()
     {
         return "String is JSON";
     }
};

class Adapter:public XML
{
    public:
        JSON *m_json;
        Adapter(JSON *json)
        {
            m_json = json;
        }   
        string Request()
        {
           string json =  m_json->Specificreq();
           cout << json << endl;
           return json;
        }   
};

int main()
{
    JSON *json = new JSON();
    XML *apt = new Adapter(json);
    apt->Request();
    delete json;
    delete apt;
    return  0 ;
}