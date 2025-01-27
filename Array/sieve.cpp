#include<iostream>
#include<vector>
using namespace std;

// SIEVE OF ERATOSTHENES
// FIND ALL PRIME NUMBERS UP TO N - TC=O(N*LOG(LOGN)), SC=O(N)

// Steps:
// 1. Initialize a vector `prime` of size `n + 1` with all elements set to true.
//    - This will track whether each number is prime (true) or not (false).
// 2. Set `prime[0]` and `prime[1]` to false because 0 and 1 are not prime numbers.
// 3. Iterate over numbers from 2 up to the square root of `n`:
// a. If the current number `i` is marked as prime:
// i. Iterate from `i * i` to `n`, marking multiples of `i` as not prime (false).
//    - This is done by setting `prime[j] = false` for every multiple `j` of `i`.
// 4. After marking non-prime numbers, iterate through the `prime` vector:
// a. Print numbers that are still marked as prime.

void primesieve(int n){
    long long count = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (long long i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (long long j = i * i; j < n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"enter ending number : ";
    cin>>n;
    primesieve(n);
}

// PRIME FACTORIZATION USING SIEVE - TC=O(N*LOG(LOGN)), SC=O(N)
//  Steps:
//  1. **Initialize `spf` Array**:
//     - Create an array `spf` where `spf[i]` will store the smallest prime factor of `i`.
//     - Set each number `i` as its own smallest prime factor initially (`spf[i] = i`).
//
//  2. **Fill Smallest Prime Factors**:
//     - Iterate through numbers from 2 to `n`.
//     - For each number `i` that is still set as its own smallest prime factor, mark `i` as a prime number.
//     - Update all multiples of `i` to have `i` as their smallest prime factor, if they have not been updated yet.
//
//  3. **Factorize the Number `n`**:
//     - Use the `spf` array to find and print the smallest prime factor of `n`.
//     - Repeatedly divide `n` by its smallest prime factor until `n` becomes 1.

void primefactor(int n){
    int spf[n+1]={0};
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
}
int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;
    primefactor(n);
}