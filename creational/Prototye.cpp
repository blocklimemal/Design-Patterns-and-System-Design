// idea behind the prototype pattern is to allow you have the clone of the objects
// Since the objects can have too many properties so it is quiet difficult to copy 
// such a big object
# include <iostream>
#include <vector>
using namespace std;
class Prototype
{
    public:
        string name;
        virtual Prototype * clone() = 0 ;

        virtual ~Prototype() 
        {

        }
};

class PrototypeA : public Prototype
{

    public:
        string name;
        PrototypeA(string sname)
        {
            cout <<"name :"<< this->name << endl; 
            cout << "Building A" << endl;
            this->name =sname;
        }
        Prototype* clone()
        {   
            return new PrototypeA(*this); // this is implicit conevrsion
        }
};

class PrototypeB : public Prototype
{

    public:
        string name;
        PrototypeB(string sname)
        {
            cout << "Building B" << endl;
            name =sname;
        }
        Prototype* clone()
        {
            
            return new PrototypeB(*this); // this is implicit conevrsion
        }
};

class CloneProto
{
    public:
        vector<Prototype *>proto;
     CloneProto()
     {
         PrototypeA *prot = new PrototypeA("dexter");
         proto.push_back( prot);
        
     }
     Prototype* getClone()
     {
        return proto[0]->clone();
     }
};

int main()
{
    CloneProto *c = new CloneProto();
    Prototype *t = c->getClone();
    cout << t->name << endl;
}