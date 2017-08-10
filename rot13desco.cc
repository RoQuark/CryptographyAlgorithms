#include<iostream>
#include<string>
using namespace std;

//To compile in any terminal: g++ -o decodifiactor decodificator.cc

int main(){
  cout<<"ROT13 decodification"<<endl;
  cout<<"Insert your chiper text(ROT13) here, when you are finish just type **** in another line and press enter :) "<<endl;
  string ini;
  string fini;
  getline(cin,ini);
  while(ini != "****"){
  for(int i = 0; i < ini.size(); ++i){
    char a;
    a = ini[i];
    int ascii = (int)a;
    if(ascii < 123 and ascii > 96){
      if((ascii - 13) <= 96){
        int exe =  ascii - 96;
        exe = 13 - exe;
        ascii  = 122 - exe;
      }
      else ascii -= 13;
    }
    else if(ascii < 91 and ascii > 64){
      if((ascii - 13) <= 64){
        int exe =  ascii - 64;
        exe = 13 - exe;
        ascii  = 90 - exe;
      }
      else ascii -= 13;
    }

    char b = ascii;
    fini.push_back(b);
    }
    getline(cin,ini);
    if( ini != "****"){
      fini = fini + "\n";
    }
  }
  cout<<"Here is your plaintext transformed from ROT13:"<<endl;
  cout<<fini<<endl;

}
