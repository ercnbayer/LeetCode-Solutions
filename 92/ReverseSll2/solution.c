/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    
    struct ListNode *pPrev=NULL;
    struct ListNode *pCurr=head;
    struct ListNode * pNext=NULL;
    struct ListNode *pTemp=NULL;
    
    struct ListNode *pTail=head;
    int iCounter=1;
    /*if(left==right)
        return head;*/
    struct ListNode *pRoot=pCurr;// keep  a root to add  the left side's left

  

   
    while(pCurr){
         
         if(iCounter == left){
            
            pTail=pCurr; // keep a tail to add  the right side's right
        }

        if(iCounter >= left && iCounter <= right){
            // reversing the l.l

            pNext=pCurr->next;
            pCurr->next=pPrev;
            pPrev=pCurr;
            pCurr=pNext;
            
            iCounter++;

        }
          else if( iCounter < left ){ // moving to the left

            pTemp=pCurr;
            pCurr=pCurr->next;

            iCounter++;            
        }

        else 
         break;

         
    }
     if(pTail){
            pTail->next=pNext;
        }

    if(pTemp !=NULL){
        pTemp->next=pPrev;
        return pRoot;
    }
    return pPrev;
}