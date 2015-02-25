#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float calcMean(int arr[],int count)
    {
    int j;
    int sum = 0;
    for(j=0;j<count;j++)
        {
        sum += arr[j];
    }
    return (float)sum/count;
}

float calcMedian(int arr[],int count)
    {
    if(count%2==0)
        return (arr[(count/2)] + arr[(count/2)-1])/2;
    else 
        return arr[(count-1)/2];
}

int calcMode(int arr[],int count)
{
    int **b;
    int bcount=0;
    int max,maxel;
    int i,j;
    int flag=1;
    
   //for(i=0;i<count;i++)
	*b = (int*)malloc(sizeof(int)*count);
   for(i=0;i<count;i++)
	b[i] = (int*)malloc(sizeof(int)*2);

            bcount++;
            b[0][0] = arr[i];
            b[0][1] = 1;
            printf("\nbcount = %d\n",bcount);
    
    for(i=1;i<count;i++)
    {
        flag=1;
        for(j=0;(j<bcount && flag);j++)
        {
            
            if(b[j][0] == arr[i])
                {
                b[j][1]++;
                flag=0;
		
            }
        }
        if(flag)
        {
        
        b[j][0]= arr[i];
        b[j][1]++;
	bcount++;
	printf("\n bcount is now = %d\n",bcount);
            //flag=0;
        }
            //b[a[i]][j]++;
    }
    printf("\nbcount = %d\n",bcount);
    maxel = b[0][0];
    max = b[0][1];
    for(i=0;i<bcount;i++)
    {
        if(b[i][1]>max)
	{
            max = b[i][1];
	    maxel = b[i][0];
	}
    }
    return maxel;
}
int main(int argc, char** argv)
{
    int totalNumbers;
    int num[100],i;
    float mean,median;
    int mode;
    //printf("Enter total numbers\n");
    scanf("%d",&totalNumbers);
    for(i=0;i<totalNumbers;i++)
        {
            scanf("%d",&num[i]);
    }
    mean = calcMean(num,totalNumbers);
    median = calcMedian(num,totalNumbers);
    mode = calcMode(num,totalNumbers);

    printf("\nThe mean is %f\n",mean);
    printf("\nThe median is %f\n",median);
    printf("\nThe mode is %d\n",mode);

}
