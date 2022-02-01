/*
    Name:  Shlomo Stept
    Date:  1/31/22 
    Project Name:  LeetCode Problem: Plus One
    Description: add 1 to the integer thats being represented as a integer array
                    
*/

/* 
1. Understand the problem
    -> (i) Given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
            The digits are ordered from most significant to least significant in left-to-right order. 
            The large integer does not contain any leading 0's.

            - Increment the large integer by one and return the resulting array of digits.
            
    -> (ii)  examples  Input: digits = [1,2,3]
                       Output: [1,2,4]
                    
                       Input: digits = [9]
                              Output: [1,0]



 2. Come up with possible Solutions
    -> (i) : There seem to be 3 core cases
                (i) Easy: the easy case is if the array is empty, simply add one --> not sure if this is a valid case
                (ii) Easy: the last digit is not a nine, simple add one to it
                (ii) hard: while the last digit is = 9,  (a) make it zero, move to the next element and repeat.
                    --> at the end of this process, if the final element is a 9, make it a zero and add a 1 to the beggining of the array
                                                    if the final element is not a 9, simply add one to it. 
 */

vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if (size<1){
            digits.push_back(1);
        }else{
            int correct_spot=size-1;
            while( correct_spot > -1 && digits[correct_spot] == 9){
                digits[correct_spot] = 0;
                correct_spot--;
            }
            if(correct_spot<0){
                digits.emplace(digits.begin()+0,1);
            }else{
                digits[correct_spot]++;
            }
        }
        return digits;
    }
