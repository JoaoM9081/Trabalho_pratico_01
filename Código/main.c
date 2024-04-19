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
    return (aluno.n1 + aluno.n2) / 2.0;
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

int main()
{
    // Abrindo os arquivos de entrada e saída
    FILE *Arquivo_entrada = fopen("DadosEntrada.csv", "r");
    FILE *Arquivo_saida = fopen("SituacaoFinal.csv", "w");

    // Verificando se os arquivos foram abertos corretamente
    if (Arquivo_entrada == NULL || Arquivo_saida == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
    }

    Aluno aluno;
    char linha[200];
    char telefone[20];
    char curso[50];

    // Lendo os dados do arquivo de entrada
    while (fgets(linha, sizeof(linha), Arquivo_entrada))
    {
        // Lendo os dados do aluno do arquivo de entrada
        if (sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", aluno.nome, telefone, curso, &aluno.n1, &aluno.n2) == 5)
        {
            // Calculando a média e a situação final do aluno
            float media = Media(aluno);
            char *situacao = Situacao_Final(media);

            // Escrevendo os dados do aluno no arquivo de saída
            fprintf(Arquivo_saida, "%s, %.2lf, %s\n", aluno.nome, media, situacao);
        }
    }

    // Fechando os arquivos
    fclose(Arquivo_entrada);
    fclose(Arquivo_saida);

    printf("Arquivo SituacaoFinal.csv gerado com sucesso!\n");

    return 0;
}