#include <iostream>

using namespace std;

struct node{
	string data;
	node* next;
};

struct Stack{
	node* top;
	int count;
};

void init(Stack* stack){
	int count =0;
	stack->top=NULL;
	cout<<"succesful"<<endl;
}
void push(Stack* stack, string key){
	node* new_node=new node;
	new_node->data = key;
	new_node->next = NULL;
	if(stack->top == NULL){
		stack->top=new_node;
		stack->count++;
	}
	else{
		new_node->next=stack->top;
		stack->top=new_node;
	}
}

string peek(Stack* stack){
	if(stack->top == NULL) return "$";
	else{
		return stack->top->data;
	}
}

void pop(Stack* stack){
	if(stack->top == NULL) return;
	else{
		node* pGo = stack->top;
		stack->top = stack->top->next;
		delete pGo;
		pGo=NULL;
		stack->count--;
	}
}

int is_operand(char str){
	return(('a' <= str && str <= 'z') || ('A'<=str && str <= 'Z'));
}
void postfix_evaluation(Stack* stack, string postfix){
	string infix ="";
	string temp="";
	string convert="";
	//node* pGo=stack->top;
	for(int i=0;i<=postfix.length()-1;i++){
		if(is_operand(postfix[i])){
			std::string convert(1,postfix[i]);
			push(stack, convert);
			convert ="";
		}
		else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^'){
			temp =temp + "(" + stack->top->next->data + postfix[i] + stack->top->data + ")";
			pop(stack);
			pop(stack);
			push(stack, temp);
			temp ="";
		}
	}
	infix =infix + peek(stack);
	cout<<infix<<endl;
}

int main(){
	Stack* stack=new Stack;
	init(stack);
	string postfix="abcd^e-fgh*+^*+i-";
	postfix_evaluation(stack, postfix);
	return 0;
}