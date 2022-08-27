/*************************************************************************
	> File Name: oj43.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Feb 2022 08:04:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[1005][1005], dp[1005][1005];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
            if (i == n) {
                dp[i][j] = num[i][j]; 
            }
        }
    }

    for(int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = num[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    cout << dp[1][1] << endl;
    return 0;
}
