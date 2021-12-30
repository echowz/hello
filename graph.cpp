#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;
unordered_map<int, vector<int>> mp;	//非链式，散列map的高效建图法
bitset<524288> st;	//标记
void DFS(int u)
{
	cout << u << " ";
	st.set(u);	//标记
	for (auto i : mp[u])	//增强for
		if (!st[i]) DFS(i);
}
void BFS(int u)
{
	st.reset();	//重置标记
	queue<int> q;
	q.push(u);
	st.set(u);
	while (!q.empty())
	{
		char temp = q.front(); 
		q.pop();
		cout << temp << " ";
		for (auto i : mp[temp])
			if (!st[i] && (st.set(i),1))	q.push(i);	//未标记点标记并入列
	}
}
int main()
{
	int n, m, start;
	puts("输入图的结点个数和边数： ");
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		puts("输入两个结点 添加一条由左到右的有向边：");
		int a, b;
		cin >> a >> b;
		mp[a].push_back(b);
	}

	puts("输入遍历起点： ");
	cin >> start;

	printf("图的深度优先遍历为 : \n");
	DFS(start);
		
	printf("\n图的广度优先遍历为 : \n");
	BFS(start);
}
