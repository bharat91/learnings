#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<stdbool.h>

int max(int a, int b)
{
	return (a>b)?a:b;	
}


struct Node
{
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

bool search(Node* root,int key)
{
	bool bl;
	if(root==NULL)
		return false;
	if(root->data == key)
		return true;	
	else if(root->data != key)
	{
		while(root!=NULL)
		{	
			if(key < root->data)
			{
				return search(root->left,key);
			}			
		
			else if(key > root->data)
				return search(root->right,key);
		}
	}
	
}

Node* Find(Node* root, int key)
{
	if(root->data == key)
		return root;	
	else if(root->data != key)
	{
		while(root!=NULL)
		{	
			if(key < root->data)
			{
				return Find(root->left,key);
			}			
		
			else if(key > root->data)
				return Find(root->right,key);
		}
	}
}

Node* FindMax(Node* root)
{
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp = root;
	while(temp->right!=NULL)
		temp = temp->right;
	return temp;
}


Node* FindMin(Node* root)
{
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp = root;
	while(temp->left!=NULL)
		temp = temp->left;
	return temp;
}
Node* InorderSucc(Node* root,int key)
{
	Node* current = (Node*)malloc(sizeof(Node*));
	
	current = Find(root,key);
	if(current->right != NULL)
		return FindMin(current->right);
	
	else 
	{
		Node* succ = NULL;		
		Node* temp;
		temp = root;
		while(temp!=current)
		{
			if(current->data < temp->data)
			{			
				succ = temp;
				temp = temp->left;
			} 
			else
				temp = temp->right;
		}
		return succ;	
	}
		
}

bool IsBST(Node* root)
{
	while(root!=NULL)
	{
		if((FindMax(root->left))->data < root->data && (FindMin(root->right))->data > root->data)
			return true;
		else 
			return false; 
	}
	return true;
	
		
}

/*Node* del(Node* root, int key)
{
	Node* hd = (Node*)malloc(sizeof(Node*));
	
	
			if(root->data != key)
			{
				if(key< root->data)
					while(key < root->data)
					{
						hd = root;					
						root = root->left;	
					}
				else if(key > root->data)
					while(key > root->data)
					{
						hd = root;					
						root = root->right;
					}
			}
			else if(root->data == key)
			{
				if(root->left == NULL && root->right == NULL)
					free(root);
				else if((root->left != NULL && root->right == NULL))
				{
					if(root->data > head->data)
					{
						hd->right = root->left;
						free(root);
					}
					else if(root->data < head->data)
					{
						hd->left = root->left;
						free(root);
					}
				}
				else if((root->left == NULL && root->right != NULL))
				{
					if(root->data > hd->data)
					{
						hd->right = root->right;
						free(root);
					}
					else if(root->data < hd->data)
					{
						hd->left = root->right;
						free(root);
					}
				}
				else if(root->left != NULL && root->right != NULL)		//two children
				{
					nd = findmin(root->right);
					if(root->data > hd->data)
					{
						hd->right = nd;
						nd->right = root->right;
						free(root);
					}
					else if(root->data < hd->data)
					{
						hd->left = root->right;
						free(root);
					}
				}
			}		
		}
			

	
}*/

int height(Node* root)
{
	if(root==NULL)
		return -1;
	else
		return max(height(root->left),height(root->right)) + 1;
		
}


int main()
{
	Node* head = NULL;
	Node* hd = (Node*)malloc(sizeof(Node*));
	bool present;
	bool check;
	int num;
	head = Insert(head,4);
	head = Insert(head,2);
	head = Insert(head,3);
	head = Insert(head,1);
	head = Insert(head,6);
	head = Insert(head,5);
	head = Insert(head,7);
	head = Insert(head,0);
	
	printf("\n Enter any number that you want to search\n");
	scanf("%d",&num);
	present = search(head,num);
	if(present == true)
		printf("Number found in that tree\n");
	else
		printf("Sorry, not found!\n");

	// Height of a tree
	printf("The height of this tree is %d\n",height(head));
	printf("Enter the node for which you want to find the inorder successor\n");
	scanf("%d",&num);
	hd = InorderSucc(head,num);
	printf("The inorder succ of %d is %d\n",num,hd->data);
	
	check = IsBST(head);
	if(check)
		printf("This tree is a BST\n");
	else
		printf("NO!!\n");

	//printf("\nRoot is %d\n",head->data);
}



