#include "header.h"

int main()
{
    //declaring variables
    tweet * head;
    tweet * tail;
    tweet * node;
    tweet * emptyList;
    head = NULL;
    tail = NULL;
    node = NULL;
    emptyList = NULL;


    int i,empty;

    printf("Beginning A4 program testing...\n");
    printf("Creating initial queue list\n\n");


    for(i=0;i<5;i++){
        enqueue (&head,&tail,node);       //creating a list of 5 nodes in the start
    }

    printf("\nVerifying queue contents using printQueue\n");
    printQueue (head);                   //printing the intial queue

    //TEST 1 [Engueue]
    printf("\nTesting [Enqueue] function\n");

    printf("Iteration [1]\n");
    enqueue (&head,&tail,node);             //call - 1
    printQueue (head);

    printf("Iteration [2]\n");
    enqueue (&head,&tail,node);             //call - 2
    printQueue (head);

    printf("Iteration [3]\n");
    enqueue (&head,&tail,node);             //call - 3
    printQueue (head);

    //TEST - 2 [Dequeue]
    printf("\nTesting [Dequeue] function\n");

    printf("Iteration [1]\n");
    dequeue (&head,&tail);              //call - 1
    printQueue (head);

    printf("Iteration [2]\n");
    dequeue (&head,&tail);              //call - 2
    printQueue (head);

    printf("Iteration [3]\n");
    dequeue (&head,&tail);              //call - 3
    printQueue (head);


    //TEST - 3 [isEmpty]
    printf("\nTesting [isEmpty] function\n");
    printf("Testing with list,expecting !isEmpty\n");
    empty = isEmpty (head);             //call - 1
    if(!empty){
        printf("SUCCESS: list is not empty\n");
    }
    else{
        printf("FAILED: non empty list declared as empty");
    }
    printf("Using printQueue to verify queue contents\n");
    printQueue (head);

    printf("\nTesting with list after two dequeus, expecting !isEmpty\n");
    dequeue(&head,&tail);                  //Two dequeues for more testing
    dequeue(&head,&tail);
    empty = isEmpty (head);                 //call - 2
    if(!empty){
        printf("SUCCESS: list is not empty\n");
    }
    else{
        printf("FAILED: non empty list declared as empty");
    }
    printf("Using printQueue to verify queue contents\n");
    printQueue (head);

    printf("\nTesting with an empty queue, expecting isEmpty\n");
    empty = isEmpty (emptyList);            //call - 3
    if(empty){
        printf("SUCCESS: list is empty\n");
    }
    else{
        printf("FAILED: empty list declared as non empty\n");
    }

    //TEST - 4 [printQueue]
    printf("\nTesting [printQueue] function\n");
    printf("printQueue was used through the verification process already...\n\n\n");

    //TEST - 5 [sortID]
    printf("Testing [ascendSortID] function\n");
    sortID (&head,&tail);           //call - 1
    printQueue (head);

    printf("Testing [ascendSortID] function after add\n");
    enqueue (&head,&tail,node);
    sortID (&head,&tail);           //call - 2
    printQueue (head);

    printf("Testing [ascendSortID] function after reversing the list using [reverse] function\n");
    reverse (&head,&tail);
    printf("List after reversing\n");
    printQueue (head);
    sortID (&head,&tail);           //call - 3
    printf("\nList after sorting\n");
    printQueue (head);

    //TEST - 6 [sortUsername]
    printf("\n\nTesting [ascendSortUsername] function\n");
    sortUsername (&head,&tail);         //call - 1
    printQueue (head);

    printf("\n\nTesting [ascendSortUsername] function and adding an enqueue\n");
    enqueue (&head,&tail,node);
    sortUsername (&head,&tail);          //call - 2
    printQueue (head);

    printf("\n\nTesting [ascendSortID] function after reversing the list using [reverse] function\n");
    reverse (&head,&tail);
    printf("List after reversing\n");
    printQueue(head);
    sortUsername (&head,&tail);             //call - 2
    printf("\nList after sorting\n");
    printQueue (head);


    //TEST - 7 [reverseQueue]
    printf("\n\nTesting [reverseQueue] function\n");
    reverse (&head,&tail);
    printQueue(head);

    printf("[Reverse] function was tested various times while testing sort functions....\n\n");
	
	clearList(&head,&tail);

    return 0;
}