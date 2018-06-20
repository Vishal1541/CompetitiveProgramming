#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fr(i,x,y) for(Int i=x; i<y; i++)

int n,temp;
std::vector<int> arr;
int ptr1,ptr2;
int m,cnt;

int main()
{
	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	ptr1 = 0;
	ptr2 = arr.size()-1;

	cnt =0;

	while(ptr1 !=ptr2 && ptr1!=arr.size() && ptr2!=0)
	{
		if(arr[ptr1] < arr[ptr1+1])
			ptr1++;
		else if(arr[ptr2] < arr[ptr2-1])
			ptr2--;
		else
		{
			m = arr[ptr1] - arr[ptr1+1] + 1;
			temp = arr[ptr2] - arr[ptr2-1] +1;

			if(m < temp)
			{
				cnt += m;
				arr[ptr1+1] += m;
				ptr1++;
			}
			else
			{
				cnt += temp;
				arr[ptr2-1] += temp;
				ptr2--;
			}
		}
	}


	cout << cnt;

	return 0;
}