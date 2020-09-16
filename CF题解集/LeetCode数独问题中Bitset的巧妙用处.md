# LeetCode数独问题中Bitset的巧妙用处

## [36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)

判断一个 9x9 的数独是否有效。只需要**根据以下规则**，验证已经填入的数字是否有效即可。

1.  数字 `1-9` 在每一行只能出现一次。
2.  数字 `1-9` 在每一列只能出现一次。
3.  数字 `1-9` 在每一个以粗实线分隔的 `3x3` 宫内只能出现一次。

![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/250px-Sudoku-by-L2G-20050714.svg.png)

上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 `'.'` 表示。

**示例 1:**

```
输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
```

**示例 2:**

```
输入:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
```



### 题解：

用`bitset​`代表每一行每一列中对应的数字是否出现过

*   $rows [i]$ 代表第$i$行的状态，例如第$i$行出现了$5$，那么$row[i][5] = 1$
*   $cows[i]$ 代表第$i$列的转状态
*   $cells[i][j]$ 代表$i$行$j$列所在的块的状态

### solution:

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9> > rows = vector<bitset<9> > (9, bitset<9>());
        vector<bitset<9> > cols = vector<bitset<9> > (9, bitset<9>());
        vector<vector<bitset<9> > > cells = vector<vector<bitset<9> > > (3, vector<bitset<9> >(3, bitset<9>()));

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                int x = board[i][j]-'1';
                if(rows[i][x] || cols[j][x] || cells[i/3][j/3][x]) return false;
                rows[i][x] = 1;
                cols[j][x] = 1;
                cells[i/3][j/3][x] = 1;
            }
        }
        return true;
    }
};
```



## [37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/)

难度困难579

编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需**遵循如下规则**：

1.  数字 `1-9` 在每一行只能出现一次。
2.  数字 `1-9` 在每一列只能出现一次。
3.  数字 `1-9` 在每一个以粗实线分隔的 `3x3` 宫内只能出现一次。

空白格用 `'.'` 表示。

![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/250px-Sudoku-by-L2G-20050714.svg.png)

一个数独。

![](https://raw.githubusercontent.com/fanshixiong/Lesson/master/img/image-20200915141141235.png)

答案被标成红色。

### 题解：

*   `bitset​`作用同上。
*   每一个格子就可以计算出所有不能填的数字，然后得到所有能填的数字 `getPossibleStatus()​`
*   填入数字和回溯时，只需要更新存储信息
*   每个格子在使用时，会根据存储信息重新计算能填的数字
*   `getNext()` 选择**能填的数字**最少的格子开始填，这样填错的概率最小，回溯次数也会变少
*    `fillNum()` 在填入和回溯时负责更新存储信息

### Solution:

```cpp
class Solution {
public:
    vector<bitset<9> > rows, cols;
    vector<vector<bitset<9> > > cells;

    bitset<9> getPosibleStatus(int x, int y){
        return ~(rows[x] | cols[y] | cells[x/3][y/3]);
    }

    vector<int> getNext(vector<vector<char> > &board){
        
        vector<int> ans;
        int minCnt = 0x3f;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] != '.') continue;
                auto cur = getPosibleStatus(i, j);
                int c = cur.count();
                if(c < minCnt){
                    minCnt = c;
                    ans = {i, j};
                }
            }
        }

        return ans;
    }
    void fillNum(int x, int y, int n, bool flag){
        rows[x][n] = flag ? 1 : 0;
        cols[y][n] = flag ? 1 : 0;
        cells[x/3][y/3][n] = flag ? 1 : 0;
    }

    bool helper(vector<vector<char> > &board, int cnt){
        if(cnt == 0) return true;

        auto next = getNext(board);
        auto bits = getPosibleStatus(next[0], next[1]);

        for(int i=0; i<bits.size(); i++){
            if(!bits.test(i)) continue;
            int x = next[0], y = next[1];
            fillNum(x, y, i, true);
            board[x][y] = i+'1';
            if(helper(board, cnt-1)) return true;
            board[x][y] = '.';
            fillNum(x, y, i, false);
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9> > (9, bitset<9>());
        cols = vector<bitset<9> > (9, bitset<9>());
        cells = vector<vector<bitset<9> > > (3, vector<bitset<9> >(3, bitset<9>()));


        int cnt = 0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                cnt += (board[i][j] == '.');
                if(board[i][j] == '.') continue;
            
                int n=board[i][j] - '1';
                rows[i] |= (1<<n);
                cols[j] |= (1<<n);
                cells[i/3][j/3] |= (1<<n);
            }
        }

        helper(board, cnt);
    }
};
```

