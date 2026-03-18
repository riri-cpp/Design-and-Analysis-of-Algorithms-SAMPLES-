#include <iostream>
#include <vector>
using namespace std;

void fibonacciDP(int n) {

    vector<long long> dp(n);

    // Base cases
    if (n >= 1) {
        dp[0] = 0;
    }
    if (n >= 2) {
        dp[1] = 1;
    }

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Fibonacci Sequence (first " << n << " terms): ";
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the number of Fibonacci terms to display: ";
    cin >> n;

    fibonacciDP(n);

    return 0;
}
