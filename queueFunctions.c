#include "header.h"

int isEmpty (tweet * head){
    if(head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue (tweet ** head, tweet ** tail, tweet * node){

    char* pos;
    int i,sum = 0,ID = 0;
    tweet * temp;

    node = malloc(sizeof(tweet));

    if(isEmpty(*head)){
        printf("Enter a username ");
        fgets(node->user,100,stdin);
        if ((pos=strchr(node->user, '\n')) != NULL){
            *pos = '\0';
        }
        if(strlen(node->user)>51){
            printf("Error: Username should be less than 50 chars\n");
            free(node);
        }

        printf("Enter the user's tweet ");
        fgets(node->text,150,stdin);
        if ((pos=strchr(node->text, '\n')) != NULL){
            *pos = '\0';
        }
        if(strlen(node->text)>141){
            printf("Error: Tweet should be less than 140 chars\n");
            free(node);
        }

        node->next = NULL;
        for(i=0;i<strlen(node->user);i++){
            sum = sum + (int)(node->user[i]);
        }
        node->id = sum + strlen(node->text);
        *head = node;
        *tail = node;
    }
    else{
        printf("Enter a username ");
        fgets(node->user,100,stdin);
        if ((pos=strchr(node->user, '\n')) != NULL){
            *pos = '\0';
        }
        if(strlen(node->user)>51){
            printf("Error: Username should be less than 50 chars\n");
            free(node);
        }

        printf("Enter the user's tweet ");
        fgets(node->text,150,stdin);
        if ((pos=strchr(node->text, '\n')) != NULL){
            *pos = '\0';
        }
        if(strlen(node->text)>141){
            printf("Error: Tweet should be less than 140 chars\n");
            free(node);
        }

        node->next = NULL;
        for(i=0;i<strlen(node->user);i++){
            sum = sum + (int)(node->user[i]);
        }
        ID = sum + strlen(node->text);
        temp = *head;
        while(temp != *tail){
            if(ID == temp->id){
                temp = *head;
                ID = ID + (int)(rand()%998)+ 1;
            }
            else{
                temp = temp->next;
            }
        }

        node->id = ID;
        (*tail)->next = node;
        *tail = node;
    }

}

void dequeue (tweet ** head, tweet ** tail){
    tweet* temp;
    temp = *head;

    *head = (*head)->next;

    free(temp);

}

void printQueue (tweet * head){
    tweet* temp;
    temp = head;

    while(temp != NULL){
        printf("%d: Created by %s : %s\n",temp->id,temp->user,temp->text);
        temp = temp->next;
    }
}