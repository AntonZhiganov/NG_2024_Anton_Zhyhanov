#include <iostream>

using namespace std;

int main()
{
    string sentence;
    int word;
    cout << "Enter a sentence:" << endl;
    getline(cin,sentence);

    bool inWord = false;
    for (char symbol : sentence){
        if(isspace(symbol)){
            if (inWord){
                inWord = false;
            }
        }

        else {
            if(!inWord){
                inWord = true;
                word++;
            }
        }
    }

    cout << "The sentence contains " << word << " words." << endl;

    return 0;
}
