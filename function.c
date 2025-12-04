#include "function.h"
#include "stdlib.h"

//Declaration

const char *filename = "data.txt";

Product products[1000];

int numProducts = 0;

//==============================Start: Menu

void displayMenu() {
	
	printf("\n\t======================================\n");
    printf("\t### Product Management System ###\n");
    printf("\t======================================\n");
    printf("\n\t[1] View Product\n");
    printf("\t[2] Add Product\n");
    printf("\t[3] Edit Product\n");
    printf("\t[4] Delete Product\n");
    printf("\t[5] Search Product\n");
    printf("\t[6] Sort Product\n");
    printf("\t[0] Save and Exit\n");
    printf("\n\t======================================\n");
	
}

//==============================End: Menu





//==============================Start: Load from File

int loadFromFile(Product products[], const char *filename) {
	FILE *file = fopen(filename, "r");
	
	if(file == NULL) {
		perror("\n\tError loading from file! ");
		return 0;
	}
	
	int count = 0;
	
	while (fscanf(file, "%9[^,], %49[^,], %49[^,], %d, %f\n", products[count].id, products[count].name, products[count].category, &products[count].quantity, &products[count].unitPrice) == 5) {                  
		count = count + 1;
	}
	
	fclose(file);
	
	return count;
}

//==============================End: Load from File




//==============================Start: Save to File

void saveToFile(Product products[], const char *filename) {
	FILE *file = fopen(filename, "w");
	
	if(file == NULL) {
		perror("\n\tError saving to file! ");
		return;
	}
	
	for(int i = 0; i < numProducts; i++) {
		
		fprintf(file, "%s, %s, %s, %d, %.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);
		
	}
	
	fclose(file);
	
	printf("\n\tProducts data was saved successfully!!!\n");
	
}
//==============================End: Save to File





//==============================Start: View Product
void viewProduct() {
	
	printf("\n\t=== View product ===\n");
	
	if(numProducts == 0) {
		printf("\n\tNo Product Found!!!");
	}
	else {
		
		printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
		printf("\t=========================================================================================");
		
		for(int i = 0; i < numProducts; i++) {
			printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);       
			
		}
		printf("\t=========================================================================================\n");
	}
	
}
//==============================End: View Product





//==============================Start: Add Product
void addProduct() {
	printf("\n\t=== Add product ===\n");
	
	char tempId[1000];
	char tempName[1000];
	char tempCategory[1000];
	
	printf("\n\tInput ID: ");
	scanf("\n");
	gets(tempId);
	if(strlen(tempId) < 10) {
		for(int i = 0; i < strlen(tempId); i++) {
			if(!isdigit(tempId[i])) {
				printf("\n\tInvalid input\n");
				return;
			}
		}
	}
	else {
		printf("\n\tInvalid input\n");
		return;
	}
			
	printf("\tInput Name: ");
	scanf("\n");
	gets(tempName);
	if(strlen(tempName) < 50) {
		for(int i = 0; i < strlen(tempName); i++) {
			if(!isalpha(tempName[i])) {
				printf("\n\tInvalid input\n");
				return;
			}
		}
	}
	else {
		printf("\n\tInvalid input\n");
		return;
	}
		
	printf("\tInput Category: ");
	scanf("\n");
	gets(tempCategory);
	if(strlen(tempCategory) < 50) {
		for(int i = 0; i < strlen(tempCategory); i++) {
			if(!isalpha(tempCategory[i])) {
				printf("\n\tInvalid input\n");
				return;
			}
		}
	}
	else {
		printf("\n\tInvalid input\n");
		return;
	}
	
	for(int i = 0; i < strlen(tempName); i++) {
		if(i == 0 || tempName[i - 1] == ' ') {
			tempName[i] = toupper(tempName[i]);
		}
	}
	
	for(int i = 0; i < strlen(tempCategory); i++) {
		if(i == 0 || tempCategory[i - 1] == ' ') {
			tempCategory[i] = toupper(tempCategory[i]);
		}
	}
	
	strcpy(products[numProducts].id, tempId);
	strcpy(products[numProducts].name, tempName);
	strcpy(products[numProducts].category, tempCategory);
			
	printf("\tInput Quantity: ");
	scanf("%d", &products[numProducts].quantity);
	printf("\tInput Unit Price: ");
	scanf("%f", &products[numProducts].unitPrice);
	
	numProducts = numProducts + 1;
	printf("\n\tProduct was added successfully!!!\n");
	
	saveToFile(products, filename);
}

//==============================End: Add Product





//==============================Start: Edit Product
void editProductMenu() {
	
	viewProduct();
	
	printf("\n\t=== Edit product ===\n");
	printf("\n\tPlease input ID of Product: "); 
	
	char productIdToEdit[10];
	scanf("%9s", productIdToEdit);
	
	int index = -1;
	for(int i = 0; i < numProducts; i++) {
		if(strcmp(productIdToEdit, products[i].id) == 0) {
			index = i;
			break;
		}
	}
	
	if(index == -1) {
		printf("\n\tNo Product Found!!!\n");
		printf("\n\tPlease try again...\n");
		return;
	}
	
	int choice;
	
    printf("\t======================================\n");
    printf("\n\tWhat do you want to edit ?\n");
    printf("\n\t[1] Name\n");
    printf("\t[2] Category\n");
    printf("\t[3] Quantity\n");
    printf("\t[4] Unit Price\n");
    printf("\t[5] All\n");
    printf("\t[0] Exit\n");
    printf("\n\t======================================\n");
    
	printf("\n\tEnter your choice (0-4): ");
	scanf("%d", &choice);
	
	switch(choice) {
		case 1:
			editProductName(index);
			break;
		case 2:
			editProductCategory(index);
			break;
		case 3:
			editProductQuantity(index);
			break;
		case 4:
			editProductUnitPrice(index);
			break;
		case 5:
			editProductAll(index);
			break;
		case 0:
			break;
		default:
			printf("\n\tInvalid input! Please enter a number between 0 and 6!!!\n");
			break;
	}
	
}
//==============================End: Edit Product





//==============================Start: Delete Product
void deleteProduct() {
	
	viewProduct();
	
	printf("\n\t=== Delete product ===\n");
	
	printf("\n\tPlease input ID of Product: ");
	
	char productIdToDelete[10];
	scanf("%9s", productIdToDelete);
	
	int foundIndex = -1;
	
	for(int i = 0; i < numProducts; i++) {
		if(strcmp(productIdToDelete, products[i].id) == 0) {
			foundIndex = i;
			break;
		}
	}
	
	if(foundIndex == -1) {
		printf("\n\tNo Product Found!!!\n");
	}
	else {
		for(int i = foundIndex; i < numProducts - 1; i++) {
			products[i] = products[i + 1];
		}
		numProducts = numProducts - 1;
		
		printf("\n\tProduct was deleted successfully!!!\n");
	}
	
	saveToFile(products, filename);

}

//==============================End: Delete Product





//==============================Start: Search Product

void searchProductMenu() {
	
	int choice;
	
	printf("\n\t======================================\n");
    printf("\t### Search Product Menu ###\n");
    printf("\t======================================\n");
    printf("\n\t[1] Search Product by Id\n");
    printf("\t[2] Max Unit Price Product\n");
    printf("\t[3] Min Unit Price Product\n");
    printf("\t[4] Max Quantity Product\n");
    printf("\t[5] Min Quantity Product\n");
    printf("\t[6] Same Category Products\n");
    printf("\t[0] Exit\n");
    printf("\n\t======================================\n");
    
	printf("\n\tEnter your choice (0-6): ");
	scanf("%d", &choice);
	
	switch(choice) {
		case 1:
			system("cls");
			searchProductById();
			break;
		case 2:
			system("cls");
			searchMaxUnitPriceProduct();
			break;
		case 3:
			system("cls");
			searchMinUnitPriceProduct();
			break;
		case 4:
			system("cls");
			searchMaxQuantityProduct();
			break;
		case 5:
			system("cls");
			searchMinQuantityProduct();
			break;
		case 6:
			system("cls");
			searchSameCategoryProduct();
			break;
		case 0:
			break;
		default:
			printf("\n\tInvalid input! Please enter a number between 0 and 6!!!\n");
			break;
	}
	
}

//==============================End: Search Product



//==============================Start: Sort Product

void sortProductMenu() {
	
	int choice;
	
	printf("\n\t======================================\n");
    printf("\t### Sort Product Menu ###\n");
    printf("\t======================================\n");
    printf("\n\t[1] Sort Product by Id\n");
    printf("\t[2] Sort Product by Name\n");
    printf("\t[3] Sort Product by Category\n");
    printf("\t[4] Sort Product by Quantity\n");
    printf("\t[5] Sort Product by Unit Price\n");
    printf("\t[0] Exit\n");
    printf("\n\t======================================\n");
    
	printf("\n\tEnter your choice (0-5): ");
	scanf("%d", &choice);
	
	switch(choice) {
		case 1:
			if(sortSelection() == 1) {
				sortProductByIdAscending();
				break;
			}
			else {
				sortProductByIdDescending();
				break;
			}
		case 2:
			if(sortSelection() == 1) {
				sortProductByNameAscending();
				break;
			}
			else {
				sortProductByNameDescending();
				break;
			}
		case 3:
			if(sortSelection() == 1) {
				sortProductByCategoryAscending();
				break;
			}
			else {
				sortProductByCategoryDescending();
				break;
			}
		case 4:
			if(sortSelection() == 1) {
				sortProductByQuantityAscending();
				break;
			}
			else {
				sortProductByQuantityDescending();
				break;
			}
		case 5:
			if(sortSelection() == 1) {
				sortProductByUnitPriceAscending();
				break;
			}
			else {
				sortProductByUnitPriceDescending();
				break;
			}
		case 0:
			break;
		default:
			printf("\n\tInvalid input! Please enter a number between 0 and 5!!!\n");
			break;
	}
}

//==============================End: Sort Product
