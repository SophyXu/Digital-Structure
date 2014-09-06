#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int MaxDeep = 0;  /*define a global variable to record the max deep of a tree*/ 
int son[101][101];  /*define a global array to store the nodes*/ 
int F[101];  /*define a global array to store the number of leaves on each level*/

/*this funtion is used to record the number of leaves on each level for a certain tree*/
void dfs(int x,int deep)
{	
	int i;	
	if (son[x][0]==0) 	/*it means that this node is a leaf*/
  	{		
    	F[deep]++;		/*we add 1 to the number of the leaves on this level*/
		if (deep>MaxDeep)     /*record the current max deep*/
		MaxDeep = deep;		
		return ;	
	}	
	for (i = 1;i <=son[x][0];i++)	
 	 {		
		dfs(son[x][i],deep+1);	 /*we use depth-first search here to count leaves*/ 
 	 }
}

int main()
{	
	int ri,i,j,k,l,m,M,N;
	int flag=0;
	while(1)
    {
	   if(flag)    /*if it is not the fist time that we do the search*/
  	   printf("\n");
	scanf("%d %d",&N,&M);
	if(N)   /*if N>0, then we start the search*/ 
	 {	
	  MaxDeep = 0;	 /*initialise MaxDeep every time*/
	for (i = 1;i<=N;i++)    /*first assume that every family member doesn't have a child*/
		son[i][0] = 0; 
	for (i = 0;i<=N;i++)    /*we first define the number of leaves on every level to be 0*/ 
		F[i] = 0;
	for (ri = 1;ri <= M ;ri++)   /*read the M following line*/
	  {
		scanf("%d %d",&k,&m);
		son[k][0] = m;		    /*we record the number of children of k*/
		for (i = 1;i<=m;i++)    /*then we record the children of k*/
			scanf("%d",&son[k][i]);
	  }
     	dfs(1,0);	/*we use this funtion to find the number of leaves on each level*/

	     for (i=0;i<MaxDeep;i++)    /*do the output*/
		   printf("%d ",F[i]);
         printf("%d",F[i]);
         
		 flag++;
	  }
	else     /*the input ends*/
		break;  
	}
	return 0;
}

