class Solution{
public:
    void make1(vector<vector<int>>& chess, int i, int j )
    {
        for(int column = j+1 ; column<chess.size() ; column++)
        {
            chess[i][column] = 1;
        }
        
        int up = i;
        int down = i;
        int right = j;
        
        while(right<chess.size() && (up>=0 || down<chess.size()))
        {
            if(up>=0) chess[up][right] = 1;
            if(down<chess.size()) chess[down][right] = 1;
            up--;
            down++;
            right++;
        }
    }
    
    
    void combinations(vector<vector<int>>& ans , vector<int> &per_sub , vector<vector<int>>& chess, int column)
    {
        if(column >= chess.size())
        {
            ans.push_back(per_sub);
            return;
        }
        
        for(int i=0; i<chess.size() ; i++)
        {
            if(chess[i][column] == 0)
            {
                per_sub.push_back(i+1);
                vector<vector<int>> copy(chess);
                make1(chess,i,column);
                combinations(ans , per_sub , chess , column+1);
                chess = copy;
                per_sub.pop_back();
            }
        }
        
        
    }
    
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> chess(n,vector<int>(n,0));
        vector<vector<int>> ans;
        vector<int> per_sub;
        
        combinations(ans,per_sub,chess,0);
        return ans;
    }
};
