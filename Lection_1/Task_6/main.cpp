 #include <iostream>

using namespace std;

void DrawTree(int size) {

    for (int i = 1; i <= size; ++i) {

        for (int j = i; j < size; ++j) {

            cout << " ";

        }
        for (int j = 1; j <= (2 * i - 1); ++j) {

            cout << "*";

        }
        cout << endl;
    }

    for (int i = 0; i < size - 1; ++i) {

        cout << " ";

    }

    cout << "*" << endl;
}

int main() {

    int size;
    cout << "Enter size: ";
    cin >> size;
    DrawTree(size);
    return 0;

}
