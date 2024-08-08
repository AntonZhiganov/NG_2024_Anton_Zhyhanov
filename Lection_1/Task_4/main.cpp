#include <iostream>
#include <cmath>

using namespace std;

float getNumber(const string& prompt){

    float number;
    cout << prompt << endl;
    cin >> number;
    return number;

}

pair<float, float> getTwoNumbers(const string& prompt1, const string& prompt2) {
    float number1 = getNumber(prompt1);
    float number2 = getNumber(prompt2);
    return make_pair(number1, number2);
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
    case 1 :{
        auto numbers = getTwoNumbers("Enter first number", "Enter second number");
        cout << numbers.first + numbers.second;
        break;
    }

    case 2 :{
        auto numbers = getTwoNumbers("Enter first number", "Enter second number");
        cout << numbers.first - numbers.second;
        break;
    }

    case 3 :{
       auto numbers = getTwoNumbers("Enter first number", "Enter second number");
        cout << numbers.first * numbers.second;
        break;
    }

    case 4 :{
        auto numbers = getTwoNumbers("Enter first number", "Enter second number");
        cout << numbers.first / numbers.second;
        break;
    }

    case 5 :
        number1 = getNumber("Enter number");
        cout << number1 * number1 ;
        break;

    case 6 :{
        auto numbers = getTwoNumbers("Enter first number", "Enter second number");
        cout << pow(numbers.first, 1.0 / numbers.second); ;
        break;
    }

    default:
        cout << "Invalid choice";

    }

    return 0;
}
