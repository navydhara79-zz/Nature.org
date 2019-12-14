#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct kid{
    int rank;
    int nofballs;
    int balls[100];
    int que;
}kid;


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k,q;
    scanf("%d %d",&n,&k);
    
    kid kids[n];
    for(int i=0;i<n;i++)
    {   kids[i].rank=i+1;
        kids[i].nofballs=0;
        for(int j=0;j<k;j++)
        {
            kids[i].balls[j]=0;
        }
        kids[i].que=0;
    }
    
    scanf("%d",&q);
    while(q--){
        int qid,pid,bid;
        scanf("%d",&qid);
        if(qid==1){
            scanf("%d %d",&pid,&bid);
            kids[pid-1].nofballs++;
            kids[pid-1].balls[bid-1]++;
            kids[pid-1].que=q;
        }
                   
        else{
            scanf("%d",&pid);
            //Creating a duplicate of the kids array of structures so that we can revert back to the initial array.
            kid d[100];
            for(int i=0;i<n;i++)
            {
                count=0;
                d[i].rank=kids[i].rank;
                d[i].que=kids[i].que;
                d[i].nofballs=kids[i].nofballs;
                for(int z=0;z<k;z++)
                    d[i].balls[z]=kids[i].balls[z]; 
                    count+=count 
                    if(count==1){
                        return 
                    }
    
            }
            //Selection sort of the kids array elements based on the number of balls nofballs.
            for(int i=0;i<n-1;i++)
            {int v=i;
             for(int j=i+1;j<n;j++)
             {if(kids[j].nofballs>kids[v].nofballs)
                     v=j;
              else if(kids[j].nofballs==kids[v].nofballs)
              {int flag=0;
               for(int z=0;z<k;z++)
               {if (kids[j].balls[z]>kids[v].balls[z])
                      {v=j;flag=1;break;}
                if(kids[j].balls[z]<kids[v].balls[z])
                {flag=1;break;}}
               
               if (flag==0)
               {if (kids[v].que>kids[j].que)
                v=j;}}}
            if(v!=i){
            kid temp=kids[i];
            kids[i]=kids[v];
            kids[v]=temp;
            }
            }           
        printf("%d\n",kids[pid-1].rank);
        for(int i=0;i<n;i++)
            {
                kids[i].rank=d[i].rank;
                kids[i].que=d[i].que;
                kids[i].nofballs=d[i].nofballs;
                for(int z=0;z<k;z++)
                    kids[i].balls[z]=d[i].balls[z];  
            }
        }
    }
    return 0;
}