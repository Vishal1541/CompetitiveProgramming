//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

string orig = "buffalo";

class BuffaloBuffalo
{
private:
	int spaces;
public:
	string check(string s){
		spaces = 0;
		for(int i=0; i<s.length(); i++){
			s[i] = tolower(s[i]);
		}
		if(s[0]==' ' || s[s.length()-1]==' '){
			return "Not good";
		}
		for(int i=1; i<s.length(); i++){
			if(s[i]==' ' && s[i-1]==' '){
				return "Not good";
			}
		}
		int i=0,ptr;
		while(i<s.length()){
			ptr = 0;
			while(s[i]==orig[ptr]){
				i++,ptr++;
				if(ptr == 7 || i==s.length())	break;
			}
			if(ptr!=7){
				return "Not good";
			}
			if(i<s.length() && s[i]!=' '){
				return "Not good";
			}
			i++;
		}
		return "Good";
	}
	char tolower(char a){
		if(a>='A' && a<='Z') return char(a+(97-65));
		return a;
	}	
};