class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lt=0,rt=nums.size()-1;
        while(lt+1<rt){
            int mid=lt+(rt-lt)/2;
            if(nums[mid]<target){
                lt=mid;
            }
            else{
                rt=mid;
            }
        }
        return nums[lt]==target?lt:nums[rt]==target?rt:-1;
    }
};
