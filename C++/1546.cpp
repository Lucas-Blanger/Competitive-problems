#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int n,k,feed;
    cin >> n;
    for(int i =0; i < n;i++){
        cin >> k;
        for(int j = 0; j < k;j++){
            cin >> feed;
            if(feed == 1){
                cout << "Rolien" << endl;
            } else if(feed == 2){
                cout << "Naej" << endl;
            } else if(feed == 3){
                cout << "Elehcim" << endl;
            } else if(feed == 4){
                cout << "Odranoel" << endl;
            }

        }
    }
}