#include <iostream>
#include <string>
using namespace std;

string& getFullName(string& firstName, string& lastName) {
    string fullName = firstName + " " + lastName;
    return fullName;
}

int main() {
    string firstName = "John";
    string lastName = "Doe";
    string& fullName = getFullName(firstName, lastName);
    cout << "Full Name: " << fullName << endl;

    // 修改全名
    fullName = "Jane Smith";
    cout << "Modified Full Name: " << fullName << endl;
    cout << "First Name: " << firstName << endl;  // firstName也被修改了

    return 0;
}
