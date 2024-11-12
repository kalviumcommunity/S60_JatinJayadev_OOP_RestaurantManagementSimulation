#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
private:
    string name;

public:
    Person(string n) : name(n) {}

    string getName() { return name; }

    void display()
    {
        cout << "Name: " << name << endl;
    }
};

// Derived class Employee (Single Inheritance)
class Employee : public Person
{
private:
    string role;
    double salary;

public:
    Employee(string n, string r, double s) : Person(n), role(r), salary(s) {}

    Employee() : Person("NA"), role("NA"), salary(0.0) {}

    string getRole() { return role; }
    double getSalary() { return salary; }

    // Function Overloading for Polymorphism
    void display()
    {
        cout << "Employee: " << getName() << endl
             << "  Role: " << getRole() << endl
             << "  Salary: " << getSalary() << endl;
    }

    void display(bool showSalary)
    {
        cout << "Employee: " << getName() << endl
             << "  Role: " << getRole() << endl;
        if (showSalary)
        {
            cout << "  Salary: " << getSalary() << endl;
        }
    }
};

// Base class MenuItem
class MenuItem
{
private:
    string name;
    string category;
    double price;

public:
    MenuItem(string n, string c, double p) : name(n), category(c), price(p) {}

    string getName() { return name; }
    string getCategory() { return category; }
    double getPrice() { return price; }

    // Function Overloading for Polymorphism
    void display()
    {
        cout << "Item: " << getName() << endl
             << "  Category: " << getCategory() << endl
             << "  Price: " << getPrice() << endl;
    }

    void display(bool showCategory)
    {
        cout << "Item: " << getName() << endl;
        if (showCategory)
        {
            cout << "  Category: " << getCategory() << endl;
        }
        cout << "  Price: " << getPrice() << endl;
    }
};

// Restaurant class to hold menu and employees
class Restaurant
{
private:
    string name;
    vector<MenuItem> menu;
    vector<Employee> employees;

public:
    Restaurant(string n) : name(n) {}

    void setRestaurantName(string n) { name = n; }

    string getRestaurantName() { return name; }

    void addMenuItem(const MenuItem &item) { menu.push_back(item); }

    void addEmployee(const Employee &emp) { employees.push_back(emp); }

    void displayRestaurant()
    {
        cout << "Restaurant Name: " << getRestaurantName() << endl;
        cout << "Menu: " << endl;
        for (int i = 0; i < menu.size(); i++)
        {
            cout << i + 1 << ". ";
            menu[i].display(true); // Using overloaded display with additional detail
        }
        cout << "Employees: " << endl;
        for (int i = 0; i < employees.size(); i++)
        {
            cout << i + 1 << ". ";
            employees[i].display(false); // Using overloaded display with less detail
        }
    }
};

int main()
{
    string restaurantName;
    cout << "Enter restaurant name: ";
    getline(cin, restaurantName);
    Restaurant myRestaurant(restaurantName);

    int menuCount;
    cout << "Enter the number of menu items: ";
    cin >> menuCount;
    cin.ignore();

    for (int i = 0; i < menuCount; i++)
    {
        string itemName, itemCategory;
        double itemPrice;

        cout << "\nEnter details for Menu Item " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, itemName);
        cout << "Category: ";
        getline(cin, itemCategory);
        cout << "Price: ";
        cin >> itemPrice;
        cin.ignore();

        MenuItem item(itemName, itemCategory, itemPrice);
        myRestaurant.addMenuItem(item);
    }

    int employeeCount;
    cout << "\nEnter the number of employees: ";
    cin >> employeeCount;
    cin.ignore();

    for (int i = 0; i < employeeCount; i++)
    {
        string empName, empRole;
        double empSalary;
        cout << "\nEnter details for Employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, empName);
        cout << "Role: ";
        getline(cin, empRole);
        cout << "Salary: ";
        cin >> empSalary;
        cin.ignore();

        Employee emp(empName, empRole, empSalary);
        myRestaurant.addEmployee(emp);
    }

    cout << "\nDisplaying Restaurant Details:\n";
    myRestaurant.displayRestaurant();

    return 0;
}
