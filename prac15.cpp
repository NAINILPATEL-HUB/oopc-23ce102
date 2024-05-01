#include<iostream>
using namespace std;
class product
{
protected:
    int product_id;
    string product_name,product_manufacturer;
    float product_price;
public:
    product(int id,string name,string manufacturer,float price)
    {
        product_id=id;
        product_name=name;
        product_manufacturer=manufacturer;
        product_price=price;
    }
    void virtual display()=0;
};
class smartwatch:public product
{
    float dial_size;
public:
    smartwatch(int id,string name,string manufacturer,float price,float d_size):product(id,name,manufacturer,price)
    {
        dial_size=d_size;
    }
    void display()
    {
cout<<"-------------------------------"<<endl;
cout<<product_id<<" : "<< product_name<<" : "<< product_manufacturer<<" : "<<product_price<<" : "<<dial_size<<endl;
cout<<"-------------------------------"<<endl;
    }
};
class bedsheet:public product
{
    float width,height;
public:
    bedsheet(int id,string name,string manufacturer,float price,float w,float h):product(id,name,manufacturer,price)
    {
        width=w;
        height=h;
    }
    void display()
    {
cout<<"-------------------------------"<<endl;
cout<<product_id<<" : "<< product_name<<" : "<< product_manufacturer<<" : "<<product_price<<" : "<<width<<":"<<height<<endl;
cout<<"-------------------------------"<<endl;
    }
};
int main()
{
    smartwatch *p1;
    bedsheet *p2;
    int choice;
    int id;
    float price,d_size,w,h;
    string name,manufacturer;
    cout<<"Enter 1:smart watch"<<endl;
    cout<<"Enter 2:bedsheet"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;

    switch(choice)
    {
    case 1:
cout<<"ENTER SMARTWATCH DATA"<<endl;
        cout<<"Enter product ID:";
        cin>>id;
cin.ignore();
        cout<<"Enter product name:";
        getline(cin,name);
        cout<<"Enter product manufacturer:";
        getline(cin,manufacturer);
        cout<<"Enter product price:";
        cin>>price;
        cout<<"Enter dial size:";
        cin>>d_size;
        p1=new smartwatch(id,name,manufacturer,price,d_size);
        p1->display();
        break;
    case 2:
    cout<<"ENTER BEDSHEET DATA"<<endl;
        cout<<"Enter product ID:";
        cin>>id;
         cin.ignore();
        cout<<"Enter product name:";
getline(cin,name);
        cout<<"Enter product manufacturer:";
       getline(cin,manufacturer);
        cout<<"Enter product price:";
        cin>>price;
        cout<<"Enter bedsheet width:";
        cin>>w;
        cout<<"Enter bedsheet height:";
        cin>>h;
         p2=new bedsheet(id,name,manufacturer,price,w,h);
         p2->display();
        break;
    }
    return 0;
}

