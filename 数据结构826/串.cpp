# define MAXLEN 255 //Ԥ������󴮳�Ϊ255
typedef struct{
    char ch[MAXLEN];    //ÿ�������洢һ���ַ�, ��̬����ʵ��(����˳��洢)
    int length;         //����ʵ�ʳ���
}SString;


typedef struct{
    char *ch;   //����������洢����chָ�򴮵Ļ���ַ
    int length; //���ĳ���
}HString;       //��̬����ʵ��(�ѷ���洢)
HString S;
S.ch = (char *)malloc(MAXLEN * sizeof(char));
S.length = 0;

/*������ʽ����*/
typedef struct StringNode{
    char ch;    //ÿ������1���ַ�
    struct StringNode * next;
}StringNode, * String;  //�洢�ܶȵͣ�ÿ���ַ�1B��ÿ��ָ��4B

typedef struct StringNode{
    char ch[4]; //ÿ���������ַ�
    struct StringNode * next;
}StringNode, *String;   //�洢�ܶ����

/*����������ʵ��*/
//���Ӵ�
S.ch = "wangdao"
S.length = 7
# define MAXLEN 255 //Ԥ������󴮳�Ϊ255
typedef struct{
    char ch[MAXLEN];    //ÿ�������洢һ���ַ�
    int length;         //����ʵ�ʳ���
}SString;


bool SubString(SString &Sub, SString S, int pos, int len){
    //�Ӵ���ΧԽ��
    if (pos+len-1 > S.length)
        return false;
    for (int i=pos; i<pos+len; i++)
        Sub.ch[i-pos+1] = S.ch[i];
    Sub.length = len;
    return true;
}

 //�Ƚϲ�����
 int StrCompare(SString S, SString T){
     for (int i=1; i<=S.length && i<=T.length; i++){
         if (S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
     }
     //ɨ����������ַ�����ͬ���򳤶ȳ��Ĵ�����
     return S.length-T.length;
 }
 
 //��λ����:
 int Index(SString S, SString T){
     int i=1, n=StrLength(S), m=StrLength(T);
     SString sub;   //�����ݴ��Ӵ�
     while(i<=n-m+1){
         SubString(sub, S, i, m);
         if(StrCompare(sub, T)!=0) ++i;
         else return i; //�����Ӵ��������е�λ��
     }
     return 0;  //S�в�������T��ȵ��Ӵ�
}
 
/*����ģʽƥ���㷨*/
int Index(SString S, SString T){
    int k=1;
    int i=k, j=1;
    while(i<=S.length && j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;    //�����ȽϺ���ַ�
        } else{
            k++;    //�����һ���Ӵ�
            i=k;
            j=1;
        }
    }
    if(j>T.length)
        return k;
    else
        return 0;
    
}

//�α��е�д��
int Index(SString S, SString T){
    int i=1, j=1;
    while(i<=S.length && j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i; ++j;
        }
        else{
            i=i-j+2;    //���Բ�ʹ�ñ���kֵ��ʵ������1
            j=1,    //ָ���������¿�ʼƥ��
        }        
    }
    if(j>T.length)
        return i-T.length;
    else
        return 0;
}
 
 
/*KMP�㷨����*/
int Index_KMP(SString S, SString T, int next[]){
    int i=1, j=1;
    while(i<=S.length&&j<=T.length){
        if(j==0||S.ch[i]==T.ch[j]){
            ++i;
            ++j;    //�����ȽϺ���ַ�
        }
        else{
            j=next[j];  //ģʽ�������ƶ�
        }
        if(j>T.length)
            return i-T.length;  //ƥ��ɹ�
        else
            return 0;
    }
}

//��ģʽ��T��next����
void get_next(SString T, int next[]){
    int i=1, j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            ++i; ++j;
            //��pi=pj����next[j+1]=next[j]+1
            next[i]=j;
        }
        else{   //������j=next[j],ѭ������
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

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
