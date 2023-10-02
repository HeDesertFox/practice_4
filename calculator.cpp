#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stack>

using namespace std;

#define MAXOP 100 // 操作数或操作符的最大长度
#define NUMBER '0' // 表示找到一个数字

int getop(char[]);
void push(double);
double pop(void);

stack<double> operandStack; // 操作数栈

/* 
   getop: 从输入中获取下一个操作数或操作符
   参数：
   - s: 存储获取结果的字符数组
   返回值：
   - 获取的操作数或操作符的类型
*/
int getop(char s[]) {
    int i, c;

    // 跳过空白字符
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    // 如果不是数字或小数点，返回字符表示的操作符
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    // 收集整数部分
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }

    // 收集小数部分
    if (c == '.') {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }

    s[i] = '\0';

    if (c != EOF) {
        ungetc(c, stdin); // 将字符放回输入流
    }

    return NUMBER;
}

/* 
   push: 将操作数压入操作数栈
   参数：
   - val: 要压入栈的操作数
*/
void push(double val) {
    operandStack.push(val);
}

/* 
   pop: 从操作数栈中弹出一个操作数
   返回值：
   - 弹出的操作数
*/
double pop(void) {
    if (!operandStack.empty()) {
        double val = operandStack.top();
        operandStack.pop();
        return val;
    } else {
        cerr << "Error: Operand stack is empty." << endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s)); // 将字符串转换为 double 并压入栈
                break;
            case '+':
                push(pop() + pop()); // 弹出两个操作数，相加，再压入栈
                break;
            case '*':
                push(pop() * pop()); // 弹出两个操作数，相乘，再压入栈
                break;
            case '-':
                op2 = pop();
                push(pop() - op2); // 弹出两个操作数，相减，再压入栈
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2); // 弹出两个操作数，相除，再压入栈
                else
                    cerr << "Error: Division by zero." << endl;
                break;
            case '\n':
                cout << "\tResult: " << pop() << endl; // 输出结果
                break;
            default:
                cerr << "Error: Unknown command " << s << endl;
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}
