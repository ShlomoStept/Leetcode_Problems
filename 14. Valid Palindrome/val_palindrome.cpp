/*
    Name:  Shlomo Stept
    Date:  3/21/22 
    Project Name:  LeetCode Problem: Determine if a string is a valid  Palindrome
    Description: Given a string s, return true if it is a palindrome, or false otherwise.                 
*/

/* 
1. Understand the problem
    -> (i) A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
            Given a string s, return true if it is a palindrome, or false otherwise.   
    
    -> (ii)  examples:  Input: s = "A man, a plan, a canal: Panama"
                        Output: true


                        Input: s = "race a car"
                        Output: false

                        Input: s = " "
                        Output: true

                 

 2. Come up with possible Solutions
    -> (i)   (1)  first go throught the string given, and save only the alphanumeric charachters to a new string, (also convert any chars to lowercase)
             (2)  then point to the start and end of the array, and check if they match, --> if they dont return false
              
                    - once you get to the point where start is not < end, return true
                  

 */
 

 //  1. ----------------------------MESSY IMPLIMENTATION
 string grab_alphabetic(string s){
    string new_s ="";
    int size = s.length();
    for(int i =0; i < size; ++i ){
        if(isalnum(s[i])){
            if(isalpha(s[i]))
                new_s.push_back(tolower(s[i]));
            else
                new_s.push_back(s[i]); 
        }
    }
    return new_s;
    }


bool isPalindrome(string s) {

    s = grab_alphabetic(s);

    if(s.length() ==0){  return true; } 
    else{
        int start =0, length = s.length()  , end=length-1;
        while(start<end){
            if(s[end] != s[start]){
                return false;
            }else{
                ++start;
                --end;
            }
        }
    }
    return true;
}


// 2  ---------------------------- SIMPLER IMPLIMENTATION

bool isPalindrome(string s) {
        if(s.length() ==0){  return true; } 
        else{
            int start = 0, length = s.length()  , end=length-1;
    
            while(start<end){
                if(!isalnum(s[start])){
                    ++start;
                    continue;
                }
                if(!isalnum(s[end])){
                    --end;
                    continue;
                }
                if(tolower(s[end]) != tolower(s[start])){
                    return false;
                }
                ++start;            
                --end;            
            }
        }
        return true;
    }
