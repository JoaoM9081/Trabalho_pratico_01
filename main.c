#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    char nome[50];
    float n1, n2;
} Aluno;

// Função para calcular a média dos alunos
float Media(Aluno aluno)
{
    return (aluno.n1 + aluno.n2) / 2;
}

// Função para determinar a situação final dos alunos
char *Situacao_Final(float media)
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

// Função para processar os dados do arquivo de entrada
void Processar_Dados(FILE *Arquivo_entrada, FILE *Arquivo_saida)
{
    Aluno aluno;
    char linha[200];
    char telefone[20];
    char curso[50];

    // Lendo os dados do arquivo de entrada
    while (fgets(linha, sizeof(linha), Arquivo_entrada))
    {
        if (sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", aluno.nome, telefone, curso, &aluno.n1, &aluno.n2) == 5)
        {
            float media = Media(aluno);
            char *situacao = Situacao_Final(media);

            // Imprimindo dados no arquivo de saída
            fprintf(Arquivo_saida, "%s, %.2lf, %s\n", aluno.nome, media, situacao);
        }
    }
}

int main()
{
    FILE *Arquivo_entrada = fopen("DadosEntrada.csv", "r");
    FILE *Arquivo_saida = fopen("SituacaoFinal.csv", "w");

    // Verificação de erro na abertura dos arquivos
    if (Arquivo_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    if (Arquivo_saida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    Processar_Dados(Arquivo_entrada, Arquivo_saida);

    fclose(Arquivo_entrada);
    fclose(Arquivo_saida);

    printf("Arquivo SituacaoFinal.csv gerado com sucesso!\n");

    return 0;
}