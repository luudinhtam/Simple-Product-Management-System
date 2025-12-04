#include "function.h"
#include <stdlib.h>

void searchProductById() {
	
	printf("\n\t=== Search Product by ID ===\n");
	
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

void searchMaxUnitPriceProduct() {
	printf("\n\t=== Search Max Unit Price Product ===\n");
	
	float maxUnitPrice = 0;
	
	for(int i = 0; i < numProducts; i++) {
		if(products[i].unitPrice > maxUnitPrice) {
			maxUnitPrice = products[i].unitPrice;
		}
	}
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	for(int i = 0; i < numProducts; i++) {
		if(products[i].unitPrice == maxUnitPrice) {
			printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);
		}
	}                                                                                                                                              
	printf("\t=========================================================================================\n");
}

void searchMinUnitPriceProduct() {
	printf("\n\t=== Search Min Unit Price Product ===\n");
	
	float minUnitPrice = 1000000000;
	
	for(int i = 0; i < numProducts; i++) {
		if(products[i].unitPrice < minUnitPrice) {
			minUnitPrice = products[i].unitPrice;
		}
	}
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	for(int i = 0; i < numProducts; i++) {
		if(products[i].unitPrice == minUnitPrice) {
			printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);
		}
	}                                                                                                                                              
	printf("\t=========================================================================================\n");
}

void searchMaxQuantityProduct() {
	printf("\n\t=== Search Max Quantity Product ===\n");
	
	int maxQuantity = 0;
	
	for(int i = 0; i < numProducts; i++) {
		if(products[i].quantity > maxQuantity) {
			maxQuantity = products[i].quantity;
		}
	}
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	for(int i = 0; i < numProducts; i++) {
		if(products[i].quantity == maxQuantity) {
			printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);
		}
	}                                                                                                                                              
	printf("\t=========================================================================================\n");
}

void searchMinQuantityProduct() {
	printf("\n\t=== Search Min Quantity Product ===\n");
	
	int minQuantity = INT_MAX;
	
	for(int i = 0; i < numProducts; i++) {
		if(products[i].quantity < minQuantity) {
			minQuantity = products[i].quantity;
		}
	}
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	for(int i = 0; i < numProducts; i++) {
		if(products[i].quantity == minQuantity) {
			printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);
		}
	}                                                                                                                                              
	printf("\t=========================================================================================\n");
}

void searchSameCategoryProduct() {
	printf("\n\t=== Search Same Category Product ===\n");
	
	printf("\n\tPlease input Product's Category: ");
	
	char categoryToSearch[50] = "";
	int found = 0;
	
	scanf("%49s", categoryToSearch);
	
	categoryToSearch[0] = toupper(categoryToSearch[0]);
	
	for(int i = 0; i < numProducts; i++) {
		if(strcmp(categoryToSearch, products[i].category) == 0) {
			found = 1;
			break;
		}
	}
	
	if(found == 0) {
		printf("\n\tNo Product Found!!!\n");
		printf("\n\tPlease try again...\n");
		return;
	}
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	for(int i = 0; i < numProducts; i++) {
		if(strcmp(categoryToSearch, products[i].category) == 0) {
			printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[i].id, products[i].name, products[i].category, products[i].quantity, products[i].unitPrice);
		}
	}
	
	printf("\t=========================================================================================\n");
	
	
	
	
}
















