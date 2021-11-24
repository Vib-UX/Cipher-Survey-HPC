#include<bits/stdc++.h>
using namespace std;
using namespace std:: chrono;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


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

/*string decryption(string input){

    //unordered_map<char, char> inverted = inverse_map(map);

    string decrypt;
    for(int i=0;i<input.size();i++){
        decrypt+=map_2[input[i]];
    }

    return decrypt;

}*/

/*string ecryption(string input){

    string encrypt;

    for(int i=0;i<input.size();i++){
        encrypt+=map_1[input[i]];
    }

    return encrypt;

}*/
void encryption_1(string &str,unordered_map<char,char>& map_1){

    string encrypt;

    for(int i=0;i<str.size();i++){
        encrypt+=map_1[str[i]];
    }

    //return encrypt;
    //str = encrypt;

}

void decryption_1(string &str, unordered_map<char,char>& map_2){



    string decrypt;
    for(int i=0;i<str.size();i++){
        decrypt+=map_2[str[i]];
    }

    //str = decrypt;

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
    string str;
	ifstream MyReadFile("10cr_strlen_dataset.txt");
	getline(MyReadFile,str);

	std::vector<int> time;
	std::vector<int> size_n;
	int i = 21;
	while(i>=1){

		auto start = high_resolution_clock::now();
		unordered_map<char,char> map_1;
        unordered_map<char,char> map_2;
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

		string temp;

		int j = 0;
		while(j<str.size()){

			temp.push_back(str.at(j));
			j+=i;
		}
		// cout<<temp.size()<<endl;
		encryption_1(temp,map_1);
		decryption_1(temp,map_2);




		auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        //cout<<"\nTime taken: "<<duration.count()<<" ms"<<endl;
        time.push_back(duration.count());
        // int store = full_dataset.size()/i;
        size_n.push_back(temp.size());
		i/=2;

	}

	 for(int i=0;i<time.size();i++){
        cout<<time.at(i)<<" "<<size_n.at(i)<<"\n";
    }
    ofstream outFile("sizeVariation_time_stringScratch.txt");
    for(int i=0;i<time.size();++i){
        outFile<<time[i]<<" "<<size_n[i]<<endl;
    }
     
    
    
    

}
