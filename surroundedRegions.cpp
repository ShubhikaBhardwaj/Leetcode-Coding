class Solution {
public:

    void dfs(int x,int y,vector<vector<char>>& board, int find,int change)
    {
        board[x][y]=change;

        vector<vector<int>> dir={(0,1),(0,-1),(1,0),(0,1)};

        for(int i=0;i<4;i++)
        {
            int rx=x+dir[0];
            int ry=y+dir[1];

            if(board[x][y]==find)
              { //board[x][y]=change;
                 dfs(rx,ry,board,find,change);
              }
        }

    }


    void solve(vector<vector<char>>& board) {
      int N=board.size();
      for(int i=0;i<N;i++)
         {  if(board[i][j]=='0')
             dfs(0,i,board,'0','@');
         }
      
      for(int i=0;i<N;i++)
         {   if(board[i][j]=='0')
             dfs(i,0,board,'0','@');
         }
      
      for(int i=0;i<N;i++)
         {   if(board[i][j]=='0')
             dfs(N-1,i,board,'0','@');
         }
      
      for(int i=0;i<N;i++)
         {   if(board[i][j]=='0')
             dfs(i,N-1,board,'0','@');
         }
        
       for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
         {   if(board[i][j]=='0')
             dfs(i,j,board,'0','X');
         } 

       for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
         {   if(board[i][j]=='@')
             dfs(i,j,board,'@','0');
         }  

    }
};