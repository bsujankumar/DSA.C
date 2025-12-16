#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}Node;

//insersion in BST
Node * newNode(int value){
    Node * temp = (Node *)malloc(sizeof(Node));
    temp -> data = value;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
Node * insert(Node *root, int value){
    if(root == NULL){
        root = newNode(value);
        return root;
    }
    if(value < root -> data){
        root -> left = insert(root -> left, value);
    }
    if(value > root -> data){
        root -> right = insert(root -> right, value);
    }
    return root;
}

//Preorder traversal
void preOrder(Node * root){
    if(root == NULL){
        return;
    }
    printf("%d\t", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}

//Inorder traversal
void inOrder(Node * root){
    if(root == NULL){
        return;
    }
    inOrder(root -> left);
    printf("%d\t", root -> data);
    inOrder(root -> right);
}

//Postorder traversal
void postOrder(Node * root){
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    printf("%d\t", root -> data);
}

//deleting a node in BST
Node * InOrderSuccessor(Node * root){
    while(root -> left != NULL){
        root = root -> left;
    }
    return root;
}
Node * delete(Node * root, int value){
    if(value < root -> data){
        root -> left = delete(root -> left, value);
    }
    else if(value > root -> data){
        root -> right = delete(root -> right, value);
    }
    else{
        //leaf node
        if(root -> left == NULL && root -> right == NULL){
            return NULL;
        }
        //single child
        if(root -> left == NULL){
            return root -> right;
        }else if(root -> right == NULL){
            return root -> left;
        }
        //two child
        Node * IS = InOrderSuccessor(root -> right);
        root -> data = IS -> data;
        root -> right = delete(root -> right, IS -> data);
    }
    return root;
}

//searching in BST
int search(Node * root, int key){
    if(root == NULL){
        return 0;
    }
    if(root -> data == key){
        return 1;
    }
    if(key < root -> data){
        return search(root -> left, key);
    }else{
        return search(root -> right, key);
    }
}

//height of BST
int height(Node * root){
    if(root == NULL){
        return -1;
    }
    int lh = height(root -> left);
    int rh = height(root -> right);
    return (lh > rh? lh : rh) + 1;
}

//count of nodes in BST
int count(Node * root){
    if(root == NULL){
        return 0;
    }
    int lc = count(root -> left);
    int rc = count(root -> right);
    return lc + rc + 1;
}

//sum of nodes in BST
int sum(Node * root){
    if( root == NULL){
        return 0;
    }
    int ls = sum(root -> left);
    int rs = sum(root -> right);
    return ls + rs + root -> data;
}

//lowest common ancestor
Node * lca(Node * root, int n1, int n2){
    if(root == NULL || root -> data == n1 || root -> data == n2){
        return root;
    }
    Node * leftlca = lca(root -> left, n1, n2);
    Node * rightlca = lca(root -> right, n1, n2);
    if(leftlca == NULL){
        return rightlca;
    }
    if(rightlca == NULL){
        return leftlca;
    }
    return root;
}

int main(){
    Node * root = NULL;

    //creating a BST
    int values[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    for(int i = 0; i < 9; i++){
        root = insert(root, values[i]);             
    }

    //preorder traversal
    preOrder(root);
    printf("\n\n");

    //inorder traversal
    inOrder(root);
    printf("\n\n");

    //postorder traversal
    postOrder(root);
    printf("\n\n");

    //deleting a node
    delete(root, 8);
    inOrder(root);
    printf("\n\n");

    //seraching 
    int key = 6;
    if(search(root, key)){
        printf("%d is found in BST\n\n", key);
    }else{
        printf("%d is not found in BST\n\n", key);
    }

    //lowest common ancestor
    int n1 = 3, n2 = 1;
    printf("%d is the lowest common ancestor of %d and %d\n\n",lca(root, n1, n2)->data, n1, n2);

    //height of BST
    printf("Height of the BST is : %d\n\n", height(root));

    //count of nodes in BST
    printf("Number of nodes in BST is : %d\n\n", count(root));

    //sum of nodes in BST
    printf("Sum of nodes in BST is : %d\n\n", sum(root));
}
