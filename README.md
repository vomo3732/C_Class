# C_Class
KOSTA 2021-1 Class Resource
2021-03-02 IoT Class daily report
### C 언어 1강
출력형식, byte

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
