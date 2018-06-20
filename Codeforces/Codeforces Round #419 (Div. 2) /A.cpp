#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

string input;
char HH1, HH2, MM1, MM2;

int main(){
	cin>>input;
	HH1 = input.at(0);
	HH2 = input.at(1);
	MM1 = input.at(3);
	MM2 = input.at(4);

	int count = 0;
	while(!(HH1 == MM2 && HH2 == MM1)){
		if(MM2 != '9'){
			MM2 ++;
			count++;
			continue;
		}
		if(MM2 == '9'){
			MM2 = '0';
			if(MM1 != '5'){
				MM1 ++;
				count++;
				continue;
			}
			if(MM1 == '5'){
				MM1 = '0';
				if(HH1 != '2'){
					if(HH2 != '9'){
						HH2++;
						count++;
						continue;
					}
					if(HH2 == '9'){
						HH2 = '0';
						HH1++;
						count++;
						continue;
					}
				}
				if(HH1 == '2'){
					if(HH2 != '3'){
						HH2++;
						count++;
						continue;
					}
					if(HH2 == '3'){
						HH1 = '0';
						HH2 = '0';
						count++;
						continue;
					}
				}
			}
		}
	}
	printf("%d\n", count);

	return 0;
}