class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0];
        int profit = 0;
        for(int i = 1; i<prices.size(); i++){
            // i is sell price
            // track if current sell is max
            // if the current price is less that the buy price, set buy to this
            profit = max(profit, (prices[i]-buy_price));
            if(prices[i]<buy_price){
                buy_price=prices[i];
            }  
        }
        return profit;
    }
};
