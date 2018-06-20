#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int,Int>
#define si set<Int>
#define si_d set<Int, greater<Int> >

Int n,m,a;
double row,col;

int main(){
	cin>>n>>m>>a;
	Int multiplierCol = m/a;
	col = (double)m/a;
	if(col!=(double)multiplierCol)
		multiplierCol++;
	Int multiplierRow = n/a;
	row = (double)n/a;
	if(row!=(double)multiplierRow)
		multiplierRow++;
	Int ANS = multiplierRow*multiplierCol;
	printf("%lld\n",ANS);
	return 0;
}