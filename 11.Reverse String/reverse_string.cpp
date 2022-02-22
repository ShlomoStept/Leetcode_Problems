/*
    Name:  Shlomo Stept
    Date:  2/21/22 
    Project Name:  LeetCode Problem: Reverse String
    Description: Reverse a string (which is in the form of  a char array)                  
*/

/* 
1. Understand the problem
    -> (i) Write a function that reverses a string. The input string is given as an array of characters s.
                --- You must do this by modifying the input array in-place with O(1) extra memory.
    
    -> (ii)  examples:  Input: s = ["h","e","l","l","o"]
                        Output: ["o","l","l","e","h"]   

                        Input: s = ["H","a","n","n","a","h"]
                        Output: ["h","a","n","n","a","H"]

                 

 2. Come up with possible Solutions
    -> (i)   (1)  pointer to front and back, 
                    i - swap the two, 
                    ii - incriiment and decrement the pointers respectivly 
                    ii - stop when the pointers pass each other (start_p > end_p) 
                  
             (2)
                  

 */
 void reverseString(vector<char>& s) {
        int size = s.size() -1;
        if(size>0){
            int i = 0;
            for(int i =0; i<size; ++i){
                swap(s[i],s[size]);
                --size;
            }
        } 
    }