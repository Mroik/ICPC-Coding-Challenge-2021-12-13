#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max1, max2;
	int temp;
	int n;
	int* A;

	scanf("%d", &n);
	A = malloc(sizeof(int) * n);
	for(int x = 0; x < n; x++)
		scanf("%d", A+x);

	max1 = A[0];
	max2 = A[1];
	if(max1 < max2)
	{
		temp = max1;
		max1 = max2;
		max2 = temp;
	}

	for(int x = 2; x < n; x++)
	{
		if(max1 < A[x])
		{
			max2 = max1;
			max1 = A[x];
		}
		else if(max2 < A[x])
			max2 = A[x];
	}

	for(int x = 0; x < n; x++)
	{
		if(max1 == A[x])
			printf("%d\n", max2);
		else
			printf("%d\n", max1);
	}
	free(A);
}
