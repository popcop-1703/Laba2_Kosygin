#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the square: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    cout << "Enter the character to fill the square with: ";
    char fillChar;
    cin >> fillChar;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                cout << "*";
            }
            else {
                if (i == j || i + j == size - 1) {
                    cout << fillChar;
                }
                else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}