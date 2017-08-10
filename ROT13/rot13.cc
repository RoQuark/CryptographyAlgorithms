#include<iostream>
#include<string>
using namespace std;



int main(){
  cout<<"ROT13 maker"<<endl;
  cout<<"Insert the text here, when you are finish just type **** in another line and press enter :) "<<endl;
  string ini;
  string fini;
  getline(cin,ini);
  while(ini != "****"){
  for(int i = 0; i < ini.size(); ++i){
    char a;
    a = ini[i];
    int ascii = (int)a;
    if(ascii < 123 and ascii > 96){
      if((ascii + 13) >= 123){
        int exe = 123 - ascii;
        exe = 13 - exe;
        ascii  = 97 + exe;
      }
      else ascii += 13;
    }
    else if(ascii < 91 and ascii > 64){
      if((ascii + 13) >= 91){
        int exe = 91 - ascii;
        exe = 13 - exe;
        ascii  = 65 + exe;
      }
      else ascii += 13;
    }

    char b = ascii;
    fini.push_back(b);
    }
    getline(cin,ini);
    if( ini != "****"){
      fini = fini + "\n";
    }
  }
  cout<<"Here is your plaintext transformed to ROT13:"<<endl;
  cout<<fini<<endl;

}
