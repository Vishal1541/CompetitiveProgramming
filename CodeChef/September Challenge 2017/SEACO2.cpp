    //    VISHAL ANAND
    /*
    3
    5 5
    1 1 2
    1 4 5
    2 1 2
    2 1 3
    2 3 4
    1 2
    1 1 1
    1 1 1
    10 10
    1 1 10
    2 1 1
    2 1 2
    2 1 3
    2 1 4
    2 1 5
    2 1 6
    2 1 7
    2 1 8
    2 1 9
    */
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
    #define us unordered_set
    #define um unordered_map
    #define mii map<Int,Int>
    #define qi queue<Int>
    #define pb push_back
    #define MOD 1000000007
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
    #define _ << " " <<
    #define cout cout
    #define continue continue
    #define break break
    #define endl endl
    template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
    template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}
     
    Int T,n,m,type,L,R,mod=1000000007;
     
    void updateRange(vi& tree,Int node, Int start, Int end, Int l, Int r, Int val){
        if (start > end || start > r || end < l)
            return;

        if (start>=l && end<=r){
            tree[node] = (tree[node]%mod + val%mod)%mod;
            // cout<<tree[node]<<"-"<<node<<"   ";
            return;
        }
     
        Int mid = (start + end) / 2;
        updateRange(tree, node*2+1, start, mid, l, r, val);
        updateRange(tree, node*2+2, mid + 1, end, l, r, val);
     
    }
     
    void queryTree(vi& segTreeArr, Int index, Int low, Int high, Int pos,Int& prv){
        if(low==high && index==low){
            prv += segTreeArr[pos];
            return;
        }
        prv += segTreeArr[pos];
        Int mid=(low+high)/2;
        if(index>=low && index<=mid)    queryTree(segTreeArr,index,low,mid,2*pos+1,prv);
        else    queryTree(segTreeArr,index,mid+1,high,2*pos+2,prv);
    }
     
    void fillArrayfromTree(vi& A, vi& tree,Int node, Int start, Int end,Int sum){
        tree[node] = (tree[node]+sum)%mod;
        if(start==end){
            A[start] = tree[node];
            return;
        }
        int mid = (start + end) / 2;
        fillArrayfromTree(A, tree, node*2+1, start, mid, tree[node]);
        fillArrayfromTree(A, tree, node*2+2, mid + 1, end,tree[node]);
    }
     
    int main(){
        ios;
        cin>>T;
        while(T--){
            cin>>n>>m;
            Int prv;
            Int x = (Int)(ceil(log2(m)));
            Int sizeM = 2*(Int)pow(2, x) - 1;
            x = (Int)(ceil(log2(n)));
            Int sizeN = 2*(Int)pow(2, x) - 1;
            vi A(n),segTreeFreq(sizeM,0),segTreeArr(sizeN,0);
            vvi queries(m,vi(3) );
            fl(i,0,m){
                cin>>type>>L>>R;
                queries[i][0] = type;
                queries[i][1] = L-1;
                queries[i][2] = R-1;
            }
            for(int i=m-1;i>=0;i--){
                if(queries[i][0]==2){
                    prv=0;
                    queryTree(segTreeFreq,i,0,m-1,0,prv);
                    updateRange(segTreeFreq,0,0,m-1,queries[i][1],queries[i][2],prv+1);
                }
                else{
                    updateRange(segTreeFreq,0,0,m-1,i,i,1);
                }
            }
            fl(i,0,m){
                if(queries[i][0]==1){
                    prv=0;
                    queryTree(segTreeFreq,i,0,m-1,0,prv);
                    updateRange(segTreeArr,0,0,n-1,queries[i][1],queries[i][2],prv);
                }
            }
            fillArrayfromTree(A,segTreeArr,0,0,n-1,0);
            fl(i,0,n)   cout<<A[i]<<" ";
            cout<<endl;
        }
     
        return 0;
    } 