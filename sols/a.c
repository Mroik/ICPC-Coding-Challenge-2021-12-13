#include <stdio.h>
#include <stdlib.h>

int sum(int* arr, int n)
{
	int tot = 0;
	for(int x = 0; x < n; x++)
		tot += arr[x];
	return tot;
}

int main()
{
	int n;
	int* A;
	int min;
	int temp;

	scanf("%d", &n);
	A = malloc(sizeof(int) * n);

	for(int x = 0; x < n; x++)
		scanf(" %d", A+x);

	min = sum(A, n);
	for(int x = 1; x < n; x++)
	{
		temp = sum(A, x) - sum(A+x, n-x);
		if(temp < 0)
			temp = -temp;
		if(temp < min)
			min = temp;
	}
	printf("%d\n", min);
	free(A);
}
