//Program to implement Tree ADT using Character Binary Tree.
#include <stdio.h>
#include <stdlib.h>

class tree {
private:
    struct node {
        struct node* parent;
        struct node* left;
        char key;
        struct node* right;
    };

    struct node* root;

public:
    tree() {
        root = nullptr;
    }

    struct node* get_root();
    char insert(char);
    char del_element(char);
    void preorder(struct node*);
    void inorder(struct node*);
    void postorder(struct node*);
    struct node* search(struct node*, char);
};

//Method to get the root of the binary tree
tree :: node* tree :: get_root(){
    return root;
}

// Method to insert an element into the tree. Time Complexity O(n).
char tree::insert(char ele) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = ele;
    newnode->left = nullptr;
    newnode->right = nullptr;

    if (root == nullptr) {
        root = newnode;
    }
    else {
        struct node* current = root;
        char choice;

        while (current != nullptr) {
            newnode->parent = current;
            printf("\nDo you want to go left or right for %c? (L/R): ", current->key);
            scanf(" %c", &choice);

            if (choice == 'L' || choice == 'l') {
                if(current->left==nullptr){
                    current->left=newnode;
                    break;
                }
                current = current->left;
            }
            else if (choice == 'R' || choice == 'r') {
                if(current->right==nullptr){
                    current->right=newnode;
                    break;
                }
                current = current->right;
            }
            else {
                printf("\nInvalid choice! Enter the correct choice.\n");
                continue;
            }
        }
    }

    return '1';
}

//Method to delete an element from the tree. Time Complexity O(n).
char tree :: del_element(char ele) {
    struct node* parent = nullptr;
    struct node* current = search(root, ele);

    if (current == nullptr) {
        printf("Element not found in the tree!\n");
        return '-';
    }

    if (current != root) {
        parent = current->parent;
    }

    // Case 1: No child
    if (current->left == nullptr && current->right == nullptr) {
        if (current == root) {
            root = nullptr;
        }
        else {
            if (parent->left == current) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        free(current);
    }

    // Case 2: One child
    else if (current->left == nullptr || current->right == nullptr) {
		struct node* child = nullptr;

		if(current->left!=nullptr){
			child=current->left;
		}
		else{
			child=current->right;
		}

        if (current == root) {
            root = child;
        }
        else {
            if (parent->left == current) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
        if(child){
            child->parent=parent;
        }
        free(current);
    }

    // Case 3: Two children
    else {
        struct node* successor = current->right;
        struct node* successor_parent = current;

        while (successor->left != nullptr) {
            successor_parent = successor;
            successor = successor->left;
        }

        current->key = successor->key;

        if (successor_parent->left == successor) {
            successor_parent->left = successor->right;
        }
        else {
            successor_parent->right = successor->right;
        }
        if(successor->right){
            successor->right->parent=successor->right;
        }
        free(successor);
    }

    return ele;
}

// Method to display the elements of the tree in pre-order. Time Complexity O(n).
void tree :: preorder(struct node* temp) {
    if (temp == nullptr) {
        return;
    }
    else {
        printf("%c ", temp->key);
        preorder(temp->left);
        preorder(temp->right);
    }
}

// Method to display the elements of the tree in in-order. Time Complexity O(n).
void tree :: inorder(struct node* temp) {
    if (temp == nullptr) {
        return;
    }
    else {
        inorder(temp->left);
        printf("%c ", temp->key);
        inorder(temp->right);
    }
}

// Method to display the elements of the tree in post-order. Time Complexity O(n).
void tree :: postorder(struct node* temp) {
    if (temp == nullptr) {
        return;
    }
    else {
        postorder(temp->left);
        postorder(temp->right);
        printf("%c ", temp->key);
    }
}

// Method to search for an element in the tree. Time Complexity O(n).
tree :: node* tree :: search(struct node* temp, char ele) {
    if (temp == nullptr) {
        return nullptr;
    }
    if (temp->key == ele) {
        return temp;
    }
    struct node* left_result = search(temp->left, ele);
    if (left_result != nullptr) {
        return left_result;
    }
    else {
        return search(temp->right, ele);
    }
}

int main() {
    tree t;
    int choice;
    char element;

    while (1) {
        printf("\nMENU\n1. Insert\n2. Delete\n3. Pre-order\n4. In-order\n5. Post-order\n6. Search\n7. Exit\nEnter your choice: ");
        scanf(" %d", &choice);
        printf("\n");

        switch (choice) {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf(" %c", &element);

            if (t.insert(element)) {
                printf("\nInsertion Sucessful!");
            }
            else {
                printf("\nInsertion failed!");
            }
            break;

        case 2:
            printf("Enter the element to be deleted: ");
            scanf(" %c", &element);
            if (t.del_element(element)) {
                printf("\nDeletion Successful!");
            }
            else {
                printf("\nDeletion Failed!");
            }
            break;

        case 3:
            if (t.get_root() == nullptr) {
                printf("\nThe tree is empty!");
            } 
			else {
				t.preorder(t.get_root());
			}
            printf("\n");
			break;

		case 4:
            if (t.get_root() == nullptr) {
                printf("\nThe tree is empty!");
            } 
			else {
				t.inorder(t.get_root());
			}
            printf("\n");
			break;

		case 5:
            if (t.get_root() == nullptr) {
                printf("\nThe tree is empty!");
            } 
			else {
				t.postorder(t.get_root());
			}
            printf("\n");
			break;

		case 6:
			printf("Enter the element to be searched: ");
			scanf(" %c", &element);
			if (t.search(t.get_root(), element) == nullptr) {
				printf("\nElement not found in the tree");
			}
			else {
				printf("\n%c was found in the tree", element);
			}
			break;

		case 7:
			exit(0);
			break;

		default:
			printf("Invalid Choice!");
			break;
		}
	}
	return 0;
}