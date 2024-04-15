#include<iostream>
using namespace std;

class literature
{

int id;
string title;
public:
void getdata()
{
    cout<<"Enter id of literature"<<endl;
    cin>>id;
    cout<<"Enter title of literature"<< endl;
    cin>>title;
}

void putdata()
{
    cout<<id<<endl;
    cout<<title<<endl;
}
};



class elit:public virtual literature
{

string DOI;
public:
void getdata1()
{
    cout<<"ENTER DOI"<<endl;
    cin>>DOI;

}

void putdata1()
{
    cout<<DOI<<endl;
}

};


class hardbound:public virtual literature
{

int copies;
public:
void getdata2()
{
    cout<<"Enter number of copies in stock"<<endl;
    cin>>copies;

}

void putdata2()
{
    cout<<copies<<endl;
}

};


class books:public elit,public hardbound
{

    int ISBN_no;
    char temp;
    public:
void getdata3()
{
    literature::getdata();
    cout<<"Enter ISBN number:"<<endl;
    cin>>ISBN_no;
    cout<<"(E) copy or (H)hardbound"<<endl;
    cin>>temp;

    if(temp=='E')
    {
        elit::getdata1();
    }
    else if(temp=='H')
    {
        hardbound::getdata2();
    }
}

void putdata3()
{
    literature::putdata();
    cout<<ISBN_no<<endl;
      if(temp=='E')
    {
        elit::putdata1();
    }
    else if(temp=='H')
    {
        hardbound::putdata2();
    }
}
};


class magazines:public elit,public hardbound
{

    int ISSN_no;
    char temp;
    public:
    void getdata4()
    {
        literature::getdata();
        cout<<"Enter the ISSN number:"<<endl;
        cin>>ISSN_no;
        cout<<"(E) copy or (H)hardbound"<<endl;
    cin>>temp;

    if(temp=='E')
    {
        elit::getdata1();
    }
    else if(temp=='H')
    {
        hardbound::getdata2();
    }
    }

    void putdata4()
    {
        literature::putdata();
        cout<<ISSN_no<<endl;
          if(temp=='E')
    {
        elit::putdata1();
    }
    else if(temp=='H')
    {
        hardbound::putdata2();
    }
    }


};


int main()
{
    books b;
    magazines m;
    char ch;
    do
    {


    int choice;
    cout<<"Enter 1 : Add book data"<<endl;
    cout<<"Enter 2 : Add magazine data"<<endl;
    cout<<"Enter 3 : List all books"<<endl;
    cout<<"Enter 4 : List all magazines"<<endl;
    cout<<"Enter your choice : "<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        b.getdata3();
        break;
    case 2:
        m.getdata4();
        break;
    case 3:
        b.putdata3();
        break;
    case 4:
        m.putdata4();
        break;
    default:
        cout<<"INVALID CHOICE!!!!!"<<endl;


    }
    cout<<"Enter M to goto main menu:"<<endl;
    cin>>ch;
    }while(ch=='M' ||ch=='m');
    return 0;
}