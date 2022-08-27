/*************************************************************************
	> File Name: heap_re.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Apr 2022 08:06:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b;b = __temp;\
};
typedef struct Heap{
    int *data;
    int size, len;
}Heap;

Heap *initHeap(int n) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (int *)malloc(sizeof(int) * n);
    h->size = n;
    h->len = 0;
    return h;
}

void freeHeap(Heap *h) {
    if (!h)
        return;
    free(h->data);
    free(h);
    return;
} 

int push(Heap *h, int val) {
    if (!h)
        return 0;

    if (h->len == h->size) 
        return 0;

    h->data[h->len] = val;
    int idx = h->len;
    while (idx > 0 && h->data[idx] > h->data[(idx - 1) / 2]) {
        swap(h->data[idx], h->data[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
    h->len++;
    return 1;
}

int isEmpty(Heap *h) {
    return !h || h->len == 0;
}

void downAdj(int *arr, int idx, int len) {
    while (idx * 2 + 1 < len) {
        int temp = idx, l = idx * 2 + 1, r = idx * 2 + 2;
        if (arr[l] > arr[temp]) {
            temp = l;
        }
        if (r < len && arr[r] > arr[temp]) {
            temp = r;
        }
        if (temp == idx) {
            break;
        }

        swap(arr[temp],arr[idx]);

        idx = temp;
    }
}

int pop(Heap *h) {
    int res = h->data[0];
    h->data[0] = h->data[h->len - 1];
    h->len--;


    downAdj(h->data, 0, h->len);
    return res;
}

void showHeap(Heap *h) {
    if (!h)
        return;

    printf("Heap :[");
    for (int i = 0; i < h->len; i++) {
        i && printf(", ");
        printf("%d", h->data[i]);
    }
    printf("]\n");
}
int main() {
    srand(time(0));
    int cnt = 10;
    Heap *h = initHeap(10);
    while (cnt--) {
        int val = rand() % 100;
        push(h, val);
    }
    showHeap(h);

    printf("pop[");
    while(!isEmpty(h)) {
        printf("%d ", pop(h));
    }
    printf("]\n");

    freeHeap(h);
    return 0;
}
