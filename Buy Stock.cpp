// 121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//第一種 int minval=prices[0]; 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 如果是「區間內的東西」會影響答案（例如：區間內不能有重複、區間總和要多少）->雙指標。
        // 如果是「過去的某個紀錄」配合「現在」就能出答案
        // 例如：找最大差值、找最大和）>維護一個值(本題)
        int n=prices.size();
        if(n==0) return 0;

        int minval=prices[0]; // 存最低點
        int maxval=0; // 賺多少

        for(int x=1;x<n;x++){
            if(prices[x]<minval){
                minval=prices[x];
            }else if(prices[x]-minval>maxval){
                maxval=prices[x]-minval;
            }
        }
        return maxval;
    }
};

第二種:
int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX; // 想像成你的 slow，但它存的是「數值」
    int max_profit = 0;      // 你的 result

    for (int price : prices) { // price 就是你的 fast 正在看的那天
        // 1. 如果今天更便宜，更新最低買入點
        if (price < min_price) {
            min_price = price;
        } 
        // 2. 如果今天賣掉賺更多，更新利潤
        else if (price - min_price > max_profit) {
            max_profit = price - min_price;
        }
    }
    return max_profit;
}
