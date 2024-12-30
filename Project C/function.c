#include<stdio.h>
struct book
{
	int id;
	char name[100];
	float price;
};
struct book sach[100];
void mainMenu()
{
	printf("   ***Liabry Management System Using C***\n\n");
	printf("           CHOOSE YOUR ROLE\n");
	printf("        ========================\n");
	printf("        [1]. Books\n");
	printf("        [2]. Cient\n");
	printf("        [3]. Admin\n");
	printf("        =========================\n");
	printf("        ENTER THE CHOICE: ");
}

void menuBook()
{
	int choiceMenuBook;
	printf("          ***Book Management***\n\n");
	printf("                  MENU\n");
	printf("       ============================\n");
	printf("       [1]. Show list book\n");
	printf("       [2]. Add book\n");
	printf("       [3]. Edit book information\n");
	printf("       [4]. Delete book\n");
	printf("       [5]. Search book by name\n");
	printf("       [6]. Sort books by price\n");
	printf("       [7]. Load information to file\n");
	printf("       [8]. Save information to file\n");
	printf("       [9]. Exit\n");
	printf("       ==============================\n");
	printf("        ENTER THE CHOICE: ");
}
void backMenuBook(int *choiceMenuBook){
	char back;
	
	printf("    Go back menu (Enter 'Y') : ");
	scanf("%c", &back);
	if (back=="Y"||back=="y"){
		menuBook();
		scanf("%d", choiceMenuBook);
		getchar();
		
	}
}
void backMainMenu(int *choiceMainMenu){
	scanf("%d", choiceMainMenu);
	while(*choiceMainMenu<0||*choiceMainMenu>3){
		printf("    Lua chon khong hop le, yeu cau nhap lai\n\n");
		mainMenu();
			scanf("%d", choiceMainMenu);
	
	}
	printf("\n\n");
}
void display(struct book *sach, int n)
{
	printf("          **** List Book ****\n\n");
	if(n==0)
	{
		printf("    Loi: Mang dang khong co sach\n\n");
		getchar();
		return ;
	}

    printf("|============|================|============|\n");
    printf("|    ID      |     Name       |   Price    |\n");
    printf("|============|================|============|\n");
for(int i = 0; i<n; i++){

    printf("| %-10d | %-14s | %-10.2f |\n", sach[i].id, sach[i].name, sach[i].price);
    

    printf("|============|================|============|\n");
}
printf("\n");
getchar();

}
void add(struct book *sach, int *n)
{
	printf("           ***Add A New Book***\n\n");
	int IDcheck;
	if(*n>100)
	{           
			printf("    Loi: Danh sach sach da day\n");
			getchar();
			return;
	}
		while(1){
		int flag=-1;
		
		
	
			
			printf("    Nhap id sach: ");
		scanf("%d", &IDcheck);
		getchar();
		
		for(int i =0;i<*n;i++){
			if(IDcheck==sach[i].id){
				flag=1;
				printf("    Loi: Id da ton tai yeu cau nhap lai\n");
				break;
			}
			
				
				
				
			
			}
			if(flag==-1){
				break;
			}
	}
		
		
		
		
		sach[*n].id=IDcheck;
		printf("    Nhap ten sach: ");
		fgets(sach[*n].name, sizeof(sach[*n].name), stdin);
		sach[*n].name[strcspn(sach[*n].name,"\n")]='\0';
		
		
		printf("    Nhap gia sach: ");
		scanf("%f", &sach[*n].price);
		getchar();
		fflush(stdin);
		
		(*n)++;
		
		printf("\n\n    Them sach thanh cong\n\n");
		
	

}
void edit(struct book *sach, int n){
		printf("       ***Edit List Book***\n\n");
	int IDedit;
	int found;
	printf("    Nhap id sach can chinh sua: ");
	scanf("%d", &IDedit);
	getchar();
	for(int i = 0;i<n;i++){
		
		if(IDedit==sach[i].id){
			found = 1;
			printf("\n    Thong tin sach hien tai\n\n");
	printf("|============|================|============|\n");
    printf("|    ID      |     Name       |   Price    |\n");
    printf("|============|================|============|\n");
    printf("| %-10d | %-14s | %-10.2f |\n", sach[i].id, sach[i].name, sach[i].price);
    

    printf("|============|================|============|\n\n");
			printf("    Nhap ten sach moi: ");
			fgets(sach[i].name,sizeof(sach[i].name),stdin);
			sach[i].name[strcspn(sach[i].name,"\n")]='\0';
			printf("    Nhap gia sach moi: ");
			scanf("%f",&sach[i].price);
			getchar();
		}
	}
	if(found!=1){
		printf("    Loi: Khong tim thay sach can chinh sua\n");
		getchar();
		return;
	}
	printf("\n    Chinh sua thong tin sach thanh cong\n\n");
}
void Delete(struct book *sach, int *n){
		printf("       ***Delete Book***\n\n");
	int found, confirmDelete;
	int IDdelete;
	printf("    Nhap id sach can xoa: ");
    scanf("%d", &IDdelete);
    getchar();
	for(int i = 0; i<*n; i++){
		if(IDdelete==sach[i].id){
			found = 1;
			printf("    Xac nhan xoa:\n");
			printf("    1.Dong y\n");
			printf("    2.Khong\n");
			printf("    Lua chon: ");
			scanf("%d", &confirmDelete);
			getchar();
			if(confirmDelete==1){
			
			for(int j = i; j<*n-1; j++){
				sach[j]=sach[j+1];
			}
			(*n)--;
			printf(    "Xoa sach thanh cong\n");
			break;
		}else if(confirmDelete==2){
			return;
		}
	}
	}
	if(found!=1){
		printf("    Loi: Khong tim thay sinh vien can xoa\n");
		getchar();
		return;
}
}
void sort(struct book *sach, int n){
	int choiceSort;
	struct book temp;
		printf("       ***Sort List Book***\n\n");
		printf("    [1].Sap xep tang dan\n");
		printf("    [2].Sap xep giam dan\n");
		printf("    Moi nhap lua chon sap xep: ");
		scanf("%d", &choiceSort);
		getchar();
		if(choiceSort==1){
				for(int i =0;i<n-1;i++){
		for(int j =i+1;j<n;j++){
			if(sach[i].price>sach[j].price){
			
			temp=sach[i];
			sach[i]=sach[j];
			sach[j]=temp;
		}
		}
	}
		}
		else if(choiceSort==2){
				for(int i =0;i<n-1;i++){
		for(int j =i+1;j<n;j++){
			if(sach[i].price<sach[j].price){
			
			temp=sach[i];
			sach[i]=sach[j];
			sach[j]=temp;
		}
		}
	}
		}
		printf("\n\n    Sap xep thanh cong\n");
}
void loadFromFile(struct book *sach, int *n){
	FILE *fptr;
	fptr=fopen("sach.bin","rb");
if(fptr==NULL){
	printf("    Loi: khong the mo file\n");
	getchar();
	return ;
}
	fread(n,sizeof(int),1,fptr);
	fread(sach,sizeof(struct book),*n,fptr);
	printf("\n    Danh sach da duoc lay tu file\n");
	fclose(fptr);
}
void saveToFile(struct book *sach, int *n){
	FILE *fptr;
	fptr = fopen("sach.bin","wb");
	if(fptr==NULL){
		printf("    Loi: Loi mo file\n");
		getchar();
		return;
	}
	fwrite(n,sizeof(int),1,fptr);
	fwrite(sach,sizeof(struct book),*n,fptr);
	printf("\n    Danh sach da duoc luu vao file\n");
	fclose(fptr);
}
void search(struct book *sach, int n){
	char searchName[50];
	printf("Nhap ten sach can tim kiem\n");
	fgets(searchName, sizeof(searchName), stdin);
	searchName[strcspn(searchName,"\n")]='\0';
	int flag=-1;
	for(int i = 0; i<n; i++){
		if(strcasecmp(sach[i].name, searchName)==0){
			flag=i;
			break;
		}
	}
	if(flag=-1){
		printf("Loi: Khong tim thay sach");
		getchar();
		return;
	}
	printf("\n    Thong tin sach tim thay\n\n");
	printf("|============|================|============|\n");
    printf("|    ID      |     Name       |   Price    |\n");
    printf("|============|================|============|\n");
    printf("| %-10d | %-14s | %-10.2f |\n", sach[flag].id, sach[flag].name, sach[flag].price);
    

    printf("|============|================|============|\n\n");
}

