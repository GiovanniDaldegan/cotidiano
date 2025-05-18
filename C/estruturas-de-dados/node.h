#ifndef NODE_H
#define NODE_H

typedef enum {INT, FLOAT} DataType;

/*
  Estrutura genérica que suporta os tipos listados em enum DataType.
  - funções:
    PrintValue()
*/
typedef struct Node
{
  DataType type;
  void* value;
  struct Node* link;

  void* (*PrintValue)(struct Node*);
} Node;

/*
  Imprime o valor armazenado no nó na formatação pertinente ao tipo definido em
  type. Chamada por ponteiro de função em Node.
*/

/*
  Aloca memória para um novo nó de lista encadeada, atribui o valor e o
  endereço do próximo nó passados e retorna seu endereço.
  - retorna:
    NULL se type for inválido;
    Node* do próximo nó.
*/
Node* InitNode(DataType, void*, Node*);

#endif
