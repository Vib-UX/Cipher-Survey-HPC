#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

using std::cout; using std::string; using std::vector; using std::cout; using std::cin; using std::endl; using std::sort;

void adfgvxEncrypt(string plaintext, string keyword, string sorted_keyword, vector<char> &ciphertxt);
int chartoint(char let);
int invalidin();


void init_code(){
    fast_io;
    #ifndef Project_repo
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}


int main()
{
    init_code();
    char cont = 'n';
    vector<char>final_ct;

    int choice;
    do{
        cout<<"Would you like to 1. encrypt a message or 2. learn about the ADFGVX cipher? ";
        cin>>choice;
        if (choice != 1 && choice != 2){
            choice = invalidin();
        }

        if (choice == 1){
            string kw;//= "DEUTSCH";
            cout<<"Enter the keyword you'd like to use: ";
            cin>>kw;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::transform(kw.begin(),kw.end(),kw.begin(), :: toupper);
            string skw = kw;
            sort(skw.begin(),skw.end());
            //cout<<endl<<keyword<<" "<<skw<<endl;
            string pt;// = "PRODUCTCIPHERS";
            cout<<"Enter the plaintext you'd like to encrypt: ";
            cin>>pt;
            std::transform(pt.begin(),pt.end(),pt.begin(), :: toupper);
            final_ct.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            adfgvxEncrypt(pt,kw,skw, final_ct);
            cout<<"Your encrypted message is: ";
            cout<<endl;
            for (unsigned index = 0; index < final_ct.size(); ++index){
                cout<<final_ct[index];
            }
            cout<<endl;
        }
        else if (choice == 2){
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"The Germany Army's ADFGVX cipher used during World War I. One of the earliest product ciphers. The key has two parts: the first part is a permutation of the 26 letters and 10 digits. The second is a keyword with no repeated letters."<<endl<<"Press any key to continue";
            cin.get();
            cout<<"In World War II it was shown that alternating substitution and transposition ciphers is a very secure thing to do. ADFGVX is weak since the substitution and transposition each occur once and the substitution is fixed, not key controlled."<<endl<<"-Dr. Edward Schaefer"<<endl;
        }
        cout<<endl<<"Would you like to continue? (Y/N): ";
        cin>>cont;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(cont == 'y' || cont == 'Y');
    cout<<"Thank you for your time. Have a lovely day."<<endl;
    return 0;
}

void adfgvxEncrypt(string plaintext, string keyword, string sorted_keyword, vector<char> &ciphertxt){
    vector<char> tenta_ct;

    vector<char> vecplt(plaintext.begin(), plaintext.end());
    char key[6][6];

    string key_components = "KZWR1F9B6CL5Q7JPGXEVY3AN8ODH02U4ISTM";
    std::random_shuffle(key_components.begin(), key_components.end());//gives a random keymap for each encryption
    for (int r = 0; r < 6 ; ++r){
        for (int q =0; q < 6; ++q){
            key[r][q] = key_components[r*6+q];
        }
    }
    //reference keymap, used for initial accuracy test
    /*
    char key[6][6] = {
    {'K', 'Z', 'W', 'R', '1', 'F'},
    {'9', 'B', '6', 'C', 'L', '5'},
    {'Q', '7', 'J', 'P', 'G', 'X'},
    {'E', 'V', 'Y', '3', 'A', 'N'},
    {'8', 'O', 'D', 'H', '0', '2'},
    {'U', '4', 'I', 'S', 'T', 'M'}
    };
    */
    cout<<"Your key is: "<<endl<<endl;
    char ADFGVX[6] = {'A','D','F','G','V','X'};
    int adfgvx_vert = 0;
    //displays the key, ADFVGX and lines for readability
    for (int key_horiz = 0; key_horiz <6 ; ++key_horiz){
        if (key_horiz == 0){
            cout<<"   ";
            for (int adfgvx_horiz = 0; adfgvx_horiz < 6; ++adfgvx_horiz){
                cout<<ADFGVX[adfgvx_horiz]<<"  ";
            }
            cout<<endl<<"  -----------------"<<endl;
        }
        cout<<ADFGVX[adfgvx_vert]<<"| "<<key[key_horiz][0]<<"  ";
        ++adfgvx_vert;
        for (int key_vert = 1; key_vert < 6; ++key_vert){
            cout<<key[key_horiz][key_vert]<<"  ";
        }
        cout<<endl;
    }
    // cout<<endl<<"Press any key to continue"<<endl;
    // cin.get();
    //finds each character of the plaintext in the key 2d array
    for (unsigned ptind = 0; ptind < vecplt.size(); ++ptind){
        for (int i  = 0; i < 6; ++i){
            for (int j = 0; j < 6; ++j){
                if (vecplt[ptind] == key[i][j]){
                    cout<<vecplt[ptind]<<" at: row "<<i+1<<", column "<<j+1<<" ";
                    tenta_ct.push_back(ADFGVX[i]);
                    tenta_ct.push_back(ADFGVX[j]);
                    cout<<endl;
                }
            }
        }
    }
    // cout<<endl<<"Press any key to continue"<<endl;
    // cin.get();
    cout<<endl<<plaintext<<" outputs ";
    for (unsigned k = 0; k < tenta_ct.size(); ++k){
        cout<<tenta_ct[k];
    }
    // cout<<endl<<endl<<"Press any key to continue"<<endl;
    // cin.get();
    vector<int>order;
    vector<int>kw_ord;
    for(unsigned kwlen = 0; kwlen < keyword.length();++kwlen){
        kw_ord.push_back(chartoint(keyword[kwlen]));
    }
    for (unsigned kwind = 0; kwind < kw_ord.size(); ++kwind){//for the sake of visualisation, shows order of the columns in the final ciphertext
        int letter_val = kw_ord[kwind];
        int letter_pos = 1;
        for (unsigned kwind2 = 0; kwind2 < kw_ord.size(); ++kwind2){
            int next = kw_ord[kwind2];
            if(letter_val > next){
                ++letter_pos;
            }
        }
        order.push_back(letter_pos);
    }
    cout<<endl;

    int ct_mat_rows;
    if ((tenta_ct.size())%keyword.length() == 0){
        ct_mat_rows = (tenta_ct.size())/keyword.length();
    }
    else{
        ct_mat_rows = 1+((tenta_ct.size())/keyword.length());
    }
    for(unsigned kw_len = 0; kw_len < keyword.length();++kw_len){
        cout<<keyword[kw_len]<<"  ";
    }
    cout<<endl;
    for(unsigned kw_len = 0; kw_len < keyword.length();++kw_len){
        cout<<order[kw_len]<<"  ";
    }
    cout<<endl;
    for(unsigned kw_len = 0; kw_len < keyword.length()-1;++kw_len){
        cout<<"---";
    }
    cout<<"-"<<endl;
    vector < vector <char> > ct_mat(ct_mat_rows, vector<char>(keyword.length()));

    for(int i=0;i<ct_mat_rows;++i)
    {
        for(unsigned j=0;j<keyword.length();++j)
        {
            if(tenta_ct.size()<=(keyword.length()*i+j)){//in case the plaintext message doesn't divide evenly, still ensures the full message is encrypted
                char space = ' ';
                (ct_mat[i])[j] =(space);//concatenation prevents the message from being decrypted properly
            }
            else{
                (ct_mat[i])[j] = tenta_ct[keyword.length()*i+j];//enters into the 6x6 array to be scrambled
            }
            cout<<ct_mat[i][j]<<"  ";
        }
        cout<<endl;
    }
    // cout<<endl<<"Press any key to continue"<<endl;
    // cin.get();
    for (unsigned keyword_count = 0; keyword_count < keyword.length(); ++keyword_count){
        for (unsigned position = 0; position < keyword.length(); ++position){
            for(int sorted_row=0;sorted_row<ct_mat_rows;++sorted_row){
                if (sorted_keyword[keyword_count] == keyword[position]){
                    if(ct_mat[sorted_row][position] != ' '){//gets rid of empty spaces, makes ciphertext harder to decrypt if each column isn't equal in length
                        ciphertxt.push_back(ct_mat[sorted_row][position]);
                    }
                }
            }
        }
    }
    cout<<endl;
}

int chartoint(char let){
    //cout<<" looking for value ";
    int num_rep;
        switch(let) {
                case 'A':
                   num_rep = 0;
                   break;
                case 'B':
                   num_rep = 1;
                   break;
                case 'C':
                   num_rep = 2;
                   break;
                case 'D':
                   num_rep = 3;
                   break;
                case 'E':
                   num_rep = 4;
                   break;
                case 'F':
                   num_rep = 5;
                   break;
                case 'G':
                   num_rep = 6;
                   break;
                case 'H':
                   num_rep = 7;
                   break;
                case 'I':
                   num_rep = 8;
                   break;
                case 'J':
                   num_rep = 9;
                   break;
                case 'K':
                   num_rep = 10;
                   break;
                case 'L':
                   num_rep = 11;
                   break;
                case 'M':
                   num_rep = 12;
                   break;
                case 'N':
                   num_rep = 13;
                   break;
                case 'O':
                   num_rep = 14;
                   break;
                case 'P':
                   num_rep = 15;
                   break;
                case 'Q':
                   num_rep = 16;
                   break;
                case 'R':
                   num_rep = 17;
                   break;
                case 'S':
                   num_rep = 18;
                   break;
                case 'T':
                   num_rep = 19;
                   break;
                case 'U':
                   num_rep = 20;
                   break;
                case 'V':
                   num_rep = 21;
                   break;
                case 'W':
                   num_rep = 22;
                   break;
                case 'X':
                   num_rep = 23;
                   break;
                case 'Y':
                   num_rep = 24;
                   break;
                case 'Z':
                   num_rep = 25;
                   break;
                default:
                   cout << "Invalid character " << let<< endl;
                   break;
           }
    return num_rep;
}

int invalidin(){
    cin.clear();
    int newinput;
    cout<<"Please enter a valid input: ";
    cin>>newinput;
    return newinput;
}