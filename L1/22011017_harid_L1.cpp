/*
*******************************
id:22011017
name:haridvarna raman
contact:0125013075
email:haridvarna_22011017@utp.edu.my
lab:1
*/


#include <iostream>
#include <string>
using namespace std;


struct Student {
    int id;
    string name;
    string email;
    string phone;
};

int main() {
    const int SIZE = 5;
    Student students[SIZE];

    
    for (int i = 0; i < SIZE; ++i) {
        cout << "Enter details for student " << (i + 1) << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cin.ignore(); 

        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "Email: ";
        getline(cin, students[i].email);

        cout << "Phone: ";
        getline(cin, students[i].phone);

        cout << endl;
    }

    
    cout << "\nEntered student information:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Student " << (i + 1) << ":\n";
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Email: " << students[i].email << endl;
        cout << "Phone: " << students[i].phone << endl << endl;
    }

    return 0;
}
