#include<iostream>
using namespace std;

class employee {
public:
    int id;
    string name, qual;
    float exp;
    int mo_no;
    static int count_call;
    static float total_experience;

public:
    void getdata() {
        cout << "Please Enter the Name of the Employee:" << endl;
        cin >> name;
        cout << "Please Enter the Qualification of the Employee:" << endl;
        cin >> qual;
        cout << "Please Enter the Experience of the Employee:" << endl;
        cin >> exp;
        total_experience += exp;
        cout << "Please Enter the Mobile Number of the Employee:" << endl;
        cin >> mo_no;
        count_call++;
    }

    void displaydata() const {
        cout << "Name of the Employee:" << name << endl;
        cout << "Qualification of the Employee:" << qual << endl;
        cout << "Experience of the Employee:" << exp << endl;
        cout << "Mobile Number of the Employee:" << mo_no << endl;
    }

    static void displaycount() {
        cout << "Number of employee data entries: " << count_call << endl;
    }

    static float avg_exp() {
        if (count_call == 0) {
            return 0;
        }
        return total_experience / count_call;
    }
};

int employee::count_call = 0;
float employee::total_experience = 0;

int main() {
    int numEmployees;
    cout << "Enter the number of employees you want to enter data for: ";
    cin >> numEmployees;

    employee *employees = new employee[numEmployees];

    for (int i = 0; i < numEmployees; ++i) {
        cout << "Please Enter the Id for employee " << (i + 1) << ":" << endl;
        cin >> employees[i].id;

        if (employees[i].id < 1000 || employees[i].id > 9999) {
            cout << "Invalid Id Entered" << endl;
            --i; // Re-prompt for the same employee
            continue;
        }

        employees[i].getdata();
        employees[i].displaydata();

        cout << "Press Y to enter data for another employee or press N to exit : ";
        char opt;
        cin >> opt;

        if (opt != 'Y' && opt != 'y') {
            break;
        }
    }

    employee::displaycount();
    cout << "Average experience of all employees: " << employee::avg_exp() << " years" << endl;

    delete[] employees; // Deallocate the dynamic array
    return 0;
}
