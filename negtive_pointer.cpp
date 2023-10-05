#include <iostream>
using namespace std;
 
int main() {
    int intArray[1024];
    
    for (int i = 0, j = 0; i < 1024; i++) {
        intArray[i] = j++;
    }
 
    cout << intArray[512] << endl;   // 512
 
    int *midArray = &intArray[512];  // 指向了数组中间的数据
 
    cout << midArray[-256] << endl;  // 256
 
    cout << intArray[-256] << endl;  // 得到不可预知的结果
}