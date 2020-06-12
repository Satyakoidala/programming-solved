/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;
typedef long l;

int search(vector<int>& nums, int target) {
        if (nums.size()==0) return -1;
        if (nums.size()==1) {
            if (nums[0]==target) return 0;
            return -1;
        }
        int i=0,j=nums.size()-1,mid;
        while (i<=j && i<nums.size() && j>-1){
            mid=i+(j-i)/2;
            if (nums[mid]==target) return mid;
            if (nums[i]==target) return i;
            if (nums[j]==target) return j;
            if (nums[i]<nums[mid]) {
                if (nums[i]<=target && target<nums[mid]) j=mid-1;
                else i=mid+1;
            }
            else {
                if (target<nums[i] && target>nums[mid]) i=mid+1;
                else j=mid-1;
            }
        }
        return -1;
   }

int main(){
	fastio;
	//make calls to the function
	return 0;
}