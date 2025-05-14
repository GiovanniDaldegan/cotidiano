#ifdef STACK_H
#define STACK_H

typedef struct Node;
typedef struct Stack;

/*
  Aloca espaço para um novo nó, atribui o valor e o ponteiro passados e
  retrona seu endereço.
*/
struct Node* InitNode(int, struct Node*);
/*
  Aloca espaço para uma nova stack, atribui seus valores iniciais e retorna
  seu endereço.
*/
struct Stack* InitStack();


/*
  Instancia um novo nó, atribui seu valor e o insere no topo da stack.
  - chamadas: InitNode()
*/
void Push(struct Stack*, int value);
/*
  Remove o nó do topo da stack e libera sua memória.
*/
void Pop(struct Stack*);

/*
  Checa se a stack está vazia.
*/
void IsEmptyStack(struct Stack*);

/*
  Remove todos os nós da stack a partir do topo.
*/
void ClearStack(struct Stack*);
/*
  Remove todos os nós da stack e libera sua memória.
  - chamadas: ClearStack()
*/
void DeleteStack(struct Stack*);

/*
  Imprime o valor do nó e chama PrintNode(lower) passando o ponteiro do nó
  abaixo na stack (reverse = 1 inverte essa ordem).
  - chamadas PrintNode()
*/
void PrintNode(struct Node*, int);
/*
  Imprime a sequência da stack de cima pra baixo (reverse = 1 inverte a ordem).
*/
void PrintStack(struct Stack*, int);


#endif
