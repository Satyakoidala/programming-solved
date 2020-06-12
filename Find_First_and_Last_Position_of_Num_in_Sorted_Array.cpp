/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;
typedef long l;

vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return vector<int> {-1,-1};
        int i=0,j=nums.size()-1,mid,x,y;
        while (i<=j){
            mid=i+(j-i)/2;
            if (mid<nums.size() && nums[mid]<=target) i=mid+1;
            else j=mid-1;
        }
        y=i-1;
        i=0;
        j=nums.size()-1;
        while (i<=j){
            mid=i+(j-i)/2;
            if (mid<nums.size() && nums[mid]<target) i=mid+1;
            else j=mid-1;
        }
        x=j+1;
        //cout<<x<<" "<<y<<"\n";
        if (x<0 or x>=nums.size() or y<0 or y>=nums.size() or (nums[x]!=target or nums[y]!=target)) return vector<int> {-1,-1};
        return vector<int> {x,y};
    }

int main(){
	fastio;
	//write your checker code here
	return 0;
}