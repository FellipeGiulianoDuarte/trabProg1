/*
 * Ele está dando o nome da imagem como "xxx.yyy", no caso a ideia é trabalhar com um parser que ao encontrar o
 "." da string nomeImagem, escreve os proximos char's em extension
 */
void getExtension(char nomeImagem[], char extension[]){
    int auxExtension = 0, i = 0, j;
    while(nomeImagem[i] != '.'){
        i++;
    }
    for (j = i; nomeImagem[j] != '\0'; j++){
        extension[auxExtension] = nomeImagem[j];
        auxExtension++;
    }
    extension[j+1] = '\0';	
}

/*
int main(){
    char nomeImagem[30] = {'t','e','s','t','e','.','p','g','m'}, extension[10];
    getExtension(nomeImagem, extension);
    printf("extension: %s", extension);
    return 0;
}
*/