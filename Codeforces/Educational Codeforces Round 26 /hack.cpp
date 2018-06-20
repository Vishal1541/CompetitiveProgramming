/*input
3 6
RRGGBG
RRGGBB
RRGGBB
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef vector<lli > vlli;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s[n];
	int flag = 1;
	map<char, int> ct;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		for (int j = 0; j < m; ++j)
		{
			ct[s[i][j]]++;
		}
	}
	if(ct['R'] == ct['G'] && ct['G'] == ct['B'])
	{
		;
	}
	else 
	{
		cout << "NO" << endl;
		return 0;
	}
	if( n % 3 == 0)
	{
		map<char, int> ma;
		ma['R'] = ma['G'] = ma['B'] = (n/3) * m;
		int next = n/3;
		for (int i = 0; i < n/3; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				ma[s[i][j]]--;
			}
		}
		if( ma['R'] && ma['G'] && ma['B'] ) 
		{
			flag = 0;
		}
		char ch = s[(n/3)][0];
		for(int i = n/3; i < 2 * (n/3); i++)
		{
			for (int j = 0; j < m; ++j)
			{
				if(s[i][j] != ch)
				{
					flag = 0;
				}
			}
		}
		if(flag)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	if( m % 3 == 0)
	{
		flag = 1;
		map<char, int> ma;
		ma['R'] = ma['G'] = ma['B'] = (m/3) * n;
		int next = n/3;
		for (int j = 0; j < m/3; ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				ma[s[i][j]]--;
			}
		}
		if( ma['R'] && ma['G'] && ma['B'] ) 
		{
			flag = 0;
		}
		char ch = s[0][(m/3)];
		for (int j = m/3; j < 2 * (m/3); ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				if(s[i][j] != ch)
				{
					flag = 0;
				}
			}
		}
		if( flag)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}