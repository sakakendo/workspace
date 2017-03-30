#include <stdio.h>

enum class{
	a=3,
	b,
	c,
#define op(name,_) #name
	
};

int main(){
	printf("hello wolrd");
	printf(op(3));
	return 0;
}
