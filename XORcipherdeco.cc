#include<iostream>
#include<sstream>
#include<string>
#include<stdio.h>
#include<vector>
#include<bitset>

using namespace std;

//8-bit ascii converter
//Max key 255


string binary;

int to_decimal(int n)
{
    int factor = 1;
    int total = 0;
    while (n != 0)
    {
        total += (n%10) * factor;
        n /= 10;
        factor *= 2;
    }
    return total;
}

void char_tobinary(int chare){
  if(chare != 0){
    char_tobinary(chare/2);
    int aux = chare%2;
    char c = aux + '0';
    binary.push_back(c);
  }
}


int main(){
  cout<<"XORcipher decodifiactor"<<endl;
  cout<<"Enter the key:"<<endl;
  string ini;
  string value;
  int key;
  cin>>key;
  cout<<"Insert the text here, when you are finish just type **** in another line and press enter :) "<<endl;
  bitset<8> bin_key(key);
  string fkey = bin_key.to_string<char,string::traits_type,string::allocator_type>();
  getline(cin,ini);
  bool first = true;
  while(ini != "****"){
    bool primer = true;
    istringstream iss(ini);
    string word;
      while(iss >> word){
        if(!primer) value.push_back(' ');
        else primer = false;

        for(int j = 0; j < word.size(); ++j){

          for(int i = 0; i < 8; ++i){
              binary.push_back(word[j]);
              ++j;
            }
            --j;
            string auxiliar;
          for(int z = 0; z < 8; ++z){
              char aux = ((binary[z]-'0') ^ (fkey[z]-'0')) + '0';
              auxiliar.push_back(aux);
          }
          int decimal = stoi(auxiliar);
          decimal = to_decimal(decimal);
          char c = static_cast<char>(decimal);
          value.push_back(c);
          auxiliar.clear();
          binary.clear();
        }

      }

    getline(cin,ini);
    if( ini != "****" and !first){
      value = value + "\n";
    }
    else first = false;
  }
  cout<<"Here is your plaintext in XORcipher with key-> "<<key<<" :"<<endl;
  cout<<value<<endl;
}
