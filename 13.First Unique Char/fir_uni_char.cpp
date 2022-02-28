/*
    Name:  Shlomo Stept
    Date:  2/25/22 
    Project Name:  LeetCode Problem: Find first unique charachter
    Description: Find the first intance of a unique charachter and return that index                  
*/

/* 
1. Understand the problem
    -> (i) Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
    
    -> (ii)  examples:  Input: s = "leetcode"
                                    Output: 0

                        Input: s = "loveleetcode"
                        Output: 2

                 

 2. Come up with possible Solutions
    -> (i)   (1)  first go throught the string given, and increment a array of size 26 with the corresonding location to each char (i.e char - 'a', so that 'a' - 'a' = 0)
                     then go throught the given string again, and for each char, if its loaction on the array has a 1, thats the index you return, 
                        if you get to the end of this second loop return -1 
             (2)
                  

 */
int firstUniqChar(string s) {
        int arr[26]= {0};
        int size = s.length();
        if(size>0){
            
            for(int i =0; i< size; ++i){
                arr[int(s[i]-'a')]++;
            }
            
            for(int i =0; i< size; ++i){
                int location = int(s[i] - 'a');
                if(arr[location] == 1){
                    return i;
                }
            }
        }
        return -1;    
    }