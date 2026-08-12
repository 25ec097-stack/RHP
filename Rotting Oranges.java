class Solution {
    public int orangesRotting(int[][] g) {
        int R=g.length,C=g[0].length;
        Queue<int[]> q = new LinkedList<>();
        int oranges=0;
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(g[row][col]==2){
                    q.add(new int[]{row,col});
                }
                if(g[row][col]!=0){
                    oranges++;
                }
            }
        } 
        if(oranges==0) return 0;
        int days=-1;
        int diff[]={0,-1,0,1,0};
        while(!q.isEmpty()){
            days++;
            int qsize=q.size();
            while(qsize-- >0){
                oranges--;
                int cell[] = q.poll();
                int row = cell[0],col=cell[1];
                for(int i=0;i<4;i++){
                    int ar=row+diff[i];
                    int ac=col+diff[i+1];
                    if(ar>=0 && ar<R && ac>=0 && ac<C && g[ar][ac]==1){
                        q.add(new int[]{ar,ac});
                        g[ar][ac]=2;
                    }
                }
            }
        }       
        return oranges>0?-1:days;
    }
}
