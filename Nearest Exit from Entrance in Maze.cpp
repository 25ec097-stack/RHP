class Solution {
public:
    const int d[5] = {0,-1,0,1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int R = maze.size() , C = maze[0].size();
        queue<pair<int,int>> q;
        q.push(make_pair(e[0],e[1]));
        maze[e[0]][e[1]] = '+';
        int steps = -1;
        while(!q.empty()){
            steps++;
            int qsize = q.size();
            while(qsize--){
                auto[row,col] = q.front();q.pop();
                if(row==0||row==R-1||col==0||col==C-1){
                    if(!(row==e[0] && col==e[1])){
                        return steps;
                    }
                }
                for(int i=0;i<4;i++){
                    int ar = row+d[i] , ac = col+d[i+1];
                    if(ar>=0 && ar<R && ac>=0 && ac<C && maze[ar][ac]=='.'){
                        q.push(make_pair(ar,ac));
                        maze[ar][ac] = '+';
                    }
                }
            }
        }
        return -1;
    }
};
