#include <iostream>
#include <cmath>
using namespace std;

int main(void )
{
	int n = 2;
	long long int power=0;
	long long int copy_n = n ;
	while(n!=1)
	{
		if(n!=0)
		{
			int dig = copy_n % 10;
			copy_n/=10;
			power+=pow(dig,2);
			cout<<n<<"  co"<<copy_n<<"  pow"<<power<<endl;
		}
		else
		{
			copy_n = power;
			n = power;
			power = 0;
		}
	}
	cout<<"da"<<endl;
}