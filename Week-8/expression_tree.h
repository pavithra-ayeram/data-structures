//Header file to implement expression tree using binary tree
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class tree{
    public:
        struct tree_node{
            char data;
            tree_node* left;
            tree_node* right;
        };
        struct tree_node* root;

        tree(){
            root=nullptr;
        }

        struct tree_node* get_root();
        bool isoperand(char);
        bool isvalid(char*);
        char insert(struct tree_node*, char);   
        struct tree_node* construct_tree(char*); 
        void preorder(struct tree_node*);   
        void inorder(struct tree_node*);
        void postorder(struct tree_node*);
};

class stack{
    private:
        struct stack_node{
            tree :: tree_node* data;
            stack_node *next;
        };

        struct stack_node* top;
    
    public:
        stack(){
            top=nullptr;
        }

        char push(struct tree :: tree_node*);
        struct tree :: tree_node* pop();
        struct tree :: tree_node* peek();
};

//Method to get the root node of the tree. Time Complexity O(1).
tree :: tree_node* tree :: get_root(){
    return root;
}

//Method to check if the character is an operand. Time Complexity O(1).
bool tree ::  isoperand(char c){
    return ((c >= '0' && c<='9'));
}

//Method to check if the given postfix expression is valid. Time Complexity O(n).
bool tree :: isvalid(char* postfix_exp) {
    int operand_count = 0;
    int operator_count = 0;

    for (int i = 0; postfix_exp[i] != '\0'; i++) {
        if (postfix_exp[i] >= '0' && postfix_exp[i] <= '9') {
            operand_count++;
        } else if (postfix_exp[i] == '+' || postfix_exp[i] == '-' || postfix_exp[i] == '*' || postfix_exp[i] == '/') {
            operator_count++;
            if (operand_count < 2) {
                printf("Invalid postfix expression: insufficient operands for operator %c\n", postfix_exp[i]);
                return false;
            }
            operand_count--;
        }
    }

    if (operand_count != 1 || operator_count == 0) {
        printf("Invalid postfix expression!\n");
        return false;
    }

    return true;
}

//Method to insert a node into the tree. Time Complexity O(n).
char tree :: insert(struct tree_node* parent, char data) {
    if (!parent) {
        printf("Invalid parent node!\n");
        return 0;
    }

    struct tree_node* newnode = (struct tree_node*)malloc(sizeof(struct tree :: tree_node));
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;

    if (root == nullptr) {
        root = newnode;
    } 
    else {
        if (!parent->left) {
            parent->left = newnode;
        } 
        else if (!parent->right) {
            parent->right = newnode;
        } 
        else {
            printf("Parent node is full!\n");
            free(newnode);
            return 0;
        }
    }

    return 1;
}

//Method to construct the expression tree. Time Complexity O(n).
tree :: tree_node* tree :: construct_tree(char* postfix_exp){
    char ch;
    stack s;
    for (int i=0; postfix_exp[i]!='\0'; i++){
        ch=postfix_exp[i];
        struct tree_node* newnode= (struct tree_node*)malloc(sizeof(struct tree :: tree_node));
        newnode->data=ch;
        newnode->left=nullptr;
        newnode->right=nullptr;
        if(isoperand(ch)){
            s.push(newnode);
        }
        else{
            newnode->right=s.pop();
            newnode->left=s.pop();

            s.push(newnode);
        }
    }
    return s.pop();
} 

//Method to display the tree in preorder. Time Complexity O(n).
void tree :: preorder(struct tree_node* temp){
    if(!temp){
        return;
    }
    else{
        printf("%c ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

//Method to display the tree in inorder. Time Complexity O(n).
void tree :: inorder(struct tree_node* temp){
    if(!temp){
        return;
    }
    else{
        inorder(temp->left);
        printf("%c ", temp->data);
        inorder(temp->right);
    }
}

//Method to display the tree in postorder. Time Complexity O(n).
void tree :: postorder(struct tree_node* temp){
    if(!temp){
        return;
    }
    else{
        postorder(temp->left);
        postorder(temp->right);
        printf("%c ", temp->data);
    }
}

//Method to push a node into the stack. Time Complexity O(1).
char stack :: push(struct tree :: tree_node* temp){
    struct stack_node* newnode=(struct stack_node*)malloc(sizeof(struct stack_node));
    newnode->data = temp;
    newnode -> next = top;
    top=newnode;
    return '1';
}

//Method to pop a node from the stack. Time Complexity O(1).
tree :: tree_node* stack :: pop(){
    struct stack_node*  temp = top;
    if(!top){
        printf("Stack Underflow!");
        return nullptr;
    }
    else{
        top=top->next;
        tree :: tree_node* del_val =temp->data;
        free(temp);
        return del_val;
    }
}

//Method to view the top element of the stack. Time Complexity O(1).
tree :: tree_node* stack :: peek(){
    if(!top){
        printf("Stack Empty!");
        return nullptr;
    }
    else{
        return top->data;
    }
}