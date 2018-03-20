// K-th ordered statistic

// You are given a sequence of n integers. Which of these numbers are k1-th, (k1 + 1)-st,
// ..., k2-th in this sequence when it is sorted?

// Input
// In the ﬁrst line of the input ﬁle there are three integers: , the sequence size, and k1 and k2,
// the interesting interval boundaries. (2 <= n <= 4 * 10^7, 1 <= k1 <= k2 <= n,k2-k1 < 200).

// The second line of the input ﬁle contains integers A, B, C, a1, a2, which do not exceed 10^9 by the 
// absolute value. You have to generate the input sequence elements, starting with the third 
// one, using the following expression: a(i) = A * a(i-2) + B * a(i-1) + C. All computations 
// should be performed in a 32-bit integer type, all overﬂows should be ignored.

// Please pay attention that an array of 4 ⋅ 10^7 32-bit integers takes 160 megabytes of memory!

// This problem is (most probably) impossible to solve in Python and PyPy, and the main 
// problem is the input sequence generation. To keep yourself sane, please consider using 
// other languages.

// Output
// In the ﬁrst and only line of the output ﬁle print the k1-th, (k1+1)-st, ..., k2-th in the sorted order
// numbers from the sequence a. Separate the numbers by single white spaces.

// Examples
// input.txt
// 5 3 4
// 2 3 5 1 2
// output.txt
// 13 48
// input.txt
// 5 3 4
// 200000 300000 5 1 2
// output.txt
// 2 800005

// In the second example, the sequence a is: [1, 2, 800005, -516268571, 1331571109]


#include <fstream>


int split(int *a, int l, int r)
{
    int x = a[(l + r) / 2];
    int l_index = l, r_index = r, buff;
    
    while (l_index <= r_index) {
        while (a[l_index] < x)
            l_index++;
        while (a[r_index] > x)
            r_index--;
            
        if (l_index <= r_index) {
            buff = a[l_index];
            a[l_index] = a[r_index];
            a[r_index] = buff;
            l_index++;
            r_index--;
        }
    }
    
    return l_index;
}


void quicksort(int *a, int l, int r, int k1, int k2)
{
    if (l == r || l > k2 || r < k1)
        return;
    
    int m = split(a, l, r);
    
    quicksort(a, l, m - 1, k1, k2);
    quicksort(a, m, r, k1, k2);
}


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int n, k1, k2, i;
    fin >> n >> k1 >> k2;
    int *a = new int [n + 1];
    
    int A, B, C;
    fin >> A >> B >> C >> a[1] >> a[2];
    
    for (i = 3; i <= n; ++i)
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    
    quicksort(a, 1, n, k1, k2);
    
    for (i = k1; i <= k2; ++i)
        fout << a[i] << ' ';
    fout << '\n';
    
    delete [] a;
    
    return 0;
}
