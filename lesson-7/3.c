#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
  uint8_t key;
  struct tree *left, *right;
  struct tree *parent;
} tree;

void insert(tree **root, int key, tree *parent)
{
  if (!(*root))
  {
    // дерево пустое или дошли до нужного места
    *root = calloc(1, sizeof(tree));
    (*root)->key = key;
    (*root)->parent = parent;
  }
  else if (key < (*root)->key)
    insert(&((*root)->left), key, *root);
  else
    insert(&((*root)->right), key, *root);
}

tree *findKey(tree *root, int key)
{
  if (root == NULL)
    return NULL;
  if (key < root->key)
  {
    return findKey(root->left, key);
  }
  else if (root->key < key)
  {
    return findKey(root->right, key);
  }
  else
    return root;
}

tree *findBrother(tree *root, int key)
{
  tree *node = findKey(root, key);
  if (node == NULL)
    return NULL;
  if (node->key < node->parent->key)
    return node->parent->right;
  else
    return node->parent->left;
}

int main(void)
{
  tree *binary_tree = NULL;
  insert(&binary_tree, 10, NULL);
  insert(&binary_tree, 5, binary_tree);
  insert(&binary_tree, 15, binary_tree);
  insert(&binary_tree, 3, binary_tree->left);
  insert(&binary_tree, 7, binary_tree->left);
  insert(&binary_tree, 13, binary_tree->right);
  insert(&binary_tree, 18, binary_tree->right);
  insert(&binary_tree, 1, binary_tree->left->left);
  insert(&binary_tree, 6, binary_tree->left->right);

  tree *brother = findBrother(binary_tree, 3);
  if (brother)
    printf("имеет брата %d\n", brother->key);
  else
    printf("не имеет брата\n");

  return 0;
}
