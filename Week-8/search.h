//Program to implement Binary Search Tree using linked lists
#include <stdio.h>
#include <stdlib.h>

class tree{
	private:
		struct node{
			struct node* parent;
			int key;
			struct node* left;
			struct node* right;
		};

		struct node* root;
	
	public:
		struct node* found;
		struct node* prev;
		struct node* next;
		struct node* head;

		tree(){
			root=nullptr;
		}

		struct node* get_root();
		int insert(struct node*&, int);
		int deletion(struct node*&, int);
		struct node* search(struct node*, int);
		void inorder(struct node*);
		void preorder(struct node*);
		void postorder(struct node*);
};

//Method to get the root of the tree. Time Complexity O(1).
tree :: node* tree :: get_root(){
	return root;
}

//Method to insert an element into the tree. Time Complexity O(n).
int tree :: insert(struct node*& temp, int value){
	if(temp==nullptr){
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		newnode->key = value;
		newnode->left = nullptr;
		newnode->right = nullptr;
		newnode->parent=nullptr;
		if(root==nullptr){
			root=newnode;
		}
		else{
			temp=newnode;
		}
		return 1;
	}
	else if(value < temp->key){
		if(temp->left == nullptr) {
			struct node* newnode = (struct node*)malloc(sizeof(struct node));
			newnode->key = value;
			newnode->left = nullptr;
			newnode->right = nullptr;
			newnode->parent = temp;
			temp->left = newnode;
			return 1;
		} else {
			return insert(temp->left, value);
		}
	}
	else{
		if(temp->right == nullptr) {
			struct node* newnode = (struct node*)malloc(sizeof(struct node));
			newnode->key = value;
			newnode->left = nullptr;
			newnode->right = nullptr;
			newnode->parent = temp;
			temp->right = newnode;
			return 1;
		} else {
			return insert(temp->right, value);
		}
	}
}

//Method to delete an element from the tree. Time Complexity O(n).
int tree :: deletion(struct node*& temp, int value){
	struct node* current = search(temp, value);
	if(!current){
		printf("\nElement not found in the tree");
		return 0;
	}

	struct node* current_parent=current->parent;
	
	//Case 1: No Child
	if(current->left==nullptr && current->right==nullptr){
		if(current==root){
			root=nullptr;
		}
		else if(current_parent->left==current){
			current_parent->left=nullptr;
		}
		else{
			current_parent->right=nullptr;
		}
		free(current);
	}

	//Case 2: One Child
	else if(current->left==nullptr || current->right==nullptr){
		struct node *child=nullptr;

		if(current->left!=nullptr){
			child=current->left;
		}
		else{
			child=current->right;
		}

		if(current==root){
			root=child;
			if(child!=nullptr){
				child->parent=nullptr;
			}
		}
		else{
			if(current_parent->left==current){
				current_parent->left=child;
				child->parent=current_parent;
			}
			else{
				current_parent->right=child;
				child->parent=current_parent;
			}
		}
		free(current);
	}

	//Case 3: Two Children.
	else{
		struct node* successor=current->right;
		struct node* successor_parent=current;

		while(successor->left!=nullptr){
			successor_parent=successor;
			successor=successor->left;
		}
		current->key=successor->key;

		if(successor_parent->left==successor){
			successor_parent->left=successor->right;
		}
		else{
			successor_parent->right=successor->right;
		}
		free(successor);
	}
	return 1;
}

//Method to print the elements of the tree in preorder. Time Complexity O(n).
void tree :: preorder(struct node *temp){
	if(temp==nullptr){
		return;
	}
	else{
		printf("%d ", temp->key);
		preorder(temp->left);
		preorder(temp->right);
	}
}

//Method to print the elements of the tree in inorder. Time Complexity O(n).
void tree :: inorder(struct node *temp){
	if(temp==nullptr){
		return;
	}
	else{
		inorder(temp->left);
		printf("%d ", temp->key);
		inorder(temp->right);
	}
}

//Method to print the elements of the tree in postorder. Time Complexity O(n).
void tree :: postorder(struct node *temp){
	if(temp==nullptr){
		return;
	}
	else{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ", temp->key);
	}
}

//Method to search for an element in the tree. Time Complexity O(n).
tree :: node* tree :: search(struct node* temp, int value){
	if(temp==nullptr){
		return nullptr;
	}
	else if(temp->key==value){
		return temp;
	}
	else if(value<temp->key){
		return search(temp->left, value);
	}
	else if(value>temp->key){
		return search(temp->right, value);
	}
}