#include <iostream>

using namespace std;

int main() {

    bool end = false;
    float account[10] {};
    int action;
    int choiceAccount;
    float money;
    int exit;
    float max = account[0];
    float min = account[0];


    while(end == false){
        cout << "Enter your account number: " << endl;
        cin >> choiceAccount;

        if (choiceAccount >= 1 && choiceAccount <= 10) {
            cout << account[choiceAccount -1] << endl;
            cout << "1 - To put money into the account" << endl;
            cout << "2 - Withdraw money from the account" << endl;
            cout << "3 - See the total amount of money in all accounts" << endl;
            cout << "What do you want to do: " << endl;
            cin >> action;

            switch(action) {
            case 1:
                cout << "How much money do you want to deposit into your account?" << endl;
                cin >> money;
                account[choiceAccount - 1] += money;
                cout << "Now you have it on your account - " << account[choiceAccount - 1] << endl;
                break;
            case 2:
                cout << "How much money do you want to withdraw from your account?" << endl;
                cin >> money;
                if (money > account[choiceAccount - 1]){
                    cout << "There is not enough money in your account, you have - " << account[choiceAccount - 1] << endl;
                }
                else {
                    account[choiceAccount - 1] -= money;
                    cout << "Now you have it on your account - " << account[choiceAccount - 1] - money << endl;
                }
                break;
            case 3:
                float total =0;
                float max = account[0];
                float min = account[0];
                for(int numAcc = 0; numAcc < 10; numAcc++) {
                    total += account[numAcc];
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

        }
        else {
            cout << "Invalid choice" << endl;
        }

        cout << "Exit? 1 - yes" << endl;
        cin >> exit;
        if (exit == 1)
            end = true;
        else
            end = false;


    }

    return 0;
}
