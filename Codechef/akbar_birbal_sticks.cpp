#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t-->0){
        long int n;
        cin>>n;
        vector<long long> stick_height(n);
        for (long int i=0; i<n; ++i){
            cin>>stick_height[i];
        }
        sort(stick_height.begin(), stick_height.end());
        long int ans = 0;
        for (long int i=n-1; i>0; --i){
            if ((stick_height[i]-stick_height[i-1])>0) ans++;
        }
        if (stick_height[0]>0) cout<<ans+1<<"\n";
        else cout<<ans<<"\n";
    }
    return 0;
}