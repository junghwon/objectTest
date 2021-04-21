#ifndef PARENT_H
#define PARENT_H

#include "child.h"

// メソッドの関数ポインタを宣言
typedef int (*parentFunc)();

// クラスの宣言
typedef struct {
    // field
    int field1;
    int field2;
    // method
    parentFunc pParentFunc;
    // composition
    childClass_t childClass;
} parentClass_t;

// 外部に公開する変数と関数
extern parentClass_t parentInitValue;
extern parentClass_t parentInitValue2;
void parent_Constructor (parentClass_t *this, parentClass_t initValue, int a, int b);

#endif // PARENT_H