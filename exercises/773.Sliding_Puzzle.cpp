#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const string target = "123450";
        
        string startState = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                startState += to_string(board[i][j]);
            }
        }
        
        if (startState == target) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({startState, 0});
        
        unordered_set<string> visited;
        visited.insert(startState);
        
        vector<vector<int>> neighbors = {
            {1, 3},     // vizinhos do idx 0
            {0, 2, 4},  // vizinhos do idx 1
            {1, 5},     // vizinhos do idx 2
            {0, 4},     // vizinhos do idx 3
            {1, 3, 5},  // vizinhos do idx 4
            {2, 4}      // vizinhos do idx 5
        };

        while (!q.empty()) {
            auto [currentState, moves] = q.front();
            q.pop();

            int zeroPos = currentState.find('0');

            for (int neighborPos : neighbors[zeroPos]) {
                string nextState = currentState;
                swap(nextState[zeroPos], nextState[neighborPos]);

                if (visited.find(nextState) == visited.end()) {
                    if (nextState == target) {
                        return moves + 1;
                    }
                    
                    q.push({nextState, moves + 1});
                    visited.insert(nextState);
                }
            }
        }
        
        return -1;
    }
};