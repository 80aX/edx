// Given two integer numbers, A and B, output A+B.

// Input
// The input file contains one line with two integer numbers, A and B (−10^9≤A,B≤10^9), 
// separated by one whitespace.

// Output
// Output A+B in the first and only line of the output file.

// Example
// input.txt
// 23 11
// output.txt
// 34


#include <fstream>

int main()
{
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    
    int a, b = 0;
    cin >> a >> b;
    cout << a + b << std::endl;
    
    return 0;
}
