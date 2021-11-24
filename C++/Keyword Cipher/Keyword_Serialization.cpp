#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

string plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string encoder(string key,string encode)
{
    bool a[26]={0};
    for(int i=0;i<key.size();i++)
    {
       if(key[i] >= 'A' && key[i] <= 'Z')
        {
            if (a[key[i]-65] == 0)
            {
                encode += key[i];
                a[key[i]-65] = 1;
            }
        }
        else if (key[i] >= 'a' && key[i] <= 'z')
        {
            if (a[key[i]-97] == 0)
            {
                encode += key[i] - 32;
                a[key[i]-97] = 1;
            }
        }
    }
    for(int i=0;i<26;i++)
    {
         if(a[i] == 0)
        {
            a[i]=1;
            encode += char(i + 65);
        }
    }
    return encode;
}

string cipher(string str,string enc)
{
    string c= "";
    for(int i=0;i<str.size();i++)
    {
        if (str[i] >='a' && str[i] <='z')
        {
            int pos = str[i] - 97;
            c += enc[pos];
        }
        else if (str[i] >='A' && str[i] <='Z')
        {
            int pos = str[i] - 65;
            c += enc[pos];
        }
        else
        {
            c += str[i];
        }
    }

    return c;
}

string decipher(string str,string enc)
{
    map <char,int> e;
      for(int i=0;i<enc.size();i++)
      {
          e[enc[i]]=i;
      }

      string d = "";
      for(int i=0;i<str.size();i++)
      {
          if (str[i] >='a' && str[i] <='z')
        {
            int pos = e[str[i]-32];
            d += plain[pos];
        }
        else if(str[i] >='A' && str[i] <='Z')
        {
            int pos = e[str[i]];
            d += plain[pos];
        }
        else
        {
            d += str[i];
        }
      }


      return d;
}


int main()
{
	
  
   cout<<"-----------------------------KEYWORD SERIAL IMPLEMENTATION-----------------------"<<endl;
   string encode="";
   //cin.get();
   string key;
   vector<string> s1;
   vector<string> encrypt;
   vector<string> decrypt;
   //string arr[50];
   cout<<"\nEnter key: ";
   cin>>key;
   cout<<"\nEnter the messages: "<<endl;
   string str;
   cin>>str;
   while(str!="-1")
   {
       arr.push_back(str);
       cin>>str;
   }
 

   cout<<arr.size()<<"\n";
   
   auto start = high_resolution_clock::now();
   string encoded=encoder(key,encode);
   
   
   for(long int i=0;i<arr.size()/2;i++)
   {
       encrypt.push_back(cipher(arr[i],encoded));
      // cout<<cipher(arr[i],encoded)<<endl;
   }
   //auto stop = high_resolution_clock::now();
   //auto duration_e = duration_cast<milliseconds>(stop-start);
   //auto start1 = high_resolution_clock::now();
   for(long int i=arr.size()/2+1;i<arr.size();i++)
   {
       decrypt.push_back(decipher(arr[i],encoded));
       //cout<<decipher(arr[i],encoded)<<endl;
   }
   auto stop1 = high_resolution_clock::now();
   auto duration_d = duration_cast<seconds>(stop1-start);
   cout<<duration_d.count()<<" s"<<endl;
   //cout<<endl;
   //cout<<"ENCRYPTED"<<endl;
   //cout<<endl;
   // for(long int i=0;i<encrypt.size();i++)
   // {
   //     cout<<encrypt[i]<<endl;
   // }
   // // cout<<endl;
   // // cout<<"DECRYPTED"<<endl;
   // // cout<<endl;
   // for(long int i=0;i<decrypt.size();i++)
   // {
   //     cout<<decrypt[i]<<endl;
   // }
   // cout<<"\nEncryption time: "<<duration_e.count()<<endl;
   // cout<<"Decryption Time: "<<duration_d.count()<<endl;
   // cout<<"Average Time: "<<(duration_e.count()+duration_d.count())/2;
    return 0;
}
