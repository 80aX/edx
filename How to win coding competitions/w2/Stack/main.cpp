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
