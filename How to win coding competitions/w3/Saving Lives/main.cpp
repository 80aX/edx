// Saving Lives

// Input file:	input.txt
// Output file:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// Dr. Garin is going to a remote village to save some lives. He has a suitcase which can 
// accomodate at most W units of medicine. However, different types of medicine have different 
// efficiency. In total, he has N different types of medicine. A single unit of the i-th type 
// can save Ai lives. However, the supply of each medicine is limited: the doctor has only Bi 
// units of the i-th type of medicine.

// How many lives can the doctor save?

// Input
// The first line of the input file contains N(1<=N<=10^5), the number of different types of medicine. 
// The following N lines contain descriptions of these types. Each such line contains two integers,
// Ai and Bi (1<=Ai,Bi<=100).

// The last line contains W (1<=W<=10^9).

// Output
// Output how many lives can the doctor save.

// Examples
// input.txt
// 2
// 2 7
// 5 3
// 8
// output.txt
// 25


#include <fstream>


class medicine
{
    private:
        int efficienty, quantity;
        
    public:
        medicine() {
            efficienty = 0;
            quantity = 0;
        }
        
        medicine(int e, int q) {
            efficienty = e;
            quantity = q;
        }
        
        ~medicine() {
            efficienty = 0;
            quantity = 0;
        }
        
        int get_efficienty() {
            return efficienty;
        }
        
        int get_quantity() {
            return quantity;
        }
        
        bool operator==(const medicine& right) {
            return efficienty == right.efficienty;
        }
        
        bool operator>(const medicine& right) {
            return efficienty <= right.efficienty;
        }
        
        bool operator>=(const medicine& right) {
            return (*this == right) || (*this > right);
        }
         
        bool operator<(const medicine& right) {
            return !(*this >= right);
        }
         
        bool operator<=(const medicine& right) {
            return !(*this > right);
        }
        
        medicine& operator=(const medicine& unit) {
            efficienty = unit.efficienty;
            quantity = unit.quantity;
            return *this;
        }
};


void mergesort(medicine *a, int l, int r)
{
    if (l >= r)
        return;
    
    int m = (l + r) / 2;
    
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    
    medicine *buff = new medicine [r - l + 1];
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
    
    delete [] buff;
}


int whattocollect(medicine *a, int n, int w)
{
    int result = 0;
    
    for (int i = 0; i < n && w > 0; ++i) {
        if (w < a[i].get_quantity()) {
            result += w * a[i].get_efficienty();
            w = 0;
        } else {
            result += a[i].get_quantity() * a[i].get_efficienty();
            w -= a[i].get_quantity();
        }
    }
    
    return result;
}


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int n, i, e, q, w;
    fin >> n;
    medicine *array = new medicine [n];
    
    for (i = 0; i < n; ++i) {
        fin >> e >> q;
        array[i] = medicine(e, q);
    }
    
    mergesort(array, 0, n - 1);
    
    fin >> w;
    fout << whattocollect(array, n, w) << '\n';
    
    delete [] array;
    
    return 0;
}
