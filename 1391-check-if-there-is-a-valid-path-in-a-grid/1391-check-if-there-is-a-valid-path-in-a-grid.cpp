class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        return dfs(grid, visited, 0, 0);
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c){
        if(r == grid.size() - 1 && c == grid[0].size() - 1){
            return true;
        }

        visited[r][c] = 1;

        bool ans = false;
        int nr = r;
        int nc = c;
        if(grid[r][c] == 1){
            nc++;
            if(nc < grid[0].size() && !visited[nr][nc]){
                if(grid[nr][nc] == 1 || grid[nr][nc] == 3 || grid[nr][nc] == 5){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
            nc -= 2;
            if(nc > - 1 && !visited[nr][nc]){
                if(grid[nr][nc] == 1 || grid[nr][nc] == 4 || grid[nr][nc] == 6){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
        }
        else if(grid[r][c] == 2){
            nr++;
            if(nr < grid.size() && !visited[nr][nc]){
                if(grid[nr][nc] == 2 || grid[nr][nc] == 6 || grid[nr][nc] == 5){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
            nr -= 2;
            if(nr > - 1 && !visited[nr][nc]){
                if(grid[nr][nc] == 2 || grid[nr][nc] == 4 || grid[nr][nc] == 3){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
        }
        else if(grid[r][c] == 3){
            nr++;
            if(nr < grid.size() && !visited[nr][nc]){
                if(grid[nr][nc] == 2 || grid[nr][nc] == 6 || grid[nr][nc] == 5){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
            nr--;
            nc--;
            if(nc > - 1 && !visited[nr][nc]){
                if(grid[nr][nc] == 1 || grid[nr][nc] == 4 || grid[nr][nc] == 6){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
        }
        else if(grid[r][c] == 4){
            nr++;
            if(nr < grid.size() && !visited[nr][nc]){
                if(grid[nr][nc] == 2 || grid[nr][nc] == 6 || grid[nr][nc] == 5){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
            nr--;
            nc++;
            if(nc < grid[0].size() && !visited[nr][nc]){
                if(grid[nr][nc] == 1 || grid[nr][nc] == 3 || grid[nr][nc] == 5){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
        }
        else if(grid[r][c] == 5){
            nc--;
            if(nc > - 1 && !visited[nr][nc]){
                if(grid[nr][nc] == 1 || grid[nr][nc] == 4 || grid[nr][nc] == 6){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
            nc++;
            nr--;
            if(nr > - 1 && !visited[nr][nc]){
                if(grid[nr][nc] == 2 || grid[nr][nc] == 4 || grid[nr][nc] == 3){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
        }
        else if(grid[r][c] == 6){
            nc++;
            if(nc < grid[0].size() && !visited[nr][nc]){
                if(grid[nr][nc] == 1 || grid[nr][nc] == 3 || grid[nr][nc] == 5){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
            nc--;
            nr--;
            if(nr > - 1 && !visited[nr][nc]){
                if(grid[nr][nc] == 2 || grid[nr][nc] == 4 || grid[nr][nc] == 3){
                    ans = dfs(grid, visited, nr, nc);
                    if(ans) return ans;
                }
            }
        }
        visited[r][c] = 0;
        return ans;
    }
};