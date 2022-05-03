# 归并排序

> *原作者： dreamcatcher-cx*

> *出处： <http://www.cnblogs.com/chengxiao/>*

## 基本思想

归并排序是利用**归并**的思想实现的排序方法,该算法采用**分治**策略,分治法将问题 **分(divide)** 为小的子问题然后递归求解,而 **治(conquer)** 则将得到的各答案归纳到一起,即分而治之。

![](pictures/merge-sort.png )

可以看到这种结构很像一颗完全二叉树，本文的归并排序采用递归实现，**分**阶段可以理解为拆分递归子序列的过程，递归深度为$log_2n$。

## 合并相邻有序子序列

**治**阶段，需要将两个有序数组合并为一个有序数组，比如上图中的最后一次合并，实现步骤如下：

![](pictures/merge-sort2-1.png )

![](pictures/merge-sort2-2.png )

## 代码实现

```cpp
#include<iostream>
#include<vector>
using namespace std;
// 归并排序
void merge(vector<int>& arr, int l, int q, int r) {
	int n = r - l + 1; // 临时数组长度，用于存放合并后的有序数组
	vector<int> tmp(n);//临时数组
	int it = 0;
	int i = l;
	int j = q + 1;
	while (i <= q && j <= r) {
		tmp[it++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
	}
	while (i <= q)
		tmp[it++] = arr[i++];
	while (j <= r)
		tmp[it++] = arr[j++];
	for (int k = 0; k < n; k++)
		arr[l + k] = tmp[k];
}
// 递归分解
void merge_sort(vector<int>& arr, int l, int r) {
	if (l == r) return;
	//递归是让数组每个数单独成为长度为1的区间
	int q = l + (r - l) / 2;
	merge_sort(arr, l, q);
	merge_sort(arr, q + 1, r);
	merge(arr, l, q, r);
}
int main() {
	vector<int> a = {8,4,5,7,1,3,6,2};
    merge_sort(a,0, a.size()-1);
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	system("pause");
	return 0;
}
```

## 最后

归并排序是稳定排序，也是一种十分高效的排序方法，能利用完全二叉树特性的排序一般性能都不会太差。从上文的图中可看出，每次合并操作的平均时间复杂度为$O(n)$，而完全二叉树的深度为$|log2n|$。总的平均时间复杂度为$O(nlogn)$。而且，归并排序的最好、最坏、平均时间复杂度均为O(nlogn)。
