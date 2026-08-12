class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        int R=nums1.length,C=nums2.length;
        int dp[][] = new int[R+1][C+1];
        int maxlen=0;
        for(int r=1;r<=R;r++){
            for(int c=1;c<=C;c++){
                if(nums1[r-1]==nums2[c-1]){
                    dp[r][c]=1+dp[r-1][c-1];
                    maxlen=Math.max(maxlen,dp[r][c]);
                }
            }
        }
        return maxlen;
    }
}
