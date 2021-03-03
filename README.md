# C_Class
KOSTA 2021-1 Class Resource
2021-03-02 IoT Class daily report
### C 언어 1강
basical things about C
switch-case문에 대한 

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
