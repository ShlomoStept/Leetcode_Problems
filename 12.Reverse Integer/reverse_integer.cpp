/*
    Name:  Shlomo Stept
    Date:  2/23/22 
    Project Name:  LeetCode Problem: Reverse String
    Description: Reverse a string (which is in the form of  a char array)                  
*/

/* 
1. Understand the problem
    -> (i) Given a signed 32-bit integer x, return x with its digits reversed. 
            -- If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], 
            then return 0.
            -- Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
    
    -> (ii)  examples:  Input: x = 123
                        Output: 321

                        Input: x = -123
                        Output: -321

                 

 2. Come up with possible Solutions
    -> (i)   (1)  How do we figure out what is going to cause an over flow
                a- 32 bit integer = standard unsigned integers in c++
                b- so we have acess to the max integer using the macro INT_MAX
                c- so how do we get pull one integer off the end ?? 
                  
             (2)
                  

 */
// I needed help with this one, because of the overflow issues
int reverse(int x) {
        int rev = 0;
        while (x != 0){
            int pop = x % 10;
            x  = x/10;
            if (rev > INT_MAX/10 || (rev ==  INT_MAX/10 && pop > 7 ) )
                return 0;
            
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8) ) 
                return 0;
            
            rev = rev * 10 + pop;
        }
        
       return rev;
    }