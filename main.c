#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "parent.h"

#define INSTANCE_ARRY_MAX (2)


// 配列にインスタンスを登録
static void addInstanceArry(int *count, parentClass_t **arry, parentClass_t *instance)
{
    if (*count < INSTANCE_ARRY_MAX) {
        arry[*count] = instance;
        (*count)++;
    }
}

// main ---------------------------------------------
int main (int argc, char *argv[])
{
    if (argc < 4) {
        int lessNum = 4 - argc;
        printf ("Error 引数が%dつ足りません\n", lessNum);
        return (1);
    }
    int a = *argv[1] - '0';
    int b = *argv[2] - '0';
    int c = *argv[3] - '0';

    // インスタンス生成＆初期化
    parentClass_t parentInstance1, parentInstance2;
    parent_Constructor(&parentInstance1, parentInitValue, a, b);
    parent_Constructor(&parentInstance2, parentInitValue2, a, c);

    // 配列にインスタンスを登録
    parentClass_t* instanceArry[INSTANCE_ARRY_MAX];
    int arryCount = 0;
    addInstanceArry(&arryCount, instanceArry, &parentInstance1);
    addInstanceArry(&arryCount, instanceArry, &parentInstance2);

    // 実行
    for (int i = 0; i < arryCount; i++) {
        instanceArry[i]->pParentFunc(instanceArry[i]);
    }

    return (0);    
}
