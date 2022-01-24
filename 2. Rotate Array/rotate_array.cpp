/*
    Name:  Shlomo Stept
    Date:  1/19/22 
    Project Name:  LeetCode Problem: Rotate Array
    Description: Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

/* 
1. Understand the problem
    -> (i) We are given an array of integers [i1, i2, i3, i4, i5,.....] 
            and we need to rotate -- move the array to the right -->  by some number of digits

                         0  1  2  3  4  5  6  7
    -> (ii)  examples  [ 1, 2, 3, 4, 5, 6, 7, 8]  Rotated by 3 is:
                       [ 6, 7, 8, 1, 2, 3, 4, 5]





 2. Come up with possible Solutions
    -> (i) One easy solution is to copy the second part of the array (k+1) into a new array starting from the k+1 th position 
                and then place the 0-k th index in after them
    
    -> (ii) another solution is to do a series of swaps 
 */



void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(k>0 && size>1){
            k = k%size;
            vector<int> nums_2;
            for( int i =-1; i<k-1; ){
                nums_2.push_back( nums[size-k+(++i)]);
            }
        
            for(int i =-1; i<size-k-1;){
                nums_2.push_back(nums[++i]);   
            }
            nums = nums_2;   
        }  
    }



