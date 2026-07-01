#include <bits/stdc++.h>
#define MAXN (int)(2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MOD (int)(1e9 + 7)
const int N = 1e6;     
long long fat[N+1];
long long invfat[N+1];

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

   int espaco = n;
    int inside = n+1;


    for(int i = 0; i < espaco; i++) cout << (char)32;
    for(int i = 0; i < inside; i++) cout << (char)95;
    cout << endl;
    espaco--;
    for(int j = 0; j < n;j++){
        for(int i = 0; i < espaco; i++) cout << (char)32;
        cout << (char)47;
        if(j == n-1){
            for(int i = 0; i < n;i++) cout << (char)95;
            for(int i = 0; i < 2*n-1;i++) cout << (char)32;
            cout << (char)92;
            for(int i = 0; i < n+1;i++) cout << (char)95;
        }else{
            for(int i = 0; i < inside; i++) cout << (char)32;
            cout << (char)92;
        }
        espaco--;
        inside+=2;
        cout << endl;
    }
    espaco = n+1;
    inside-=2;

    for(int j = 0; j < n;j++){
        for(int i = 0; i < espaco; i++) cout << (char)32;
        cout << (char)92;
        if(j == n-1){
            for(int i = 0; i < inside; i++) cout << (char)95;
        }else{
            for(int i = 0; i < inside; i++) cout << (char)32;
        }
    
        cout << (char)47;
        espaco++;
        inside-=2;
        cout << endl;
    }

   
    
 
}
