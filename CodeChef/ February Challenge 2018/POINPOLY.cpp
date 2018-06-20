// VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

#define int ll
#define all(v)  (v).begin(), (v).end()
#define pb push_back
#define SZ(a) ((int)((a).size()))
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep2(i,n) for(int i = 1; i <= (n); i++)
#define tag(i,v) rep(i,SZ(v))
#define _tr(x) #x<<" = "<<(x)
#define trace(x) {if(!OJ)cerr<<_tr(x)<<endl;}
#define trace2(x,y) {if(!OJ)cerr<<_tr(x)<<" "<< _tr(y)<<endl;}
#define fst get<0>
#define snd get<1>
#define thd get<2>
#define divup(x,y) ((x)/(y)+(0<((x)%(y))))
#define mp make_tuple
#define range(x,a,b) ((x) >= (a) && (x) <= (b))

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef tuple<int,int> int2;

const int inf = 1LL << 60;

#define eb emplace_back


typedef complex<double> point;
map<pair<double,double>,int> flag,vertex;
int ptr,n;
pair<int,int> ans[1000009];
bool found;

double cross(const point& a, const point& b) {
  return imag(conj(a)*b);
}

bool convex_contains(const vector<point>& P, const point& p){

  const int n = P.size();
  point g = (P[0] + P[n/4] + P[2*n/4] + P[3*n/4]) / 4.0; // inner-point
  int a = 0, b = n;
  while (a+1 < b) { // invariant: c is in fan g-P[a]-P[b]
    int c = (a + b) / 2;
    if (cross(P[a]-g, P[c]-g) > 0) { // angle < 180 deg
      if (cross(P[a]-g, p-g) >= 0 && cross(P[c]-g, p-g) < 0) a = c;
      else                                                  b = c;
    } else {
      if (cross(P[a]-g, p-g) <= 0 && cross(P[c]-g, p-g) > 0) b = c;
      else                                                  a = c;
    }
  }
  b %= n;
  //trace(g);
  //trace2(a,b);
  //trace(cross(P[a] - p, P[b] - p));
  if (cross(P[a] - p, P[b] - p) < 0) return true;
  if (cross(P[a] - p, P[b] - p) > 0) return false;
  return false;
}

void traverse(const vector<point>& poly,point p){
    if(flag[{real(p),imag(p)}] || found) return;
    flag[{real(p),imag(p)}] = 1;
    if(real(p)>1000000009 || imag(p)>1000000009)    return;
    point p1(real(p)+1,imag(p));
    point p2(real(p)-1,imag(p));
    point p3(real(p),imag(p)+1);
    point p4(real(p),imag(p)-1);
    if(convex_contains(poly,p)){
        ans[ptr] = {real(p),imag(p)};
        ptr++;
        if(ptr==n/10){
            found = 1;
            return;
        }
        if(!found && !flag[{real(p1),imag(p1)}])    traverse(poly,p1);
        if(!found && !flag[{real(p2),imag(p2)}])    traverse(poly,p2);
        if(!found && !flag[{real(p3),imag(p3)}])    traverse(poly,p3);
        if(!found && !flag[{real(p4),imag(p4)}])    traverse(poly,p4);
    }
    else if(vertex[{real(p),imag(p)}]){
        if(!found && !flag[{real(p1),imag(p1)}])    traverse(poly,p1);
        if(!found && !flag[{real(p2),imag(p2)}])    traverse(poly,p2);
        if(!found && !flag[{real(p3),imag(p3)}])    traverse(poly,p3);
        if(!found && !flag[{real(p4),imag(p4)}])    traverse(poly,p4);
    }
}

#undef int
int main() {
    int t;
    cin>>t;
    while(t--){
        found = 0;
        vertex.clear();
        flag.clear();
        ptr = 0;
        ll xx = 0, yy = 0;
        cin>>n;
        vector<point> poly;
        for(int i=0; i<n; i++){
            int x,y;
            cin>>x>>y;
            vertex[{x,y}] = 1;
            poly.eb(x,y);
            xx += x;
            yy += y;
        }
        reverse(poly.begin(),poly.end());
        xx /= n;
        yy /= n;
        point p(xx,yy);
        point p1(real(p)+1,imag(p));
        point p2(real(p)-1,imag(p));
        point p3(real(p),imag(p)+1);
        point p4(real(p),imag(p)-1);
        traverse(poly,p);
        if(!found)  traverse(poly,p1);
        if(!found)  traverse(poly,p2);
        if(!found)  traverse(poly,p3);
        if(!found)  traverse(poly,p4);
        if(!found){
            for(int i=0; i<n; i++){
                if(!flag[{real(poly[i]),imag(poly[i])}]){
                    traverse(poly,poly[i]);
                }
                if(found)   break;
            }
        }
        if(found){
            for(int i=0; i<ptr; i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    #ifndef LOCAL_DEFINE
        cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
    #endif
    return 0;
}