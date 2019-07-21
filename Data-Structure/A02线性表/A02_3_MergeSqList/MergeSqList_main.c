//
//  main.c
//  A02_3_MergeSqList
//
//  Created by qingmei2 on 2019/7/21.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#include <stdio.h>

#include "MergeSqList.h"
#include "../A02_1_SequenceList/SequenceList.h"

void PrintElem(LElemType_Sq e);            //测试函数，打印整型

int main(int argc, const char * argv[]) {
    SqList La, Lb, Lc1, Lc2;
    LElemType_Sq a[4] = {3, 5, 8, 11};
    LElemType_Sq b[7] = {2, 6, 8, 9, 11, 15, 20};
    int i;
    
    InitList_Sq(&La);                    //初始化La
    for(i=1; i<=4; i++)
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
    
    MergeSqList1(La, Lb, &Lc1);        //合并A与B,算法2.6
    printf("合并La和Lb为Lc1(算法2.2) = ");         //输出Lc1
    ListTraverse_Sq(Lc1, PrintElem);
    printf("\n\n");
    
    MergeSqList2(La, Lb, &Lc2);        //合并A与B,算法2.7
    printf("合并La和Lb为Lc2(算法2.7) = ");         //输出Lc2
    ListTraverse_Sq(Lc2, PrintElem);
    printf("\n\n");
    
    return 0;
}

void PrintElem(LElemType_Sq e)
{
    printf("%d ", e);
}
