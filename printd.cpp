#include <iostream>
using namespace std;

// printd: 打印 n 的十进制表示
void printd(int n)
{
    if (n < 0)
    {
        putchar('-'); // 如果 n 为负数，打印负号
        n = -n; // 将 n 变为正数
    }

    if (n / 10)
    {
        printd(n / 10); // 递归打印除以 10 后的部分
    }

    putchar(n % 10 + '0'); // 打印最后一位数字
}

int main()
{
    int n = -12345; // 要打印的数字
    printd(n); // 调用打印函数
    cout << endl; // 输出换行符

    return 0;
}
/*
当我们调用 printd(123) 时，以下是函数 printd 的递归过程：

初始调用：printd(123)，n 是正数，不会进入负数的分支。

printd(12)：此时 n 是 123 除以 10 的结果，即 12。我们进入了递归调用。

printd(1)：现在 n 是 12 除以 10 的结果，即 1。我们再次进入递归调用。

printd(1)：此时 n 是 1 除以 10 的结果，即 0。因为 n 不大于 0，不再进入递归调用。

返回递归调用：现在我们开始从最深层的递归调用返回。

putchar(1 % 10 + '0')：在 printd(1) 的上一级递归中，我们打印了 1 的最后一位数字，即 1。

putchar(12 % 10 + '0')：在 printd(12) 的上一级递归中，我们打印了 12 的最后一位数字，即 2。

putchar(123 % 10 + '0')：在初始调用 printd(123) 中，我们打印了 123 的最后一位数字，即 3。

递归调用的过程是从最深层一直到最初的调用，依次打印数字的每一位，从最高位到最低位。

这是通过递归调用和取余数操作实现的。最后，每个数字都被打印出来，得到结果 123。
*/