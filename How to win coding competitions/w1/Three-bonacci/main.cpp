// This problem is about a funny extension of the well-known Fibonacci numbers, called 
// Three-bonacci numbers. We define them as follows:

// Ti = A0 if i=0; A1 if i=1; A2 if i=2; Ti−1+Ti−2−Ti−3 otherwise.

// We give you A0, A1, A2, and n. Your task is to calculate Tn.

// Input
// The input file contains one line with four integer numbers, A0, A1, A2, and n. 
// For these numbers, it holds that −10^3≤A0,A1,A2≤10^3 and 0≤n≤10^5.

// Output
// Output Tn in the first and only line of the output file.

// Example
// input.txt
// 1 2 3 4
// output.txt
// 5


#include <fstream>


class three_fib
{
    private:
        int a, b, c, n, result;
        
    public:
        three_fib(int a_, int b_, int c_, int n_) {
            a = a_;
            b = b_;
            c = c_;
            n = n_;
        }
        
        int processing() {
            if (n == 0)
                return a;
            else if (n == 1)
               return b;
            else if (n == 2)
                return c;
            else {
                for (int i = 0; i < n - 2; ++i) {
                    result = c + b - a;
                    a = b;
                    b = c;
                    c = result;
                }
                return result;
            }
        }
};


// рекурсивная реализация (не проходит по времени)
// int fib(int a, int b, int c, int n)
// {
    // if (n == 0)
        // return a;
    // else if (n == 1)
       // return b;
    // else if (n == 2)
        // return c;
    // else
        // return fib(a, b, c, n - 1) + fib(a, b, c, n - 2) - fib(a, b, c, n - 3);
// }


int main()
{
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    
    three_fib test(a, b, c, n);
    cout << test.processing() << std::endl;

    return 0;
}
