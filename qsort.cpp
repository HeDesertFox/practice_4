#include <iostream>
using namespace std;

// swap: 交换 v[i] 和 v[j]
void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// qsort: 将 v[left] 到 v[right] 区间的元素升序排序
void qsort(int v[], int left, int right) {
    int i, last;

    // 如果区间内只有一个或零个元素，则无需排序
    if (left >= right)
        return;

    // 交换分区元素到 v[0]
    swap(v, left, (left + right) / 2);
    last = left;

    // 分区，将小于 v[left] 的元素移到左边
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }

    // 恢复分区元素的位置、3
    swap(v, left, last);

    // 递归排序分区的左半部分
    qsort(v, left, last - 1);

    // 递归排序分区的右半部分
    qsort(v, last + 1, right);
}

int main() {
    int arr[] = {5, 3, 9, 1, 6, 2, 8, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 调用 qsort 函数对数组进行排序
    qsort(arr, 0, n - 1);

    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
qsort 函数是一个递归排序算法，
它使用快速排序（Quick Sort）的思想将数组中的元素排序为升序（从小到大）的顺序。
下面解释一下 qsort 函数的递归逻辑：

基本情况：在每一次递归调用中，首先检查 left 是否大于或等于 right。
如果是，表示当前分区内只包含一个元素或没有元素，不需要排序，直接返回。

选择分区元素：选取分区元素（通常是数组的中间元素）并将其与 v[left] 交换，
这将把分区元素移到数组的起始位置。

分区：从 left + 1 开始遍历数组，将小于 v[left] 的元素交换到数组的左侧，即交换到位置 ++last 处，
同时 last 增加。

恢复分区元素：最后，将分区元素 v[left] 放回它在数组中的正确位置，即交换到位置 last 处。

递归：递归调用 qsort 函数对分区的左半部分（从 left 到 last-1）和右半部分（从 last+1 到 right）进行排序。
这将重复上述步骤，直到分区内只包含一个或零个元素，不再递归。

通过不断地选择分区元素、分区和递归排序，qsort 函数最终将整个数组排序为升序。
每次递归都将问题分解为两个子问题，直到子问题变得非常简单（只有一个元素或零个元素），然后开始合并排序结果，直到整个数组有序。
这是快速排序算法的基本思想。
*/