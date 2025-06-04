#ifndef TAREFAS_H
#define TAREFAS_H
#define MAX_DESCRIPTION 256

// Definição da estrutura Tarefa
struct Tarefa {
    int id;
    bool concluida;
    char descricao[MAX_DESCRIPTION];
    int prioridade; // 1 a 3

};

typedef struct Tarefa Tarefa;

// Protótipos das funções
void adicionar_tarefa(Tarefa* tasks, int* task_count, int* next_id, int* prioridade);
void listar_tarefas(const Tarefa* tasks, int task_count);
void concluir_tarefa(Tarefa* tasks, int* task_count);
void remover_tarefa(Tarefa* tasks, int* task_count);
void buscar_tarefa(const Tarefa* tasks, int task_count);
void alterar_tarefa(Tarefa* tasks, int task_count);

#endif 