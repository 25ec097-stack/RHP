class Solution {
public:
    int minDistance(string word1, string word2) {
        int R = word1.length();
        int C = word2.length();
        vector<vector<int>> dp(R+1,vector<int>(C+1,0));
        for(int row=1;row<=R;row++){
            for(int col=1;col<=C;col++){
                if(word1[row-1]==word2[col-1]){
                    dp[row][col]=1+dp[row-1][col-1];
                }
                else{
                    dp[row][col]=max(dp[row][col-1],dp[row-1][col]);
                }
            }
        }
        return ((R-dp[R][C])+(C-dp[R][C]));
    }
};
