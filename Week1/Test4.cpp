#include <stdio.h>
/*
int xarr[100];
int yarr[100];

void Sorting(int arr[]){
	int minimum=2147000000;
	for(int i=0; i<5; i++){
		for(int j=i+1; j<5; j++){
			
			if(arr[j]<arr[i]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(int i=0; i<5; i++){
		printf("%d ",arr[i]);
	}
	printf("\n%d", arr[0]);
}

void gcd(int a, int b){
    //printf("B");
    int xcnt=0;
    int ycnt=0;
    
    for(int i=a; i>=1; i--){
    	if(a%i==0) xarr[xcnt++]=i;
	}
	for(int j=b; j>=1; j--){
		if(b%j==0) yarr[ycnt++]=j;
	}
	
	int xnum=0;
	int ynum=0;
	while(1){
		if(xarr[xnum]==yarr[ynum]){
			printf("%d", xarr[xnum]);
			break;
		}
		else if(xarr[xnum]>yarr[ynum]) xnum++;
		else ynum++;
	}
}
*/
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
   return -1; //error�߻� ��� 
}

int main(void){
	/*
	int a=2005;
	int b=2021; 
	int* pA=&a;
	
	printf("pA   : %08x \n", pA);//%08x : 8�ڸ��� 16���� ǥ�� 
	printf("&a   : %08x \n", &a);//������� 0���� ä�� 
	(*pA)++; //a++ �� ���� �ǹ̸� �� �� 
	
	printf("a    : %d\n",a);
	printf("*pA  : %d\n", *pA);
	
	pA++; // a ���� ������ �ּ� 
	printf("pA   : %08x \n", pA);
	printf("*pA  : %d\n", *pA);
	
	
	
	for(int i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}
	
	Sorting(arr);
	
	swap(arr, arr+1)//swap(&arr[0], arr[0]+1);
	*/
	
//	int x, y;
//	scanf("%d %d", &x, &y);
	//printf("A");
	//gcd(x, y);
	
   	int num1, num2;
  	int n1, n2, MaxNum;
  	int arr1[100],arr2[100];
   
   	printf("2���� ���ڸ� �Է��ϼ���.\n");
   	scanf("%d %d",&num1,&num2);
   
   	n1 = GetCD(num1, arr1); // n1 : 1st ���� ��� ���� 
   	n2 = GetCD(num2, arr2); // n2 : 2st ���� ��� ���� 
   
   	MaxNum = GetGCD(arr1,n1,arr2,n2);
   
   	// num1�� ����� num2�� ��� ��� 
   	printf("%d�� ��� : ", num1);
   	for(int i=0;i<n1;i++){
    	printf("%d ",arr1[i]);
	}
   	printf("\n%d�� ��� : ", num2);
   	for(int i=0;i<n2;i++){
		printf("%d ",arr2[i]);
   	}
   	printf("\n\n%d�� %d�� �ִ������� %d�Դϴ�.\n", num1, num2, MaxNum);
   	return 0;
}
