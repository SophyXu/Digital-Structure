/* Author: Xu Xiaoyao; ID: 3120101033; No.01 */
#include <stdio.h>
#include <stdlib.h>
int flag = 0;
int count = 0;
struct tree
{
    int element;
	struct tree *left;
	struct tree *right;	
};

struct tree * insert(int a, struct tree *t)
{
    if(t == NULL)
    {
    	t =(struct tree *)malloc(sizeof(struct tree));
    	if(t == NULL)
    	     printf("out of space!");
        else
        {
        	t->element = a;
        	t->left = t->right = NULL;
        }
    }
	else if(a < t->element)
	{
		t->left = insert(a, t->left);
	}
	else if(a > t->element)
	{
		t->right = insert(a, t->right);
	}
	return t;
}

void preorder(int *x,struct tree *T)
{
	if(T == NULL)
	return ;
	x[count] = T->element;
	count++;
	preorder(x,T->left);
	preorder(x,T->right);
}

void del(struct tree *T)
{
	if (T == NULL) 
	  return;
	del(T->left);
	del(T->right);
	free(T);
}

int main()
{
	int N,L;
	int i,j,e,f;
	struct tree *t = NULL;
	int x[11],y[11];
	while(1)
	{
		flag = 0;   
		scanf("%d",&N);
		if(N>0)
		{
			scanf("%d",&L);	
			for(i=1;i<=N;i++)
			{
				scanf("%d",&e);
				t = insert(e,t);
			}
			count = 0; 
			preorder(x,t);  
			 
			del(t);
			t = NULL;
		    
			for(i=1;i<=L;i++)     
			{
				flag++;
				for(j=1;j<=N;j++)
				{
					scanf("%d",&e);
					t = insert(e,t); 
				}
				count = 0;
				preorder(y,t); 
			  
			  f = 0;
			  for(j=0;j<N;j++)
			  {
  			      if(x[j]!=y[j])
				     {
     					printf("No");
     					f++;
     					break;
     				}	
  			  } 
  			  if(!f)
  			   printf("Yes");
  	
  			   printf("\n");
  			  
  			  del(t);
			  t = NULL;
			}	
		}
		else 
		 break;
	}
	return 0;
}

