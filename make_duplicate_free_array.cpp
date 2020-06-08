#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;
typedef long l;

int removeDuplicates(vector<int>& nums) {
        int c=1,prev=nums[0];
        for (int i=1; i<nums.size(); ++i) {
            if (prev!=nums[i]) c++;
            prev=nums[i];
        }
        cout<<c<<endl;
        while(nums.size()>c){
            int i=1,prev=nums[0];
            while(i<=c){
                cout<<"in inner while\n";
                if (nums[i]==prev) {
                    nums.erase(nums.begin()+i);
                    break;
                }
                i++;
                prev=nums[i];
            }
            for (int j=0; j<nums.size(); ++j) cout<<nums[j]<<" ";
            cout<<"\n";
        }
        return c;
    }

int main(){
	fastio;
	std::vector<int> v{1,1,2};
	cout<<removeDuplicates(v)<<"\n";
    for (int j=0; j<v.size(); ++j) cout<<v[j]<<" ";
    cout<<"\n";
	return 0;
}