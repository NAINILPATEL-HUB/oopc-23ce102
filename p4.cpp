#include<iostream>
#include<iomanip>
using namespace std;


void area(float r)
{
   int q=3.14*r*r;
    cout << "The area of cirlce is " << q << endl;
}

void area(int x,int y)
{
   int w=x*y;
    cout << "The area of rectangle is : " << w << endl;
}

void area(int x,int y, int z)
{
    int e=x*y*z;
    cout << "The area of cuboid is " << e << endl;
}

int main()
{
    float a,b,c,l;
    cout << "Enter the radius of a circle : ";
    cin >> l;
    area(l);
    cout << endl <<"Enter the height of the rectangle : ";
    cin >> a;
    cout << endl << "Enter the width of the rectangle : ";
    cin >> b;
    area(a,b);
    cout << endl << "Enter the height of rhe cuboid : ";
    cin >> a;
    cout << endl <<"Enter the height of rhe cuboid : ";
    cin >> b;
    cout << endl <<"Enter the height of rhe cuboid : ";
    cin >> c;
    area(a,b,c);


    return 0;
}