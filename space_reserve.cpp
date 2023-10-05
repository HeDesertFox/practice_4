#include <iostream>

using namespace std;

#define ALLOCSIZE 10000 // 可用空间的大小
static char allocbuf[ALLOCSIZE]; // 分配的存储空间
static char *allocp = allocbuf; // 下一个空闲位置

// 分配 n 个字符的存储空间，返回指向这些字符的指针
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) { // 如果空间足够
        allocp += n;
        return allocp - n; // 返回旧的指针位置
    } else { // 空间不足
        return 0;
    }
}

// 释放 p 指向的存储空间
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

int main() {
    // 示例用法
    char *ptr1 = alloc(10); // 分配 10 个字符的存储空间
    char *ptr2 = alloc(5);  // 分配 5 个字符的存储空间

    // 检查分配是否成功
    if (ptr1 != nullptr) {
        cout << "ptr1 分配成功_YES" << endl;
    } else {
        cout << "ptr1 分配失败" << endl;
    }

    if (ptr2 != nullptr) {
        cout << "ptr2 分配成功_YES" << endl;
    } else {
        cout << "ptr2 分配失败" << endl;
    }

    // 释放存储空间
    afree(ptr1);
    afree(ptr2);

    return 0;
}
