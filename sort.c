#include "function.h"
#include <stdlib.h>

int sortSelection() {
	printf("\n\t=== Ascending or Descending order ===\n");
	printf("\n\t[1] Ascending order\n");
    printf("\t[2] Descending order\n");
    
    int selection;
    printf("\n\tEnter your choice: ");
    scanf("%d", &selection);
    
    return selection;
}

void sortProductByIdAscending() {
	printf("\n\t=== Sort product by Product's Id (Ascending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			int iId = atoi(products[i].id);
			int jId = atoi(products[j].id);
			if(jId < iId) {
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

void sortProductByIdDescending() {
	printf("\n\t=== Sort product by Product's Id (Descending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			int iId = atoi(products[i].id);
			int jId = atoi(products[j].id);
			if(jId > iId) {
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

void sortProductByNameAscending() {
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

void sortProductByNameDescending() {
	printf("\n\t=== Sort product by Product's Name (Descending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			if(strcmp(products[j].name, products[i].name) > 0) {
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

void sortProductByCategoryAscending() {
	printf("\n\t=== Sort product by Product's Category (Ascending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			if(strcmp(products[j].category, products[i].category) < 0) {
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

void sortProductByCategoryDescending() {
	printf("\n\t=== Sort product by Product's Category (Descending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			if(strcmp(products[j].category, products[i].category) > 0) {
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

void sortProductByQuantityAscending() {
	printf("\n\t=== Sort product by Product's Quantity (Ascending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			if(products[j].quantity < products[i].quantity) {
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

void sortProductByQuantityDescending() {
	printf("\n\t=== Sort product by Product's Quantity (Descending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			if(products[j].quantity > products[i].quantity) {
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

void sortProductByUnitPriceAscending() {
	printf("\n\t=== Sort product by Product's Unit Price (Ascending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			if(products[j].unitPrice < products[i].unitPrice) {
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

void sortProductByUnitPriceDescending() {
	printf("\n\t=== Sort product by Product's Unit Price (Descending Order) ===\n");
	
	Product temp;
	
	for(int i = 0; i < numProducts - 1; i++) {
		for(int j = i + 1; j < numProducts; j++) {
			if(products[j].unitPrice > products[i].unitPrice) {
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











