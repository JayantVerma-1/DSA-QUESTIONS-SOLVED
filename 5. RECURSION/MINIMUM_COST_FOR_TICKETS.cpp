#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int mincostTicketsHelper(vector<int> &days, vector<int> &costs, int i)
    {
        // BASE CASE
        if (i >= days.size())
            return 0;

        // 1 DAY PASS TAKEN
        int cost1 = costs[0] + mincostTicketsHelper(days, costs, i + 1);

        // 7 DAY PASS TAKEN
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost7 = costs[1] + mincostTicketsHelper(days, costs, j);

        // 30 DAY PASS TAKEN
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }

        int cost30 = costs[2] + mincostTicketsHelper(days, costs, j);
        return min(cost1, min(cost7, cost30));
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return mincostTicketsHelper(days, costs, 0);
    }
};

int main()
{
    // Example usage
    Solution sol;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout << "Minimum cost: " << sol.mincostTickets(days, costs) << endl;
    return 0;
}
