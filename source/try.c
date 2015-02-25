#include<stdio.h>
#include<stdlib.h>


int func(int *arr)
{
    int rows = *arr;
    int columns = *(arr + 1);
    int **matrix;
    int count=0,i,j;
    int total_cells;
    
    matrix = (int**)malloc(sizeof(int*)*rows);
    for(i=0;i<columns;i++)
        matrix[i] = (int*)malloc(sizeof(int));
    
    
    
    
    total_cells = rows * columns;
    //printf("total cells = %d\n",total_cells);
    
    for(i=0;i<rows;i++)
        {
            for(j=0;j<columns;j++)
                {
                    matrix[i][j] = 1;
            }
    }
    
    for(i=0;i<rows;i++)
        {
            for(j=0;j<columns;j++)
                {
                if(matrix[i][j] == 1)
                    {
                    matrix[i][j+1] = 0;
                    matrix[i+1][j] = 0;
                    matrix[i+1][j+1] = 0;
                }
            }
    }
    
    for(i=0;i<rows;i++)
        {
            for(j=0;j<columns;j++)
                {
                    if(matrix[i][j] == 1)
                        count++;
            }
    }
    return count;
    
    
}

int main()
{
    int noOfCases;
    int **MN,i,j;
    int *cnt;
        
    scanf("%d",&noOfCases);
    
    cnt = (int*)malloc(sizeof(int)*noOfCases);
    
    MN = (int**)malloc(sizeof(int*)*noOfCases);
    for(i=0;i<noOfCases;i++)
        MN[i] = (int*)malloc(sizeof(int)*2);
    
    for(i=0;i<noOfCases;i++)
    {  
       for(j=0;j<2;j++)
       {     
           scanf("%d",&MN[i][j]);
           
       }
        cnt[i] = func(MN[i]);
    }
    
   for(i=0;i<noOfCases;i++)
       printf("%d\n",cnt[i]);
   
  return 0;  
}
