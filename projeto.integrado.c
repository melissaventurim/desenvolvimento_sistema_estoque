#include <stdio.h>
#include <string.h>

// Definindo os limites de estoque antes de começar com as funções
#define ESTOQUE_BAIXO 3      // Considerar o estoque baixo quando a quantidade for igual a 3 ou menos
#define EXCESSO_ESTOQUE 40   // Considerar o estoque em excesso se a quantidade for 40 ou mais

// Definindo a estrutura dos dados que representam um produto no estoque de acordo os requisitos apresentados no roteiro
typedef struct {
    char nome[25];         // O nome do prodito pode ter no máximo 25 caracteres
    char categoria[20];    // A categoria do produto pode ter no máximo 20 caracteres
    int quantidade;        // A quantidade disponível do produto no estoque
    float preco;           // O preço do produto
    char localizacao[15];  // A localização do produto no depósito pode ter no máximo 15 caracteres
} Produto;

int main() {
    Produto estoque[100];  // Armazenando até 100 produtos no estoque
    int total_produtos = 0;  // Essa variável guarda o número total de produtos cadastrados
    int opcao, quantidade;  // Essa variável armazena a opção do menu e a quantidade de produtos
    char nome[25], categoria[20], localizacao[15];  // Variáveis para armazenar os dados dos produtos
    float preco;  // Essa variável armazena o preço do produto

    // Loop do menu de opções que são ofertadas pelo sistema
    do {
        // Forma que vai ser exibido o menu para o funcionário
        printf("\n===== Sistema de Gerenciamento do Estoque =====\n");
        printf("1. Cadastrar produto\n");
        printf("2. Atualizar estoque\n");
        printf("3. Gerar relatório de estoque\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Opção 1: Cadastrando um novo produto
                if (total_produtos < 100) {  // Como coloquei que o estoque armazena até 100 produtos, aqui se verifica se há espaço para cadastrar mais produtos
                    // Solicita as informações do produto
                    printf("Digite o nome do produto (máximo de 25 caracteres): ");
                    scanf(" %24[^\n]", nome);  // Para ler o nome do produto
                    printf("Digite a categoria do produto (máximo de 20 caracteres): ");
                    scanf(" %19[^\n]", categoria);  // Para ler a categoria do produto
                    printf("Digite a quantidade do produto: ");
                    scanf("%d", &quantidade);  // Para ler a quantidade disponível no estoque
                    printf("Digite o preço do produto: ");
                    scanf("%f", &preco);  // Para ler o preço do produto
                    printf("Digite a localização do produto (máximo de 15 caracteres): ");
                    scanf(" %14[^\n]", localizacao);  // Para ler a localização do produto no estoque

                    // Preenchendo a estrutura de produto com as informações fornecidas
                    strcpy(estoque[total_produtos].nome, nome);  // Copiando o nome para o campo da estrutura
                    strcpy(estoque[total_produtos].categoria, categoria);  // Copiando a categoria
                    estoque[total_produtos].quantidade = quantidade;  // Definindo a quantidade
                    estoque[total_produtos].preco = preco;  // Definindo o preço
                    strcpy(estoque[total_produtos].localizacao, localizacao);  // Copiando a localização

                    // Para acrescentar os produtos cadastrados
                    total_produtos++;

                    // Print para informar se o produto foi cadastrado com sucesso ou não
                    printf("Produto '%s' cadastrado com sucesso!\n", nome);
                } else {
                    // Se o estoque estiver cheio (o limite é de 100 produtos)
                    printf("Estoque cheio! Não é possível cadastrar mais produtos.\n");
                }
                break;

            case 2:
                // Opção 2: Atualizando a quantidade do produto
                printf("Digite o nome do produto para atualizar: ");
                scanf(" %24[^\n]", nome);  // Para ler o nome do produto que será atualizado
                int encontrado = 0;  // Variável de controle que verifica se o produto foi encontrado

                // Loop que procura o produto no estoque
                for (int i = 0; i < total_produtos; i++) {
                    if (strcmp(estoque[i].nome, nome) == 0) {
                        // Se o nome do produto for encontrado, então solicita a quantidade a ser atualizada
                        printf("Digite a quantidade a ser adicionada ou retirada (número negativo para subtrair): ");
                        scanf("%d", &quantidade);  // Para ler a quantidade a ser alterada
                        estoque[i].quantidade += quantidade;  // Para atualizar a quantidade no estoque
                        printf("Estoque do produto '%s' atualizado para %d unidades.\n", nome, estoque[i].quantidade);
                        encontrado = 1;  // Mostra que o produto foi encontrado
                        break;
                    }
                }

                // Se o produto não for encontrado, exibe uma mensagem de erro
                if (!encontrado) {
                    printf("Produto '%s' não encontrado.\n", nome);
                }
                break;

            case 3:
                // Opção 3: Para gerar o relatório de estoque
                printf("\n=== Relatório de Estoque ===\n");
                int baixo = 0, excesso = 0;  // Contadores para produtos com estoque baixo ou excessivo

                // Loop que percorre todos os produtos e gera o relatório
                for (int i = 0; i < total_produtos; i++) {
                    // Verificando se o estoque está baixo (quantidade <= 3)
                    if (estoque[i].quantidade <= ESTOQUE_BAIXO) {
                        printf("Produto com estoque baixo: '%s' - Quantidade: %d\n", estoque[i].nome, estoque[i].quantidade);
                        baixo++;  // Incrementa o contador de produtos com estoque baixo
                    }
                    // Verificando se o estoque está em excesso (quantidade >= 40)
                    if (estoque[i].quantidade >= EXCESSO_ESTOQUE) {
                        printf("Produto com excesso de estoque: '%s' - Quantidade: %d\n", estoque[i].nome, estoque[i].quantidade);
                        excesso++;  // Incrementa o contador de produtos com excesso de estoque
                    }
                }

                // Se não houver produtos com estoque baixo ou excessivo, informa-se ao usuário
                if (baixo == 0) {
                    printf("Não há produtos com estoque baixo.\n");
                }
                if (excesso == 0) {
                    printf("Não há produtos com excesso de estoque.\n");
                }
                break;

            case 4:
                // Opção 4: Para sair do programa
                printf("Saindo...\n");
                break;

            default:
                // Se o usuário escolher uma opção inválida
                printf("Opção inválida, tente novamente.\n");
                break;
        }

    } while (opcao != 4);  // O programa vai continuar até o usuário escolher a opção 4 (Sair)

    return 0;
}