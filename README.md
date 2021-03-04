# C_Class
KOSTA 2021-1 Class Resource
2021-03-02 IoT Class daily report
### C 언어 1강
출력형식, data type 별 byte 

```
#include <stdio.h> 

int main(){
//	printf("%8d\n", 1234);
//	printf("%-8d\n", 1234);
//	printf("%+8d\n",1234); 
//	printf("%8d %8d %8d\n", 123, 456, 789);
//	printf("%-8d %-8d %-8d\n", 123, 456, 789);
//	printf("%+9d %+9d %+9d\n\n\n", 123, 456, 789);
	
	printf("실수의 출력: %f %f\n\n", 3.14159265, 456.7891230);
	
	printf("실수의 출력: %8.2f %10.3f\n\n", 3.14159265, 456.7891230);
	

	printf("data type 별 byte 수(int): %d byte\n", sizeof(int));
	printf("(char): %d byte\n", sizeof(char));
	printf("(long): %d byte\n", sizeof(long));
	printf("(float): %d byte\n", sizeof(float));
	printf("(double): %d byte\n", sizeof(double));
	printf("(long long): %d byte\n", sizeof(long long));
	
	
	return 0;
}
```

switch-case문에 대한 내용

```
#include <stdio.h>

int main(void){
	
	while(1){
		int a;
		printf("숫자키를 누르세요. 끝내시려면 '0'키를 누르세요 ");
		scanf("%d", &a);
		
//		for(int i=0; i<10; i++){
//			switch(i){
//			case 1:
//				printf(">1 : One");
//				break;
//			case 2: 
//				printf(">2 : Two");
//				break;
//			case 3: 
//				printf(">3 : Three");
//				break;
//			case 4:
//				printf(">4 : Four");
//				break;
//			case 5:
//				printf(">5 : Five");
//				break;
//			case 6:
//				printf(">6 : Six");
//				break;
//			case 7:
//				printf(">7 : Seven");
//				break;
//			case 8: 
//				printf(">8 : Eight");
//				break;
//			case 9:
//				printf(">9 : Nine");
//				break;
//			default:
//				printf("수고하셨습니다.");
//				break; 
//			}
//			printf("\n");
//		}
		
		switch(a){
			case 0:
				return 0;
			case 1:
				printf(">1 : One");
				break;
			case 2: 
				printf(">2 : Two");
				break;
			case 3: 
				printf(">3 : Three");
				break;
			case 4:
				printf(">4 : Four");
				break;
			case 5:
				printf(">5 : Five");
				break;
			case 6:
				printf(">6 : Six");
				break;
			case 7:
				printf(">7 : Seven");
				break;
			case 8: 
				printf(">8 : Eight");
				break;
			case 9:
				printf(">9 : Nine");
				break;
			default:
				printf("수고하셨습니다.");
				break; 
		}
		printf("\n");
		
	}

	return 0;
}
```

03/04 getch() 함수와 배열에 대한 내용

```

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
	

}

int main(){
	

	scanf("%s", &buf);//enter 키를 눌러서 값을 되돌림 
	printf("입력 문자열은 %s 입니다\n\n\n\n", buf);
	
	while(1){	
		int ch=getch();//단일 키값을 되돌림.
		if(ch<48||ch>57) break;
		printlocation(ch);
	}

	return 0;
}

```
