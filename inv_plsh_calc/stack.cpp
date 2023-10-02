#include <iostream>
#include <cstdio> // 用于 printf 函数
#include "calc.h"

using namespace std;

#define MAXVAL 100 // val 栈的最大深度
int sp = 0;         // 下一个空闲栈位置
double val[MAXVAL]; // 值栈

// push: 将 f 压入值栈
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        cout << "error: stack full, can't push " << f << endl;
}

// pop: 弹出并返回栈顶的值
double pop()
{
    if (sp > 0)
        return val[--sp];
    else
    {
        cout << "error: stack empty" << endl;
        return 0.0;
    }
}
