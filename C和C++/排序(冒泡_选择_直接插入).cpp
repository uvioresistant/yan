/*13.2����*/
/*ð������*/
void BubbleSort(ElemType elem[], int n)
//���������������elem����ð�������������
//�����ElemType���Ի����ھ�������е���Ӧ����
{
    for (int i=n-1; i>0; i--)
        {   //��i��ð������ 
            for (int j=0; j<1; j++)
            { // �Ƚ�elem[j]��elem[j+1] 
                if (elem[j]>elem[j+1])
                { //����������򽻻�elem[j]��elem[j+1]
                    Swap(elem[j], elem[j+1]);
                    // Swap�����Ĺ����ǽ���2��������ֵ��������ʵ��
                }
            }
        } 
 }
 
/*�Ľ���ð������*/
 
