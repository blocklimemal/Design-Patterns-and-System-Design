// singelton pattern suggest that your class need to have one instance 
// This is useful when you are doing resource intensive programming 
// like multithreading ======>  driver implementation of hardware devices
#include <iostream>
using namespace std ;
class Singelton
{
    public:
        static Singelton *singelton ;
        static Singelton* get_instance()
        {
            if(singelton == NULL)
                return singelton= new Singelton();
            else
            {
                cout << "already initialzed" << endl;
                return singelton;
            }
            
        }
    private:
        Singelton()
        {
            cout << "singelton initiated" << endl;
        } 
    
};

Singelton * Singelton:: singelton= 0; // initiate a variable

int main()
{
    Singelton *sin = sin->get_instance();
    sin->get_instance();
}