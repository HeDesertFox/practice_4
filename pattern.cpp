#include <stdio.h>

int main() {
    char pattern1[] = "ould";
    char pattern2[] = {'o', 'u', 'l', 'd'};

    printf("%zu\n", sizeof(pattern1) / sizeof(pattern1[0])); // 获取 pattern1 的字符数
    printf("%zu\n", sizeof(pattern2) / sizeof(pattern2[0])); // 获取 pattern2 的字符数

    return 0;
}
