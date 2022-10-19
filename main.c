//libTrabalho.h é inclusa para que a função main tenha acesso às funções, registros e constantes definidos. 
#include "libTrabalho.h"

int main(){

   //=======Variáveis para cadastro na base
  //arqFisicoImagensBase.txt armazena todas as informações sobre as imagens cadastradas.
  char arqFisicoImagensBase[] = "arqFisicoImagensBase.bin";
  int id;
  char nomeImagem[MAX_NAME];  


   //======Variáveis para operações sobre imagens	
   int opt = 1, lin, col, maxval, gravou;
   char *tipo, *nomeArqSaida;
   int **matImagem; 
   char *auxNomeImagem;
   Imagem img;

  
  do{	  
     //Função que mostra as opções para o usuário ao executar o programa	  
     menuOperacoes();
     scanf("%d", &opt);

     
     switch (opt){
	     case 0:printf("\n");
		    break;
	     //===listaImagens	    
	     case 1: //listaImagens
  		    break; 
	     //===cadastraImagem	    
	     case 2:
		    //cadastraImagem
		    break;
             //===alteraImagem		    
	     case 3:
		    break; 
             //===removeImagem 		    
	     case 4: printf("\nID da imagem a remover: ");
		    scanf("%d",&id);
		    removeImagem(arqFisicoImagensBase, id);
		    break;  
             //===Binarizar		    
	     case 5: //binarizar(matImagem, lin, col);
		   break;
	     //===Ruído  	   
	     case 6:  //ruido(matImagem, lin, col);	
		   break;
	      //===Negativo 	   
	     case 7: //negativo(matImagem, lin, col);	
		   break;
	     //====Espelhamento	    
	     case 8: //espelhar(matImagem, lin, col);	
		   break;		    
	     default: printf("\nOpção inválida");
     }

  }while (opt != 0);

  return 0;
}
