#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, pos, l, r;
    cin>>n>>pos>>l>>r;
    int a = 1,b = n;
    int time_ = 0;
    int curr_pos = pos;
    if(abs(pos-l) < abs(pos-r)) {
        if(l-a > 0) {
            time_ += 1 + abs(curr_pos-l);
            curr_pos = l;
        }
        if(b-r > 0) {
            time_ += abs(r-curr_pos) + 1;
            curr_pos = r;
        }
    }
    else {
        if(b-r > 0) {
            time_ += 1 + abs(curr_pos-r);
            curr_pos = r;
        }
        if(l-a > 0) {
            time_ += abs(curr_pos-l) + 1;
            curr_pos = l;
        }
    }
    cout<<time_<<endl;
    return 0;
}