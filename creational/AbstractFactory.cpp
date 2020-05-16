// idea behind this pattern is to create the family of the class without knowing the
//concrete classes 

//eg furniture of same type
// All creational patterns are based on making the classes easy to change 
#include <iostream>
using namespace std ;
class Chair
{
    public:
    virtual void operation() = 0 ; 
};

class ModernChair :public Chair
{
    public :
    void operation() override
    {

    }
};
class VintageChair : public Chair
{
    public:
    void operation() override
    {

    }
};

class Table
{
    public:
    virtual void operation() = 0 ; 
};

class ModernTable :public Table
{
    public :
    void operation() override
    {

    }
};
class VintageTable : public Table
{
    public:
    void operation() override
    {

    }
};

class factory
{
    public:
        virtual Table* CreateTable() = 0; 
         virtual Chair* CreateChair() = 0; 
};
class ModernTableChair :public factory
{
    public:
        Table* CreateTable() override
        {
            return new ModernTable();
        } 
         Chair * CreateChair() override
        {
            return new ModernChair();
        } 
        
};
class VintageTableChair :public factory
{
    public:
        Table* CreateTable() override
        {
            return new VintageTable();
        } 
         Chair * CreateChair() override
        {
            return new VintageChair();
        } 
        
};

void clientCode(factory &fact)
{
    Chair *chair = fact.CreateChair();
     Table *table = fact.CreateTable();
     cout << "Both are created" << endl;
}

int main()
{
 ModernTableChair *modern = new ModernTableChair(); 
 clientCode(*modern) ;
 return  0;    
}