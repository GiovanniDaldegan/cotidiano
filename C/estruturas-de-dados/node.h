#ifndef NODE_H
#define NODE_H

typedef enum {INT, FLOAT} DataType;

typedef struct Node Node;

/*
  Estrutura genérica que suporta os tipos listados em enum DataType.
  - funções:
    PrintValue()
*/
struct Node
{
  DataType type;
  void* value;
  struct Node* link;

  void* (*PrintValue)(Node*);
};

/*
  Imprime o valor armazenado no nó na formatação pertinente ao tipo definido em
  type. Chamada por ponteiro de função em Node.
  
  NOTE: não sei se uma definição global é ideal, já que a ideia é que ela seja
  exclusivamente chamada por node->PrintValue(node).
*/
void* PrintValue(Node *);

/*
  Aloca memória para um novo nó de lista encadeada, atribui o valor e o
  endereço do próximo nó passados e retorna seu endereço.
  - retorna:
    NULL se type for inválido;
    Node* do próximo nó.
*/
struct Node* InitNode(DataType, void*, struct Node*);

#endif
