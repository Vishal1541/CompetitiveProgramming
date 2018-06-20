//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define pb push_back

Int n;

bool right(int i,vector< vector<string> > &pos){
	Int x=stoi(pos[i][0]);
	Int y=stoi(pos[i][1]);
	x++;
	string x_str=to_string(x);
	string y_str=to_string(y);
	bool flag=true;
	fl(i,0,n){
		if(x_str.compare(pos[i][0])==0 && y_str.compare(pos[i][1])==0){
			flag=false;
			break;
		}
	}
	return flag;
}

bool bottom(int i,vector< vector<string> > &pos){
	Int x=stoi(pos[i][0]);
	Int y=stoi(pos[i][1]);
	y--;
	string x_str=to_string(x);
	string y_str=to_string(y);
	bool flag=true;
	fl(i,0,n){
		if(x_str.compare(pos[i][0])==0 && y_str.compare(pos[i][1])==0){
			flag=false;
			break;
		}
	}
	return flag;
}

bool left(int i,vector< vector<string> > &pos){
	Int x=stoi(pos[i][0]);
	Int y=stoi(pos[i][1]);
	x--;
	string x_str=to_string(x);
	string y_str=to_string(y);
	bool flag=true;
	fl(i,0,n){
		if(x_str.compare(pos[i][0])==0 && y_str.compare(pos[i][1])==0){
			flag=false;
			break;
		}
	}
	return flag;
}

bool top(int i,vector< vector<string> > &pos){
	Int x=stoi(pos[i][0]);
	Int y=stoi(pos[i][1]);
	y++;
	string x_str=to_string(x);
	string y_str=to_string(y);
	bool flag=true;
	fl(i,0,n){
		if(x_str.compare(pos[i][0])==0 && y_str.compare(pos[i][1])==0){
			flag=false;
			break;
		}
	}
	return flag;
}

int main(){
	ios;
	cin>>n;
	vvi arr(n);
	vi visited(n,0);
	vector< vector<string> > pos(n);
	fl(i,0,n-1){
		Int u,v;
		cin>>u>>v;
		u--,v--;
		arr[u].pb(v);
		arr[v].pb(u);
	}
	fl(i,0,n){
		pos[i].pb("X");
		pos[i].pb("Y");
	}
	pos[0][0]=pos[0][1]="0";
	visited[0]=1;
	bool yes=true;
	fl(i,0,n){
		string x=pos[i][0];
		string y=pos[i][1];
		fl(j,0,arr[i].size()){
			if(visited[arr[i][j]])	continue;
			Int vertex = arr[i][j];
			if(right(i,pos)){
				pos[vertex][0]= to_string(stoi(x)+1);
				pos[vertex][1]= y;
			}
			else if(bottom(i,pos)){
				pos[vertex][0]= x;
				pos[vertex][1]= to_string(stoi(y)-1);
			}
			else if(left(i,pos)){
				pos[vertex][0]= to_string(stoi(x)-1);
				pos[vertex][1]= y;
			}
			else if(top(i,pos)){
				pos[vertex][0]= x;
				pos[vertex][1]= to_string(stoi(y)+1);
			}
			else{
				yes=false;
				break;
			}
			visited[arr[i][j]]=1;
		}
		if(!yes)	break;
	}
	if(yes){
		cout<<"YES\n";
		fl(i,0,n) cout<<pos[i][0]<<" "<<pos[i][1]<<endl;
	}
	else
		cout<<"NO\n";

	return 0;
}