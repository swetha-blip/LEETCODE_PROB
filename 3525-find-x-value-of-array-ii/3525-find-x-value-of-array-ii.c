#define MAXK 5

typedef struct {
    int prod;
    int cnt[MAXK];
} Node;

Node tree[400005];
int K;

Node merge(Node a, Node b) {
    Node res;

    res.prod = (a.prod * b.prod) % K;

    for (int i = 0; i < K; i++)
        res.cnt[i] = a.cnt[i];

    // Prefix = complete left + prefix of right
    for (int r = 0; r < K; r++) {
        if (b.cnt[r] == 0)
            continue;

        int newRem = (a.prod * r) % K;
        res.cnt[newRem] += b.cnt[r];
    }

    return res;
}

void build(int node, int l, int r, int* nums) {
    if (l == r) {
        int rem = nums[l] % K;

        tree[node].prod = rem;

        for (int i = 0; i < K; i++)
            tree[node].cnt[i] = 0;

        tree[node].cnt[rem] = 1;
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid, nums);
    build(node * 2 + 1, mid + 1, r, nums);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int l, int r, int pos, int value) {
    if (l == r) {
        int rem = value % K;

        tree[node].prod = rem;

        for (int i = 0; i < K; i++)
            tree[node].cnt[i] = 0;

        tree[node].cnt[rem] = 1;
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(node * 2, l, mid, pos, value);
    else
        update(node * 2 + 1, mid + 1, r, pos, value);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int l, int r, int ql, int qr) {
    // Completely inside range
    if (ql <= l && r <= qr)
        return tree[node];

    int mid = (l + r) / 2;

    if (qr <= mid)
        return query(node * 2, l, mid, ql, qr);

    if (ql > mid)
        return query(node * 2 + 1, mid + 1, r, ql, qr);

    Node left = query(node * 2, l, mid, ql, qr);
    Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

    return merge(left, right);
}

int* resultArray(
    int* nums,
    int numsSize,
    int k,
    int** queries,
    int queriesSize,
    int* queriesColSize,
    int* returnSize
) {
    K = k;

    build(1, 0, numsSize - 1, nums);

    int* result = malloc(queriesSize * sizeof(int));

    for (int i = 0; i < queriesSize; i++) {

        int index = queries[i][0];
        int value = queries[i][1];
        int start = queries[i][2];
        int x = queries[i][3];

        // Update nums[index]
        update(1, 0, numsSize - 1, index, value);

        // Query nums[start ... numsSize-1]
        Node res = query(
            1, 0, numsSize - 1,
            start, numsSize - 1
        );

        result[i] = res.cnt[x];
    }

    *returnSize = queriesSize;

    return result;
}