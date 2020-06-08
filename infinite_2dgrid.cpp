#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;
typedef long l;

ll steps(ll n){
	ll i=1,j=0;
	while(j<n){
		j+=(1<<(i-1));
		i+=1;
	}
	return i;
}
string path(ll x, ll y){
	ll stps = steps(abs(x)+abs(y))-1;
	string s="";
	while(x!=0 || y!=0){
		//cout<<"( "<<x<<" ,"<<y<<" )"<<"\n";
		char dir= max(abs(x),abs(y))==abs(x)? (x<0? 'E':'W') : (y<0? 'N':'S');
		s+=dir;
		switch(dir){
			case 'E': x+=(1<<(stps-1));
					  stps--;
					  break;
			case 'W': x-=(1<<(stps-1));
					  stps--;
					  break;
			case 'N': y+=(1<<(stps-1));
					  stps--;
					  break;
			case 'S': y-=(1<<(stps-1));
					  stps--;
					  break;
			default: break;
		}
	}
	//cout<<"( "<<x<<" ,"<<y<<" )"<<"\n";
	reverse(s.begin(),s.end());
	string s1="";
	for(ll i=0; i<s.length(); ++i){
		switch(s[i]){
			case 'E': s1+='W';
					  break;
			case 'W': s1+='E';
					  break;
			case 'N': s1+='S';
					  break;
			case 'S': s1+='N';
					  break;
			default: break;
		}
	}
	return s1;
}

int main(){
	fastio;
	ll t;
	cin>>t;
	for(int i=1; i<=t; ++i){
		ll x,y;
		cin>>x>>y;
		if (abs(x%2)==abs(y%2)){
			cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
		}
		else
			cout<<"Case #"<<i<<": "<<path(x,y)<<endl;
	}
	return 0;
}