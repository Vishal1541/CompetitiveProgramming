#include <stdio.h>
#include <string.h>

int A,B,res;

int main(){
	scanf("%d%d",&A,&B);
	res = A-B;
	int arr[4];
	int digit_arr[4];
	int multiplier = 10;
	int i=0;
	while(1){
			arr[i] = res % multiplier;
			if(res == arr[i])
				break;
			i++;
			multiplier *= 10;
	}

	int j;
	digit_arr[0] = arr[0];
	if(digit_arr[0] == 9)
		digit_arr[0]--;
	else
		digit_arr[0]++;
	
	for(j=1; j<=i; j++){
		digit_arr[j] = arr[j] - arr[j-1];
	}
	int final_res = 0;
	for (j=0; j<=i; j++)
		final_res += digit_arr[j];

	printf("%d\n",final_res );

	return 0;
}