#include<iostream>
using namespace std;
int count = 0;

class circle {
    float area;
    int radius;

public:
    circle() {
        radius = 1;
        area = 3.14 * radius;
        count++;
        display();
        count_display();
    }

    circle(int r) {
        radius = r;
        area = 3.14 * radius;
        count++;
        display();
        count_display();
    }

    circle(circle& c) {
        radius = c.radius;
        area = c.area;
        count++;
        display();
        count_display();
    }

    void display() const {
        cout << "Circle with radius " << radius << " has area =" << area << endl;
    }

    void count_display() const {
        cout << "Total active object is = " << count << endl;
    }
    ~circle() {
        cout << "one object deleted" << endl;
        count--;
        count_display();
    }
};

int main() {
    circle* c1 = new circle;
    circle* c2 = new circle(20);
    circle* c3 = new circle(*c2);


    delete c1;
    delete c2;
    delete c3;
    return 0;
}