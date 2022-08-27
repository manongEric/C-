/*************************************************************************
	> File Name: quickFind.c
	> Author: 
	> Mail: 
	> Created Time: Tue 03 May 2022 08:48:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet{
    int *data;
    int size;
}UnionSet;

UnionSet *initUnionSet(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->data = (int *)malloc(sizeof(int) * (n + 1));
    u->size = n + 1;

    for (int i = 0; i < u->size; i++) {
        u->data[i] = i;
    }
    return u;
}

void freeUnionSet(UnionSet *u) {
    if (!u)
        return;

    free(u->data);
    free(u);
}
//O(1)
int find(UnionSet *u, int idx) {
    return u->data[idx];
}
//O(n)
int merge(UnionSet *u, int a, int b) {
    if (u->data[a] == u->data[b])
        return 0;
    
    int acolor = u->data[a];
    for (int i = 0; i < u->size; i++) {
        if (find(u, i) == acolor)
            u->data[i] = u->data[b];
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = initUnionSet(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch(a) {
            case 1:
                merge(u, b, c);
                break;
            case 2:
                printf("%s\n", find(u, c) == find(u, b) ? "Yes" : "No");
                break;
        }
    }
    freeUnionSet(u);

    return 0;
}
