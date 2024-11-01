#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;


//backend statements for the code to work properly


int create(const string& filename){
    ofstream file(filename);
    if(file){
        cout<<"File "<<filename<<" Created.";
    }
    else{
        cout<<"Error! While Creating"<<filename<<"\n Suggestions:Use another name";
    }
    return 0;
}
int write(const string& filename){
    ofstream file(filename, ios::app); //for opening the file used ios::app
    if(file){
        cout<<"Enter the text to the file";
        string text;
        while(getline(cin,text)){
            if(text=="exit"){
                break;
            }
            file<<text<<endl;

        }
        cout<<"Data Written to "<<filename<<".";

    }
    else if(!file){
        cout<<"File not Found.";
        cout<<"\nPlease check the Spelling or make sure that the file is created properly.";
    }
    return 0;
}
int read(const string& filename){
    
    ifstream file(filename);
    if(file){
        cout<<"Content of "<<filename<<":\n";
        string text;
        getline(cin,text);
        cout<<text<<endl;
    }
    else if(!file){
        cout<<"Error While Opening the File";
         cout<<"\nPlease check the Spelling or make sure that the file is created properly.";
        
    }

    return 0;

}
int deletef(const string& filename){
    
   if(remove(filename.c_str())==0){
    cout<<filename<<" removed succesfully"<<endl;
   }
    else{
        cout<<"Error While Deleting the file.";
        cout<<"\nPlease check the Spelling or make sure that the file is created properly.";
        
    }
    return 0;
}


int main(){
    int choice;
    string filename;
   
   do{
    cout<<"Welcome to File Manager Created by Devansh Yadav\n";
    cout<<"Please choose an option from below: \n\n";
    cout<<"\n1. Create a file";
    cout<<"\n2. write to a file";
    cout<<"\n3. read a file";
    cout<<"\n4. Delete a file";
    cout<<"\n5. Exit"<<endl;


    
    cout<<"\nSelected Operation: "<<endl;
    cin>>choice;

     switch (choice)
     {
     
     
    case 1:
        cout<<"Enter the File name: ";
        cin>>filename;
        create(filename);
        break;
        
    case 2:
        cout<<"Write";
        cin>>filename;
        write(filename);
        break;
    
    case 3:
        cout<<"Read";
        cin>>filename;
        cout<<read(filename);
        break;
    
    case 4:
        cout<<"Delete";
        cin>>filename;
        deletef(filename);
        break;
    
    case 5:
        cout<<"Exiting the file manager."<<endl;
        break;
    
     }
    }
while(choice!=5);

   
   return 0;
   
}