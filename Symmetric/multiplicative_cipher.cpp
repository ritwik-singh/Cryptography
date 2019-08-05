#include <bits/stdc++.h>
using namespace std;

# define MOD 26

int extended_euclid(int b)
{
	int r1,r2,q1,q2,t1,t2,r,t,q;
	r1 = 26;
	r2 = b;
	t1 = 0;
	t2 = 1;
	while(r2>0)
	{
		q = r1/r2;
		r = r1  - q*r2;
		r1 = r2;
		r2 = r;

		t = t1 - q*t2;
		t1 = t2;
		t2 = t;
	}	

	return t1;
}


string encryption(string text,int s)
{
	string result = "";

	for(int i=0;i<text.length();i++)
	{
		if(isupper(text[i]))
			result += char((int(text[i]-65)*s)%MOD + 65);
		else
			result += char((int(text[i]-97)*s)%MOD + 97);
	}

	return result;
}


string decryption(string text,int s)
{
	string result = "";
	s = 26 +  s;
	for(int i=0;i<text.length();i++)
	{
		if(isupper(text[i]))
		{
			int x = int(text[i] - 65);
			result += char((x*s)%MOD + 65);
		}	
		else
		{	
			int x = int(text[i]-97);
			result += char((x*s)%MOD+97);
		}	
	}

	return result;

}



int main()
{
	string s;
	
	cout<<"enter the message to be sent\n";
	cin>>s;
	
	string result = encryption(s,5);
	cout<<result<<"\n";
	int key = extended_euclid(5);
	cout<<decryption(result,key)<<"\n";




	return 0;
}
