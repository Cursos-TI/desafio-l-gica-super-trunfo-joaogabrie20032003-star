#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 2

typedef struct {
    char estado[50];
    char nome[50];
    int codigo;
    long populacao;
    float area;
    float pib;
    int pontosTuristicos;
} CartaCidade;

void cadastrarCarta(CartaCidade *carta) {
    printf("Digite o código da carta: ");
    scanf("%d", &carta->codigo);
    getchar();

    printf("Digite o nome da cidade: ");
    fgets(carta->nome, 50, stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0;

    printf("Digite o estado: ");
    fgets(carta->estado, 50, stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0;

    printf("Digite a população: ");
    scanf("%ld", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void exibirCarta(CartaCidade carta) {
    printf("\n--- Carta da Cidade ---\n");
    printf("Código: %d\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("Estado: %s\n", carta.estado);
    printf("População: %ld\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

void compararSimples(CartaCidade c1, CartaCidade c2) {
    int atributo;

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Opção: ");
    scanf("%d", &atributo);

    printf("\nComparando cartas...\n");

    if (atributo == 1) {
        if (c1.populacao > c2.populacao)
            printf("Vencedora: %s (População maior)\n", c1.nome);
        else if (c2.populacao > c1.populacao)
            printf("Vencedora: %s (População maior)\n", c2.nome);
        else
            printf("Empate em População.\n");
    } else if (atributo == 2) {
        if (c1.area > c2.area)
            printf("Vencedora: %s (Área maior)\n", c1.nome);
        else if (c2.area > c1.area)
            printf("Vencedora: %s (Área maior)\n", c2.nome);
        else
            printf("Empate em Área.\n");
    } else if (atributo == 3) {
        if (c1.pib > c2.pib)
            printf("Vencedora: %s (PIB maior)\n", c1.nome);
        else if (c2.pib > c1.pib)
            printf("Vencedora: %s (PIB maior)\n", c2.nome);
        else
            printf("Empate em PIB.\n");
    } else if (atributo == 4) {
        if (c1.pontosTuristicos > c2.pontosTuristicos)
            printf("Vencedora: %s (Mais pontos turísticos)\n", c1.nome);
        else if (c2.pontosTuristicos > c1.pontosTuristicos)
            printf("Vencedora: %s (Mais pontos turísticos)\n", c2.nome);
        else
            printf("Empate em Pontos Turísticos.\n");
    } else if (atributo == 5) {
        float densidade1 = c1.populacao / c1.area;
        float densidade2 = c2.populacao / c2.area;

        if (densidade1 < densidade2)
            printf("Vencedora: %s (Menor densidade populacional)\n", c1.nome);
        else if (densidade2 < densidade1)
            printf("Vencedora: %s (Menor densidade populacional)\n", c2.nome);
        else
            printf("Empate em Densidade Populacional.\n");
    } else {
        printf("Opção inválida.\n");
    }
}

float getValue(CartaCidade c, int attr) {
    switch(attr) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.populacao / c.area;
        default: return 0;
    }
}

void compararDoisAtributos(CartaCidade c1, CartaCidade c2) {
    int attr1, attr2;
    float val1_c1, val1_c2, val2_c1, val2_c2;

    printf("\nEscolha o primeiro atributo:\n1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n> ");
    scanf("%d", &attr1);
    printf("Escolha o segundo atributo:\n1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n> ");
    scanf("%d", &attr2);

    val1_c1 = getValue(c1, attr1);
    val1_c2 = getValue(c2, attr1);
    val2_c1 = getValue(c1, attr2);
    val2_c2 = getValue(c2, attr2);

    int inverso1 = (attr1 == 5);
    int inverso2 = (attr2 == 5);
    int vencedor = 0;

    if ((inverso1 ? val1_c1 < val1_c2 : val1_c1 > val1_c2)) {
        vencedor = 1;
    } else if ((inverso1 ? val1_c2 < val1_c1 : val1_c2 > val1_c1)) {
        vencedor = 2;
    } else {
        vencedor = (inverso2 ? (val2_c1 < val2_c2 ? 1 : val2_c2 < val2_c1 ? 2 : 0)
                             : (val2_c1 > val2_c2 ? 1 : val2_c2 > val2_c1 ? 2 : 0));
    }

    if (vencedor == 1)
        printf("Vencedora: %s\n", c1.nome);
    else if (vencedor == 2)
        printf("Vencedora: %s\n", c2.nome);
    else
        printf("Empate total nos dois atributos!\n");
}

int main() {
    CartaCidade cartas[MAX_CIDADES];

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&cartas[0]);
    exibirCarta(cartas[0]);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&cartas[1]);                    
    exibirCarta(cartas[1]);

    // Ative o nível que deseja testar:

    // Nível Novato
    //compararSimples(cartas[0], cartas[1]);

    // Nível Mestre
    compararDoisAtributos(cartas[0], cartas[1]);

    return 0;
}