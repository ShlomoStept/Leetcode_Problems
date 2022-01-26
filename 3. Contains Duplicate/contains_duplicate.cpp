/*
    Name:  Shlomo Stept
    Date:  1/25/22 
    Project Name:  LeetCode Problem: Contains Duplicate
    Description: Given an integer array nums, return true if any value appears at least twice in the array, 
                    and return false if every element is distinct.
*/

/* 
1. Understand the problem
    -> (i) We are given an array of integers [i1, i2, i3, i4, i5,.....] 
            and we need to determine if there are any duplicates, so we need to come up with a way of keeping track of what weve seen so far
            
    -> (ii)  examples  Input: nums = [1,2,3,1]
                       Output: true    
                    
                       Input: nums = [1,1,1,3,3,4,3,2,4,2]
                       Output: true

                       Input: nums = [1,2,3,4]
                       Output: false




 2. Come up with possible Solutions
    -> (i) My first thought is to keep a map around and when we see a value add it(as the key)/ increment its value
            then check if the value is >1 and if so return true, if the end of the vector is reached return true. 
        This is low runtime O(n), but high space cost O(n)

        Q. is there another way of doing this in a manner that higher runtime,  but less constly in space. 

    -> (ii) another solution is: First sort the array, second check if i = i+1, and return 1 if it does or zero it you reach the end
 */


// (i) Method uses a map to determine if a duplicate value is present in and array
bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> contains;
        for(int &num:nums){
            int x =(contains[num]++);
            print(x)
            if( contains[num] >1){
                return true;
            }
        }
        return false;
    }

// (ii) Sort first method was slower that the map method 
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i =1; i<size; ++i){
            if( nums[i]==nums[i-1]){
                return true;
            }
        }
        return false;
    }