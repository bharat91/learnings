#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node Node;

Node* Insert(Node* root,int x)
{
	
	Node *rt = (Node* )malloc(sizeof(Node));
	rt->data = x;
	
	Node *temp = (Node* )malloc(sizeof(Node));
	temp = root;
	if(root==NULL)
		return rt;
		
	else
	{
		if(rt->data < root->data)
			root->left = Insert(root->left,x);
		if(rt->data >= root->data)
			root->right = Insert(root->right,x);
		return root;
	}
	
	free(rt);
	free(temp);

}

void LeftView(Node* root)
{
	//Node* temp = (Node*)malloc(sizeof(Node*));
	//temp = root;
	
	if(root == NULL)
		return;
	while(root != NULL)
	{	
		if(root->left != NULL)
		{
			printf("%d ",root->data);
			
			LeftView(root->left);
		}
		if(root->right != NULL)
		{
			printf("%d ",root->data);			
			
			LeftView(root->right);
		}	
	}
	

}

void Ino(Node* root)
{
	if(root == NULL)
		return;
	Ino(root->left);
	printf("%d ",root->data);
	Ino(root->right);
}

int main()
{
	Node* head = NULL;
	Node* hd = (Node*)malloc(sizeof(Node*));
		
		
	
	head = Insert(head,4);
	head = Insert(head,2);
	head = Insert(head,3);
	head = Insert(head,1);
	head = Insert(head,6);
	head = Insert(head,5);
	head = Insert(head,7);
	
	printf("The head is %d\n",head->data);
	printf("hellp\n");
	//Ino(head);
	LeftView(head);
}
