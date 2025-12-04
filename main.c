#include "function.h"


int main() {
	
	numProducts = loadFromFile(products, filename);
	
	int choice;
	
	do {
		displayMenu();
		
		printf("\tEnter your choice (0-6): ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				system("cls");
				viewProduct();
				break;
			case 2:
				system("cls");
				addProduct();
				break;
			case 3:
				system("cls");
				editProductMenu();
				break;
			case 4:
				system("cls");
				deleteProduct();
				break;
			case 5:
				system("cls");
				searchProductMenu();
				break;
			case 6:
				system("cls");
				sortProductMenu();
				break;
			case 0:
				system("cls");
				saveToFile(products, filename);
				printf("\n\tExit successfully!!!\n");
				break;
			default:
				printf("\n\tInvalid input! Please enter a number between 0 and 6!!!\n");
				break;
		}
		
	} while (choice != 0);
	
	return 0;
	
}