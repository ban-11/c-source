#ifndef DP
#define DP

#include <stdio.h>
#include <math.h>
#define maxn_1d 110000
#define maxn_2d 11000
#define max(a,b) (a) > (b) ? (a) : (b) 

int pack_01 (int, int, int w[], int v[], int &dp[]);

int pack_01 (int n, int c, int w[], int v[], int &dp[])
{
	int i, j;
	for (i = 1; i <= n; ++i)
		for (j = c; j >= w[i]; --j) dp[j] = max (dp[j], dp[j - w[i]] + v[i]);
}

int lcs (char &S[], char &T[], int &dp[][]);
void lcs_dfs (char S[], char T[], int dp[][], int, int);

int lcs (char S[], char T[], int &dp[][])
{
	int i, j;
	int l1 = sizeof (S) / sizeof (char), l2 = sizeof (T) / sizeof (char);
	if (!l1 || !l2) return -1;
	for (i = 1; i <= l1; ++i)
		for (j = 1; j <= l2; ++j)
		{
			if (S[i - 1] == T[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
		}
	return 1;
}
void lcs_dfs (char S[], char T[], int dp[][], int X, int Y)
{
	if (!X || !Y) return;
	if (dp[X][Y] - dp[X - 1][Y - 1] == 1 && S[X - 1] == T[Y - 1]) 
	{
		dfs (S, T, dp, X - 1, Y - 1);
		printf ("%c ", T[Y - 1]);
	}
	else dp[X][Y - 1] > dp[X - 1][Y] ? dfs (S, T, dp, X, Y - 1) : dfs (S, T, dp, X - 1, Y);
}

#endif
