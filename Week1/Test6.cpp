#include <stdio.h>
#include <io.h>
#include <malloc.h>


/*

void Filetest(){ //procedure 절차함수 
	char *name=(char*)malloc(255);
	int *korean=(int*)malloc(100);
	int *math=(int*)malloc(100);
	NOTE *fp=fopen("C:\\Users\\Owner\\Desktop\\AA\\test.txt", "rb");
	
	fscanf(fp, "%s %d %d", name, korean, math);
	 
	printf("파일에서 읽은 문자열: \" %s  %s\"", name, korean+math);//Good Morning
	fclose(fp);
}
*/


// 데이터 파일을 open 하여 읽어오기
// ---> 이름   과목명1  과목명2  과목명3   [총점]   [평균]   [석차] 
// ---> 홍길동   점수1    점수2    점수3    총점     실수     등수 
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
		//for문 종료되었을 때의 i값은 무엇을 가리키나요? : 데이터의 갯수 
	}
	int n=i;
	for(i=0; i<n; i++){
		printf("%d   %d   %d \n", *(kor+i), *(eng+i), *(san+i));
	}
	
	//fprintf(fp, "Hello!");
	//Filetest();
	fclose(fp);
}
