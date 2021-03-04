#include <stdio.h>
#include <conio.h>
#include "MyHeader.h"
char buf[10000];

void ConvertChr(char buf[]){
	int i, j, k;
	for(i=0; buf[i]; i++){
		if(buf[i]>96&&buf[i]<123) buf[i]-=32;
		printf("%c ", buf[i]);
	}
	printf("\n");
}

void printlocation(int x){
	x=x-48;
	printf("%s (%d)  --> %c \n\n", buf, x, *(buf+x));
	
//	x=x-48;
//	printf("%c \n", buf[x]);
}

int main(){
	
	//char buf[10000];
	scanf("%s", &buf);//enter 키를 눌러서 값을 되돌림 
	printf("입력 문자열은 %s 입니다\n\n\n\n", buf);
	
	while(1){	
		int ch=getch();//단일 키값을 되돌림.
		if(ch<48||ch>57) break;
		printlocation(ch);
	}
	/*
	int a[3][2]={{1, 2}, 
				 {3, 4},
				 {5, 6}};
	printf("a[0]: %d\n", a[0]);
	printf("*(a+0): %d\n", *(a+0));
	printf("a[1]: %d\n", a[1]);
	printf("*(a+1): %d\n", *(a+1));
	printf("a[2]: %d\n", a[2]);
	printf("*(a+2): %d\n", *(a+2));
	printf("%d %d \n", a[1][0], (*(a+1))[0]);
	printf("%d %d \n", a[1][2], *(a[1]+2));
	printf("%d %d \n", a[2][1], *(*(a+2)+1));
	
	int key;//입력받기 위한 변수 선언 
	int i, j, k;//내부 사용 변 수 
	
	while(1){
		scanf("%c", &key); 
		if(key=='z') break;
		if(key!=13) func1(key);
	}
	char str1[5]={'g', 'o', 'o', 'o', 'd'};
	char str2[]="morning";
	printf("%s \n", str1);
	printf("%s %s \n",str1, str2);
	return 0;
	
	
	char buf[10000];
	while(1){
		scanf("%s", &buf);
		printf("입력 문자열은 %s 입니다\n\n\n\n", buf);
		ConvertChr(buf);
	
		for(int i=0; buf[i]!='\0'; i++){
			if(buf[i]>='a'&&buf[i]<='z'){
				buf[i]=buf[i]-32;
			}
			printf("%c ", buf[i]);
		}
		printf("\n");
		
		
	}
	
	
	int i, j, k;
	while(1){
		scanf("%s", &buf);
		printf("입력 문자열은 %s입니다\n", buf);
	}
	*/
	return 0;
}

