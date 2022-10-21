/*
 * Ele está dando o nome da imagem como "xxx.yyy", no caso a ideia é trabalhar com um parser que ao encontrar o
 "." da string nomeImagem, escreve os proximos char's em extension
 */

void getExtension(char nomeImagem[], char extension[]){
   int auxExtension = 0, i = 0;
   while(nomeImagem[i] != "."){
      i++;
   }
   for (int j = i; nomeImagem[j] != "\0"; j++){
        extension[auxExtension] = nomeImagem[j];
        auxExtension++;
      }
   printf("\nImplementar - função cadastraImagem.\n");	
}
