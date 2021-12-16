#include <stdio.h>
#include <stdlib.h>

long sum(int* array, int n)
{
	long tot = 0;
	for(int x = 0; x < n; x++)
		tot += array[x];
	return tot;
}

long sub_sequence(int* array, int n, long k)
{
	long tot = 0;
	long prev;
	for(int x = 0; x < n; x++)
	{
		prev = array[x];
		if(prev >= k)
		{
			tot += n - x;
			continue;
		}
		for(int size = 2; size <= n - x; size++)
		{
			prev += array[x + (size-1)];
			if(prev >= k)
			{
				tot += n - (x + (size - 1));
				break;
			}
		}
	}
	return tot;
}

int main()
{
	int* array;
	int n;
	long k;

	scanf("%d %ld", &n, &k);
	array = malloc(sizeof(int) * n);
	for(int x = 0; x < n; x++)
		scanf("%d", array+x);

	printf("%ld\n", sub_sequence(array, n, k));
	free(array);
}
