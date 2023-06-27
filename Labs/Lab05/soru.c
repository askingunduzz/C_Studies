#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int id; // researcher id
    char name[20]; // researcher name
	char surname[20]; // researcher surname
    char department[20]; // department of researcher
    int citIndex; // citation index of the researcher
} researcher;

void showRecords(FILE *filePtr);

int modifyCitIndex(FILE *filePtr, unsigned int id, int increaseCit);
int insertResearcher(FILE *filePtr, unsigned int id, char name[], char surname[], char department[], int citIndex);
int removeResearcher(FILE *filePtr, unsigned int id);
int viewDepartmentCits(FILE *filePtr, char department[], int maxCit);

int main()
{
    unsigned int id;
    int increaseCit;
    int status;

    char name[20];
    char surname[20];
	char department[20];
    int citIndex;

    int count;
	int maxCitation;

    FILE *filePtr;
    filePtr = fopen("researcher.bin","rb+");
    if (filePtr == NULL)
    {
        printf("Could not open researcher.bin");
        return;
    }

    showRecords(filePtr);

    int choice;

    printf("\nWhich operation do you choose?\n");
    printf("1 : Update Citation Index\n");
    printf("2 : Add Researcher\n");
    printf("3 : Delete researcher\n");
    printf("4 : View Department Info with Citation\n");
    printf("> ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("\nResearcher id: ");
        scanf("%d",&id);
        printf("Increase value for citation index: ");
        scanf("%d",&increaseCit);
        status = modifyCitIndex(filePtr, id, increaseCit);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No researcher with id %d\n", id);
        break;
    case 2:
        printf("\nResearcher id: ");
        scanf("%d",&id);
        printf("Name: ");
        scanf("%s",name);
		printf("Surname: ");
        scanf("%s",surname);
        printf("Department: ");
        scanf("%s",department);
        printf("Citation Index: ");
        scanf("%d",&citIndex);
        status = insertResearcher(filePtr, id, name, surname, department, citIndex);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("There is already an researcher with id %d\n", id);
        break;
    case 3:
        printf("\nResearcher id: ");
        scanf("%d",&id);
        status = removeResearcher(filePtr, id);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No researcher with id %d\n", id);
        break;
    case 4:
        printf("\nDepartment: ");
        scanf("%s",department);
		printf("\nMax Citation Index: ");
        scanf("%d",&maxCitation);
        count = viewDepartmentCits(filePtr, department, maxCitation);
        if (count == 0)
            printf("No researcher in department %s with citation index <= %d\n", department, maxCitation);
        else
            printf("There are %d researchers in department %s with citation index <= %d\n", count, department, maxCitation);
        break;
    }

    fclose(filePtr);
    return 0;
}

void showRecords(FILE *filePtr)
{
    fseek(filePtr, 0, SEEK_SET);

    printf("\n%-3s %-20s %-20s %-20s %s\n",
           "ID",
           "Name",
           "Surname",
           "Department",
           "Citation Index");

    while (!feof(filePtr))
    {
        researcher r;
        int result = fread(&r, sizeof(researcher), 1, filePtr);
        if (result != 0 && r.id != 0)
        {
            printf("%-3d %-20s %-20s %-20s %d\n",
                   r.id,
                   r.name,
                   r.surname,
                   r.department,
                   r.citIndex);
        }
    }
}


int insertResearcher(FILE *filePtr, unsigned int id, char name[], char surname[], char department[], int citIndex)
{
    fseek(filePtr, 0, SEEK_SET);
 
    researcher rs[333];
    int number_of_rs;
    number_of_rs = 0;

   for (; fread(&rs[number_of_rs], sizeof(researcher), 1, filePtr) == 1; number_of_rs++)
         {
    if (rs[number_of_rs].id == id)
         {
         return 0;
           }
   }

    
    researcher newrs;
    newrs.id = id;
    strcpy(newrs.name, name);
    strcpy(newrs.surname, surname);
    strcpy(newrs.department, department);
    newrs.citIndex = citIndex;
    
    rs[number_of_rs] = newrs;
    number_of_rs++;

  int i;
  i= 0;
while (i < number_of_rs - 1)
{  int j;
    j= 0;
    while (j < number_of_rs - i - 1)
    {
        if (rs[j].id > rs[j + 1].id)
        {
            researcher t = rs[j];
            rs[j] = rs[j + 1];
            rs[j + 1] = t;
        }
        j++; }
    i++; }

    fseek(filePtr, 0, SEEK_SET);
    fwrite(rs, sizeof(researcher), number_of_rs, filePtr);

 for (int x = 0; x < number_of_rs; x++)
{
    if (rs[x].citIndex == 0) {
        continue; 
    }

  
}
    return 1;
}



int removeResearcher(FILE *filePtr, unsigned int id)
{
   fseek(filePtr, 0, SEEK_SET);

   for (; !feof(filePtr); )
{
    researcher aras;
    int sonuc;
    sonuc = fread(&aras, sizeof(researcher), 1, filePtr);

    if (sonuc != 0 && aras.id == id)
    {
        fseek(filePtr, -sizeof(researcher), SEEK_CUR);
        researcher wr = {0, "", "", "", 0};
        fwrite(&wr, sizeof(researcher), 1, filePtr);
        return 1;
    }
}


    return 0;
}



int modifyCitIndex(FILE *filePtr, unsigned int id, int increaseCit)
{
    fseek(filePtr, 0, SEEK_SET);

   for (; !feof(filePtr); )
{
    researcher aras;
    int result;
    result = fread(&aras, sizeof(researcher), 1, filePtr);

    if (result != 0 && aras.id == id)
    {
        aras.citIndex= aras.citIndex + increaseCit;
        fseek(filePtr, -sizeof(researcher), SEEK_CUR);
        fwrite(&aras, sizeof(researcher), 1, filePtr);
        return 1;
    }
}


    return 0;
}



int viewDepartmentCits(FILE *filePtr, char department[], int maxCit)
{
   fseek(filePtr, 0, SEEK_SET);
    int sayac;
    sayac= 0;

    printf("\n%-3s %-20s %-20s %-20s %s\n",
           "ID",
           "Name",
           "Surname",
           "Department",
           "Citation Index");
           
for (; !feof(filePtr); )
{
    researcher aras;
    int result = fread(&aras, sizeof(researcher), 1, filePtr);
    
    if (result != 0 && aras.id != 0 && strcmp(aras.department, department) == 0 && aras.citIndex <= maxCit)
    {
        printf("%-3d %-20s %-20s %-20s %d\n",
               aras.id,
               aras.name,
               aras.surname,
               aras.department,
               aras.citIndex);
        sayac++;
    }
}


    return sayac;
}