/*
 * allshow.c
 *
 *  Created on: 2024��5��16��
 *      Author: ��Ԫ
 */
#include "L610.h"
#include "structures.h"
#include "stdlib.h"
#include <string.h>
#include "allshow.h"

// ��ʼ������
void initProductList(ProductInfoList *list)
{
    list->head = NULL;
    list->size = 0;
}

// ������β��������Ʒ��Ϣ
void insertProduct(ProductInfoList *list, ProductInfo product)
{
    ProductInfo *newProduct = (ProductInfo *)malloc(sizeof(ProductInfo));
    if (newProduct == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    *newProduct = product;
    newProduct->next = NULL;

    if (list->head == NULL) {
        list->head = newProduct;
    } else {
        ProductInfo *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProduct;
    }
    list->size++;
}

// ��������
void destroyProductList(ProductInfoList  *list)
{
    ProductInfo *current = list->head;
    while (current != NULL) {
        ProductInfo *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->size = 0;
}

// ��ӡ�����е���Ʒ��Ϣ
void printProductList(ProductInfoList *list)
{
    ProductInfo *current = list->head;
    while (current != NULL) {
        printf("Product ID: %s\n", current->productID);
        printf("Product Name: %s\n", current->productName);
        printf("Product Price: %.2f\n", current->productPrice);
        printf("Product Weight: %.2f\n", current->productWeight);
        printf("-----------------\n");
        current = current->next;
    }
}
void deleteProduct(ProductInfoList *list, const char *productID)
{
    if (list->head == NULL) {
        // ����Ϊ��
        return;
    }

    ProductInfo *current = list->head;
    ProductInfo *previous = NULL;

    // ����Ҫɾ���Ľڵ�
    while (current != NULL && strcmp(current->productID, productID) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // û���ҵ�Ҫɾ���Ľڵ�
        printf("Product with ID %s not found.\n", productID);
        return;
    }

    // ɾ���ڵ�
    if (previous == NULL) {
        // Ҫɾ���Ľڵ���ͷ�ڵ�
        list->head = current->next;
    } else {
        // Ҫɾ���Ľڵ��������м��β��
        previous->next = current->next;
    }

    free(current);
    list->size--;
    printf("Product with ID %s deleted.\n", productID);
}
int ALLshow()
{
        ProductInfoList  productList;
        initProductList(&productList);

        // ѭ��������Ʒ��Ϣ����������
        for (int i = 0; i < MAX_PRODUCTS; i++) {
            ProductInfo product = L610_Recive();
            if (strlen(product.productID) == 0) {
                // ����յ�����Ʒ��Ϣ��IDΪ�գ����������
                break;
            }
            insertProduct(&productList, product);
        }

        // ��ӡ�����е���Ʒ��Ϣ
        printf("Product List:\n");
        printProductList(&productList);

//        // ��������
//        destroyProductList(&productList);

        return 0;


}

//Pro createList()
//{
//
//     int n=5;
//     Pro list =NULL;
//     for(int i=0;i<=n;i++)
//     {
//         ProductInfo productPriceStr=L610_Recive();
//         Pro p_new = (Pro)malloc(sizeof(ProductInfo));
//         if (p_new == NULL)
//         {
//            fprintf(stderr, "Memory allocation failed\n");
//            exit(1);
//         }
//         p_new->productPriceStr =productPriceStr;
//         p_new ->next =list;
//         list = p_new ;
//
//     }
//     return list;
//}
//void printList(Pro list)
//{
//    while(list!=NULL)
//    {
//      printf("%f",list->productPriceStr);
//      list = list ->next;
//
//    }
//}
//void freeProductList(Pro list)
//{
//    while (list != NULL)
//    {
//        Pro temp = list;
//        list = list->next;
//        free(temp);
//    }
//}
//
////����
//
//void test()
//{
//
//    Pro list =createList();
//    printList(list);
//    freeProductList(list);
//
//}

//�˺������ڽ�Ŀǰ��ӵ���Ʒ����Ϣ������Ļ��

