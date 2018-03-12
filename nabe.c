
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

* main(){
  char str[9],n[9];
  gets(n);
//  printf("input%d\n",atoi(n));
  for(int i=1;i<atoi(n)+1;i++){
    sprintf(str,"%d",i);
    printf( "%d %s\n",i,(i%3==0||strstr(str,"3")? "nabe":"") );
  }
}
