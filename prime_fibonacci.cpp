/*
-----------------TCS MOCKVITA ROUND 1---------------------
*/
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;
typedef long l;

void soe(vector <int> &prime, ull n){
	prime[0]=prime[1]=0;
	ull i=2;
	while (i*i<n){
		for (ull k = 2*i; k<=n; k+=i) prime[k]=0;
		i++;
	}
}

int main(){
	fastio;
	ull n1,n2;
	cin>>n1>>n2;
	ll n=stoull(to_string(max(n1,n2))+to_string(max(n1,n2)));
	std::vector<int> prime(n+1,1);
	soe(prime,n);
	vector<ull> list1; 
	for (ull i=n1; i<=n2; ++i) if (prime[i]) list1.push_back(i);
	map <ull,int> list;
	vector<ull> list2;
	for (ull i=0; i<list1.size(); ++i){
		for (ull j=0; j<list1.size(); ++j){
			if (i!=j){
				ll num=stoull(to_string(list1[i])+to_string(list1[j]));
				if (prime[num]) {
					if (list.find(num)==list.end()) list2.push_back(num);
					list[num]=1;
				}
			}
		}
	}
	sort(list2.begin(),list2.end());
	ull count=list2.size(),a=list2[0],b=list2[count-1],c;
	count-=2;
	while (count){
		c=a+b;
		a=b;
		b=c;
		count--;
	}
	cout<<c<<endl;
	return 0;
}