//
//  main.c
//  A02_2_Union
//
//  Created by qingmei2 on 2019/7/21.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#include <stdio.h>

#include "Union.h"
#include "../A02_1_SequenceList/SequenceList.h"

void PrintElem(LElemType_Sq e);        //测试函数，打印整型 

int main(int argc, const char * argv[]) {
    SqList La, Lb;
    LElemType_Sq a[5] = {5, 2, 1, 3, 9};
    LElemType_Sq b[7] = {7, 2, 6, 9, 11, 3, 10};
    int i;
    
    InitList_Sq(&La);                    //初始化La
    for(i=1; i<=5; i++)
        ListInsert_Sq(&La, i, a[i-1]);
    InitList_Sq(&Lb);                    //初始化Lb
    for(i=1; i<=7; i++)
        ListInsert_Sq(&Lb, i, b[i-1]);
    
    printf("La = ");                    //输出La
    ListTraverse_Sq(La, PrintElem);
    printf("\n");
    printf("Lb = ");                    //输出Lb
    ListTraverse_Sq(Lb, PrintElem);
    printf("\n\n");
    
    printf("La = La∪Lb = ");            //输出新表La的内容
    Union(&La, Lb);
    ListTraverse_Sq(La, PrintElem);
    printf("\n\n");
    
    return 0;
}

void PrintElem(LElemType_Sq e)
{
    printf("%d ", e);
}

