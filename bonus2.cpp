/* Author: Xu Xiaoyao; ID: 3120101033; No.02 */
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 1000
struct HeapStruct{
	int Size;
	int * Elements;
};
struct Point{
	int Num;
	struct Point * Next;
};
void HeapInsert(struct HeapStruct *H,int x,int Hash[])
{
	int i;
	H->Size++;
	for (i = H->Size;Hash[x] < Hash[H->Elements[i/2]]; i/=2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = x;
}
int getMin(struct HeapStruct *H)
{
	return H->Elements[1];
}
void HeapDel(struct HeapStruct *H,int *Hash)
{
	int i,child,x;
	x = H->Elements[H->Size];
	H->Size--;
	for (i = 1;i*2 <=H->Size;i = child)
	{
		child  = 2*i;
		if (child != H->Size && Hash[H->Elements[child]] > Hash[H->Elements[child+1]]) child++;
		if (Hash[x] > Hash[H->Elements[child]]) H->Elements[i] = H->Elements[child];
		else break;
	}
	H->Elements[i] = x;
}
int main()
{
	int i,j,k,l,N,M;
	int Hash[MaxSize];
	int F[MaxSize],Ans[MaxSize];
	struct Point *Head[MaxSize],*p;
	struct HeapStruct *Heap;
	Heap = (struct HeapStruct *)malloc(sizeof(struct HeapStruct));
	Heap->Elements = (int*)malloc(sizeof(int)*1001);
	Heap->Elements[0] = -1;
	for (i = 0;i < MaxSize;i++)
		Head[i] = (struct Point*)malloc(sizeof(struct Point));
	

	scanf("%d",&N);
	while (N != 0)
	{
		M = 0;
		Heap->Size = 0;
		for (i = 0;i < N;i++)
			Head[i]->Next = NULL;

		for (i = 0;i<N;i++)	scanf("%d",&Hash[i]);

		for (i = 0;i<N;i++)
		{
			if (Hash[i] < 0) F[i] = -1;
			else
			{
				M++;
				int X0 = Hash[i] % N;
				F[i] = (i - X0 +N) %N;
				if (F[i] == 0)
					HeapInsert(Heap,i,Hash);
				for (j = X0;j != i;j++)	
				{
					if (j == N) j = 0;
					p = (struct Point*)malloc(sizeof(struct Point));
					p->Num = i;
					p->Next = Head[j]->Next;
					Head[j] ->Next = p;
				}
			}

		}
		
		int count = 0,x;
		while (count != M)
		{
			x = Ans[count++] = getMin(Heap);	
			HeapDel(Heap,Hash);
			p = Head[x]->Next;			
			while (p != NULL)
			{
				F[p->Num]--;
				if (F[p->Num] == 0) HeapInsert(Heap,p->Num,Hash);
				struct Point * q = p;		
				p = p->Next;
				free(q);
				
			}
		}
		for (i = 0;i < M - 1;i++)
			printf("%d ",Hash[Ans[i]]);
		printf("%d\n",Hash[Ans[i]]);
		scanf("%d",&N);

	}

	for (i = 0;i < MaxSize;i++)
		free(Head[i]);
	free(Heap->Elements);
	free(Heap);
	return 0;
}