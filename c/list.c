#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Log printf("%d %s ",__LINE__,__func__); printf

struct list{
  char *name;
  struct list *prev;
  struct list *next;
};

void addList(struct list *head,char *s){
  struct list *next,*now=head;
  next=(struct list*)malloc(sizeof(struct list *));
  next->name=(char *)malloc(sizeof(char)*20);
  next->name=s;
  next->next=NULL;

  while(now->next!=NULL){
    Log ("%s",now->name);
    now=now->next;
  }
  now->next=next;
}

void printListAll(struct list *now){
  Log ("\n");
  do{
    printf("%s ",now->name);
    if(now->next==NULL){
      break;
    }else{
      now=now->next;
    }
  }while(1);
}

int main(){
  struct list *first,*next,*now;
  //make head list
  first=(struct list*)malloc(sizeof(struct list));
  first->name=(char *)malloc(sizeof(char)*20);
  strcpy(first->name,"head");
  first->prev=NULL;
  first->next=NULL;
  //add next list
  first->next=(struct list*)malloc(sizeof(struct list));
  first->next->name=(char *)malloc(sizeof(char)*20);
  strcpy(first->next->name,"next");
  Log ("%s\n",first->name);
  Log ("%s\n",first->next->name);
  first->next->next=NULL;
    //  printf("fist name:%s \n",first->name);
  Log ("\n");
  addList(first,"newName");
  printListAll(first);
  addList(first,"secName");
  addList(first,"thirdName");
  addList(first,"fourthName");
  addList(first,"fifthName");
  printListAll(first);
  Log ("\n");
}
