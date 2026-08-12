class Solution {
    public int maxRotateFunction(int[] nums) {
        int N=nums.length,sum=0;
        long fval=0,ans=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
            fval+=(i*nums[i]);
        }
        ans=fval;
        for(int li=N-1;li>0;li--){
            fval=fval-(nums[li]*(N-1))+(sum-nums[li]);
            ans=Math.max(ans,fval);
        }
        return (int)ans;
    }
}
