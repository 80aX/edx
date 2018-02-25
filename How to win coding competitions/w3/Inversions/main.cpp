// Inversions

// Input file:	input.txt
// Output file:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// Recall that an inversion in an sequence of numbers A is a situation when i<j, but Ai>Aj.

// Given a sequence of integers. Your task is to count the number of inversions in it.

// Hint: to make it faster, you may adapt the mergesort algorithm to solve this problem.

// Input
// The ﬁrst line of the input ﬁle contains an integer n(1<=n<=10^6) – the number of elements 
// in the sequence. The sequence itself follows in the second line. All numbers in this 
// sequence do not exceed 10^9 by the absolute value.

// Output
// Output the number of inversions in the ﬁrst and only line of the output ﬁle.

// Example
// input.txt
// 10
// 1 8 2 1 4 7 3 2 3 6
// output.txt
// 17


#include <fstream>


long long mergesort(int *a, int l, int r)
{
    if (l >= r)
        return 0;
    
    int m = (l + r) / 2;
    long long inv = 0;
    
    inv += mergesort(a, l, m);
    inv += mergesort(a, m + 1, r);
    
    int *buff = new int [r - l + 1];
    int j = 0, l_index = l, r_index = m + 1;
    
    while (l_index <= m && r_index <= r) {
        if (a[l_index] > a[r_index]) {
            buff[j++] = a[r_index++];
            inv += m - l_index + 1;
        } else
            buff[j++] = a[l_index++];
    }
    
    while (l_index <= m)
        buff[j++] = a[l_index++];
    while (r_index <= r)
        buff[j++] = a[r_index++];
    
    for (j = 0; j < r - l + 1; ++j)
        a[j + l] = buff[j];
    
    delete [] buff;
    
    return inv;
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
    
    fout << mergesort(array, 1, n) << '\n';
    
    delete [] array;
    
    return 0;
}
