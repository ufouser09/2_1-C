#include <stdio.h>
#include <string.h>
int main(){
	const char* ankaraKod="06";
	const char* istanbulKod="34";
	
	char plakalar[][20]={"06 AA 122","34 ZA 243","06 BB 222","34 UUU 34","35 CC 456"};
	
	int i;
	for(i=0;i<5;i++){
		if(strncmp(plakalar[i],ankaraKod,2)==0){
			printf("%s-(ankara)\n",plakalar[i]);
		}
	   else if(strncmp(plakalar[i],istanbulKod,2)==0){
			printf("%s-(istanbul)\n",plakalar[i]);
		}
	}
	return 0;
}



//sayfa 344
