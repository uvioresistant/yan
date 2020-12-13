/*顺序查找的实现*/
typedef struct{			//查找表的数据结构(顺序表)
	ElemType *elem;		//动态数组基址
	int TableLen;		//表的长度
}SSTable;

//顺序查找
int Search_Seq(SSTable ST, ElemType key){
	int i;
	for(i=0; i<ST.TableLen && ST.elem[i]!=key; ++i);
	//查找成功，则返回元素下标；查找失败，则返回-1
	return i==ST.TableLen? -1 : i;
}

//课本中的实现(哨兵)
int Search_Seq(SSTable ST, ElemType key){
	ST.elem[0]=key;		//哨兵，0号位置存储哨兵~优点：无需判断是否越界，效率更高
	int i;	//数据从下标1开始存
	for(i=ST.TableLen;ST.elem[i]!=key; --i);//从后往前找
	return i;	//查找成功，则返回元素下标；查找失败，则返回0
}