g/*
    Name:  Shlomo Stept
    Date:  2/8/22 
    Project Name:  LeetCode Problem: Two Sum
    Description: Given an array ints and wanted sum, return indices of the two numbers that add up to target.
                    
*/

/* 
1. Understand the problem
    -> (i) Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
                You may assume that each input would have exactly one solution, and you may not use the same element twice.
                    - You can return the answer in any order.
            
    -> (ii)  examples  Input: nums = [2,7,11,15], target = 9
                       Output: [0,1]
                    
                       Input: nums = [3,2,4], target = 6
                       Output: [1,2]

                       Input: nums = [3,3], target = 6
                       Output: [0,1]


 2. Come up with possible Solutions
    -> (i)   (1)  for each number explore all options that come after it as combos: 0(n^2)
             (2)  There has to be a dynamic method: 
                maybe 1. add the elements in the array to a hashmap, and
                  then for each one see if there exists a value ST target - current = value. 
                  if so return
                  

 */


/*  Ugly Version */
vector<int> twoSum(vector<int>& nums, int target) {
        // sort array then do biary search once we find one value
        
    int size = nums.size();
    if( size == 2){
        vector<int> a ={0,1};
        return a;
    } else {
        vector<int> ans;
            
        // 1.add the elements in the array to a hashmap
        unordered_map< int, vector<int>> all;
        vector<int> temp;
        for(int i = 0 ; i< size; ++i){
            int num = nums[i];
            temp = all[num];
            temp.push_back(i);
            all[num] = temp;
        }
        
        
        int j;
        for (auto it = all.cbegin(); it != all.cend(); ++it) {
       
            j = (*it).first;
               if(all.find(target-j) != all.end()  && all.find(j) != all.end()){
                   
                    if( (target-j) == j && all[j].size() > 1){
                        ans.push_back(all[j][0]);
                        ans.push_back(all[j][1]);
                        break;
                    }else{
                        if((target-j) != j){
                            ans.push_back(all[j][0]);
                            ans.push_back(all[target-j][0]);
                            break;  
                        }
                    }  
               }
        }
        sort(ans.begin(), ans.end());
        return ans;
        }
    }  



    // A Cleaner version of this can be made by searching for each current values counterpart and if it isnt int the map yet adding the current number
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort array then do biary search once we find one value
        
    int size = nums.size();
    if( size == 2){
        vector<int> a ={0,1};
        return a;
    } else {
        vector<int> ans;
            
        // 1.add the elements in the array to a hashmap
        unordered_map< int, int> all;
        vector<int> temp;
        for(int i = 0 ; i< size; ++i){
            if( all.find(target-nums[i]) != all.end()){
                ans.push_back(all[target-nums[i]]);
                ans.push_back(i);
                break;
            }else{
                all[nums[i]] = i;
            }
        }
        
        return ans;
        }