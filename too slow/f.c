#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int work(int** jobs, int worked, int n, int* done)
{
	int finished = TRUE;
	for(int x = 0; x < n; x++)
	{
		if(done[x] == FALSE)
		{
			finished = FALSE;
			break;
		}
	}
	if(finished == TRUE)
		return TRUE;

	for(int x = 0; x < n; x++)
	{
		if(done[x] == TRUE || worked + jobs[0][x] > jobs[1][x])
			continue;
		done[x] = TRUE;
		if(work(jobs, worked + jobs[0][x], n, done) == TRUE)
			return TRUE;
		done[x] = FALSE;
	}
	return FALSE;
}

int main()
{
	int n;
	int can = FALSE;
	int* jobs[2];
	int* done;

	scanf("%d", &n);
	jobs[0] = malloc(sizeof(int) * n);
	jobs[1] = malloc(sizeof(int) * n);
	done = malloc(sizeof(int) * n);

	for(int x = 0; x < n; x++)
		scanf("%d %d", jobs[0]+x, jobs[1]+x);

	for(int x = 0; x < n; x++)
	{
		if(work(jobs, 0, n, done) == TRUE)
		{
			can = TRUE;
			break;
		}
	}
	if(can == TRUE)
		printf("Yes");
	else
		printf("No");

	free(jobs[0]);
	free(jobs[1]);
	free(done);
}
