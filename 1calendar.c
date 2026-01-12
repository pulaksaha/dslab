#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Day{
    char  *dayname;
    int date;
    char *activity;
};
typedef struct Day *day;

day create(){
    day d =(day)malloc(sizeof(struct Day));
    d->dayname=(char*)malloc(sizeof(char)*20);
    d->activity=(char*)malloc(sizeof(char)*50);
    return d;
}

void read(day cal[7]){
   
    for (int i = 0; i < 7; i++) {
     printf("\nEnter details for Day %d\n", i + 1);

        printf("Day Name:");
        scanf("%s", cal[i]->dayname);

        printf("Date: ");
        scanf("%d", &cal[i]->date);

        printf("Activity: ");
        scanf("%s", cal[i]->activity);
    }
    
}

void display(day cal[7]){
     printf("\n\n WEEK ACTIVITY DETAILS\n");
    printf("----------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("Day Name : %s\n", cal[i]->dayname);
        printf("Date     : %d\n", cal[i]->date);
        printf("Activity : %s\n\n", cal[i]->activity);
    }

}

int main(){
    day calendar[7];

    for(int i=0;i<7;i++){
        calendar[i]=create();
    }
    read (calendar);
    display (calendar);

    return 0;
}

