class Solution {
    private int find(int ldr[] , int node){
        if(ldr[node] != node){
            ldr[node] = find(ldr,ldr[node]);
        }
        return ldr[node];
    }
    private void join(int ldr[] , int lt , int rt){
        ldr[find(ldr,rt)] = find(ldr,lt);
    }
    public int latestDayToCross(int R, int C, int[][] cells) {
        int days = 0;
        boolean water[] = new boolean[R*C+2];
        int d[][] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        int ldr[] = new int[R*C+2];
        for(int node=0;node < R*C+2 ;node++){
            ldr[node]=node;
        }
        for(int cell[] : cells){
            int row = cell[0], col = cell[1];
            row--;
            col--;
            water[row*C+col+1] = true;
            for(int i=0;i<8;i++){
                int ar=row+d[i][0] , ac=col+d[i][1];
                if(ar>=0 && ar<R && ac>=0 && ac<C && water[ar*C+ac+1]){
                    join(ldr,row*C+col+1,ar*C+ac+1);
                }
            }
            if(col==0){
                join(ldr,0,row*C+col+1);
            }
            if(col==C-1){
                join(ldr,row*C+col+1,R*C+1);
            }
            if(find(ldr,0)==find(ldr,R*C+1)){
                return days;
            }
            days++;
        } 
        return days;
    }
}
