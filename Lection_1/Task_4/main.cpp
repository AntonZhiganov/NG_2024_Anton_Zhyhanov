#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float number1;
    float number2;
    int action;
    cout << "Calculator" << endl;

    cout << "What do you want to do?" << endl;
    cout << "1 = +" << endl;
    cout << "2 = -" << endl;
    cout << "3 = *" << endl;
    cout << "4 = :" << endl;
    cout << "5 = Number square" << endl;
    cout << "5 = Apply to the root" << endl;
    cin >> action;

    switch(action) {
        case 1 :
            action = 1;
            cout << "Enter first number" << endl;
            cin >> number1;

            cout << "Enter second number" << endl;
            cin >> number2;
            cout << number1 + number2;
            break;

        case 2 :
            action = 2;
            cout << "Enter first number" << endl;
            cin >> number1;

            cout << "Enter second number" << endl;
            cin >> number2;
            cout << number1 - number2;
            break;

        case 3 :
            action = 3;
            cout << "Enter first number" << endl;
            cin >> number1;

            cout << "Enter second number" << endl;
            cin >> number2;
            cout << number1 * number2;
            break;

        case 4 :
            action = 4;
            cout << "Enter first number" << endl;
            cin >> number1;

            cout << "Enter second number" << endl;
            cin >> number2;
            cout << number1 / number2;
            break;

        case 5 :
            action = 5;
            cout << "Enter number" << endl;
            cin >> number1;
            cout << number1 * number1 ;
            break;

        case 6 :
            action = 6;
            cout << "Enter number" << endl;
            cin >> number1;
            cout << sqrt(number1);
            break;
    }

    return 0;
}
