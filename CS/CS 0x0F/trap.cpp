#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 0;
    try {
        cout << "Result: " << (a / b) << endl;
    } catch (const exception& e) {
        cerr << "Exception caught: Division by zero!" << endl;
    }
    return 0;
}