#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float N, x, y;
    cout << "Enter field radius(N): " << endl;
    cin >> N;
    cout << "Enter x coordinate (x): " << endl;
    cin >> x;
    cout << "Enter y coordinate (y): " << endl;
    cin >> y;

    float distance = sqrt(x*x + y*y);
    cout << "Detector blinking frequency: " << distance << endl;

    return 0;
}
