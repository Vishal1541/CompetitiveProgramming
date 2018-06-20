#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
const int MAX = 1e5+7,MAX2 = 50007;
int n,A[MAX],ans,g;
vector<bool> P(MAX,true);
vector<vector<int> > fact(MAX);
set<int> :: iterator it,it2;
 
struct STree{
    set<int> U,I;
};
STree stree[4*MAX2];
 
void build(int pos, int l, int h){
    if(l==h){
        for(int i=0; i<fact[A[l]].size(); i++){
            stree[pos].U.insert(fact[A[l]][i]);
            stree[pos].I.insert(fact[A[l]][i]);
        }
        // cout<<A[l]<<"->"<<stree[pos].U.size()<<endl;
        return;
    }
    int m = (l+h)/2;
    build(2*pos+1,l,m);
    build(2*pos+2,m+1,h);
    for(it=stree[2*pos+1].I.begin(); it!=stree[2*pos+1].I.end(); it++){
        it2 = stree[2*pos+2].I.find(*it);
        if(it2!=stree[2*pos+2].I.end()){
            stree[pos].I.insert(*it);
        }
    }
    for(it=stree[2*pos+1].U.begin(); it!=stree[2*pos+1].U.end(); it++){
        stree[pos].U.insert(*it);
    }
    for(it=stree[2*pos+2].U.begin(); it!=stree[2*pos+2].U.end(); it++){
        stree[pos].U.insert(*it);
    }
}
 
void update(int pos, int l, int h, int index, int val){
    if(l==h){
        stree[pos].U.clear();
        stree[pos].I.clear();
        for(int i=0; i<fact[A[l]].size(); i++){
            stree[pos].U.insert(fact[A[l]][i]);
            stree[pos].I.insert(fact[A[l]][i]);
        }
        return;
    }
    int m = (l+h)/2;
    if(l<=index && index<=m){
        update(2*pos+1,l,m,index,val);
    }
    else{
        update(2*pos+2,m+1,h,index,val);
    }
    stree[pos].I.clear();
    stree[pos].U.clear();
    for(it=stree[2*pos+1].I.begin(); it!=stree[2*pos+1].I.end(); it++){
        it2 = stree[2*pos+2].I.find(*it);
        if(it2!=stree[2*pos+2].I.end()){
            stree[pos].I.insert(*it);
        }
    }
    for(it=stree[2*pos+1].U.begin(); it!=stree[2*pos+1].U.end(); it++){
        stree[pos].U.insert(*it);
    }
    for(it=stree[2*pos+2].U.begin(); it!=stree[2*pos+2].U.end(); it++){
        stree[pos].U.insert(*it);
    }
}
 
void query(int pos, int l, int h, int rl, int rh){
    if(rh<l || h<rl)    return;
    int m = (l+h)/2;
    if(l>=rl && h<=rh){
        for(int i=0; i<fact[g].size(); i++){
            if(stree[pos].I.find(fact[g][i])!=stree[pos].I.end()){
                return;
            }
        }
        bool in = 0;
        for(int i=0; i<fact[g].size(); i++){
            if(stree[pos].U.find(fact[g][i])!=stree[pos].U.end()){
                in = 1;
                break;
            }
        }
        if(in){
            query(2*pos+1,l,m,rl,rh);
            query(2*pos+2,m+1,h,rl,rh);
            return;
        }
        ans += h-l+1;
        return;
    }
    query(2*pos+1,l,m,rl,rh);
    query(2*pos+2,m+1,h,rl,rh);
}
 
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    P[1] = 0;
    for(int i=2; i<MAX; i++){
        if(P[i]){
            fact[i].push_back(i);
            for(int j=2*i; j<MAX; j+=i){
                P[j] = 0;
                fact[j].push_back(i);
            }
        }
    }
    cin>>n;
    for(int i=0; i<n; i++)  cin>>A[i];
    build(0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int inp;
        cin>>inp;
        if(inp==1){
            int x,y;
            cin>>x>>y;
            x--;
            A[x] = y;
            update(0,0,n-1,x,y);
        }
        else{
            int l,r;
            cin>>l>>r>>g;
            l--,r--;
            ans = 0;
            query(0,0,n-1,l,r);
            cout<<ans<<endl;
        }
    }
 
    return 0;
}  