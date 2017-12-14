// Postfix Notation

// Input file:	input.txt
// Output file:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// In postﬁx notation (or reverse Polish notation) an operation is written directly after its 
// operands. For instance, a sum of two numbers, A + B, is written as A B +. The expression 
// B C + D ∗ means (B + C) ∗ D, and A B C + D ∗ + means A + (B + C) ∗ D. (Here, we denote the 
// multiplication operation as ∗). An advantage of this notation is that it does not require 
// neither parentheses nor agreements on priority of operators.

// Given an expression in postﬁx notation, evaluate it.

// Input
// The first line of the input file contains N, 1≤N≤10^6, the number of elements in the 
// subsequent expression. The second line contains the expression in postﬁx notation, which 
// has exactly N elements. The expression can contain single-digit non-negative numbers and 
// operations +, -, ∗. All operations are binary, that is, they take two arguments and return 
// the result. Every two subsequent elements are separated by a single whitespace. It is 
// guaranteed that the expression is correct and is evaluated to a single number.

// Output
// Output the result of evaluation of this expression. It is guaranteed that the result, as 
// well as any intermediate value, will be less than 2^31 by the absolute value.

// Example
// input.txt
// 7
// 8 9 + 1 7 - *
// output.txt
// -102


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
        
        void set_value(int v) {
            value = v;
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
        
        void pop(int operation) {
            stack_node *temp;
            int value1, value2, result;
            
            value1 = first -> get_value();
            temp = first;
            first = first -> get_next();
            delete temp;
            value2 = first -> get_value();
            
            if (operation == 42)
                result = value2 * value1;
            else if (operation == 43)
                result = value2 + value1;
            else if (operation == 45)
                result = value2 - value1;
            else if (operation == 47)
                result = value2 / value1;
            
            first -> set_value(result);
        }
        
        void processing() {
            std::ifstream fin("input.txt");
            std::ofstream fout("output.txt");
            
            int n;
            char inp;
            
            fin >> n;
            
            for (int i = 0; i < n; ++i) {
                fin >> inp;
                
                if (inp > 47)
                    push((int)inp - 48);
                else
                    pop(inp);
                
            }
            
            fout << first -> get_value() << '\n';
        }
};


int main()
{

    stack test;
    test.processing();
    
    return 0;
}
