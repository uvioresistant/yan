/* 1. */
// 8,8
// 4,4
// 0,0
// 2,2

/* 2. */
// 4个元素

/* 3. */
// 8、4、4 ->++f不是合法的C，ref是常量而不是变量

/* 4. */ 
// -> ptr指向第一个元素，ptr+2指向第三个元素，是第二行的第一个元素
// a. *ptr==12、*(ptr+2)==16
// b. *ptr==12、*(ptr+2)==14

/* 5. */
// -> ptr指向第一行，ptr+1指向第二行，*ptr指向第一行中的第一个元素，而*(ptr+1)指向第二行中的第一个元素
// a. **ptr==12、**(ptr+1)==14  ->**ptr==12、**(ptr+1)=16
// b. **ptr==12、**(ptr+1)==0   ->**ptr==12、**(ptr+1)==14 (因为有花括号，所以只有12在第一行中)

/* 6. */
// a. &grid[22][56]
// b. &(*grid[22])[0]、&*grid[22]   -> &grid[22][0]、&grid[22]
// c. &grid、&grid[0]、&grid[0][0]  ->&grid[0][0]、grid[0]、(int *)grid :这里grid[0]是整数元素grid[0][0]的地址，grid是数组grid[0]的地址，这两个地址具有相同的数值但是类型不同，类型指派可以使它们的类型相同

/* 7. */
// a. int digits[10];
// b. float rates[6];
// c. int mat[3][5];
// d. char * psa[20]; -> []的优先级比* 高，所以没有()时，首先应用数组描述符，然后才是指针描述符，这个声明与char* (psa[20]); 相同
// e. char pstr[][20]; -> char (*pstr)[20]; char *pstr[20];是错误的，会使pstr成为指针数组，而不是指向数组的指针。pstr会指向一个单个char(数组的第一个元素)；pstr+1会指向下一个字节。使用正确的声明，pstr是一个变量而不是一个数组名，pstr+1指向起始字节后的第20个字节

/* 8. */
// a. int list{1, 2, 4, 8, 16, 32}; -> int sextet[6] = {1, 2, 4, 8, 16, 32};
// b. list[2];  
// c. int arr[100] = -1 -> int lots[100] = {[99]=-1};

/* 9. */
// 0~9

/* 10 */
// a 对
// b 错 ->错，rootbeer不是一个float变量
// c 对 ->错，rootbeer不是一个float变量
// d 对 ->错，rootbeer不是一个float变量
// e 对
// f 错 ->错，不能使用数组赋值
// g 错 ->错，value不是一个地址
// h 对

/* 11. */
// int cow[800][600];   -> int screen[800][600];

/* 12. */
// a. void func1(int n, double trots[n]);   -> void process(double ar[], int n);
// func1(trots);    -> process(trots, 20);
// VLA: void func1(int, double trots[*]);   ->void processvla(int n, double ar[n]);
// func1(trots);    ->processvla(20, trots);

// b.void func2(int n, int n clops[][]);    -> void process2(short ar2[30], int n);
// func2(n, m, clops[n][m]);                -> process2(clops, 10);
// VLA: void func2vla(int, int clops[*][*]); -> void process2vla(int n, int m, short ar2[n][m]);
// func2vla(10, 30, clops);    -> process2vla(10, 30, clops);

// c.void func3(int x, int y, int z clops[x][y][z]);    ->void process3(long ar3[10][15], int n);
// func3(x, y, z shots[x][y][z]);                       ->process3(shots, 5);
// VLA: void func3vla(int, int, int clops[*][*][*]);    ->void process3vla(int n, int m, int k long ar3[n][m][k]);
// func3vla(5, 10, 15, shots);                          ->process3vla(5, 10, 15, shots);

/* 13. */
// a. show((double []){8, 3, 9, 2});                -> show((int [4]){8, 3, 9, 2}, 4);
// b. show((double [][3]){8, 3, 9},{5, 4, 1});      -> show((int [][3]){{8, 3, 9},{5, 4, 1}}, 2);
