// Given two integer numbers, A and B, output A+B^2.

// Input
// The input ﬁle contains one line with two integer numbers, A and B (−10^9≤A,B≤10^9), 
// separated by one whitespace.

// Output
// Output A+B^2 in the first and only line of the output file.

// Example
// input.txt
// 23 11
// output.txt
// 144


#include <fstream>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    long long a, b = 0;
    fin >> a >> b;
    fout << a + b * b << std::endl;
    
    return 0;
}
