#include <stdio.h>
#define MAX 10
int main(int argc,char** argv){
	printf("MAX=%d",MAX);
	
	#undef MAX
	
	printf("MAX =%d",MAX);//hata MAX artýk tanýmlý degil
	
	return 0;
}
