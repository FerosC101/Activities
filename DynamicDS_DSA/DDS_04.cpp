#include <iostream>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
};

void manageEmployees() {
    int numEmployees;
    int choice;
    Employee *employees = nullptr;

    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter details for employee " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> employees[i].id;
        cout << "Name: ";
        cin.ignore();
        getline(cin, employees[i].name);
        cout << "Salary: ";
        cin >> employees[i].salary;
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new employee\n";
        cout << "2. Delete an employee by ID\n";
        cout << "3. Print all employee details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add a new employee
                Employee *newEmployees = new Employee[numEmployees + 1];
                for (int i = 0; i < numEmployees; ++i) {
                    newEmployees[i] = employees[i];
                }
                cout << "Enter details for the new employee:\n";
                cout << "ID: ";
                cin >> newEmployees[numEmployees].id;
                cout << "Name: ";
                cin.ignore();
                getline(cin, newEmployees[numEmployees].name);
                cout << "Salary: ";
                cin >> newEmployees[numEmployees].salary;
                delete[] employees;
                employees = newEmployees;
                numEmployees++;
                break;
            }
            case 2: {
                int deleteID;
                cout << "Enter the ID of the employee to delete: ";
                cin >> deleteID;
                int foundIndex = -1;
                for (int i = 0; i < numEmployees; ++i) {
                    if (employees[i].id == deleteID) {
                        foundIndex = i;
                        break;
                    }
                }
                if (foundIndex != -1) {
                    Employee *newEmployees = new Employee[numEmployees - 1];
                    for (int i = 0, j = 0; i < numEmployees; ++i) {
                        if (i != foundIndex) {
                            newEmployees[j++] = employees[i];
                        }
                    }
                    delete[] employees;
                    employees = newEmployees;
                    numEmployees--;
                    cout << "Employee with ID " << deleteID << " deleted.\n";
                } else {
                    cout << "Employee with ID " << deleteID << " not found.\n";
                }
                break;
            }
            case 3: {
                cout << "\nDetails of employees:\n";
                for (int i = 0; i < numEmployees; ++i) {
                    cout << "Employee " << i + 1 << ":\n";
                    cout << "ID: " << employees[i].id << endl;
                    cout << "Name: " << employees[i].name << endl;
                    cout << "Salary: " << employees[i].salary << endl << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    delete[] employees;
}

int main() {
    manageEmployees();
    return 0;
}
