#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int already_in(int arr[], int amount_to_check, int val)
{
	for (int i = 0; i < amount_to_check;i++)
	{
		if (arr[i] == val)
			return 1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int i, n;
	time_t t;

	n = atoi(argv[1]);
	int nums[n];

	/* Intializes random number generator */
	srand((unsigned)time(&t));

	/* Print 5 random numbers from 0 to 49 */
	for (i = 0; i < n; i++)
	{
		int new_num = rand();
		if (!already_in(nums, i, new_num))
		{
			nums[i] = new_num;
			printf("%d ", new_num);
		}
		else
			i--;
	}
	return (0);
}