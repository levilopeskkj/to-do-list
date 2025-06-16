#ifndef TAREFAS_H
#define TAREFAS_H

#include <stdbool.h>

#define MAX_DESCRIPTION 256
#define MAX_TAREFAS 100
#define MAX_TAGS 10
#define MAX_TAG_LENGTH 20
#define MAX_TITLE_LENGTH 100

// Definição da estrutura Tarefa
typedef struct {
    int id;
    bool concluida;
    char titulo[MAX_TITLE_LENGTH];
    char descricao[MAX_DESCRIPTION];
    int prioridade; // 1 a 3
    char tags[MAX_TAGS][MAX_TAG_LENGTH];
    int num_tags;
    int data_criacao; // Unix timestamp
    int data_vencimento; // Unix timestamp
    char responsavel[MAX_TITLE_LENGTH];
    int status; // 0: pendente, 1: em andamento, 2: concluída
    bool soft_deleted; // Para exclusão suave
    int dependencias[MAX_TAREFAS]; // IDs de tarefas dependentes
    int num_dependencias;
} Tarefa;

#endif // TAREFAS_H
