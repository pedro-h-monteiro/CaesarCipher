// Code made by Pedro Monteiro
// Funciona corretamente com o dicionário português

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

void substitute (char spaces[500], char entrada[500]);

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

    spaces[0] = '\0';
    saida[0] = '\0';
    entrada[0] = '\0';

    printf("Cifra de Cesar - Cifragem\n\n");

    fin = fopen("mensagem.txt","r");
    fout = fopen("cifra.txt", "a+");
    fgets(spaces, 500, (FILE*)fin);
    printf("O conteudo do ficheiro 'mensagem.txt' e o seguinte:\n\n");
    printf(spaces);
    do
    {
        printf("\n\nIntroduza o shift para a cifragem [0-26]: ");
        scanf("%d", &key);
    }
    while (key > 25);

    printf("\nCifragem: ");

    // funcao de tratamento do texto forncedio
    substitute(spaces, entrada);

    // substituicao de chars de acordo com a key fornecida
    for (i = 0; entrada[i] != '\0'; i++)
    {
        saida[i] = entrada[i] + key;

        if (entrada[i] + key > 'z')
        {
            saida[i] -= 26;
        }
        else if (entrada[i] + key < 'a')
        {
            saida[i] += 26;
        }
        printf("%c", saida[i]);
        fputc(saida[i], fout);
    }

    printf("\n\nA cifragem foi guardada com sucesso em 'cifra.txt'. \n\nGoodbye.");
    fclose(fin);
    fclose(fout);
    printf("\n");
}

void substitute (char spaces[500], char entrada[500])
{
    char nut = ' ';
    int i = 0;
    int j = 0;
    int m = 0;

    while (spaces[i] != '\0')
    {
        if (spaces[i] == 'á' || spaces[i] == 'à' || spaces[i] == 'ã' || spaces[i] == 'â')
        {
            spaces[i] = 'a';
        }
        if (spaces[i] == 'é' || spaces[i] == 'è' || spaces[i] == 'ê')
        {
            spaces[i] = 'e';
        }
        if (spaces[i] == 'í' || spaces[i] == 'ì' || spaces[i] == 'î')
        {
            spaces[i] = 'i';
        }
        if (spaces[i] == 'ó' || spaces[i] == 'ò' || spaces[i] == 'õ' || spaces[i] == 'ô')
        {
            spaces[i] = 'o';
        }
        if (spaces[i] == 'ú' || spaces[i] == 'ù' || spaces[i] == 'û')
        {
            spaces[i] = 'u';
        }
        if (spaces[i] == 'ç' || spaces[i] == 'Ç' ) //C cedilhado
        {
            spaces[i] = 'c';
        }
        if (spaces[i] >= 33 && spaces[i] <= 64 || spaces[i] >= 91 && spaces[i] <= 96)
        {
            //remover non chars
            spaces[i] = nut;
        }

        m = spaces[i];

        if (isupper(m)) //passar tudo para minusculas
        {
            spaces[i] = tolower(m);
        }

        if (!(spaces[i] == ' ' )) // remover espacos
        {
            entrada[j] = spaces[i];
            j++;
        }
        entrada[j] = '\0';
        i++;
    }
}
