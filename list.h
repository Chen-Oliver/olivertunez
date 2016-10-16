struct song_node{
  char artist[256];
  char name[256];
  struct song_node* next;
};
struct song_node* insert_front(struct song_node*,char*,char*);
struct song_node* insert_inOrder(struct song_node*,char*,char*);
struct song_node* free_list(struct song_node*);
void print_list(struct song_node *);
int compNodes(struct song_node *, struct song_node *);
char* lowercase(char *);
struct song_node *find_song(struct song_node *,char *);
struct song_node *find_artist(struct song_node *,char *);
struct song_node* random_node(struct song_node *);
struct song_node* remove_song(struct song_node *,char *,char *);
void print_node(struct song_node *);
int mystrcmp(char *, char *);
