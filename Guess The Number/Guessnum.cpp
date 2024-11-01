#include<iostream>
using namespace std;
int main(){

    srand(time(NULL));
    int num=rand() %100;
    int a;
    do
    {
        cout<<"Gues the num between 1 to 100: ";
        cin>>a;
        if(a<num){
            cout<<"Too low"<<endl;
        }
        else if(a>num){
            cout<<"Too High"<<endl;
        }
    } while (a !=num);

    
    cout<<"You guessed it right."<<endl;
    
  
    
    return 0;
}