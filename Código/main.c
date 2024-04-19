#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    char nome[50];
    char telefone[20];
    char curso[50];
    float n1, n2;
} Aluno;

// Função para calcular a média das notas de um aluno
float Media(Aluno aluno)
{
    return (aluno.n1 + aluno.n2) / 2.0;
}

// Função para determinar a situação do aluno (APROVADO ou REPROVADO)
const char *Situacao_Final(float media)
{
    if (media >= 7.0)
    {
        return "APROVADO";
    }
    else
    {
        return "REPROVADO";
    }
}

int main()
{
    FILE *Arquivo_entrada = fopen("DadosEntrada.csv", "r");
    FILE *Arquivo_saida = fopen("SituacaoFinal.csv", "w");

    if (Arquivo_entrada == NULL || Arquivo_saida == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    Aluno aluno;
    int count = 0;
    while (fscanf(Arquivo_entrada, "%[^,],%[^,],%[^,],%f,%f\n", aluno.nome, aluno.telefone, aluno.curso, &aluno.n1, &aluno.n2) == 5)
    {
        float media = Media(aluno);
        const char *situacao = Situacao_Final(media);
        fprintf(Arquivo_saida, "%s,%.2f,%s\n", aluno.nome, media, situacao);
        fflush(Arquivo_saida); // Força o sistema a escrever qualquer dado não escrito no arquivo
        count++;
        printf("Processado aluno %d: %s\n", count, aluno.nome); // Imprime o nome do aluno que foi processado
    }

    fclose(Arquivo_entrada);
    fclose(Arquivo_saida);

    printf("Arquivo SituacaoFinal.csv gerado com sucesso!\n");

    return 0;
}
