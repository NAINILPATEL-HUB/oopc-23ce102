#include <iostream>
#include <iomanip>
using namespace std;

void print_marksheet();

int main() {
    print_marksheet();
    return 0;
}

void print_marksheet()
 {
    string student_name, student_id;
    int semester, i, theory[3], pract[3], gp1[3], gp2[3];
    int t_credit[3] = {2, 2, 2}, p_credit[3] = {1, 1, 1};
    float sum = 0, total_credit = 0, sgpa;
    string subject[3], grade1[3], grade2[3];

    cout << "Enter student id  :";
    cin >> student_id;
    cout << "Enter student name :";
    cin >> student_name;
    cout << "Enter student semester :";
    cin >> semester;


    cout << "Enter 3 subject names :\n";
    for (i = 0; i < 3; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> subject[i];
    }

    cout << "\nEntered subjects:\n";
    for (i = 0; i < 3; i++) {
        cout << "Subject " << i + 1 << ": " << subject[i] << "\n";
    }
    for (i = 0; i < 3; i++) {
        cout << "\nEnter theory and practical marks of " << subject[i] << "\n";
        cout << "Theory: ";
        cin >> theory[i];
        cout << "Practical: ";
        cin >> pract[i];
    }

    for (i = 0; i < 3; i++) {
        if (theory[i] >= 80) {
            grade1[i] = "AA";
            gp1[i] = 10;
        } else if (theory[i] >= 73 && theory[i] < 80) {
            grade1[i] = "AB";
            gp1[i] = 9;
        } else if (theory[i] >= 66 && theory[i] < 73) {
            grade1[i] = "BB";
            gp1[i] = 8;
        } else if (theory[i] >= 60 && theory[i] < 66) {
            grade1[i] = "BC";
            gp1[i] = 7;
        } else if (theory[i] >= 55 && theory[i] < 60) {
            grade1[i] = "CC";
            gp1[i] = 6;
        } else if (theory[i] >= 50 && theory[i] < 55) {
            grade1[i] = "CD";
            gp1[i] = 5;
        } else if (theory[i] >= 45 && theory[i] < 50) {
            grade1[i] = "DD";
            gp1[i] = 4;
        } else {
            grade1[i] = "FF";
            gp1[i] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        if (pract[i] >= 80) {
            grade2[i] = "AA";
            gp2[i] = 10;
        } else if (pract[i] >= 73 && pract[i] < 80) {
            grade2[i] = "AB";
            gp2[i] = 9;
        } else if (pract[i] >= 66 && pract[i] < 73) {
            grade2[i] = "BB";
            gp2[i] = 8;
        } else if (pract[i] >= 60 && pract[i] < 66) {
            grade2[i] = "BC";
            gp2[i] = 7;
        } else if (pract[i] >= 55 && pract[i] < 60) {
            grade2[i] = "CC";
            gp2[i] = 6;
        } else if (pract[i] >= 50 && pract[i] < 55) {
            grade2[i] = "CD";
            gp2[i] = 5;
        } else if (pract[i] >= 45 && pract[i] < 50) {
            grade2[i] = "DD";
            gp2[i] = 4;
        } else {
            grade2[i] = "FF";
            gp2[i] = 0;
        }
    }
    cout << "\nEntered student details" << "\n";
    cout << left << setw(20) << "Student ID" << left << ":" << student_id << "\n";
    cout << left << setw(20) << "Student Name" << left << ":" << student_name << "\n";
    cout << left << setw(20) << "Student Semester" << left << ":" << semester << "\n\n";

    cout << "\nGrades for each subject:\n";
    cout << left << setw(20) << "Subject" << setw(15) << "Grade Theory" << setw(15) << "Grade Practical" << "\n";
       for (i = 0; i < 3; i++)
        {
          cout << left << setw(20) << subject[i] << setw(15) << grade1[i] << setw(15) << grade2[i] << "\n";
        }

      for (i = 0; i < 3; i++)
        {
          sum += gp1[i] * t_credit[i] + gp2[i] * p_credit[i];
          total_credit += t_credit[i] + p_credit[i];
        }

     sgpa = sum / total_credit; 

cout << "\n SGPA is: " << setw(20)<<setprecision(2) << sgpa << endl; 

}
