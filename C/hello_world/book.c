#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define FILENAME "books.dat"

typedef struct {
    char title[50];
    char author[50];
    int id;
    float price;
    int is_available; // 1-可借 0-已借出
} Book;

Book books[MAX_BOOKS];
int count = 0;

void saveToFile() {
    FILE *fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        printf("无法保存文件!\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(books, sizeof(Book), count, fp);
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("首次使用，创建新文件\n");
        return;
    }
    fread(&count, sizeof(int), 1, fp);
    fread(books, sizeof(Book), count, fp);
    fclose(fp);
}

void addBook() {
    if (count >= MAX_BOOKS) {
        printf("库存已满!\n");
        return;
    }
    
    Book newBook;
    printf("输入图书ID: ");
    scanf("%d", &newBook.id);
    getchar(); // 清除输入缓冲区
    
    // 检查ID是否已存在
    for (int i = 0; i < count; i++) {
        if (books[i].id == newBook.id) {
            printf("ID已存在!\n");
            return;
        }
    }
    
    printf("输入书名: ");
    fgets(newBook.title, 50, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    
    printf("输入作者: ");
    fgets(newBook.author, 50, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;
    
    printf("输入价格: ");
    scanf("%f", &newBook.price);
    
    newBook.is_available = 1;
    
    books[count++] = newBook;
    saveToFile();
    printf("添加成功!\n");
}

void displayAllBooks() {
    if (count == 0) {
        printf("没有图书记录!\n");
        return;
    }
    
    printf("\n%-5s %-20s %-15s %-10s %s\n", 
           "ID", "书名", "作者", "价格", "状态");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-15s $%-9.2f %s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].price,
               books[i].is_available ? "可借" : "已借出");
    }
}

void searchBook() {
    int choice;
    printf("搜索方式:\n");
    printf("1. 按ID\n");
    printf("2. 按书名\n");
    printf("请选择: ");
    scanf("%d", &choice);
    getchar();
    
    if (choice == 1) {
        int id;
        printf("输入要搜索的ID: ");
        scanf("%d", &id);
        
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                printf("\n找到图书:\n");
                printf("ID: %d\n书名: %s\n作者: %s\n价格: %.2f\n状态: %s\n",
                       books[i].id,
                       books[i].title,
                       books[i].author,
                       books[i].price,
                       books[i].is_available ? "可借" : "已借出");
                return;
            }
        }
        printf("未找到该ID的图书\n");
    } else if (choice == 2) {
        char title[50];
        printf("输入要搜索的书名: ");
        fgets(title, 50, stdin);
        title[strcspn(title, "\n")] = 0;
        
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(books[i].title, title) == 0) {
                printf("\n找到图书:\n");
                printf("ID: %d\n书名: %s\n作者: %s\n价格: %.2f\n状态: %s\n",
                       books[i].id,
                       books[i].title,
                       books[i].author,
                       books[i].price,
                       books[i].is_available ? "可借" : "已借出");
                found = 1;
            }
        }
        if (!found) {
            printf("未找到相关图书\n");
        }
    } else {
        printf("无效选择!\n");
    }
}

void deleteBook() {
    int id;
    printf("输入要删除的图书ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            // 将后面的元素前移
            for (int j = i; j < count - 1; j++) {
                books[j] = books[j + 1];
            }
            count--;
            saveToFile();
            printf("删除成功!\n");
            return;
        }
    }
    printf("未找到该ID的图书\n");
}

int main() {
    loadFromFile();
    int choice;
    
    while (1) {
        printf("\n图书管理系统\n");
        printf("1. 添加图书\n");
        printf("2. 显示所有图书\n");
        printf("3. 搜索图书\n");
        printf("4. 删除图书\n");
        printf("5. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayAllBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                saveToFile();
                printf("感谢使用!\n");
                exit(0);
            default:
                printf("无效选择!\n");
        }
    }
    
    return 0;
}