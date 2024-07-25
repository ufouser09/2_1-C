#include <stdio.h>
#include <string.h>

#define ISLETIM_SISTEMI_LINUX

int main(int argc,char** argv){
	char logDizini[50];
	#ifdef ISLETIM_SISTEMI_WINDOWS
	strcpy(logDizini,"C:\\logs");
	#elif defined(ISLETIM_SISTEMI_LINUX)
	strcpy(logdizini,"/var/log");
	#else
	strcpy(logdizini,"loglar");
	#endif
	printf("log dizini:%s\n",logDizini);
}
