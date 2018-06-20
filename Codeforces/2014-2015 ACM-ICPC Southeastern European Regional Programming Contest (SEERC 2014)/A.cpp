//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int k1,k2;

struct chess{
	int king,queen,bishop,knight,rook,pawn;
};

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>k1>>k2;
	string one[k1][2], two[k2][2];	//color-piece
	chess white,black;

	white.king = white.queen = black.king = black.queen = 1;
	white.pawn = black.pawn = 8;
	white.bishop = white.knight = white.rook = black.bishop = black.knight = black.rook = 2;

	fl(i,0,k1){
		cin>>one[i][0]>>one[i][1];
		if(one[i][0].compare("black")==0){
			if(one[i][1].compare("king")==0)	black.king--;
			else if(one[i][1].compare("queen")==0)	black.queen--;
			else if(one[i][1].compare("bishop")==0)	black.bishop--;
			else if(one[i][1].compare("knight")==0)	black.knight--;
			else if(one[i][1].compare("rook")==0)	black.rook--;
			else if(one[i][1].compare("pawn")==0)	black.pawn--;
		}
		else{
			if(one[i][1].compare("king")==0)	white.king--;
			else if(one[i][1].compare("queen")==0)	white.queen--;
			else if(one[i][1].compare("bishop")==0)	white.bishop--;
			else if(one[i][1].compare("knight")==0)	white.knight--;
			else if(one[i][1].compare("rook")==0)	white.rook--;
			else if(one[i][1].compare("pawn")==0)	white.pawn--;
		}
	}
	fl(i,0,k2){
		cin>>two[i][0]>>two[i][1];
	}
	int found;
	bool yes = true;
	if(white.king>0){
		found = 0;
		fl(i,0,k2){
			if(two[i][0].compare("white")==0 && two[i][1].compare("king")==0){
				found++;
			}
		}
		if(found<white.king){
			yes = false;
		}
	}
	if(yes){
		if(white.queen>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("white")==0 && two[i][1].compare("queen")==0){
					found++;
				}
			}
			if(found<white.queen){
				yes = false;
			}
		}
	}
	if(yes){
		if(white.bishop>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("white")==0 && two[i][1].compare("bishop")==0){
					found++;
				}
			}
			if(found<white.bishop){
				yes = false;
			}
		}
	}
	if(yes){
		if(white.knight>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("white")==0 && two[i][1].compare("knight")==0){
					found++;
				}
			}
			if(found<white.knight){
				yes = false;
			}
		}
	}
	if(yes){
		if(white.rook>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("white")==0 && two[i][1].compare("rook")==0){
					found++;
				}
			}
			if(found<white.rook){
				yes = false;
			}
		}
	}
	if(yes){
		if(white.pawn>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("white")==0 && two[i][1].compare("pawn")==0){
					found++;
				}
			}
			if(found<white.pawn){
				yes = false;
			}
		}
	}
	if(yes){
		if(black.king>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("black")==0 && two[i][1].compare("king")==0){
					found++;
				}
			}
			if(found<black.king){
				yes = false;
			}
		}
	}
	if(yes){
		if(black.queen>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("black")==0 && two[i][1].compare("queen")==0){
					found++;
				}
			}
			if(found<black.queen){
				yes = false;
			}
		}
	}
	if(yes){
		if(black.bishop>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("black")==0 && two[i][1].compare("bishop")==0){
					found++;
				}
			}
			if(found<black.bishop){
				yes = false;
			}
		}
	}
	if(yes){
		if(black.knight>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("black")==0 && two[i][1].compare("knight")==0){
					found++;
				}
			}
			if(found<black.knight){
				yes = false;
			}
		}
	}
	if(yes){
		if(black.rook>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("black")==0 && two[i][1].compare("rook")==0){
					found++;
				}
			}
			if(found<black.rook){
				yes = false;
			}
		}
	}
	if(yes){
		if(black.pawn>0){
		found = 0;
		fl(i,0,k2){
				if(two[i][0].compare("black")==0 && two[i][1].compare("pawn")==0){
					found++;
				}
			}
			if(found<black.pawn){
				yes = false;
			}n
		}
	}
	if(!yes){
		cout<<"impossible\n";
	}
	else{
		fl(i,0,white.king)	cout<<"white king\n";
		fl(i,0,white.queen)	cout<<"white queen\n";
		fl(i,0,white.bishop)	cout<<"white bishop\n";
		fl(i,0,white.knight)	cout<<"white knight\n";
		fl(i,0,white.rook)	cout<<"white rook\n";
		fl(i,0,white.pawn)	cout<<"white pawn\n";

		fl(i,0,black.king)	cout<<"black king\n";
		fl(i,0,black.queen)	cout<<"black queen\n";
		fl(i,0,black.bishop)	cout<<"black bishop\n";
		fl(i,0,black.knight)	cout<<"black knight\n";
		fl(i,0,black.rook)	cout<<"black rook\n";
		fl(i,0,black.pawn)	cout<<"black pawn\n";
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}