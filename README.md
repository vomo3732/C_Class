# C_Class
KOSTA 2021-1 Class Resource
IoT Class daily report
### C 언어 1강

#### 03/02 
출력형식, 데이터 타입별 byte 

```
#include <stdio.h> 
int main(){
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

#### 03/03 
switch-case문에 대한 내용

```
#include <stdio.h>
int main(void){
	while(1){
		int a;
		printf("숫자키를 누르세요. 끝내시려면 '0'키를 누르세요 ");
		scanf("%d", &a);
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

#### 03/04 
getch() 함수와 배열에 대한 내용

```
#include <stdio.h>
#include <conio.h>
char buf[10000];
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

#### 03/05
함수와 포인터를 사용해서 최대공약수를 구하는 내용
```
#include <stdio.h>

int GetCD(int num, int *arr){
   int i,j,k;
   for(i=1,j=0;i<=num;i++){
      if(num%i == 0){
         *(arr+j) = i;
         j++;
         // *arr++=i; 
      }
   }
   return j;
}

int GetGCD(int *arr1, int n1, int *arr2, int n2){
   int i,j,k;
   for(i=n1-1;i>=0;i--){ //for(i=0;i<n1;i++)
      for(j=0;j<n2;j++){
         if(*(arr1+i) == *(arr2+j)) return *(arr1+i);
      }
   }
   return -1; //error발생 고려 
}

int GetGCD2(int n1, int n2){   
   for(int i=n1;i>0;i--){
      if(n1%i == 0 && n2%1 == 0) return i;
   }   
}

int main(){
   int num1, num2;
   int n1, n2, MaxNum;
   int arr1[100],arr2[100];
   
   printf("2개의 숫자를 입력하세요.\n");
   scanf("%d %d",&num1,&num2);
   
   n1 = GetCD(num1, arr1); // n1 : 1st 수의 약수 갯수 
   n2 = GetCD(num2, arr2); // n2 : 2st 수의 약수 갯수 
   
   MaxNum = GetGCD(arr1,n1,arr2,n2);
   
   // num1의 약수와 num2의 약수 출력 
   printf("%d의 약수 : ", num1);
   for(int i=0;i<n1;i++){
      printf("%d ",arr1[i]);
   }
   printf("\n%d의 약수 : ", num2);
   for(int i=0;i<n2;i++){
      printf("%d ",arr2[i]);
   }
   printf("\n\n%d와 %d의 최대공약수는 %d입니다.\n", num1, num2, MaxNum);
   return 0;
} 
```
