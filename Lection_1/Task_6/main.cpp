 #include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;
    for (int row = 1; row <= size; ++row) {
        for (int symbol = row; symbol < size; ++symbol) {
            cout << " ";
        }
        for (int symbol = 1; symbol <= (2 * row - 1); ++symbol) {
            cout << "*";
        }
        cout << endl;
    }

    for (int row = 0; row < size - 1; ++row) {
        cout << " ";
    }
    cout << "*" << endl;
    return 0;
}
