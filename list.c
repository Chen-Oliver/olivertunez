#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
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

struct song_node* insert_front(struct song_node *p, char* a, char* n){
  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(new->artist,a);
  strcpy(new->name,n);
  new->next = p;
  return new;
}
char* lowercase(char *p){
  char *orig = p;
  while(*p){
    *p=tolower(*p);
    p++;
  }
  return orig;
}
int compNodes(struct song_node *first, struct song_node *second){ //compares two nodes by artist then by name
  if(strcmp(first->artist,second->artist)==0){
  //  printf("%d\n",strcmp(first->name,second->name));
    return strcmp(first->name,second->name);
  }
  else{
  //  printf("%d\n",strcmp(first->artist,second->artist));
  return strcmp(first->artist,second->artist);
}
}
//inserts nodes alphabetically
struct song_node* insert_inOrder(struct song_node* p,char* a,char* n){
  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(new->artist,a);
  strcpy(new->name,n);
  if (compNodes(p,new)>0)return insert_front(p,a,n); //if song goes in front
  struct song_node *curr = p;
  while(curr!=NULL){//go through the list
    if((curr->next)==NULL){ //if song goes in the back
      curr->next=new;
      new->next = NULL;
      break;
    }
    if((compNodes(curr,new)<=0)&&(compNodes(curr->next,new)>0)){ //if its between two nodes
      new->next = curr->next;
      curr->next = new;
      break;
}
      else curr=curr->next;
  }
  return p; //pointer to header
}
struct song_node *find_artist(struct song_node *p,char *a){
  struct song_node *curr = (struct song_node*)malloc(sizeof(struct song_node));
  curr = p;
  while(curr){
    if(strcmp(curr->artist,a)==0)return curr;
    else curr= curr->next;
  }
  return NULL;
}
struct song_node *find_song(struct song_node *p,char *n){
  struct song_node *curr = (struct song_node*)malloc(sizeof(struct song_node));
  curr = p;
  while(curr){
    if(strcmp(curr->name,n)==0)return curr;
    else curr= curr->next;
  }
  return NULL;
}
//given a node, remove it from the list
void remove_song(struct song_node *p,char *a,char *n){
struct song_node *curr = (struct song_node*)malloc(sizeof(struct song_node));
curr->next= p;
struct song_node *dummy = curr;
while(curr->next!=NULL){
  if(strcmp(curr->next->artist,a)==0 && strcmp(curr->next->name,n)==0){
    curr->next = curr->next->next;
    curr->next->next = 0;
    free(curr->next);
    curr=curr->next;
    break;
  }
}
}
int main(){
  struct song_node *head = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(head->artist,"pearl jam");
  strcpy(head->name,"alive");
  head->next =NULL;
  head = insert_inOrder(head,"pearl jam","yellow ledbetter");
  head = insert_inOrder(head,"pink floyd","time");
  head = insert_inOrder(head,"pearl jam","even flow");
  print_list(head);
 struct song_node *p = find_artist(head,"pearl jam");
  printf("%s \n", p->name);
  //print_list(head);

}
