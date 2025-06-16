#include "../headers/controler_header/remover_tarefa.h"
#include <stdio.h>
#include <string.h>
#include "../headers/controler_header/utils.h"

void remover_tarefa(Tarefa* tasks, int* task_count) {
    if (*task_count == 0) {
        printf("❌ Nenhuma tarefa disponível para remover.\n");
        return;
    }

    printf("🔍 SISTEMA DE BUSCA DE TAREFAS\n");
    printf("==========================================\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por descrição\n");
    printf("3. Buscar por status (concluída/pendente)\n");
    printf("4. Buscar por prioridade (1-3)\n");
    printf("0. Voltar\n");
    printf("==========================================\n");

    while (1) {
        printf("\nDigite sua opção: ");
        int opcao;
        scanf("%d", &opcao);

        if (opcao == 0) break;

        switch (opcao) {
            case 1: // Buscar por ID
                printf("Digite o ID da tarefa: ");
                int id;
                scanf("%d", &id);

                for (int i = 0; i < *task_count; i++) {
                    if (tasks[i].id == id) {
                        mostrar_detalhes_tarefa(&tasks[i]);
                        printf("⚠️ Tem certeza que deseja remover esta tarefa? (s/n): ");
                        char confirmacao;
                        scanf(" %c", &confirmacao);

                        if (tolower(confirmacao) == 's') {
                            printf("⚠️ Esta ação não pode ser desfeita. Confirmar? (s/n): ");
                            scanf(" %c", &confirmacao);
                            if (tolower(confirmacao) == 's') {
                                // Remover a tarefa e ajustar IDs
                                for (int j = i; j < *task_count - 1; j++) {
                                    tasks[j] = tasks[j + 1];
                                    tasks[j].id = j + 1; // Ajusta o ID para ser sequencial
                                }
                                (*task_count)--;
                                // Ajusta o próximo ID disponível
                                if (i < *task_count) {
                                    for (int k = i; k < *task_count; k++) {
                                        tasks[k].id = k + 1;
                                    }
                                }
                                printf("✅ Tarefa removida com sucesso!\n");
                                return;
                            }
                        }
                    }
                }
                printf("❌ Tarefa não encontrada com ID %d.\n", id);
                break;

            case 2: // Buscar por descrição
                printf("Digite a descrição (ou parte dela): ");
                char descricao[256];
                scanf(" %[^\n]", descricao);
                int encontradas = 0;

                printf("\n🔍 Encontradas %d tarefas:\n\n", encontradas);
                for (int i = 0; i < *task_count; i++) {
                    if (busca_descricao_insensitive(tasks[i].descricao, descricao)) {
                        encontradas++;
                        printf("%d. ID: %d - %s\n", encontradas, tasks[i].id, tasks[i].descricao);
                        printf("   Status: %s | Prioridade: %s\n\n",
                            tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente",
                            tasks[i].prioridade == 1 ? "🔴 Alta" :
                            tasks[i].prioridade == 2 ? "🟡 Média" : "🟢 Baixa");
                    }
                }

                if (encontradas > 0) {
                    printf("Digite o ID da tarefa para remover: ");
                    int id;
                    scanf("%d", &id);
                    for (int i = 0; i < *task_count; i++) {
                        if (tasks[i].id == id) {
                            mostrar_detalhes_tarefa(&tasks[i]);
                            printf("⚠️ Tem certeza que deseja remover esta tarefa? (s/n): ");
                            char confirmacao;
                            scanf(" %c", &confirmacao);

                            if (tolower(confirmacao) == 's') {
                                printf("⚠️ Esta ação não pode ser desfeita. Confirmar? (s/n): ");
                                scanf(" %c", &confirmacao);
                                if (tolower(confirmacao) == 's') {
                                    // Remover a tarefa
                                    for (int j = i; j < *task_count - 1; j++) {
                                        tasks[j] = tasks[j + 1];
                                    }
                                    (*task_count)--;
                                    printf("✅ Tarefa removida com sucesso!\n");
                                    return;
                                }
                            }
                        }
                    }
                    printf("❌ Tarefa não encontrada com ID %d.\n", id);
                } else {
                    printf("❌ Nenhuma tarefa encontrada com a descrição especificada.\n");
                }
                break;

            case 3: // Buscar por status
                printf("Digite 1 para pendentes ou 2 para concluídas: ");
                int status;
                scanf("%d", &status);
                if (status != 1 && status != 2) {
                    printf("❌ Entrada inválida. Use 1 para pendentes ou 2 para concluídas.\n");
                    break;
                }

                printf("\n🔍 Encontradas %d tarefas:\n\n", encontradas);
                for (int i = 0; i < *task_count; i++) {
                    if ((status == 1 && !tasks[i].concluida) || (status == 2 && tasks[i].concluida)) {
                        encontradas++;
                        printf("%d. ID: %d - %s\n", encontradas, tasks[i].id, tasks[i].descricao);
                        printf("   Status: %s | Prioridade: %s\n\n",
                            tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente",
                            tasks[i].prioridade == 1 ? "🔴 Alta" :
                            tasks[i].prioridade == 2 ? "🟡 Média" : "🟢 Baixa");
                    }
                }

                if (encontradas > 0) {
                    printf("Digite o ID da tarefa para remover: ");
                    int id;
                    scanf("%d", &id);
                    for (int i = 0; i < *task_count; i++) {
                        if (tasks[i].id == id) {
                            mostrar_detalhes_tarefa(&tasks[i]);
                            printf("⚠️ Tem certeza que deseja remover esta tarefa? (s/n): ");
                            char confirmacao;
                            scanf(" %c", &confirmacao);

                            if (tolower(confirmacao) == 's') {
                                printf("⚠️ Esta ação não pode ser desfeita. Confirmar? (s/n): ");
                                scanf(" %c", &confirmacao);
                                if (tolower(confirmacao) == 's') {
                                    // Remover a tarefa
                                    for (int j = i; j < *task_count - 1; j++) {
                                        tasks[j] = tasks[j + 1];
                                    }
                                    (*task_count)--;
                                    printf("✅ Tarefa removida com sucesso!\n");
                                    return;
                                }
                            }
                        }
                    }
                    printf("❌ Tarefa não encontrada com ID %d.\n", id);
                } else {
                    printf("❌ Nenhuma tarefa encontrada com o status especificado.\n");
                }
                break;

            case 4: // Buscar por prioridade
                printf("Digite a prioridade (1=Alta, 2=Média, 3=Baixa): ");
                int prioridade;
                scanf("%d", &prioridade);
                if (!validar_prioridade(prioridade)) {
                    printf("❌ Prioridade inválida. Use 1 para Alta, 2 para Média ou 3 para Baixa.\n");
                    break;
                }

                printf("\n🔍 Encontradas %d tarefas:\n\n", encontradas);
                for (int i = 0; i < *task_count; i++) {
                    if (tasks[i].prioridade == prioridade) {
                        encontradas++;
                        printf("%d. ID: %d - %s\n", encontradas, tasks[i].id, tasks[i].descricao);
                        printf("   Status: %s | Prioridade: %s\n\n",
                            tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente",
                            tasks[i].prioridade == 1 ? "🔴 Alta" :
                            tasks[i].prioridade == 2 ? "🟡 Média" : "🟢 Baixa");
                    }
                }

                if (encontradas > 0) {
                    printf("Digite o ID da tarefa para remover: ");
                    int id;
                    scanf("%d", &id);
                    for (int i = 0; i < *task_count; i++) {
                        if (tasks[i].id == id) {
                            mostrar_detalhes_tarefa(&tasks[i]);
                            printf("⚠️ Tem certeza que deseja remover esta tarefa? (s/n): ");
                            char confirmacao;
                            scanf(" %c", &confirmacao);

                            if (tolower(confirmacao) == 's') {
                                printf("⚠️ Esta ação não pode ser desfeita. Confirmar? (s/n): ");
                                scanf(" %c", &confirmacao);
                                if (tolower(confirmacao) == 's') {
                                    // Remover a tarefa
                                    for (int j = i; j < *task_count - 1; j++) {
                                        tasks[j] = tasks[j + 1];
                                    }
                                    (*task_count)--;
                                    printf("✅ Tarefa removida com sucesso!\n");
                                    return;
                                }
                            }
                        }
                    }
                    printf("❌ Tarefa não encontrada com ID %d.\n", id);
                } else {
                    printf("❌ Nenhuma tarefa encontrada com a prioridade especificada.\n");
                }
                break;
        }
    }
}
