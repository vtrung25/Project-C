#include <stdio.h>
#include <stdlib.h>
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct book{
	int id;
	char name[100];
	float price;
};
int main(int argc, char *argv[]) {
	int choiceMainMenu;
	int choiceMenuBook;
	struct book sach[100];
	int n;
	mainMenu();
	backMainMenu(&choiceMainMenu);
	


	switch(choiceMainMenu){
		case 1:
			do{
			
			menuBook();
				scanf("%d", &choiceMenuBook);
		
	printf("\n");
	switch(choiceMenuBook){
		case 1:
			display(sach,n);
			backMenuBook(&choiceMenuBook);
			printf("\n\n");
			break;
		case 2:
			add(sach, &n);
			backMenuBook(&choiceMenuBook);
				printf("\n");
				break;
		case 3:
			edit(sach,n);
			backMenuBook(&choiceMenuBook);
					printf("\n");
					break;
		case 4:
			Delete(sach,&n);
			backMenuBook(&choiceMenuBook);
						printf("\n");
						break;
		case 5:
			search(sach,n);
			backMenuBook(&choiceMenuBook);
							printf("\n");
							
			break;
		case 6:
			sort(sach,n);
			backMenuBook(&choiceMenuBook);
			printf("\n");
			break;
		case 7:
			loadFromFile(sach,&n);
			backMenuBook(&choiceMenuBook);
			printf("\n");
			break;
		case 8:
			saveToFile(sach,&n);
			backMenuBook(&choiceMenuBook);
			printf("\n");
			break;
		case 9:
			mainMenu();
			backMainMenu(&choiceMainMenu);
			break;
	}
	
}while(choiceMenuBook>0&&choiceMenuBook<10);
			break;		
	break;
	    case 2:
				
			break;
	    case 3:
	    	
	    	break;
	    	
	    	    
	}
	return 0;
}