
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct employee
{
    int employee_id;
    string employee_name;
    string employee_qualification;
    long long int contact_number;

    void getdata()
    {
        cout << "Enter employee id: ";
        cin >> employee_id;
        cout << "Enter employee name: ";
        cin >> employee_name;
        cout << "Enter employee qualification: ";
        cin >> employee_qualification;
        cout << "Enter employee contact number: ";
        cin >> contact_number;
    }

    void displaydata()
    {
        for(int i=0;i<60;i++)
        cout<<"*";
        cout <<left<< setw(31)<<"\nEmployee id" <<":"<< employee_id << endl;
        cout <<left<< setw(30)<<"Employee name " <<":"<<employee_name << endl;
        cout <<left<< setw(30)<<"Employee qualification " <<":"<< employee_qualification << endl;
        cout <<left<< setw(30)<<"Employee contact number " <<":"<<contact_number << endl;
    }
};

int main()
{
    int n, eid;
    cout <<"\nEnter the number of employees: ";
    cin >> n;

    employee e[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter data for employee " << i + 1 << ":\n";
        e[i].getdata();
    }

    char ch;
    do
    {
        for(int i=0;i<60;i++)
        cout<<"*";
        cout <<"\nEnter employee id for information: ";
        cin >> eid;
        for(int i=0;i<60;i++)
        cout<<"*";
        int j;
        for (j = 0; j < n; j++)
        {
            if (eid == e[j].employee_id)
            {
                cout << "\nData for employee " << j + 1 << ":\n";
                e[j].displaydata();
                break;
            }
        }

        if (j == n)
        {
            cout <<"\nEmployee id is not valid." << endl;
        }
        for(int i=0;i<60;i++)
        cout<<"*";
        cout <<"\nIf you want other information press y and for exit press n: ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
