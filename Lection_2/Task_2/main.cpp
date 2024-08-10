#include <iostream>

using namespace std;

int main() {
    int arr[20];
    int count = 0;
    int maxWidth = 40;

    for (int num = 0; num < 20; num++) {
        cout << "Enter value: ";
        cin >> arr[num];
        if (arr[num] <= 0) {
            break;
        }
        count++;
    }

    for (int numA = 0;  numA < count;  numA++) {
        int padding = (maxWidth - arr[ numA]) / 2;
        for (int spc = 0; spc < padding; spc++) {
            cout << ' ';
        }
        for (int line = 0; line < arr[ numA]; line++) {
            cout << "*";
        }
        cout << endl;
    }


    return 0;
}
