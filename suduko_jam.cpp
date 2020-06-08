#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

unordered_map <int , int> rows;
unordered_map <int , int> cols;

void watchrows(ll ** arr, ull r, ull n){
	ull i;
	for(i=0; i<n; i++){
		if(arr[r][abs(arr[r][i])-1]<0)
			break;
		arr[r][abs(arr[r][i])-1]*=-1;
	}

	for(ull j=0; j<n; j++) arr[r][j]=abs(arr[r][j]);

	if(i<n){
		if(rows.find(r)==rows.end())
			rows.insert(make_pair(r,1));
	}
}

void watchcols(ll ** arr, ull c, ull n){
	ull i;
	for(i=0; i<n; i++){
		if(arr[abs(arr[i][c])-1][c]<0)
			break;
		arr[abs(arr[i][c])-1][c]*=-1;
	}
	for(ull j=0; j<n; j++) arr[j][c]=abs(arr[j][c]);
	if(i<n){
		if(cols.find(c)==cols.end())
			cols.insert(make_pair(c,1));
	}
}

void duplicates(ll **arr, ull n){
	for(ull i=0; i<n; i++){
		//for rows
		watchrows(arr, i, n);
		//for cols
		watchcols(arr, i, n);
	}
}


int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(ll i=1; i<=t; i++){
		ull n;
		cin>>n;
		ll **arr = new ll *[n];
		for(ull i=0; i<n; i++) arr[i] = new ll[n];

		ull trace=0;
		for(ull i=0; i<n; i++){
			for(ull j=0; j<n; j++){
				cin>>arr[i][j];
				if(i==j)
					trace+=arr[i][j];
			}
		}
		rows.clear();
		cols.clear();

		duplicates(arr,n);
		cout<<"Case #"<<i<<": "<<trace<<" "<<rows.size()<<" "<<cols.size()<<endl;
	}
	return 0;
}