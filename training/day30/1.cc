// https://editor.csdn.net/md?not_checkout=1&spm=1015.2103.3001.8066&articleId=149979801

#include <iostream>
using namespace std;

bool isPrime(long long x) 
{
    if(x < 2) return false;
    for(long long i = 2; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        long long a, b;
        cin >> a >> b;
        cout << (isPrime(a * b) ? "YES" : "NO") << endl;
    }
    return 0;
}