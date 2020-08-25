#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
bool pr(int x)
{  bool y;
	for(int i=1;i<x/2;i++)
	{
		if(x%i==0)
         y=false;
		else
		 y=true;
	}
return y;
}
using namespace std;
int main()
{
	int arr[10000];
	int n,prime=0,not_prime=0;
	cin>>n;
	for(int i=0;i<n;i++)
	   cin>>arr[i];
	for(int i=0;i<n;i++)
	{  if(pr)
	    prime++;
	   else
		   not_prime++;
	
	}

	cout<<prime<<" "<<not_prime<<endl;




system("pause");

return 0;

}