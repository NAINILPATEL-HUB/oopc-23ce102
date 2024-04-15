#include<iostream>
#include<iomanip>
using namespace std;

void printline();
void failline();

class employee
{
    int emp_id;
    string emp_name;
    string qualification;
    float experience;
    long long int contact;
    float avg_experience;
    int t_emp;
    static float tExp;
    static int totalEmp;
    protected:
        void getempdata()
        {
            cout << "Enter employe id : ";
            cin >> emp_id;
            cin.ignore();
            cout << "Enter Name of employe : ";
            getline(cin,emp_name);
            cout << "Enter qualification : ";
            cin>>qualification;
            cout << "your experience in years: ";
            cin >> experience;
            tExp = tExp + experience;
            cout << "Enter Contact number of employee : ";
            cin >> contact;
            totalEmp++;
            cin.ignore();
        }
        void putempydata()
        {
            cout << left << setw(20) << "Employe Name" << ": " << emp_name << endl;
            cout << left << setw(20) << "Qualification" << ": " << qualification << endl;
            cout << left << setw(20) << "Experience" << ": " << experience << endl;
            cout << left << setw(20) << "Contact Number" << ": " << contact << endl; 

        }
        int searchemp()
        {
            return emp_id;
        }
        public:
        void avgexp()
        {
            cout << "Average experience of Employes is : " <<   tExp/(totalEmp)  << " year"<< endl;
        }
};

float employee :: tExp=0;
int employee :: totalEmp=0;
class teaching_emp : public employee
{
    string designation;
    string specialization;
    string pay_scale;
    public:
        int searchtemp(int fid)
        {
            if(fid==searchemp())
            {
                puttempdata();
                return 0;
            }
            return 1;
        }
        void gettempdata()
        {
            getempdata();
            cout << "Enter Designation : ";
            getline(cin,designation);
            cout << "Enter specialization : ";
            getline(cin,specialization);
            cout << "Enter pay scale : ";
            getline(cin,pay_scale);
        }
        void puttempdata()
        {
            putempydata();
            cout << left << setw(20) << "Designation" << ": " << designation << endl;
            cout << left << setw(20) << "Specialization" << ": " << specialization << endl;
            cout << left << setw(20) << "pay scale" << ": " << pay_scale << endl;
            avgexp();
            printline(); 
        }
};

class non_teaching_emp : public employee
{
    int salary;
    public:
        int searchntemp(int fid)
        {
            if(fid==searchemp())
            {
                putntempdata();
                return 0;
            }
        }
        void getntempdata()
        {
            getempdata();
            cout << "Enter salary : ";
            cin >> salary;
        }
        void putntempdata()
        {
            putempydata();
            cout << "Salary : " << salary << endl;
            avgexp();
            printline();
        }
};

int main()
{
    int i,tn,ntn;
    cout << "Enter How many teaching employe : ";
    cin >> tn;
    cout << "Enter how many non-teaching employe : ";
    cin >> ntn;
    class teaching_emp t[tn];
    class non_teaching_emp nt[ntn];
    cout << endl << "ENTER TEACHING EMPLOYE DATA :-" << endl;
    for(i=0 ; i<tn ; i++)
    {
        t[i].gettempdata();
    }
    cout << "ENTER NON-TEACHING EMPLOYE DATA :- " << endl;
    for(i=0; i<ntn ; i++)
    {
        nt[i].getntempdata();
    }
    int fid,c;
    char ch;
    do
    {
    cout << "Enter an employe id : ";
    cin >> fid;
    printline();
    for(i=0 ; i<tn ; i++)
    {
        c=t[i].searchtemp(fid);
        if(c==0)
        {
            break;
        }
    }
    for(i=0 ; i<ntn ; i++)
    {
        c=nt[i].searchntemp(fid);
        if(c==0)
        {
            break;
        }
    }
    if(c!=0)
    {
        failline();
        cout << "ERROR : ENTERED EMPLOYEE ID DOES NOT EXIST";
        failline();
    }
    cout << endl << "Do you want another(y/n)? : ";
    cin >> ch;
    }while(ch=='y');
}

void printline()
{
    int i;
    for(i=0 ; i<50 ; i++)
    {
        cout << "_";
    }
    cout << endl;
}

void failline()
{
    int i;
    cout << endl;
    for(i=0 ; i<35 ; i++)
    {
        cout << "*";
    }
    cout << endl;
}

