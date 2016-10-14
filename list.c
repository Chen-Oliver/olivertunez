#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"

void print_list(struct song_node *p){
  struct song_node *tmp = p;
  printf("Data:[ ");
  while(tmp){
    printf("%s ",tmp->artist);
    printf("- %s ",tmp->name);
    tmp = tmp->next;
  }
  printf("]\n");
}
struct song_node* free_list(struct song_node *ptr){
  struct song_node *head = ptr;
  struct song_node *nxt = (struct song_node*)malloc(sizeof(struct song_node));
  while(ptr){
    nxt = ptr->next;
    free(ptr);
    ptr = nxt;
  }
  head = NULL;
  return head;
}

struct song_node* insert_front(struct song_node *p, char* artis7, char* nam3){
  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(new->artist,artis7);
  strcpy(new->name,nam3);
  new->next = p;
  return new;
}
struct song_node* insert_inOrder(struct song_node* p,char* artis7,char* nam3){
  struct song_node *head = p;
  //create node to be inserted
  struct song_node *new = (struct song_node*) malloc(sizeof(struct song_node));
  strcpy(new->artist,artis7);
  strcpy(new->name,nam3);
  new->next = NULL;
}
int main(){
  struct song_node *head = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(head->artist,"me");
  strcpy(head->name,"something");
  head->next =NULL;
  head = insert_front(head,"led zep","stairway");
  print_list(head);
}
