

/* Problem # 1: Best Time to Buy and Sell Stock II and Best Time to Buy and Sell Stock I -> on bottom
   Author: Shlomo Stept
   Date: 1/17/22
*/   


/*
 1. Understand the problem
    -> (i) We are given an array of integers [i1, i2, i3, i4, i5,.....]
    -> (ii) Each ith index represents the price of the stock on this day. So i2 = price of stock on second day
    -> (iii) We are trying to return the MAX Profit that we can obtain by buying and selling this stock
                The KEY Condition is that we can only hold one share of this stock on a single day.
                    Meaning if we hold the stock from i1->i3, once we sold it on i3 we can buy it again on say i4 
                        (p.s. We can buy and sell a stock on the say day, and vice versa)  


 2. Come up with possible Solutions
    -> (i) There is always the brute force method 
            We can try all combos and then determine of they combos overlap
    
    -> (ii) There is ussually a dynamic programming approach, and this is the one that we want but currently i cant think of what it might be    

                // Essentially increment the counter and if the previos day price was less than the current day price execute the trade
                // By trading each day once (or not trading that day), you end up realizing all the gains you would have from simply holding it, and waiting                 

*/


// 1.0 --> Best Time to Buy and Sell Stock II
int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int max_profit = 0, profit;
        for(int i = 1; i < size; ++i){
            //profit = prices[i] - prices[i-1];
            if( prices[i] > prices[i-1])  { 
                max_profit += prices[i] - prices[i-1]; 
            }
        }
        return max_profit;
    }



// 2.0 --> Best Time to Buy and Sell Stock I : 
// Similiar probelm but, "You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock."
     int maxProfit(vector<int>& prices) {
        int size = prices.size()-1, max_prof = 0, min_ = INT_MAX, curr ;
        // Setting the size orriginally to correct size, and using a curr variable that increments the location, seems to work faster for some reason
        for( int i = -1; i < size;){
            curr = prices[++i];
            min_ = min(min_, curr);
            max_prof = max(max_prof, curr-min_);
        }
        return max_prof;
    }