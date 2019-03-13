// binary tree

#include<iostream>
using namespace std;

//node class

class node{
	public:
		int data;
		
		node * left;
		node* right;
		
		//constructor
		node(int val){
			data=val;
			left=NULL;
			right=NULL;
		}
		
		
};

class Bist{
	public:
		node* root;
		
		Bist(){
			root=NULL;
			
		}
		
		void insert(int value){
			insertHelper(root,value);
		}
		void insertHelper(node* curr, int value){
			// case if curr is nULL
			if(curr==NULL){
				curr=new node(value);
				if(root==NULL){
					root=curr;
				}
				return;
			}
			//else compare the curr data wth value
			else if(curr->data>value){
				//curr=curr->left;
				if(curr->left==NULL) curr->left=new node(value);
				else
				insertHelper(curr->left,value);
			}
			else{
				//curr=curr->right;
				if(curr->right==NULL) curr->right=new node(value);
				else
				insertHelper(curr->right,value);
			}
				
			}
			
			//display
			
			void display(){
				display2(root);
			}
		void display2(node* curr){
			if(curr==NULL)
			return;
			display2(curr->left);
			cout<<curr->data<<",";
			display2(curr->right);			
			}
		
		// search
		node* search(node* curr,int value){
			if(curr==NULL || curr->data==value) return curr;
			else if(value<curr->data) return search(curr->left,value);
			else return search(curr->right,value);
		}	

		
	
		node* search();
		height();
		deleteNode();
};

// main function

int main(){
	Bist l;
	l.insert(10);
	l.insert(6);
	l.insert(13);
	l.insert(7);
	l.insert(8);
	l.display();
}
