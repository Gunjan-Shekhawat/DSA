# IN C 
struct node  
{ 
  int data; 
  struct node *left; 
  struct node *right; 
};

# IN CPP

struct Node { 
  int key; 
  Node *left, *right; 
  Node (int x) 
  { 
     key = x; 
     left = right = NULL; 
  } 
};
