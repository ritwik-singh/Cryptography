#include <bits/stdc++.h>
using namespace std;

# define MOD 26

string encryption(string text,int s)
{
	string result = "";

	for(int i=0;i<text.length();i++)
	{
		if(isupper(text[i]))
			result += char(int(text[i]+s-65)%MOD + 65);
		else
			result += char(int(text[i]+s-97)%MOD + 97);
	}

	return result;
}


string decryption(string text,int s)
{
	string result = "";
	for(int i=0;i<text.length();i++)
	{
		if(isupper(text[i]))
		{
			int x = int(text[i]-s-65);
			result += char((x)%MOD +65);
		}	
		else
		{	
			int x = int(text[i]-s-97);
			result += char(( x)%MOD + 97);
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

	cout<<decryption(result,5)<<"\n";




	return 0;
}
