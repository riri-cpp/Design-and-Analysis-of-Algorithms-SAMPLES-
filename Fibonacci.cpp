#include <iostream>
#include <vector>

using namespace std;

long long fibo(int n){

    vector<long long> fiboCall(n+1, 0);

    if(n >= 1){
        fiboCall[0] = 0;
    }
    if(n >= 2){
        fiboCall[1] = 1;
    }

    for(int i = 2; i <= n; i++){
        fiboCall[i] = fiboCall[i-1] + fiboCall[i-2];
    }

    long long result = fiboCall[n];
    return result;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    long long fiboNum = fibo(n);

    cout << n << "-th Fibonacci number is: " << fiboNum;

    return 0;
}