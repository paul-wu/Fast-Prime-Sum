#include<stdio.h>
#include<math.h>
#include<time.h>

#define TRIM(a) ((a)>r)?(a)=2*r - n/(a) + 1:(a)=(a);

int main()
{
	int start = clock();
	long long n = 1000000000,r;
	r = (int)sqrt((double)n);
	long long V[100000],S[100000],k; // where V is the array of index, and S[i] denotes sum of primes less than i
	for(k = 0; k < r + 1; k++){
		V[k] = k;
		S[k] = (k*(k+1))/2 - 1;
	}
	for(; k < 2*r + 1;k++){
		V[k] = n/(2*r - k + 1);
		S[k] = (V[k]*(V[k]+1))/2 - 1;
	}
	for(long long p = 2; p < r + 1; p++){
		if(S[p]>S[p-1]){ // this condition satifise only when p is prime
			long long sp = S[p-1],p2 = p*p;
			for(long long j = k-1; j > 1; j--){
				if(V[j] < p2)break;
				long long a = V[j], b = a/p;
				TRIM(a)TRIM(b) // makes the indices correct
				S[a] -= p*(S[b] - sp); // sieve out the sum of composite numbers in S[a] wich divided by p
			} 
		}
	}
	printf("%lld\n",S[2*r]);
	int end1 = clock();
	printf("Total time is: %lf ms\n",(double)(end1 - start)/1000);
	return 0;
} 

/*
Compiled in Windows 7 with gcc:

24739512092254535
Total time is: 1.680000 ms

The time complexity is approximate to O(n^{3/4}/log(n))
*/
