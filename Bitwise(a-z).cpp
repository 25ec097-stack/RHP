#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int flag = 0;

    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z')
            flag |= (1 << (ch - 'a'));
    }

    if (flag == ((1 << 26) - 1))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}