/*************************************************************************
	> File Name: oj508.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Mar 2022 02:53:55 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int n, num[1005], ans;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    for (int i = n - 1; 1; i-=2) {
        if (i == 0) {
            ans += num[0];
            break;
        }else if (i == 1) {
            ans += num[1];
            break;
        }else if (i == 2) {
            ans += num[1] + num[0] + num[2];
        }else {
            ans += min(num[1] + num[0] + num[i] + num[1], num[i] + num[0] + num[i - 1] + num[0]);
        }
    } 
    cout << ans << endl;

    return 0;
}

