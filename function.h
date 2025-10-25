#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Structure definition

typedef struct {
	char id[15];
	char name[50];
	char category[50];
	int quantity;
	float unitPrice;
	
} Product;

// Macro definition
		
extern Product products[500];

extern int numProducts;

//Function

void displayMenu();

void viewProduct();
void addProduct();
void editProduct();
void deleteProduct();
void searchProduct();
void sortProduct();


#endif