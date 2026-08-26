#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    queue<int> f0;
    queue<int> f1;
    int dir = -1; 

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(b == 0) f0.push(a);
        else f1.push(a);
    }

    int r = 0;

    while(!f0.empty() || !f1.empty()){
        if (dir == -1) {
            if (f0.empty()) dir = 1;
            else if (f1.empty()) dir = 0;
            else dir = (f0.front() < f1.front()) ? 0 : 1;
            
            if (dir == 0) r = f0.front();
            else r = f1.front();
        }

        if (dir == 0) {
            r = r + 10; 
            
            while(!f0.empty() && f0.front() <= r){
                r = max(r, f0.front() + 10);
                f0.pop();
            }
            
            if(!f1.empty() && f1.front() <= r) dir = 1; 
            else dir = -1; 
            
        } else { 
            r = r + 10;
            
            while(!f1.empty() && f1.front() <= r){
                r = max(r, f1.front() + 10);
                f1.pop();
            }
            
            if(!f0.empty() && f0.front() <= r) dir = 0;
            else dir = -1;
        }
    }

    cout << r << endl;

}