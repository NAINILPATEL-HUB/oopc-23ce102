#include<iostream>
#include<iomanip>
#include<string>
int n,x;
using namespace std;
class tata
{
    public :
    int mileage,seat;
    float tank,price;
    string name,tra,fuel,air;
    void getdata()
    {
        int x;
        cout<<"enter name of car    :";
        cin>>name;
        fflush(stdin);
        cout<<"enter fuel type of car 1. diesel   2. petrol   3. cng   4. electric    :";
        cin>>x;
        fflush(stdin);
        if (x==1)
            fuel="diesel";
        else if(x==2)
            fuel="petrol";
        else if(x==3)
            fuel="cng";
        else if(x==4)
            fuel="electric";
        cout<<"enter price(lakhs) of car    :";
        cin>>price;
        fflush(stdin);
        cout<<"enter milage of car    :";
        cin>>mileage;
        fflush(stdin);
        cout<<"enter transmission of car:-  1. manual  2.amt    :";
        cin>>x;
        if (x==1)
            tra="manual";
        else if(x==2)
            tra="amt";
        cout<<"enter tank capacity of car    :";
        cin>>tank;
        fflush(stdin);
        cout<<"enter seat capacity of car    :";
        cin>>seat;
        fflush(stdin);
        cout<<"enter 1. airbag  2. not airbag    :";
        cin>>x;
        if(x==1)
            air="yes";
        else if(x==2)
            air="no";
    }
    void detail()
    {
        cout<<"car details :-  "<<endl<<endl;
        cout.width(8);cout<<left<<"Model";
        cout.width(10);cout<<left<<"Fuel";
        cout.width(10);cout<<left<<"Price(lks)";
        cout.width(8);cout<<left<<"Mileage";
        cout.width(15);cout<<left<<"Transmission";
        cout.width(14);cout<<left<<"Tank capacity";
        cout.width(16);cout<<left<<"Seat capacity";
        cout.width(8);cout<<left<<"Airbag"<<endl;
    }
    void putdata()
    {
        cout.width(8);cout<<left<<name;
        cout.width(10);cout<<left<<fuel;
        cout.width(10);cout<<left<<price;
        cout.width(8);cout<<left<<mileage;
        cout.width(15);cout<<left<<tra;
        cout.width(14);cout<<left<<tank;
        cout.width(16);cout<<left<<seat;
        cout.width(8);cout<<left<<air<<endl;
    }
};
int main()
{
    float y;
    cout<<"Enter number of car you want to enter :";
    cin>>n;
    tata cars[n];
    for(int i=0;i<n;i++)
    {
       cars[i].getdata();
    }
    char s;
    do
    {
        cout<<"Get the car details as per your preference : "<<endl;
        cout<<"(1)model name (2)fuel type (3) price range :";
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"List of cars :-"<<endl;
             for(int i=0;i<n;i++)
            {
                cout<<"("<<i+1<<") "<<cars[i].name<<"\t";
            }
            cout<<endl<<"choose no of car to get details :";
            cin>>x;
            cars[0].detail();
            cars[x-1].putdata();
            break;
        case 2:
            cout<<"Fuel option :"<<endl;
            cout<<"(1) diesel  (2) petrol  (3) cng  (4) electric :";
            cin>>x;
            cars[0].detail();
        for(int i=0;i<n;i++)
            {
                if (x==1)
                    {
                        if (cars[i].fuel=="diesel")
                            cars[i].putdata();
                    }
                if (x==2)
                    {
                        if (cars[i].fuel=="petrol")
                            cars[i].putdata();
                    }
                if (x==3)
                    {
                        if (cars[i].fuel=="cng")
                            cars[i].putdata();
                    }
                if (x==4)
                    {
                        if (cars[i].fuel=="electric")
                            cars[i].putdata();
                    }
            }
            break;
        case 3:
            cout<<"enter your price range    :";
            cin>>x;
            cars[0].detail();
            for(int i=0;i<n;i++)
            {
                if (cars[i].price<=x)
                    {
                        cars[i].putdata();
                    }
            }
            break;
        default:
            cout<<"Enter valid option.";
        }
        cout<<"Enter Y or y if you want more    :-";
        cin>>s;
    }while(s=='y'||s=='Y');
   return 0;
}
