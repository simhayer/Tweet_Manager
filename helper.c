#include "header.h"

void clearList(tweet ** head, tweet ** tail){

    tweet * temp;
    tweet * temp2;
    temp = *head;
    temp2 = *head;

    while(temp != NULL){
        temp2  = temp->next;
        free(temp);
        temp = temp2;
    }

}