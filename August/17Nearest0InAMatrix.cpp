// Problem Link : https://leetcode.com/problems/01-matrix/description/


struct Cell{
    int r,c,distance;
    
    void createCell(int a, int b, int d)
    {
        this->r = a;
        this->c = b;
        this->distance = d;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int rowCount = mat.size();
        int columnCount = mat[0].size();
        
        queue<Cell> q;
        vector<vector<int>> visited(rowCount, vector<int>(columnCount,0));
        
        vector<vector<int>> result;
        
        
        // push all the rows with zero into the queue
        
        for(int i=0; i<rowCount; i++)
        {
            for(int j=0; j<columnCount; j++)
            {
                if( mat[i][j] == 0)
                {
                    Cell c1;
                    c1.createCell(i,j,0);
                    q.push(c1);
                    visited[i][j]=1;
                  //  cout<<i<<" "<<j<<"\n";
                }
            }
        }
        
        while( q.empty() == false )
        {
            Cell current = q.front();
            q.pop();
            
          //  cout<<current.r<<" "<<current.c<<" \n";
            
            // process all the neighbors
            
            // starting with the top neighbor
            if( current.r - 1 >= 0 )
            {
                if(visited[current.r-1][current.c] == 0)
                {
                    Cell c1;
                    c1.createCell(current.r-1, current.c, current.distance + 1);
                    q.push(c1);
                    mat[current.r-1][current.c] = current.distance+1;
                    visited[current.r-1][current.c] = 1;
                    
                   // cout<<current.r-1<<" "<<current.c<<" "<<current.distance+1<<"\n";
                }
            }
            
            // now moving to left cell
            if( current.c - 1 >= 0)
            {
                if(visited[current.r][current.c-1] == 0)
                {
                    Cell c1;
                    c1.createCell(current.r, current.c-1, current.distance + 1);
                    q.push(c1);
                    mat[current.r][current.c-1] = current.distance+1;
                    visited[current.r][current.c-1] = 1;
                  //  cout<<current.r<<" "<<current.c-1<<" "<<current.distance+1<<"\n";

                }
                
            }
            
            // now moving to right cell
            if( current.c + 1 < columnCount )
            {
                if(visited[current.r][current.c+1] == 0)
                {
                    Cell c1;
                    c1.createCell(current.r, current.c+1, current.distance + 1);
                    q.push(c1);
                    mat[current.r][current.c+1] = current.distance+1;
                    visited[current.r][current.c+1] = 1;
                  //  cout<<current.r<<" "<<current.c+1<<" "<<current.distance+1<<"\n";

                }
                
            }
            
           // now moving to down cell
            if( current.r + 1 < rowCount )
            {
                if(visited[current.r+1][current.c] == 0)
                {
                    Cell c1;
                    c1.createCell(current.r+1, current.c, current.distance + 1);
                    q.push(c1);
                    mat[current.r+1][current.c] = current.distance+1;
                    visited[current.r+1][current.c] = 1;
                   // cout<<current.r+1<<" "<<current.c<<" "<<current.distance+1<<"\n";

                }
                
            }
        }
        
        return mat;
    }
};