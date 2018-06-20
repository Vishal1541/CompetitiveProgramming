//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

class Substitute
{
private:
	int ans;
public:
	int getValue(string key, string code){
		ans = 0;
		map<char,int> m;
		for(int i=0; i<10; i++){
			m[key[i]] = i+1;
		}
		int code_ptr = 0;
		while(code_ptr!=code.length()){
			if(m[code[code_ptr]]){
				ans = ans*10+(m[code[code_ptr]]%10);
			}
			code_ptr++;
		}
		return ans;
	}	
};