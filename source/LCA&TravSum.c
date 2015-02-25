#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	int sum;
	struct Node* left;
	struct Node* right;
	
};

typedef struct Node Node;

Node* GetNode(int ky)
{
	Node* tmp = (Node*)malloc(sizeof(Node*));
	tmp->data = ky;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

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

Node* LCA(Node* root,Node* t1,Node *t2)
{
	Node* temp = (Node*)malloc(sizeof(Node*));
	Node* tmp = (Node*)malloc(sizeof(Node*));
	temp = root;
	int a[50]={0};
	int b[50]={0};
	int i=0,j=0;

	while(temp!=t1)
	{
		if(temp->data > t1->data)
		{
			a[i++] = temp->data;
			temp = temp->left;
		}
		else if(temp->data < t1->data)
		{
			a[i++] = temp->data;
			temp = temp->right;
		}
	}
	temp = root;
	while(temp!=t2)
	{
		if(temp->data > t2->data)
		{
			b[j++] = temp->data;
			temp = temp->left;
		}
		else if(temp->data < t2->data)
		{
			b[j++] = temp->data;
			temp = temp->right;
		}
	}

	i=0;
	j=0;
	while(a[i] == b[i] && a[i]!=0)
	{	
		//printf("a[%d] = %d\n",i,a[i]);		
		i++;
	}
	tmp = Find(root,a[i-1]);
	
	free(t1);
	free(t2);
	return tmp;
	
}

void Inorder(Node* root)
{
	//Node* tp = (Node*)malloc(sizeof(Node*));
	//tp = root;
	if(root == NULL)
		return;	
	
		Inorder(root->left);
		root->sum = 0;
		Inorder(root->right);
	
	
}

void TravSum(Node* root,int* sm)
{
	//*sm = 0;	
	if(root->right != NULL)
		TravSum(root->right,sm);
	
	root->sum = *sm;
	printf("%d ",root->sum);
	//printf("%d ",root->data);
	*sm = *sm + root->data;
	
	if(root->left != NULL)
		TravSum(root->left,sm);
	
}

void PrintTravSum(Node* root)
{
	if(root == NULL)
		return;
	PrintTravSum(root->left);
	printf("%d ",root->sum);
	PrintTravSum(root->right);
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
		
		
	int sum = 0;
	head = Insert(head,4);
	head = Insert(head,2);
	head = Insert(head,3);
	head = Insert(head,1);
	head = Insert(head,6);
	head = Insert(head,5);
	head = Insert(head,7);
	//head = Insert(head,0);
	
	printf("Head is %d\n",head->data);
	//Ino(head);
	//Inorder(head); //For making all node's sum = 0

	//hd = LCA(head,head->left->left,head->right->right);
	//printf("The LCA is %d\n",hd->data);
	//Inorder(head);
	TravSum(head,&sum);
	printf("\n");
	//PrintTravSum(head);

}
