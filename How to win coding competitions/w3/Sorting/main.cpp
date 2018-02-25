// Sorting

// Input file:	input.txt
// Output file:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// Given a sequence of integer numbers. Your task is to sort it in a non-decreasing order using 
// the mergesort algorithm.

// In order to persuade us that you really use the mergesort algorithm, we ask you, after 
// performing a merge of a certain interval, to print the endpoint indices and endpoint values 
// of this interval.

// Input
// In the ﬁrst line of the input ﬁle there is an integer n(1<=n<=2*10^5), the number of elements in the 
// sequence. The second line contains the sequence itself:  integer numbers not exceeding 10^9  
// by their absolute value.

// Output
// The output ﬁle consists of several lines.

// In the last line of the output ﬁle print the sequence after sorting. Separate the numbers 
// by single white spaces.

// All the previous lines should describe the results of merges, one per line. Every such line 
// should contain four numbers: I(f), I(l), V(f), V(l), where I(f) is the starting index of the 
// just-merged interval, I(l) is its ending index, V(f)  is the value of the ﬁrst element of the 
// interval, V(l)  is the value of the last element. Indices start with one, that is, 1<=I(f)<=I(l)<=n

// As the interval of length one is sorted by definition, you are allowed to omit merge records 
// when I(f) = I(l).

// If you print I(f), I(l), X, Y, this means you have just merged a subsequence which corresponds 
// to the [I(f), I(l)] subsequence of the original sequence. In your particular implementation, 
// the real indices for the beginning and ending of this subsequence may vary, but we nevertheless 
// ask you to use this numbering scheme.

// The correctness of the sorting scenario which you printed will be performed by a special 
// checker program. Every correct mergesort, which splits a subsequence into two smaller 
// subsequences (not necessary equal!), will be accepted if it manages to perform sorting 
// within time and memory limits.

// Example
// input.txt
// 10
// 1 8 2 1 4 7 3 2 3 6
// output.txt
// 1 2 1 8
// 3 4 1 2
// 1 4 1 8
// 5 6 4 7
// 1 6 1 8
// 7 8 2 3
// 9 10 3 6
// 7 10 2 6
// 1 10 1 8
// 1 1 2 2 3 3 4 6 7 8


#include <fstream>


void mergesort(int *a, int l, int r, std::ofstream &fout)
{
    if (l >= r)
        return;
    
    int m = (l + r) / 2;
    
    mergesort(a, l, m, fout);
    mergesort(a, m + 1, r, fout);
    
    int *buff = new int [r - l + 1];
    int j = 0, l_index = l, r_index = m + 1;
    
    while (l_index <= m && r_index <= r) {
        if (a[l_index] > a[r_index])
            buff[j++] = a[r_index++];
        else
            buff[j++] = a[l_index++];
    }
    
    while (l_index <= m)
        buff[j++] = a[l_index++];
    while (r_index <= r)
        buff[j++] = a[r_index++];
    
    for (j = 0; j < r - l + 1; ++j)
        a[j + l] = buff[j];
    
    fout << l << ' ' << r << ' ' << a[l] << ' ' << a[r] << '\n';
    
    delete [] buff;
}


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int n, i;
    fin >> n;
    int *array = new int [n + 1];
    
    for (i = 1; i <= n; ++i)
        fin >> array[i];
    
    mergesort(array, 1, n, fout);
    
    for (i = 1; i <= n; ++i)
        fout << array[i] << ' ';
    fout << '\n';
    
    delete [] array;
    
    return 0;
}
