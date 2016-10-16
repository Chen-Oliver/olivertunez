#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "list.h"
#include "songlib.h"
int main(){
  printf("Testing linked list functions\n=================================\n");
  printf("Creating head...\n");
  struct song_node *head = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(head->artist,"pearl jam");
  strcpy(head->name,"alive");
  head->next =NULL;
  printf("Printing current list...\n");
  print_list(head);
  printf("Testing insert_inOrder...\n");
  head = insert_inOrder(head,"pearl jam","yellow ledbetter");
  head = insert_inOrder(head,"pink floyd","time");
  head = insert_inOrder(head,"pearl jam","even flow");
  printf("Printing current list...\n");
  print_list(head);
  printf("Testing find_artist...\n");
  printf("Finding pearl jam...\n");
  struct song_node *p = find_artist(head,"pearl jam");
  printf("Artist found at %p: \n",p);
  printf("Printing artist and name at the address...\n");
  print_node(p);
  printf("Testing random function...\n");
  struct song_node *random = random_node(head); //test random song
  printf("Random function gave the follow: \n");
  print_node(random);
  printf("Testing remove function...\n");
  printf("Removing pearl jam - time...\n");
  head = remove_song(head,"pink floyd","time");
  printf("printing new list...\n");
  print_list(head);
  printf("Testing remove again...\n");
  printf("Removing pink floyd - alive...\n");
  head = remove_song(head,"pearl jam","alive");
  printf("printing new list...\n");
  print_list(head);
  printf("Testing library functions\n=================================\n");
  struct song_node *table[26];
  int i=0;
  for(;i<26;i++)table[i]=0;
  printf("Library set to empty\n");
  printf("Adding a-lettered list to library\n");
  struct song_node *alist = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(alist->artist,"adele");
  strcpy(alist->name,"hello");
  table[0] = alist;
  table[0]->next = NULL;
  libadd("AC/DC","highway to hell");
  printf("Calling print letter function for a\n");
  printLetter(table,'a');
}
