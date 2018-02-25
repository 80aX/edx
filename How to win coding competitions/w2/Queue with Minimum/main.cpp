// Queue with Minimum

// Input ﬁle:	input.txt
// Output ﬁle:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// Implement a queue which supports push and pop operations, and additionally a minimum query, 
// which returns a minimum among the elements in the queue. For every minimum query, output its result.

// Input
// The ﬁrst line of the input ﬁle contains a single integer number  () – the number of commands.  
// lines follow, each line contains exactly one command. There are the following commands:

// + : push  to the queue. Every  will be an integer such that . The symbol + and the number 
// will be separated by exactly one white space.
// -: pop an element from the queue. It is guaranteed that this operation will never be executed 
// on an empty queue.
// ?: query a minimum element in the queue. It is guaranteed that this operation will never be 
// executed on an empty queue. There will be at least one such query.
// Output
// Output the results of the minimum queries on the queue, one per line, in the order they were 
// performed.

// Example
// input.txt
// 10
// + 1
// + 10
// ?
// -
// ?
// + 2
// ?
// + 1234
// -
// ?
// output.txt
// 1
// 10
// 2
// 2


#include <fstream>


class queue_node
{
    private:
        int value, min;
        queue_node *next;
        queue_node *prev;
    
    public:
        queue_node() {
            value = 0;
            next = 0;
            prev = 0;
            min = 0;
        }
        
        ~queue_node() {}
        
        queue_node(int v, queue_node *p) {
            value = v;
            prev = p;
            next = 0;
            min = v;
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
        
        int get_min() {
            return min;
        }
        
        void set_min(int m) {
            min = m;
        }
};


class queue_with_min
{
    private:
        queue_node *first;
        queue_node *last;
    
    public:
        queue_with_min() {
            first = 0;
            last = 0;
        }
        
        ~queue_with_min() {
            queue_node *temp;
            
            while (last != 0) {
                temp = last;
                last = last -> get_prev();
                delete temp;
            }
        }
        
        int min_value() {
            return first->get_min();
        }
        
        void push(int value) {
            queue_node *new_node;
            new_node = new queue_node(value, last);
            
            if (first == 0)
                first = new_node;
            else {
                queue_node *temp = last;
                
                while(temp != 0 && temp -> get_min() > value) {
                    temp -> set_min(value);
                    temp = temp -> get_prev();
                }
                last -> set_next(new_node);
            }
            last = new_node;
        }
        
        void pop() {
            queue_node *temp;
            temp = first;
            first = first -> get_next();
            
            if (first != 0)
                first -> set_prev(0);
            else
                last = last -> get_prev();
            
            delete temp;
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
                } else if (operation == '?') {
                    fout << min_value() << '\n';
                } else {
                    pop();
                }
            }
        }
};


int main()
{
    queue_with_min test;
    test.processing();
    
    return 0;
}
