#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myHeader.h" 

//ASCII �ڵ�ǥ�� ����ϴ� ���α׷�
//printf �Լ��� ��ȯ�� (%c) ���

int Prompt(char *pt, int *ret);
int chrPos(char *str, char chr); 
int strPos(char *str, char *s1);
 
int main(){
	/*
	int i, j, k, m, m1;
	int n=5;
	
	k=(128-1)/n + 1;//(��°���-1)/ĭ��+1 
	
	for(i=0; i<k; i++){//1ĭ���� ���--->4ĭ Ȥ�� nĭ����... 
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
	 A=Prompt("�Է��ϼ���: ",&r);
	 char str1[30];
	 char str2[10];
	 
	 fputs("What is your favorite computer language? : ", stdout);
	 fgets(str2, sizeof(str2), stdin);
	 int num=0;
	 num=atoi(str2);
	 printf("�̰��� ���ڿ��Դϴ�: %s\n", str2);
	 printf("��ȯ�� ����: %d \n", num);
	 return 0;
	 
	
	int a, b, c;
	Prompt("A �� �Է��ϼ���\n", &a);
	c=Prompt("B �� �Է��ϼ��� \n", &b);
	
	printf("A:%d B:%d C:%d", a,b,c);
	*/
	int a, b, c;
	char *str="abcdefgacdbhijklmn";
	char *s1="acdb";
	printf("���ڿ� : %s\n", str);
	printf("%c�� ��ġ�� %d�Դϴ�\n", 'e', chrPos(str, 'e'));//4
	printf("%c�� ��ġ�� %d�Դϴ�\n", 'o', chrPos(str, 'o'));//-1 
	printf("%s�� ��ġ�� %d�Դϴ�\n",s1, strPos(str, s1));
	
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

//�Լ��� ����:
//�Լ���: int chrPos(char *str, char chr);
//return type: int: chr ������ �� ġ, ���ٸ� -1 
//input: char *str: ��� ���ڿ� 
//		char chr: ã�� ���� 
//���: str�� ���޵� ���ڿ��߿��� chr���ڸ� �˻��Ͽ� �ش� ��ġ�� ��ȯ(zero base) �˻����� ������ -1�� ��ȯ 

//�Լ��� ����:
//�Լ���: int strPos(char *str, char *s1);
//return type: int: s1 ������ �� ġ, ���ٸ� -1 
//input: char *str: ��� ���ڿ� 
//		char *s1: ã�� ���� 
//���: str�� ���޵� ���ڿ��߿��� s1 ���ڿ��� �˻��Ͽ� �ش� ��ġ�� ��ȯ(zero base) �˻����� ������ -1�� ��ȯ 
//===���� ���� ================================================ 
//1. str���� s1�� ù ���ڰ� �ִ� ��ġ�� �˻�
//2. �ش� ��ġ���� strncmp�� �̿��Ͽ� ��/ ������ return i, �ƴϸ� �ٽ� 1�� 
//3. ���� ������ ������ -1
 

//pt�� ���޵� ���ڿ��� ����ϰ�(�ȳ�����) 
//�Էµ� ���� ���ڿ��� ���ڷ� ��ȯ�Ͽ� ret������ ��ȯ 
//+ �Լ��� return ������ ó�� 
// ex) Scanf(" %d", &r);
//		A=r;
//		===> A=Prompt("�Է��ϼ���: ", &r); 
//			--> ���� ����(ū)���� swap
//3. �迭 ��ü�� ���Ͽ� 2�� ������ �ݺ�
 

