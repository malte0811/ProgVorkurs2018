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
	return sol;
}

int bell_it(int n)
{
	int *bell_n = new int[n+1];

	bell_n[0] = 1;

	for(int k = 1; k <= n; ++k)
	{
		bell_n[k] = 0;

		for(int i = 0; i < k; ++i)
		{
			bell_n[k] += binomial(k-1, i) * bell_n[i];
		}
	}

	int tmp = bell_n[n];
	delete [] bell_n;
	return tmp;
}

int main () {
	std::cout << bell_it(3) << std::endl;
}
