
#include <stdio.h>
#define func(x) _Generic((x),char* : funcs,\
							int : funcn)(x)

int funcs(char *str){
	printf(str);
}

int funcn(int n){
	printf("%d",n);
}
int main(){
	func(3);
	func("hello world");


}
