#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//Structure definition

typedef struct {
	char id[10];
	char name[50];
	char category[50];
	int quantity;
	float unitPrice;
	
} Product;

// Macro definition

extern const char *filename;
		
extern Product products[];

extern int numProducts;

//Function

void displayMenu();

void viewProduct();
void addProduct();
void editProduct();
void deleteProduct();
void searchProduct();
void sortProduct();

void saveToFile(Product products[], const char *filename);
int loadFromFile(Product products[], const char *filename);

#endif