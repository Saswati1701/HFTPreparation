//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> ans = grid;
        queue<pair<pair<int, int>, int>> q;

        //fill the queue wherever there is 2, i.e., rotten oranges
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(ans[i][j]==2){
                    q.push({{i, j}, 0});
                }
            }
        }
        
        //for traversal in all 4 directions
        int delRow[] = {0, -1, 0, 1};
        int delCol[] = {-1, 0, 1, 0};
        int count = 0;
        int tm = 0;
        
         while(!q.empty()){
            int currRow = q.front().first.first;
            int currCol = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            //run bfs on each rotten orange
            for(int i=0; i<4; i++){
                int nrow = currRow + delRow[i];
                int ncol = currCol + delCol[i];
                if(nrow>=0 && nrow<M && ncol>=0 && ncol<N && grid[nrow][ncol]==1 && ans[nrow][ncol]!=2){
                    ans[nrow][ncol] = 2;

                    //push every rotten orange to the queue. This prevents the need to fill up the queue 
                    //with rotten oranges after the queue is empty
                    q.push({{nrow, ncol}, t+1});
                }
            }

            
        }
        //if all oranges could not be rottened then return -1
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == 1 && ans[i][j]!=2) return -1;
            }
        }
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends