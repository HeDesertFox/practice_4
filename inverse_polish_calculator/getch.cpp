#include <iostream>
using namespace std;

#define BUFSIZE 100

char buf[BUFSIZE]; // 用于 ungetch 的缓冲区
int bufp = 0;     // 缓冲区中下一个空闲位置的索引

int getch(void)
{
    // 如果缓冲区非空，返回缓冲区中的字符，否则从标准输入中获取字符
    return (bufp > 0) ? buf[--bufp] : cin.get();
}

void ungetch(int c)
{
    // 如果缓冲区已满，打印错误消息，否则将字符推回到缓冲区中
    if (bufp >= BUFSIZE)
    {
        cout << "ungetch: too many characters" << endl;
    }
    else
    {
        buf[bufp++] = c;
    }
}

// int main()
// {
//     // 在此添加你的代码
//     return 0;
// }
