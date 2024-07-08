#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
    int step,mod;
    while(cin >> step){
           cin >> mod;
           int arr[100000+5]={};
           arr[0] =1;
           int seed = 0;
           while(arr[0]<=1){
               ++arr[(seed+step)%mod];
               seed = (seed+step)%mod;
           }
           bool goodChoice = true;
           for(int i=0;mod>i;++i){
               if(arr[i]<1){
                   goodChoice = false;
                   break;
                   }
               }
           cout << setw(10) << step << setw(10) << mod << "    ";
           if(goodChoice){
              cout << "Good Choice" << endl << endl;
           }else{
              cout << "Bad Choice" << endl << endl;
           }
    }
}
