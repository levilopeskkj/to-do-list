#ifndef TAREFAS_H
#define TAREFAS_H

#include <stdbool.h>

#define MAX_DESCRIPTION 256
#define MAX_TAREFAS 100

// Definição da estrutura Tarefa
typedef struct {
    int id;
    bool concluida;
    char descricao[MAX_DESCRIPTION];
    int prioridade; // 1 a 3
} Tarefa;

#endif // TAREFAS_H
