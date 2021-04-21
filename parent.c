#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "parent.h"

// メソッド宣言
static int parentMethod (parentClass_t *this);
static int parentMethod2 (parentClass_t *this);

// インスタンスの初期値
parentClass_t parentInitValue = {
    0,
    0,
    &parentMethod,
};

parentClass_t parentInitValue2 = {
    0,
    0,
    &parentMethod2,
};

// メソッド定義
static int parentMethod (parentClass_t *this)
{
    printf("This function is parentMethod\n");

    if (this->field1 >= 1) {
        this->childClass.pChildFunc(&this->childClass);
    } else {
        printf("Child function is not execute\n");
    }
}

static int parentMethod2 (parentClass_t *this)
{
    printf("This function is parentMethod2\n");
}

// コンストラクタ
void parent_Constructor (parentClass_t *this, parentClass_t initValue, int num1, int num2)
{
    this->field1 = num1;
    this->field2 = num2;
    this->pParentFunc = initValue.pParentFunc;

    child_Constructor(&this->childClass, childInitValue, this->field2);
}
