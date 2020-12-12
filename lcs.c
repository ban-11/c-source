/*
acbbabdbb
abcbdb
*/
#include <stdio.h>
#include <string.h>
#define N 10000
char x[N], y[N];
int dp[N][N], i, j, l1, l2;
int max (int, int);
void dfs (int, int);
int main ()
{
	scanf ("%s", x);
	scanf ("%s", y);
	l1 = strlen (x); l2 = strlen (y); 
	for (i = 1; i <= l1; ++i)
		for (j = 1; j <= l2; ++j)
		{
			if (x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
		}
	printf ("%d\n", dp[l1][l2]);
	dfs (l1, l2);
	return 0;
}
int max (int a, int b)
{
	return a > b ? a : b;
}
void dfs (int X, int Y)
{
	if (!X || !Y) return;
	if (dp[X][Y] - dp[X - 1][Y - 1] == 1 && x[X - 1] == y[Y - 1]) 
	{
		dfs (X - 1, Y - 1);
		printf ("%c ", y[Y - 1]);
	}
	else dp[X][Y - 1] > dp[X - 1][Y] ? dfs (X, Y - 1) : dfs (X - 1, Y);
}
