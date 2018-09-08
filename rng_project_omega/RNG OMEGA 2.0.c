//--------------------------------## CÓDIGO DESENVOLVIDO POR DOUGLAS V. BERNARDINO ##--------------------------------
//Revisão:	João Rener (paitola)
//			João Vitor (fiato)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int statement;

int bubble_sort(unsigned int L[], unsigned int n){
	int i, j;
	for (i=1; i<=n-1; i++){
		for (j=0; j<n-i; j++){
			if (L[j]>L[j+1]){
				unsigned int x = L[j];
				L[j] = L[j+1];
				L[j+1] = x;
			}
		}
	}
}
//-------------------------------------------------
void header(void){ //Esta função exibe o cabeçalho.
	system("cls");
	system("color 0e");
	printf("\n\n\n\n\t#####################################\n");
	printf("\t##     R4ND0M NUMB3R G3N3R4T0R     ##\n");
	printf("\t#####################################\n\n");
}

//---------------------------------------------------------------------------------
int linear_search(int key, int L[], int n, int excluded){ //Esta função executa uma busca linear. [MÉTODO ADAPTADO]
		for (int i=0; i < excluded; i++){
			if (key == L[i]) return 1;
		}
		return 0;
}

//------------------------------------------
int main(void){ //Esta é a função principal.
	
	int confirm_menu;
	
	do {
	system("cls");
	system("COLOR 0c");
	printf("\n\n\n\t\t       1.\tCONTINUE.  \n\n");
	printf("\t\t    (-1).\tEXIT.  \n\n\t\t\t");
	scanf("%d",&confirm_menu);
	if ((confirm_menu != 1) && (confirm_menu != -1)){
		printf("\n\t\t\t---------- Invalid input! ----------");
		getch();
	}
	} while ((confirm_menu != 1) && (confirm_menu != -1));
	


//======================= AQUI COMEÇA A MERDA DO CICLO WHILE, SE O EMBUSTE DO USUÁRIO TIVER INSERIDO "1" ========================		
	while (confirm_menu == 1){
		srand(time(NULL));
		system("cls");
		
		int A	=	0;
		int B	=	0;
		int n	=	0;
			
		header();
		
		printf("\tHow many random samples do you want? ");
		scanf("%d",&n);
		printf("\tEnter the beginning of the range: ");
		scanf("%d",&A);
		printf("\tEnter the end of the range: ");
		scanf("%d",&B);
		printf("\n");
		
			
		
//======================================================================================	
		unsigned int sample[n];														  //
		for (int i=0; i<n; i++){                         //Cria um vetor e zera o mesmo.
			sample[i] = 0;															  //
		}																			  //
//======================================================================================



//==========================================================================================================================
		for (int i=0; i<n; i++){																						  //
			sample[i] =  A + (rand() % (B-A+1));																		  //
			statement = linear_search(sample[i], sample, n, i);															  //
			if (statement == 1){																						  //
				i--;                                                                   //Sorteia valores e preenche o vetor.
			}																											  //
		}	           					     																			  //
//==========================================================================================================================
		
		bubble_sort(sample,n);
		printf("\n");
		for (int i=0; i<n; i++){
			if (i%4 == 0) printf("\n\t");
			printf("\t%d",sample[i]);
		}
		printf("\n\nPRESS ANY KEY!\n\n");
		getch();

		do {
			system("cls");
			printf("\n\n\tDo you want to generate another sequence?\n\n\t1. Yes\t\t(-1). Nope\n\t");
			scanf("%d",&confirm_menu);
			if ((confirm_menu != 1) && (confirm_menu != -1)){
				printf("\n\t\t---------- Invalid input! ----------");
				getch();
			} 
		} while ((confirm_menu != 1) && (confirm_menu != -1));
	}
//====================================== AQUI TERMINA A CARALHA DO WHILE, NESSA MERDA ===========================================
	getchar();
	return 0;
}
