    #include <iostream>
     
    using namespace std;
     
    int main(){
        int t, d,m;
        cin >> t >> d >> m;
     
        bool descansou = false;
        int ref[m];
        for(int i = 0; i < m; i++){
            cin >> ref[i];
        }
     
        int dif = 0;
        if(ref[0] >= t){
            descansou = true;
        }
        if(d - ref[m-1] >= t){
            descansou = true;
        }
        for(int i = 1; i < m; i++){
            dif = ref[i] - ref[i-1];
            if(dif >= t){
                descansou = true;
                break;
            }
            
        }
        
     
        if(descansou){
            cout << "Y" << endl;
        }else {
            cout << "N" << endl;
        }
    }