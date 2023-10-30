#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T 3

typedef char TYPE;
typedef struct BTree {
    int n;
    TYPE keys [2*T - 1];
    struct BTree *child [2*T];
    bool leaf;
} BTree;

BTree* createBtree () {
    BTree *a = (BTree *)malloc (sizeof (BTree));
    a->n = 0;
    a->leaf = true;
    return a;
}

void printBtree (BTree *a, int level) {
    int i;
    for (i = 0; i < level; i++) {
        printf (" ");
    }
    printf ("|");
    for (i = 0; i < a->n; i++) {
        printf ("%c|", a->keys [i]);
    }
    printf ("\n");
    for (i = 0; i <= a->n; i++) {
        if (a->leaf == false) {
            printBtree (a->child [i], level + 1);
        }
    }
}

BTree* splitNode (BTree *x, int i, BTree *y) {
    int j;
    BTree *z = createBtree ();
    z->n = T - 1;
    for (j = 0; j < T - 1; j++) {
        z->keys [j] = y->keys [j+T];
    }
    if (y->leaf == false) {
        for (j = 0; j < T; j++) {
            z->child [j] = y->child [j+T];
        }
    }
    y->n = T - 1;
    for (j = x->n; j >= i+1; j--) {
        x->child [j+1] = x->child [j];
    }
    x->child [i+1] = z;
    
    for (j = x->n-1; j >= i; j--) {
        x->keys [j+1] = x->keys [j];
    }
    
    x->keys [i] = y->keys [T-1];
    
    x->n++;
    
    return x;
}

BTree* insertNonFull (BTree *x, TYPE k) {
    int i = x->n-1;
    
    if (x->leaf == true) {
        while (i >= 0 && x->keys [i] > k) {
            x->keys [i+1] = x->keys [i];
            i--;
        }
        
        x->keys [i+1] = k;
        
        x->n++;
        
    } else {
        while (i >= 0 && x->keys [i] > k) {
            i--;
        }
        
        i++;
        
        if (x->child [i]->n == 2*T-1) {
            x = splitNode (x, i, x->child [i]);
            
            if (k > x->keys [i]) {
                i++;
            }
        }
        
        x->child [i] = insertNonFull (x->child [i], k);
        
    }
    
    return x;
}

BTree* insert(BTree *root, TYPE k) {
    
   BTree *r = root;
   
   if(r -> n == (2*T - 1)) {
       BTree *s = createBtree();
       s -> leaf = false;
       s -> child[0] = r;
       s = splitNode(s, 0, r);
       s = insertNonFull(s, k);
       return s;
   } else {
       return insertNonFull(r, k);
   }
}

int main () {

   BTree *a = createBtree();
   
   a = insert(a, 'F');
   a = insert(a, 'S');
   a = insert(a, 'Q');
   a = insert(a, 'K');
   a = insert(a, 'C');
   a = insert(a, 'L');
   a = insert(a, 'H');
   a = insert(a, 'T');
   a = insert(a, 'V');
   a = insert(a, 'W');
   a = insert(a, 'M');
   a = insert(a, 'R');
   a = insert(a, 'N');
   a = insert(a, 'P');
   a = insert(a, 'A');
   a = insert(a, 'B');
   a = insert(a, 'X');
   a = insert(a, 'Y');
   a = insert(a, 'D');
   a = insert(a, 'Z');
   a = insert(a, 'E');
   
   printBtree(a, 0);
   
   return 0;
}
