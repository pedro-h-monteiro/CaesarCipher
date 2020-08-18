// Code made by Pedro Monteiro
// Funciona corretamente com o dicionário português

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    //Para ler corretamente os acentos, o encoding do .txt deve ser ANSI
    setlocale(LC_ALL, "Portuguese");
    char entrada[500] = {'\0'};
    char saida[500] = {'\0'};
    char spaces[500] = {'\0'};
    int key = 0;
    int j = 0;
    int i = 0;
    int k = 0;

    FILE *fin, *fout;

    printf("Cifra de Cesar - Decifragem\n\n");

    spaces[0] = '\0';
    saida[0] = '\0';
    entrada[0] = '\0';

    fin = fopen("cifra.txt","r");
    fout = fopen("mesg_ces.txt", "a+");
    fgets(spaces, 500, (FILE*)fin);
    printf("O conteudo do ficheiro 'mesg_ces.txt' e o seguinte:\n\n");
    printf(spaces);

    do
    {
        printf("\n\nIntroduza o shift para a decifragem [0-25]: ");
        scanf("%d", &key);
    }
    while (key > 25);

    printf("\nDecifragem: ");

    for (i = 0; spaces[i] != '\0'; i++)
    {
        entrada[i] = spaces[i];
        saida[i] = spaces[i] - key;

        if (entrada[i] - key < 'a')
        {
            saida[i] += 26;
        }
        else if (entrada[i] - key > 'z')
        {
            saida[i] -= 26;
        }
        printf("%c", saida[i]);
        fputc(saida[i], fout);
    }

    printf("\n\nA decifragem foi guardada com sucesso em 'mesg_ces.txt'. \n\nGoodbye.");
    fclose(fin);
    fclose(fout);
    printf("\n");
}
