#include <iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main() {
	// your code goes here
	int t;
	//scanf("%d",&t);
    cin>>t;
	while(t>0){
	    t--;
	    int S=0,W[3];
	    //scanf("%d",&S);
        cin>>S;
	    for(int i=0; i<3; i++){
	        //scanf("%d",W[i]);
            cin>>W[i];
	    }
	     int sum=0;
	     sum=W[0]+W[1]+W[2];
	    // double v=sum/(double)S;
	    // int punches=(int)ceil(v);
	    // //printf("%d",punches);
        //cout<<punches<<endl;
        //int k,front=0,last=2;
        //while()
        if(S>=sum){
            cout<<1<<endl;
        }
        else{
            if(S>=W[0]+W[1]){
                cout<<2<<endl;
            }
            else{
                if(S>=W[1]+W[2]){
                    cout<<2<<endl;
                }
                else{
                    cout<<3<<endl;
                }
            }
        }
	}
	return 0;
}

//codechef Jan longchallenge question1 completed.