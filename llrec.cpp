#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    //base case - head is null;
    if (head == nullptr)
    {
        return;
    }
    else
    {
        if (head->val > pivot) //places into larger
        {
            Node* temp_head = head;
            head = NULL;
            *larger = *temp_head;

            llpivot (temp_head->next, smaller, larger->next, pivot);
        }
        else //places into smaller
        {
            Node* temp_head = head;
            head = NULL;
            *smaller = *temp_head;

            llpivot (temp_head, smaller->next, larger, pivot);
        }
    }
    
}
