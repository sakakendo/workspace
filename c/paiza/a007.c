#include <stdio.h>

int group[100][100];
int g_len; //group nums

int search(int n){
	for(int i=0;i<g_len;i++){
		for(int j=0;group[i][j];j++){
			if(group[i][j]==n) return i; 
		}
	}
	return -1;
}
int gsize(int n){
	int i;
	while(group[n][i]){
//		printf("%d",group[n][i]);
		i++;
	}
	printf("gsize(group[%d])=%d\n",n,i);
	return i;
}
void append(int x,int y){
	int g=search(x);
	int size=gsize(g);
	printf("%s size(group[%d])=%d\n",__func__,g,size);
	group[g][size]=y;
}

void connect(int x,int y){
	printf("connect\n");
	int size=gsize(x);
	for(int i=0;group[y][i];i++){
		group[x][size+i]=group[y][i];
	}
	for(int i=0;group[y][i];i++){
		group[y][i]=0;
	}
}
void new(int x,int y){
	group[g_len][0]=x;
	group[g_len][1]=y;
	g_len++;
	printf("%s %d\n",__func__,g_len);
}

void addUser(int x,int y){
	int gx,gy;
	gx=search(x);
	gy=search(y);
	printf("%s %d%d\n",__func__,gx,gy);
	if(gx==-1 && gy==-1){
		new(x,y);
	}else if(gx!=-1 && gy==-1){
		append(x,y);
	}else if(gx==-1 && gy!=-1){
		append(y,x);
	}else if(gx!=-1 && gy!=-1){
		connect(gx,gy);
	}else{
		printf("unknown pattern \ngx :%d gy:%d",gx,gy);
	}
}
void checkUser(int x,int y){
	if(search(x)==search(y)){
		printf("yes");
	}else{
		printf("no");
	}
}

void printGroup(){
	printf("\n%s g_len:%d\n",__func__,g_len);
	for(int i=0;i<g_len;i++){
//		printf("g[%d](size:%d)=",i,gsize(i));
		for(int j=0;group[i][j];j++){
			printf("%-2d",group[i][j]);
		}
		printf("\n");
	}

}
int main(){
	int n,m;
	int a,b,c;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		if(a==0){
			addUser(b,c);
		}else if(a==1){
			checkUser(b,c);
		}
		printGroup();
	}
	return 0;
}
