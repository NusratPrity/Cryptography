#include<bits/stdc++.h>
using namespace std;


int main()
{
    string plaintext = "Nusrat Jahan Prity";/// i
    string key = "ter", extendedkey;/// j

    //cin >> plaintext >> key;
    string ciphertext;

    int sze = plaintext.size();
    //return 0;
    while(extendedkey.size() < sze)
        extendedkey += key;



    extendedkey.resize(sze);

    cout << plaintext << '\n'; /// i
    cout << extendedkey << '\n'; /// j
    /// string plaintext = "dept of ice";/// i
    /// string key = "terterterter", key_2;/// j

    for(int i = 0, j = 0; i < sze ; i++){
        if(plaintext[i] != ' '){

                char ch=plaintext[i];
                int shift;


                        if(extendedkey[i]>='A' and extendedkey[i]<='Z')
                            shift=extendedkey[i]-'A';
                        else
                            shift=extendedkey[i]-'a';

                 if(ch>='A' and ch<='Z'){

                        int val1 = plaintext[i]-'A';

                        ciphertext += char(((val1 + shift) % 26) + 'A');
                        j++;
                 }
                 else if (ch>='a' and ch<='z'){


                                int val1 = plaintext[i]-'a';

                        ciphertext += char(((val1 + shift) % 26) + 'a');
                        j++;

                 }

        }
        else
            ciphertext += ' ';
    }

    cout << "CipherText :"<<ciphertext << '\n';
    string decipher;
      for(int i = 0, j = 0; i < sze ; i++){
           char ch=plaintext[i];
                int shift;


                        if(extendedkey[i]>='A' and extendedkey[i]<='Z')
                            shift=extendedkey[i]-'A';
                        else
                            shift=extendedkey[i]-'a';


        if(ciphertext[i] != ' '){

               if(ch>='A' and ch<='Z'){
                    int deval1 = ciphertext[i]-'A';

                    int val=(deval1-shift);
                    if(val<0)
                        val=val+26;
                    decipher += char(((val) % 26) + 'A');
                    j++;
               }
                else if (ch>='a' and ch<='z'){

                    int deval1 = ciphertext[i]-'a';

                    int val=(deval1-shift);
                    if(val<0)
                        val=val+26;
                    decipher += char(((val) % 26) + 'a');
                    j++;

                }

        }
        else
            decipher += ' ';
    }

     cout << "Decrypted PlainText :"<<decipher << '\n';

    return 0;
}



///  Alhamdulillah...

