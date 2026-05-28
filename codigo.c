#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    float temperatura;
    float energia;
    int   comunicacao;
} Leitura;

Leitura historico[MAX];
int total = 0;

void inserir_dados() {
    if (total >= MAX) {
        printf("Historico cheio!\n");
        return;
    }

    printf("\n-- INSERIR DADOS --\n");
    printf("Temperatura (C): ");
    scanf("%f", &historico[total].temperatura);

    printf("Energia (0-100%%): ");
    scanf("%f", &historico[total].energia);

    printf("Comunicacao ativa? (1=Sim / 0=Nao): ");
    scanf("%d", &historico[total].comunicacao);

    total++;
    printf("Leitura #%d registrada!\n", total);
}

void verificar_alertas(Leitura l, int id) {
    printf("\n-- ANALISE DA LEITURA #%d --\n", id);

    if (l.temperatura > 80)
        printf("[ALERTA] Superaquecimento! Temp: %.1fC\n", l.temperatura);
    else
        printf("[OK] Temperatura: %.1fC\n", l.temperatura);

    if (l.energia < 20)
        printf("[ALERTA] Economia de energia! Nivel: %.1f%%\n", l.energia);
    else
        printf("[OK] Energia: %.1f%%\n", l.energia);

    if (l.comunicacao == 0)
        printf("[ALERTA] Falha de comunicacao!\n");
    else
        printf("[OK] Comunicacao ativa.\n");
}

void visualizar_status() {
    int i;
    if (total == 0) {
        printf("Nenhuma leitura cadastrada.\n");
        return;
    }

    printf("\n-- HISTORICO DE LEITURAS --\n");
    printf("%-4s %-10s %-12s %-14s\n", "ID", "TEMP(C)", "ENERGIA(%)", "COMUNICACAO");
    printf("-------------------------------------------\n");

    for (i = 0; i < total; i++) {
        printf("%-4d %-10.1f %-12.1f %-14s\n",
            i + 1,
            historico[i].temperatura,
            historico[i].energia,
            historico[i].comunicacao ? "ATIVA" : "FALHA");
    }
}

void executar_analise() {
    int i;
    if (total == 0) {
        printf("Nenhuma leitura cadastrada.\n");
        return;
    }

    for (i = 0; i < total; i++)
        verificar_alertas(historico[i], i + 1);
}

int main() {
    int opcao;

    do {
        printf("\n===== MISSAO ESPACIAL =====\n");
        printf("1. Inserir dados\n");
        printf("2. Visualizar status\n");
        printf("3. Executar analise\n");
        printf("0. Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserir_dados();    break;
            case 2: visualizar_status(); break;
            case 3: executar_analise(); break;
            case 0: printf("Sistema encerrado.\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}