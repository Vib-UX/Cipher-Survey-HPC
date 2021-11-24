#include<bits/stdc++.h>
#include <fstream>
#include <cstdlib>
using namespace std;


void removeSpecialCharacter(string &s)
{
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 'A' || s[i] > 'Z' &&
            s[i] < 'a' || s[i] > 'z')
        {
            s.erase(i, 1);
            i--;
        }
    }
}

int main(){


    vector<string> s1;
    fstream file;
    string word,t,q,filename;
     filename = "rockyou.txt";
     file.open(filename.c_str());
      while (file >> word)
    {

        s1.push_back(word);

    }

    /*for(int i=0;i<s1.size();i++){
        cout<<s1[i]<<endl;
    }*/

    cout<<"Total Dictionary Size : "<<s1.size()<<" number of words"<<endl;

    vector<string> updated_file;

    for(int i=0;i<s1.size();i++){
        removeSpecialCharacter(s1.at(i));
        if(s1.at(i)==""){
            continue;
        }
        updated_file.push_back(s1.at(i));
        //cout<<s1.at(i)<<endl;
    }

    cout<<"Updated Dictionary Size : "<<updated_file.size()<<" number of words"<<endl;

    ofstream outFile("dataset.txt");
    for (const auto &e : updated_file) outFile << e << "\n";
    cout<<"Dataset Updated ...... "<<endl;


    /*int i=11663;
    int k=0;
    while(i!=0){

        subsample.push_back(s1[k]);
        k+=40;

        i--;
    }*/


}
