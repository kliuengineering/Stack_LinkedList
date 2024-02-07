//
//  main.cpp
//  Stack_LinkedList
//
//  Created by Kevin Liu on 2024-02-06.
//

#include <iostream>
#include <vector>
#include <iterator>

template <class T>
class Stack
{
private:
    
    /*-------------------- construct a node begins --------------------*/
    
    struct Node
    {
        Node *previous;
        Node *next;
        T data;
        
        Node( Node *previous=nullptr, Node *next=nullptr, const T &data=T{} ) :
        previous(previous), next(next), data(data)
        {}
    };
    
    Node *front;
    Node *back;
    
    /*-------------------- construct a node ends. --------------------*/
    
    
public:
    
    // constructor for the Stack()
    Stack() : front(nullptr), back(nullptr){}
    
    // is-empty query
    bool is_empty(void)
    {
        bool flag = false;
        
        if(!front && !back)
        {
            flag = true;
        }
        
        return flag;
    }

    
    /*-------------------- push back begins --------------------------*/
    
    void push_back(const T &data_input)
    {
        Node *node_new = new Node();
        
        node_new->previous = nullptr;
        node_new->next = nullptr;
        node_new->data = data_input;
        
        if( is_empty() )
        {
            front = node_new;
            back = node_new;
        }
        else
        {
            back->next = node_new;
            node_new->previous = back;
            
            back = node_new;
        }
    }
    
    /*-------------------- push back ends. ---------------------------*/
    
    
    /*-------------------- pop top begins ----------------------------*/
    
    T pop_back()
    {
        T data_temp;
        
        if( is_empty() )
        {
            data_temp = T{};
        }
        else if(front == back)
        {
            data_temp = back->data;
            delete back;
            front = nullptr;
            back = nullptr;
        }
        else
        {
            Node *node_new = back;
            back = back->previous;
            back->next = nullptr;
            
            data_temp = node_new->data;
            
            delete node_new;
        }
        
        return data_temp;
    }
    
    /*-------------------- pop top ends ------------------------------*/
    
    
    // destructor
    ~Stack()
    {
        while( !is_empty() )
            pop_back();
    }
    
    // printing
    void Print(void)
    {
        Node *ptr_print = front;
        
        while( ptr_print )
        {
            std::cout << ptr_print->data << "  ";
            ptr_print = ptr_print->next;
        }
    }
};


int main(int argc, const char * argv[])
{
    Stack<int> my_stack;
    
    for(int i=0; i<10; i++)
        my_stack.push_back(i+1);
    
    std::cout << "pushed... stack is -> ";
    my_stack.Print();
    puts(""); puts("");
    
    // ------------------------------------------
    
    for(int i=0; i<15; i++)
        my_stack.pop_back();
    
    std::cout << "popped... stack is -> ";
    my_stack.Print();
    puts(""); puts("");
    
    puts("");
    
    // ------------------------------------------

    for(int i=0; i<10; i++)
        my_stack.push_back(i+1);
    
    std::cout << "pushed... stack is -> ";
    my_stack.Print();
    puts(""); puts("");
    
    // ------------------------------------------
    

    std::vector<int> my_vector;

    std::vector<int>::iterator itr;
    
    for(int i=0; i<15; i++)
        my_vector.push_back(my_stack.pop_back());
    
    std::cout << "popped... stack is -> ";
    for(itr = my_vector.begin(); itr != my_vector.end(); itr++)
    {
        std::cout << *itr << "  ";
    }
    puts(""); puts("");
    
    return 0;
}
