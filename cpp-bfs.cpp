/*
4
0 1 1 0
0 0 0 1
0 0 0 0
0 1 0 0
*/
#include <stdio.h>
#include <queue>
#define N 11000

using std::queue;

struct node
{
	int x, y, stp;
	node (int X, int Y):x(X), y(Y), stp(0){}
	node (){}
};

queue <node> q;
int n, i, j, ans = -1;
int map[N][N];
int dir [4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int main ()
{
	
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j) scanf ("%d", &map[i][j]);
	
	q.push (node (1, 1));
	map[1][1] = 1;
	while (!q.empty ())
	{
		node nd = q.front (), temp;
		q.pop ();
		if (nd.x == n && nd.y == n)
		{
			ans = nd.stp;
			break;
		}
		for (i = 0; i < 4; ++i)
		{
			temp.x  = nd.x + dir[i][0];
			temp.y  = nd.y + dir[i][1];
			temp.stp = nd.stp + 1;
			if (temp.x >= 1 && temp.x <= n && 
				temp.y >= 1 && temp.y <= n && 
				!map[temp.x][temp.y])
			{
				q.push (temp);
				map[temp.x][temp.y] = 1;
			}
		}
	}
	
	if (ans == -1) printf ("No Entrance\n");
	else printf ("%d\n", ans);
	
	return 0;
}
