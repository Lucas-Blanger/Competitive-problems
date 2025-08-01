#include <iostream>
#include <string>

using namespace std;

string pre, in;

string build_post(int pre_start, int in_start, int n) {
    if (n == 0) return "";
    char root = pre[pre_start];
    int root_idx = in.find(root, in_start);

    int left_len = root_idx - in_start;
    int right_len = n - 1 - left_len;

    string left_post = build_post(pre_start + 1, in_start, left_len);
    string right_post = build_post(pre_start + 1 + left_len, root_idx + 1, right_len);
    
    return left_post + right_post + root;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        int N;
        cin >> N >> pre >> in;
        cout << build_post(0, 0, N) << endl;
    }
    return 0;
}
