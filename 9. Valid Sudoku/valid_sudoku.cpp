/*
    Name:  Shlomo Stept
    Date:  2/8/22 
    Project Name:  LeetCode Problem: Valid Sudoku
    Description: Determine if a 9 x 9 Sudoku board is valid.
                    
*/

/* 
1. Understand the problem
    -> (i) Determine if a 9 x 9 Sudoku board is valid. 
            - Only the filled cells need to be validated according to the following rules:
                1. Each row must contain the digits 1-9 without repetition.
                2. Each column must contain the digits 1-9 without repetition.
                3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    
    -> (ii)  examples  Input: 
                            [["5","3",".",".","7",".",".",".","."]
                            ,["6",".",".","1","9","5",".",".","."]
                            ,[".","9","8",".",".",".",".","6","."]
                            ,["8",".",".",".","6",".",".",".","3"]
                            ,["4",".",".","8",".","3",".",".","1"]
                            ,["7",".",".",".","2",".",".",".","6"]
                            ,[".","6",".",".",".",".","2","8","."]
                            ,[".",".",".","4","1","9",".",".","5"]
                            ,[".",".",".",".","8",".",".","7","9"]]
                        Output: true
                            n m
                        [   00 01 02   03 04 05   06 07 08       ]
                        [   10 11 12   13 14 15   16 17 18       ]
                        [   20 21 22   23 24 25   26 27 28       ]
                        ------------------------------------------
                        [   30 31 32   33 34 35   36 37 38       ]
                        [   40 41 42   43 44 45   46 47 48       ]
                        [   50 51 52   53 54 55   56 57 58       ]
                        ------------------------------------------
                        [   60 61 62   63 64 65   66 67 68       ]
                        [   70 71 72   73 74 75   76 77 78       ]
                        [   80 81 82   83 84 85   86 87 88       ]

 2. Come up with possible Solutions
    -> (i)   (1)  test each of the three conditions, if one is false return false
             (2)  There has to be a dynamic method:
                  

 */

/* 507 / 507 test cases passed.
Status: Accepted
Runtime: 16 ms
Memory Usage: 18.6 MB */

/* UGLY Mess --> there has to be a cleaner more succinct way of doing this !! */

bool valid_rows(vector<vector<char>>& board, unordered_map<char, int>& set){
        int next;
        for(int m = 0; m < 9; ++m){
            int test[10] = {0};
            for(int n = 0; n < 9; ++n){
                next = set[board[n][m]];
                ++test[next];
                if(test[next] > 1 && next != 0){
                    return false;
                }
            }
        }
        return true;
    }
    bool valid_cols(vector<vector<char>>& board, unordered_map<char, int>& set){
        int next;
        for(int n = 0; n < 9; ++n){
            int test[10] = {0};
            for(int m = 0; m < 9; ++m){
                next = set[board[n][m]];
                ++test[next];
                if(test[next] > 1 && next != 0){
                    return false;
                }
            }
        }
        return true;
    }
    bool valid_squares(vector<vector<char>>& board, unordered_map<char, int>& set){
        int next;
        for(int i =0 ; i< 9; i= i+3 ){
            for (int j =0; j < 9; j =j+3){
                int test[10] = {0};
                for(int n = 0; n < 3; ++n){
                     for(int m = 0; m < 3; ++m){
                        next = set[board[n+i][m+j]];
                        ++test[next];
                        if(test[next] > 1 && next != 0){
                            return false;
                        }
                    } 
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> set({ {'1',1}, {'2',2},{'3',3}, {'4',4}, {'5',5},{'6',6},{'7',7}, {'8',8},{'9',9},{'.', 0}  } );
        if(valid_rows(board, set)){
            if( valid_cols(board, set) ){
                if(valid_squares(board, set)){
                    return true;
                }
            }
        }
        return false;
    }
