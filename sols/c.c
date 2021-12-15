#include <stdio.h>
#include <stdlib.h>

void merge_sort(int* array, int size)
{
	int* sub1;
	int* sub2;
	int half = size/2;
	int i1 = 0, i2 = 0;
	int many1 = half, many2 = size - half;

	if(size == 1)
		return;

	sub1 = malloc(sizeof(int) * many1);
	sub2 = malloc(sizeof(int) * many2);
	for(int x = 0; x < half; x++)
		sub1[x] = array[x];
	for(int x = half; x < size; x++)
		sub2[x - half] = array[x];

	merge_sort(sub1, many1);
	merge_sort(sub2, many2);

	for(int x = 0; x < size; x++)
	{
		if(many2 == 0)
		{
			array[x] = sub1[i1];
			i1++;
			many1--;
		}
		else if(many1 == 0)
		{
			array[x] = sub2[i2];
			i2++;
			many2--;
		}
		else if(sub1[i1] >= sub2[i2])
		{
			array[x] = sub1[i1];
			i1++;
			many1--;
		}
		else
		{
			array[x] = sub2[i2];
			i2++;
			many2--;
		}
	}

	free(sub1);
	free(sub2);
}

int main()
{
	int n;
	int* A;
	int tot = 0;

	scanf("%d", &n);
	A = malloc(sizeof(int) * n);
	for(int x = 0; x < n; x++)
		scanf("%d", A+x);

	merge_sort(A, n);

	for(int x = 1; x <= A[0]; x++)
	{
		if(A[n/2] < x && A[n/2 - 1] >= x)
			tot++;
	}

	printf("%d\n", tot);
	free(A);
}
