#include <iostream>
using namespace std;

long long countWays(int n) {
    if(n <= 0) {
        return 0;
    }
    
    if(n == 1) {
        return 1;
    }
    
    if(n == 2) {
        return 2;
    }
    
    long long* dp = new long long[n+1];
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    long long result = dp[n];
    delete[] dp;
    return result;
}

int main(){
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    
    long long ways = countWays(n);
    cout << "Number of distinct ways: " << ways << endl;
    
    return 0;
}