#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        fflush(stdin);
        char name[500];
        int i,space=0,ind=0;
        cin.getline(name,sizeof(name));
        //cout<<name<<endl;
        for ( i=0 ; name[i]!='\0' ; i++ ){
            if( name[i] == ' ' ){
                space++;
            }
        }
        char f=name[0];
        if ( space == 0 ){
            if ( f>='A' && f<='Z' ){
                cout<<f;
            }
            else{
                f = f - ' ';
                cout<<f;
            }
            for ( i=1 ; name[i]!='\0' ; i++ ){
                if ( name[i]>='a' && name[i]<='z' ){
                    cout<<name[i];
                }
                else{
                    name[i] = name[i] + ' ';
                    cout<<name[i];
                }
            }
        }
        else if ( space == 1 ){
            if ( f>='A' && f<='Z' ){
                cout<<f<<". ";
            }
            else{
                f = f - ' ';
                cout<<f<<". ";
            }
            for (int i=0 ; name[i]!=' ' ; i++ ){
                ind++;
            }
            if ( name[ind+1]>='A' && name[ind+1]<='Z' ){
                cout<<name[ind+1];
            }
            else{
                name[ind+1] = name[ind+1] - ' ';
                cout<<name[ind+1];
            }
            for ( int i=ind+2 ; name[i]!='\0' ; i++ ){
                if ( name[i]<='z' && name[i]>='a' ){
                    cout<<name[i];
                }
                else{
                    name[i]=name[i]+' ';
                    cout<<name[i];
                }
            }
        }
        else if( space == 2 ){
            if ( f>='A' && f<='Z' ){
                cout<<f<<". ";
            }
            else{
                f = f - ' ';
                cout<<f<<". ";
            }
            for (int i=0 ; name[i]!=' ' ; i++ ){
                ind++;
            }
            if ( name[ind+1]>='A' && name[ind+1]<='Z' ){
                cout<<name[ind+1]<<". ";
            }
            else{
                name[ind+1] = name[ind+1] - ' ';
                cout<<name[ind+1]<<". ";
            }
            for ( int i=ind+1 ; name[i]!=' ' ; i++ ){
                ind++;
            }
            ind++;
            if ( name[ind+1]>='A' && name[ind+1]<='Z' ){
                cout<<name[ind+1];
            }
            else{
                name[ind+1] = name[ind+1] - ' ';
                cout<<name[ind+1];
            }
             for ( int i=ind+2 ; name[i]!='\0' ; i++ ){
                if ( name[i]<='z' && name[i]>='a' ){
                    cout<<name[i];
                }
                else{
                    name[i]=name[i]+' ';
                    cout<<name[i];
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
