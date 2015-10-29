#include <iostream> 	// Allows input output operations
using namespace std;

int main() {

	int N;
	cout << "N=";
	cin >> N;


	cout << endl;
	if(N<1 || N>26)
	{
		cout<<"INVALID INPUT"<<endl;
		return 1;
	}
	if(N==1)
	{
		cout<<'A'<<endl;
		return 0;
	}
	char a='A';

	/*---------------------------------------------*/
	// Add your code here for Q3

	for(int i=1;i<=N;i++)
	{
		cout<<a;
		a++;
	}
	a--;
	for(int i=1;i<=N-1;i++)
	{
		a--;
		cout<<a;

	}
	cout<<endl;
//	cout<<"I have printed first line"<<endl;
	for(int i=2;i<=N;i++)
	{
		a='A';
		for(int j=1;j<=(N-i+1);j++)
		{
			cout<<a;
			a++;
		}
		for(int j=1,m=2*i-3;j<=m && m>0;j++ )
		{
			cout<<" ";
		}
		for(int j=1,m=N-i+1;j<=m;j++)
		{
			a--;
			cout<<a;

		}
		cout<<endl;
	}
//	cout<<"I have printed half pyramid"<<endl;

	a='A';
	for(int i=1,m=N-1;i<=N-2;i++)
	{
		a='A';
		for(int j=1,l=i+1;j<=l;j++)
		{
			cout<<a;
			a++;
		}
		for(int j=1,l=2*N-(2*i)-3;j<=l;j++)
		{
			cout<<" ";
		}
		a--;
	//	cout<<"after spaces";
		for(int j=0,l=i+1;j<l;j++)
		{

			cout<<a;
			a--;
		}
		cout<<endl;
	}
	a='A';
	for(int i=1;i<=N;i++)
	{
		cout<<a;
		a++;
	}
	a--;
	for(int i=1;i<=N-1;i++)
	{
		a--;
		cout<<a;

	}
	cout<<endl;	// 
	/*---------------------------------------------*/

	return 0;
}
