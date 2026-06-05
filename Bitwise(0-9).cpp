#include <stdio.h>

int main() {
    char str[1000];
    scanf("%s", str);

    int digit[10] = {0};

    for(int i = 0; str[i] != '\0'; i++) {

        if(str[i] >= '0' && str[i] <= '9') {
            int n = str[i] - '0';
            digit[n] = 1;
        }
    }

    int flag = 1;

    for(int i = 0; i < 10; i++) {
        if(digit[i] != 1) {
            flag = 0;
        }
    }

    if(flag == 1)
        printf("Yes");
    else
        printf("No");

    return 0;
}