//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

class EllysExpression
{
private:
	int ans;
public:
	int getMax(vector<int> numbers, int numPluses, int numMinuses){
		sort(numbers.begin(), numbers.end(), greater<int>());
		ans = numbers[0];
		if(numbers.size()==1){
			return numbers[0];
		}
		for(int i=0; i<numbers.size()-1; i++){
			if(numPluses>0){
				ans += numbers[i+1];
				numPluses--;
			}
			else if(numMinuses>0){
				ans -= numbers[i+1];
				numMinuses--;
			}
		}
		return ans;
	}	
};