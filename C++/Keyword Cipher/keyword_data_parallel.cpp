#include<bits/stdc++.h>
// #include<string.h>
// #include<vector>
// #include<unordered_map>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#include<pthread.h>
#include<thread>
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

void decryption(string &str, string &input, int si, int ei){



    string decrypt;
    for(int i=si;i<ei;i++){
        decrypt+=map_2[input[i]];
    }

    str = decrypt;

}

void encryption(string &str, string &input, int si, int ei){

    string encrypt;

    for(int i=si;i<ei;i++){
        encrypt+=map_1[input[i]];
    }
    

    //return encrypt;
    str = encrypt;

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


void init_code(){
    fast_io;
    #ifndef Project_Repo
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

int main(){

    init_code();

    const auto processor_count = thread::hardware_concurrency();
    unsigned int n = thread::hardware_concurrency();
    cout << n << " concurrent threads are supported.\n";
    //cout<<processor_count<<endl;

    // string input;
    // string key;
    // cout<<"Enter the message : "<<endl;
    // //getline(cin,input);
    // cin>>input;
    // cout<<"Enter the Key : "<<endl;
    // //getline(cin,key);
    // cin>>key;
    // /*cout<<input<<endl;
    // return 0;*/
    // clock_t time_req;
    // time_req=clock();
    // auto start = high_resolution_clock::now();
    // removeSpecialCharacter(input);
    // transform(input.begin(), input.end(), input.begin(), ::tolower);
    // cout<<input<<endl;


    // key = removeDuplicates(key);
    // removeSpecialCharacter(key);
    // transform(key.begin(), key.end(), key.begin(), ::tolower);
    // //cout<<key<<endl;


    
    // string string_difference;

    // string all_char ="abcdefghijklmnopqrstuvwxyz";

    // string temp = key;
    // sort(temp.begin(),temp.end());

    // set_difference(all_char.begin(), all_char.end(), temp.begin(), temp.end(), back_inserter(string_difference));
    // //cout << "In string1 but not string2: " << string_difference << std::endl;

    // string final_key_used = key+string_difference;
    


    // for(int i=0;i<all_char.size();i++){
    //     map_1[all_char[i]]=final_key_used[i];
    // }

    // for(int i=0;i<all_char.size();i++){
    //     map_2[final_key_used[i]]=all_char[i];
    // }

    // // cout<<final_key_used<<endl;
    // // cout<<all_char<<endl;


    // // thread t1(encryption,ref(s1),ref(input),0,input.size()/2);
    // // thread t2(encryption,ref(s2),ref(input),input.size()/2,input.size());



    // // t1.join();
    // // t2.join();





    // int num_threads = 2;
    // int steps = input.size()/num_threads;
    // vector<thread> threads;
    // vector<string> output(num_threads);

    // for(int i=0;i<num_threads;i++){
    //     threads.push_back(thread(encryption,ref(output[i]),ref(input),i*steps,(i+1)*steps));
    // }
    // for (std::thread &t : threads) {
    //     if (t.joinable()) {
    //     t.join();
    //     }
    // }
    // // for(int i=0;i<output.size();i++){
    // //     cout<<output[i];
    // // }
    // cout<<output[0]+output[1];
    // //cout<<output[0]+output[1]+output[2]+output[3]+output[4]+output[5]+output[6]+output[7]+output[8];
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop-start);
    // cout<<"\nTime taken: "<<duration.count()<<" us"<<endl;

    // time_req = clock() - time_req;
    // cout << "\nMultithreading " << (float)time_req/CLOCKS_PER_SEC << " seconds\n";


    // /*string encrypted = ecryption(input,map);

    // cout<<"Encypted Text : "<<encrypted<<endl;


    // string decrypted = decryption(encrypted,map);

    // cout<<"Decrypted Text : "<<decrypted<<endl;

    // time_req = clock() - time_req;
    // cout << "Linear " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;


    // /*time_req = clock() - time_req;
    // cout << "Linear " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;*/

    // return 0;
    
    string str;
    ifstream MyReadFile("10cr_strlen_dataset.txt");
    getline(MyReadFile,str);

    std::vector<int> time;
    std::vector<int> no_threads;
    int i = 1;
    while(i<=12){

        auto start = high_resolution_clock::now();
        
        string key="secret";
        key = removeDuplicates(key);
        removeSpecialCharacter(key);
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        // cout<<key<<endl;

        
        string string_difference;

        string all_char ="abcdefghijklmnopqrstuvwxyz";

        string temp_1 = key;
        sort(temp_1.begin(),temp_1.end());

        set_difference(all_char.begin(), all_char.end(), temp_1.begin(), temp_1.end(), back_inserter(string_difference));
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

        string temp = str;

        // int j = 0;
        // while(j<str.size()){

        //     temp.push_back(str.at(j));
        //     j+=i;
        // }
        // cout<<temp.size()<<endl;
        int num_threads = i;
        int steps = temp.size()/num_threads;
        vector<thread> threads;
        vector<string> output(num_threads);

        for(int i=0;i<num_threads;i++){
            threads.push_back(thread(encryption,ref(output[i]),ref(temp),i*steps,(i+1)*steps));
        }
        for (std::thread &t : threads) {
            if (t.joinable()) {
            t.join();
            }
        }
        // encryption_1(temp,map_1);
        // decryption_1(temp,map_2);




        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        //cout<<"\nTime taken: "<<duration.count()<<" ms"<<endl;
        time.push_back(duration.count());
        // int store = full_dataset.size()/i;
        no_threads.push_back(i);
        i++;

    }

     for(int i=0;i<time.size();i++){
        cout<<time.at(i)<<" "<<no_threads.at(i)<<"\n";
    }
    ofstream outFile("Threads_variation_time_stringScratch.txt");
    for(int i=0;i<time.size();++i){
        outFile<<time[i]<<" "<<no_threads[i]<<endl;
    }
     

}



