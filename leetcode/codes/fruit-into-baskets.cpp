//
// Created by riddle on 10/11/20.
//
#include <cstdio>

int getTreeValue(int *tree, int index) {
    if (index == -1) {
        return -1;
    }

    return tree[index];
}

int totalFruit(int *tree, int treeSize) {
    if (treeSize <= 2) {
        return treeSize;
    }
    int result = 0;
    int left = -1;
    int mid = 0;
    int right = 0;
    while (right < treeSize) {
        if (getTreeValue(tree, right) == getTreeValue(tree, mid)) {
            if(right - left + 1 > result) {
                result = right - left + 1;
            }
        } else if (getTreeValue(tree, right) == getTreeValue(tree, left)) {
            if(right - left + 1 > result) {
                result = right - left + 1;
            }
            mid = right;
        } else {
            left = mid;
            mid = right;
            if(right - left + 1 > result) {
                result = right - left + 1;
            }
        }
        right++;
    }

    return result;
}

// 初始化 left = -1 mid = 0 right = 0
// 指针指到2时left = -1 mid = 0 right = 2
// 指针指到3时tree[3] != tree[-1] && tree[3] != tree[0]，则left = 0 mid = 3 right = 3
// 指针指到4时 tree[4] != tree[0] && tree[4] ！= tree[3]，则left = 3 mid = 4 right = 4
// 指针指到7时 left = 3 mid = 7 right = 7
// 指针指到8时 tree[8] != tree[3] && tree[8] != tree[4]，则left = 7 mid = 8 right = 8
// 指针指到9时 left = 7 mid = 8 right = 9
// 指针指到10时 tree[10] != ... ，则left = 8 mid = 10 right = 10

int main() {
    int tree[] = {
            3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4
    };
    printf("%d", totalFruit(tree, 11));

    return 0;
}