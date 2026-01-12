#include <stdio.h>
#include<math.h>

void tower(int n, char source,char auxiliary,char destination){
    if(n==1){
        printf("Move disk1 from %c to %c",source,destination);
      return;   
    }
    tower(n-1,source,destination,auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower(n-1,auxiliary,source,destination);
    
}

int main(){
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\nSteps to solve Tower of Hanoi:\n");
    tower(n, 'A', 'B', 'C');

    printf("\nTotal number of moves = %d\n", (int)pow(2, n) - 1);

    return 0;

}