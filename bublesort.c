#include <stdio.h>

void exchange(int t[], int p1, int p2)
{
	int temp;
  temp=t[p1];
  t[p1]=t[p2];
  t[p2]=temp;
}

void display(int t[], int size)
{
  int i;
  for(i=0; i<size; i++)
    printf("%d ", t[i]);
  printf("\n");
}


void bubblesort(int t[], int size)
{
  int permut=0;
  int i;
 // int s=size;
  while (!permut)
  {
    permut=1;
    for(i=0; i<size-1; i++)
    {
      if(t[i]>t[i+1])
      {
        exchange(t, i, i+1);
        permut=0;
      }
      
    }
    size--;
  }
}


double mean(int t[], int size)
{
  int i;
  double sum=0;
  for(i=0; i<size; i++)
    sum += t[i];
  if(size)  
  sum /= size;
  return sum;
  
}

int main()
{
  int tab1[] = {5, 4, 3, 6, 2, 1};
  int tab2[] = {3, 1, 17, 4, 10, 1};
  int tab3[] = {};
  
  bubblesort(tab1, 6);
  bubblesort(tab2, 6);
  bubblesort(tab3, 0);
  display(tab1, 6);
  display(tab2, 6);
  display(tab3, 0);
  printf("mean tab1: %f\n", mean(tab1, 6));
  printf("mean tab2: %f\n", mean(tab2, 6));
  printf("mean tab3: %f\n", mean(tab3, 0));
  return 0;
}


