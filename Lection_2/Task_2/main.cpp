#include <iostream>

using namespace std;

void Printlier(int arr[], int count) {
    int maxWidth = 40;
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
}

int main() {
    int arr[20];
    int count = 0;

    for (int num = 0; num < 20; num++) {
        cout << "Enter value: ";
        cin >> arr[num];
        if (arr[num] <= 0) {
            break;
        }
        count++;
    }

    Printlier(arr, count);

    return 0;
}
