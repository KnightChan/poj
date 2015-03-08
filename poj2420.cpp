#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define MAX_NUM 128

typedef struct TagPoint
{
	double x;
	double y;
}Point;

inline double pt_distance(Point a, Point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double fermat_point(Point pt[], int n, Point& ptres)
{
	Point u, v;
	double step = 0.0, curlen, explen, minlen;
	int i, j, k, idx;
	bool flag;
	u.x = u.y = v.x = v.y = 0.0;
	for(i = 0; i < n; ++i)
	{
		step += fabs(pt[i].x) + fabs(pt[i].y);
		u.x += pt[i].x;
		u.y += pt[i].y;
	}
	u.x /= n;
	u.y /= n;
	flag = 0;
	while(step > 1e-10)
	{
		for(k = 0; k < 10; step /= 2, ++k)
			for(i = -1; i <= 1; ++i)
				for(j = -1; j <= 1; ++j)
				{
					v.x = u.x + step*i;
					v.y = u.y + step*j;
					curlen = explen = 0.0;
					for(idx = 0; idx < n; ++idx)
					{
						curlen += pt_distance(u, pt[idx]);
						explen += pt_distance(v, pt[idx]);
					}
					if(curlen > explen)
					{
						u = v;
						minlen = explen;
						flag = 1;
					}
				}
	}
	ptres = u;
	return flag ? minlen : curlen;
}

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n, i;
	double res;
	Point pt[MAX_NUM], ptres;
	while(scanf("%d", &n)!=EOF)
	{
		for(i = 0; i < n; ++i)
		{
			scanf("%lf %lf", &pt[i].x, &pt[i].y);
		}
		res = fermat_point(pt, n, ptres);
		//printf("(%.3lf,%.3lf)\n", ptres.x, ptres.y);
		if(res-(int)(res) > 0.5)
			printf("%d\n", (int)(res+1));
		else
			printf("%d\n", (int)(res));
	}

	return 0;
}
