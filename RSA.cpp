#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	//key generation
	double p ,q;
	cout<<"enter two prime numbers\n";
	cin>>p>>q;
	double n = p*q;
	double phi = (p-1)*(q-1);
	double e = 2;
	while(e<phi)
	{
		if(__gcd((int)e,(int)phi) == 1)
			break;
		e++;
	}

	double d = 1/e;
	d = fmod(d,phi);
	cout<<"public key:"<<e<<"\n";
	cout<<"private key:"<<d<<"\n";
	//input of msg
	double msg;
	cout<<"enter the message:";
	cin>>msg;

	//encryption
	double c = pow(msg,e);

	double c1 = fmod(c,n);
	cout<<"encrypted message is:"<<c1<<"\n";

	//decryption
	double m = pow(c,d);
	m = fmod(m,n);
	cout<<"decrypted message is:"<<m<<"\n";

	return 0;
}
