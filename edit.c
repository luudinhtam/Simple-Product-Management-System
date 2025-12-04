#include "function.h"

void editProductAll(int index) {
	
	char tempName[1000];
	
	printf("\n\tInput new Name (Old name: %s): ", products[index].name);
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
			
	for(int i = 0; i < strlen(tempName); i++) {
		if(i == 0 || tempName[i - 1] == ' ') {
			tempName[i] = toupper(tempName[i]);
		}
	}
	strcpy(products[index].name, tempName);
	
	char tempCategory[1000];
			
	printf("\n\tInput new Category (Old category: %s): ", products[index].category);
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
			
	for(int i = 0; i < strlen(tempCategory); i++) {
		if(i == 0 || tempCategory[i - 1] == ' ') {
			tempCategory[i] = toupper(tempCategory[i]);
		}
	}
	strcpy(products[index].category, tempCategory);
	
	printf("\n\tInput new Quantity (Old category: %d): ", products[index].quantity);
	scanf("%d", &products[index].quantity);
	
	printf("\n\tInput new Unit Price (Old category: %.2f): ", products[index].unitPrice);
	scanf("%f", &products[index].unitPrice);
	
	saveToFile(products, filename);
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[index].id, products[index].name, products[index].category, products[index].quantity, products[index].unitPrice);
	printf("\t=========================================================================================\n");
	
}

void editProductName(int index) {
	
	char tempName[1000];
	
	printf("\n\tInput new Name (Old name: %s): ", products[index].name);
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
			
	for(int i = 0; i < strlen(tempName); i++) {
		if(i == 0 || tempName[i - 1] == ' ') {
			tempName[i] = toupper(tempName[i]);
		}
	}
	strcpy(products[index].name, tempName);
	
	saveToFile(products, filename);
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[index].id, products[index].name, products[index].category, products[index].quantity, products[index].unitPrice);
	printf("\t=========================================================================================\n");
}

void editProductCategory(int index) {
	
	char tempCategory[1000];
			
	printf("\n\tInput new Category (Old category: %s): ", products[index].category);
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
			
	for(int i = 0; i < strlen(tempCategory); i++) {
		if(i == 0 || tempCategory[i - 1] == ' ') {
			tempCategory[i] = toupper(tempCategory[i]);
		}
	}
	strcpy(products[index].category, tempCategory);
			
	saveToFile(products, filename);
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[index].id, products[index].name, products[index].category, products[index].quantity, products[index].unitPrice);
	printf("\t=========================================================================================\n");
}

void editProductQuantity(int index) {
	
	printf("\n\tInput new Quantity (Old category: %d): ", products[index].quantity);
	scanf("%d", &products[index].quantity);
	
	saveToFile(products, filename);
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[index].id, products[index].name, products[index].category, products[index].quantity, products[index].unitPrice);
	printf("\t=========================================================================================\n");
}

void editProductUnitPrice(int index) {
			
	printf("\n\tInput new Unit Price (Old category: %.2f): ", products[index].unitPrice);
	scanf("%f", &products[index].unitPrice);
	
	saveToFile(products, filename);
	
	printf("\n\t%-10s  %-20s  %-20s  %-20s  %-20s\n", "ID", "Name", "Category", "Quantity", "Unit Price");
	printf("\t=========================================================================================");
	printf("\n\t%-10s  %-20s  %-20s  %-20d  $%-20.2f\n", products[index].id, products[index].name, products[index].category, products[index].quantity, products[index].unitPrice);
	printf("\t=========================================================================================\n");
}
















