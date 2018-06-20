#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int T, len_string1, len_string2;
string string1, string2;

map<char,int> initMap(){
	map<char,int> m;
	pair<char,int> p;
    p.second = 0;
    for(char ch='0'; ch<='9'; ch++){
        p.first = ch;
        m.insert(p);
    }
    for(char ch='a'; ch<='z'; ch++){
        p.first = ch;
        m.insert(p);
    }
    for(char ch='A'; ch<='Z'; ch++){
        p.first = ch;
        m.insert(p);
    }
    return m;
}

int main(){
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        cin>>string1;
        cin>>string2;
        len_string1 = string1.length();
        len_string2 = string2.length();
        map<char,int> map_initial = initMap();
        for(int j=0; j<len_string1; j++){
        	char get_char = string1[j];
        	map_initial[get_char]++;
        }
        /*for(map<char,int> :: iterator itr = map_initial.begin(); itr!=map_initial.end(); itr++){
            printf("%c->%d  ",itr->first, itr->second);
        }*/
        map<char,int> map_final = initMap();
        int FINAL_COUNT = 0;
        for(int j=0; j<len_string2; j++){
        	char get_char = string2[j];
        	if(map_final[get_char] < map_initial[get_char]){
        		map_final[get_char]++;
        		FINAL_COUNT++;
        	}
        }
        printf("%d\n",FINAL_COUNT);
    }
    return 0;
}