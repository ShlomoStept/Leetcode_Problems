/*
    Name:  Shlomo Stept
    Date:  1/25/22 
    Project Name:  LeetCode Problem: Single Number
    Description: Find the only value that is only present once in an array.
                    
*/

/* 
1. Understand the problem
    -> (i) Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
                    -You must implement a solution with a linear runtime complexity and use only constant extra space.
            
    -> (ii)  examples  Input: nums = [2,2,1]
                       Output: 1
                    
                       Input: nums = [4,1,2,1,2]
                       Output: 4



 2. Come up with possible Solutions
    -> (i) You can use the ^ bitwise XOR operator on the array at the end, the only value remaining is the value thats present only once.
    
    -> (ii) A more costly method in terms of runtime would be to 
 */


// (i) Method uses the ^ bitwise XOR operator, to eliminate double entries of numbers, and leaves the ony single number
int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        
        int single = 0;    
        while(n){
            single ^= nums.at(--n);
        }
        
        return single;
    }