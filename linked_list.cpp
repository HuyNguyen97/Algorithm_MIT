#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
	node(int pl=0, node* n_ptr=NULL) :
        data(pl), next(n_ptr) {};
};

struct list_node{
	node* head;
};

node* create_node(int key){
	node* new_node=new node;
	if(new_node){
		new_node->data= key;
		new_node->next=NULL;
	}
	return new_node;
}

void insert_first(list_node* pList, int key){
	struct node* new_node=new node;
	new_node->data=key;
	new_node->next=NULL;
	if(pList->head==NULL){
		pList->head= new_node;
	}
	else{
		new_node->next=pList->head;
		pList->head=new_node;
	}
}
//find length recursion
int length_list(node* pGo){
	if(pGo==NULL) return 0;
	else{
		return length_list(pGo->next)+1;
	}
}
//find length iterative
int length_list_iterative(node* pGo){

}
//reverse recursion
node* reverse_list_recursion(node* current){
	node* new_begin=NULL;
	if(!current){  //check if list rong
		return current;
	}
	if(current->next){
		new_begin=reverse_list_recursion(current->next);
	}
	else{
		return current;
	}
	current->next->next=current;
	current->next=NULL;
	return new_begin;
}

//reverse iterative

node* reverse_iterative(list_node* list){
	node* prev=NULL;
	node* current=list->head;
	node* pNext;
	while(current){
		pNext=current->next;
		current->next=prev;
		prev=current;
		current=pNext;
	}
	return prev;
}
//merge two sorted linked list
node* merge_list(node* list_a, node* list_b){
	if(list_a==NULL){
		return list_b;
	}
    if(list_b==NULL){
		return list_a;
	}
	node* new_root=NULL;
	if(list_a->data <= list_b->data){
		new_root=list_a;
		new_root->next=merge_list(list_a->next,list_b);
	}
	else{
		new_root=list_b;
		new_root->next=merge_list(list_a,list_b->next);
	}
	return new_root;
}
void insert_last(struct list_node* pList, int key){
	node* new_node=new node;
	new_node->data=key;
	new_node->next=NULL;
	if(pList->head==NULL){
		pList->head=new_node;
	}
	else{
		node* pGo=pList->head;
		while(pGo->next !=NULL){
			pGo=pGo->next;
		}
		pGo->next=new_node;
	}
}

void print_list(node* pGo){
	while(pGo!=NULL){
		cout<<pGo->data<<" ";
		if(pGo->next !=NULL){
			pGo=pGo->next;
		}
		else break;
	}
}
//---------------------------------------------------------------------------------------
int main(){
	list_node* list=new list_node;
	list->head=NULL;
	insert_first(list,1);
	insert_first(list,2);
	insert_first(list,3);
	insert_first(list,4);
    node* pGo=list->head;
    while(pGo !=NULL){
    	cout<<pGo->data<<"->";
    	if(pGo->next !=NULL) pGo=pGo->next;
    	else break;
    }
    
    //cout<<pGo->next->data<<endl;
    cout<<"------------------------"<<endl;
    insert_last(list,5);
	insert_last(list,6);
	pGo=list->head;
	
   
    cout<<endl;
    print_list(pGo);
    cout<<endl;
    list->head=reverse_iterative(list);
    pGo=list->head;
    print_list(pGo);

    //---------------------
    if(list !=NULL) {
    	node* pDel=NULL;
    	while(list->head !=NULL){
    		pDel=list->head;
    		list->head=list->head->next;
    		delete pDel;
    	}
    }
	return 0;
}
