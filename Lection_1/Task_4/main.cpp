#include <iostream>
#include <cmath>

using namespace std;

float getNumber(const string& prompt){

    float number;
    cout << prompt << endl;
    cin >> number;
    return number;

}

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
    cout << "6 = Apply to the root" << endl;
    cin >> action;

    switch(action) {
    case 1 :
        number1 = getNumber("Enter first number");
        number2 = getNumber("Enter second number");
        cout << number1 + number2;
        break;

    case 2 :
        number1 = getNumber("Enter first number");
        number2 = getNumber("Enter second number");
        cout << number1 - number2;
        break;

    case 3 :
        number1 = getNumber("Enter first number");
        number2 = getNumber("Enter second number");
        cout << number1 * number2;
        break;

    case 4 :
        number1 = getNumber("Enter first number");
        number2 = getNumber("Enter second number");
        cout << number1 / number2;
        break;


    case 5 :
        number1 = getNumber("Enter number");
        cout << number1 * number1 ;
        break;

    case 6 :
        number1 = getNumber("Enter the degree of the root");
        number2 = getNumber("Enter the number under the root");
        cout << pow(number2, 1.0 / number1); ;
        break;
    }

    return 0;
}
