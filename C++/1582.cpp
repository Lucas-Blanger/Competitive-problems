#include <bits/stdc++.h>


using namespace std;

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mdc3(int a, int b, int c) {
    return mdc(mdc(a, b), c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x, y, z;
    
    while(cin >> x >> y >> z){
        int nums[3] = {x, y, z};
        sort(nums, nums + 3);
        
        int a = nums[0];
        int b = nums[1];
        int c = nums[2]; 
        
        long long a2 = (long long)a * a;
        long long b2 = (long long)b * b;
        long long c2 = (long long)c * c;
        
        if(a2 + b2 == c2){
            int g = mdc3(a, b, c);
            
            if(g == 1){
                cout << "tripla pitagorica primitiva" << endl;
            } else {
                cout << "tripla pitagorica" << endl;
            }
        } else {
            cout << "tripla" << endl;
        }
    }
    

}