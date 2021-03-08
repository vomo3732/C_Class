#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myHeader.h" 

//ASCII 코드표를 출력하는 프로그램
//printf 함수의 변환자 (%c) 사용

int Prompt(char *pt, int *ret);
int chrPos(char *str, char chr); 
int strPos(char *str, char *s1);
 
int main(){
	/*
	int i, j, k, m, m1;
	int n=5;
	
	k=(128-1)/n + 1;//(출력갯수-1)/칸수+1 
	
	for(i=0; i<k; i++){//1칸으로 출력--->4칸 혹은 n칸으로... 
		for(j=0; j<n; j++){
			m1=m=i+j*k;
			if(m1==7||m1==8||m1==9||m1==10||m1==13) m1=0x20;
			if(m1<128) printf("%3d [%02x] : %c   ",m, m, m1);
		}
		printf("\n");
//		if(i==7||i==8||i==9||i==10||i==13){
//			printf("%3d [%02x]:   | %3d [%02x]: %c | %3d [%02x]: %c | %3d [%02x]: %c\n", i,i, i, i+32, i+32, i+32, i+64, i+64, i+64, i+96, i+96, i+96);
//		}
//		else
//		printf("%3d [%02x]: %c | %3d [%02x]: %c | %3d [%02x]: %c | %3d [%02x]: %c\n", i,i, i, i+32, i+32, i+32, i+64, i+64, i+64, i+96, i+96, i+96);
	}
	 
	 
	int A, r;
	 A=Prompt("입력하세요: ",&r);
	 char str1[30];
	 char str2[10];
	 
	 fputs("What is your favorite computer language? : ", stdout);
	 fgets(str2, sizeof(str2), stdin);
	 int num=0;
	 num=atoi(str2);
	 printf("이것은 문자열입니다: %s\n", str2);
	 printf("변환된 숫자: %d \n", num);
	 return 0;
	 
	
	int a, b, c;
	Prompt("A 를 입력하세요\n", &a);
	c=Prompt("B 를 입력하세요 \n", &b);
	
	printf("A:%d B:%d C:%d", a,b,c);
	*/
	int a, b, c;
	char *str="abcdefgacdbhijklmn";
	char *s1="acdb";
	printf("문자열 : %s\n", str);
	printf("%c의 위치는 %d입니다\n", 'e', chrPos(str, 'e'));//4
	printf("%c의 위치는 %d입니다\n", 'o', chrPos(str, 'o'));//-1 
	printf("%s의 위치는 %d입니다\n",s1, strPos(str, s1));
	
}

int Prompt(char *pt, int *ret){
	char buf[254];
	printf("%s", pt);
	
	fgets(buf, 254, stdin);
	*ret=atoi(buf);
	return *ret;
}

int chrPos(char *str, char chr){
	int i, j, k;
	i=0;
	
	for(i; *(str+i); i++){
		if(*(str+i)==chr) return i;
	}
	return -1;
	
//	while(*(str+i)){
//		if(*(str+i++)==chr) return i-1;
//	}
//	return -1;
}

int strPos(char *str, char *s1){
	int i, j, k;
	int p=1;
	for(i=0; *(str+i); i+=p+1){
		p=chrPos(str+i, *s1);
		if(strncmp(str+p+i, s1, strlen(s1))==0){
			return p+i;
		}
	}
	return -1;
}

//함수의 정의:
//함수명: int chrPos(char *str, char chr);
//return type: int: chr 문자의 위 치, 없다면 -1 
//input: char *str: 대상 문자열 
//		char chr: 찾을 문자 
//기능: str로 전달된 문자열중에서 chr문자를 검색하여 해당 위치를 반환(zero base) 검색되지 않으면 -1을 반환 

//함수의 정의:
//함수명: int strPos(char *str, char *s1);
//return type: int: s1 문자의 위 치, 없다면 -1 
//input: char *str: 대상 문자열 
//		char *s1: 찾을 문자 
//기능: str로 전달된 문자열중에서 s1 문자열을 검색하여 해당 위치를 반환(zero base) 검색되지 않으면 -1을 반환 
//===로직 구현 ================================================ 
//1. str에서 s1의 첫 문자가 있는 위치를 검색
//2. 해당 위치에서 strncmp를 이용하여 비교/ 같으면 return i, 아니면 다시 1번 
//3. 만일 끝까지 없으면 -1
 

//pt로 전달된 문자열을 출력하고(안내문자) 
//입력된 정수 문자열을 숫자로 변환하여 ret값으로 반환 
//+ 함수의 return 값으로 처리 
// ex) Scanf(" %d", &r);
//		A=r;
//		===> A=Prompt("입력하세요: ", &r); 
//			--> 가장 작은(큰)값과 swap
//3. 배열 전체에 대하여 2번 과정을 반복
 

