/*
 ________  ___  ___  ________  ________  _________  _______
|\   ___ \|\  \|\  \|\   __  \|\   __  \|\___   ___\\  ___ \
\ \  \_|\ \ \  \\\  \ \  \|\  \ \  \|\  \|___ \  \_\ \   __/|
 \ \  \ \\ \ \  \\\  \ \   __  \ \   _  _\   \ \  \ \ \  \_|/__
  \ \  \_\\ \ \  \\\  \ \  \ \  \ \  \\  \|   \ \  \ \ \  \_|\ \
   \ \_______\ \_______\ \__\ \__\ \__\\ _\    \ \__\ \ \_______\
	\|_______|\|_______|\|__|\|__|\|__|\|__|    \|__|  \|_______|
*/

// libTrabalho.h é inclusa para que a função main tenha acesso às funções, registros e constantes definidos.
#include "libTrabalho.h"

int main()
{

	//=======Variáveis para cadastro na base
	// arqFisicoImagensBase.bin armazena todas as informações sobre as imagens cadastradas.
	char arqFisicoImagensBase[] = "arqFisicoImagensBase.bin";
	int id;
	char nomeImagem[MAX_NAME];

	//======Variáveis para operações sobre imagens
	int opt = 1, lin, col, maxval, gravou;
	char *tipo, *nomeArqSaida;
	int **matImagem;
	char *auxNomeImagem;
	Imagem img;

	do
	{
		// Função que mostra as opções para o usuário ao executar o programa
		menuOperacoes();
		scanf("%d", &opt);

		switch (opt)
		{
		case 0:
			printf("\n");
			break;
		//===listaImagens
		case 1:
			listaImagens(arqFisicoImagensBase);
			break;
		//===cadastraImagem
		case 2:
			printf("\nInsira nome da imagem a ser cadastrada (com extensao): ");
			scanf("%s", nomeImagem);
			cadastraImagem(arqFisicoImagensBase, nomeImagem);
			break;
		//===alteraImagem
		case 3:
			printf("\nInsira ID da imagem a ser alterada: ");
			scanf("%d", &id);
			if (alteraImagem(arqFisicoImagensBase, id))
			{
				printf("\nInformacoes alteradas corretamente!");
			}
			else
			{
				printf("\nNao foi possivel encontrar a imagem.\n");
			}
			break;
		//===removeImagem
		case 4:
			printf("\nID da imagem a remover: ");
			scanf("%d", &id);
			removeImagem(arqFisicoImagensBase, id);
			break;
		//===Binarizar
		case 5:
			auxNomeImagem = alocaString(MAX_NAME);
			printf("\nNome imagem a binarizar: ");
			scanf("%s", auxNomeImagem);
			if (verificaCadastro(arqFisicoImagensBase, auxNomeImagem) != 1)
			{
				printf("\nErro ao verificar cadastro - Binarizar.\n");
			}
			tipo = alocaString(3);
			matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
			if (matImagem == NULL)
			{
				free(tipo);
				free(auxNomeImagem);
			}
			binarizar(matImagem, lin, col);
			nomeArqSaida = alocaString(MAX_NAME);
			do
			{
				printf("\nNome arquivo saida: ");
				scanf("%s", nomeArqSaida);
			} while (verificaCadastro(arqFisicoImagensBase, nomeArqSaida) != 0);
			gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			// alterando dados
			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			strcpy(img.nome, nomeArqSaida);
			struct tm tm = getSystemTime();
			img.data_modificacao.dia = tm.tm_mday;
			img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_modificacao.ano = tm.tm_year + 1900;
			img.id = getLastId(arqFisicoImagensBase) + 1;
			gravaInfoImagem(arqFisicoImagensBase, img);
			printf("\nImagem binarizada com sucesso! id = %d\n", img.id);
			// desalocando memoria
			free(tipo);
			free(auxNomeImagem);
			free(nomeArqSaida);
			desalocaMatrizImagem(matImagem, lin, col);
			break;
		//===Ruído
		case 6:
			auxNomeImagem = alocaString(MAX_NAME);
			printf("\nNome imagem a gerar Ruido: ");
			scanf("%s", auxNomeImagem);
			if (verificaCadastro(arqFisicoImagensBase, auxNomeImagem) != 1)
			{
				printf("\nErro ao verificar cadastro - Ruido.\n");
			}
			tipo = alocaString(3);
			matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
			if (matImagem == NULL)
			{
				free(tipo);
				free(auxNomeImagem);
			}
			ruido(matImagem, lin, col);
			nomeArqSaida = alocaString(MAX_NAME);
			do
			{
				printf("\nNome arquivo saida: ");
				scanf("%s", nomeArqSaida);
			} while (verificaCadastro(arqFisicoImagensBase, nomeArqSaida) != 0);
			gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			// alterando dados
			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			strcpy(img.nome, nomeArqSaida);
			tm = getSystemTime();
			img.data_modificacao.dia = tm.tm_mday;
			img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_modificacao.ano = tm.tm_year + 1900;
			img.id = getLastId(arqFisicoImagensBase) + 1;
			gravaInfoImagem(arqFisicoImagensBase, img);
			printf("\nProcesso de ruido feito com sucesso! id = %d\n", img.id);
			// desalocando memoria
			free(tipo);
			free(auxNomeImagem);
			free(nomeArqSaida);
			desalocaMatrizImagem(matImagem, lin, col);
			break;
		//===Negativo
		case 7:
			auxNomeImagem = alocaString(MAX_NAME);
			printf("\nNome imagem a gerar Negativo: ");
			scanf("%s", auxNomeImagem);
			if (verificaCadastro(arqFisicoImagensBase, auxNomeImagem) != 1)
			{
				printf("\nErro ao verificar cadastro - Negativo.\n");
			}
			tipo = alocaString(3);
			matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
			if (matImagem == NULL)
			{
				free(tipo);
				free(auxNomeImagem);
			}
			negativo(matImagem, lin, col);
			nomeArqSaida = alocaString(MAX_NAME);
			do
			{
				printf("\nNome arquivo saida: ");
				scanf("%s", nomeArqSaida);
			} while (verificaCadastro(arqFisicoImagensBase, nomeArqSaida) != 0);
			gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem);
			// alterando dados
			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			strcpy(img.nome, nomeArqSaida);
			tm = getSystemTime();
			img.data_modificacao.dia = tm.tm_mday;
			img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_modificacao.ano = tm.tm_year + 1900;
			img.id = getLastId(arqFisicoImagensBase) + 1;
			gravaInfoImagem(arqFisicoImagensBase, img);
			printf("\nProcesso de negativo feito com sucesso! id = %d\n", img.id);
			// desalocando memoria
			free(tipo);
			free(auxNomeImagem);
			free(nomeArqSaida);
			desalocaMatrizImagem(matImagem, lin, col);
			break;
		//====Espelhamento
		case 8:
			auxNomeImagem = alocaString(MAX_NAME);
			printf("\nNome imagem a Espelhar: ");
			scanf("%s", auxNomeImagem);
			if (verificaCadastro(arqFisicoImagensBase, auxNomeImagem) != 1)
			{
				printf("\nErro ao verificar cadastro - Espelhar.\n");
			}
			tipo = alocaString(3);
			matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
			if (matImagem == NULL)
			{
				free(tipo);
				free(auxNomeImagem);
			}
			// aloca matCopia
			int **matCopia = alocaMatrizImagem(lin, col);
			copiaMatrizImagem(matImagem, matCopia, lin, col);
			espelhar(matCopia, lin, col);
			nomeArqSaida = alocaString(MAX_NAME);
			do
			{
				printf("\nNome arquivo saida: ");
				scanf("%s", nomeArqSaida);
			} while (verificaCadastro(arqFisicoImagensBase, nomeArqSaida) != 0);
			gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matCopia);
			// alterando dados
			img = getImage(arqFisicoImagensBase, auxNomeImagem);
			strcpy(img.nome, nomeArqSaida);
			tm = getSystemTime();
			img.data_modificacao.dia = tm.tm_mday;
			img.data_modificacao.mes = tm.tm_mon + 1;
			img.data_modificacao.ano = tm.tm_year + 1900;
			img.id = getLastId(arqFisicoImagensBase) + 1;
			gravaInfoImagem(arqFisicoImagensBase, img);
			printf("\nImagem espelhada com sucesso! id = %d\n", img.id);
			// desalocando memoria
			free(tipo);
			free(auxNomeImagem);
			free(nomeArqSaida);
			desalocaMatrizImagem(matCopia, lin, col);
			desalocaMatrizImagem(matImagem, lin, col);
			break;
			break;
		default:
			printf("\nOpção inválida");
		}

	} while (opt != 0);

	return 0;
}
