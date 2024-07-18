#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// class Solution {
// public:
//     int slidingPuzzle(vector<vector<int>>& board) {
//         vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
//         queue<vector<vector<int>>> q; 
//         q.push(board);
//         int step = 0;
//         while(!q.empty()){
//             int size = board.size();
//             for (int i = 0; i < size; ++i){
//                 vector<vector<int>> cur = q.front();
//                 q.pop();
//                 if (cur == target){
//                     return step;
//                 }
//                 if (cur == visited){
//                     continue;
//                 }
//                 int left = leftnums(cur);
//                 int right = rightnums(cur);
//                 int updown = updownnums(cur);

//                 q.push(left);
//                 q.push(right);
//                 q.push(updown);
//             }
//             step++;
//         }
//     }
// };


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";
        unordered_set<string> visited;
        for (int i = 0; i < board.size(); ++i){
            for (int s : board[i]){
                start += to_string(s);
            }
        };
        // record 
        vector<vector<int>> neighbour = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };
        queue<string> q;
        q.push(start);
        int step = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; ++i){
                string cur = q.front();
                q.pop();
                if (cur == target){
                    return step;
                }
                // find the number that it's value = 0;
                int idx = cur.find('0');
                for (int i : neighbour[idx]){
                    swap(cur[idx], cur[i]);
                    if (!visited.count(cur)){
                        q.push(cur);
                        visited.insert(cur);
                    }
                    swap(cur[idx], cur[i]);
                }
            }
            step++;
        }
        return -1;
    }

};

int main(){
    Solution so;
    vector<vector<int>> board = {{1,2,3},{4,0,5}};
    int res = so.slidingPuzzle(board);
    cout << res << endl;
}