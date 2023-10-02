#include <iostream>
#include <cctype> // 用于 isdigit 函数
#include "calc.h"

using namespace std;

// getop: 获取下一个字符或数字操作数
int getop(char s[])
{
    int i, c;
    
    // 跳过空格和制表符
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    
    s[1] = '\0';
    
    if (!isdigit(c) && c != '.')
        return c; // 不是数字
    
    i = 0;
    
    if (isdigit(c)) // 收集整数部分
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    
    if (c == '.') // 收集小数部分
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    
    s[i] = '\0';
    
    if (c != EOF)
        ungetch(c);
    
    return NUMBER;
}

// int main()
// {
//     // 在此添加你的代码
//     return 0;
// }
