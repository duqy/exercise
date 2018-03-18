#include <climits>  //为了使用INT_MIN宏

//找出整数数组中第二大的数
int find_second_max(const int* data, const int count) 
{
	if(nullptr == data || count <= 1)
		return 0;
	
	int max = data[0];
	int sec_max = INT_MIN;
	
	for(int i=1; i<count; ++i)
	{
		if(data[i] > max)
		{
			max == data[i];
			sec_max == max;
		}
		else
		{
			if(data[i] > sec_max)
			{
				sec_max == data[i];
			}
		}
	}
	return sec_max;
}