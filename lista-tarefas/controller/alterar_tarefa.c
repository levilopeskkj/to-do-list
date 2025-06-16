#include "../headers/controler_header/alterar_tarefa.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "../headers/controler_header/utils.h"
#include "../headers/controler_header/buscar_tarefa.h"

void alterar_tarefa(Tarefa* tasks, int task_count) {
    if (task_count == 0) {
        printf("Nenhuma tarefa disponível para alterar.\n");
        return;
    }

    int id;
    printf("\n📝 Digite o ID da tarefa que deseja alterar: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            found = 1;
            printf("\n📝 Tarefa encontrada!\n");
            printf("ID: %d\n", tasks[i].id);
            printf("Status: %s\n", tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente");
            printf("Descrição: %s\n", tasks[i].descricao);
            printf("Prioridade: %d\n", tasks[i].prioridade);

            int opcao;
            printf("\n📝 O que você deseja alterar?\n");
            printf("1. Descrição\n");
            printf("2. Prioridade\n");
            printf("3. Status\n");
            printf("Digite sua escolha (1-3): ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1: { // Alterar descrição
                    char nova_descricao[MAX_DESCRIPTION];
                    printf("📝 Digite a nova descrição: ");
                    scanf("%*c"); // Limpa o buffer do scanf anterior
                    fgets(nova_descricao, sizeof(nova_descricao), stdin);
                    nova_descricao[strcspn(nova_descricao, "\n")] = '\0';
                    strcpy(tasks[i].descricao, nova_descricao);
                    break;
                }
                case 2: { // Alterar prioridade
                    int nova_prioridade;
                    printf("📝 Digite a nova prioridade (1-3): ");
                    scanf("%d", &nova_prioridade);
                    if (nova_prioridade >= 1 && nova_prioridade <= 3) {
                        tasks[i].prioridade = nova_prioridade;
                    } else {
                        printf("❌ Prioridade inválida! Deve ser entre 1 e 3.\n");
                    }
                    break;
                }
                case 3: { // Alterar status
                    printf("📝 Selecione o novo status:\n");
                    printf("1. Pendente\n");
                    printf("2. Concluída\n");
                    printf("Digite sua escolha (1-2): ");
                    scanf("%d", &opcao);
                    tasks[i].concluida = (opcao == 2);
                    break;
                }
                default:
                    printf("❌ Opção inválida!\n");
                    break;
            }

            printf("✅ Tarefa alterada com sucesso!\n");
            break;
        }
    }

    if (!found) {
        printf("❌ Nenhuma tarefa encontrada com o ID especificado.\n");
    }

    printf("==========================================\n");

    printf("\nDeseja voltar ao menu principal? (s/n): ");
    char resposta;
    scanf(" %c", &resposta);
    if (tolower(resposta) != 's') {
        printf("\nRetornando ao menu principal...\n");
    }
}
