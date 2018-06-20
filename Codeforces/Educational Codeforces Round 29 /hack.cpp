#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include <list>
#include <functional>
using namespace std;



int main()
{
	string s;
	int flag=1;

	getline(cin,s);
	if (s.length()==0)
	{
		getline(cin,s);
	}
	//cout<<s.length()<<"\n";
	long int count=0;
	long i;
	for (i = s.length()-1;s[i]=='0' ; --i)
	{
		count++;
		//cout<<count<<" ";
	}
	/*string s1;
	for (long int i = 0; i < count; ++i)
	{
		s1[i]=0;
	}
	long int k=0;

	for (long int j = count; j < count+s.length(); ++j)
	{
		s1[j]=s[k];
		k++;
	}
	int x=1;
	long int a = 0;
	long int b=s1.length()-1;
	for (; a <= b; ++a,b--)
	{
		if (s1[a]!=s1[b])
		{
			x=0;
			break;
		}
	}*/
	long j=s.length()-count-1;
	i=0;
	for(;i<=j;)
	{
		if(s[i]!=s[j])
			flag=0;
		i++;
		j--;
	}
	if (flag==0)
	{
		cout<<"NO\n";
	}
	else
	{
		cout << "YES\n";
		/*cout<<s1<<"\n";
		cout<<count<<"\n"*/
	}
return 0;
}