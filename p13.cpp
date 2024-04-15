#include <iostream>
#include <iomanip>
using namespace std;

class employee
{
private:
    int id;
    string name;
    string qucalification;
    float experince;
    long long int con_number;
    static float avg_experince;
    static int count;

protected:
    int get_id() {
        return id;
    }

    void getdata()
    {
        fflush(stdin);
        cout << "Enter the Employee ID:";
        cin >> id;
        cout << "Enter Empoyee Name:";
        getchar();
        getline(cin, name);
        cout << "Enter the Qucalification:";
        getline(cin, qucalification);
        cout << "Enter Experince:";
        cin >> experince;
        cout << "Enter the Contact Number:";
        cin >> con_number;
        avg_experince += experince;
        count++;
        fflush(stdin);
    }

    void display() const
    {
        cout.width(20);
        cout << left << "Employee ID" << ":" << id << endl;
        cout.width(20);
        cout << left << "Employee Name" << ":" << name << endl;
        cout.width(20);
        cout << left << "Qucalification" << ":" << qucalification << endl;
        cout.width(20);
        cout << left << "Experince" << ":" << experince << endl;
        cout.width(20);
        cout << left << "Contact Number" << ":" << con_number << endl;
    }

    int searchemp1(int empid) {
        if (empid == id) {
            return 1;
        }
        else {
            return 0;
        }
    }

public:
    employee() {
        id = 0;
        name = "";
        qucalification = "";
        experince = 0.0;
        con_number = 0;
    }

    static void experince_f() {
        cout << "Average Experince of employee " << avg_experince / count << " years" << endl;
    }

    static void total_count() {
        cout << "Total number of employees: " << count << endl;
    }
};

float employee::avg_experince;
int employee::count;

class non_teaching_emp :public employee {
    int salary;
public:
    non_teaching_emp() : employee() {
        salary = 0;
    }

    void getntempdata() {
        getdata();
        cout << "Enter the salary" << endl;
        cin >> salary;
    }

    void putntempdata() {
        display();
        cout.width(20);
        cout << left << "salary" << ":" << salary << endl;
    }

    int seachtemp2(int eid) {
        return searchemp1(eid);
    }
};

class teaching_emp : public employee
{
    string designation;
    string spacialization;
    string pay_scale;

public:
    teaching_emp() : employee() {
        designation = "";
        spacialization = "";
        pay_scale = "";
    }

    void gettempdata() {
        getdata();
        fflush(stdin);
        cout << "Enter the designation" << endl;
        getchar();
        getline(cin, designation);
        cout << "Enter the spacialization" << endl;
        getchar();
        getline(cin, spacialization);
        cout << "Enter the pay_scale" << endl;
        getchar();
        getline(cin, pay_scale);
        fflush(stdin);
    }

    void puttempdata() {
        display();
        cout.width(20);
        cout << left << "Designation" << ":" << designation << endl;
        cout.width(20);
        cout << left << "spacialization" << ":" << spacialization << endl;
        cout.width(20);
        cout << left << "pay_scale" << ":" << pay_scale << endl;
    }

    int seachtemp(int eid) {
        return searchemp1(eid);
    }
};

int main()
{
    int n, i, tn, ntn;

    cout << "Enter the numbers of  teaching employee:";
    cin >> tn;
    teaching_emp* te = new teaching_emp[tn];
    cout << "Enter the numbers of non teaching employee:";
    cin >> ntn;
    non_teaching_emp* nte = new non_teaching_emp[ntn];

    for (int i = 0; i < tn; i++)
    {
        cout << "Enter Teaching Employee " << i + 1 << " detail" << endl;
        te[i].gettempdata();
    }
    for (int i = 0; i < ntn; i++)
    {
        cout << "Enter Non Teaching Employee " << i + 1 << " detail" << endl;
        nte[i].getntempdata();
    }
    char ch;
    int emp_id, g, flage = 0;
    do
    {
        cout << "Enter Employee id which you check:" << endl;
        cin >> emp_id;
        for (i = 0; i < tn; i++)
        {
            g = te[i].seachtemp(emp_id);

            if (g == 1) {
                te[i].puttempdata();
                flage = 1;
                break;
            }
        }
        if (flage == 0) {
            for (i = 0; i < ntn; i++)
            {
                g = nte[i].seachtemp2(emp_id);

                if (g == 1) {
                    nte[i].putntempdata();
                    flage = 1;
                }
            }
        }
        if (flage == 0)
        {
            cout << "ERROR:ENTERED EMPLOYEE ID DOSE NOT EXIST" << endl;
        }
        cout << "Press Y for another Employee detail:";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    employee::experince_f();
    employee::total_count();

    delete[] te;
    delete[] nte;

    return 0;
}
