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
    void hello()
    {
        cout << "I am Menu Item" << endl;
        ;
    }
};

class Employee
{
private:
    string name;
    string role;
    double salary;

public:
    void hello()
    {
        cout << "I am employee" << endl;
    }
};

int main()
{
    MenuItem pizza;
    pizza.hello();

    Employee Shiva;
    Shiva.hello();
    return 0;
}