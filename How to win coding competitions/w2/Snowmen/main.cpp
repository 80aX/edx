// Snowmen

// Input file:	input.txt
// Output file:	output.txt
// Time limit:	2 seconds
// Memory limit:	256 megabytes

// In the winter of 2012, due to vast amount of news about Apocalypsis and the end of the world, 
// one thing came completely unnoticed. It as a breakthrough in the areas of snowmen and cloning: 
// snowmen cloning. You surely know, but we nevertheless remind, that a snowmen consists of zero 
// or more snowballs put one atop another, and cloning is a procedure of creating an identical copy, 
// which is called a clone.

// In a little city Littlecity, a school teacher A. Schoolteacher bought a snowmen cloning device 
// in the “Snowmen Cloning Device Online Store” online store. Now the schoolgirls, as well as 
// schoolboys, can play, and do indeed play, the following game. At a certain moment of time, 
// some of the children chooses an existing snowman, clones it, and performs one of the actions 
// with the clone:

// adds a new snowball atop, or
// removes the topmost snowball.
// The school teacher A. Schoolteacher has written the sequence of actions performed by the 
// children and now wants to know the total mass of all the created snowmen.

// Input
// The ﬁrst line contains a number  (), the number of actions performed by the children. The 
// following  lines contain descriptions of these actions. An -st line of the input ﬁle contains a 
// description of the -th action, which can be one of the following:

 // : clone the -th snowman () and add a snowball with a mass of  () atop it;
 // 0: clone the -th snowman () and remove the topmost snowball. It is guaranteed that the -th 
 // snowman is not empty.
// Initially, there is an empty snowman with the number of 0. As a result of the -th action, a 
// snowman with the number of  is created. All numbers in the input ﬁle are integers.

// Output
// Output the total mass of all the snowmen which were built.

// Example
// input.txt
// 8
// 0 1
// 1 5
// 2 4
// 3 2
// 4 3
// 5 0
// 6 6
// 1 0
// output.txt
// 74


#include <fstream>


class stack_node
{
    private:
        int mass;
        stack_node *prev;
    
    public:
        stack_node() {
            mass = 0;
            prev = 0;
        }
        
        stack_node(int m) {
            mass = m;
            prev = 0;
        }
        
        ~stack_node() {}
        
        int get_mass() {
            return mass;
        }
        
        stack_node * get_prev() {
            return prev;
        }
        
        void set_prev(stack_node *p) {
            prev = p;
        }
};


class stack
{
    private:
        stack_node *top;
        stack_node *bottom;
        int snowman_mass;
        
    public:
        stack() {
            top = 0;
            bottom = 0;
            snowman_mass = 0;
        }
        
        stack(stack *origin, int mass) {
            top = 0;
            bottom = 0;
            snowman_mass = 0;
            
            if (origin -> bottom == 0)
                push(mass);
            else {
                stack_node *temp = origin -> bottom;
                stack_node *temp_prev = temp -> get_prev();
                
                while (temp_prev != 0) {
                    push(temp -> get_mass());
                    
                    temp = temp_prev;
                    temp_prev = temp -> get_prev();
                }
                
                if (mass != 0) {
                    push(temp -> get_mass());
                    push(mass);
                }
            }
        }
        
        ~stack() {
            stack_node *temp;
            
            while (bottom != 0) {
                temp = bottom;
                bottom = bottom -> get_prev();
                delete temp;
            }
        }
        
        void push(int value) {
            snowman_mass += value;
            stack_node *new_node = new stack_node(value);
            
            if (bottom == 0)
                bottom = new_node;
            else
                top -> set_prev(new_node);
            
            top = new_node;
        }
        
        int get_snowman_mass() {
            return snowman_mass;
        }
};


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int n, t, m, total_mass = 0;
    fin >> n;
    
    stack **snow_array = new stack *[n + 1];
    snow_array[0] = new stack();
    
    for (int i = 1; i <= n; ++i) {
        fin >> t >> m;
        snow_array[i] = new stack(snow_array[t], m);
        
        total_mass += snow_array[i] -> get_snowman_mass();
    }
    
    fout << total_mass << '\n';
    
    for (int i = 0; i <= n; ++i)
        delete snow_array[i];
    
    delete [] snow_array;
    
    return 0;
}
