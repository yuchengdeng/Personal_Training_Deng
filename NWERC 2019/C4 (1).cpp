#include<cstdio>
#include<cstdlib>
#include<set>
using namespace std;
const int N = 1e3 + 5;
const int M = 2e3 + 5;
int n, p;
struct node
{
	int l;
	int r;
}w[N];
int pos[M];
int hav[N];
int cnt = 1;
int rec[M];
int ans;
bool flag = true;
set < int > vis;
inline void work()
{
	for (int i = 1; i < n; i ++)
	{
		while(pos[cnt] <= w[i + 1].r && cnt <= p)
		{
			if (pos[cnt] >= w[i].l && pos[cnt] <= w[i].r)
				hav[i] ++;
			if (pos[cnt] >= w[i + 1].l && pos[cnt] <= w[i + 1].r)
				hav[i + 1] ++;
			if (i + 2 <= n && w[i + 2].l == pos[cnt])
				hav[i + 2] ++;
			cnt ++;
		}
		if (hav[i] > 2)
		{
			printf("impossible\n");
			flag = false;
			return;
		}
		if (hav[i] == 2)
			continue;
		if (hav[i] < 2)
		{
			if (w[i].r == w[i + 1].l && hav[i + 1] < 2 && ! vis.count(w[i + 1].l))
			{
				ans ++;
				rec[ans] = w[i + 1].l;
				hav[i] ++;
				hav[i + 1] ++;
				vis.insert(w[i].r);
			}
			else
			{
				ans ++;
				for (int j = w[i].r; j >= w[i].l; j --)
				{
					if (! vis.count(j) && j != w[i + 1].l)
					{
						rec[ans] = j;
						hav[i] ++;
						vis.insert(j);
						break;
					}
				}
			}
			if (hav[i] == 1)
			{
				ans ++;
				for (int j = w[i].r; j >= w[i].l; j --)
				{
					if (! vis.count(j) && j != w[i + 1].l)
					{
						rec[ans] = j;
						hav[i] ++;
						vis.insert(j);
						break;
					}
				}
			}
		}
	}
	while(pos[cnt] >= w[n].l && pos[cnt] <= w[n].r && cnt <= p)
	{
		hav[n] ++;
		cnt ++;
	}
	if (hav[n] > 2)
	{
		printf("impossible\n");
		flag = false;
		return;
	}
	if (hav[n] < 2)
	{
		ans ++;
		for (int j = w[n].r; j >= w[n].l; j --)
		{
			if (! vis.count(j))
			{
				rec[ans] = j;
				hav[n] ++;
				vis.insert(j);
				break;
			}
		}
	}
	if (hav[n] == 1)
	{
		ans ++;
		for (int j = w[n].r; j >= w[n].l; j --)
		{
			if (! vis.count(j))
			{
				rec[ans] = j;
				hav[n] ++;
				vis.insert(j);
				break;
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", &w[i].l, &w[i].r);
	scanf("%d", &p);
	for (int i = 1; i <= p; i ++)
	{
		scanf("%d", &pos[i]);
		vis.insert(pos[i]);
	}
	work();
	if (! flag)
		return 0;
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i ++)
		printf("%d ", rec[i]);
	printf("\n");
	return 0;
 } 
