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

//ALL FUNCTIONS

//Display the main menu
void displayMenu();

//View Function
void viewProduct();

//Add Function
void addProduct();

//Edit Function
void editProductMenu();

void editProductAll(int index);

void editProductName(int index);

void editProductCategory(int index);

void editProductQuantity(int index);

void editProductUnitPrice(int index);

//Delete Function
void deleteProduct();

//Search Function
void searchProductMenu();

void searchProductById();

void searchMaxUnitPriceProduct();
void searchMinUnitPriceProduct();

void searchMaxQuantityProduct();
void searchMinQuantityProduct();

void searchSameCategoryProduct();

//Sort Function
void sortProductMenu();

int sortSelection();

void sortProductByIdDescending();
void sortProductByIdAscending();

void sortProductByNameDescending();
void sortProductByNameAscending();

void sortProductByCategoryAscending();
void sortProductByCategoryDescending();

void sortProductByQuantityAscending();
void sortProductByQuantityDescending();

void sortProductByUnitPriceAscending();
void sortProductByUnitPriceDescending();


//Working with FILE
void saveToFile(Product products[], const char *filename);
int loadFromFile(Product products[], const char *filename);

#endif