#include <string.h>

void connect(char a[],char b[]){
	int lenSum=(int)strlen(a)+(int)strlen(b);
	for(int i=(int)strlen(a),j=0;i<lenSum;i++,j++){
		a[i]=b[j];
	}
	a[lenSum]='\0';
}
