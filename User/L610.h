/*
 * L610.c
 *
 *      Created on      :2024��3��22��
 *      Author          :�˲���
 *      Version         :V1.0
 *      Description     :FibocomL610�ӿڿ�,���汾Ϊ��һ�棬���Դֲڣ���Ҫȱ���Լ��ɸĽ������£�
 *                          1.�²����ڴ��ڴ�ӡ�ľ����ԣ��޷���ʾ��ӡ�����ĸ������֣������Ǵ�ӡ�̶���������
 *                            �����Ҫ�ں����ⲿ������ת���ĸ������Ƿ���ȷ���������ȷ�����������д�ַ�����ת�����͵ĺ�����
 *                          2.���ڹ�ʱ�϶̣����汾�в�����³���ԣ�����׳�ԣ��ƻ�δ����V2����ǿ��
 *                          3.����Ŀ�ƻ���Դ����˴ӵ�һ�濪ʼӦ�滮�����׶��ԣ���δ���汾�н����д���ע�ͣ��Լ�VSCode
 *                            ��ʶ��ɵ����Ľ����ĵ���������ĿĿ¼�����README.md�ļ�
 *
 *      !WARNING!       :1.���ļ��е�����Delay��ʱ����Ҫ�޸ģ��ȴ�����Ż�ʱ��ͳһ�޸ģ�
 *                       2.���ӿ�ֻ������Price��Weight���ַ�����ʽ������ʹ�ø����ʽ�����б�д����ת��������Ҫ�޸�ԭ�ġ�
 *                       3.��ʼ��ʱ��ܳ����1-2���ӣ������ĵȴ�����CH340�����շ����߼���L610��CH32֮���ͨ����
 *                       4.��ʼ��֮����Ҫ�ٵ���  void L610_Init();
 *                                          void L610_Lookup();
 *                                          void L610_RequestIP();
 *                                          void L610_SetAndConnect();
 *                                          void L610_Sub();
 *                         ������void L610_Pub(const char* productID);
 *                              ProductInfo L610_Recive();
 *                         ���ɡ�
 *
 *
 */

#ifndef USER_L610_H_
#define USER_L610_H_

#include "debug.h"
#include "usart.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

// ���������ճ���Ϊ100
//#define MAX_STRING_LENGTH 100

extern char *strx;
extern char *strstr(const char *, const char *);
extern char USART_Rbuffer[1024];
extern char USART_Rbuffer_Num;
extern char *endptr;
extern int len;
extern int number;

//���ص���Ʒ��Ϣ�ṹ��
#define MAX_PRODUCTS 100 //�涨�����Դ���100����Ʒ��Ϣ
//typedef struct {
//    char productID[MAX_STRING_LENGTH+1];
//    float productPrice;
//    char productName[MAX_STRING_LENGTH+1];
//    float productWeight;
//    char productPriceStr[MAX_STRING_LENGTH];
//    char productWeightStr[MAX_STRING_LENGTH];
//    struct ProductInfo *next;
//} ProductInfo;

//extern ProductInfo products[MAX_PRODUCTS];

void L610_Init();
void L610_Lookup();
void L610_RequestIP();
void L610_SetAndConnect();
void L610_Sub();
void L610_Pub(const char* productID,const char* AddorDelete);
ProductInfo L610_Recive();

#endif /* USER_L610_H_ */
