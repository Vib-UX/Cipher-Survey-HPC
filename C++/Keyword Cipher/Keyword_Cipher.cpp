#include <bits/stdc++.h>
#include <omp.h>
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

string cipherPara(string str,string enc)
{
    string c= "";
    #pragma omp parallel for
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

string decipherPara(string str,string enc)
{
      map <char,int> e;
      for(int i=0;i<enc.size();i++)
      {
          e[enc[i]]=i;
      }

      string d = "";
      #pragma omp parallel for
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
    cout<<"-----------------------KEYWORD CIPHER---------------------------"<<endl;
    char ch;
    do
    {
        int choice;
        cout<<"1.Encrypt"<<endl;
        cout<<"2.Decrypt"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {cin.get();
            string encode = "";
            string key,message;
            cout<<"\nEnter the key: ";
            getline(cin,key);
            cout<<"\nEnter the message to encrypt: ";
            getline(cin,message);
            for(int i=0;i<message.length();i++)
            {
                if(isupper(message[i]))
                    putchar(tolower(message[i]));
            }
            remove(message.begin(),message.end(),' ');
            string encoded = encoder(key,encode);
            auto start = high_resolution_clock::now();
            cout<<"\ncipher text: "<<cipher(message,encoded);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop-start);
            cout<<"\nTime taken: "<<duration.count()<<" ms"<<endl;
            auto start1 = high_resolution_clock::now();
            cout<<"\ncipher text: "<<cipherPara(message,encoded);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1-start1);
            cout<<"\nTime taken: "<<duration1.count()<<" ms"<<endl;
            break;}

        case 2:
            {cin.get();
            string encode = "";
            string key,message;
            cout<<"\nEnter the key: ";
            getline(cin,key);
            cout<<"\nEnter the message to decrypt: ";
            getline(cin,message);
            for(int i=0;i<message.length();i++)
            {
                if(isupper(message[i]))
                    putchar(tolower(message[i]));
            }
            remove(message.begin(),message.end(),' ');
            string encoded = encoder(key,encode);
            auto start = high_resolution_clock::now();
            cout<<"\nplain text: "<<decipher(message,encoded);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop-start);
            cout<<"\nTime taken: "<<duration.count()<<" ms"<<endl;
            auto start1 = high_resolution_clock::now();
            cout<<"\nplain text: "<<decipherPara(message,encoded);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1-start1);
            cout<<"\nTime taken: "<<duration1.count()<<" ms"<<endl;

            break;}

        default: cout<<"\nInvalid choice. Try Again.";
        }
        cout<<"\nEnter more(y/n): ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');

    return 0;
}
