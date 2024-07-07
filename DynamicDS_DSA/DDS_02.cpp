#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    float gpa;
};

void dynamicStudentArray() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student *students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Age: ";
        cin >> students[i].age;
        cout << "GPA: ";
        cin >> students[i].gpa;
    }

    // Print details of each student
    cout << "\nDetails of students:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "GPA: " << students[i].gpa << endl << endl;
    }

    delete[] students;
}

int main() {
    dynamicStudentArray();
    return 0;
}
