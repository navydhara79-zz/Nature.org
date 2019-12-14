#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct racer{
    int rank;
    int count_of_balls;
    int balls[100];
    int dque;
}racer;


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    int q;
    scanf("%d %d",&n,&k);
    
    racer racers[n];
    for(int c=0;c<n;c++)
    {   racers[c]->rank=c+1;
        racers[c]->count_of_balls=0;
        for(int d=0;d<k;d++)
        {
            racers[c]->balls[d]=0;
        }
        racers[c]->dque=0;
    }
    
    scanf("%d",&q);
    while(q--){
        int id_q,pers,ball_iden;
        scanf("%d",&id_q);
        switch (id_q)
        {
        case 1:
            scanf("%d %d",&pers,&ball_iden);
            racers[pers-1].count_of_balls++;
            racers[pers-1].balls[ball_iden-1]++;
            racers[pers-1].dque=q;
            
            break;
        
        default:
                scanf("%d",&pers);
                    //Creating a duplicate of the racers array of structures so that we can revert back to the initial array.
                    racer d[100];
                    for(int i=0;i<n;i++)
                    {
                        d[i].rank=racers[i].rank;
                        d[i].dque=racers[i].dque;
                        d[i].count_of_balls=racers[i].count_of_balls;
                        for(int z=0;z<k;z++)
                            d[i].balls[z]=racers[i].balls[z];  
                    }
                    //Selection sort of the racers array elements based on the number of balls count_of_balls.
                    for(int i=0;i<n-1;i++)
                    {
                        int v=i;
                        for(int j=i+1;j<n;j++)
                    {if(racers[j].count_of_balls>racers[v].count_of_balls)
                            v=j;
                    else if(racers[j].count_of_balls==racers[v].count_of_balls)
                    {int flag=0;
                    for(int z=0;z<k;z++)
                    {if (racers[j].balls[z]>racers[v].balls[z])
                            {v=j;flag=1;break;}
                        if(racers[j].balls[z]<racers[v].balls[z])
                        {flag=1;break;}}
                    
                    if (flag==0)
                    {if (racers[v].dque>racers[j].dque)
                        v=j;}}}
                    if(v!=i){
                    racer temp=racers[i];
                    racers[i]=racers[v];
                    racers[v]=temp;
                    }
                    }           
                printf("%d\n",racers[pers-1].rank);
                for(int i=0;i<n;i++)
                    {
                        racers[i].rank=d[i].rank;
                        racers[i].dque=d[i].dque;
                        racers[i].count_of_balls=d[i].count_of_balls;
                        for(int z=0;z<k;z++)
                            racers[i].balls[z]=d[i].balls[z];  
                    }
                }
            }
            return 0;
        }
            break;
        }
//         if(id_q==1){
//             scanf("%d %d",&pers,&ball_iden);
//             racers[pers-1].count_of_balls++;
//             racers[pers-1].balls[ball_iden-1]++;
//             racers[pers-1].dque=q;
//         }
                   
//         else{
//             scanf("%d",&pers);
//             //Creating a duplicate of the racers array of structures so that we can revert back to the initial array.
//             racer d[100];
//             for(int i=0;i<n;i++)
//             {
//                 d[i].rank=racers[i].rank;
//                 d[i].dque=racers[i].dque;
//                 d[i].count_of_balls=racers[i].count_of_balls;
//                 for(int z=0;z<k;z++)
//                     d[i].balls[z]=racers[i].balls[z];  
//             }
//             //Selection sort of the racers array elements based on the number of balls count_of_balls.
//             for(int i=0;i<n-1;i++)
//             {int v=i;
//              for(int j=i+1;j<n;j++)
//              {if(racers[j].count_of_balls>racers[v].count_of_balls)
//                      v=j;
//               else if(racers[j].count_of_balls==racers[v].count_of_balls)
//               {int flag=0;
//                for(int z=0;z<k;z++)
//                {if (racers[j].balls[z]>racers[v].balls[z])
//                       {v=j;flag=1;break;}
//                 if(racers[j].balls[z]<racers[v].balls[z])
//                 {flag=1;break;}}
               
//                if (flag==0)
//                {if (racers[v].dque>racers[j].dque)
//                 v=j;}}}
//             if(v!=i){
//             racer temp=racers[i];
//             racers[i]=racers[v];
//             racers[v]=temp;
//             }
//             }           
//         printf("%d\n",racers[pers-1].rank);
//         for(int i=0;i<n;i++)
//             {
//                 racers[i].rank=d[i].rank;
//                 racers[i].dque=d[i].dque;
//                 racers[i].count_of_balls=d[i].count_of_balls;
//                 for(int z=0;z<k;z++)
//                     racers[i].balls[z]=d[i].balls[z];  
//             }
//         }
//     }
//     return 0;
// }
