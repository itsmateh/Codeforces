#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin>>n; 
  int v[n];
  int par=0,posPar=0,impar=0,posImp=0;
 
  for(int i=0; i<n; i++){
    cin>>v[i];
    if(v[i] %2 == 0){
      par++;
      posPar=i+1;
    }
    else{
      impar++;
      posImp=i+1;
    }
  }
 
  int encontrado;
  if(impar == 1){
    encontrado=posImp;
  }else{
    encontrado=posPar;
  }
 
  cout<<encontrado<<endl;
 
}