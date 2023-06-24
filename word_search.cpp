bool search(vector<vector<char>>& board, string word , int i, int j, int index ,int m ,int n)
    {
        if(index == word.size()) return true;
        
        int condition = (i<0 || j<0 || i>n-1 || j>m-1);
        if(condition || word[index] != board[i][j] || board[i][j] == '0')
        return false;
        
        char copy = board[i][j];
        board[i][j] = '0';
        bool b1 = search(board, word,i+1,j,index+1,m,n);
        bool b2 = search(board , word, i-1,j,index+1,m,n);
        bool b3 = search(board, word, i , j+1,index+1,m,n);
        bool b4 = search(board,word,i,j-1,index+1,m,n);
        
        board[i][j]= copy;
      return b1+b2+b3+b4; 
    }
    bool isWordExist(vector<vector<char>>& board, string word) 
    {
        set<vector<int>> st;
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0 ; i<n ; i++ )
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(search(board,word,i,j,0,m,n)) return true;
                }
            }
        }
        return false;
    }
