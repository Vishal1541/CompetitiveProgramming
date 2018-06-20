//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

class EllysGame
{
private:
	int ans,M,N,moves;
public:
	int getMax(vector<string> board){
		M = board[0].length();
		N = board.size();
		// for(int i=0; i<N; i++)	arr.push_back(board[i]);
		ans = -1;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				// for(int k=0; k<N; k++)	arr[k] = board[k];
				vector<string> arr(board);
				moves = 0;
				if(board[i][j]!='.'){
					solve(arr,i,j,'x');
					ans = max(ans, moves);
				}
			}
		}
		return ans;
	}
	void solve(vector<string> &arr, int i, int j, char last){
		if(i<0 || i>=N || j<0 || j>=M)	return;
		moves++;
		if(arr[i][j]=='v'){
			arr[i][j] = '.';
			solve(arr,i+1,j,'v');
		}
		else if(arr[i][j]=='^'){
			arr[i][j] = '.';
			solve(arr,i-1,j,'^');
		}
		else if(arr[i][j]=='<'){
			arr[i][j] = '.';
			solve(arr,i,j-1,'<');
		}
		else if(arr[i][j]=='>'){
			arr[i][j] = '.';
			solve(arr,i,j+1,'>');
		}
		else if(arr[i][j]=='.'){
			arr[i][j] = '.';
			if(last=='v')	solve(arr,i+1,j,'v');
			else if(last=='^')	solve(arr,i-1,j,'^');
			else if(last=='>')	solve(arr,i,j+1,'>');
			else if(last=='<')	solve(arr,i,j-1,'<');
		}
	}	
};