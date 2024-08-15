// USING SIEVE OF ERATOSTHENES
//TIME COMPLEXITY O{n * log(log n)}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n == 0) return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        int ans = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;
                int j = 2 * i;
                while (j < n) {
                    prime[j] = false;
                    j = j + i;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 10;
    cout << "Number of prime numbers less than " << n << ": " << sol.countPrimes(n) << endl;
    return 0;
}
