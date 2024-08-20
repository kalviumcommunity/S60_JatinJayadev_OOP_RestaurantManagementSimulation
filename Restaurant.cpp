#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;

class MenuItem
{
private:
    string name;
    string category;
    double price;

public:
    void setMenuItem(string n, string c, double p)
    {
        this->name = n;
        this->category = c;
        this->price = p;
    }

    void display()
    {
        cout << "Item: " << this->name << endl
             << "Category: " << this->category << endl
             << "Price: " << this->price << endl;
    }
};

class Employee
{
private:
    string name;
    string role;
    double salary;

public:
    Employee(string n, string r, double s)
    {
        this->name = n;
        this->role = r;
        this->salary = s;
    }

    void display()
    {
        cout << "Employee: " << this->name << endl
             << "Role: " << this->role << endl
             << "Salary: " << this->salary << endl;
    }
};

int main()
{
    MenuItem Rice;
    Rice.setMenuItem("Rice", "Dinner", 100.0);
    cout << "Menu: " << endl;
    Rice.display();

    Employee shiva("Shiva", "Chef", 50000.0);
    cout << "Employee: " << endl;
    shiva.display();
    return 0;
}