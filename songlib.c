#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songlib.h"
#include "list.h"

int alphaToNum(char *info){//get index of list to place song in
  //char letter = tolower(info[0]); //removed all lowercasing for convenience
  char letter = info[0];
  int index=-1;
  if (letter >= 'A' && letter <= 'Z')
    index = letter - 'A';
  else if (letter >= 'a' && letter <= 'z')
    index = letter - 'a';
  return index;
  }
void add_song(struct song_node* *lib, char *a,char*n){
  int index = alphaToNum(a);
  if(index == -1)printf("Invalid song\n");
  else lib[alphaToNum(a)]=insert_inOrder(lib[alphaToNum(a)],a,n);
}
struct song_node* findlib_artist(struct song_node* *lib,char *a){
  int index = alphaToNum(a);
  if(index == -1){
    printf("artist not found\n");
    return NULL;
  }
  else return find_artist(lib[index],a);
}
struct song_node* findlib_song(struct song_node* *lib,char *n){
  int i=0;
  for(;i<26;i++){
    if(find_song(lib[i],n)){
      return(find_song(lib[i],n));
    }
  }
  printf("song not found\n");
  return NULL;
}
void printLetter(struct song_node* *lib,char letter){
  int index = alphaToNum(&letter);
  if(index == -1)printf("Invalid letter\n");
  else{
    printf("%c ",letter);
    print_list(lib[index]);
  }
}
void printArtist(struct song_node* *lib,char* a){
  int index = alphaToNum(a);
  if(index == -1)printf("Invalid artist\n");
  else{
  struct song_node* curr = lib[index];
  int i = 0;
  while(curr){
    if (strcmp(curr->artist,a)==0){
      print_node(curr);
      i++;
    }
    curr = curr->next;
  }
    if (i==0)
    printf("no songs by %s found.\n",a);
}
}
void printLib(struct song_node **lib){
  int i=0;
  for(;i<26;i++)print_list(lib[i]);
}
void shuffle(struct song_node **lib){
  int i=0;
  for(;i<26;i++)if(lib[i])print_node(random_node(lib[i])); //if list not empty print random song
}
void delete_song(struct song_node **lib,char *a,char *n){
  int index = alphaToNum(a);
  if(index == -1)printf("Invalid artist\n");
  else lib[index] = remove_song(lib[index],a,n);
}
void delete_all(struct song_node **lib){
  int i=0;
  for(;i<26;i++)lib[i]=free_list(lib[i]);
}
