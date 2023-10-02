#include <iostream>
#include <cstdlib> // for atof()
#include "calc.h"

#define MAXOP 100  // 最大操作数或运算符的大小

using namespace std;

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                cout << "error: zero divisor" << endl;
            break;
        case '\n':
            cout << "\t" << pop() << endl;
            break;
        default:
            cout << "error: unknown command " << s << endl;
            break;
        }
    }
    return 0;
}

