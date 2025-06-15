#include "../headers/controler_header/mostrar_estatistica.h"
#include <stdio.h>

void mostrar_estatistica(const Tarefa* tasks, int task_count) {
    if (task_count == 0) {
        printf("Nenhuma tarefa cadastrada para exibir estatísticas.\n");
        return;
    }

    int total_tarefas = task_count;
    int concluidas = 0;
    int prioridade[3] = {0}; // Índices: 0=baixa, 1=média, 2=alta

    // Contar tarefas concluídas e por prioridade
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].concluida) {
            concluidas++;
        }
        
        // Contar por prioridade (1-3, ajustando para índice 0-2)
        if (tasks[i].prioridade >= 1 && tasks[i].prioridade <= 3) {
            prioridade[tasks[i].prioridade - 1]++;
        }
    }

    float percentual_concluidas = (float)concluidas / total_tarefas * 100;
    int pendentes = total_tarefas - concluidas;

    // Exibir estatísticas
    printf("\n📊 ESTATÍSTICAS DAS TAREFAS\n");
    printf("==========================================\n");
    printf("Total de tarefas: %d\n", total_tarefas);
    printf("Tarefas concluídas: %d (%.1f%%)\n", concluidas, percentual_concluidas);
    printf("Tarefas pendentes: %d (%.1f%%)\n", pendentes, 100 - percentual_concluidas);
    printf("\n📌 Distribuição por prioridade:\n");
    printf("  🔴 Alta prioridade: %d tarefas\n", prioridade[2]);
    printf("  🟡 Média prioridade: %d tarefas\n", prioridade[1]);
    printf("  🟢 Baixa prioridade: %d tarefas\n", prioridade[0]);
    printf("==========================================\n");
}