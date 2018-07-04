#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef map<int,int> mpii;
typedef map<string,int> mpsi;
typedef set<int> si;
typedef set<ll> sll;
#define pb push_back
#define INF 1000000000
#define LINF INF*INF
#define all(x) x.begin(),x.end()
int bfs(vector<vi> &adj,vector<int> &visited,int s,vector<vi>&adj2,int k=1)
{
	if(k==2)
	{
		vi visited2=visited;
		queue<int> q;q.push(s);
		int ls =s;
		while(!q.empty())
		{
			int u = q.front();q.pop();
		visited2[u]=1;
		ls=u;
		int sz=0;
		for(auto it:adj2[u])
		{
			if(!visited2[it])
			{
				visited2[it]=1;
				q.push(it);
				sz++;
				}
			
		}
		}
		s=ls;
	}
	int res=0;
	queue<int> q;q.push(s);
//	vi visited2= visited;
	while(!q.empty())
	{
		int u = q.front();q.pop();
		visited[u]=1;
		for(auto it:adj[u])
		{
			if(!visited[it])
			{
				visited[it]=1;
				q.push(it);
			}
			
		}
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,s;cin>>n>>m>>s;
	vector<vi> adj(n+1),adj2(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v;
		adj[u].pb(v);
		adj2[v].pb(u);
	}
	vi visited(n+1);
	queue<int> q;q.push(s);
	while(!q.empty())
	{
		int u = q.front();q.pop();
		visited[u]=1;
		for(auto it:adj[u])
		{
			if(!visited[it])
			{
				visited[it]=1;
				q.push(it);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]) continue;
		if(adj2[i].size()==0)
		{
			cnt++;
			bfs(adj,visited,i,adj2);
		}
	}
	vi visited3=visited;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			cnt++;
			int res = bfs(adj,visited,i,adj2,2);
		}
	}

	cout<<cnt<<endl;
	return 0;
}