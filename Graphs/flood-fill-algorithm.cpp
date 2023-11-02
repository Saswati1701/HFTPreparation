void dfs(vector<vector<int>>& ans, vector<vector<int>>& image, int sr, int sc, int newColor, int orgColor, int delrow[], int delcol[]){
        ans[sr][sc] = newColor;
        int M = ans.size();
        int N = ans[0].size();
        for(int i=0; i<4; i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            //nrow ans ncol stay inside the matrix
            //if the the color in new position(nrow, ncol) is equal to starting position(sr, sc)
            //if the color in the new matrix hasn't already changed then run dfs for the (nrow, ncol)
            if(nrow>=0 && nrow<M && ncol>=0 && ncol<N && image[nrow][ncol]==orgColor && ans[nrow][ncol]!=newColor){
                dfs(ans, image, nrow, ncol, newColor, orgColor, delrow, delcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        //ALways use a copy of original matrix. Don't tamper with given data
        vector<vector<int>> ans = image;
        int orgColor = ans[sr][sc];

        //the four directions traversed as nodes of the graph
        int delrow[] = {0, -1, 0, 1};
        int delcol[] = {-1, 0, 1, 0};
        
        dfs(ans, image, sr, sc, newColor, orgColor, delrow, delcol);
        return ans;
    }
    