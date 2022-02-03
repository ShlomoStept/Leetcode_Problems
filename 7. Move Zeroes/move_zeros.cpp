/*
    Name:  Shlomo Stept
    Date:  2/1/22 
    Project Name:  LeetCode Problem: Move Zeroes
    Description: move all 0's to the end of given array, while  maintaining the relative order of the non-zero elements.
                    
*/

/* 
1. Understand the problem
    -> (i) Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
            - Note that you must do this in-place without making a copy of the array.
            
    -> (ii)  examples  Input: nums = [0,1,0,3,12]
                       Output: [1,3,12,0,0]
                    
                       Input: nums = [0]
                        Output: [0]



 2. Come up with possible Solutions
    -> (i)   (1)  go through the entire array (man n times and) bubble up each zero. = O(n^n)
             (2)  go through the array and  keep trck of the block size of zeros
                    -> if you encounter a zero note the block size, 
                        and swap current zero value with the value one past the block size;
                    -> if you dont encounter a zero increment counter 
 */

/* METHOD 1: Terrible! */
 void bubble_up(vector<int>& nums, int start, int end){
        for(int i = start; i<end ; ++i){
            nums[i]=nums[i+1];
        }
        nums[end] =0;
    }
    
    void moveZeroes(vector<int>& nums) {
        // 1. find the first zero
        // 2. move it to the end- number of zeros already found
        // 3. stop when you do a pass and there are no zeros found
        int size = nums.size();
        if (size>1){
            int min = 0, count =0;
            while( min < (size-count) ){
                if( nums[min] == 0 ){
                    ++count;
                    bubble_up(nums, min, size-count);
                    --min;
                }
            ++min;
            }    
        }
    }
//--------------------------------------------
/*  Method 2: beat ~94% of all other solutions in runtime and  */
void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if(size>1){
            int block = 0, p =0;
            while(p+block < size){
                if(nums[p] == 0){
                    while( p+block < size && nums[p+block]==0 ){
                       ++block; 
                    }
                    if(p+block<size)
                        swap(nums[p], nums[p+block]);
                }else{
                    ++p;
                }
            }
        }
    }





