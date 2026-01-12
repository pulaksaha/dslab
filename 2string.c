#include <stdio.h>
#include <string.h>

int main(){
    char str[100],pat[50],rep[50],result[200];
    int i=0,j=0,k,found=0;

    printf("Enter main string\n");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';

    printf("Enter PATTERN string\n");
    fgets(pat,sizeof(pat),stdin);
    pat[strcspn(pat,"\n")]='\0';

    printf("Enter REPLACEMENT string\n");
    fgets(rep,sizeof(rep),stdin);
    rep[strcspn(rep,"\n")]='\0';

    while(str[i]!=0){
        k=0;
        while(str[i+k]==pat[k]&&pat[k]!='\0');{
            k++;
        }
        if(pat[k]=='\0'){
            found=1;
            for(int m=0;rep[m]!='\0';m++){
                result[j++]=rep[m];
            }
        }
        else{
             
             result[j++]=str[i++];
            
            } 

        }

       if (found)
        printf("\nResultant String: %s\n", result);
    else
        printf("\nPattern not found\n");

    return 0; 
    }
