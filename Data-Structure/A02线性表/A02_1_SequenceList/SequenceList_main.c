//
//  单链表顺序结构相关函数测试
//
//  Created by qingmei2 on 2019/5/7.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#include <stdio.h>
#include "SequenceList.h"

// 若 data > e 返回true， 否则返回false
Status CmpGreater(LElemType_Sq e, LElemType_Sq data)
{
    return data > e ? TRUE : FALSE;
}

// 测试函数，打印整型
void PrintElem(LElemType_Sq e)
{
    printf("%d", e);
}

int main(int argc, const char * argv[]) {
    SqList L;
    int i;
    LElemType_Sq e;
    
    printf("▼1\n 函数 InitList_Sq 测试...\n");
    {
        printf("初始化顺序表 L ...\n");
        InitList_Sq(&L);
        printf("\n");
    }
    PressEnter;
    
    printf("▼4\n 函数 ListEmpty_Sq 测试...\n");
    {
        ListEmpty_Sq(L) ? printf("L 为空！！\n") : printf(" L 不为空！ \n");
        printf("\n");
    }
    PressEnter;
    
    printf("▼10\n 函数 ListInsert_Sq 测试...\n");
    {
        for (i = 1; i < 6; i++) {
            printf("作为示范， 在 L 的第 %d 个位置插入\"%d\"..\n", i, 2 * i);
            ListInsert_Sq(&L, i, 2 * i);
        }
        printf("\n");
    }
    PressEnter;
    
    printf("▼12\n 函数 ListTraverse_Sq 测试...\n");
    {
        printf("L 中的元素为：L = ");
        ListTraverse_Sq(L, PrintElem);
        printf("\n\n");
    }
    PressEnter;
    
    printf("▼5\n▲函数 ListLength_Sq 测试...\n");
    {
        i = ListLength_Sq(L);
        printf("L的长度为 %d", i);
        printf("\n");
    }
    PressEnter;
    
    printf("▼11\n▲函数 ListDelete_Sq 测试...\n");
    {
        ListDelete_Sq(&L, 2, &e);
        printf("删除第2个元素,被删除的值为 %d", *(&e));
        printf("L 中的元素为：L = ");
        ListTraverse_Sq(L, PrintElem);
        printf("\n");
    }
    PressEnter;
    
    printf("▼6\n▲函数 GetElem_Sq 测试...\n");            //6.函数GetElem_Sq测试
    {
        GetElem_Sq(L, 4, &e);
        printf(" L 中第 4 个位置的元素为 \"%d\" \n", e);
        printf("\n");
    }
    PressEnter;
    
    printf("▼7\n▲函数 LocateElem_Sq 测试...\n");          //7.函数LocateElem_Sq测试
    {
        i = LocateElem_Sq(L, 7, CmpGreater);
        printf(" L 中第一个元素值大于 \"7\" 的元素的位置为 %d \n", i);
        printf("\n");
    }
    PressEnter;

    printf("▼8\n▲函数 PriorElem_Sq 测试...\n");        //8.函数PriorElem_Sq测试
    {
        PriorElem_Sq(L, 6, &e);
        printf("元素 \"6\" 的前驱为 \"%d\" \n", e);
        printf("\n");
    }
    PressEnter;
    
    printf("▼9\n▲函数 NextElem_Sq 测试...\n");        //9.函数NextElem_Sq测试
    {
        NextElem_Sq(L, 6, &e);
        printf("元素 \"6\" 的后继为 \"%d\" \n", e);
        printf("\n");
    }
    PressEnter;
    
    printf("▼2\n▲函数 ClearList_Sq 测试...\n");        //2.函数ClearList_Sq测试
    {
        printf("清空 L 前：");
        ListEmpty_Sq(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
        ClearList_Sq(&L);
        printf("清空 L 后：");
        ListEmpty_Sq(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
        printf("\n");
    }
    PressEnter;
    
    printf("▼3\n▲函数 DestroyList_Sq 测试...\n");        //3.函数DestroyList_Sq测试
    {
        printf("销毁 L 前：");
        L.elem ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
        DestoryList_Sq(&L);
        printf("销毁 L 后：");
        L.elem ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
        printf("\n");
    }
    PressEnter;
    return 0;
}
