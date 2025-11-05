#include "function.h"

//Declaration

const char *filename = "data.txt";

Product products[1000];

int numProducts = 0;

//==============================Start: Menu

void displayMenu() {
	
	printf("\n\t======================================\n");
    printf("\t### PRODUCT MANAGEMENT SYSTEM ###\n");
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
	if(strlen(tempId) > 9) {
		printf("\n\tInvalid input\n");
		return;
	}
			
	printf("\tInput Name: ");
	scanf("\n");
	gets(tempName);
	if(strlen(tempName) > 49) {
		printf("\n\tInvalid input\n");
		return;
	}
		
	printf("\tInput Category: ");
	scanf("\n");
	gets(tempCategory);
	if(strlen(tempCategory) > 49) {
		printf("\n\tInvalid input\n");
		return;
	}
	
	tempName[0] = toupper(tempName[0]);
	tempCategory[0] = toupper(tempCategory[0]);
	
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
void editProduct() {
	
	viewProduct();
	
	printf("\n\t=== Edit product ===\n");
	printf("\n\tPlease input ID of Product: "); 
	
	char productIdToEdit[10];
	scanf("%9s", productIdToEdit);
	
	int found = 0;
	for(int i = 0; i < numProducts; i++) {
		if(strcmp(productIdToEdit, products[i].id) == 0) {
			found = 1;
			
			char tempId[1000];
			char tempName[1000];
			char tempCategory[1000];
	
			
			printf("\n\tInput new ID: ");
			scanf("\n");
			gets(tempId);
			if(strlen(tempId) > 9) {
				printf("\n\tInvalid input\n");
				return;
			}
			
			printf("\tInput new Name: ");
			scanf("\n");
			gets(tempName);
			if(strlen(tempName) > 49) {
				printf("\n\tInvalid input\n");
				return;
			}
			
			printf("\tInput new Category: ");
			scanf("\n");
			gets(tempCategory);
			if(strlen(tempCategory) > 49) {
				printf("\n\tInvalid input\n");
				return;
			}
			
			tempName[0] = toupper(tempName[0]);
			tempCategory[0] = toupper(tempCategory[0]);
			
			strcpy(products[i].id, tempId);
			strcpy(products[i].name, tempName);
			strcpy(products[i].category, tempCategory);
			
			printf("\tInput new Quantity: ");
			scanf("%d", &products[i].quantity);
			
			printf("\tInput new Unit Price: ");
			scanf("%f", &products[i].unitPrice);
			
			break;
		}
	}
	
	if(found == 1) {
		printf("\n\tProduct was edited successfully!!!\n");
	}
	else {
		printf("\n\tNo Product Found!!!\n");
	}
	saveToFile(products, filename);
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

void searchProduct() {
	
	printf("\n\t=== Search product ===\n");
	
	printf("\n\tPlease input ID of Product: ");
	
	char productIdToSearch[10];
	scanf("%9s", productIdToSearch);
	
	int found = 0;
	
	for(int i = 0; i < numProducts; i++) {
		if(strcmp(productIdToSearch, products[i].id) == 0) {
			
			found = 1;
			
			printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
			printf("\t=========================================================================================");
			printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);
			printf("\t=========================================================================================\n");
			
			break;
		}
	}
	
	if(found == 1) {
		printf("\n\tProduct was found successfully!!!\n");
	}
	else {
		printf("\n\tNo Product Found!!!\n");
	}
	
}

//==============================End: Search Product





//==============================Start: Sort Product

void sortProduct() {
	
	printf("\n\t=== Sort product by Product's Name (Ascending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			if(strcmp(products[j].name, products[i].name) < 0) {
				temp = products[i];
				products[i] = products[j];
				products[j] = temp;
			}
		}
	}
	
	printf("\n\tProducts were sorted successfully!!!\n");
	
	saveToFile(products, filename);
	
	viewProduct();
}

//==============================End: Sort Product
