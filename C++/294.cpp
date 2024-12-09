#include <iostream>
#include <math.h>

using namespace std;

int main(){

  int casos;

  scanf("%d",&casos);

  while(casos--){

    int l, u;

    double aux, cont;

    int num=0, numd=0;

    cin>>l>>u;

    for(int i=l;i<=u;i++){

      aux=pow(i,0.5);
      cont=0;

      for(int j=1;j<=aux;j++){

        if(i%j==0){
          cont++;
          if(j<aux) cont++;
        }
        
      }
      if(cont>numd){
        numd=(int)cont;
        num=i;
      }
    }
    cout<<"Between "<<l<<" and "<<u<<", "<<num<<" has a maximum of "<<numd<<" divisors."<<endl;
  }
 return 0;
}