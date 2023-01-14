#include<bits/stdc++.h>
using namespace std;


string plaintext, key,pt,ct;


string del_sp(string pt){
    string plaintext;
    for(int i = 0; i<pt.size(); i++)
        if(pt[i] != ' ') plaintext += pt[i];
    return plaintext;
}

string add_spc(string pt, string ct){
    string ciphertext;
    for(int i = 0, j = 0; i<pt.size(); i++){
        if(pt[i] == ' ')
            ciphertext += ' ';
        else{
            ciphertext += ct[j];
            j++;
        }
    }
    return ciphertext;
}

string encodeMessage()
{
    int age_ache[26] = {0};
    string encoded;
    for(int i = 0; i<key.size(); i++){
        int val = key[i] - 'a';
        if(age_ache[val] == 0){
            encoded += key[i];
            age_ache[val] = 1;
        }
    }
    for(char c = 'a'; c<='z'; c++){
        int val = c - 'a';
        if(age_ache[val] == 0){
            age_ache[val] = 1;
            encoded += c;
        }
    }
    return encoded;
}

string encryptMessage(string encoded)
{
    string cipher ;

    plaintext=del_sp(plaintext);

	for(int i = 0; i<plaintext.size(); i++){
        int val = plaintext[i] - 'a';
        cipher += encoded[val];

	}
	cipher=add_spc(pt,cipher);
	//cout<<cipher<<" Cipher1 "<<endl;
	return cipher;
}



int main()
{
    plaintext = "zombie here";
    pt=plaintext;
    key ="sec ret";
    //cin >> plaintext >> sh;

    plaintext=del_sp(plaintext);
    key=del_sp(key);

     string plain;
    for(int i=0;i<26;i++)
        plain +=char(i+97);
    cout<<"Plain : "  <<plain<<endl;

    string encoded = encodeMessage();
    string ciphertext = encryptMessage(encoded);
    cout <<"Cipher :"<< encoded << '\n';
    cout <<"Plaintext : "<< plaintext << '\n';
    cout << "Ciphertext :"<< ciphertext << '\n';




///Decryption Process

      string decipher ;

      ct=ciphertext;


    //  ciphertext=del_sp(ciphertext);

     int  k=0;
	for(int i = 0; i<ciphertext.size(); i++){
         for(k=0;k<26;k++){
        if(ciphertext[i]==encoded[k]){

        decipher += plain[k];
        }

        }
	}
	decipher=add_spc(ct,decipher);

     cout << "Decrypted Plaintext :"<<decipher << '\n';


    return 0;
}



///  Alhamdulillah...


