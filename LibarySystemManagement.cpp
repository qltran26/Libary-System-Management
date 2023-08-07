#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	
struct books {
		char id[8];
		char name[32];
		char author[32];
		char fields[32];
		int year;
		int page;
		char state[32];
	};
	struct books b[144];
	int n;

void add(){
	printf("Enter number of books: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("Enter information of book [%d]:\n", i);
		
		fflush(stdin);
		printf("ID: ");
		gets(b[i].id);
		
		fflush(stdin);
		printf("Name: ");
		gets(b[i].name);
		
		fflush(stdin);
		printf("Author: ");
		gets(b[i].author);
		
		fflush(stdin);
		printf("Fields: ");
		gets(b[i].fields);
		
		printf("Release year: ");
		scanf("%d", &b[i].year);
		
		printf("Page: ");
		scanf("%d", &b[i].page);
		
		fflush(stdin);
		printf("State: ");
		gets(b[i].state);
		
		printf("\n");
	}
	
	printf("Press Enter to continue...");
	fflush(stdin);
    getchar();
}

void list(){
	printf("+======================================+\n");
    printf("|             LIST OF BOOKS            |\n");
    printf("+======================================+\n");
    
    for(int i = 0; i < n; i++){
    	printf("ID: %s\n", b[i].id);
    	printf("Name: %s\n",  b[i].name);
    	printf("Author: %s\n", b[i].author);
    	printf("Fields: %s\n", b[i].fields);
    	printf("Release year: %d\n", b[i].year);
    	printf("Pages: %d\n", b[i].page);
    	printf("State: %s\n", b[i].state);
    	
    	printf("\n");
    }
    
    printf("Press Enter to continue...");
    fflush(stdin);
    getchar();
}

void search(){
	char search_id[8];
	printf("Enter book's ID: ");
	gets(search_id);
	
	int found = 0;
	for(int i = 0; i < n; i++){
		if(strcmp(search_id, b[i].id) == 0){
			printf("ID: %s\n", b[i].id);
    		printf("Name: %s\n",  b[i].name);
    		printf("Author: %s\n", b[i].author);
    		printf("Fields: %s\n", b[i].fields);
    		printf("Release year: %d\n", b[i].year);
    		printf("Pages: %d\n", b[i].page);
    		printf("State: %s\n", b[i].state);
    		
    		found = 1;
    		break;
		
		} if(found == 0) {
			printf("Book's ID is not available !");
		}
	}
	
	printf("Press Enter to continue...");
	fflush(stdin);
    getchar();
}

void rented(){
	for(int i = 0; i < n; i++){
		if(strcmp(b[i].state, "Available")){
			printf("ID: %s\n", b[i].id);
    		printf("Name: %s\n",  b[i].name);
    		printf("Author: %s\n", b[i].author);
    		printf("Fields: %s\n", b[i].fields);
    		printf("Release year: %d\n", b[i].year);
    		printf("Pages: %d\n", b[i].page);
    		printf("State: %s\n", b[i].state);
    		
    		printf("\n");
		}
	}
	
	printf("Press Enter to continue...");
	fflush(stdin);
    getchar(); 
}
		
void deleted(){
	char deleted_id[8];
	printf("Enter book's ID to delete: ");
	gets(deleted_id);
	
	int found = 0;
	for(int i = 0; i < n; i++){
		if(strcmp(deleted_id, b[i].id) == 0){
			for (int j = i; j < n - 1; j++){
                b[j] = b[j + 1];
            }
            n--;
            found = 1;
            printf("Book deleted successfully.\n");
            break;
		}
	}
	
	printf("Press Enter to continue...");
	fflush(stdin);
    getchar();	
}

void sort_year(){
	for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (b[i].year > b[j].year){
                struct books temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
	}
        printf("Books sorted by year successfully.\n");
        
        for (int i = 0; i < n - 1; i++){
        	printf("ID: %s\n", b[i].id);
    		printf("Name: %s\n",  b[i].name);
    		printf("Author: %s\n", b[i].author);
    		printf("Fields: %s\n", b[i].fields);
    		printf("Release year: %d\n", b[i].year);
    		printf("Pages: %d\n", b[i].page);
    		printf("State: %s\n", b[i].state);
    		
    		printf("\n");
		}
    
	printf("Press Enter to continue...");
	fflush(stdin);
    getchar();
}

void sort_name(){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (strcmp(b[i].name, b[j].name) > 0){
                struct books temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
        printf("Books sorted by name successfully.\n");
    
    for(int i = 0; i < n; i++){
        printf("ID: %s\n", b[i].id);
        printf("Name: %s\n",  b[i].name);
        printf("Author: %s\n", b[i].author);
        printf("Fields: %s\n", b[i].fields);
        printf("Release year: %d\n", b[i].year);
        printf("Pages: %d\n", b[i].page);
        printf("State: %s\n", b[i].state);
        
		printf("\n");
    }
    
    printf("Press Enter to continue...");
    fflush(stdin);
    getchar();
}

void save(){
	char file_name[32];
	printf("Enter file name: ");
	fflush(stdin);
	gets(file_name);
	
	FILE *fout = fopen(file_name, "w+");
	fwrite(b, sizeof(struct books), n, fout);
	
	printf("File saved !");
	
	fclose(fout);
}

void load(){
	char file_name[32];
	printf("Enter file name: ");
	fflush(stdin);
	gets(file_name);
	
	FILE *fin = fopen(file_name, "r");
	
	if(fin == NULL){
		printf("\nFile not found!\n");
		return;
	}
	
	fseek(fin, 0, SEEK_END);
	int b_num = (ftell(fin)) / sizeof(struct books);
	fseek(fin, 0, SEEK_SET);
	
	fread(&b[n], sizeof(struct books), b_num, fin);
	n += b_num;
	
	printf("File loaded !");
	
	list();

	fclose(fin);
}	
	
int main() {
	while(1){
		system("cls");
			
		printf("+======================================+\n");
		printf("|       LIBRARY MANAGEMENT SYSTEM      |\n");
		printf("+======================================+\n");
		printf("|> 1. Add book                         |\n");
		printf("|> 2. List book                        |\n");
		printf("|> 3. Search book                      |\n");
		printf("|> 4. Rented book                      |\n");
		printf("|> 5. Delete book                      |\n");
		printf("|> 6. Sort by year                     |\n");
		printf("|> 7. Sort by name                     |\n");
		printf("|> 8. Save                             |\n");
		printf("|> 9. Load                             |\n");
		printf("+======================================+\n");
			
		int choice;
		printf("Enter choice: ");
		scanf("%d", &choice);
			
		while (choice < 1 || choice > 9){
		printf("Enter choice again ");
		scanf("%d", &choice);
	}
			
		switch (choice){
		case 1:
			add();
			break;
		case 2:
			list();
			break;
		case 3:
			search();
			break;
		case 4:
			rented();
			break;
		case 5:
			deleted();
			break;
		case 6:
			sort_year();
			break;
		case 7:
			sort_name();
			break;		
		case 8:
			save();
			break;			
		case 9:
			load();
			break;
		default:
			break;	
		}
	}
}

