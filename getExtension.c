/*
 * Ele está dando o nome da imagem como "xxx.yyy", parser que ao encontrar o
 * "." da string nomeImagem, escreve os proximos char's em extension
 */
void getExtension(char nomeImagem[], char extension[])
{
    int i = 0, j = 0;
    while (nomeImagem[i] != '.')
    {
        i++;
    }
    while (nomeImagem[i] != '\0')
    {
        extension[j] = nomeImagem[i];
        i++;
        j++;
    }
    extension[j] = '\0';
}