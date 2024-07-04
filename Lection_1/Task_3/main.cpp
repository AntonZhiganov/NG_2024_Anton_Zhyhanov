#include <iostream>

using namespace std;

int main()
{
    int money = 0;
    cout << "How much do you earn?" << endl;
    cin >> money;

    if (money < 1000){
        cout << "Work harder" << endl;
    }

    if (money > 999){
        if (money < 1000000){
            cout << "You're doing a good job" << endl;
        }

        if (money > 999999){
            cout << "Wow, you're a millionaire" << endl;
        }
    }

    cout << "But you're great" << endl;
    return 0;
}
