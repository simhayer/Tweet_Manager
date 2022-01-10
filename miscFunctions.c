#include "header.h"

void sortID (tweet ** head, tweet ** tail){
    int swapped;
    tweet* temp;
    tweet* temp2;
    tweet* temp1;

    temp2 = malloc(sizeof(tweet));

    if (*head == NULL){
        return;
    }

    do
    {
        swapped = 0;
        temp = *head;

        while (temp->next != NULL)
        {
            if (temp->id > temp->next->id)
            {
                temp1 = temp->next;
                temp2->id = temp->id;
                strcpy(temp2->user,temp->user);
                strcpy(temp2->text,temp->text);

                temp->id = temp1->id;
                strcpy(temp->user,temp1->user);
                strcpy(temp->text,temp1->text);

                temp1->id = temp2->id;
                strcpy(temp1->user,temp2->user);
                strcpy(temp1->text,temp2->text);

                swapped = 1;
            }
            temp = temp->next;
        }
    }
    while (swapped);
    free(temp2);
}

void sortUsername (tweet ** head, tweet ** tail){
    int swapped;
    tweet* temp;
    tweet* temp2;
    tweet* temp1;

    temp2 = malloc(sizeof(tweet));

    if (*head == NULL){
        return;
    }

    do
    {
        swapped = 0;
        temp = *head;

        while (temp->next != NULL)
        {
            if (strcmp(temp->user,temp->next->user)>0)
            {
                temp1 = temp->next;
                temp2->id = temp->id;
                strcpy(temp2->user,temp->user);
                strcpy(temp2->text,temp->text);

                temp->id = temp1->id;
                strcpy(temp->user,temp1->user);
                strcpy(temp->text,temp1->text);

                temp1->id = temp2->id;
                strcpy(temp1->user,temp2->user);
                strcpy(temp1->text,temp2->text);

                swapped = 1;
            }
            temp = temp->next;
        }
    }
    while (swapped);
    free(temp2);
}

void reverse (tweet ** head, tweet ** tail){
    tweet* temp;
    tweet* temp1;
    tweet* temp2;
    temp = *head;
    temp1 = *head;

    *tail = *head;
    temp1 = temp->next;

    while(temp1->next != NULL){
        temp2 = temp1->next;
        if(temp == *head){
            temp->next = NULL;
        }
        temp1->next = temp;

        temp = temp1;
        temp1 = temp2;

    }

    temp1->next = temp;

    *head = temp1;
}
