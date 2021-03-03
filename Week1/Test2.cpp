#include <stdio.h>

int main(void){
	/*
	int a, b;
	int result;

	a=10;
	b=20;
	result=a+b;

	
	printf("두 수의 덧셈 결과는 result= %d + %d = %d\n", a, b, result);
	
	
	int a, b;
	if(a>5)	//a가 5보다 큰가?
	if(a<10) //a가 10보다 작은가?
	
	if(a>5&&a<10)
	printf("범위의 누적값 계산을 위한 두 수를 입력하세요.\n"); 
	int a, b;
	scanf("%d %d",&a, &b);

	int result=0;
	int t=a;
	while(a<=b){
		if(a%2==1){
			result+=a;
		}
		a++;
	}
	
	printf("[while]문을 이용한 누적 계산: ");
	printf("a = %d\nb = %d \n", a, b);
	printf("result = %d \n", result);
	
	result=0;
	
	for(a=t; a<=b; a++){
		if(a%2==0)
		result+=a;
	} 
	
	printf("[for]문을 이용한 누적 계산: ");
	printf("a = %d\nb = %d \n", a, b);
	printf("result = %d \n", result);
	
	int res1=0, res2=0;
	int res3=0, res4=0, res5=0, res6=0, res7=0, res8=0, res9=0;
	printf("반복문을 이용한 누적계산\n");
	printf("%d 에서 %d 까지의 5의 배수는 ",a,b);
	
	for(int i=a; i<=b; i++){
		if(i%2==0){
			res2+=i;
		}
		else res1+=i;

		if(i%5==0){
			printf("%7d", i);
		}
		if(i%9==0) res9+=i;
		else if(i%8==0) res8+=i;
		else if(i%7==0) res7+=i;
		else if(i%6==0) res6+=i;
		else if(i%5==0) res5+=i;
		else if(i%4==0) res4+=i;
		else if(i%3==0) res3+=i;
		else if(i%2==0) res2+=i;
		else res1+=i;
		
	}
	
	printf("입니다. \n\n\n");
	

	printf("a=%d\nb=%d\n", a, b);
	printf("9의 배수의  합=%d \n", res9);
	printf("8의 배수의  합=%d\n", res8); 
	printf("7의 배수의  합=%d \n", res7);
	printf("6의 배수의  합=%d\n", res6); 
	printf("5의 배수의  합=%d \n", res5);
	printf("4의 배수의  합=%d\n", res4); 
	printf("3의 배수의  합=%d \n", res3);
	printf("2의 배수의  합=%d\n", res2); 
	printf("1의 배수의  합=%d \n", res1);
	
	printf("a=%d\nb=%d\n", a, b);
	printf("짝수의 합=%d \n", res2);
	printf("홀수의 합=%d\n", res1);
*/ 
	while(1){
		int a;
		printf("숫자키를 누르세요. 끝내시려면 '0'키를 누르세요 ");
		scanf("%d", &a);
		
		for(int i=0; i<10; i++){
			switch(i){
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
