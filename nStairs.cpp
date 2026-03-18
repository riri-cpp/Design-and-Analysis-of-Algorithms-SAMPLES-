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
    
    long long* stairs = new long long[n+1];
    stairs[1] = 1;
    stairs[2] = 2;
    
    for(int i = 3; i <= n; i++) {
        stairs[i] = stairs[i-1] + stairs[i-2];
    }
    
    long long result = stairs[n];
    delete[] stairs;
    return result;
}

int main(){
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    
    long long totalWays = countWays(n);
    cout << "Number of distinct ways: " << totalWays << endl;
    
    return 0;
}