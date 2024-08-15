#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void maxProfitFinder(std::vector<int>& prices, int i, int &minPrice, int &maxProfit){
    // BASE CASE
    if(i == prices.size()) 
        return;

    // SOLVE ONE CASE
    if(prices[i] < minPrice) 
        minPrice = prices[i];
    int todaysProfit = prices[i] - minPrice;

    if(todaysProfit > maxProfit)
        maxProfit = todaysProfit;

    // BAAKI RECURSION SAMBHAL LEGA
    maxProfitFinder(prices, i+1, minPrice, maxProfit);
}

int maxProfit(std::vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int main() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Call the maxProfit function
    int result = maxProfit(prices);

    // Output the result
    std::cout << "Maximum profit: " << result << std::endl;

    return 0;
}
