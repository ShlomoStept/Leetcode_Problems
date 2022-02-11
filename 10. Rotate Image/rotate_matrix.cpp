/*
    Name:  Shlomo Stept
    Date:  2/10/22 
    Project Name:  LeetCode Problem: Rotate Image
    Description: Rotate a N x N matrix to the right (by 90 degrees)                     
*/

/* 
1. Understand the problem
    -> (i) You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
            You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
                DO NOT allocate another 2D matrix and do the rotation.
    
    -> (ii)  examples:  Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
                        Output: [[7,4,1],[8,5,2],[9,6,3]]

                        Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
                        Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

                 

 2. Come up with possible Solutions
    -> (i)   (1)  Swap all the i j pairs with their j i siblings, 
                    (but this only works if i do j+i (th inner loop starts at one more each outter loop run))
                  Then reverse each row
                  
             (2)
                  

 */
void rotate(vector<vector<int>>& matrix) {

        int size = matrix.size();
        for( int i = 0 ; i < size; ++i){
            for (int j = 0 + i; j< size; ++j){
                swap(matrix[i][j], matrix[j][i]);          
            }
        }
        
        for(int i =0; i<size; ++i){
            int start =0;
            int last = size-1;
            while(start<last){
                swap(matrix[i][start++], matrix[i][last--]);
            }
        }
    }