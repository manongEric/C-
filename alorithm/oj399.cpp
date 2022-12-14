/*************************************************************************
	> File Name: oj399.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 12 Mar 2022 01:23:21 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x, y, step;
};
char mmap[505][505];
int n, m, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node> que;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '2') {
                mmap[i][j] = '#';
                sx = i, sy = j;
            }
        }
    }
    que.push((node){sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '3'){
                cout << temp.step + 1 << endl;;
                return 0;
            }
            if (mmap[x][y] == '.') {
                mmap[x][y] = '#';
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
