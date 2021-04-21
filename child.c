#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "child.h"

// メソッド宣言
static int childMethod (childClass_t *this);

// インスタンスの初期値
childClass_t childInitValue = {
    0,
    &childMethod,
};

// メソッド定義
static int childMethod (childClass_t *this)
{
    printf ("This function is childMethod\n");
    printf ("num = %d\n", this->field);
}

// コンストラクタ
void child_Constructor (childClass_t *this, childClass_t initValue, int num)
{
    this->field = num;
    this->pChildFunc = initValue.pChildFunc;
}
