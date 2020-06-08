#include <bits/stdc++.h>

using namespace std;

long long count(int p,int q,int r,int s){
    int cols=max(max(p,q)+1,max(r,s)+1);
    int arr[cols][cols];
    memset(arr,0,sizeof(arr));
    for (int i=1; i<cols; ++i){
        arr[i][i]=1;
        for (int j=i+1; j<cols; ++j){
            arr[i][j]=INT_MAX;
            int m=1, n=j-1;
            while (m<=n) {
                arr[i][j]=min(arr[i][j],arr[min(i,m)][max(i,m)]+arr[min(i,n)][max(i,n)]);
                m++;
                n--;
            }
        }
    }
    for (int i=0; i<cols; ++i){
        for (int j=0; j<cols; ++j) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    long long sum=0;
    for (int i=p; i<q+1; ++i){
        for (int j=r; j<s+1; ++j) sum+=arr[min(i,j)][max(i,j)];
    }
    return sum;
}

int main(){
    int p,q,r,s;
    cin>>p>>q>>r>>s;
    cout<<count(p,q,r,s)<<endl;
    return 0;
}