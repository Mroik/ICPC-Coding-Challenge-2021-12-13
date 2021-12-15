#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int is_in(int value, int* array, int size)
{
	int start = 0, end = size-1;
	int half;

	while(start <= end)
	{
		half = start + (end - start) / 2;
		if(array[half] == value)
			return TRUE;
		else if(value < array[half])
			end = half-1;
		else
			start = half+1;
	}
	return FALSE;
}

int jump(int start, int end, int* array, int size, int* cache)
{
	int tot = 0;
	if(start == end)
		return 1;
	if(cache[start] != -1)
		return cache[start];
	if(start+1 <= end && is_in(start+1, array, size) == FALSE)
		tot = jump(start+1, end, array, size, cache);
	if(start+2 <= end && is_in(start+2, array, size) == FALSE)
		tot += jump(start+2, end, array, size, cache);
	cache[start] = tot % 1000000007;
	return cache[start];
}

int main()
{
	int n, m;
	int* cache;
	int* A;

	scanf("%d %d", &n, &m);
	A = malloc(sizeof(int) * m);
	cache = malloc(sizeof(int) * n);
	for(int x = 0; x < n; x++)
		cache[x] = -1;

	for(int x = 0; x < m; x++)
		scanf("%d", A+x);

	printf("%d\n", jump(0, n, A, m, cache));
}
