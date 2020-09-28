# define MAXLEN 255 //预定义最大串长为255
typedef struct{
    char ch[MAXLEN];    //每个分量存储一个字符, 静态数组实现(定长顺序存储)
    int length;         //串的实际长度
}SString;


typedef struct{
    char *ch;   //按串长分配存储区，ch指向串的基地址
    int length; //串的长度
}HString;       //动态数组实现(堆分配存储)
HString S;
S.ch = (char *)malloc(MAXLEN * sizeof(char));
S.length = 0;

/*串的链式储存*/
typedef struct StringNode{
    char ch;    //每个结点存1个字符
    struct StringNode * next;
}StringNode, * String;  //存储密度低；每个字符1B，每个指针4B

typedef struct StringNode{
    char ch[4]; //每个结点存多个字符
    struct StringNode * next;
}StringNode, *String;   //存储密度提高

/*基本操作的实现*/
//求子串
S.ch = "wangdao"
S.length = 7
# define MAXLEN 255 //预定义最大串长为255
typedef struct{
    char ch[MAXLEN];    //每个分量存储一个字符
    int length;         //串的实际长度
}SString;


bool SubString(SString &Sub, SString S, int pos, int len){
    //子串范围越界
    if (pos+len-1 > S.length)
        return false;
    for (int i=pos; i<pos+len; i++)
        Sub.ch[i-pos+1] = S.ch[i];
    Sub.length = len;
    return true;
}

 //比较操作：
 int StrCompare(SString S, SString T){
     for (int i=1; i<=S.length && i<=T.length; i++){
         if (S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
     }
     //扫描过的所有字符都相同，则长度长的串更大
     return S.length-T.length;
 }
 
 //定位操作:
 int Index(SString S, SString T){
     int i=1, n=StrLength(S), m=StrLength(T);
     SString sub;   //用于暂存子串
     while(i<=n-m+1){
         SubString(sub, S, i, m);
         if(StrCompare(sub, T)!=0) ++i;
         else return i; //返回子串在主串中的位置
     }
     return 0;  //S中不存在与T相等的子串
}
 
/*朴素模式匹配算法*/
int Index(SString S, SString T){
    int k=1;
    int i=k, j=1;
    while(i<=S.length && j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;    //继续比较后继字符
        } else{
            k++;    //检查下一个子串
            i=k;
            j=1;
        }
    }
    if(j>T.length)
        return k;
    else
        return 0;
    
}

//课本中的写法
int Index(SString S, SString T){
    int i=1, j=1;
    while(i<=S.length && j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i; ++j;
        }
        else{
            i=i-j+2;    //可以不使用变量k值，实现增加1
            j=1,    //指正后退重新开始匹配
        }        
    }
    if(j>T.length)
        return i-T.length;
    else
        return 0;
}
 
 
/*KMP算法代码*/
int Index_KMP(SString S, SString T, int next[]){
    int i=1, j=1;
    while(i<=S.length&&j<=T.length){
        if(j==0||S.ch[i]==T.ch[j]){
            ++i;
            ++j;    //继续比较后继字符
        }
        else{
            j=next[j];  //模式串向右移动
        }
        if(j>T.length)
            return i-T.length;  //匹配成功
        else
            return 0;
    }
}

//求模式串T的next数组
void get_next(SString T, int next[]){
    int i=1, j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            ++i; ++j;
            //若pi=pj，则next[j+1]=next[j]+1
            next[i]=j;
        }
        else{   //否则令j=next[j],循环继续
            j=next[j];
        }
    }
}

nextval[1]=0
for (int j=2; j<=T.length; j++){
    if(T.ch[next[j]]==T.ch[j]){
        nextval[j]=nextval[next[j]];
    }else{
        nextval[j]=next[j];
    }
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
