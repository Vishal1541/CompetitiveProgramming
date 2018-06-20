//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

class TaroBalls
{
private:
	int ans;
public:
	string getWinner(int R, int B){
		if(R==B){
			return "Friend";
		}
		else{
			return "Taro";
		}
	}	
};