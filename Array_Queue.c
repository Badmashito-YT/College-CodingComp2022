#include<stdio.h>
#define MAX 6

int Q[MAX];
int front,rear,stop=0,choice;


//Some Functions
int menu();
void conditions(int x);

//Main Program Starts from here
int main(){

    while(!stop){
        choice = menu();
        conditions(choice);

    }

    printf("\nProgran Terminated !!\n");

    return 0;
    
}

int menu(){
    printf("\n\n[1]Enqueue");
    printf("\n[2]Dequeue");
    printf("\n[3]Display Queue");
    printf("\n[4]EXIT !!");

    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);

    return choice;

}

void conditions(int x){
    if(x==1){
        printf("Enqueue");
    }

    else if(x==2){
        printf("\nDequeue");
    }

    else if(x==3){
        printf("\nDisplay");
    }

    else if(x==4){
        printf("\nTHANK YOU !");
        stop = 1;
    }

    else{
        printf("\nInvaild Input ! Try Again !!");
    }


}






