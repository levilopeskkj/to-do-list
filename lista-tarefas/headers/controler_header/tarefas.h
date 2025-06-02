#ifndef TAREFAS_H
#define TAREFAS_H
#define MAX_TASKS 100
#define MAX_DESCRIPTION 256

typedef struct {
    char descricao[256];
    int concluida;  // 0 = não concluída, 1 = concluída
    int id;
} Tarefa;

extern Tarefa tasks[MAX_TASKS];
extern int task_count; //extern mostra que a variável existe em outro lugar para não ficar com problema, pois todas as funções do tarefa.c usa essa variável//levi
extern int next_id;

void adicionar_tarefa();
void listar_tarefas();
void concluir_tarefa();
void remover_tarefa();

#endif 