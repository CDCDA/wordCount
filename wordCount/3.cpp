#include<iostream>           //��ǿ�棬��3 4 5 6 8 9�� 
#include<stdlib.h>
#include<string.h>
#include<queue>
#pragma warning(disable : 4996)
using namespace std;
FILE* fp = NULL;
FILE* fq = NULL;
int totalNum[3];
int *getCharNum(int *totalNum){
    char buffer[1003];  //���������洢��ȡ����ÿ�е�����
    int bufferLen;  // ��������ʵ�ʴ洢�����ݵĳ���
    int i;  // ��ǰ�����������ĵ�i���ַ�
    char c;  // ��ȡ�����ַ�
    int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
    int charNum = 0;  // ��ǰ�е��ַ���
    int wordNum = 0; // ��ǰ�еĵ�����

    printf("\n");
    // ÿ�ζ�ȡһ�����ݣ����浽buffer��ÿ�����ֻ����1000���ַ�
    while(fgets(buffer, 1003, fp) != NULL){
        bufferLen = strlen(buffer);
        // ����������������
        for(i=0; i<bufferLen; i++){
            c = buffer[i];
            if( c==' ' || c=='\t'){  // �����ո�
                !isLastBlank && wordNum++;  // ����ϸ��ַ����ǿո���ô��������1
                isLastBlank = 1;
            }else if(c!='\n'&&c!='\r'){  // ���Ի��з�
                charNum++;  // ����Ȳ��ǻ��з�Ҳ���ǿո��ַ�����1
                isLastBlank = 0;
            }
        }

        !isLastBlank && wordNum++;  // ������һ���ַ����ǿո���ô��������1
        isLastBlank = 1;  // ÿ�λ�������Ϊ1

        // һ�н������������ַ������ܵ�������������
        totalNum[0]++;  // ������
        totalNum[1] += charNum;  // ���ַ���
        totalNum[2] += wordNum;  // �ܵ�����

       // printf("%-7d%-7d%d\n", totalNum[0], wordNum, charNum);

        // ���㣬����ͳ����һ��
        charNum = 0;
        wordNum = 0;
    }
    return totalNum;
}
int main(int argc, char* argv[])
{
	string inputname;                //���������봦�� 
	string outputname;
	string a, b, c, d;
	a = "-m";
	b = "-n";
	c = "-i";
	d = "-o";
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == c)
		{
			fp = fopen(argv[++i], "r");     //���ı���ʽ���ļ���
			if (fp == NULL)               //���ļ�����
			{
				cout << "Input not found.\n" << endl;
				return 0;
			}
			continue;
		}
		if (argv[i] == d)
		{
			fq = fopen(argv[++i], "w");     //���ı���ʽ���ļ���
			if (fq == NULL)               //���ļ�����
			{
				cout << "Output not found.\n" << endl;
				return 0;
			}
			continue;
		}

	}
	 int totalNum[3] = {0, 0, 0};

   	if(fq==NULL)
	{
		cout<<"Output not found.\n"<<endl;
		return 0;
	}
	
    if(getCharNum(totalNum)){
    	fprintf(fq,"characters: %d\n",totalNum[1]);
    	fprintf(fq,"\n");
    	fprintf(fq,"words: %d\n",totalNum[2]);
    	fprintf(fq,"\n");
    	fprintf(fq,"lines: %d\n",totalNum[0]);
    	fprintf(fq,"\n");
        }
		else{
        fprintf(fq,"Error!\n");
    }
    
	if (fp != NULL)   fclose(fp);
	if (fq != NULL)  fclose(fq);
	return 0;
}

