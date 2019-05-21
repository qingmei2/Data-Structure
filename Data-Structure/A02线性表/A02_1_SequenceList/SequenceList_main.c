//
//  单链表顺序结构相关函数测试
//
//  Created by qingmei2 on 2019/5/7.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#include <stdio.h>
#include "SequenceList.c"

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
    
    printf("▼2\n 函数 ListEmpty_Sq 测试...\n");
    {
        ListEmpty_Sq(L) ? printf("L 为空！！\n") : printf(" L 不为空！ \n");
        printf("\n");
    }
    PressEnter;
    return 0;
}
