#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "list.h"
#include "songlib.h"
int main(){
  struct song_node *table[26];
  int i=0;
  for(;i<26;i++)table[i]=0;
  struct song_node *alist = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(alist->artist,"adele");
  strcpy(alist->name,"hello");
  table[0] = alist;
  table[0]->next = NULL;
  libadd("AC/DC","highway to hell");
  struct song_node *plist = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(plist->artist,"pearl jam");
  strcpy(plist->name,"alive");
  table[15] = plist;
  table[15]->next =NULL;
  table[15] = insert_inOrder(plist,"pearl jam","yellow ledbetter");
  table[15] = insert_inOrder(plist,"pink floyd","time");
  table[15] = insert_inOrder(plist,"pearl jam","even flow");
}
