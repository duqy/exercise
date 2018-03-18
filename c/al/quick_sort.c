#include <stdio.h>

int partition(int start, int end)
{
  // partition函数有多种写法
  // 从a[start..end]中选取一个pivot元素(比如a[start]为pivot);
  int pivot = a[start];
  // 在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
  // 使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，而a[mid]就是pivot元素，
  return mid;

/* 
  int pivot = a[start];
  while (start < end) {
    while (start < end && a[end] >= pivot)
      end--;
    if (start < end) 
      a[start++] = a[end];
    while (start < end && a[start] <= pivot)
      start++;
    if (start < end) 
      a[end--] = a[start];
  }
  a[start] = pivot;
*/
}

void quicksort(int start, int end)
{
  int mid;
  if (start < end) {
    mid = partition(start, end);
    quicksort(start, mid-1);
    quicksort(mid+1, end);
  }
}

/*
快速排序采用分而治之策略，在平均情况下的时间复杂度也是Θ(nlgn)，但比归并排序有更小的时间常数
思想：
通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列

步骤：
a. 先从数列中取出一个数作为基准数。
b. 分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
c. 再对左右区间重复第二步，直到各区间只有一个数

*/
