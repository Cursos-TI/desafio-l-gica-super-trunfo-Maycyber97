#include <stdio.h>

int main() {
    // Declaração de variáveis
    char estado1[3], codigo1[10], nome1[50];
    unsigned long int populacao1;
    float area1, pib1, densidade1, pibPerCapita1;
    int pontosTuristicos1;

    char estado2[3], codigo2[10], nome2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade2, pibPerCapita2;
    int pontosTuristicos2;

    int opcao1, opcao2;

    printf("=========================================\n");
    printf("      SUPER TRUNFO - PAÍSES\n");
    printf("=========================================\n\n");

    printf(">>> Cadastro do Primeiro País\n");
    printf("-----------------------------------------\n");
    printf("Digite o estado (sigla): ");
    scanf("%s", estado1);
    printf("Digite o código da carta: ");
    scanf("%s", codigo1);
    printf("Digite o nome do país: ");
    scanf(" %[^\n]", nome1);
    printf("Digite a população: ");
    scanf("%lu", &populacao1);
    printf("Digite a área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões de dólares): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n>>> Cadastro do Segundo País\n");
    printf("-----------------------------------------\n");
    printf("Digite o estado (sigla): ");
    scanf("%s", estado2);
    printf("Digite o código da carta: ");
    scanf("%s", codigo2);
    printf("Digite o nome do país: ");
    scanf(" %[^\n]", nome2);
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    printf("Digite a área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões de dólares): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    printf("\n=========================================\n");
    printf("         Escolha de Atributos\n");
    printf("=========================================\n");

    // Escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per capita\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // Menu dinâmico para o segundo atributo
    do {
        printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != opcao1) {
                switch (i) {
                    case 1: printf("%d - População\n", i); break;
                    case 2: printf("%d - Área\n", i); break;
                    case 3: printf("%d - PIB\n", i); break;
                    case 4: printf("%d - Pontos Turísticos\n", i); break;
                    case 5: printf("%d - Densidade Demográfica\n", i); break;
                    case 6: printf("%d - PIB per capita\n", i); break;
                }
            }
        }
        printf("Opção: ");
        scanf("%d", &opcao2);

        if (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 6) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 6);

    // Definindo valores dos atributos escolhidos
    float valor1_atributo1, valor2_atributo1;
    float valor1_atributo2, valor2_atributo2;

    switch(opcao1) {
        case 1: valor1_atributo1 = populacao1; valor2_atributo1 = populacao2; break;
        case 2: valor1_atributo1 = area1; valor2_atributo1 = area2; break;
        case 3: valor1_atributo1 = pib1; valor2_atributo1 = pib2; break;
        case 4: valor1_atributo1 = pontosTuristicos1; valor2_atributo1 = pontosTuristicos2; break;
        case 5: valor1_atributo1 = densidade1; valor2_atributo1 = densidade2; break;
        case 6: valor1_atributo1 = pibPerCapita1; valor2_atributo1 = pibPerCapita2; break;
    }

    switch(opcao2) {
        case 1: valor1_atributo2 = populacao1; valor2_atributo2 = populacao2; break;
        case 2: valor1_atributo2 = area1; valor2_atributo2 = area2; break;
        case 3: valor1_atributo2 = pib1; valor2_atributo2 = pib2; break;
        case 4: valor1_atributo2 = pontosTuristicos1; valor2_atributo2 = pontosTuristicos2; break;
        case 5: valor1_atributo2 = densidade1; valor2_atributo2 = densidade2; break;
        case 6: valor1_atributo2 = pibPerCapita1; valor2_atributo2 = pibPerCapita2; break;
    }

    printf("\n=========================================\n");
    printf("         Comparação dos Países\n");
    printf("=========================================\n");

    printf("\nPaís 1: %s (%s)\n", nome1, estado1);
    printf("País 2: %s (%s)\n\n", nome2, estado2);

    // Comparação do primeiro atributo
    printf(">>> Atributo 1: ");
    switch(opcao1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
        case 6: printf("PIB per capita\n"); break;
    }
    printf("%s: %.2f\n", nome1, valor1_atributo1);
    printf("%s: %.2f\n", nome2, valor2_atributo1);
    if (opcao1 == 5) { // Densidade Demográfica: menor valor vence
        if (valor1_atributo1 < valor2_atributo1)
            printf("%s vence no primeiro atributo!\n\n", nome1);
        else if (valor2_atributo1 < valor1_atributo1)
            printf("%s vence no primeiro atributo!\n\n", nome2);
        else
            printf("Empate no primeiro atributo!\n\n");
    } else { // Outros atributos: maior valor vence
        if (valor1_atributo1 > valor2_atributo1)
            printf("%s vence no primeiro atributo!\n\n", nome1);
        else if (valor2_atributo1 > valor1_atributo1)
            printf("%s vence no primeiro atributo!\n\n", nome2);
        else
            printf("Empate no primeiro atributo!\n\n");
    }

    // Comparação do segundo atributo
    printf(">>> Atributo 2: ");
    switch(opcao2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
        case 6: printf("PIB per capita\n"); break;
    }
    printf("%s: %.2f\n", nome1, valor1_atributo2);
    printf("%s: %.2f\n", nome2, valor2_atributo2);
    if (opcao2 == 5) { // Densidade Demográfica: menor valor vence
        if (valor1_atributo2 < valor2_atributo2)
            printf("%s vence no segundo atributo!\n\n", nome1);
        else if (valor2_atributo2 < valor1_atributo2)
            printf("%s vence no segundo atributo!\n\n", nome2);
        else
            printf("Empate no segundo atributo!\n\n");
    } else { // Outros atributos: maior valor vence
        if (valor1_atributo2 > valor2_atributo2)
            printf("%s vence no segundo atributo!\n\n", nome1);
        else if (valor2_atributo2 > valor1_atributo2)
            printf("%s vence no segundo atributo!\n\n", nome2);
        else
            printf("Empate no segundo atributo!\n\n");
    }

    // Soma dos atributos
    float soma1 = valor1_atributo1 + valor1_atributo2;
    float soma2 = valor2_atributo1 + valor2_atributo2;

    printf(">>> Soma dos Atributos:\n");
    printf("%s: %.2f\n", nome1, soma1);
    printf("%s: %.2f\n", nome2, soma2);

    // Definindo vencedor
    printf("\n=========================================\n");
    printf("         Resultado Final\n");
    printf("=========================================\n");

    if (soma1 > soma2)
        printf("\n%s venceu!\n", nome1);
    else if (soma2 > soma1)
        printf("\n%s venceu!\n", nome2);
    else
        printf("\nEmpate!\n");

    printf("\n=========================================\n");

    return 0;
}