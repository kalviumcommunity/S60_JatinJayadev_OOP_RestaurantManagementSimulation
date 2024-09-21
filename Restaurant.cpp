#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MenuItem
{
private:
    string name;
    string category;
    double price;

public:
    MenuItem(string n, string c, double p)
    {
        name = n;
        category = c;
        price = p;
    }

    ~MenuItem()
    {
        cout << "Destructor is called for MenuItem: " << name << endl;
    }

    string getName() { return name; }
    string getCategory() { return category; }
    double getPrice() { return price; }

    void display()
    {
        cout << "Item: " << getName() << endl
             << "  Category: " << getCategory() << endl
             << "  Price: " << getPrice() << endl;
    }
};

class Employee
{
private:
    string name;
    string role;
    double salary;

public:
    Employee()
    {
        name = "NA";
        role = "NA";
        salary = 0.0;
    }

    Employee(string n, string r, double s)
    {
        name = n;
        role = r;
        salary = s;
    }

    ~Employee()
    {
        cout << "Destructor is called for Employee: " << name << endl;
    }

    string getName() { return name; }
    string getRole() { return role; }
    double getSalary() { return salary; }

    void display()
    {
        cout << "Employee: " << getName() << endl
             << "  Role: " << getRole() << endl
             << "  Salary: " << getSalary() << endl;
    }
};

class Restaurant
{
private:
    string name;
    vector<MenuItem> menu;
    vector<Employee> employees;

public:
    Restaurant(string n)
    {
        name = n;
    }

    ~Restaurant()
    {
        cout << "Destructor called for Restaurant: " << name << endl;
    }

    void setRestaurantName(string n)
    {
        this->name = n;
    }

    string getRestaurantName()
    {
        return name;
    }

    void addMenuItem(const MenuItem &item)
    {
        menu.push_back(item);
    }

    void addEmployee(const Employee &emp)
    {
        employees.push_back(emp);
    }

    void displayRestaurant()
    {
        cout << "Restaurant Name: " << getRestaurantName() << endl;
        cout << "Menu: " << endl;
        for (int i = 0; i < menu.size(); i++)
        {
            cout << i + 1 << ". ";
            menu[i].display();
        }
        cout << "Employees: " << endl;
        for (int i = 0; i < employees.size(); i++)
        {
            cout << i + 1 << ". ";
            employees[i].display();
        }
    }
};

int main()
{
    Restaurant myRestaurant("Snack Bites");

    MenuItem item1("Burger", "Snack", 8.5);
    myRestaurant.addMenuItem(item1);

    Employee emp1("Alice", "Manager", 3000);
    myRestaurant.addEmployee(emp1);

    Employee defaultEmployee;
    myRestaurant.addEmployee(defaultEmployee);

    myRestaurant.displayRestaurant();

    return 0;
}
