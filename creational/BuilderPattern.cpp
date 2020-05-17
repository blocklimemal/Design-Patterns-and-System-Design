// This builder pattern is for the creation of any complex object 
// One is builder and other is the director =====> cretes the builder object 
// The director is present in order to remove the complexity from the user also for the 
// abstraction purpose and to the hide the data and implementation from the client as well
#include <iostream>
#include <vector>
#include <string>
using namespace std ;

// The product that need to be build
class ProductA
{
    public:
    vector <string> part;
     ProductA()
     {

     }

     void add_new_part(string part_)
     {
         part.push_back(part_);
     }

};
class ConcreteClass
{
    public:
        virtual void BuildPartA() = 0 ; 
        virtual void BuildPartB() = 0 ;
};

class Builder:public ConcreteClass
{
    public:
    ProductA *prod;

    Builder()
    {
        this->start();
    }

    void start()
    {
        prod = new ProductA();
    }

    void BuildPartA() override
    {
        prod->add_new_part("PARTa");
    }
    void BuildPartB() override
    {
            prod->add_new_part("PARTb");
    }

};

class Director
{
    public:
    Builder *bd ; 
    Director()
    {
        bd = new Builder();
    }
    void startBuilding()
    {
        bd->BuildPartA();
        bd->BuildPartB();
    }
};

void clientClass(Director &dir)
{
    dir.startBuilding();
}
int main()
{
    Director *d = new Director();
    clientClass(*d);
    return 0;
}

// idea is to move away the complexity from the constructor
// We don't want to overload the constructor with too many args so we decide 
// to build the product by parts
