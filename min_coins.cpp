/*	
------------TCS MOCKVITA ROUND 1-------------------
*/
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;
typedef long l;

int main(){
	fastio;
	ll t;
	cin>>t;
	while(t--){
		ll target;
		cin>>target;
		// ll diff=target,sum_so_far=0,count=0,n=1,k=0;
		// while (diff>(sum_so_far+1)){
		// 	sum_so_far+=n;
		// 	n++;
		// 	diff=target-sum_so_far;
		// 	k++;
		// }
		// if (diff==0) cout<<k<<endl;
		// else cout<<k+1<<endl;
		cout<<floor(log(target)/log(2))+1<<endl;
	}	
	return 0;
}