//    VISHAL ANAND
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <functional>

using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
#define Int unsigned long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define us unordered_set
#define um unordered_map
#define mii map<Int,Int>
#define qi queue<Int>
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define PI 3.141592653589793238L
#define F first
#define S second
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define mp make_pair
#define gcd(x,y)  __gcd(x, y)
#define cout cout
#define continue continue
#define break break
#define endl endl
/*
sort(first_iterator, last_iterator) – To sort the given vector.
reverse(first_iterator, last_iterator) – To reverse a vector.
*max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
*min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements 

count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
find(first_iterator, last_iterator, x) – Points to last address of vector ((name_of_vector).end()) if element is not present in vector.

binary_search(first_iterator, last_iterator, x) – Tests whether x exists in sorted vector or not. use with if()
lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.
upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’. 

arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly.
arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line. 
distance(first_iterator,desired_position) – It returns the distance of desired position from the first iterator.This function is very useful while finding the index. 

n = n << 1;   // Multiply n with 2
n = n >> 1;   // Divide n by 2

Number of digits in N =floor(log10(N)) + 1;

are all of the elements positive?
all_of(first, first+n, ispositive()); 

is there at least one positive element?
any_of(first, first+n, ispositive());

are none of the elements positive?
none_of(first, first+n, ispositive()); 

copy 5 elements from source to target
copy_n(source, 5, target);

/* Function to check if x is power of 2*/
bool isPowerOfTwo (int x)
{
  /* First x in the below expression is 
    for the case when x is 0 */
  return x && (!(x&(x-1)));
}

char arr[10][10];
int pos[2][105];
int pos_size=0;
Int x,y;
bool yes = false;

void horiz_right(){
	int num_dots=0, Ofound=0,j;
	for(j=y+1; j<y+5; j++){
		if(j<10){
			if(arr[x][j]=='X')	continue;
			if(arr[x][j]=='O'){
				Ofound = 1;
				break;
			}
			if(arr[x][j]=='.')	num_dots++;
		}
		else 	break;
	}
	if(num_dots==1 && Ofound==0 && j==y+5)	yes = true;
}

void horiz_left(){
	int num_dots=0, Ofound=0;
	int j;
	for(j=y-1; j>y-5; j--){
		if(j>=0){
			if(arr[x][j]=='X')	continue;
			if(arr[x][j]=='O'){
				Ofound = 1;
				break;
			}
			if(arr[x][j]=='.')	num_dots++;
		}
		else 	break;
	}
	if(num_dots==1 && Ofound==0 && j==y-5)	yes = true;
}

void vert_down(){
	int num_dots=0, Ofound=0;
	int i;
	for(i=x+1; i<x+5; i++){
		if(i<10){
			if(arr[i][y]=='X')	continue;
			if(arr[i][y]=='O'){
				Ofound = 1;
				break;
			}
			if(arr[i][y]=='.')	num_dots++;
		}
		else 	break;
	}
	if(num_dots==1 && Ofound==0 && i==x+5)	yes = true;
}

void vert_up(){
	int num_dots=0, Ofound=0;
	int i;
	for(i=x-1; i>x-5; i--){
		if(i>=0){
			if(arr[i][y]=='X')	continue;
			if(arr[i][y]=='O'){
				Ofound = 1;
				break;
			}
			if(arr[i][y]=='.')	num_dots++;
		}
		else 	break;
	}
	if(num_dots==1 && Ofound==0 && i==x-5)	yes = true;
}

void diag_right_down(){
	int num_dots=0, Ofound=0;
	int i=x,j=y,l;
	for(l=1; l<5; l++){
		i++,j++;
		if(i<10 && j<10){
			if(arr[i][j]=='X')	continue;
			if(arr[i][j]=='O'){
				Ofound = 1;
				break;
			}
			if(arr[i][j]=='.')	num_dots++;
		}
		else 	break;
	}
	if(num_dots==1 && Ofound==0 && l==5)	yes = true;
}

void diag_right_up(){
	int num_dots=0, Ofound=0;
	int i=x,j=y,l;
	for(l=1; l<5; l++){
		i--,j++;
		if(i>=0 && j<10){
			if(arr[i][j]=='X')	continue;
			if(arr[i][j]=='O'){
				Ofound = 1;
				break;
			}
			if(arr[i][j]=='.')	num_dots++;
		}
		else 	break;
	}
	if(num_dots==1 && Ofound==0 && l==5)	yes = true;
}

void diag_left_down(){
	int num_dots=0, Ofound=0;
	int i=x,j=y,l;
	for(l=1; l<5; l++){
		i++,j--;
		if(i<10 && j>=0){
			if(arr[i][j]=='X')	continue;
			if(arr[i][j]=='O'){
				Ofound = 1;
				break;
			}
			if(arr[i][j]=='.')	num_dots++;
		}
		else 	break;
	}
	if(num_dots==1 && Ofound==0 && l==5)	yes = true;
}

void diag_left_up(){
	int num_dots=0, Ofound=0;
	int i=x,j=y,l;
	for(l=1; l<5; l++){
		i--,j--;
		if(i>=0 && j>=0){
			if(arr[i][j]=='X')	continue;
			if(arr[i][j]=='O'){
				Ofound = 1;
				break;
			}
			if(arr[i][j]=='.')	num_dots++;
		}
		else 	break;
	}
	if(num_dots==1 && Ofound==0 && l==5)	yes = true;
}

int main(){
	ios;
	fl(i,0,10){
		fl(j,0,10){
			char input;
			cin>>input;
			arr[i][j] = input;
			if(input=='X'){
				pos[0][pos_size]=i;
				pos[1][pos_size]=j;
				pos_size++;
			}
		}
	}
	fl(i,0,pos_size){
		x = pos[0][i];
		y = pos[1][i];
		horiz_right();
		if(!yes)	horiz_left();
		if(!yes)	vert_down();
		if(!yes)	vert_up();
		if(!yes)	diag_right_down();
		if(!yes)	diag_right_up();
		if(!yes)	diag_left_down();
		if(!yes)	diag_left_up();
	}
	if(yes)	cout<<"YES\n";
	else 	cout<<"NO\n";

	return 0;
}