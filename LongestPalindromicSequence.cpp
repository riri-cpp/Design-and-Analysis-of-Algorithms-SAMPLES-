#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestPalindromicSubsequence(string s) {
    int n = s.length();
    
    // Create a 2D DP table
    // dp[i][j] represents the length of longest palindromic subsequence in s[i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Every single character is a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Fill the DP table
    // We need to consider all substrings of length 2 or more
    for (int len = 2; len <= n; len++) {  // len is the length of substring
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;  // ending index of substring
            
            if (s[i] == s[j]) {
                // If first and last characters match
                if (len == 2) {
                    dp[i][j] = 2;  // Two matching characters
                } else {
                    dp[i][j] = dp[i + 1][j - 1] + 2;  // Add 2 and recurse for inner substring
                }
            } else {
                // If first and last characters don't match
                // Take maximum of either excluding first or excluding last character
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // The answer is dp[0][n-1] (longest palindromic subsequence in entire string)
    return dp[0][n - 1];
}

int main() {
    string s;
    
    cout << "Enter the string: ";
    cin >> s;
    
    int result = longestPalindromicSubsequence(s);
    
    cout << "Length of longest palindromic subsequence: " << result << endl;
    
    return 0;
}
