#include <iostream>
#include <queue>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

struct binary_tree{
	node* root;
};

node* new_node_of_tree(int key){
	node* new_node = new node;
	new_node->data = key;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void insert_node(binary_tree*& tree, int key){	
	node* pTemp = new_node_of_tree(key);
	if(tree->root == NULL){
		tree->root = pTemp;
		return;
	}
	
}

node* inorder_traversal(node* pGo){
	if(pGo == NULL) return NULL;
	else{
		inorder_traversal(pGo->left);
		cout << pGo->data << " ";
		inorder_traversal(pGo->right);
	}
}

//BFS on tree using queue
void bfs(node* pGo){
	if(pGo == NULL) return;
	queue<node *> my_queue;
	my_queue.push(pGo);
	while(my_queue.empty() == false){
		node* temp = my_queue.front();
		cout << temp->data << " ";
		my_queue.pop();
		if(temp->left != NULL){
			my_queue.push(temp->left);
		}
		if(temp->right != NULL){
			my_queue.push(temp->right);
		}
	}
}

//bfs using recursion
int height_binary_tree(node* pGo){
	if(pGo == NULL) return 0;
	int lheight = height_binary_tree(pGo->left);
	int rheight = height_binary_tree(pGo->right);
	if(lheight > rheight) return lheight;
	else return rheight;
}

void print_level_node(node* pGo, int level){
	if(pGo == NULL) return;
	if(level == 1) cout << pGo->data << " ";
	else if(level > 1){
		print_level_node(pGo->left, level - 1);
		print_level_node(pGo->right, level - 1);
	}
}

void print_bfs_recursion(node* pGo){
	if(pGo == NULL) return;
	int level = height_binary_tree(pGo);
	for(int i = i; i <= level; i++){
		print_level_node(pGo, level);
	}
}


//LCA: lowest common ancester
//this method is in O(n), but does not cover all corner case, for example if one in two node does not
//exist in tree
//assumming that there are nodes with the same value
node* find_LCA(node* root, int n1, int n2){
	if(root == NULL) return NULL;
	if(root->data == n1 || root->data == n2){
		return root;
	}
	node* left_LCA = find_LCA(root->left, n1, n2);
	node* right_LCA = find_LCA(root->right, n1, n2);
	if(left_LCA && right_LCA) return root;
	return (left_LCA != NULL) ? left_LCA : right_LCA;
}

int distance_root_to_node(node* root, int key){
	if(root == NULL) return 0;
	if(root->data == key) return key;
	int level = distance_root_to_root(root->left, );
}
 int main(){
 	//queue
 	//build tree
 	binary_tree* tree = new binary_tree;
 	tree->root = NULL;
 	tree->root = new_node_of_tree(1);
 	tree->root->left = new_node_of_tree(2);
 	tree->root->right = new_node_of_tree(3);
 	tree->root->left->left = new_node_of_tree(4);
 	tree->root->left->right = new_node_of_tree(5);
 	tree->root->right->left = new_node_of_tree(6);
 	tree->root->right->right = new_node_of_tree(7);
 	node* pGo = tree->root;
 	
 	print_bfs_recursion(pGo);
 
 	return 0;
 }