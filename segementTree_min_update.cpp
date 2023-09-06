
#include <bits/stdc++.h>
using namespace std;

class sgTree{
    vector<int> seg;
public:
    sgTree(int n) {
        seg.resize( 4 * n + 1);
    }
    void segmentTree(int ind, int low, int high, vector<int> &inp) {
        if(low == high) {
            seg[ind] = inp[low];
            return;
        }
        int mid = (low + high) / 2;
        segmentTree(2 * ind + 1, low, mid, inp);
        segmentTree(2 * ind + 2, mid + 1, high, inp);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind +2]);
        }
    int query(int ind, int low, int high, int l, int r) {
        if(r < low || high < l) {
            return INT_MAX;
        }

        if(low >= l && high <= r) return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }    
};


void test_case() {
    int n;
    cin >> n;
    vector<int> inp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inp.push_back(x);
    }
    sgTree sg(n);
    sg.segmentTree(0, 0, n - 1, inp);
    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            cout << sg.query(0, 0, n - 1, l, r) << endl;            
        } else {
            int i, val;
            cin >> i >> val;
            inp[i] = val;
            sg.update(0, 0, n - 1, i, val);
        }
    }
}

int main(){  
    test_case();
    return 0;
}

