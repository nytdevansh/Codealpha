#include<iostream>
#include<vector>
#include<string>
using namespace std;


// Helper function to convert a string to lowercase
string toLowerCase(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Helper function to check if a keyword is in the input
bool contains(const string &input, const string &keyword) {
    return input.find(keyword) != string::npos;
}

int main(){
     char a[]="_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

    cout<<a<<endl;
    std::cout << "     *     *****       *****    *   *    *    ******   ****   ***** *******\n";
    std::cout << "    * *      *        *     *   *   *   * *      *     *   *  *   *    *\n";
    std::cout << "   *   *     *        *         *****  *   *     *     ****   *   *    *\n";
    std::cout << "   *****     *        *         *   *  *****     *     *   *  *   *    *\n";
    std::cout << "  *     *  *****       *****    *   * *     *    *     ****   *****    *\n";

    cout<<a<<endl;
     cout<<"This is an Ai chatbot creted by Devansh Yadav.\n";
    string text;
  do{
    
   
    cout<<"You: ";
    getline(cin,text);
    string lowerText = toLowerCase(text);

    if(contains(lowerText, "hi")){
        cout<<"AI:";
        cout<<"Hello!\nHow can I help yoou today."<<endl;
    }
    else if(contains(lowerText, "what is your name")){
        cout<<"AI:";
        cout<<"My name is ai chatbot."<<endl;

    }
    else if(contains(lowerText, "how are you feeling today")){
        cout<<"AI:";
        cout<<"I  am feeling awesome today."<<endl;
    }
    else if(text=="0"){
        cout<<"AI: ";
        cout<<"Exiting"<<endl;
    }
    else{
        cout<<"AI:"<<endl;
        cout<<"Sorry I can't help with that yet."<<endl;
    }

}
while(text!="0");

    return 0;
}


//it's just an trial