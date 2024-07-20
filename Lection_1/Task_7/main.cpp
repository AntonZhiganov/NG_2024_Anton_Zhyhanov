#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float N, x, y;
    cout << "Enter field radius (N): " << endl;
    cin >> N;
    cout << "Enter x coordinate (x): " << endl;
    cin >> x;
    cout << "Enter y coordinate (y): " << endl;
    cin >> y;

    float distance = sqrt(x*x + y*y);

    if (distance <= N) {
        cout << "Detector blinking frequency: " << distance << endl;
    } else {
        cout << "Point is outside the field radius." << endl;
    }

    return 0;
}
