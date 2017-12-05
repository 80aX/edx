// Generate Tests!

// Input file:	input.txt
// Output file:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// When you solve programming problems, it is possible to get one of the Wrong Answer, Runtime 
// Error or Time imit Exceeded outcomes on a test with a quite big number.

// It often happens that the mistake is too deep, and you cannot check it by small tests you 
// can write by hand. It can also happen that it is too diﬃcult to come up with such a test 
// at all. In this case, test generators can help. A test generator is a small program which 
// creates various tests for the problem you are solving.

// Consider a problem, for which the program should print exactly one number. A maximal test 
// is a test, the answer for which is the maximum possible for this problem. Certain typical
// mistakes in solutions can be found by using maximal tests. Often, a maximal test may be generated 
// by a small test generator.

// Assume you are solving a simple problem: among the numbers from 2 to N, find the number x, 
// such that it has the maximum possible number of divisors (the numbers 1≤y≤x such that xmody=0), 
// and print the number of divisors of x.

// Please find the number of maximal tests for the constraint 2≤N≤K.

// Input
// The first line contains a single integer number K (2≤K≤10^7).

// Output
// Output the number of maximal tests for this problem with the constraint K.

// Examples
// input.txt
// 11
// output.txt
// 6
// input.txt
// 12
// output.txt
// 1

// Note
// In the first example, all the numbers from 6 to 11, inclusively, are maximal tests, because no 
// number from an interval [2; 11] has more than four divisors. In the second example, the single 
// possible maximal test is 12.


#include <fstream>
#include <math.h>


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int k = 0, i, j, m, count;
    int max_value = 0, max_index = 0;
    int *mod_array;
    
    fin >> k;
    mod_array = new int[k + 1];
    mod_array[1] = 1;
    
    for (i = 2; i <= k; ++i) {
        
        mod_array[i] = 0;
        
        for (j = 2; j <= 19; ++j) {
            if (i % j == 0) {
                
                m = i / j;
                count = 1;
                
                while (m % j == 0) {
                    m = m / j;
                    count++;
                }
                
                mod_array[i] = (count + 1) * mod_array[m];
                break;
            }
        }
        
        if (mod_array[i] == 0)
            mod_array[i] = 2;
        else if (mod_array[i] > max_value) {
            max_value = mod_array[i];
            max_index = i;
        }
    }
    
    fout << k - max_index + 1 << std::endl;
    
    delete [] mod_array;
    
    return 0;
}
