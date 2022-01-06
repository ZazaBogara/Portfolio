#include <stdio.h>
#include <math.h>

/*
Знайти максимальне число у масиві цілих чисел, і на якій позиції воно знаходиться.
*/

int main()
{
	int n=0;
	printf("n: ");
	scanf("%d", &n);
	n--;
	int array[n];
	for (int i=0;i<=n;i++)
	{
		scanf("%d", &array[i]);
	}
	int max_max=0;
	int which_is_max=0;
	for (int i = 0; i <= n; i++)
	{
		int x = array[i];
		int counter = 0;
		for (int j = 0; j <= n; j++)
		{
			if (x == array[j])
				counter++;
		}
		if (counter > max_max)
		{
			max_max=counter;
			which_is_max = x;
		}
	}
	printf("Counter:%d \n Which is max:%d", max_max, which_is_max);
	return 0;
}