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
				editProduct();
				break;
			case 4:
				system("cls");
				deleteProduct();
				break;
			case 5:
				system("cls");
				searchProduct();
				break;
			case 6:
				system("cls");
				sortProduct();
				break;
			case 0:
				saveToFile(products, filename);
				system("cls");
				printf("\n\tThank you for using this system!!!\n");
				break;
			default:
				printf("\n\tInvalid input! Please enter a number between 0 and 6!!!\n");
				break;
		}
		
	} while (choice != 0);
	
	return 0;
	
}