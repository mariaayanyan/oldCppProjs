// DES algorithm (final).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;   
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned char uch;
class DES
{
	bitset<56>key; 
	string plaintext; //plaintext (binary)
	string hexademical;
	map<char, int>hex_map;
	void read(); //reads all the tables
	void get_key(ull); //ull to bitset<56>
	void encrypt();
	bitset<48> expand(bitset<32> &);
	bitset<32>f(bitset<32> &,int);
	void divide();//c0 d0, calls next_key()
	void next_key();//c1 d1,c2 d2, ... , c16 d16
	string hex_to_bin(char); //hex to binary
	int pc1[56],pc2[48],ip[64],e[48],s[8][4][16],p[32],ip1[64];//tables
	bitset<28>cd[2][16];
	bitset<48>keys[16];
	string ciphertext;
	void check_key(string key);

	public:
	string get_ciphertext();
	DES(string, string);

};
bitset<48> DES::expand(bitset<32>&r)
{
	bitset<48>ans;
	for (int i = 0; i < 48; ++i)
		ans[i] = r[e[i]];

	return ans;
}
bitset<32> DES::f(bitset<32>&r, int ind)
{
	bitset<32>ans,cur_ans;
	bitset<48>temp = expand(r);
	temp ^= keys[ind];

	for (int i = 0; i < 8; ++i)
	{
		bitset<2>rw;
		bitset<4>cl;
		
		rw[1] = temp[6 * i]; rw[0] = temp[6 * i + 5];
		for (int j = 0; j < 4; ++j)
			cl[3-j] = temp[6 * i + j + 1];
	
		ul row = rw.to_ulong(), col=cl.to_ulong();
		int var = s[i][row][col];
		
		for (int j = 0; j < 4; ++j)
		{
			cur_ans[4 * (i+1) - j - 1] = (var & 1);
			var /= 2;
		}
	}

	for (int i = 0; i < 32; ++i)
		ans[i] = cur_ans[p[i]];

	return ans;
}
string DES::get_ciphertext()
{
	string txt;
	int len = ciphertext.length() / 4;
	for (int i = 0; i < len; ++i)
	{
		int var = 0,cur_pow=8;
		for (int j = 0; j < 4; ++j)
		{
			var += cur_pow * (ciphertext[4 * i + j] == '1');
			cur_pow /= 2;
		}
		txt += hexademical[var];
	}

	return txt;
}
void DES::encrypt()
{
	cout <<endl<< setw(75)<<"STEP 1. Stexcum enq 16 entabanali, yuraqanchyur@ 48 bit" << endl << endl; 

	cout << setw(12) << "PC-1"; cout<<setw(50)<<"64 bit key->56 bit key" << endl;
		for (int i = 0; i < 56; ++i)
		{
			cout << setw(2) << pc1[i] << " ";
			if (!((i + 1) % 7))cout << endl;
		}
		cout << endl;

		cout << "K+ = ";
		for (int i = 0; i < 56; ++i)cout << key[i];
		cout <<" (56 bit)"<< endl << endl;


	divide();

	for (int i = 0; i < 16; ++i)
	{
		cout << "C" << i + 1 <<((i<9)? "  = " : " = ");
		for (int j = 0; j < 28; ++j) cout << cd[0][i][j];
		cout<< endl;
		cout << "D" << i + 1 << ((i < 9) ? "  = " : " = ");
		for (int j = 0; j < 28; ++j) cout << cd[1][i][j];
		cout<< endl;
		cout << endl;
	}
	cout << endl;
	
	cout << setw(10) << "PC-2"; cout<<setw(50)<<"(Cn + Dn->Kn dzevapoxutyan axyusak)" << endl;
	for (int i = 0; i < 48; ++i)
	{
		cout << setw(2) << pc2[i] << " ";
		if (!((i + 1) % 6))cout << endl;
	}
	cout << endl<<endl;
	cout << "Mijankyal banaliner:" << endl<<endl;
	for (int k = 0; k < 16; ++k)
	{
		for (int i = 0; i < 48; ++i)
		{
			int ind = pc2[i];
			if (ind < 28)
			{
				keys[k][i] = cd[0][k][ind];
				continue;
			}
			keys[k][i] = cd[1][k][ind - 28];
		}
		cout << "K" << k + 1 << ((k < 9) ? "  = " : " = ");
		for (int j = 0; j < 48; ++j) cout << keys[k][j];
		cout<<endl<< endl;
	}
	cout << endl;
	
	cout << endl << setw(75) << "STEP 2. 64 bitanoc blockeri cackagrum" << endl << endl;

	cout << setw(11) << "IP"<<endl;
	for (int i = 0; i < 64; ++i)
	{
		cout << setw(2) << ip[i] << " ";
		if (!((i + 1) % 8))cout << endl;
	}
	cout << endl << endl;
	
	cout << "IP-ic stanum enq L0 ev R0 (arajin ev verjin 32 bitery)." << endl;
	cout << "16 iteracianeri ardyunqum aj ev dzax maseri popoxutyun:" << endl;
	cout << "L[n]=R[n-1]" << endl;
	cout << "R[n]=L[n-1] + f(R[n-1],K[n])                      (+ -> XOR)" << endl<<endl;


	cout << endl << setw(65) << "f funkciayi ashxatanqy" << endl << endl;

	cout << setw(10) << "E" << setw(50) << "(32 bit -> 48 bit)" << endl;
	for (int i = 0; i < 48; ++i)
	{
		cout << setw(2) << e[i] << " ";
		if (!((i + 1) % 6))cout << endl;
	}
	cout << endl<<endl;

	cout << "Kn + E(Rn - 1) = B1B2B3B4B5B6B7B8                       (B[i] -> 6 bitanoc block)" << endl;
	cout << "Bolor blockeri hamar hashvum enq S1(B1)S2(B2)S3(B3)S4(B4)S5(B5)S6(B6)S7(B7)S8(B8)" << endl<<endl;

	cout << setw(25) << "S1" << endl;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 16; ++j)
			cout << setw(2) << s[0][i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;



	int q = plaintext.length() / 64;
	for (int n = 0; n < q; ++n)
	{
		bitset<32>l, r,cur_l,cur_r;
		for (int i = 0; i < 32; ++i)
		{
			l[i] = (plaintext[64 * n + ip[i]] == '1');
			r[i] = (plaintext[64 * n + ip[i+32]] == '1');
		}
		
		for (int i = 0; i < 16; ++i)
		{
			cur_l = r;
			cur_r = l^f(r,i);

			r = cur_r; l = cur_l;
		}
		
		for (int i = 0; i < 64; ++i)
		{
			int temp=ip1[i];
			if (temp < 32)
			{
				ciphertext.push_back((r[temp] ? '1' : '0'));
				continue;
			}
			ciphertext.push_back((l[temp-32] ? '1' : '0'));
		}

	}
	
}
void DES::next_key()
{
	static int ind = 1;
	int iter[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

	vector<bool>temp[2];
	
	cd[0][ind] = cd[0][ind - 1];
	cd[1][ind] = cd[1][ind - 1];

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < iter[ind]; ++j)
			temp[i].push_back(cd[i][ind][j]);
			
	cd[0][ind] >>= iter[ind];
	cd[1][ind] >>= iter[ind];
	

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < iter[ind]; ++j)
			cd[i][ind][28-iter[ind]+j] = temp[i][j];

	++ind;
}
void DES::divide()
{
	bitset<28>c, d;
	for (int i = 0; i < 28; ++i)
	{
		cd[0][0][i] = key[i];
		cd[1][0][i] = key[28 + i];
	}
	
	cout << endl;
	cout << "C0  = ";
	for (int i = 0; i < 28; ++i)cout << cd[0][0][i];
	cout<< endl;
	cout << "D0  = "; for (int i = 0; i < 28; ++i)cout << cd[1][0][i];
	cout<< endl;
	cout << endl;

	bool temp = cd[0][0][0];
	cd[0][0] >>= 1;
	cd[0][0][27]= temp;

	temp = (cd[1][0] == 1);
	cd[1][0] >>= 1;
	cd[1][0][27] = temp;

	for (int i = 0; i < 15; ++i)
		next_key();

}
DES::DES(string txt,string k)
{
	read(); 

	hexademical = "0123456789ABCDEF";
	for (int i = 0; i < 16; ++i)
		hex_map[hexademical[i]] = i;

	transform(txt.begin(), txt.end(), txt.begin(), toupper);
	transform(k.begin(), k.end(), k.begin(), toupper);
	check_key(k);

	int len = (16- (txt.length() % 16))%16;
	for (int i = 0; i < len; ++i)
		txt += '0';

	len = txt.length();
	for (int i = 0; i < len; ++i)
		plaintext += hex_to_bin(txt[i]);

	ull K = stoull(k, nullptr, 16);
	get_key(K);
	encrypt();

}
void DES::get_key(ull k)
{
	bitset<64>temp(k);
	for (int i = 0; i < 56; ++i)
		key[i] = temp[63-pc1[i]];
	
}
void DES::read()
{
	ifstream in("pc1.txt");
	for (int i = 0; i < 56; ++i)
	{
		in >> pc1[i];
		--pc1[i];
	}
// DES algorithm (final).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned char uch;
class DES
{
	bitset<56>key; 
	string plaintext; //plaintext (binary)
	string hexademical;
	map<char, int>hex_map;
	void read(); //reads all the tables
	void get_key(ull); //ull to bitset<56>
	void encrypt();
	bitset<48> expand(bitset<32> &);
	bitset<32>f(bitset<32> &,int);
	void divide();//c0 d0, calls next_key()
	void next_key();//c1 d1,c2 d2, ... , c16 d16
	string hex_to_bin(char); //hex to binary
	int pc1[56],pc2[48],ip[64],e[48],s[8][4][16],p[32],ip1[64];//tables
	bitset<28>cd[2][16];
	bitset<48>keys[16];
	string ciphertext;
	void check_key(string key);

	public:
	string get_ciphertext();
	DES(string, string);

};
bitset<48> DES::expand(bitset<32>&r)
{
	bitset<48>ans;
	for (int i = 0; i < 48; ++i)
		ans[i] = r[e[i]];

	return ans;
}
bitset<32> DES::f(bitset<32>&r, int ind)
{
	bitset<32>ans,cur_ans;
	bitset<48>temp = expand(r);
	temp ^= keys[ind];

	for (int i = 0; i < 8; ++i)
	{
		bitset<2>rw;
		bitset<4>cl;
		
		rw[1] = temp[6 * i]; rw[0] = temp[6 * i + 5];
		for (int j = 0; j < 4; ++j)
			cl[3-j] = temp[6 * i + j + 1];
	
		ul row = rw.to_ulong(), col=cl.to_ulong();
		int var = s[i][row][col];
		
		for (int j = 0; j < 4; ++j)
		{
			cur_ans[4 * (i+1) - j - 1] = (var & 1);
			var /= 2;
		}
	}

	for (int i = 0; i < 32; ++i)
		ans[i] = cur_ans[p[i]];

	return ans;
}
string DES::get_ciphertext()
{
	string txt;
	int len = ciphertext.length() / 4;
	for (int i = 0; i < len; ++i)
	{
		int var = 0,cur_pow=8;
		for (int j = 0; j < 4; ++j)
		{
			var += cur_pow * (ciphertext[4 * i + j] == '1');
			cur_pow /= 2;
		}
		txt += hexademical[var];
	}

	return txt;
}
void DES::encrypt()
{
	cout <<endl<< setw(75)<<"STEP 1. Stexcum enq 16 entabanali, yuraqanchyur@ 48 bit" << endl << endl; 

	cout << setw(12) << "PC-1"; cout<<setw(50)<<"64 bit key->56 bit key" << endl;
		for (int i = 0; i < 56; ++i)
		{
			cout << setw(2) << pc1[i] << " ";
			if (!((i + 1) % 7))cout << endl;
		}
		cout << endl;

		cout << "K+ = ";
		for (int i = 0; i < 56; ++i)cout << key[i];
		cout <<" (56 bit)"<< endl << endl;


	divide();

	for (int i = 0; i < 16; ++i)
	{
		cout << "C" << i + 1 <<((i<9)? "  = " : " = ");
		for (int j = 0; j < 28; ++j) cout << cd[0][i][j];
		cout<< endl;
		cout << "D" << i + 1 << ((i < 9) ? "  = " : " = ");
		for (int j = 0; j < 28; ++j) cout << cd[1][i][j];
		cout<< endl;
		cout << endl;
	}
	cout << endl;
	
	cout << setw(10) << "PC-2"; cout<<setw(50)<<"(Cn + Dn->Kn dzevapoxutyan axyusak)" << endl;
	for (int i = 0; i < 48; ++i)
	{
		cout << setw(2) << pc2[i] << " ";
		if (!((i + 1) % 6))cout << endl;
	}
	cout << endl<<endl;
	cout << "Mijankyal banaliner:" << endl<<endl;
	for (int k = 0; k < 16; ++k)
	{
		for (int i = 0; i < 48; ++i)
		{
			int ind = pc2[i];
			if (ind < 28)
			{
				keys[k][i] = cd[0][k][ind];
				continue;
			}
			keys[k][i] = cd[1][k][ind - 28];
		}
		cout << "K" << k + 1 << ((k < 9) ? "  = " : " = ");
		for (int j = 0; j < 48; ++j) cout << keys[k][j];
		cout<<endl<< endl;
	}
	cout << endl;
	
	cout << endl << setw(75) << "STEP 2. 64 bitanoc blockeri cackagrum" << endl << endl;

	cout << setw(11) << "IP"<<endl;
	for (int i = 0; i < 64; ++i)
	{
		cout << setw(2) << ip[i] << " ";
		if (!((i + 1) % 8))cout << endl;
	}
	cout << endl << endl;
	
	cout << "IP-ic stanum enq L0 ev R0 (arajin ev verjin 32 bitery)." << endl;
	cout << "16 iteracianeri ardyunqum aj ev dzax maseri popoxutyun:" << endl;
	cout << "L[n]=R[n-1]" << endl;
	cout << "R[n]=L[n-1] + f(R[n-1],K[n])                      (+ -> XOR)" << endl<<endl;


	cout << endl << setw(65) << "f funkciayi ashxatanqy" << endl << endl;

	cout << setw(10) << "E" << setw(50) << "(32 bit -> 48 bit)" << endl;
	for (int i = 0; i < 48; ++i)
	{
		cout << setw(2) << e[i] << " ";
		if (!((i + 1) % 6))cout << endl;
	}
	cout << endl<<endl;

	cout << "Kn + E(Rn - 1) = B1B2B3B4B5B6B7B8                       (B[i] -> 6 bitanoc block)" << endl;
	cout << "Bolor blockeri hamar hashvum enq S1(B1)S2(B2)S3(B3)S4(B4)S5(B5)S6(B6)S7(B7)S8(B8)" << endl<<endl;

	cout << setw(25) << "S1" << endl;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 16; ++j)
			cout << setw(2) << s[0][i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;



	int q = plaintext.length() / 64;
	for (int n = 0; n < q; ++n)
	{
		bitset<32>l, r,cur_l,cur_r;
		for (int i = 0; i < 32; ++i)
		{
			l[i] = (plaintext[64 * n + ip[i]] == '1');
			r[i] = (plaintext[64 * n + ip[i+32]] == '1');
		}
		
		for (int i = 0; i < 16; ++i)
		{
			cur_l = r;
			cur_r = l^f(r,i);

			r = cur_r; l = cur_l;
		}
		
		for (int i = 0; i < 64; ++i)
		{
			int temp=ip1[i];
			if (temp < 32)
			{
				ciphertext.push_back((r[temp] ? '1' : '0'));
				continue;
			}
			ciphertext.push_back((l[temp-32] ? '1' : '0'));
		}

	}
	
}
void DES::next_key()
{
	static int ind = 1;
	int iter[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

	vector<bool>temp[2];
	
	cd[0][ind] = cd[0][ind - 1];
	cd[1][ind] = cd[1][ind - 1];

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < iter[ind]; ++j)
			temp[i].push_back(cd[i][ind][j]);
			
	cd[0][ind] >>= iter[ind];
	cd[1][ind] >>= iter[ind];
	

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < iter[ind]; ++j)
			cd[i][ind][28-iter[ind]+j] = temp[i][j];

	++ind;
}
void DES::divide()
{
	bitset<28>c, d;
	for (int i = 0; i < 28; ++i)
	{
		cd[0][0][i] = key[i];
		cd[1][0][i] = key[28 + i];
	}
	
	cout << endl;
	cout << "C0  = ";
	for (int i = 0; i < 28; ++i)cout << cd[0][0][i];
	cout<< endl;
	cout << "D0  = "; for (int i = 0; i < 28; ++i)cout << cd[1][0][i];
	cout<< endl;
	cout << endl;

	bool temp = cd[0][0][0];
	cd[0][0] >>= 1;
	cd[0][0][27]= temp;

	temp = (cd[1][0] == 1);
	cd[1][0] >>= 1;
	cd[1][0][27] = temp;

	for (int i = 0; i < 15; ++i)
		next_key();

}
DES::DES(string txt,string k)
{
	read(); 

	hexademical = "0123456789ABCDEF";
	for (int i = 0; i < 16; ++i)
		hex_map[hexademical[i]] = i;

	transform(txt.begin(), txt.end(), txt.begin(), toupper);
	transform(k.begin(), k.end(), k.begin(), toupper);
	check_key(k);

	int len = (16- (txt.length() % 16))%16;
	for (int i = 0; i < len; ++i)
		txt += '0';

	len = txt.length();
	for (int i = 0; i < len; ++i)
		plaintext += hex_to_bin(txt[i]);

	ull K = stoull(k, nullptr, 16);
	get_key(K);
	encrypt();

}
void DES::get_key(ull k)
{
	bitset<64>temp(k);
	for (int i = 0; i < 56; ++i)
		key[i] = temp[63-pc1[i]];
	
}
void DES::read()
{
	ifstream in("pc1.txt");
	for (int i = 0; i < 56; ++i)
	{
		in >> pc1[i];
		--pc1[i];
	}
	in.close();

	in.open("pc2.txt");
	for (int i = 0; i < 48; ++i)
	{
		in >> pc2[i];
		--pc2[i];
	}
	in.close();

	in.open("ip.txt");
	for (int i = 0; i < 64; ++i)
	{
		in >> ip[i];
		--ip[i];
	}
	in.close();

	in.open("e.txt");
	for (int i = 0; i < 48; ++i)
	{
		in >> e[i];
		--e[i];
	}
	in.close();

	in.open("s.txt");
	for (int n = 0; n < 8; ++n)
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 16; ++j)
				in >> s[n][i][j];
			
	in.close();

	in.open("p.txt");
	for (int i = 0; i < 32; ++i)
	{
		in >> p[i];
		--p[i];
	}
	in.close();

	in.open("ip1.txt");
	for (int i = 0; i < 64; ++i)
	{
		in >> ip1[i];
		--ip1[i];
	}
	in.close();

}
string DES::hex_to_bin(char a)
{
	string ans;
	int num = hex_map[a];

	for (int i = 0; i < 4; ++i)
	{
		ans += (num & 1) ? '1' : '0';
		num /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
string text_to_hex(string s)
{
	ostringstream ans;
	for (int i = 0; i < (int)s.length(); ++i)
		ans << setw(2) << setfill('0') << hex << uppercase << int(s[i]);

	return ans.str();
}
string hex_to_text(string s)
{
	string ans;
	for (int i = 0; i < s.length(); i += 2)
	{
		string temp; temp += s[i]; temp += s[i + 1];
		int t = stoi(temp, nullptr, 16);
		ans += char(t);
	}
	return ans;
}
void DES::check_key(string key)
{
	bool WrongSizeOfKey = (key.length() == 16);
	
	if (!WrongSizeOfKey)
	{
		cout << endl << "Wrong size of key." << endl << "Expected: 16" << endl << "Found: " << key.length() << endl;
		exit(0);
	}
		assert(WrongSizeOfKey);

	bool InvalidKey = true;
	
	for (int i = 0; i < 16 && InvalidKey; ++i)
		if (hex_map.find(key[i]) == hex_map.end())
			InvalidKey = false;

	if (!InvalidKey)
	{
		cout << endl << "Invalid key." << endl << "Hexademical key should only contain symbols 0123456789ABCDEF (uppercase or lowercase)" << endl;
		exit(0);
	}

	assert(InvalidKey);
}
int _tmain(int argc, _TCHAR* argv[])
{
	string text;// = "0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF";// = "123948083"; 
	cout << "DES" << endl;
	bool first = true;
	while (true)
	{
		cout <<endl<< "1. Encryption" << endl << "2. Decryption" << endl<< "3. End session"<<endl;
		int num;

		do
		{
			cin >> num;
		} while (num != 1 && num != 2 && num != 3);
		if (num == 3)break;

			if (num == 1)
			{
				cout << "1. English text input" << endl << "2. Hexademical text input" << endl;
				int t;
				do
				{
					cin >> t;
				} while (t != 1 && t != 2);

				cin.ignore();
				cout << "Enter the text: ";
				getline(cin, text);

				if (t == 1)
				{
					text = text_to_hex(text);
					text += "0D0A";
					cout << "Hexademical text: " << text << endl;
				}
				ofstream out("result.txt");
	
				string key;
				cout << "Enter the hexademical key: ";
				//cin >> hex >> key; 
				cin >> key;
				
				if (first)
				{
					out << text << endl;
					out << uppercase << key<<endl;
				}


				DES des(text, key);
				text = des.get_ciphertext();
				cout << "Cackagrvac text (16akan): " << text << endl;
				cout << "Cackagrvac text: " << hex_to_text(text) << endl;
				if (first)
				{
					out << text;
					first = false;
				}
				out.close();
				continue;
			}

			ifstream in("result.txt");
			string ct, k;
			in >> text >> k >> ct;
			in.close();
			cout << "Hexademical ciphertext: " << hex_to_text(ct) << endl;;
			cout << "Ciphertext: "<<ct<<endl;
			cout << "Hexademical key: " << uppercase << k << endl;
			cout << "Hexademical plaintext: " << text << endl;
			cout << "Plaintext: " << hex_to_text(text) << endl;
					

	}

	


	return 0;
}
// DES algorithm (final).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned char uch;
class DES
{
	bitset<56>key; 
	string plaintext; //plaintext (binary)
	string hexademical;
	map<char, int>hex_map;
	void read(); //reads all the tables
	void get_key(ull); //ull to bitset<56>
	void encrypt();
	bitset<48> expand(bitset<32> &);
	bitset<32>f(bitset<32> &,int);
	void divide();//c0 d0, calls next_key()
	void next_key();//c1 d1,c2 d2, ... , c16 d16
	string hex_to_bin(char); //hex to binary
	int pc1[56],pc2[48],ip[64],e[48],s[8][4][16],p[32],ip1[64];//tables
	bitset<28>cd[2][16];
	bitset<48>keys[16];
	string ciphertext;
	void check_key(string key);

	public:
	string get_ciphertext();
	DES(string, string);

};
bitset<48> DES::expand(bitset<32>&r)
{
	bitset<48>ans;
	for (int i = 0; i < 48; ++i)
		ans[i] = r[e[i]];

	return ans;
}
bitset<32> DES::f(bitset<32>&r, int ind)
{
	bitset<32>ans,cur_ans;
	bitset<48>temp = expand(r);
	temp ^= keys[ind];

	for (int i = 0; i < 8; ++i)
	{
		bitset<2>rw;
		bitset<4>cl;
		
		rw[1] = temp[6 * i]; rw[0] = temp[6 * i + 5];
		for (int j = 0; j < 4; ++j)
			cl[3-j] = temp[6 * i + j + 1];
	
		ul row = rw.to_ulong(), col=cl.to_ulong();
		int var = s[i][row][col];
		
		for (int j = 0; j < 4; ++j)
		{
			cur_ans[4 * (i+1) - j - 1] = (var & 1);
			var /= 2;
		}
	}

	for (int i = 0; i < 32; ++i)
		ans[i] = cur_ans[p[i]];

	return ans;
}
string DES::get_ciphertext()
{
	string txt;
	int len = ciphertext.length() / 4;
	for (int i = 0; i < len; ++i)
	{
		int var = 0,cur_pow=8;
		for (int j = 0; j < 4; ++j)
		{
			var += cur_pow * (ciphertext[4 * i + j] == '1');
			cur_pow /= 2;
		}
		txt += hexademical[var];
	}

	return txt;
}
void DES::encrypt()
{
	cout <<endl<< setw(75)<<"STEP 1. Stexcum enq 16 entabanali, yuraqanchyur@ 48 bit" << endl << endl; 

	cout << setw(12) << "PC-1"; cout<<setw(50)<<"64 bit key->56 bit key" << endl;
		for (int i = 0; i < 56; ++i)
		{
			cout << setw(2) << pc1[i] << " ";
			if (!((i + 1) % 7))cout << endl;
		}
		cout << endl;

		cout << "K+ = ";
		for (int i = 0; i < 56; ++i)cout << key[i];
		cout <<" (56 bit)"<< endl << endl;


	divide();

	for (int i = 0; i < 16; ++i)
	{
		cout << "C" << i + 1 <<((i<9)? "  = " : " = ");
		for (int j = 0; j < 28; ++j) cout << cd[0][i][j];
		cout<< endl;
		cout << "D" << i + 1 << ((i < 9) ? "  = " : " = ");
		for (int j = 0; j < 28; ++j) cout << cd[1][i][j];
		cout<< endl;
		cout << endl;
	}
	cout << endl;
	
	cout << setw(10) << "PC-2"; cout<<setw(50)<<"(Cn + Dn->Kn dzevapoxutyan axyusak)" << endl;
	for (int i = 0; i < 48; ++i)
	{
		cout << setw(2) << pc2[i] << " ";
		if (!((i + 1) % 6))cout << endl;
	}
	cout << endl<<endl;
	cout << "Mijankyal banaliner:" << endl<<endl;
	for (int k = 0; k < 16; ++k)
	{
		for (int i = 0; i < 48; ++i)
		{
			int ind = pc2[i];
			if (ind < 28)
			{
				keys[k][i] = cd[0][k][ind];
				continue;
			}
			keys[k][i] = cd[1][k][ind - 28];
		}
		cout << "K" << k + 1 << ((k < 9) ? "  = " : " = ");
		for (int j = 0; j < 48; ++j) cout << keys[k][j];
		cout<<endl<< endl;
	}
	cout << endl;
	
	cout << endl << setw(75) << "STEP 2. 64 bitanoc blockeri cackagrum" << endl << endl;

	cout << setw(11) << "IP"<<endl;
	for (int i = 0; i < 64; ++i)
	{
		cout << setw(2) << ip[i] << " ";
		if (!((i + 1) % 8))cout << endl;
	}
	cout << endl << endl;
	
	cout << "IP-ic stanum enq L0 ev R0 (arajin ev verjin 32 bitery)." << endl;
	cout << "16 iteracianeri ardyunqum aj ev dzax maseri popoxutyun:" << endl;
	cout << "L[n]=R[n-1]" << endl;
	cout << "R[n]=L[n-1] + f(R[n-1],K[n])                      (+ -> XOR)" << endl<<endl;


	cout << endl << setw(65) << "f funkciayi ashxatanqy" << endl << endl;

	cout << setw(10) << "E" << setw(50) << "(32 bit -> 48 bit)" << endl;
	for (int i = 0; i < 48; ++i)
	{
		cout << setw(2) << e[i] << " ";
		if (!((i + 1) % 6))cout << endl;
	}
	cout << endl<<endl;

	cout << "Kn + E(Rn - 1) = B1B2B3B4B5B6B7B8                       (B[i] -> 6 bitanoc block)" << endl;
	cout << "Bolor blockeri hamar hashvum enq S1(B1)S2(B2)S3(B3)S4(B4)S5(B5)S6(B6)S7(B7)S8(B8)" << endl<<endl;

	cout << setw(25) << "S1" << endl;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 16; ++j)
			cout << setw(2) << s[0][i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;



	int q = plaintext.length() / 64;
	for (int n = 0; n < q; ++n)
	{
		bitset<32>l, r,cur_l,cur_r;
		for (int i = 0; i < 32; ++i)
		{
			l[i] = (plaintext[64 * n + ip[i]] == '1');
			r[i] = (plaintext[64 * n + ip[i+32]] == '1');
		}
		
		for (int i = 0; i < 16; ++i)
		{
			cur_l = r;
			cur_r = l^f(r,i);

			r = cur_r; l = cur_l;
		}
		
		for (int i = 0; i < 64; ++i)
		{
			int temp=ip1[i];
			if (temp < 32)
			{
				ciphertext.push_back((r[temp] ? '1' : '0'));
				continue;
			}
			ciphertext.push_back((l[temp-32] ? '1' : '0'));
		}

	}
	
}
void DES::next_key()
{
	static int ind = 1;
	int iter[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

	vector<bool>temp[2];
	
	cd[0][ind] = cd[0][ind - 1];
	cd[1][ind] = cd[1][ind - 1];

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < iter[ind]; ++j)
			temp[i].push_back(cd[i][ind][j]);
			
	cd[0][ind] >>= iter[ind];
	cd[1][ind] >>= iter[ind];
	

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < iter[ind]; ++j)
			cd[i][ind][28-iter[ind]+j] = temp[i][j];

	++ind;
}
void DES::divide()
{
	bitset<28>c, d;
	for (int i = 0; i < 28; ++i)
	{
		cd[0][0][i] = key[i];
		cd[1][0][i] = key[28 + i];
	}
	
	cout << endl;
	cout << "C0  = ";
	for (int i = 0; i < 28; ++i)cout << cd[0][0][i];
	cout<< endl;
	cout << "D0  = "; for (int i = 0; i < 28; ++i)cout << cd[1][0][i];
	cout<< endl;
	cout << endl;

	bool temp = cd[0][0][0];
	cd[0][0] >>= 1;
	cd[0][0][27]= temp;

	temp = (cd[1][0] == 1);
	cd[1][0] >>= 1;
	cd[1][0][27] = temp;

	for (int i = 0; i < 15; ++i)
		next_key();

}
DES::DES(string txt,string k)
{
	read(); 

	hexademical = "0123456789ABCDEF";
	for (int i = 0; i < 16; ++i)
		hex_map[hexademical[i]] = i;

	transform(txt.begin(), txt.end(), txt.begin(), toupper);
	transform(k.begin(), k.end(), k.begin(), toupper);
	check_key(k);

	int len = (16- (txt.length() % 16))%16;
	for (int i = 0; i < len; ++i)
		txt += '0';

	len = txt.length();
	for (int i = 0; i < len; ++i)
		plaintext += hex_to_bin(txt[i]);

	ull K = stoull(k, nullptr, 16);
	get_key(K);
	encrypt();

}
void DES::get_key(ull k)
{
	bitset<64>temp(k);
	for (int i = 0; i < 56; ++i)
		key[i] = temp[63-pc1[i]];
	
}
void DES::read()
{
	ifstream in("pc1.txt");
	for (int i = 0; i < 56; ++i)
	{
		in >> pc1[i];
		--pc1[i];
	}
	in.close();

	in.open("pc2.txt");
	for (int i = 0; i < 48; ++i)
	{
		in >> pc2[i];
		--pc2[i];
	}
	in.close();

	in.open("ip.txt");
	for (int i = 0; i < 64; ++i)
	{
		in >> ip[i];
		--ip[i];
	}
	in.close();

	in.open("e.txt");
	for (int i = 0; i < 48; ++i)
	{
		in >> e[i];
		--e[i];
	}
	in.close();

	in.open("s.txt");
	for (int n = 0; n < 8; ++n)
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 16; ++j)
				in >> s[n][i][j];
			
	in.close();

	in.open("p.txt");
	for (int i = 0; i < 32; ++i)
	{
		in >> p[i];
		--p[i];
	}
	in.close();

	in.open("ip1.txt");
	for (int i = 0; i < 64; ++i)
	{
		in >> ip1[i];
		--ip1[i];
	}
	in.close();

}
string DES::hex_to_bin(char a)
{
	string ans;
	int num = hex_map[a];

	for (int i = 0; i < 4; ++i)
	{
		ans += (num & 1) ? '1' : '0';
		num /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
string text_to_hex(string s)
{
	ostringstream ans;
	for (int i = 0; i < (int)s.length(); ++i)
		ans << setw(2) << setfill('0') << hex << uppercase << int(s[i]);

	return ans.str();
}
string hex_to_text(string s)
{
	string ans;
	for (int i = 0; i < s.length(); i += 2)
	{
		string temp; temp += s[i]; temp += s[i + 1];
		int t = stoi(temp, nullptr, 16);
		ans += char(t);
	}
	return ans;
}
void DES::check_key(string key)
{
	bool WrongSizeOfKey = (key.length() == 16);
	
	if (!WrongSizeOfKey)
	{
		cout << endl << "Wrong size of key." << endl << "Expected: 16" << endl << "Found: " << key.length() << endl;
		exit(0);
	}
		assert(WrongSizeOfKey);

	bool InvalidKey = true;
	
	for (int i = 0; i < 16 && InvalidKey; ++i)
		if (hex_map.find(key[i]) == hex_map.end())
			InvalidKey = false;

	if (!InvalidKey)
	{
		cout << endl << "Invalid key." << endl << "Hexademical key should only contain symbols 0123456789ABCDEF (uppercase or lowercase)" << endl;
		exit(0);
	}

	assert(InvalidKey);
}
int _tmain(int argc, _TCHAR* argv[])
{
	string text;// = "0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF";// = "123948083"; 
	cout << "DES" << endl;
	bool first = true;
	while (true)
	{
		cout <<endl<< "1. Encryption" << endl << "2. Decryption" << endl<< "3. End session"<<endl;
		int num;

		do
		{
			cin >> num;
		} while (num != 1 && num != 2 && num != 3);
		if (num == 3)break;

			if (num == 1)
			{
				cout << "1. English text input" << endl << "2. Hexademical text input" << endl;
				int t;
				do
				{
					cin >> t;
				} while (t != 1 && t != 2);

				cin.ignore();
				cout << "Enter the text: ";
				getline(cin, text);

				if (t == 1)
				{
					text = text_to_hex(text);
					text += "0D0A";
					cout << "Hexademical text: " << text << endl;
				}
				ofstream out("result.txt");
	
				string key;
				cout << "Enter the hexademical key: ";
				//cin >> hex >> key; 
				cin >> key;
				
				if (first)
				{
					out << text << endl;
					out << uppercase << key<<endl;
				}


				DES des(text, key);
				text = des.get_ciphertext();
				cout << "Cackagrvac text (16akan): " << text << endl;
				cout << "Cackagrvac text: " << hex_to_text(text) << endl;
				if (first)
				{
					out << text;
					first = false;
				}
				out.close();
				continue;
			}

			ifstream in("result.txt");
			string ct, k;
			in >> text >> k >> ct;
			in.close();
			cout << "Hexademical ciphertext: " << hex_to_text(ct) << endl;;
			cout << "Ciphertext: "<<ct<<endl;
			cout << "Hexademical key: " << uppercase << k << endl;
			cout << "Hexademical plaintext: " << text << endl;
			cout << "Plaintext: " << hex_to_text(text) << endl;
					

	}

	


	return 0;
}
	in.close();

	in.open("pc2.txt");
	for (int i = 0; i < 48; ++i)
	{
		in >> pc2[i];
		--pc2[i];
	}
	in.close();

	in.open("ip.txt");
	for (int i = 0; i < 64; ++i)
	{
		in >> ip[i];
		--ip[i];
	}
	in.close();

	in.open("e.txt");
	for (int i = 0; i < 48; ++i)
	{
		in >> e[i];
		--e[i];
	}
	in.close();

	in.open("s.txt");
	for (int n = 0; n < 8; ++n)
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 16; ++j)
				in >> s[n][i][j];
			
	in.close();

	in.open("p.txt");
	for (int i = 0; i < 32; ++i)
	{
		in >> p[i];
		--p[i];
	}
	in.close();

	in.open("ip1.txt");
	for (int i = 0; i < 64; ++i)
	{
		in >> ip1[i];
		--ip1[i];
	}
	in.close();

}
string DES::hex_to_bin(char a)
{
	string ans;
	int num = hex_map[a];

	for (int i = 0; i < 4; ++i)
	{
		ans += (num & 1) ? '1' : '0';
		num /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
string text_to_hex(string s)
{
	ostringstream ans;
	for (int i = 0; i < (int)s.length(); ++i)
		ans << setw(2) << setfill('0') << hex << uppercase << int(s[i]);

	return ans.str();
}
string hex_to_text(string s)
{
	string ans;
	for (int i = 0; i < s.length(); i += 2)
	{
		string temp; temp += s[i]; temp += s[i + 1];
		int t = stoi(temp, nullptr, 16);
		ans += char(t);
	}
	return ans;
}
void DES::check_key(string key)
{
	bool WrongSizeOfKey = (key.length() == 16);
	
	if (!WrongSizeOfKey)
	{
		cout << endl << "Wrong size of key." << endl << "Expected: 16" << endl << "Found: " << key.length() << endl;
		exit(0);
	}
		assert(WrongSizeOfKey);

	bool InvalidKey = true;
	
	for (int i = 0; i < 16 && InvalidKey; ++i)
		if (hex_map.find(key[i]) == hex_map.end())
			InvalidKey = false;

	if (!InvalidKey)
	{
		cout << endl << "Invalid key." << endl << "Hexademical key should only contain symbols 0123456789ABCDEF (uppercase or lowercase)" << endl;
		exit(0);
	}

	assert(InvalidKey);
}
int _tmain(int argc, _TCHAR* argv[])
{
	string text;// = "0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF";// = "123948083"; 
	cout << "DES" << endl;
	bool first = true;
	while (true)
	{
		cout <<endl<< "1. Encryption" << endl << "2. Decryption" << endl<< "3. End session"<<endl;
		int num;

		do
		{
			cin >> num;
		} while (num != 1 && num != 2 && num != 3);
		if (num == 3)break;

			if (num == 1)
			{
				cout << "1. English text input" << endl << "2. Hexademical text input" << endl;
				int t;
				do
				{
					cin >> t;
				} while (t != 1 && t != 2);

				cin.ignore();
				cout << "Enter the text: ";
				getline(cin, text);

				if (t == 1)
				{
					text = text_to_hex(text);
					text += "0D0A";
					cout << "Hexademical text: " << text << endl;
				}
				ofstream out("result.txt");
	
				string key;
				cout << "Enter the hexademical key: ";
				//cin >> hex >> key; 
				cin >> key;
				
				if (first)
				{
					out << text << endl;
					out << uppercase << key<<endl;
				}


				DES des(text, key);
				text = des.get_ciphertext();
				cout << "Cackagrvac text (16akan): " << text << endl;
				cout << "Cackagrvac text: " << hex_to_text(text) << endl;
				if (first)
				{
					out << text;
					first = false;
				}
				out.close();
				continue;
			}

			ifstream in("result.txt");
			string ct, k;
			in >> text >> k >> ct;
			in.close();
			cout << "Hexademical ciphertext: " << hex_to_text(ct) << endl;;
			cout << "Ciphertext: "<<ct<<endl;
			cout << "Hexademical key: " << uppercase << k << endl;
			cout << "Hexademical plaintext: " << text << endl;
			cout << "Plaintext: " << hex_to_text(text) << endl;
					

	}

	


	return 0;
}
