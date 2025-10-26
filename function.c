#include "function.h"

//Declaration

Product products[500];

int numProducts = 0;

//==============================Start: Menu
void displayMenu() {
	
	printf("\n\t======================================\n");
    printf("\t## PRODUCT MANAGEMENT SYSTEM ##\n");
    printf("\t======================================\n");
    printf("\n\t[1] View Product\n");
    printf("\t[2] Add Product\n");
    printf("\t[3] Edit Product\n");
    printf("\t[4] Delete Product\n");
    printf("\t[5] Search Product\n");
    printf("\t[6] Sort Product\n");
    printf("\t[0] Exit\n");
    printf("\n\t======================================\n");
	
}

//==============================End: Menu





//==============================Start: View Product
void viewProduct() {
	
	printf("\n\t=== View product ===\n");
	
	if(numProducts == 0) {
		printf("\n\tNo Product Found!!!");	
	}
	else {
		for(int i = 0; i < numProducts; i++) {
			printf("\n\t%s %s %s %d %.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);       
		}
	}
	
}
//==============================End: View Product





//==============================Start: Add Product

void addProduct() {
	
	printf("\n\t=== Add product ===\n");
	
	printf("\n\tInput ID: ");
	scanf("%s", products[numProducts].id);
	
	printf("\tInput Name: ");
	scanf("%s", products[numProducts].name);
	    
	printf("\tInput Category: ");
	scanf("%s", products[numProducts].category);
	
	printf("\tInput Quantity: ");
	scanf("%d", &products[numProducts].quantity);
	
	printf("\tInput Unit Price: ");
	scanf("%f", &products[numProducts].unitPrice);
	
	numProducts = numProducts + 1;
	
	printf("\n\tProduct was added successfully!!!\n");
	
}

//==============================End: Add Product





//==============================Start: Edit Product
void editProduct() {
	printf("\n\t=== Edit product ===\n");
	printf("\n\tPlease input ID of Product: "); 
	
	char productIdToEdit[15];
	scanf("%s", productIdToEdit);
	
	int found = 0;
	for(int i = 0; i < numProducts; i++) {
		if(strcmp(productIdToEdit, products[i].id) == 0) {
			found = 1;
			
			printf("\n\tInput ID: ");
			scanf("%s", products[i].id);
			
			printf("\tInput Name: ");
			scanf("%s", products[i].name);
			    
			printf("\tInput Category: ");
			scanf("%s", products[i].category);
			
			printf("\tInput Quantity: ");
			scanf("%d", &products[i].quantity);
			
			printf("\tInput Unit Price: ");
			scanf("%f", &products[i].unitPrice);
			
			break;
		}
	}
	if(found == 1) {
		printf("\n\tProduct was edited successfully!!!");
	}
	else {
		printf("\n\tNo Product Found!!!");
	}
	
}
//==============================End: Edit Product





//==============================Start: Delete Product
void deleteProduct() {
	
	printf("\n\t=== Delete product ===\n");
	
	printf("\n\tPlease input ID of Product: ");
	
	char productIdToDelete[15];
	scanf("%s", productIdToDelete);
	
	int foundIndex = -1;
	
	for(int i = 0; i < numProducts; i++) {
		if(strcmp(productIdToDelete, products[i].id) == 0) {
			foundIndex = i;
			break;
		}
	}
	
	if(foundIndex == -1) {
		printf("\n\tNo Product Found!!!");
	}
	else {
		for(int i = foundIndex; i < numProducts - 1; i++) {
			products[i] = products[i + 1];
		}
		numProducts = numProducts - 1;
		
		printf("\n\tProduct was deleted successfully!!!\n");
	}
	

}

//==============================End: Delete Product





//==============================Start: Search Product

void searchProduct() {
	
	printf("\n\t=== Search product ===\n");
	
	printf("\n\tPlease input ID of Product: ");
	
	char productIdToSearch[15];
	scanf("%s", productIdToSearch);
	
	int found = 0;
	
	for(int i = 0; i < numProducts; i++) {
		if(strcmp(productIdToSearch, products[i].id) == 0) {
			
			found = 1;
			
			printf("\n\t%s %s %s %d %.2f", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);
			
			break;
		}
	}
	
	if(found == 1) {
		printf("\n\tProduct was found successfully!!!");
	}
	else {
		printf("\n\tNo Product Found!!!");
	}
	
}

//==============================End: Search Product





//==============================Start: Sort Product

void sortProduct() {
	
	printf("\n\t=== Sort product by Product's Name ===\n");
	
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
	
	printf("\n\tProducts were sorted successfully!!!");
	
}

//==============================End: Sort Product










