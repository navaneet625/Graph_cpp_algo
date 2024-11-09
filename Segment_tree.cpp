#include <bits/stdc++.h>
using namespace std;

// Range sum function
int sum(int tree[], int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (tl == l && tr == r) {
        return tree[v];
    }
    int mid = (tl + tr) / 2;
    return sum(tree, v * 2, tl, mid, l, min(r, mid)) +
           sum(tree, v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
}

// Point update function
void update_point(int tree[], int v, int tl, int tr, int idx, int val) {
    if (tl == tr) {
        tree[v] = val;
    } else {
        int mid = (tl + tr) / 2;
        if (idx <= mid) {
            update_point(tree, v * 2, tl, mid, idx, val);
        } else {
            update_point(tree, v * 2 + 1, mid + 1, tr, idx, val);
        }
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

// Range update function (without lazy propagation)
void update_range(int tree[], int v, int tl, int tr, int l, int r, int val) {
    if (l > r) {
        return;
    }
    if (tl == tr) { // Leaf node
        tree[v] += val;
    } else {
        int mid = (tl + tr) / 2;
        update_range(tree, v * 2, tl, mid, l, min(r, mid), val);
        update_range(tree, v * 2 + 1, mid + 1, tr, max(l, mid + 1), r, val);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

// Build tree function
void buildTree(int tree[], int arr[], int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int mid = (tl + tr) / 2;
        buildTree(tree, arr, v * 2, tl, mid);
        buildTree(tree, arr, v * 2 + 1, mid + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tree[4 * n];

    // Build the segment tree
    buildTree(tree, arr, 1, 0, n - 1);

    // Example range update
    int l, r, addend;
    cout << "Enter range (l, r) to update and addend: ";
    cin >> l >> r >>  val;
    update_range(tree, 1, 0, n - 1, l, r, val);

    // Example range sum query
    cout << "Enter range (l, r) to get sum: ";
    cin >> l >> r;
    cout << "Range sum: " << sum(tree, 1, 0, n - 1, l, r) << endl;

    return 0;
}