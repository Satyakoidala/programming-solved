/*
------------------ TCS MOCKVITA ROUND 1---------------------
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
	ll c;
	cin>>c;
	map<ull,ull> time;
	while (c--){
		ll a,b;
		ull v;
		cin>>a>>b>>v;
		time[(ull)sqrt(a*a+b*b)/v]++;
	}
	//cout<<"cp1\n";
	map<ull,ull>::iterator itr;
	ull sum=0;
	for (itr=time.begin(); itr!=time.end(); ++itr){
		sum+=(itr->second)*(itr->second-1)/2;
	} 
	cout<<sum<<endl;
	return 0;
}