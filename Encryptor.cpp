
//############### RSA ####################
/*
* Algorithm RSA:
*   1)Randomize two prime numbers (p & q)
*   2)Find their modulo (n = q * p)
*   3)Compute λ(n) = lcm(λ(p), λ(q)) = lcm(p − 1, q − 1)
*   4)Choose an integer e such that 1 < e < λ(n) and gcd(e, λ(n)) = 1; i.e., e and λ(n) are coprime.
*   5)Determine d as d ≡ e − 1 (mod λ(n)); i.e., d is the modular multiplicative inverse of e (mod λ(n))
*   6)Couple {e, n} - common key
*   7)Couple {d, n} - secret key
*/

#include<iostream>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<vector>

using namespace std;

/*
* Next function found the immediate prime number to "n"
*/
int Prime(int n)
{
	int *arr = new int [n], k, j;
	memset(arr, 0, sizeof(int) * n);
	for(int i = 1; (3 * i + 1) < n; i++)
	{
		for(j = 1; ((k = (i + j + 2 * i * j)) < n) && (j <= i); j++)
        {
            arr[k] = 1;
        }
	}

	for(int i = n - 1; i >= 1; i--)
    {
		    if(arr[i] == 0)
		{
			return (2 * i + 1);
			break;
		}
		delete [] arr;
    }
}

/*
* Next function realize the Euclid algorithm.
* It found the greatest common divisor for two numbers.
*/

int GCD(int a, int b)
{
    int c;

    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return(abs(a));
}

int main()
{
    char SourceFile[256];
    char EncryptionFile[256];

    cout << "Source file: ";
    cin.getline(SourceFile, 256);

    cout << endl;

    cout << "Encryption file: ";
    cin.getline(EncryptionFile, 256);

    ifstream in(SourceFile);
    if(!in)
    {
        cerr << "There are some trouble with your input file!\n";
        return(1);
    }

    vector<char> buffer;
    char ch;

    while((ch = in.get()) != EOF)
    {
        buffer.push_back(ch);
    }

    in.close();


    ofstream out(EncryptionFile);
    if(!out)
    {
        cerr << "There are some trouble with your output file!\n";
        return(1);
    }

    srand(time(NULL));

    int p = Prime(rand()%99 + 1);
    int q = Prime(rand()%99 + 1);
    int n = p * q;
    int d, d_prime;

    do{
        d = Prime(rand()%99 + 1);
        d_prime = GCD(d, ((p - 1) * (q - 1)));

    }while(d_prime != 1);


    int e = 0, e_prime;
    do{
        e += 1;
        e_prime = ((e * d) % ((p - 1) * (q - 1)));

    }while(e_prime != 1);

    ofstream key("Castle.key");
    key << e << "," << n << endl;
    key << d << "," << n;

    key.close();
    /////////////////////////////////////////////////

	int b = 301, c;

	for(std::vector<char>::iterator x = buffer.begin() ; x != buffer.end(); ++x)
    {
		c = 1;
		unsigned int i = 0;
		int ASCIIcode = (static_cast<int>(*x)) + b;

		while(i < e)
		{
			c = c * ASCIIcode;
			c = c % n;
			i++;
		}
		out << c << endl;
		b += 1;
	}

    out.close();

    cout << "\tComplete!\n";

    return(0);
}
