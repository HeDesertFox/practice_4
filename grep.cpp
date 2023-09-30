#include <iostream>
using namespace std;

#define MAXLINE 1000 /* 最大输入行长度 */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* 要搜索的模式 */

/* 查找匹配模式的所有行 */
int main() {
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            cout << line;
            found++;
        }
    }

    return found;
}

/* getline: 读取一行到 s 中，返回长度 */
int getline(char s[], int lim) {
    int c, i;
    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

/* strindex: 在 s 中查找 t，返回第一个匹配的位置，否则返回 -1 */
int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            // 什么都不做，只是循环直到找到不匹配的字符或 t 到达结尾
        }

        if (k > 0 && t[k] == '\0') {
            return i; // 找到匹配，返回 i
        }
    }

    return -1; // 未找到匹配
}
