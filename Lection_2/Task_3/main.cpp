#include <iostream>

using namespace std;

int main(){
    int arr[20];
    int count = 0;
    int maxStars = 0;

    for (int num = 0; num < 20; num++) {
        cout << "Enter number of stars: ";
        cin >> arr[num];
        if (arr[num] < 0) {
            break;
        }
        if (arr[num] > maxStars) {
            maxStars = arr[num];
        }
        count++;
    }

    for (int row = 0; row < maxStars; row++) {
        for (int column = 0; column < count; column++) {
            if (row < arr[column]) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
