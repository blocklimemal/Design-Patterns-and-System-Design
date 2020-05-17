// This pattern provides bassically the two thing 
// Abstraction ------> just like the front end 
// implementation -----> api gate way to communicate to the end point 
// Abstraction ------> implementation
// abstraction will have the implementation
#include <iostream>
using namespace std;
class Shape 
{
    public:
        virtual void operational() = 0 ;
};

class Square:public Shape
{
    public:
    Square()
    {

    }
    void operational() override
    {
        cout << "Creating the square" << endl;
    }
};

class Color
{
    protected:
        Shape *shape; 
    public:
        Color(Shape *shape):shape(shape)
        {

        }
        virtual void operation()
        {
            this->shape->operational();          
        }
};

class Red:public Color
{
    public:
        Red(Shape *shape):Color(shape)
        {

        }
        void operation() override
        {
            this->shape->operational();
        }
};
int main()
{
    Square *sq = new Square();
    Red *redSquare = new Red(sq);
    return 0 ;
}