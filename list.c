#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"

void print_node(struct song_node *p){
  printf("\t%s ",p->artist);
  printf("- %s\n ",p->name);
}
void print_list(struct song_node *p){
  struct song_node *tmp = p;
  printf("songs:[ \n");
  while(tmp){
    print_node(tmp);
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

int compNodes(struct song_node *first, struct song_node *second){ //compares two nodes by artist then by name
  if(strcmp(first->artist,second->artist)==0){

    return strcmp(first->name,second->name);
  }
  else{

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
  printf("no songs by %s found\n",a);
  return NULL;
}
struct song_node *find_song(struct song_node *p,char *n){
  struct song_node *curr = (struct song_node*)malloc(sizeof(struct song_node));
  curr = p;
  while(curr){
    if(strcmp(curr->name,n)==0)return curr;
    else curr= curr->next;
  }
  printf("%s not found\n",n);
  return NULL;
}
//remove a song
struct song_node* remove_song(struct song_node *p,char *a,char *n){
  struct song_node* curr = p;
  struct song_node* prev = NULL;
  while(curr){
    if(strcmp(curr->artist,a)==0 && strcmp(curr->name,n)==0){
      if(prev==NULL){
	      curr = curr->next;
        free(p);
	return curr;
      }
      else{
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
        break;
      }
    }
      else{
        prev= curr;
        curr = curr->next;
      }
    }
    return p;
}
int length(struct song_node* p){
  int len = 0;
  while (p){
    len++;
    p = p->next;
  }
return len;
  }
struct song_node* random_node(struct song_node *p){
  //sranddev();
  srand(time(NULL));
  int index = rand()%length(p);
  int i;
  for(i=0;i<index;i++)p=p->next;
  return p;
}
