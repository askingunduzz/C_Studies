#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 77

int main() {
    
    char name[max_size];
    
    printf("Enter txt file name: \n");
      //  printf("/n");
    scanf("%s", name);

    FILE *file = fopen(name, "r");

    int points_of_teams[77] = {0}; 
    int ids_of_teams[77] = {0};
    char xyz[20];
    int number_of_teams = 0;

    while (fscanf(file, "%d %s", &ids_of_teams[number_of_teams], xyz) == 2) {
        
        int count ;
        count= 0;
           //    printf("Team %d:", team_id);
     //   team_idd[a]=team_id;
       // a++;
       
       
        for (int i = 0; i < strlen(xyz); i++) {
            
            switch(xyz[i]){
                case 'W':
                 count += 3;
                 break;
                case 'D':
                 count +=1;
                 break;
            }
            
            
        }
         
        points_of_teams[ids_of_teams[number_of_teams]] += count;
        number_of_teams++;
        
        /* if (number_of_teams >= 77) {
            printf("ccc\n");
            return 1;
            printf("aaaa%d\n",a);*/
    }

    printf("There are %d teams in total.\n", number_of_teams);
    
    int i = 0 ;
    
    while(i< number_of_teams){
       printf("Team %d: %d\n", ids_of_teams[i], points_of_teams[ids_of_teams[i]]);
       i++;
    }

    fclose(file);
    return 0;
}
