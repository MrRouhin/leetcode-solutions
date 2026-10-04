class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        
        for (int price : prices) {
            // Update the minimum price if a lower price is found
            if (price < min_price) {
                min_price = price;
            } 
            // Calculate profit if we sell today and update max_profit if it's higher
            else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }
        
        return max_profit;
    }
};