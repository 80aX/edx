// Anti-Quicksort

// For sorting integer sequences, the Quicksort algorithm is widely used.

// Although Quicksort is very fast on average, there exist integer sequences, which take 
// quite a long time to be sorted using this algorithm. We will measure the running time 
// of the algorithm by the number of comparisons where array elements participate (that is, 
// the total number of comparisons in the ﬁrst and the second while loop).

// Your task is to generate a test, which forces the given Quicksort implementation to perform 
// the maximum number of these comparisons.

// Input
// The ﬁrst line of the input ﬁle contains a single integer number n (1 <= n <= 10^6).

// Output
// Output a permutation of numbers from  to , which forces the given Quicksort implementation 
// to perform the maximum number of these comparisons (among all permutations of numbers from  
// to ). If there are several such permutations, print any of them.

// Example
// input.txt
// 3
// output.txt
// 1 3 2


#include <fstream>


void antiqucksort(int n, std::ofstream &fout)
{
    int *a = new int [n];
    a[0] = 1;
    a[1] = 2;
    
    int buff;
    
    for (int i = 2; i < n; ++i) {
        a[i] = i + 1;
        buff = a[i / 2];
        a[i / 2] = a[i];
        a[i] = buff;
    }
    
    for (int i = 0; i < n; i++)
        fout << a[i] << " ";
    fout << "\n";
    
    delete [] a;
}


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int n;
    fin >> n;
    
    if (n > 1)
        antiqucksort(n, fout);
    else
        fout << "1\n";
    
    return 0;
}
