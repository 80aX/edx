// Bracket Sequence

// Input file:	input.txt
// Output file:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// A sequence A of characters “(”, “)”, “[”, “]” is called a correct bracket sequence, if one 
// of the following is true:

// A is empty.
// The ﬁrst character of A is “(”, and A contains a character “)”, such that A=(B)C, where B and C 
// are correct bracket sequences.
// The ﬁrst character of A is “[”, and A contains a character “]”, such that A=[B]C, where B and C 
// are correct bracket sequences
// For example, the sequences “(())” and “()[]” are correct, while the sequences “[)” and “((” are 
// not correct.

// N sequences are given. For every of them determine whether it is a correct bracket sequence.

// Input
// The first line of the input file contains N, the number of sequences to test (1≤N≤500). Each of 
// the following N lines contains at least one and at most 10^4 characters, and there are only four 
// possible characters: “(”, “)”, “[”, “]”. Every line, including the last one, is terminated by a 
// newline sequence.

// Output
// For every line from the input ﬁle output “YES” if it is a correct bracket sequence, and “NO” 
// otherwise.

// Example
// input.txt
// 5
// ()()
// ([])
// ([)]
// ((]]
// )(
// output.txt
// YES
// YES
// NO
// NO
// NO


#include <fstream>
#include <string>


class stack_node
{
    private:
        char sym;
        stack_node *next;
    
    public:
        stack_node() {
            sym = '\0';
            next = 0;
        }
        
        ~stack_node() {}
        
        stack_node(char s, stack_node *n) {
            sym = s;
            next = n;
        }
        
        char get_value() {
            return sym;
        }
        
        stack_node * get_next() {
            return next;
        }
};


class stack
{
    private:
        bool flag;
        stack_node *first;
    
    public:
        stack() {}
        
        ~stack() {
            stack_node *temp;
            
            while(first != 0) {
                temp = first -> get_next();
                delete first;
                first = temp;
            }
        }
        
        void push(char sym) {
            stack_node *new_node;
            new_node = new stack_node(sym, first);
            first = new_node;
        }
        
        void pop() {
            stack_node *temp;
            temp = first;
            first = temp -> get_next();
            delete temp;
        }
        
        void processing() {
            std::ifstream fin("input.txt");
            std::ofstream fout("output.txt");
            
            int n, symbol, i, j;
            std::string str;
            
            fin >> n;
            std::getline(fin, str);
            for (i = 0; i < n; ++i) {
                
                flag = true;
                this -> ~stack();
                
                std::getline(fin, str);
                for (j = 0; j < str.length(); ++j) {
                    
                    if (str[j] == '(' || str[j] == '[')
                        push(str[j]);
                    else if (first != 0 && (int)(first -> get_value() + str[j]) % 132 > 1)
                        pop();
                    else {
                        flag = false;
                        break;
                    }
                }
                
                if (flag && first == 0)
                    fout << "YES" << '\n';
                else
                    fout << "NO" << '\n';
            }
        }
};


int main()
{
    stack test;
    test.processing();
    
    return 0;
}
