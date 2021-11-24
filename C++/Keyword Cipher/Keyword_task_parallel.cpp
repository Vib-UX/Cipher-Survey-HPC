#include<bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include<pthread.h>
#include<thread>
#include<omp.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace std:: chrono;



unordered_map<char,char> map_1;

unordered_map<char,char> map_2;

/*unordered_map<char,char> inverse_map(unordered_map<char,char> &map)
{
    unordered_map<char,char> inv;
    for_each(map.begin(), map.end(),
                [&inv] (const std::pair<char,char> &p)
                {
                    inv.insert(make_pair(p.second, p.first));
                });
    return inv;
}*/

void decryption_1(string &input, int si, int ei){



    string decrypt;
    for(int i=si;i<ei;i++){
        decrypt+=map_2[input[i]];
    }

    //str = decrypt;

}

string decryption(string &input){



    string decrypt;
    for(int i=0;i<input.size();i++){
        decrypt+=map_2[input[i]];
    }

    return decrypt;

}

void encryption_1(string &input, int si, int ei){

    string encrypt;

    for(int i=si;i<ei;i++){
        encrypt+=map_1[input[i]];
    }

    
    //str = encrypt;

}

string encryption(string &input){

    string encrypt;

    for(int i=0;i<input.size();i++){
        encrypt+=map_1[input[i]];
    }

    return encrypt;
    // str = encrypt;

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

void task_1(vector<string> &subsample, int si, int ei){
    #pragma omp parallel for 
    //int iterat=si;
    //while(iterat<ei){
    for(int iterat = si; iterat<ei;iterat++){
        transform(subsample.at(iterat).begin(), subsample.at(iterat).end(), subsample.at(iterat).begin(), ::tolower);
        vector<string> for_encrypt;

        /*vector<string> output(2);

        thread t1(encryption,ref(output[0]),ref(input),ref(map),0,input.size()/2);
        thread t2(encryption,ref(output[1]),ref(input),ref(map),input.size()/2,input.size());



        t1.join();
        t2.join();*/

        //int number = input.size();

        // int num_threads = 2;
        // int steps = subsample.at(iterat).size()/num_threads;
        // vector<thread> threads;
        // vector<string> output(num_threads);

        // for(int i=0;i<num_threads;i++){
        //     threads.push_back(thread(encryption_1,ref(output[i]),ref(subsample.at(iterat)),
        //     	i*steps,(i+1)*steps));
        // }


        // for (thread &t : threads) {
        //     if (t.joinable()) {
        //         t.join();
        //     }

        // }



        /*for(int i=0;i<output.size();i++){
            cout<<output[i];
        }*/
        //cout<<output[0]+output[1]+output[2]+output[3]+output[4]+output[5]+output[6]+output[7]+output[8];
        //cout<<output[0]+output[1]<<endl;

        // string str = output[0]+output[1];
        for_encrypt.push_back(encryption(subsample.at(iterat)));
        // for_encrypt.push_back(str);
        //iterat++;



    }
}


void task_2(vector<string> &subsample, int si, int ei){

    //int iterat=si;
    //while(iterat<ei){
    #pragma omp parallel for 

    for(int iterat = si; iterat<ei;iterat++){

        transform(subsample.at(iterat).begin(), subsample.at(iterat).end(), subsample.at(iterat).begin(), ::tolower);

        vector<string>for_decrypt;
        // vector<string> output(2);
        // thread t5(encryption,ref(output[0]),ref(subsample.at(iterat)),0,subsample.at(iterat).size()/2);
        // thread t6(encryption,ref(output[1]),ref(subsample.at(iterat)),subsample.at(iterat).size()/2,subsample.at(iterat).size());
        // t5.join();
        // t6.join();

        //int number = input.size();

        // int num_threads = 2;
        // int steps = subsample.at(iterat).size()/num_threads;
        // vector<thread> threads;
        // vector<string> output(num_threads);

        // for(int i=0;i<num_threads;i++){
        //     threads.push_back(thread(decryption_1,ref(output[i]),
        //     	ref(subsample.at(iterat)),i*steps,(i+1)*steps));
        // }


        // for (thread &t : threads) {
        //     if (t.joinable()) {
        //         t.join();
        //     }

        // }
        /*for(int i=0;i<output.size();i++){
            cout<<output[i];
        }*/
        //cout<<output[0]+output[1]+output[2]+output[3]+output[4]+output[5]+output[6]+output[7]+output[8];
        //cout<<output[0]+output[1]<<endl;
        // string str1 = output[0]+output[1];
        for_decrypt.push_back(decryption(subsample.at(iterat)));
        // for_decrypt.push_back(str1);
        
    }
}

void init_code(){
    fast_io;
    #ifndef Project_Repo
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}


int main(){

    init_code();


    vector<string> full_dataset;
    
    fstream file;
    string word,t,q,filename;
     filename = "dataset.txt";
     file.open(filename.c_str());
      while (file >> word)
    {

        full_dataset.push_back(word);

    }
    
    
    vector<int>time;
    vector<int>size_n;
    int i=353;
    while(i>=1){
        auto start = high_resolution_clock::now();
        // unordered_map<char,char> map_1;
        // unordered_map<char,char> map_2;
        string key="secret";
        // cout<<"Enter the Key : "<<endl;
        // getline(cin,key);
        std::vector<string> subsample;
        clock_t time_req;
        time_req=clock();
        

        // removeSpecialCharacter(input);
        // transform(input.begin(), input.end(), input.begin(), ::tolower);
        // cout<<input<<endl;


        key = removeDuplicates(key);
        removeSpecialCharacter(key);
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        // cout<<key<<endl;

        
        string string_difference;

        string all_char ="abcdefghijklmnopqrstuvwxyz";

        string temp = key;
        sort(temp.begin(),temp.end());

        set_difference(all_char.begin(), all_char.end(), temp.begin(), temp.end(), back_inserter(string_difference));
        //cout << "In string1 but not string2: " << string_difference << std::endl;

        string final_key_used = key+string_difference;
        //cout<<final_key_used<<endl;
        //cout<<all_char<<endl;
        for(int temp_store=0;temp_store<all_char.size();temp_store++){
            map_1[all_char[temp_store]]=final_key_used[temp_store];
        }

        for(int temp_store=0;temp_store<all_char.size();temp_store++){
            map_2[final_key_used[temp_store]]=all_char[temp_store];
        }

        int interal_splitting = 0;
        while(interal_splitting<full_dataset.size()){
            subsample.push_back(full_dataset.at(interal_splitting));
            interal_splitting+=i;
        }

        /*for(int i=0;i<s1.size();i++){
            cout<<s1.at(i)<<endl;
        }*/
        vector<string> for_encrypt;
        vector<string> for_decrypt;



        // thread t1(task_1,ref(for_encrypt),ref(subsample), 0, subsample.size()/2);
        // thread t2(task_2,ref(for_decrypt),ref(subsample),subsample.size()/2,subsample.size());
        thread t1(task_1,ref(subsample), 0, subsample.size()/2);
        thread t2(task_2,ref(subsample),subsample.size()/2,subsample.size());

        t1.join();
        t2.join();

        

        /*for(int k=0;k<s1.size();k++){
            encryption_1(s1.at(k),map_1);
        }

        for(int j =0;j<s1.size();j++){
            decryption_1(s1.at(j),map_2);
        }*/


        // string encrypted = ecryption(input);

        // cout<<"Encypted Text : "<<encrypted<<endl;

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop-start);
        //cout<<"\nTime taken: "<<duration.count()<<" ms"<<endl;
        time.push_back(duration.count());
        // int store = full_dataset.size()/i;
        size_n.push_back(subsample.size());
        //cout<<s1.at(0)<<"\n";

        // string decrypted = decryption(encrypted);

        // cout<<"Decrypted Text : "<<decrypted<<endl;



        // time_req = clock() - time_req;
        // cout << "Linear " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
        i/=2;

    }

    for(int i=0;i<time.size();i++){
        cout<<time.at(i)<<" "<<size_n.at(i)<<"\n";
    }
    
    /*ofstream outFile("Task_sizeVariation_time_Scratch.txt");
    for(int i=0;i<time.size();++i){
        outFile<<time[i]<<" "<<size_n[i]<<endl;
    }*/




}
