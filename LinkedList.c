#include<stdio.h>
#include<stdlib.h>

//@Animesh_Das (16.03.2023)

//Some Global Variables
int stop=0, choice;

//Global, Singly LinkedList
struct LinkList{
    int data;
    struct LinkList *next;
};

typedef struct LinkList node;
node *head= NULL;

//Get Node Function (Very Imp Func)
node *getnode(){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));

    printf("\nEnter the Data: ");
    scanf("%d",&newnode->data);

    newnode->next = NULL;

    return newnode;
}


//Some Functions
void insert_beg();
void insert_end();

void del_beg();
void del_end();

int count_nodes();
void print_ll();

int menu();
void conditions(int x);

//Main Program Starts From Here
int main(){

    while(!stop){

        choice = menu();
        conditions(choice);

    }

    printf("\nProgram Terminated !!\n");

    return 0;   //Main Program Ended Here

}

//Making the Functions
int menu(){

    printf("\n");
    printf("\n[1]Insert at Beginning ");
    printf("\n[2]Insert at End ");
    printf("\n[3]Delete the Beginning Node");
    printf("\n[4]Delete the End Node ");
    printf("\n[5]Display the LinkedList");
    printf("\n[6]Count the Number of Nodes ");
    printf("\n[7]EXIT !! ");

    printf("\n\nEnter your Choice: ");
    scanf("%d",&choice);

    return choice;

}

void conditions(int x){
    if(x==1){
        insert_beg();
    }

    else if(x==2){
        insert_end();
    }

    else if(x==3){
        del_beg();
    }

    else if(x==4){
        del_end();
    }

    else if(x==5){
        print_ll();
    }

    else if(x==6){
        int counter;
        counter = count_nodes();
        printf("\nTheir are %d Nodes in the LinkedList !!",counter);
    }

    else if(x==7){
        printf("\nTHANK YOU !");
        stop = 1;

    }
    else{
        printf("\nInvaild Input !! Try Again .");
    }


}

void print_ll(){
    if(head == NULL){
        printf("\nLinkedList is Empty");
    }
    else{
        node *temp;
        temp = head;

        printf("\nThe Contents of the LinkedList are: \n");
        while(temp != NULL){
            printf("%d ==> ",temp->data);

            temp = temp->next;
        }
        printf("Null");
    }
}

int count_nodes(){
    int count=0;

    node *curr;
    curr = head;

    while(curr != NULL){
        count ++;

        curr = curr->next;
    }

    return count;
}

void insert_beg(){
    node *newnode;
    newnode = getnode();

    if(head == NULL){
        head = newnode;
        printf("\nNode Inserted at the Beginning !!");
    }

    else{
        newnode->next = head;
        head = newnode;
    }
}

void insert_end(){
    node *newnode;
    newnode = getnode();

    if(head == NULL){
        head = newnode;
        printf("\nNode Inserted at the End !!");
    }

    else{
        node *temp;
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        printf("\nNode Inserted at the End !!");
    }
}

void del_beg(){
    if(head == NULL){
        printf("\nLinkedList is Empty !!");
    }
    else{
        node *temp;
        temp = head;

        head = head->next;

        free(temp);
        printf("\nFirst Node is Deleted !!");
    }
}

void del_end(){
    if(head == NULL){
        printf("\nLinkedList is Empty !!");
    }
    else{
        node *prev;
        node *curr;

        prev = head;
        curr = head;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        free(curr);
        printf("\nLast Node is Deleted !!");
    }
}



