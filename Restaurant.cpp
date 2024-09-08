#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MenuItem
{
private:
    string name;     // Hidden
    string category; // Hidden
    double price;    // Hidden

public:
    // Mutator to modify private data
    void setMenuItem(string n, string c, double p)
    {
        this->name = n;
        this->category = c;
        this->price = p;
    }

    // Accessor to access private data
    string getName()
    {
        return name;
    }

    string getCategory()
    {
        return category;
    }

    double getPrice()
    {
        return price;
    }

    // Public method to display item
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
    string name;   // Hidden
    string role;   // Hidden
    double salary; // Hidden

public:
    Employee(string n, string r, double s)
    {
        setName(n);
        setRole(r);
        setSalary(s);
    }

    // Accessors
    string getName()
    {
        return name;
    }

    string getRole()
    {
        return role;
    }

    double getSalary()
    {
        return salary;
    }

    // Mutators
    void setName(string n)
    {
        name = n;
    }

    void setRole(string r)
    {
        role = r;
    }

    void setSalary(double s)
    {
        salary = s;
    }

    // Public methods to display employee details
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
    string name;                  // Hidden
    vector<MenuItem *> menu;      // Hidden
    vector<Employee *> employees; // Hidden
    static int restaurantCount;   // Static member to track the count

public:
    Restaurant()
    {
        restaurantCount++; // Increment the count when a restaurant is created
    }

    // Public Setter (Mutator)
    void setRestaurantName(string n)
    {
        this->name = n;
    }

    // Accessor
    string getRestaurantName()
    {
        return name;
    }

    // Public method to add a menu item
    void addMenuItem(MenuItem *item)
    {
        menu.push_back(item);
    }

    // Public method to add an employee
    void addEmployee(Employee *emp)
    {
        employees.push_back(emp);
    }

    void displayRestaurant()
    {
        cout << "Restaurant Name: " << getRestaurantName() << endl;
        cout << "Menu: " << endl;
        for (int i = 0; i < menu.size(); i++)
        {
            cout << i + 1 << ".";
            menu[i]->display();
        }
        cout << "Employees: " << endl;
        for (int i = 0; i < employees.size(); i++)
        {
            cout << i + 1 << ".";
            employees[i]->display();
        }
    }

    // Static member function
    static int getRestaurantCount()
    {
        return restaurantCount;
    }
};

// Static member variable
int Restaurant::restaurantCount = 0;

int main()
{
    int numRestaurants;

    cout << "Enter the number of restaurants to create: ";
    cin >> numRestaurants;
    cin.ignore();

    for (int r = 0; r < numRestaurants; r++)
    {
        Restaurant *myRestaurant = new Restaurant();

        string restaurantName;
        int numMenuItems, numEmployees;

        cout << "Enter Restaurant Name: ";
        getline(cin, restaurantName);
        myRestaurant->setRestaurantName(restaurantName);

        cout << "Enter the number of menu items: ";
        cin >> numMenuItems;

        for (int i = 0; i < numMenuItems; i++)
        {
            string name;
            string category;
            double price;
            cout << "Enter details for Menu Item " << i + 1 << ":" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Category: ";
            getline(cin, category);
            cout << "Price: ";
            cin >> price;

            MenuItem *item = new MenuItem();
            item->setMenuItem(name, category, price);
            myRestaurant->addMenuItem(item);
        }

        cout << "Enter the number of employees: ";
        cin >> numEmployees;
        for (int i = 0; i < numEmployees; i++)
        {
            string name;
            string role;
            double salary;
            cout << "Enter details for Employee " << i + 1 << ":" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Role: ";
            getline(cin, role);
            cout << "Salary: ";
            cin >> salary;

            Employee *emp = new Employee(name, role, salary);
            myRestaurant->addEmployee(emp);
        }

        myRestaurant->displayRestaurant();

        delete myRestaurant;
    }

    cout << "Total number of restaurants created: " << Restaurant::getRestaurantCount() << endl;

    return 0;
}