// Win the Competition!

// Bad is the team which doesn't dream of winning a competition! However, in order to win, 
// it is necessary to understand what you can do, distribute your forces the right way, and 
// implement your ideas precisely.

// The team of three, the Dream Team, can do this rather well. In particular, since the very 
// beginning of the competition it manages to understand, for every proposed problem, how much 
// time it will take them to solve it. This way, they are able to efficiently distribute their 
// time during the competition. But it is not enough for a victory. It is necessary to solve the 
// maximum possible number of problems.

// Write a program that, given the time Dream Team needs to solve every proposed problem, can 
// determine what is the maximum possible number of problems they can solve in 300 minutes, 
// which is the timespan of the ACM ICPC World Finals.

// Input
// The first line of the input file contains an integer number n (1≤n≤15) – the number of 
// proposed problems. The second line contains n integer numbers t1,t2,…,tn, where ti is the 
// time, in seconds, which is required to solve the i-th problem. All ti are positive and don't 
// exceed 10^5. Please recall that one minute consists of 60 seconds.

// Output
// Output the single number – the maximum number of problems, which Dream Team can solve.

// Examples
// input.txt
// 2
// 60 18000
// output.txt
// 1
// input.txt
// 3
// 10000 9000 8000
// output.txt
// 2


#include <fstream>


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int n = 0, time_limit = 18000, time_counter, problems_counter, problems_max = 0;
    int *time_array;
    
    fin >> n;
    time_array = new int [n];
    
    for (int i = 0; i < n; ++i)
        fin >> time_array[i];
    
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            
            time_counter = 0;
            problems_counter = 0;
            
            for (int k = j; k < n; ++k) {
                if (time_counter + time_array[k] <= time_limit) {
                    time_counter += time_array[k];
                    problems_counter++;
                }
            }
            
            if (problems_max < problems_counter)
                problems_max = problems_counter;
        }
    }
    
    fout << problems_max << std::endl;
    
    delete [] time_array;
    
    return 0;
}
