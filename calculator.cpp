#include <iostream>
#include <cstdlib> // 包含头文件 cstdlib，用于 atof 函数
#include <stack>   // 包含头文件 stack，用于操作数栈

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
    // 实现 getop 函数的逻辑
    // ...

    return 0; // 用于示例，实际根据实现填充返回值
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
                    cerr << "Error: Division by zero." << endl;
                break;
            case '\n':
                cout << "\tResult: " << pop() << endl;
                break;
            default:
                cerr << "Error: Unknown command " << s << endl;
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}
