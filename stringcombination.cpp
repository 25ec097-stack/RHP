#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    for(int mask = 0; mask < (1 << n); mask++) {

        string combi = "";

        for(int i = 0; i < n; i++) {

            if(mask & (1 << i)) {
                combi += s[i];
            }
        }

        cout << combi << endl;
    }

    return 0;
}