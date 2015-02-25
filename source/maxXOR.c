#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {

    int diff = r-l+1;
    int *arr,size,j,k;
    int p = l,max;
    
    size = diff*(diff+1)/2;
    arr = (int*)malloc(sizeof(int)*size);
    int i=0;
    
    
    while(i<size && l<=r)
        {
        
        j=l;
        while(j<=r)
            {
            arr[i++] = l^j;
            j++;
        }
        
        l++;
        
        
    }
    
    
    
    max=arr[0];
    for(k=0;k<size;k++)
        {
        
        if(arr[k]>max)
            max = arr[k];
    }
    
    return max;

}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}

