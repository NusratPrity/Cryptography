#include <bits/stdc++.h>
using namespace std;
#define SIZE 30
string plaintext, key, cipher_text, plain_text, ciphertext;
char keytable[5][5];
string plain,cipher,pt,ct,ptu;

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


void generateKeyTable()
{
	int i, j, k, flag = 0;
	string key_t = key;

	for(int i = 0; i<key_t.size();i++)
        if(key_t[i]=='j')
            key_t[i] = 'i';

	int achekina[26] = { 0 };


	for(int i = 0; i<5; i++)
        for(int j = 0; j<5; j++)
            keytable[i][j]='.';

	for(int i = 0, l = 0; i < 5 and l < key_t.size(); i++){
        for(int j = 0; j < 5 and l < key_t.size(); ){
            char c = key_t[l++];
            if(achekina[c-'a'] == 0){
                achekina[c-'a'] = 1;
                keytable[i][j] = c;
                j++;
            }
        }
	}

	char c = 'a';
	for(int i = 0; i<5; i++){
        for(int j = 0; j<5;){
            if(keytable[i][j] != '.'){
                j++;
                continue;
            }
            if(achekina[c-'a']==1 or c == 'j'){
                c++;
                continue;
            }
            achekina[c-'a'] = 1;
            keytable[i][j++] = c++;
        }
	}
	for(int i = 0; i<5; i++){
        for(int j = 0; j< 5 ; j++){
            cout << keytable[i][j] << ' ';
        }
        cout << '\n';
	}



}
int arr[4];

void search_for_index(char a, char b)
{
	if (a == 'j')
		a = 'i';
	if (b == 'j')
		b = 'i';

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			if (keytable[i][j] == a) {
				arr[0] = i;
				arr[1] = j;
			}
			else if (keytable[i][j] == b) {
				arr[2] = i;
				arr[3] = j;
			}
		}
	}
}
void encrypt(){

    cout<<"Plaintext: "<<plaintext<<endl;

    for (int i = 0; i < plaintext.size(); i += 2) {

        search_for_index( plaintext[i], plaintext[i + 1]);

        int x1 = arr[0], y1 = arr[1], x2 = arr[2], y2 = arr[3];

        if (x1 == x2) {
            cipher_text[i] = keytable[x1][(y1 + 1)%5];
            cipher_text[i + 1] = keytable[x2][(y2 + 1)%5];
        }
        else if (y1 == y2) {
            cipher_text[i] = keytable[(x1 + 1)%5][y1];
            cipher_text[i + 1] = keytable[(x2 + 1)%5][y2];
        }
        else {
            cipher_text[i] = keytable[x1][y2];
            cipher_text[i + 1] = keytable[x2][y1];
        }
        cipher+=cipher_text[i];
        cipher+=cipher_text[i+1];

        cout<<cipher_text[i]<<" "<<cipher_text[i+1]<<endl;
    }
    cout<<endl;
    cipher=add_spc(ptu,cipher);

    cout<<"CipherText :"<<cipher<<endl;
}


void decrypt(){
    ct=cipher;

    cipher=del_sp(cipher);


    for (int i = 0; i <cipher.size(); i += 2) {

        search_for_index(cipher[i], cipher[i + 1]);

        int x1 = arr[0], y1 = arr[1], x2 = arr[2], y2 = arr[3];

        if (x1 == x2) {
            plain_text[i] = keytable[x1][(((y1 - 1)%5+5)%5)];
            plain_text[i + 1] = keytable[x2][(((y2 - 1)%5+5)%5)];
        }
        else if (y1 == y2) {
            plain_text[i] = keytable[(((x1 - 1)%5+5)%5)][y1];
            plain_text[i + 1] = keytable[(((x2 - 1)%5+5)%5)][y2];
        }
        else {
            plain_text[i+1] = keytable[x2][y1];
            plain_text[i] = keytable[x1][y2];
        }
        plain+=plain_text[i];
        plain+=plain_text[i+1];
    }
    plain=add_spc(ct,plain);
    cout<<plain<<endl;
    plain.resize(ptu.size());
    cout<<"Decrypted Cipher Text :"<<plain<<endl;
}



// Driver code
int main()
{
	//cin >> key >> plaintext;

	// Key to be encrypted
	key = "monar chy";
	cout << "Key text: " << key << "\n";

	pt="instr ument";
	ptu=pt;

	pt=del_sp(pt);
	key=del_sp(key);

    //ciphertext = "gatlmzclrqtx";
	//cout << "Plain text: " << plaintext << "\n";
    int sz=pt.size();

    for(int i = 0; i<sz; i+=2){
        plaintext+=pt[i];

        if(i+1==sz) break;

        if(pt[i] != pt[i+1])
            plaintext+=pt[i+1];
        else{
            if(pt[i+1] == 'z')
                plaintext += 'x';
            else
                plaintext += 'z';
        }
    }

	if(plaintext.size()%2==1)
        plaintext+='z';
    cout<<plaintext<<endl;

	generateKeyTable();
	encrypt();

	///Decryption process


	decrypt();

	return 0;
}

// This code is contributed by aditya942003patil


