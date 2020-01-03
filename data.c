#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
// Input: ’in_name’: a string ends with ’\0’
// ’in_id’: an integer
// Output: a pointer of type pointer to Key,
// pointing to an allocated memory containing a Key
// Effect: dynamically allocate memory to hold a Key
// set Key’s id to be in_id
// dynamically allocate memory for the Key’s name
// so that name will contain what is in ’in_name’.
// Note: may use strdup()
Key *key_construct(char *in_name, int in_id) {
    Key *key= (Key *) malloc(sizeof(key_construct));
    key->name=strdup(in_name);
    key->id=in_id;
    return key;
}
// Input: ’key1’ and ’key2’ are two Keys
// Output: if return value < 0, then key1 < key2,
// if return value = 0, then key1 = key2,
// if return value > 0, then key1 > key2,
// Note: use strcmp() to compare key1.name and key2.name
// if key1.name = key2.name, then compare key1.id with key2.id
int key_comp(Key key1, Key key2) {
int result=0;
result=strcmp(key1.name,key2.name);
if(result==0){
    if(key1.id > key2.id){
        return 1;
    }
    if(key1.id<key2.id){
        return -1;
    }
    if(key1.id==key2.id){
        return 0;
    }
}
else{
    result=strcmp(key1.name,key2.name);
}
return result;
}
// Input: ’key’: a pointer to Key
// Effect: ( key->name key->id ) is printed
void print_key(Key *key) {
    printf("%s\t%d\n",key->name,key->id);

}
// Input: ’node’: a node
// Effect: node.key is printed and then the node.data is printed
void print_node(Node node) {
      int strleng=strlen(node.key->name);
      int intleng=1,keyid,total=25;
      keyid=(node.key->id)/10;
      if(0<=keyid&&keyid<1){
          intleng=1;
      }
      else if(1<=keyid&&keyid<10){
          intleng=2;
      }
      else if(10<=keyid&&keyid<100){
          intleng=3;
      }
      total=total-strleng-intleng;
      printf(" (%s",node.key->name);
      int i;
      for(i=0;i<=total;i++){
          printf(" ");
      }
      printf("%d )",node.key->id);
      printf("   %d\n",node.data);
}
