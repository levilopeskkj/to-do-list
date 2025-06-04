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

// Protótipos das funções
void adicionar_tarefa(Tarefa* tasks, int* task_count, int* next_id, int* prioridade);
void listar_tarefas(const Tarefa* tasks, int task_count);
void concluir_tarefa(Tarefa* tasks, int* task_count);
void remover_tarefa(Tarefa* tasks, int* task_count);
void buscar_tarefa(const Tarefa* tasks, int task_count);
void alterar_tarefa(Tarefa* tasks, int task_count);
void mostrar_estatisticas(const Tarefa* tasks, int task_count);

#endif // TAREFAS_H