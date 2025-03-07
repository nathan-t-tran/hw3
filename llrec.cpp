#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    larger = nullptr; //makes sure that the node is null
    smaller = nullptr; //makes sure that node is null

    //base case - head is null;
    if (head == nullptr)
    {
        return;
    }
    else
    {
        if (head->val > pivot) //places into larger
        {
            larger = head;
            Node* next_head = head->next;
            head = nullptr;

            llpivot (next_head, smaller, larger->next, pivot); //moves onto next head and next larger node
        }
        else //places into smaller
        {
            smaller = head;
            Node* next_head = head->next;
            head = nullptr;
            
            llpivot (next_head, smaller->next, larger, pivot); //moves onto next head and next smaller node
        }
    }
    
}
