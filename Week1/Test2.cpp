#include <stdio.h>

int main(void){
	/*
	int a, b;
	int result;

	a=10;
	b=20;
	result=a+b;

	
	printf("�� ���� ���� ����� result= %d + %d = %d\n", a, b, result);
	
	
	int a, b;
	if(a>5)	//a�� 5���� ū��?
	if(a<10) //a�� 10���� ������?
	
	if(a>5&&a<10)
	printf("������ ������ ����� ���� �� ���� �Է��ϼ���.\n"); 
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
	
	printf("[while]���� �̿��� ���� ���: ");
	printf("a = %d\nb = %d \n", a, b);
	printf("result = %d \n", result);
	
	result=0;
	
	for(a=t; a<=b; a++){
		if(a%2==0)
		result+=a;
	} 
	
	printf("[for]���� �̿��� ���� ���: ");
	printf("a = %d\nb = %d \n", a, b);
	printf("result = %d \n", result);
	
	int res1=0, res2=0;
	int res3=0, res4=0, res5=0, res6=0, res7=0, res8=0, res9=0;
	printf("�ݺ����� �̿��� �������\n");
	printf("%d ���� %d ������ 5�� ����� ",a,b);
	
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
	
	printf("�Դϴ�. \n\n\n");
	

	printf("a=%d\nb=%d\n", a, b);
	printf("9�� �����  ��=%d \n", res9);
	printf("8�� �����  ��=%d\n", res8); 
	printf("7�� �����  ��=%d \n", res7);
	printf("6�� �����  ��=%d\n", res6); 
	printf("5�� �����  ��=%d \n", res5);
	printf("4�� �����  ��=%d\n", res4); 
	printf("3�� �����  ��=%d \n", res3);
	printf("2�� �����  ��=%d\n", res2); 
	printf("1�� �����  ��=%d \n", res1);
	
	printf("a=%d\nb=%d\n", a, b);
	printf("¦���� ��=%d \n", res2);
	printf("Ȧ���� ��=%d\n", res1);
*/ 
	while(1){
		int a;
		printf("����Ű�� ��������. �����÷��� '0'Ű�� �������� ");
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
				printf("�����ϼ̽��ϴ�.");
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
				printf("�����ϼ̽��ϴ�.");
				break; 
		}
		printf("\n");
		
	}
	
	
	
	
	return 0;
}
