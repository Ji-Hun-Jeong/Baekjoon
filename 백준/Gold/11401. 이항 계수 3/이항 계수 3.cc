#include <iostream>
using namespace std;
int n, k;
long long nk1 = 1, kk = 1, half = 1;
const long long mod = 1000000007;
long long f(int p)
{
    if (0 == p)
        return 1;
    if (1 == p % 2)
        return kk * f(p - 1) % mod;
    else
    {
        half = f(p / 2);
        return  half * half % mod;
    }
}
int main()
{
    cin >> n >> k;
    for (int i = n; i >= n - k + 1; --i)
    {
        nk1 = (nk1 * i) % mod;
    }
    for (int i = 1; i <= k; ++i)
    {
        kk = (kk * i) % mod;
    }
    kk = f(mod - 2);
    cout << (nk1 * kk) % mod;
}