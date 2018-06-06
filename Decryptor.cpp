
//############### RSA decoder ####################


#include<iostream>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<vector>

using namespace std;


int main()
{
    ifstream key("Castle.key");

    if(!key)
    {
        cerr << "Trouble with key file!\n";
        return(1);
    }

    int e, d, n;
    char dump;

    key >> e >> dump >> n >> d;
    key.close();

    char EncryptFile[256];

    cout << "Crypted file path: ";
    cin.getline(EncryptFile, 256);

    ifstream in(EncryptFile);
    if(!in)
    {
        cerr << "Trouble with input file!\n";
        return(1);
    }

    vector<int> buffer;
    int x;

    while(in >> x)
    {
        buffer.push_back(x);
    }

    in.close();

    char DecryptFile[256];

    cout << "Decrypt file path: ";
    cin.getline(DecryptFile, 256);

    ofstream out(DecryptFile);
    if(!out)
    {
        cerr << "Trouble with output file!\n";
        return(1);
    }

	int b = 301;
	int m;

	for(int j = 0; j < buffer.size(); j++)
	{
		m = 1;
		unsigned int i = 0;

		while(i < d)
		{
			m = m * buffer[j];
			m = m % n;
			i++;
		}
		m = m - b;
		out << static_cast<char>(m);
		b += 1;
	}

    out.close();

    cout << "\tDecryption complete!\n";
    return(0);
}
