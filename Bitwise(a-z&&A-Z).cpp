#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int lowerFlag = 0;
    int upperFlag = 0;

    for (char ch : str) {

        if (ch >= 'a' && ch <= 'z')
            lowerFlag |= (1 << (ch - 'a'));

        else if (ch >= 'A' && ch <= 'Z')
            upperFlag |= (1 << (ch - 'A'));
    }

    if (lowerFlag == ((1 << 26) - 1) &&
        upperFlag == ((1 << 26) - 1))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}