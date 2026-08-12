class Solution {
public:
    const int diff[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
    int dfs(vector<vector<int>>&matrix, vector<vector<int>>&dp,int R,int C,int row,int col){
        //Base condition or Gauge or Exit Condition
        if(dp[row][col]!=0){
            return dp[row][col];
        }
        int adjMax=0;
        for(int i=0;i<4;i++){
            int ar=row+diff[i][0],ac=col+diff[i][1];
            if(ar>=0 && ar<R && ac>=0 && ac<C && matrix[ar][ac]>matrix[row][col]){
                adjMax=max(adjMax,dfs(matrix,dp,R,C,ar,ac));
            }
        }
        dp[row][col]=1+adjMax;
        return 1+adjMax;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int R=matrix.size(), C=matrix[0].size();
        vector<vector<int>> dp(R,vector<int>(C,0));
        int maxlen=1;
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(dp[row][col]==0){
                    maxlen=max(maxlen,dfs(matrix,dp,R,C,row,col));
                    maxlen=max(maxlen,dp[row][col]);
                }
            }
        }
        return maxlen;
    }
}
