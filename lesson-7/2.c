#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
  uint8_t key;
  struct tree *left, *right;
} tree;

void insert(tree **root, int key)
{
  if (!(*root))
  {
    // дерево пустое или дошли до нужного места
    *root = calloc(1, sizeof(tree));
    (*root)->key = key;
  }
  else if (key < (*root)->key)
    insert(&((*root)->left), key);
  else
    insert(&((*root)->right), key);
}

void btUpLeftView(tree *root)
{
  if (root->left)
  {
    btUpLeftView(root->left);
  }
  printf("%d ", root->key);
}

void btUpRighttView(tree *root)
{
  printf("%d ", root->key);
  if (root->right)
  {
    btUpRighttView(root->right);
  }
}

void btUpView(tree *root)
{
  if (root->left)
    btUpLeftView(root->left);
  btUpRighttView(root);
}

int main(void)
{
  tree *binary_tree = NULL;
  insert(&binary_tree, 10);
  insert(&binary_tree, 5);
  insert(&binary_tree, 15);
  insert(&binary_tree, 3);
  insert(&binary_tree, 7);
  insert(&binary_tree, 13);
  insert(&binary_tree, 18);
  insert(&binary_tree, 1);
  insert(&binary_tree, 6);

  btUpView(binary_tree);

  return 0;
}
