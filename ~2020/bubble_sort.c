/*
사용자로부터 알파벳 문자로 구성된 문자열(길이 256으로 제한) 입력받아 
알파벳 문자가 나타내는 빈도(알파벳 대소문자 구분X)를 계산해
빈도가 낮은 알파벳부터 높은 알파벳까지 순서대로 정렬하여(버블정렬이용) 
알파벳과 빈도 수를 출력(빈도가 0인 경우 출력X)하는 프로그램 작성*/

#include <stdio.h>
#include <string.h>//문자열 라이브러리 함수 사용위해 헤더파일 포함
#define MAX	256//문자열 입력 개수 길이 256으로 제한하기
#define MAX_ALPHABET 26//알파벳 개수 26개이므로 기호상수 26으로 지정

/* 매개 변수 ch가 알파벳 문자인지를 판단하는 함수.
   알파벳이면 1, 알파벳이 아니면 0을 반환. */
int isAlpha(int ch) {
	if (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z') return 1;
	else return 0;
}

/* 매개 변수 ch가 알파벳 대문자라면 소문자로 변경시켜주는 함수 
   매개 변수 ch가 알파벳 대문자면 소문자로 변경된 정수 값, 아니면 ch 값을 그대로 반환 */
int UpperToLower(int ch) {
	char result;
	if (ch>='A'&&ch<='Z'){
		result=ch-'A'+'a';//알파벳이 대문자면 소문자로 변경해 반환
		return result;
	}
	else { 
		result=ch; 
		return result;}//알파벳이 소문자면 그대로 반환
}

int main(void)
{
	char str[MAX]; // 사용자로부터 입력 받을 문자열을 저장하기 위한 문자형 배열
	int len; // 사용자로부터 입력 받은 문자열의 길이를 저장하기 위한 변수
	int count[MAX_ALPHABET]={0};//빈도수 넣을 배열
	char ch[MAX_ALPHABET]={0};//알파벳 문자 넣을 배열
	int i, j; // 반복문의 제어를 위해 사용되는 변수
	char temp;//버블 정렬에 사용할 변수

	printf("문자열을 입력하세요:");
	gets_s(str,MAX-1);// 사용자로부터 문자열 입력

	len=strlen(str);// 입력 받은 문자열의 길이 계산 (strlen함수 이용)

	for(i=0;i<len;i++){
		if(isAlpha(str[i])==1) { //알파벳 문자면 1반환하는 함수 호출
			char lower_c=UpperToLower(str[i]); //알파벳 대문자면 소문자로 변경하는 함수 호출
			count[lower_c-'a']++;//빈도수 증가시킴
		}
		else continue; 
	}

	for(i=0;i<MAX_ALPHABET;i++){
		ch[i]='a'+i;//알파벳 소문자를 배열의 각 요소에 저장
	}
	
	for(j=0;j<MAX_ALPHABET;j++){
		for(i=0;i<MAX_ALPHABET-1;i++){
			if(count[i]>count[i+1]){
				int swap=count[i];
				count[i]=count[i+1];
				count[i+1]=swap;
				//빈도수 정렬
				temp=ch[i];
				ch[i]=ch[i+1];
				ch[i+1]=temp;
				}//빈도수 정렬하는 동시에 알파벳도 정렬
		}
	}//버블정렬

	printf("문자: 빈도수\n");
	for(i=0;i<MAX_ALPHABET;i++){
		if(count[i]==0) continue;//빈도수가 0이면 continue (출력x)
		printf("%c: %d\n", ch[i],count[i]);
	}
	
	return 0;
}
