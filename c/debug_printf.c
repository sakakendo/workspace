#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef __linux__
//#define BLUE(s)		"\e[34m"s"\e[37m"
#define RED(s)		"\033[31m"s"\033[39m"
#define Error(fmt, ...)	printf(RED("\nError: %s: %d: ")fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__)

#elif __WIN32__
#include <windows.h>
#include <string.h>

HANDLE hConsole;
WORD saved_attributes;

enum LOG_CLASS{CLASS_ERROR,CLASS_WARNING,CLASS_INFO,CLASS_LOG};
int printVA(int type,char *v,...){
  if(type==CLASS_ERROR)  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  if(type==CLASS_WARNING)  SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
  if(type==CLASS_INFO)  SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
  if(type==CLASS_LOG)  SetConsoleTextAttribute(hConsole,saved_attributes);
  char *str=(char*)malloc(sizeof(v)*100);
  va_list ap;
  va_start(ap,v);
  vsprintf(str,v,ap);
  puts(str);
  va_end(ap);
  SetConsoleTextAttribute(hConsole, saved_attributes);
}

#define Error(fmt, ...)     printVA(CLASS_ERROR,"%-8s: %s: %d: "fmt "","Error", __FUNCTION__, __LINE__, __VA_ARGS__);
#define Warning(fmt, ...)   printVA(CLASS_WARNING,"%-8s: %s: %d: "fmt "","Warning", __FUNCTION__, __LINE__, __VA_ARGS__);
#define Info(fmt, ...)      printVA(CLASS_INFO,"%-8s: %s: %d: "fmt "","Info", __FUNCTION__, __LINE__, __VA_ARGS__);
#define Log(fmt, ...)       printVA(CLASS_LOG,"%-8s: %s: %d: "fmt "","Log", __FUNCTION__, __LINE__, __VA_ARGS__);


__attribute__((constructor))
void SetupColor(){
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    hConsole  = GetStdHandle(STD_OUTPUT_HANDLE);
    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    printf("start main\n");
}
__attribute__((destructor))
void destruct(){
  printf("end main\n");
}
#else
#define Error(fmt,...) do{}whiile(0);
#endif

void func(){
  func();
}
int main() {
  char str[1];
  printf("normal\n");
  func();

  Error("hello %s","world")
  Warning("warning %s","world")
  Info("hello %s","world")
  Log("hello %s","world")

  printf("normal");
}
