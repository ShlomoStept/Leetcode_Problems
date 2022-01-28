/*
    Name:  Shlomo Stept
    Date:  1/27/22 
    Project Name:  LeetCode Problem: Intersection of Two Arrays
    Description: Find the only value that is only present once in an array.
                    
*/

/* 
1. Understand the problem
    -> (i) Given two integer arrays nums1 and nums2, return an array of their intersection.
                Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
            
    -> (ii)  examples  Input: nums1 = [1,2,2,1], nums2 = [2,2]
                       Output: [2,2]
                    
                       Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
                              Output: [4,9]
                              Explanation: [9,4] is also accepted.



 2. Come up with possible Solutions
    -> (i)  (1) sort the array 
            (2) Then name arr1 = the array with the smaller starting value
            (3) Then while that value is smaller than the first value in arr2 increment
            (4) if its not smaller then:
            (5)     if the values are equal add that value to the arr3 and increment both arrays
            (6)     else its larger in which case start incrementing arr2 untill its value is = or greater than arr2's current value
    
            ** NOTE: Make sure the while loops break once any of the arrays have gone to its end

            
    -> (ii) is there a way to do this without sorting the arrays first? 
 */

// Best runtime 0ms,  2nd best 6ms, 
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {   
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1=nums1.size(), p2=nums2.size();
        vector<int> nums3;
        int s1 =0, s2=0;
        while(s1<p1 && s2<p2){
            if(nums1[s1] < nums2[s2]){
                ++s1;
            }else if(nums1[s1] > nums2[s2]){
                ++s2;
            }else{
                nums3.push_back(nums1[s1]);
                ++s1;
                ++s2;
            }  
        }
        return nums3;   
    }