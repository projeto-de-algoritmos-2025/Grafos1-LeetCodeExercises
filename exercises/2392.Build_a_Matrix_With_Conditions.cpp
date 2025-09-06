#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> topologicalSort(int k, const vector<vector<int>>& conditions) {
        vector<vector<int>> adj(k + 1);
        vector<int> inDegree(k + 1, 0);

        for (const auto& cond : conditions) {
            int u = cond[0];
            int v = cond[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);

            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (order.size() == k) {
            return order;
        } else {
            return {}; 
        }
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {}; 
        }

        unordered_map<int, int> rowPosition;
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
        }

        unordered_map<int, int> colPosition;
        for (int i = 0; i < k; ++i) {
            colPosition[colOrder[i]] = i;
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            int row = rowPosition[i];
            int col = colPosition[i];
            matrix[row][col] = i;
        }

        return matrix;
    }
};