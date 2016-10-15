#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "list.h"

void print_node(struct song_node *p){
  printf("%s ",p->artist);
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
char* lowercase(char *p){
  char *orig = p;
  while(*p){
    *p=tolower(*p);
    p++;
  }
  return orig;
}
int compNodes(struct song_node *first, struct song_node *second){ //compares two nodes by artist then by name
  if(strcmp(lowercase(first->artist),lowercase(second->artist))==0){
  //  printf("%d\n",strcmp(first->name,second->name));
    return strcmp(lowercase(first->name),lowercase(second->name));
  }
  else{
  //  printf("%d\n",strcmp(first->artist,second->artist));
  return strcmp(lowercase(first->artist),lowercase(second->artist));
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
    if(strcmp(lowercase(curr->artist),lowercase(a))==0)return curr;
    else curr= curr->next;
  }
  return NULL;
}
struct song_node *find_song(struct song_node *p,char *n){
  struct song_node *curr = (struct song_node*)malloc(sizeof(struct song_node));
  curr = p;
  while(curr){
    if(strcmp(lowercase(curr->name),lowercase(n))==0)return curr;
    else curr= curr->next;
  }
  return NULL;
}
//remove a song
struct song_node* remove_song(struct song_node *p,char *a,char *n){
  struct song_node* curr = p;
  struct song_node* prev = NULL;
  while(curr){
    if(strcmp(lowercase(curr->artist),lowercase(a))==0 && strcmp(lowercase(curr->name),lowercase(n))==0){
      if(prev==NULL){
        free(p);
        return curr = curr->next;;
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
  srand(time(NULL));
  int index = rand()%length(p);
  int i;
  for(i=0;i<index;i++)p=p->next;
  return p;
}
int main(){
  struct song_node *head = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(head->artist,"pearl jam");
  strcpy(head->name,"alive");
  head->next =NULL;
  head = insert_inOrder(head,"pearl jam","yellow leDBetter");
  head = insert_inOrder(head,"pInk floyd","time");
  head = insert_inOrder(head,"PeArL jAm","eveN flow");
  print_list(head);
  //struct song_node *p = find_artist(head,"pearl jam"); //test find
  //printf("%s \n", p->name);
/* head = remove_song(head,"pearl jam","alive");  //test remove
  print_list(head);
  head = remove_song(head,"pearl jam","yellow ledbetter");
  print_list(head);
  */
 /* struct song_node *random = random_node(head); //test random song
 print_node(random); */
}
