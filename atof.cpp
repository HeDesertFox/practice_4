#include <iostream>
#include <cctype> // 包含头文件 cctype，用于 isspace 和 isdigit 函数

using namespace std;

/* 
   atof: 将字符串 s 转换为 double 值
   参数：
   - s: 待转换的字符串
   返回值：
   - 转换后的 double 值
*/
double atof(char s[]) {
    double val, power;
    int i, sign;

    // 跳过前导空白字符
    for (i = 0; isspace(s[i]); i++)
        ;

    // 处理正负号
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    // 处理整数部分
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // 处理小数点和小数部分
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    return sign * val / power;
}

int main() {
    char str[] = "123.45"; // 示例字符串
    double result = atof(str); // 调用 atof 函数将字符串转换为 double 值
    cout << "String \"" << str << "\" converted to double: " << result << endl;
    return 0;
}
