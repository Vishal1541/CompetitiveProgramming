#include<stdio.h>
#include<math.h>
#define PI 3.14159265
#define R 50
int main(){
    int i,T,P,X,Y;
    int ans=-1; //for black ans=1, for white ans=0
    float progress_angle,user_angle,dist;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d%d%d",&P,&X,&Y);
        progress_angle = P*3.6;
        dist = sqrtf(powf((X-50),2)+powf((Y-50),2));
        user_angle = (180*atanf((X-50)/(Y-50)))/PI;
        /*
        if(user_angle>360)
            user_angle = (int)user_angle%360;
        */
        if((X<=50 && Y<=50) || (X>=50 && Y<=50) )
            user_angle+=180;
        else if(X<=50 && Y>=50)
            user_angle+=360;
        if(user_angle<=progress_angle && dist<=R)
            ans = 1;
        else
            ans = 0;
        if(ans==1)
            printf("Case #%d: black",i);
        else
            printf("Case #%d: white",i);
    }
    return 0;
}
