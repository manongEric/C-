/*************************************************************************
	> File Name: oj519_2re.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Apr 2022 04:27:12 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
long long a, b;
int cnt;
int main() {
    cin >> a >> b;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j) continue;
            for (int k = 3; k <= 17; k++) {
                for (int l = 1; l <= k; l++) {
                    if (i == 0 && l == 1) continue;
                    if (j == 0 && l != 1) break;
                    long long t = 0;
                    for (int m = 1; m <= k; m++) {
                        if (m == l) {
                            t = t * 10 + i;
                        } else {
                            t = t * 10 + j;
                        }
                    }
                    if (t >= a && t <= b) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}
