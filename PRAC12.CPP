#include <iostream>
#include <iomanip>
using namespace std;

class Student {
private:
    string student_name;
    string student_id;
    int semester;
    string subject[3];
    int theory[3];
    int pract[3];
    string grade1[3];
    string grade2[3];
    int gp1[3];
    int gp2[3];
    int t_credit[3] = {2, 2, 2};
    int p_credit[3] = {1, 1, 1};
    float sum;
    float total_credit;
    float cgpa;

public:
    void getDetails() {
        cout << "Enter student id  :";
        cin >> student_id;
        cout << "Enter student name :";
        cin >> student_name;
        cout << "Enter student semester :";
        cin >> semester;

        cout << "Enter 3 subject names :\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> subject[i];
        }

        cout << "\nEnter theory and practical marks for each subject:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << subject[i] << ":\n";
            cout << "Theory: ";
            cin >> theory[i];
            cout << "Practical: ";
            cin >> pract[i];
        }
    }

    void calculateGrades() {
        for (int i = 0; i < 3; i++) {
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

        for (int i = 0; i < 3; i++) {
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
    }

    void calculateCGPA() {
        sum = 0;
        total_credit = 0;
        for (int i = 0; i < 3; i++) {
            sum += gp1[i] * t_credit[i] + gp2[i] * p_credit[i];
            total_credit += t_credit[i] + p_credit[i];
        }
        cgpa = sum / total_credit;
    }

    void printMarksheet() {
        cout << "\nEntered student details" << "\n";
        cout << left << setw(20) << "Student ID" << left << ":" << student_id << "\n";
        cout << left << setw(20) << "Student Name" << left << ":" << student_name << "\n";
        cout << left << setw(20) << "Student Semester" << left << ":" << semester << "\n\n";

        cout << "\nGrades for each subject:\n";
        cout << left << setw(20) << "Subject" << setw(15) << "Grade Theory" << setw(15) << "Grade Practical" << "\n";
        for (int i = 0; i < 3; i++) {
            cout << left << setw(20) << subject[i] << setw(15) << grade1[i] << setw(15) << grade2[i] << "\n";
        }

        cout << "\nCGPA is: " << setw(20) << setprecision(2) << cgpa << endl;
    }
};

int main() {
    Student student;
    student.getDetails();
    student.calculateGrades();
    student.calculateCGPA();
    student.printMarksheet();
    return 0;
}
