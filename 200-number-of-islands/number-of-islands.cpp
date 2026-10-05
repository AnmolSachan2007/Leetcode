// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int dr[] = {1, -1, 0, 0};
//         int dc[] = {0, 0, 1, -1};
//         int ans = 0;
//         queue<pair<int, int>> q;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == '1') {
//                     q.push({i, j});
//                     grid[i][j] = '0';
//                     ans++;
//                     while (!q.empty()) {
//                         auto [r, c] = q.front();
//                         q.pop();
//                         for (int k = 0; k < 4; k++) {
//                             int nr = r + dr[k];
//                             int nc = c + dc[k];
//                             if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
//                                 grid[nr][nc] == '1') {
//                                 grid[nr][nc] = '0';
//                                 q.push({nr, nc});
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// DFS
class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Track whether a cell has already been visited
        vector<vector<bool>> isVisited(
            m,
            vector<bool>(n, false)
        );

        int count = 0;

        // Traverse every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If we find unvisited land,
                // we have discovered a new island.
                if (!isVisited[i][j] && grid[i][j] == '1') {

                    count++;

                    // Visit the complete island
                    dfs(grid, isVisited, i, j);
                }
            }
        }

        return count;
    }

    void dfs(
        vector<vector<char>>& grid,
        vector<vector<bool>>& isVisited,
        int i,
        int j
    ) {

        // Check boundaries
        if (
            i < 0 ||
            i >= grid.size() ||
            j < 0 ||
            j >= grid[0].size()
        ) {
            return;
        }

        // Already visited
        if (isVisited[i][j]) {
            return;
        }

        // Water cannot be part of an island
        if (grid[i][j] != '1') {
            return;
        }

        // Mark current land cell as visited
        isVisited[i][j] = true;

        // Visit all four directions

        // Up
        dfs(grid, isVisited, i - 1, j);

        // Down
        dfs(grid, isVisited, i + 1, j);

        // Left
        dfs(grid, isVisited, i, j - 1);

        // Right
        dfs(grid, isVisited, i, j + 1);
    }
};