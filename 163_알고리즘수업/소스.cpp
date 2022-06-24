#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int DP[50];
int cnt = 0;

int fib(int n) 
{
    cnt++;
    if (n == 1 || n == 2)
    {
        return 1;
    }
        
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) 
{
    int count = 1;

    DP[1] = 1;
    DP[2] = 1;
    
    for (int i = 3; i < n; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
        count++;
    }

    return count;
}

int main()
{
	int n;
	cin >> n;

    int answer1 = fib(n);
    int answer2 = fibonacci(n);

    cout << answer1 << " " << answer2 << endl;
}