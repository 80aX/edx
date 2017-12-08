// Queue

// Input file:	input.txt
// Output file:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// Implement a queue which supports push and pop operations. For every pop operation, output 
// its result.

// Input
// The ﬁrst line of the input ﬁle contains a single integer number N (1≤N≤106) – the number 
// of commands. N lines follow, each line contains exactly one command. There are the following 
// commands:

// + x: push x to the queue. Every x will be an integer such that |x|≤109. The symbol + and 
// the number will be separated by exactly one white space.
// -: pop an element from the queue. It is guaranteed that this operation will never be executed 
// on an empty queue. There will be at least one such operation.
// Output
// Output the integers popped from the queue, one per line, in the order they were popped.

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
// 1
// 10


#include <fstream>


class queue_node
{
    private:
        int value;
        queue_node *next;
        queue_node *prev;
    
    public:
        queue_node() {
            value = 0;
            next = 0;
            prev = 0;
        }
        
        ~queue_node() {}
        
        queue_node(int v, queue_node *p) {
            value = v;
            prev = p;
            next = 0;
        }
        
        int get_value() {
            return value;
        }
        
        queue_node * get_next() {
            return next;
        }
        
        queue_node * get_prev() {
            return prev;
        }
        
        void set_next(queue_node *n) {
            next = n;
        }
        
        void set_prev(queue_node *p) {
            prev = p;
        }
};


class queue
{
    private:
        queue_node *first;
        queue_node *last;
    
    public:
        queue() {
            first = 0;
            last = 0;
        }
        
        ~queue() {
            queue_node *temp;
            
            while (last != 0) {
                temp = last;
                last = last -> get_prev();
                delete temp;
            }
        }
        
        void push(int value) {
            queue_node *new_node;
            new_node = new queue_node(value, last);
            
            if (first == 0)
                first = new_node;
            else
                last -> set_next(new_node);
            
            last = new_node;
        }
        
        int pop() {
            queue_node *temp;
            int value = first -> get_value();
            
            temp = first;
            first = first -> get_next();
            
            if (first != 0)
                first -> set_prev(0);
            else
                last = last -> get_prev();
            
            delete temp;
            return value;
        }
        
        void processing() {
            std::ifstream fin("input.txt");
            std::ofstream fout("output.txt");
            
            int n, value;
            char operation;
            
            fin >> n;
            
            for (int i = 0; i < n; ++i) {
                fin >> operation;
                
                if (operation == '+') {
                    fin >> value;
                    push(value);
                } else {
                    fout << pop() << '\n';
                }
            }
        }
};


int main()
{
    queue test;
    test.processing();
    
    return 0;
}
