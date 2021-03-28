#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int passengerID;
	struct node* left;
	struct node* right;
	int height;
	node()
	{
		passengerID = 0;
		left = NULL;
		right = NULL;
		height = 0;
	}
	node(int x)
	{
		left = NULL;
		right = NULL;
		passengerID = x;
		height = 0;
	}
};
class PassengerTree
{
public:
	node* treeRoot; 
	int numOfNodes=0;
	PassengerTree()
	{
		treeRoot = NULL;
	}
	//~PassengerTree();
	node* RR(node* root)
	{
		root = LeftRotate(root);
		root->height = root->left->height > root->right->height ? (root->left->height) : (root->right->height);
		return root;
	}
	node* LL(node* root)
	{
		root = RightRotate(root);
		root->height = root->left->height > root->right->height ? (root->left->height) : (root->right->height);
		return root;
	}
	node* LR(node* root)
	{
		root->right = RightRotate(root->left);
		root = LeftRotate(root);
		root->height = root->left->height > root->right->height ? (root->left->height) : (root->right->height);
		return root;
	}
	node* RL(node* root)
	{
		root->left = LeftRotate(root->left);
		root = RightRotate(root);
		root->height = root->left->height > root->right->height ? (root->left->height) : (root->right->height);
		return root;
	}
	node* LeftRotate(node* root)
	{
		if (root != NULL)
		{
			node* tmp = new node();
			tmp->passengerID = root->passengerID;
			tmp->left = root->left;
			tmp->right = NULL;
			if (root->right != NULL)
			{
				if (root->right->left != NULL)
					tmp->right = root->right->left;
			}
			root = root->right;
			if (tmp->passengerID == treeRoot->passengerID)
				treeRoot = root;
			root->left = new node();
			root->left = insertNode(tmp, tmp->passengerID);
			return root;
		}
	}
	node* RightRotate(node* root)
	{
		if (root != NULL)
		{
			node* tmp = new node();
			tmp->passengerID = root->passengerID;
			tmp->right = root->right;
			tmp->left = NULL;
			if (root->left != NULL)
			{
				if (root->left->right != NULL)
					tmp->left = root->left->right;
			}
			root = root->left;
			if (tmp->passengerID == treeRoot->passengerID)
				treeRoot = root;
			root->right = new node();
			root->right = insertNode(tmp, tmp->passengerID);
			return root;
		}
	}
	int calcBalanceFactor(node* root)
	{
		int balance=0;
		int left=0;
		int right=0;
		if (root != NULL)
		{
			if (root->right == NULL && root->left != NULL)
				return left+=getNodeHeight(root->left)+1;
			if (root->left == NULL && root->right != NULL)
				return right+=0-(getNodeHeight(root->right)+1);
			return balance = getNodeHeight(root->left) - getNodeHeight(root->right);
		}
	}
	node* balanceTree(node* root)
	{
		int balance = calcBalanceFactor(root);
		int leftbalance= calcBalanceFactor(root->left);
		int rightbalance = calcBalanceFactor(root->right);
		if (balance==2)
		{
			if (leftbalance == 1)
			{
				root = LL(root);
			}
			if (rightbalance == -1)
			{
				root=LR(root);
			}
		}
		if (balance == -2)
		{
			if (rightbalance == -1)
			{
				root = RR(root);
			}
			if (rightbalance == +1)
			{
				root = RL(root);
			}
		}
		return root;
	}
	node* insertNode(node* root, int value)
	{
		if (treeRoot == NULL)
		{
			return treeRoot = new node(value);
		}
		if (root == NULL)
		{
			return root = new node(value);
		}
		if (value > root->passengerID)
		{
			root->right=insertNode(root->right, value);
		}
		if (value < root->passengerID)
		{
			root->left=insertNode(root->left, value);
		}
		treeRoot->height=getNodeHeight(treeRoot)+1;
		if(calcBalanceFactor(treeRoot)>1 || calcBalanceFactor(treeRoot)<-1)
			balanceTree(treeRoot);
		root->height=getNodeHeight(root)+1;
		if (calcBalanceFactor(root)>1 || calcBalanceFactor(root)<-1)
			root=balanceTree(root);
		return root;
	}
	int getNodeHeight(node *root)
	{
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right==NULL)
			return 0;
		if (root->left != NULL)
			root->left->height = getNodeHeight(root->left)+1;
		if (root->right != NULL)
			root->right->height = getNodeHeight(root->right)+1;
		if (root->left == NULL || root->right == NULL)
		{
			if (root->left != NULL)
				return root->left->height;
			if (root->right != NULL)
				return root->right->height;
		}
		else
		{
			root->height = 0;
			root->height = root->left->height > root->right->height ? (root->left->height) : (root->right->height);
		}
		return root->height;
	}
	int numofnodes(node* root)
	{
		int counter = 0;
		if (root != NULL)
		{
			if(root->left!=NULL)
			counter += numofnodes(root->left) + 1;
			if(root->right!=NULL)
			counter += numofnodes(root->right) + 1;
		}
		return counter;
	}
	/**
		Add necessary methods here
	*/
};