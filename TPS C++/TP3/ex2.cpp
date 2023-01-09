#include <iostream>

using namespace std;


class shape 
{
    protected :
        double width ;
        double height;
    public:
        shape(double , double );
    virtual double area()= 0 ;
};

shape::shape(double a, double b): width{a} , height{b}{}


class triangle : public shape
{
    public:
        triangle(double a , double b):shape(a,b){}
        double area();
};


double triangle::area()
{
     return (width*height)*0.5;

}

int main()
{
    double a;
    double b;
    cout<<"width = "<<'\n';
    cin>> a;
    cout<<"height = "<<'\n';
    cin>> b;
    triangle A(a,b);
    double S=A.area();
    cout<<"area = "<<S<<endl;
}


