#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int tree[4 * MAXN];   // Segment tree array
int lazy[4 * MAXN];   // Lazy propagation array

// Range sum function with lazy propagation
int sum(int v, int tl, int tr, int l, int r) {
    // Apply pending updates if any
    if (lazy[v] != 0) {
        tree[v] += (tr - tl + 1) * lazy[v];
        if (tl != tr) {  // If not a leaf node, propagate lazily
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    
    if (l > r) {
        return 0;
    }
    if (tl == l && tr == r) {
        return tree[v];
    }
    int mid = (tl + tr) / 2;
    return sum(v * 2, tl, mid, l, min(r, mid)) +
           sum(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
}

// Point update function
void update_point(int v, int tl, int tr, int idx, int val) {
    if (tl == tr) {
        tree[v] = val;
    } else {
        int mid = (tl + tr) / 2;
        if (idx <= mid) {
            update_point(v * 2, tl, mid, idx, val);
        } else {
            update_point(v * 2 + 1, mid + 1, tr, idx, val);
        }
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

// Range update function with lazy propagation
void update_range(int v, int tl, int tr, int l, int r, int val) {
    // Apply pending updates if any
    if (lazy[v] != 0) {
        tree[v] += (tr - tl + 1) * lazy[v];
        if (tl != tr) {  // If not a leaf node, propagate lazily
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }

    if (l > r) {
        return;
    }
    if (tl == l && tr == r) {
        tree[v] += (tr - tl + 1) * val;
        if (tl != tr) {  // If not a leaf node, propagate lazily
            lazy[v * 2] += val;
            lazy[v * 2 + 1] += val;
        }
    } else {
        int mid = (tl + tr) / 2;
        update_range(v * 2, tl, mid, l, min(r, mid), val);
        update_range(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r, val);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

// Build tree function
void buildTree(int arr[], int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int mid = (tl + tr) / 2;
        buildTree(arr, v * 2, tl, mid);
        buildTree(arr, v * 2 + 1, mid + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int main() {
    int n, m, a, b, wt;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build the segment tree
    buildTree(arr, 1, 0, n - 1);

    // ange update
    int l, r, val;
    cout << "Enter range (l, r) to update and val: ";
    cin >> l >> r >> val;
    update_range(1, 0, n - 1, l, r, val);

    // Example range sum query
    cout << "Enter range (l, r) to get sum: ";
    cin >> l >> r;
    cout << "Range sum: " << sum(1, 0, n - 1, l, r) << endl;

    return 0;
}