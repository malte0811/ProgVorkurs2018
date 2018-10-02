#include <iostream>

int binomial(int n, int k)
{
	int sol = 1;
	for(int i = 1; i <= k; ++i)
	{
		sol *= (n-i+1);
		sol /= (i);
	}
	return sol;
}

int bell(int n)
{
	if(n <= 0) return 1;

	int sol=0;
	for(int k=0; k<n; ++k)
	{
		sol += binomial(n-1,k) * bell(k);
	}
}

int main () {}
