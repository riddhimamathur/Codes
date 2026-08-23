#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }

        return profit;
    }
};

int main() {
    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution obj;

    cout << "Maximum Profit: " << obj.maxProfit(prices);

    return 0;
}