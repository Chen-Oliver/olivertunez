#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  print_node(p);

  printf("Finding song: time\n");
  struct song_node *t = find_song(head,"time");
  print_node(t);

  printf("Finding song: sandstorm\n");
  struct song_node *notfound = find_song(head,"sandstorm");
  print_node(notfound);

  printf("Testing random function...\n");
  struct song_node *random = random_node(head);

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
  
  printf("freeing list...\n");
  head = free_list(head);
  print_list(head);

  printf("Testing library functions\n=================================\n");
  struct song_node *table[26];
  int i=0;
  for(;i<26;i++)table[i]=0;
  printf("Library set to empty\n");
  printf("printing empty library: \n");
  printLib(table);
  printf("Adding a-lettered list to library using add_song function\n");
  struct song_node *alist = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(alist->artist,"adele");
  strcpy(alist->name,"hello");
  table[0] = alist;
  table[0]->next = NULL;
  add_song(table,"adele","rolling in the deep");
  add_song(table,"aerosmith","dream on");
  printf("Calling print letter function for a\n");
  printLetter(table,'a');

  printf("Adding some more songs...\n");
  struct song_node *mlist = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(mlist->artist,"muse");
  strcpy(mlist->name,"supremacy");
  table[12] = mlist;
  table[12]->next = NULL;
  add_song(table,"meek mill","levels");
  struct song_node *llist = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(llist->artist,"led zeppelin");
  strcpy(llist->name,"when the levee breaks");
  table[11] = llist;
  table[11]->next = NULL;
  add_song(table,"led zeppelin","kashmir");
  add_song(table,"lil wayne","lollipop");
  struct song_node *elist = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(elist->artist,"eminem");
  strcpy(elist->name,"lose yourself");
  table[4] = elist;
  table[4]->next = NULL;
  struct song_node *rlist = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(rlist->artist,"rick astley");
  strcpy(rlist->name,"never gonna give you up");
  table[17] = rlist;
  table[17]->next = NULL;

  printf("Calling print library function...\n");
  printLib(table);

  printf("Testing print artist on led zeppelin...\n");
  printArtist(table,"led zeppelin");

  printf("Testing find song in library on levels\n");
  struct song_node *levels = findlib_song(table,"levels");
  print_node(levels);
  printf("Testing find artist in library on adele\n");
  struct song_node *adele = findlib_artist(table,"adele");
  print_node(adele);
  printf("testing shuffle function...\n");
  shuffle(table);
  printf("testing delete song function on never gonna give you up...\n");
  delete_song(table,"rick astley","never gonna give you up");
  printf("after removing song:\n");
  printLib(table);
  printf("testing delete library function...\n");
  delete_all(table);
  printf("after deleting library:\n");
  printLib(table);
}
