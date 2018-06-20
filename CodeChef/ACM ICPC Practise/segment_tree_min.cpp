#include <bits/stdc++.h>
using namespace std;

void constructSegTree(int inputArr[], int segTreeArr[], int low, int high, int pos){
	if(low==high){
		segTreeArr[pos] = inputArr[low];
		return;
	}
	int mid=(low+high)/2;
	constructSegTree(inputArr,segTreeArr,low,mid,2*pos+1);
	constructSegTree(inputArr,segTreeArr,mid+1,high,2*pos+2);
	segTreeArr[pos] = min(segTreeArr[2*pos+1],segTreeArr[2*pos+2]);
}

int rangeMinQuery(int segTreeArr[], int qlow, int qhigh, int low, int high, int pos){
	if(qlow<=low && qhigh>=high)	return segTreeArr[pos];				//total overlap
	else if(qlow>high || qhigh<low)	return numeric_limits<int>::max();	//no overlap
	int mid=(low+high)/2;
	return min(rangeMinQuery(segTreeArr,qlow,qhigh,low,mid,2*pos+1),	//partial overlap
				rangeMinQuery(segTreeArr,qlow,qhigh,mid+1,high,2*pos+2));
}

unsigned int nextPowerOf2(unsigned int n)
{
  unsigned count = 0;
  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}

int main(){
	int n,q,size,l,r;
	cin>>n>>q;
	size = nextPowerOf2(n);
	int arr[n],segArr[size];
	for(int i=0;i<n;i++)	cin>>arr[i];
	constructSegTree(arr,segArr,0,n-1,0);
	while(q--){
		cin>>l>>r;
		cout<<rangeMinQuery(segArr,l,r,0,n-1,0)<<endl;
	}
	return 0;
}
