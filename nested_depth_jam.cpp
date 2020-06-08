#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string nested_depth(string s, ull n){
	string ans = "";
	for(int j=0; j<s[0]-'0'; ++j)	ans+='(';
	ans+=s[0];

	for(ull i=1; i<n; ++i){
		if(s[i-1]<=s[i]){
			for(int j=0; j<abs(s[i]-s[i-1]); ++j)
				ans+='(';
			ans+=s[i];
		}
		else{
			for(int j=0; j<abs(s[i]-s[i-1]); ++j)
				ans+=')';
			ans+=s[i];
		}
	}

	for(int j=0; j<s[n-1]-'0'; ++j)	ans+=')';

	return ans;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(ll i=1; i<=t; i++){
		string s;
		cin>>s;
		cout<<"Case #"<<i<<": "<<nested_depth(s,s.size())<<endl;
	}	
	return 0;
}