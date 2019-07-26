#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

typedef struct leaf{
    struct leaf *left;
    struct leaf *right;
    struct leaf *parent;
    char item;
}Leaf;

int isNodeExp(Leaf *node){
    if (node->item >= '0' && node->item <= '9'){
        return 0;
    }
    else{
        return 1;
    }
}

int main(int argc, char *argv[]){
    char *a = argv[1];
    char N = strlen(a);
    STACKinit(N);
    for (int i = 0; i < N; i++){
        if (a[i] >= '0' && a[i] <= '9'){
            Leaf *t = malloc(sizeof(Leaf));
            t->right = NULL;
            t->left = NULL;
            t->parent = NULL;
            t->item = a[i];
            STACKpush((void *)t);
        }
        if (a[i] == '*' || a[i] == '/' || a[i] == '*' || a[i] == '-' || a[i] == '+'){
            Leaf *t = malloc(sizeof(Leaf));
            t->parent = NULL;
            t->right = (Leaf*)STACKpop();
            t->left = (Leaf*)STACKpop();
            t->item = a[i];
            t->right->parent = t;
            t->left->parent = t;
            STACKpush((void *)t);
        }
    }
    Leaf *node = (Leaf*)STACKpop();
    while(node != NULL){
        if (node->left != NULL){
            printf("(");
            node = node->left;
        }
        else if(!isNodeExp(node) && (node == node->parent->left)){
            printf("%c", node->item);
            node = node->parent;
            node->left = NULL;
        }
        else if(isNodeExp(node) && (node->left == NULL) && (node->right != NULL)){
            printf(" %c ", node->item);
            node = node->right;
        }
        else if (node->right != NULL){
            node = node->right;
        }
        else if(!isNodeExp(node) && (node == node->parent->right)){
            printf("%c", node->item);
            node = node->parent;
            node->right = NULL;
        }
        else if(!node->left && !node->right){
            if (node->parent == NULL){
                node = node->parent;
                printf(")");
            }
            else if (node == node->parent->left){
                node = node->parent;
                printf(")");
                node->left = NULL;
            }
            else if (node == node->parent->right){
                node = node->parent;
                printf(")");
                node->right = NULL;
            }
            else{
                break;
            }
        }
    }
    printf("\n");
}