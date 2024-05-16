#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH];
    char longestWord[MAX_LENGTH];
    int maxLength = 0;

    printf("请输入一个字符串：");
    fgets(str, MAX_LENGTH, stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    char currentWord[MAX_LENGTH];
    int currentLength = 0;
    int start = 0;

    for (int i = 0; i <= len; i++) {
        if (isalpha(str[i])) {
            currentWord[currentLength++] = str[i];
        } else {
            if (currentLength > 0) {
                currentWord[currentLength] = '\0';
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    strcpy(longestWord, currentWord);
                }

                currentLength = 0;
            }
        }
    }

    printf("字符串中最长的单词是：%s\n", longestWord);

    return 0;
}
