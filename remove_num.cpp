#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int>& nums, int val) {
        int c=0,l=nums.size();
        while (true){
            int i=0;
            bool f=true;
            while (i<nums.size()){
                cout<<nums[i]<<" ";
                if (nums[i]==val) {
                    f=false;c++;
                    nums.erase(nums.begin()+i);
                    break;
                }
                i++;
            }
            cout<<endl;
            if (f) break;
            //if (i-1>=0) i-=1;
        }
        return l-c;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v{0,1,2,2,3,0,4,2,2};
    int k=2;
    int l=removeElement(v,k);
    for (int i=0; i<l; ++i) cout<<v[i]<<" ";
    cout<<"\n";
    return 0;
}