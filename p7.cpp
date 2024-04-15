#include<iostream>
using namespace std;
class ABC
{
private:
    int real;
    int imag;
public:
    ABC(int r=0, int i=0):real(r),imag(i){}

    ABC operator+ (const ABC& other) const
    {
        return ABC(real + other.real, imag + other.imag);
    }

    ABC operator- (const ABC& other) const
    {
        return ABC(real - other.real, imag - other.imag);
    }

    ABC operator* (const ABC& other) const
    {
        return ABC(real *other.real - imag *other.imag ,real *other.imag + imag *other.real);
    }

    ABC operator/ (const ABC& other) const
    {
        int denominator = other.real * other.real + other.imag * other.imag;
        return ABC((real * other.real + imag * other.imag)/denominator,
                   (imag * other.real - real * other.imag)/denominator);
    }
    ABC operator!()const
    {
        return ABC(-real,-imag);
    }
    void display() const
    {
        cout<< real<<"+"<<imag<<"i";
    }
};
int main()
{
    int a,b,c,d;
    cout<<"enter the real part:";
    cin>>a;
    cout<<"enter the iamg part:";
    cin>>b;
    cout<<"enter the real part:";
    cin>>c;
    cout<<"enter the imag part:";
    cin>>d;

    ABC c1(a,b);
    ABC c2(c,d);
    ABC result;

    char ch;
    cout<<"enter the operator (+,-,*,/,!):";
    cin>>ch;

    switch(ch)
    {
        case '+':
        result = c1+c2;
        break;

        case '-':
        result =c1-c2;
        break;

        case '*':
        result = c1*c2;
        break;

        case '/':
        result = c1/c2;
        break;

        case '!':
        result=!c1;
        result+!c2;
        break;
        default:
            cout<<"invalid";
            return 1;
    }
    cout<<"result";
    result.display();
    cout<<endl;
    return 0;
}
