/*************************************************************************
	> File Name: prim.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 20 Jan 2022 03:21:59 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct node{
    int e, v;
    bool operator<(const node &b) const {
        return this->v > b.v;
    } 
};
struct edge {
    int e, v, next;
};
edge edg[200005];
int cnt, edg_cnt, ans,  n, m, head[100005], mark[100005];

void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }

    priority_queue<node> que;
    que.push((node){(n / 4 == 0 ? 1:n / 4), 0});
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (mark[temp.e] == 1) {
            continue;
        }

        mark[temp.e] = 1;
        ans += temp.v;
        cnt++;
        if (cnt == n) {
            cout << ans << endl;
            return 0;
        }
        for (int i = head[temp.e]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (mark[e] == 0) {
                que.push((node){e, v});
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
