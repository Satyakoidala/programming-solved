#include <bits/stdc++.h>

using namespace std;

/*

--------- Passed with O(n * log(days)) complexity 

------- Look for alternative solution at the bottom for O(n) complexity solution


bool isReachable(long long day, vector<long long> br, long long D){
    long long curr_day = day;
    for (auto it = br.begin(); it!=br.end(); ++it){
        curr_day = ceil((double)curr_day/(*it))*(*it);
        if (curr_day>D) return false;
    }
    return true;
}

long long lateday(long long D, vector<long long> br){
    long long low = 1, high = D, mid=1;
    while (low<=high) {
        mid = (high-low)/2 + low;
        cout<<mid<<" "<<low<<" "<<high<<"\n";
        if (isReachable(mid, br, D)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low-1;
}

int main(){
    int testcases;
    cin>>testcases;
    for (int t=1; t<=testcases; ++t){
        long long n,days;
        cin>>n>>days;
        vector <long long> br(n);
        for (long long i=0; i<n; ++i){
            cin>>br[i];
        }
        cout<<"Case #"<<t<<": "<<lateday(days, br)<<"\n";
    }
    return 0;
}

*/

int main(){
    int testcases;
    cin>>testcases;
    for (int t=1; t<=testcases; ++t){
        long long n,days;
        cin>>n>>days;
        vector <long long> br(n);
        for (long long i=0; i<n; ++i){
            cin>>br[i];
        }
        long long curr_day = days;
        for (long long i=n-1; i>=0; --i){
            curr_day = floor(curr_day/br[i])*br[i];
        }
        cout<<"Case #"<<t<<": "<<curr_day<<"\n";
    }
    return 0;
}
