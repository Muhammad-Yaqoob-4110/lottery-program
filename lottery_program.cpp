#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;
int generator();
const int CONST = 5;
int arr[CONST];
bool isNotRepeater(int result);
int sortInAssending(int s);
void header();
string menuf();
void clearScreen();
main(){
     header();
     string menu;
     while(true){
          menu = menuf();
          if(menu =="1"){
             //start lottery
             clearScreen();
             for(int i=0; i<CONST; i++){   
             arr[i] = generator();
          }
            int smallidx;
            int temp;
            for(int i=0; i<CONST; i++){
            smallidx = sortInAssending(i);
            temp = arr[i];
            arr[i] = arr[smallidx];
            arr[smallidx] = temp;      
          }
            for(int i=0; i<CONST; i++){
            cout<<"2021-CS-" << arr[i] << endl;      
          }
          clearScreen();
          }
          else if(menu == "2"){
             //exit 
             break;      
          }
          else{
              cout <<"Wrong Entry\n";
              clearScreen();      
          }      
     }     
      
}
int generator(){
    int result;      
    srand(time(0));
    bool flag = true;
    while(flag){
    result = 1+ (rand() % 165);
    if(result >= 110){
    flag = isNotRepeater(result);
    }
    }
    return result;     
}
bool isNotRepeater(int result){
      int count = 0;    
      for(int i=0; i<CONST; i++){
         if(result != arr[i]){
           count++;
         }       
      }
      if(count == CONST){
         return false;       
      }
      else{
          return true;      
      }    
}
int sortInAssending(int s){
    int idx;
    int small = 1000;
    for(int i=s; i<CONST; i++){
        if(arr[i] < small){
            small = arr[i];
            idx = i;       
        }      
    }
    return idx;      
}
void header(){
     system("cls");     
     cout <<"=========================================================\n\n";

     cout <<"            WELCOME TO \"LUCKY DRAW\" \n\n";

     cout <<"=========================================================\n\n";    
}
string menuf(){
       cout <<"1) Start Lottery\n";
       cout <<"2) Exit\n";
       string op;
       cin >> op;
       return op;   
}
void clearScreen(){
     cout <<"Press anykey to continue:";
     getch();
     system("cls");     
}