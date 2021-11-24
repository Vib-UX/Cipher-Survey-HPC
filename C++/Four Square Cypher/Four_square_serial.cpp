#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string; using std::to_string;
#include<fstream>
using std::ifstream; using std::ofstream;
#include<sstream>
using std::ostringstream;
using namespace std:: chrono;



string block1,block2;

void init_code(){
    fast_io;
    #ifndef Project_repo
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}



string clean_string(string s) {
	string return_string = "";

	//return a lowercase version of the input string with only letters, ignoring 'q'
	for (long i = 0; i < s.size(); i++) {
		char character = s[i];
		if (isalpha(character) && character != 'q')
			return_string += tolower(character);
	}
	return return_string;
}


string create_encoding(string &key) {
	//block encoding does not include 'q'
	string keyword_encoding = "abcdefghijklmnoprstuvwxyz";

	//create and return an encoded block for the keyword
	for (long i = key.size() - 1; i >= 0; i -= 1) {
		if (key[i] != 'q') {
			auto index = keyword_encoding.find(key[i]);
			keyword_encoding.erase(index, 1);
			keyword_encoding = key[i] + keyword_encoding;
		}
	}
	return keyword_encoding;
}


//encode a two letter string (digraph) using keyword blocks
string encode_digraph(string &dg) {
	string encoded_digraph = "";
	string alphabet_block = "abcdefghijklmnoprstuvwxyz";
	char first_letter = dg[0];
	char second_letter = dg[1];
	int first_index = alphabet_block.find(first_letter);
	int second_index = alphabet_block.find(second_letter);
	int first_row = first_index / 5;
	int first_column = first_index % 5;
	int second_row = second_index / 5;
	int second_column = second_index % 5;

	//find index in encoded blocks
	int first_encoded_index = 5 * first_row + second_column;
	int second_encoded_index = 5 * second_row + first_column;

	//find encoded letters in blocks
	char first_encoded_letter = block1[first_encoded_index];
	char second_encoded_letter = block2[second_encoded_index];

	//create encoded digraph
	encoded_digraph = encoded_digraph + first_encoded_letter;
	encoded_digraph = encoded_digraph + second_encoded_letter;
	return encoded_digraph;
}

//decode an encoded two letter string (digraph) using keyword blocks
string decode_digraph(string &dg) {
	string decoded_digraph = "";
	string alphabet_block = "abcdefghijklmnoprstuvwxyz";
	char first_letter = dg[0];
	char second_letter = dg[1];
	int first_index = block1.find(first_letter);
	int second_index = block2.find(second_letter);
	int first_row = first_index / 5;
	int first_column = first_index % 5;
	int second_row = second_index / 5;
	int second_column = second_index % 5;

	//find index in alphabet blocks
	int first_decoded_index = 5 * first_row + second_column;
	int second_decoded_index = 5 * second_row + first_column;

	//find decoded letters in alphabet blocks
	char first_decoded_letter = alphabet_block[first_decoded_index];
	char second_decoded_letter = alphabet_block[second_decoded_index];

	//create decoded digraph
	decoded_digraph = decoded_digraph + first_decoded_letter;
	decoded_digraph = decoded_digraph + second_decoded_letter;
	return decoded_digraph;
}

//encode a message using keyword blocks
void encode(string &msg) {
	string encoded_message = "";
	// string block1 = create_encoding(key1);
	// string block2 = create_encoding(key2);
	string message = clean_string(msg);
	long message_length = message.size();

	//add "x" to end of message if string has an odd number of letters
	if (message_length % 2 == 1)
		message += "x";

	//string together the encoded digraphs to make the encoded message
	for (long i = 0; i < message_length; i += 2) {
		string digraph = message.substr(i, 2);
		string encoded_digraph = encode_digraph(digraph);
		encoded_message += encoded_digraph;
	}
	// return encoded_message;
	msg = encoded_message;
}

//decode an encoded message using keyword blocks
void decode(string &msg) {
	string decoded_message = "";
	string message = clean_string(msg);
	long message_length = message.size();

	//string together decoded digraphs to make decoded message
	for (long i = 0; i < message_length; i += 2) {
		string digraph = message.substr(i, 2);
		string decoded_digraph = decode_digraph(digraph);
		decoded_message += decoded_digraph;
	}
	// return decoded_message;
	msg = decoded_message;
}

int main() {
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
        string keyword1 = "german";
		string keyword2 = "monarchy";
		
		block1 = create_encoding(keyword1);
		block2 = create_encoding(keyword2);
        vector<string> s1;
        int interal_splitting = 0;
        while(interal_splitting<full_dataset.size()){
            s1.push_back(full_dataset.at(interal_splitting));
            interal_splitting+=i;
        }

        for(int k=0;k<s1.size()/2;k++){
            encode(s1.at(k));
        }

        for(int j =0;j<s1.size()/2;j++){
            //cout<<s1.at(j)<<" ";
            decode(s1.at(j));
        }


        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop-start);
        //cout<<"\nTime taken: "<<duration.count()<<" ms"<<endl;
        time.push_back(duration.count());
        size_n.push_back(s1.size());
      
        i/=2;

    }

    for(int i=0;i<time.size();i++){
        cout<<time.at(i)<<" "<<size_n.at(i)<<"\n";
    }
    ofstream outFile("sizeVariation_time_Scratch.txt");
    for(int i=0;i<time.size();++i){
        outFile<<time[i]<<" "<<size_n[i]<<endl;
    }

}