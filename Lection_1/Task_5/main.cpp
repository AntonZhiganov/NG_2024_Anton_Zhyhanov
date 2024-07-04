#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

void QuadraticEquationValues(float a, float b, float c) {

    if (a == 0) {

        cout << "It is not a Quadratic equation." << endl;
        return;

    }

    float discriminant = b * b - 4 * a * c;
    cout << "Discriminant (D) = " << discriminant << endl;

    if (discriminant > 0) {

        float root1 = (-b + sqrt(discriminant)) / (2 * a);
        float root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots of the equation: " << root1 << " and " << root2 << endl;

    }
    else if (discriminant == 0) {

        float root = -b / (2 * a);
        cout << "Root of the equation: " << root << endl;

    }
    else {

        complex<float> root1 = complex<float>(-b / (2 * a), sqrt(-discriminant) / (2 * a));
        complex<float> root2 = complex<float>(-b / (2 * a), -sqrt(-discriminant) / (2 * a));
        cout << "Complex roots of the equation: " << root1 << " and " << root2 << endl;

    }

}

int main() {

    float a, b, c;
    cout << "Quadratic Equation Solver" << endl;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter c: ";
    cin >> c;

    QuadraticEquationValues(a, b, c);

    return 0;

}
