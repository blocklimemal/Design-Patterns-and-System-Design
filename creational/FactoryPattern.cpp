//objects are being called by the factory method that will be a abstract 
// eg:Let's suppose you are desigining a Logistic management, you currrntly have the truck
// but now if you want to extend it to the sea the you can use the factory method to extend it 
// Chair (Modern,Vintage)                  
// Table (Modern,Vintage)

// User want both the types should be same Modern,Modern or Vintage,Vintage
#include <iostream> 
using  namespace std ;
class Product
{
    public:
        virtual ~Product()
        {

        }
        virtual string Operation() = 0 ; 
};

class ProductA :public Product
{
    public: 
    string Operation() override
    {
        return "Creating the productA" ;
    }
};

class ProductB:public Product
{
    public:
    string Operation() override
    {
        return "creating the product B";
    }
};

class Creator
{
    public:
    virtual Product* factorymethod() = 0 ;

    void operations()
    {
        Product *p = this->factorymethod();

        cout << "Created the product " << endl;
        }
  
};
// creator for objet A
class CreatorA:public Creator
{
    public:

    Product *factorymethod() override
    {
        cout << "Created the product A" << endl;
        return new ProductA();
    }

};
// creator for object B
class CreatorB:public Creator
{
    public:

    Product *factorymethod() override
    {
        return new ProductB();
    }

};
// class for requesting the factory method to create the specified object 
void clientClass (Creator &creator)
{
    cout << "Created Object" << endl;
    creator.operations();
}
int main()
{
    Creator *c = new CreatorA();
    clientClass(*c);


}

//note : All theses creational pattern are easy but lengthy 
// The idea is to add the additional feature without making change to the code
