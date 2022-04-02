class Solution {
public:
  bool dfs(int i, int j, int sindex, vector<vector<char>> &board, string &word, vector<int> &dx, vector<int> &dy) {
    if (sindex == word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[sindex]) return false;

    char ch = board[i][j];
    board[i][j] = '$';

    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];

      bool valid = dfs(x, y, sindex + 1, board, word, dx, dy);
      if (valid) {
        board[i][j] = ch;
        return true;
      }
    }

    board[i][j] = ch;
    return false;

  }

  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (board[i][j] == word[0])
          if (dfs(i, j, 0, board, word, dx, dy)) return true;

    return false;

  }
};