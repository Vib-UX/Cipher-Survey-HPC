#include<iostream>
#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace std:: chrono;

void encrypt(char a , char b, string keygen[],string &output){

    for(int i=0;i<5;i++){
      int fst_chr_row=-1,d;
        for(int j=0;j<5;j++){

            if(keygen[i][j]==a){
                d = j;
                fst_chr_row =i;
            }
        }
        for(int j=0;j<5;j++){
            if(keygen[i][j]==b && i==fst_chr_row){
                output+=keygen[i][(d+1)%5];
                output+=keygen[i][(j+1)%5];
                //cout<<"hello"<<endl;
                return;
            }
        }
    }

    for(int j=0;j<5;j++){
        int fst_chr_col=-1, d;
        for(int i=0;i<5;i++){

            if(keygen[i][j]==a){
                d=i;
                fst_chr_col=j;
            }
        }
        for(int i=0; i<5;i++){
            if(keygen[i][j]==b && j==fst_chr_col){
                output+=keygen[(d+1)%5][j];
                output+=keygen[(i+1)%5][j];

                //cout<<output;
                return;

            }
        }
    }

    int fst_char_col , fst_char_row, scnd_char_col, scnd_char_row;
    for(int i=0;i<5;i++){

        for(int j=0;j<5;j++){
            if(keygen[i][j]==a){
                fst_char_row=i;

                fst_char_col=j;
            }
            else if(keygen[i][j]==b){
                scnd_char_row=i;
                scnd_char_col=j;
            }
        }
    }

    output+=keygen[fst_char_row][scnd_char_col];
    output+=keygen[scnd_char_row][fst_char_col];
    return;
    //cout<<output;
}
void decrypt(char a , char b, string keygen[],string &output){

    for(int i=0;i<5;i++){
      int fst_chr_row=-1,d;
        for(int j=0;j<5;j++){

            if(keygen[i][j]==a){
                d = j;
                fst_chr_row =i;

            }
        }
        for(int j=0;j<5;j++){
            if(keygen[i][j]==b && i==fst_chr_row){
                //cout<<"Hello"<<endl;
                int count_d=0;
                int count_i =0;
                if(d-1<0){
                    count_d = 5;
                }
                if(j-1<0){
                    count_i=5;
                }
                //cout<<"hello"<<endl;
                //cout<<d;
                output+=keygen[i][(count_d+d-1)%5];
                output+=keygen[i][(count_i+j-1)%5];
                //cout<<"hello"<<endl;
                return;
            }
        }
    }

    for(int j=0;j<5;j++){
        int fst_chr_col=-1, d;
        for(int i=0;i<5;i++){

            if(keygen[i][j]==a){
                d=i;
                fst_chr_col=j;
            }
        }
        for(int i=0;i<5;i++){
            if(keygen[i][j]==b && j==fst_chr_col){
                int count_d=0;
                int count_i =0;
                if(d-1<0){
                    count_d = 5;
                }
                if(i-1<0){
                    count_i=5;
                }
                output+=keygen[(count_d+d-1)%5][j];
                output+=keygen[(count_i+i-1)%5][j];

                //cout<<output;
                return;

            }
        }
    }
    int fst_char_col , fst_char_row, scnd_char_col, scnd_char_row;
    for(int i=0;i<5;i++){

        for(int j=0;j<5;j++){
            if(keygen[i][j]==a){
                fst_char_row=i;

                fst_char_col=j;
            }
            else if(keygen[i][j]==b){
                scnd_char_row=i;
                scnd_char_col=j;
            }
        }
    }

    output+=keygen[fst_char_row][scnd_char_col];
    output+=keygen[scnd_char_row][fst_char_col];
    return;
    //cout<<output;
}

void init_code(){
    fast_io;
    #ifndef Project_Repo
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

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

void replcae_j(string &s){

    for(int i=0;i<s.size();i++){
        if(s[i]=='j'){
            s[i]='i';
        }
    }

}

string removeDuplicates(string s){
  unordered_map<char,bool> exists;
  string output;
  for(int i=0;i<s.size();i++){
    exists[s[i]]=true;
  }

  for(int i=0;i<s.size();i++){
    if(exists[s[i]]==true){
        output+=s[i];
        exists[s[i]]=false;
    }
  }

  return output;
}


int main(){


    init_code();

    vector<string> full_dataset;
    
    fstream file;
    string word,t,q,filename;
    filename = "dataset.txt";
    file.open(filename.c_str());
    while (file >> word){
        replcae_j(word);
        full_dataset.push_back(word);
    }

    cout<<full_dataset.size()<<endl;
    //return 0;

    vector<int>time;
    vector<int>size_n;
    
    int k = 353;
    while(k>=1){
        vector<string> subsample;
        int interal_splitting = 0;
        while(interal_splitting<full_dataset.size()){
            subsample.push_back(full_dataset.at(interal_splitting));
            interal_splitting+=k;
        }
        //cout<<subsample.size()<<endl;

        auto start = high_resolution_clock::now();
        string p ="abcdefghiklmnopqrstuvwxyz";
        string key="chickendinner";
        // cout<<"Enter the Key : ";
        // cin>>key;
        key = removeDuplicates(key);
        removeSpecialCharacter(key);
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        
        
        int n=key.size();

        // cout<<new_key<<endl;
        // Generation of Keygen :
        string key_gen[5];
        int val=0;
        int con_row = n/5;
        int con_col = n%5;
        for(int i=0;i<=con_row;i++){
            for(int j=0;j<5;j++){
                key_gen[i]+=key[val];
                val++;
                if(val==n){
                    break;
                    }
                }
            }
        /*for(int i=0;i<n;i++){
            cout<<key_gen[i]<<endl;
        }*/
        string non_key;
        for(int i=0;i<p.size();i++){
            bool flag =true;
            for(int j=0;j<n;j++){
                if(p[i]==key[j]){
                    flag=false;
                }
            }
            if(flag){
                non_key+=p[i];
            }
        }
        int non_key_val=0;
        int i=con_row;
        for(;i<5;i++){
            int j;
            if(i>con_row){
                j=0;
            }
            else{
                j=con_col;
            }
            for(;j<5;j++){
                key_gen[i]+=non_key[non_key_val];
                non_key_val++;
            }
        }
        /*for(int i=0;i<5;i++){
            cout<<key_gen[i]<<endl;
        }*/

        

        
        for(int j=0;j<subsample.size()/2;j++){
            string cypher;
            string pln_txt =  subsample.at(3);
            transform(pln_txt.begin(), pln_txt.end(), pln_txt.begin(), ::tolower);
            // cout<<"Enter the Text : ";
            // cin>>pln_txt;
            // replcae_j(pln_txt);

            int diphr_size = pln_txt.size();
            if(diphr_size%2==1){
                pln_txt+='z';
                diphr_size+=1;
            }
            for(int i=0;i<diphr_size;i+=2){
                encrypt(pln_txt[i],pln_txt[i+1],key_gen,cypher);
            }
        }

        for(int j = subsample.size()/2;j<subsample.size();j++){
            string decypher;
            // cout<<subsample.at(j)<<endl;
            string pln_txt_1 =  subsample.at(3);
            transform(pln_txt_1.begin(), pln_txt_1.end(), pln_txt_1.begin(), ::tolower);
            // replcae_j(pln_txt_1);
            // cout<<pln_txt_1<<"\n";
            

            int diphr_size_1 = pln_txt_1.size();
            if(diphr_size_1%2==1){
                pln_txt_1+='z';
                diphr_size_1+=1;
            }
            for(int i=0;i<diphr_size_1;i+=2){
                decrypt(pln_txt_1[i],pln_txt_1[i+1],key_gen,decypher);
            }
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop-start);
        time.push_back(duration.count());
        size_n.push_back(subsample.size());
        //cout<<"\nTime taken: "<<duration.count()<<" ms"<<endl;
        k/=2;
    }

    
    for(int i=0;i<time.size();i++){
        cout<<time.at(i)<<" "<<size_n.at(i)<<"\n";
    }
    /*ofstream outFile("sizeVariation_time_Scratch.txt");
    for(int i=0;i<time.size();++i){
        outFile<<time[i]<<" "<<size_n[i]<<endl;
    }*/
}