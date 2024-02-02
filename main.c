//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int x=5;
    struct node a,b,*head ;
    head=&a;
    head->next=&b;
    head->value = x;
    head->next->value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
    4.print by use head
 */
    struct node c;
    head->next->next=&c;
    head->next->next->value=head->next->value+3; // or c.value = 11;
    head->next->next->next = NULL;
    printf("Exercise I\n"); 
    printf("%d\n", head ->next->next->value ); //what value for 11
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    struct node d;
    d.next=&a;
    d.value = 2;
    head = &d;
    printf("Exercise II\n"); 
    printf("%d\n", head ->value ); //what value for 2
    printf("%d\n", head ->next->value ); //what value for 5
    printf("%d\n", head ->next->next->value ); //what value for 8
    printf("%d\n", head ->next->next->next->value ); //what value for 11
        
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
    printf("Exercise III\n"); 
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp=tmp->next;
          // What is missing??? I don't know ;-;
        }
    printf("\n");
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */
    printf("Exercise IV\n");
    tmp=head;
    while (tmp != NULL)
    {
        printf("%3d",tmp->value);
        tmp = tmp->next;
    }
         
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */

    printf("\nExercise IV\n");
    head = (NodePtr)malloc(sizeof(struct node));//head peng build
    tmp=head;
    tmp->value = 2;
    //printf("tmp->value = %d \n",tmp->value);
    for(i=0;i<4;i++){
        printf("i=%d",i);
        tmp->next = (NodePtr)malloc(sizeof(struct node));
        tmp->next->value = tmp->value+3;
        tmp=tmp->next;
        if(i==3) tmp->next=NULL;//
        printf("tmp->value = %d \n",tmp->value);
    }
    
    /*  Exercise VI Free all node !!
         //use a loop to help
          
    
     */
    while(head!=NULL){
        tmp=head;
        head=head->next;
        printf("free = %d \n",tmp->value);
        free(tmp);
    }
    return 0;
}
