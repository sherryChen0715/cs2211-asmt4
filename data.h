//
// Created by tamaki on 2018/11/11.
//

#ifndef ASS4_DATA_H
#define ASS4_DATA_H

typedef struct {char *name; int id;} Key;
typedef struct {Key *key; int data;} Node;
Key *key_construct(char *in_name, int in_id);
int key_comp(Key key1, Key key2);
void print_key(Key *key);
void print_node(Node node);

#endif //ASS4_DATA_H
