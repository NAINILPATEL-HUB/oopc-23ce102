#include <iostream>

using namespace std;

class Employee {
private:
  int years;
  int months;

public:
  Employee() : years(0), months(0) {}

  Employee(float experience) {
    years = int(experience);
    months = int((experience - years) * 12);
  }

  void displayExperience() {
    cout << years << " years " << months << " months" << endl;
  }
};

int main() {
  float experience_in_years;

  cout << "Enter years of experience : ";
  cin >> experience_in_years;

  Employee emp(experience_in_years);

  cout << "Employee Experience: ";
  emp.displayExperience();

  return 0;
}