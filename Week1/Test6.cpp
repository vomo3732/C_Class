#include <stdio.h>
#include <io.h>
#include <malloc.h>


/*

void Filetest(){ //procedure �����Լ� 
	char *name=(char*)malloc(255);
	int *korean=(int*)malloc(100);
	int *math=(int*)malloc(100);
	NOTE *fp=fopen("C:\\Users\\Owner\\Desktop\\AA\\test.txt", "rb");
	
	fscanf(fp, "%s %d %d", name, korean, math);
	 
	printf("���Ͽ��� ���� ���ڿ�: \" %s  %s\"", name, korean+math);//Good Morning
	fclose(fp);
}
*/


// ������ ������ open �Ͽ� �о����
// ---> �̸�   �����1  �����2  �����3   [����]   [���]   [����] 
// ---> ȫ�浿   ����1    ����2    ����3    ����     �Ǽ�     ��� 
//
//

#define PNUM 100

int main(){
	int i, j, k; 
//	int pNum=100;
	int *eng, *kor, *san;
	
	eng=(int*)malloc(PNUM*sizeof(int));
	kor=(int*)malloc(PNUM*sizeof(int));
	san=(int*)malloc(PNUM*sizeof(int));
//	name=(char**)malloc(PNUM*10);
	
	FILE *fp=fopen("C:\\Users\\Owner\\Desktop\\AA\\test.txt", "rb");
	
	for(i=0; i<PNUM; i++){
		k= fscanf(fp, "%d %d %d", kor+i, eng+i, san+i);
		if(k!=3) break;
		//for�� ����Ǿ��� ���� i���� ������ ����Ű����? : �������� ���� 
	}
	int n=i;
	for(i=0; i<n; i++){
		printf("%d   %d   %d \n", *(kor+i), *(eng+i), *(san+i));
	}
	
	//fprintf(fp, "Hello!");
	//Filetest();
	fclose(fp);
}
