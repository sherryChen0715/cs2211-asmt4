//
// Created by tamaki on 2018/11/11.
//

#ifndef ASS4_BST_H
#define ASS4_BST_H
// ====== this is in bst.h
#include "data.h"
typedef struct {Node *tree_nodes; unsigned char *is_free; int size;} BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key *key, int data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
int getIndex(BStree bst,Key *key);
void bst_insertinsesrt(BStree bst, Key *key, int data,int index);
void bst_traversal(BStree bst, int index);
#endif //ASS4_BST_H
