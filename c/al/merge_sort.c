#include <stdio.h>

#define LEN 8

int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6};

void merge(int start, int mid, int end) {
  int n1 = mid -start + 1;
  int n2 = end -mid;
  int left[n1], right[n2];
  int i, j, k;

  for (i = 0; i < n1; i++)	/* a[start..mid] */
    left[i] = a[start+i];
  for (j = 0; j < n2; j++)	/* a[mid+1..end] */
    right[j] = a[mid+1+j];

  i = j = 0;
  k = start;
  while (i < n1 && j < n2) {
    if (left[i] < right[j])
      a[k++] = left[i++];	/* C99的新特性－－可变长数组 */
    else
      a[k++] = right[j++];
  }

  while (i < n1)
    a[k++] = left[i++];		/* left[] is not exhausted */
  while (j < n2)
    a[k++] = right[j++];	/* right[] is not exhausted */
}

void sort(int start, int end) {
  int mid;
  if (start < end) {
    mid = (start + end) / 2;
    printf("sort\t(%d-%d, %d-%d)\t%d %d %d %d %d %d %d %d\n",
	   start, mid, mid+1, end,
	   a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    sort(start, mid);
    sort(mid+1, end);
    merge(start, mid, end);
    printf("merge\t(%d-%d, %d-%d)\t%d %d %d %d %d %d %d %d\n",
	   start, mid, mid+1, end,
	   a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    
  }
}

int main(int argc, char *argv[])
{
  sort(0, LEN-1);
  return 0;
}

/*
归并排序，采取分而治之(Divide-and-Conquer)的策略，时间复杂度是Θ(nlgn)。
归并排序步骤：
Divide: 把长度为n的输入序列分成两个长度为n/2的子序列。
Conquer: 对这两个子序列分别采用归并排序。是一个递归的过程
Combine: 将两个排序好的子序列合并成一个最终的排序序列

sort函数把a[start..end]平均分成两个子序列，分别是a[start..mid]和a[mid+1..end]，对这两个子序列分别递归调用sort函数进行排序
调用merge函数将排好序的两个子序列合并起来，每次循环取两个子序列中最小的元素进行比较，将较小的元素取出放到最终的排序序列中，如果其中一个子序列的元素已取完，就把另一个子序列剩下的元素都放到最终的排序序列中

输出：
sort	(0-3, 4-7)	5 2 4 7 1 3 2 6
sort	(0-1, 2-3)	5 2 4 7 1 3 2 6
sort	(0-0, 1-1)	5 2 4 7 1 3 2 6
merge	(0-0, 1-1)	2 5 4 7 1 3 2 6
sort	(2-2, 3-3)	2 5 4 7 1 3 2 6
merge	(2-2, 3-3)	2 5 4 7 1 3 2 6
merge	(0-1, 2-3)	2 4 5 7 1 3 2 6
sort	(4-5, 6-7)	2 4 5 7 1 3 2 6
sort	(4-4, 5-5)	2 4 5 7 1 3 2 6
merge	(4-4, 5-5)	2 4 5 7 1 3 2 6
sort	(6-6, 7-7)	2 4 5 7 1 3 2 6
merge	(6-6, 7-7)	2 4 5 7 1 3 2 6
merge	(4-5, 6-7)	2 4 5 7 1 2 3 6
merge	(0-3, 4-7)	1 2 2 3 4 5 6 7

*/
