#include<bits/stdc++.h> 
using namespace std; 

void naivepatternsearch(string text,string pattern){ 
    int n=text.length();    
     int m=pattern.length();     
     for(int i=0;i<=n-m;i++){         
        int j; 
        for( j=0;j<m;j++){           
            if(text[i+j]!=pattern[j]){            
                 break; 
          }           } 
        if( j == m){ 
            cout<<" pattern found at index "<<i+1<<endl;  
        } 
    } 
} 
  
int main(){ 
    string text,pattern;     char a,b; 
    cout<<"enter text element :"<<endl;
        
    cin>>a;     
    cin.ignore();     
    getline(cin,text);     
    text=a+text; 

    cout<<"enter pattern element :"<<endl;

    cin>>b;      
    cin.ignore();    
    getline(cin,pattern);    
    pattern=b+pattern;  
    //search for the pattern in the text
    naivepatternsearch(text,pattern);  
 
} 
