#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
struct song_node* insert_inOrder(struct song_node* p,char* artis7,char* nam3){
  struct song_node *head = p;
  char artistsong[] = *(strcat(artis7,nam3));
  while(p){
    char cur[] = *(strcat(p->artist,p->name));
    cmp = strcmp(cur,artistsong);
    if(cmp)break;
  }
return head;
}
