#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, m = 127, sa[Maxn], buc[Maxn], first[Maxn], second[Maxn];
string str;
void radix_sort(int *first, int *second)
{
	memset(buc, 0, sizeof(buc));
	for (int i = 0; i < n; i++)
		buc[first[second[i]]]++;
	for (int i = 1; i <= m; i++)
		buc[i] += buc[i - 1];
	for (int i = n - 1; i >= 0; i--)
		sa[--buc[first[second[i]]]] = second[i];
}
void suffix_array(void)
{
	for (int i = 0; i < n; i++)
		second[i] = i;
	for (int i = 0; i < n; i++)
		first[i] = str[i];
	radix_sort(first, second);
	for (int w = 1; w <= n; w <<= 1)
	{
		int cnt = 0;
		for (int i = n - w; i < n; i++)
			second[cnt++] = i;
		for (int i = 0; i < n; i++)
			if (sa[i] >= w)
				second[cnt++] = sa[i] - w;
		radix_sort(first, second);
		swap(first, second);
		cnt = 0;
		first[sa[0]] = cnt++;
		for (int i = 1; i < n; i++)
			first[sa[i]] = (sa[i - 1] + w < n && sa[i] + w < n && sa[i] + w < n && sa[i - 1] + w < n && second[sa[i]] == second[sa[i - 1]] && second[sa[i] + w] == second[sa[i - 1] + w]) ? cnt - 1 : cnt++;
		if (cnt >= n) break;
		m = cnt;
	}
}
int main()
{
	cin >> str;
	n = str.size();
	suffix_array();
	for (int i = 0; i < n; i++)
		printf("%d ", sa[i] + 1);
	return 0;
}