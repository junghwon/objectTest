#ifndef CHILD_H
#define CHILD_H

// メソッドの関数ポインタを宣言
typedef int (*childFunc)();

// クラスの宣言
typedef struct {
    // field
    int field;
    // method
    childFunc pChildFunc;
} childClass_t;

// 外部に公開する変数と関数
extern childClass_t childInitValue;
void child_Constructor (childClass_t *this, childClass_t initValue, int num);

#endif // CHILD_H