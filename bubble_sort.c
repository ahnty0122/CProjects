/*
����ڷκ��� ���ĺ� ���ڷ� ������ ���ڿ�(���� 256���� ����) �Է¹޾� 
���ĺ� ���ڰ� ��Ÿ���� ��(���ĺ� ��ҹ��� ����X)�� �����
�󵵰� ���� ���ĺ����� ���� ���ĺ����� ������� �����Ͽ�(���������̿�) 
���ĺ��� �� ���� ���(�󵵰� 0�� ��� ���X)�ϴ� ���α׷� �ۼ�*/

#include <stdio.h>
#include <string.h>//���ڿ� ���̺귯�� �Լ� ������� ������� ����
#define MAX	256//���ڿ� �Է� ���� ���� 256���� �����ϱ�
#define MAX_ALPHABET 26//���ĺ� ���� 26���̹Ƿ� ��ȣ��� 26���� ����

/* �Ű� ���� ch�� ���ĺ� ���������� �Ǵ��ϴ� �Լ�.
   ���ĺ��̸� 1, ���ĺ��� �ƴϸ� 0�� ��ȯ. */
int isAlpha(int ch) {
	if (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z') return 1;
	else return 0;
}

/* �Ű� ���� ch�� ���ĺ� �빮�ڶ�� �ҹ��ڷ� ��������ִ� �Լ� 
   �Ű� ���� ch�� ���ĺ� �빮�ڸ� �ҹ��ڷ� ����� ���� ��, �ƴϸ� ch ���� �״�� ��ȯ */
int UpperToLower(int ch) {
	char result;
	if (ch>='A'&&ch<='Z'){
		result=ch-'A'+'a';//���ĺ��� �빮�ڸ� �ҹ��ڷ� ������ ��ȯ
		return result;
	}
	else { 
		result=ch; 
		return result;}//���ĺ��� �ҹ��ڸ� �״�� ��ȯ
}

int main(void)
{
	char str[MAX]; // ����ڷκ��� �Է� ���� ���ڿ��� �����ϱ� ���� ������ �迭
	int len; // ����ڷκ��� �Է� ���� ���ڿ��� ���̸� �����ϱ� ���� ����
	int count[MAX_ALPHABET]={0};//�󵵼� ���� �迭
	char ch[MAX_ALPHABET]={0};//���ĺ� ���� ���� �迭
	int i, j; // �ݺ����� ��� ���� ���Ǵ� ����
	char temp;//���� ���Ŀ� ����� ����

	printf("���ڿ��� �Է��ϼ���:");
	gets_s(str,MAX-1);// ����ڷκ��� ���ڿ� �Է�

	len=strlen(str);// �Է� ���� ���ڿ��� ���� ��� (strlen�Լ� �̿�)

	for(i=0;i<len;i++){
		if(isAlpha(str[i])==1) { //���ĺ� ���ڸ� 1��ȯ�ϴ� �Լ� ȣ��
			char lower_c=UpperToLower(str[i]); //���ĺ� �빮�ڸ� �ҹ��ڷ� �����ϴ� �Լ� ȣ��
			count[lower_c-'a']++;//�󵵼� ������Ŵ
		}
		else continue; 
	}

	for(i=0;i<MAX_ALPHABET;i++){
		ch[i]='a'+i;//���ĺ� �ҹ��ڸ� �迭�� �� ��ҿ� ����
	}
	
	for(j=0;j<MAX_ALPHABET;j++){
		for(i=0;i<MAX_ALPHABET-1;i++){
			if(count[i]>count[i+1]){
				int swap=count[i];
				count[i]=count[i+1];
				count[i+1]=swap;
				//�󵵼� ����
				temp=ch[i];
				ch[i]=ch[i+1];
				ch[i+1]=temp;
				}//�󵵼� �����ϴ� ���ÿ� ���ĺ��� ����
		}
	}//��������

	printf("����: �󵵼�\n");
	for(i=0;i<MAX_ALPHABET;i++){
		if(count[i]==0) continue;//�󵵼��� 0�̸� continue (���x)
		printf("%c: %d\n", ch[i],count[i]);
	}
	
	return 0;
}
