#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct node
{
	int cnt;
	node *next[2];
	node()
	{
		cnt = 0;
		memset(next, 0, sizeof(next));
	}
};
node *root = new node();
void insert(int x)
{
	node *p = root;
	for (int i = 30;i >= 0;i--)
	{
		int num = x&(1 << i) ? 1 : 0;
		if (p->next[num] == NULL)
			p->next[num] = new node();
		p = p->next[num];
		p->cnt++;
	}
}
void del(int x)
{
	node *p = root;
	for (int i = 30;i >= 0;i--)
	{
		int num = x&(1 << i) ? 1 : 0;
		p = p->next[num];
		p->cnt--;
	}
}
int query(int x)
{
	node *p = root;
	int ans = 0;
	for (int i = 30;i >= 0;i--)
	{
		int num = x&(1 << i) ? 0 : 1;
		if (p->next[num] != NULL&&p->next[num]->cnt > 0)
			ans += 1 << i, p = p->next[num];
		else p = p->next[num ^ 1];
	}
	return ans;
}
int main()
{
	int n, i, x;
	char str[2]; 
	insert(0);
	scanf("%d", &n);
	for (i = 1;i <= n;i++)
	{
		scanf("%s%d", str, &x);
		if (str[0] == '+')
			insert(x);
		else if (str[0] == '-')
			del(x);
		else
			printf("%d\n", query(x));
	}
	return 0;
}