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

void printListAll(struct list *head){
  struct list*now=head;
  do{
    Log ("%s\n",now->name);
    now=now->next;
  }while(now->next!=NULL);
  Log ("\n");
}

int main(){
  struct list *first,*next;
  //make head list
  first=(struct list*)malloc(sizeof(struct list *));
  first->name=(char *)malloc(sizeof(char)*20);
  strcpy(first->name,"head");
  first->prev=NULL;
  first->next=NULL;
  //add next list
//  printf("fist name:%s \n",first->name);
  Log ("\n");
  printListAll(first);
  Log ("\n");
  printListAll(first);
  Log ("\n");
  addList(first,"newName");
//  Log ("\n");
//  printListAll(first);
//  addList(first,"thirdName");
//  printListAll(first);

}
