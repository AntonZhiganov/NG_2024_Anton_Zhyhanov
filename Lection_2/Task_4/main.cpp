#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string sentence;
    int word = 0;
    cout << "Enter a sentence:" << endl;
    getline(cin, sentence);

    bool inWord = false;
    for (char symbol : sentence){
        if (isalpha(symbol)) {
            if (!inWord) {
                inWord = true;
                word++;
            }
        }
        else {
            inWord = false;
        }
    }

    cout << "The sentence contains " << word << " words." << endl;

    return 0;
}
