#include <iostream>

using namespace std;

class Employee {
private:
  int years;
  int months;

public:
  Employee() : years(0), months(0) {}  // Default constructor

  Employee(int y, int m) : years(y), months(m) {}  // Parameterized constructor

  operator float() {
    return years + float(months) / 12.0f;  // Overloaded operator float()
  }

  void displayExperience() {
    cout << years << " years " << months << " months" << endl;  // Display experience
  }
};

int main() {
  int years, months;

  cout << "Enter years of experience: ";
  cin >> years;
  cout << "Enter months of experience: ";
  cin >> months;

  Employee emp(years, months);  // Create Employee object

  cout << "Employee Experience: ";
  emp.displayExperience();

  float total_experience = emp;  // Convert Employee object to float using overloading

  cout << "Total Experience (years): " << total_experience << endl;

  return 0;
}