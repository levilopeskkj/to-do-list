#include "../headers/controler_header/utils.h"
#include <stdio.h>
#include <string.h>

// Função auxiliar para transformar string em lowercase
void str_to_lower(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower((unsigned char) str[i]);
}

// Função auxiliar para mostrar detalhes de uma tarefa
void mostrar_detalhes_tarefa(const Tarefa* task) {
    printf("\n📝 DETALHES DA TAREFA\n");
    printf("==========================================\n");
    printf("ID: %d\n", task->id);
    printf("Descrição: %s\n", task->descricao);
    printf("Status: %s\n", task->concluida ? "✅ Concluída" : "⏳ Pendente");
    printf("Prioridade: %s\n", 
        task->prioridade == 1 ? "🔴 Alta" :
        task->prioridade == 2 ? "🟡 Média" : 
        "🟢 Baixa");
    printf("==========================================\n");
}

// Função auxiliar para busca case-insensitive
bool busca_descricao_insensitive(const char* texto, const char* busca) {
    if (!texto || !busca) return false;
    char texto_lower[256];
    char busca_lower[256];
    strncpy(texto_lower, texto, 255);
    strncpy(busca_lower, busca, 255);
    texto_lower[255] = '\0';
    busca_lower[255] = '\0';
    
    for (int i = 0; texto_lower[i]; i++) {
        texto_lower[i] = tolower(texto_lower[i]);
    }
    for (int i = 0; busca_lower[i]; i++) {
        busca_lower[i] = tolower(busca_lower[i]);
    }
    
    return strstr(texto_lower, busca_lower) != NULL;
}

// Função auxiliar para validar prioridade
bool validar_prioridade(int prioridade) {
    return prioridade >= 1 && prioridade <= 3;
}

// Função auxiliar para validar descrição
bool validar_descricao(const char* descricao) {
    return strlen(descricao) > 0 && strlen(descricao) < MAX_DESCRIPTION;
}

// Função auxiliar para mostrar preview das alterações
void mostrar_preview(Tarefa* antes, Tarefa* depois) {
    printf("\n🔄 CONFIRMAÇÃO DE ALTERAÇÃO\n");
    printf("==========================================\n");
    printf("ANTES:\n");
    mostrar_detalhes_tarefa(antes);
    printf("DEPOIS:\n");
    mostrar_detalhes_tarefa(depois);
    printf("==========================================\n");
}
