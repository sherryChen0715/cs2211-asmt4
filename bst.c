//
// Created by tamaki on 2018/11/11.
//
// ====== this is in bst.c
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned char array of size+1 for member is_free
// set all entries of is_free to 1
// set member size to ’size’;
BStree bstree_ini(int size) {
    BStree_struct *bst = (BStree_struct *)malloc(sizeof(BStree_struct));
    Node *tree_nodes = (Node *)malloc((size+1)* sizeof(Node));
    unsigned char *is_free = (unsigned char *)malloc((size+1) * sizeof(unsigned char));
    bst->is_free = is_free;
    int i;
    for(i=0;i<size+1;i++) {
        bst->is_free[i] = '1';
    }
    bst->tree_nodes = tree_nodes;
    bst->size = size;

    return bst;
}
// Input:
// ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing

void bstree_insert(BStree bst, Key *key, int data) {
    bst_insertinsesrt(bst, key, data,1);
}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
    bst_traversal(bst, 1);
}
// Input: ’bst’: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst) {
    free(bst->tree_nodes);
    free(bst->is_free);
    free(bst);
}
/**
 *
 * @param bst is a binary search tree
 * @param key a pointer to key
 * @param data an integer
 * @param index the position of nodes
 */
void bst_insertinsesrt(BStree bst, Key *key, int data,int index) {
        if(index>(*bst).size){  // if the index returned by the recursive is greator than size, than it is out of bound
            printf("out of bound\n");
        }
        if (bst->is_free[index] == '1') {// judge if the position is empty ,if yes than insert here
            bst->tree_nodes[index].key = key;
            bst->tree_nodes[index].data = data;
            bst->is_free[index] = '0';
    }
            if (key_comp(*key, *((*bst).tree_nodes[index].key)) < 0) {// otherwise , small than go left ,big than go right , use recursive , update the index each time
                index = index * 2;
                bst_insertinsesrt(bst, key, data, index);
            }
            if (key_comp(*key, *((*bst).tree_nodes[index].key)) > 0) {
                index = index * 2 + 1;
                bst_insertinsesrt(bst, key, data, index);
            }
        }

/**
 *
 * @param bst is a binary search tree
 * @param index the position of nodes
 */
void bst_traversal(BStree bst, int index){
    if(index < (*bst).size) {// use in order, go to the left first and then the current , finally the right
        bst_traversal(bst,2*index);
        if((*bst).is_free[index] == '0') {
            print_node((*bst).tree_nodes[index]);
        }
        bst_traversal(bst,2*index+1);
    }
}

