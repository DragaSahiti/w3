#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node
{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node()
    {
        next = NULL;
    }

};

class LinkedList{
    // Head + Circles inside linked with each other
    public:
    // Head -> Node type ptr
    Node * head;
    Node * tail;

    // Construct
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    } 
    // Circles inside linked with each other
    // Rules how circles will be linked

    // Insert
    void insert(int value)
    {
       // If 1st Node is added
       Node * temp = new Node; 
       // Insert value in the node
       temp->data = value;
       // 1st Node only.
       if(head == NULL)
       {
            head = temp;
       }
       // Any other Node only.
       else
       {
            tail->next = temp;
       }
       tail = temp;
    } 

    void insertAt(int pos, int value)
    {
        // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < pos-1)
        {
            i++;
            current = current->next;
        }

        // Create a node
        Node * temp = new Node;
        temp -> data = value;


        // Moving ptrs like magic ! if not head
        temp->next = current->next;
        current->next = temp;
        
        // Update the code for 1st position

    }

    // Deletion of last element
    void delet()
    {
        // store the tail in temp
        Node * temp = tail;
        
        // before tail has to point to null
        Node * current = head;
        while(current->next != tail)
        {
            current = current->next;
        }
        current->next = NULL; 

        // update tail
        tail = current;
        // delete temp
         delete temp;
    }
    // deletion of an element at  particular position
    void deletAt(int pos)
    {
        // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < pos-1)
        {
            i++;
            current = current->next;
        } 
        //move the ptrs
        Node * temp = current->next;
        current->next = temp->next;
        // delete temp 
        delete temp; 
    }
    // count the number of nodes in the linked list
    int countItems()
    {
        // Initialze count
        int count = 0;
        // Initialise current
        Node * current = head;
        while(current != NULL)
        {
           count++;
           current = current->next;
        }
        cout << count << endl;
        return count;
    }
    // Display
    void display()
    {
        Node * current = head;
        while(current != NULL)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << endl;
    }
    
    void revDisplay()
    {
       revDisplay2(head);
       cout << endl;
    }
    void revDisplay2(Node * current)
    {
         //Moves to next till available
         if (current == NULL) return;
         else
         {
             revDisplay2(current->next);
             cout << current->data << "->";
         }
         //print while coming back
    }
    
    void revLL()
    {
       Node * temp = head;
       revLL2(head);
       temp->next = NULL;
    }
    
    void revLL2(Node * current)
    {
       //condition for empty LL
       if(current == NULL) return;
       //condition for 1 element
       else if(current->next == NULL)
       {
          head = current;
          return;
       }
       //Reverse for the rest
       else{
          revLL2(current->next);
          current->next->next = current;
       }
    }


};


int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.countItems();
    l1.display();
    l1.revDisplay();
    l1.revLL();
    l1.display();
    /*l1.delet();
    l1.countItems();
    l1.display();
    l1.insertAt(1,3);
    l1.countItems();
    l1.display();
    l1.deletAt(3);
    l1.countItems();
    l1.display();*/
    return 0;
}
