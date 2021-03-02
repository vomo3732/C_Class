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
