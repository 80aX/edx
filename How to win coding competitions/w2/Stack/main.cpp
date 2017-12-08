// Stack

// Input file:	input.txt
// Output file:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// Implement a stack which supports push and pop operations. For every pop operation, output 
// its result.

// Input
// The ﬁrst line of the input ﬁle contains a single integer number N (1≤N≤106) – the number of 
// commands. N lines follow, each line contains exactly one command. There are the following 
// commands:

// + x: push x to the stack. Every x will be an integer such that |x|≤109. The symbol + and 
// the number will be separated by exactly one white space.
// -: pop an element from the stack. It is guaranteed that this operation will never be executed 
// on an empty stack. There will be at least one such operation.
// Output
// Output the integers popped from the stack, one per line, in the order they were popped.

// Example
// input.txt
// 6
// + 1
// + 10
// -
// + 2
// + 1234
// -
// output.txt
// 10
// 1234


#include <fstream>


class stack_node
{
    private:
        int value;
        stack_node *next;
    
    public:
        stack_node() {
            value = 0;
            next = 0;
        }
        
        ~stack_node() {}
        
        stack_node(int v, stack_node *n) {
            value = v;
            next = n;
        }
        
        int get_value() {
            return value;
        }
        
        stack_node * get_next() {
            return next;
        }
};


class stack
{
    private:
        stack_node *first;
    
    public:
        stack() {
            first = 0;
        }
        
        ~stack() {
            stack_node *temp;
            
            while(first) {
                temp = first -> get_next();
                delete first;
                first = temp;
            }
        }
        
        void push(int value) {
            stack_node *new_node;
            new_node = new stack_node(value, first);
            first = new_node;
        }
        
        int pop() {
            stack_node *temp;
            int value = first -> get_value();
            temp = first;
            first = first -> get_next();
            
            delete temp;
            return value;
        }
};


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int n, value;
    char operation;
    
    fin >> n;
    stack test;
    
    for (int i = 0; i < n; ++i) {
        fin >> operation;
        
        if (operation == '+') {
            fin >> value;
            test.push(value);
        } else {
            fout << test.pop() << '\n';
        }
    }
    
    return 0;
}
