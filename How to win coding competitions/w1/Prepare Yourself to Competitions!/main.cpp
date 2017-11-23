// To successfully participate in programming competitions, you should prepare a lot. 
// This is very clear to young Jamie. So he decided to undertake a scientific point of view. 
// Jamie thinks that the preparation level is determined by a certain number, the ability to 
// solve problems, which accumulates every possible aspect of being ready to compete well.

// After reading some books on competitive programming, Jamie understood that there are two 
// ways to improve his skills: studying theory and practicing a lot. There are n days before 
// the next programming competition. Based on his biorhythm calendar, Jamie determined two 
// numbers for each of these days: ti is how much his ability to solve problems will improve 
// if he studies theory at the i-th day, and pi is how much it will improve if he practices 
// a lot at the i-th day. Every day should be entirely dedicated to either theory or practice. 
// Additionally, at least one of these days should be theoretical, and at least one should be 
// practical.

// Help Jamie construct such a timetable which increases his ability to solve problems to a 
// maximum possible value. You may assume that this value is equal to zero before preparation.

// Input
// The first line of the input file contains an integer n (2≤n≤100). The second line contains 
// n integers p1,p2,…,pn, separated by whitespace. The third line contains n integers t1,t2,…,tn, 
// separated by whitespace.

// All pi and ti are positive and do not exceed 1000.

// Output
// Output the maximum possible value of ability to solve problems, which Jamie can achieve in 
// n days. Pay attention to the fact that Jamie should spend at least one day for theory, and 
// at least one day for practicing.

// Examples

// input.txt
// 2
// 1 2
// 2 1
// output.txt
// 4

// input.txt
// 3
// 1 2 3
// 1 2 3
// output.txt
// 6


#include <fstream>
#include <stdlib.h> 


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int n = 0, flag = 0, result = 0;
    int *p_array, *t_array;
    
    fin >> n;
    
    p_array = new int[n];
    t_array = new int[n];
    
    for (int i = 0; i < n; ++i)
        fin >> p_array[i];
    
    for (int i = 0; i < n; ++i) {
        fin >> t_array[i];
        
        if (t_array[i] > p_array[i]) {
            result += t_array[i];
            flag++;
        } else {
            result += p_array[i];
        }
    }
    
    if (flag == n || flag == 0) {
        int diff = 1001;
        
        for (int i = 0; i < n; ++i) {
            if (abs(p_array[i] - t_array[i]) < diff)
                diff = abs(p_array[i] - t_array[i]);
        }
        result -= diff;
    }
    
    fout << result << std::endl;
    
    delete [] p_array;
    delete [] t_array;
    
    return 0;
}
