struct song_node{
  char artist[256];
  char name[256];
  struct song_node* next;
};
struct song_node* insert_front(struct song_node*,char*,char*);
struct song_node* insert_inOrder(struct song_node*,char*,char*);
struct song_node* free_list(struct song_node*);
