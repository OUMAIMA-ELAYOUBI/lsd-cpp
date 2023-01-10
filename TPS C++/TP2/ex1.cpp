#include <iostream>
#include <cmath>
using namespace std;

template<typename type>



type multiply(type m,int n)
{
    return m*n;
}





int main()
{
    int n;
    float m;
    cout<<"\n n=";
    cin>>n;
    cout<<"\n m=";
    cin>>m;  
    cout<<"\n n*m= "<<multiply(m,n)<<endl;
