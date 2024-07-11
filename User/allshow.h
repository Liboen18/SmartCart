/*
 * allshow.h
 *
 *  Created on: 2024��5��16��
 *      Author: ��Ԫ
 */

#ifndef USER_ALLSHOW_H_
#define USER_ALLSHOW_H_
#include "structures.h"

void initProductList(ProductInfoList *list);
void insertProduct(ProductInfoList *list, ProductInfo product);
void destroyProductList(ProductInfoList  *list);
void printProductList(ProductInfoList *list);
void deleteProduct(ProductInfoList *list, const char *productID);
int ALLshow();

#endif /* USER_ALLSHOW_H_ */
