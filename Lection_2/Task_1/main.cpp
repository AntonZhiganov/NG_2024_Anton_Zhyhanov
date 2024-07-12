#include <iostream>

using namespace std;

int main() {

    float account[10] {342.34,432.3,2.88,873.9,7564,545.5,65455,777.7,8,976};
    int action;
    int choiceAccount;
    float money;
    float max = account[0];
    float min = account[0];

    cout << "Enter your account number: " << endl;
    cin >> choiceAccount;

    switch(choiceAccount) {
    case 1:
        cout << account[0] << endl;
            break;
    case 2:
        cout << account[1] << endl;
        break;
    case 3:
        cout << account[2] << endl;
        break;
    case 4:
        cout << account[3] << endl;
        break;
    case 5:
        cout << account[4] << endl;
        break;
    case 6:
        cout << account[5] << endl;
        break;
    case 7:
        cout << account[6] << endl;
        break;
    case 8:
        cout << account[7] << endl;
        break;
    case 9:
        cout << account[8] << endl;
        break;
    case 10:
        cout << account[9] << endl;
        break;
    }

    cout << "1 - To put money into the account" << endl;
    cout << "2 - Withdraw money from the account" << endl;
    cout << "3 - See the total amount of money in all accounts" << endl;
    cout << "What do you want to do: " << endl;
    cin >> action;

    switch(action) {
    case 1:
        cout << "How much money do you want to deposit into your account?" << endl;
        cin >> money;
        cout << "Now you have it on your account - " << account[choiceAccount - 1] + money << endl;
        break;
    case 2:
        cout << "How much money do you want to withdraw from your account?" << endl;
        cin >> money;
        if (money > account[choiceAccount - 1]){
            cout << "There is not enough money in your account, you have - " << account[choiceAccount - 1] << endl;
        }
        else {
            cout << "Now you have it on your account - " << account[choiceAccount - 1] - money << endl;
        }
        break;
    case 3:
        for(int numAcc = 0; numAcc < 10; numAcc++) {
            if(account[numAcc] > max) {
                max = account[numAcc];
            }
            if(account[numAcc] < min){
                min = account[numAcc];
            }
        }
        cout << "Total amount: " << account[0] + account[1] + account[2] + account[3] + account[4] + account[5] + account[6] + account[7] + account[8] + account[9] << endl;
        cout << "Minimum account balance: " << min << endl;
        cout << "Maximum account balance: " << max << endl;
    }

    return 0;
}
