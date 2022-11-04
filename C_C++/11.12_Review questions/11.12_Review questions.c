/* 1. */
// 用,隔开了，最终只能保存最后一个's' -> 想得到一个字符串，就应在初始化中包括一个'\0'，另一种写法可自动添加空字符，char name[]="Fess";

/* 2. */
// S    -> See you at the snack bar. 
// e    -> ee you at the snack bar.
// See you
// e #？ -> e you

/* 3. */
// Y    # 因为food+4,即指向y，但--ptr即为food-4，则--ptr为Y >= food(为“Yummy”首地址Y)
// -> y # food +5 后，指向y，则--ptr，逐步指向Y，则输出如下
//    my
//    mmy
//    ummy
//    Yummy