#include <bits/stdc++.h>


using namespace std;

int  main(){
    double n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    double media;
    media = (n1 *2 + n2 * 3 + n3 * 4 + n4 * 1 ) / (2 +3 +4 +1);
    cout << fixed << setprecision(1);

    cout << "Media: " << media << endl;
    if(media >= 7.0){
        cout << "Aluno aprovado." << endl;
    } else if(media < 5.0){
        cout << "Aluno reprovado." << endl;
    } else if(media >= 5.0 && media < 7.0){
        cout << "Aluno em exame." << endl;
        double ex;
        cin >> ex;
        cout << "Nota do exame: " << ex<< endl;
        double newMedia = (media + ex) / 2;
        if(newMedia >= 5.0){
            cout << "Aluno aprovado." << endl;
            cout << "Media final: " << newMedia << endl;
        } else {
            cout << "Aluno reprovado." << endl;
            cout << "Media final: " << newMedia << endl;
        }

    }
    
}