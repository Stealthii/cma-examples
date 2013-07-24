#include <iostream>
#include <string>

using namespace std;

int main() {

    string mystr;
    cout << "Please enter your name: ";
    getline(cin,mystr);
    cout << "You entered " << mystr << "\n";
    return(0);
}
