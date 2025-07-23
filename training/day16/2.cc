// https://www.nowcoder.com/questionTerminal/99fa7be28d5f4a9d9aa3c98a6a5b559a

#include <iostream>
using namespace std;

int a, b;
int res;

bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

bool check(int x)
{
    int N, numb[10];
    for (N = 0; x; N++)
    {
        numb[N] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            if (numb[i] != 0 && isPrime(numb[i] * 10 + numb[j]))
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (check(i))
        {
            res++;
        }
    }
    if (res == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << res << endl;
    }
    return 0;
}