#include <stdio.h>
#include <string.h>
#define MAX_PRODUCT 100
#define ADMIN_EMAIL "minhkhoi@gmail.com"
#define ADMIN_PASSWORD "1234"

typedef struct {
    char productID[10];
    char productName[20];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCT];
int productCount = 0;

void addProduct() {
	
	
	
    if (productCount > MAX_PRODUCT) {
        printf("\nProduct full!\n");
        return;
    }

    printf("\nEnter product details:\n");
    printf("Product ID: ");
    scanf("%s", products[productCount].productID);
    printf("Product Name: ");
    scanf(" %s", products[productCount].productName);
    printf("Quantity: ");
    scanf("%d", &products[productCount].quantity);
    printf("Price: ");
    scanf("%f", &products[productCount].price);

    productCount++;
    printf("\nProduct added successfully!\n");
    
    printf("[0] Back to Menu\n");
	int choice;
    printf("Choice: ");
    scanf("%d", &choice);
    if (choice == 0) return;
}

void showAllProduct() {
	
	
    
    if (productCount == 0) {
        printf("\nNo products available!\n");
        return;
    }
	printf("***Store Management Sytem Using C***");
    printf("\n%29s","---All Product---\n");
    printf("|------------|----------------|----------|----------|\n");
    printf("| Product ID | Product Name   | Quantity |  Price   |\n");
    printf("|------------|----------------|----------|----------|\n");

    for (int i = 0; i < productCount; i++) {
        printf("| %-10s | %-14s | %-8d | %-8.3f |\n",
               products[i].productID, products[i].productName,
               products[i].quantity, products[i].price);
    }

    printf("|------------|----------------|----------|----------|\n");
    
    printf("[0] Back to Menu\n");
	int choice;
    printf("Choice: ");
    scanf("%d", &choice);
    if (choice == 0) return;
}

void editProduct() {
	
	
	
    if (productCount == 0) {
        printf("\nNo products available to edit!\n");
        return;
    }

    char id[10];
    printf("\nEnter product ID to edit: ");
    scanf("%s", id);

    int found = -1;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productID, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\nProduct ID not found!\n");
        return;
    }

    printf("Product Name: %s\n", products[found].productName);
    printf("Quantity: %d\n", products[found].quantity);
    printf("Price: %.3f\n", products[found].price);

    char newName[20];
    int newQuantity;
    float newPrice;

    printf("Product Name [%s]: ", products[found].productName);
    getchar();
    fgets(newName, sizeof(newName), stdin);
    if (newName[0] != '\n') {
        newName[strcspn(newName, "\n")] = 0;
        strcpy(products[found].productName, newName);
    }

    printf("Quantity [%d]: ", products[found].quantity);
    if (scanf("%d", &newQuantity) == 1) {
        products[found].quantity = newQuantity;
    }
    getchar();

    printf("Price [%.3f]: ", products[found].price);
    if (scanf("%f", &newPrice) == 1) {
        products[found].price = newPrice;
    }

    printf("\nProduct updated successfully!\n");
    
	printf("[0] Back to Menu\n");
	int choice;
    printf("Choice: ");
    scanf("%d", &choice);
    if (choice == 0) return;
}

void deleteProduct() {
	
    
        
    if (productCount == 0) {
        printf("\nNo products available to delete!\n");
        return;
    }

    char id[10];
    printf("\nEnter Product ID to delete: ");
    scanf("%s", id);

    int found = -1;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productID, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\nProduct ID not found!\n");
        return;
    }

    for (int i = found; i < productCount - 1; i++) {
        products[i] = products[i + 1];
    }
    productCount--;

    printf("\nProduct deleted successfully!\n");
    
    printf("[0] Back to Menu\n");
	int choice;
    printf("Choice: ");
    scanf("%d", &choice);
    if (choice == 0) return;
    
}


void menu() {
    int choice;
    while (1) {
    	system("cls");  
    	printf("***Store Management Sytem Using C***\n");
        printf("\n===== MENU =====\n");
        printf("[1] Add Product\n");
        printf("[2] Show All Product\n");
        printf("[3] Edit Product\n");
        printf("[4] Delete Product\n");
        printf("[5] Exit\n");
        printf("======================\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	system("cls");
                addProduct();
                break;
            case 2:
            	system("cls");
                showAllProduct();
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
                printf("\nExit program.\n");
                return; 
            default:
                printf("\nInvalid choice. Please try again!\n");
        }
    }
}


void login() {
    char email[20], password[10];

    while (1) {
        printf("\n%22s","LOGIN\n");
        printf("minhkhoi@gmail.com\n");
        printf("1234\n");
        printf("=========================================\n");
        printf("Email: ");
        scanf("%s", email);
        printf("Password: ");
        scanf("%s", password);

        
        if (strcmp(email, ADMIN_EMAIL) == 0 && strcmp(password, ADMIN_PASSWORD) == 0) {
            printf("\nLogin successful\n");
            menu(); 
            break;
        } else {
            printf("\nInvalid login! Please try again.\n");
        }
    }
}


int main() {
    int choice;

    while (1) {
    	printf("***Store Management Sytem Using C***\n");
        printf("\n%28s","CHOOSE YOUR ROLE\n");
        printf("=========================================\n");
        printf("[1] Admin\n");
        printf("[2] Customer\n");
        printf("[0] Exit\n");
        printf("=========================================\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            login();
        } else if (choice == 2) {
            printf("\nYou are a customer\n");
            break;
        } else if (choice == 0) {
            printf("\nExit program.\n");
            return 0;
        } else {
            printf("\nInvalid choice. Please try again!\n");
        }
    }

    return 0;
}

