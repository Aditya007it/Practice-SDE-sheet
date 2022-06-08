
// Accepted on codestudio..
// on 8 june 2022 (12.38 PM)

int findMinimumCoins(int amount) 
{   
    int arr[] = {1,2,5,10,20,50,100,500,1000};
    int mincoins=0;
    for(int i=8;i>=0;i--){
       if(amount/arr[i]>=1){
           mincoins+=amount/arr[i];
           amount=amount%arr[i];
       }
        if(amount==0) break;
    }
    return mincoins;
}