#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_AD_UZUNLUK 66
#define MAX_MAIL_UZUNLUK 132
#define MAX_KAYITLAR 500

typedef struct {
    float toplamdrtn;
    int proc;
    char soyad[MAX_AD_UZUNLUK];
    char ilkad[MAX_AD_UZUNLUK];
} Zoom_attendant;

typedef struct {
    char ad[MAX_AD_UZUNLUK];
    char mail[MAX_MAIL_UZUNLUK];
    char joining[22];
    char leaving[22];
    float drtn;
} Zoom_attendantKayitlar;


int karsilastir_(const char* ad1, const char* ad2) {
    char soyad1[MAX_AD_UZUNLUK];
    char soyad2[MAX_AD_UZUNLUK];
    int i1,i2;
    i1 = strlen(ad1) - 1;
    i2 = strlen(ad2) - 1;

   while (i1 >= 0 && !isspace(ad1[i1])) {
    i1--; } i1++;
   while (i2 >= 0 && !isspace(ad2[i2])) {
    i2--; } i2++;

    strncpy(soyad1, &ad1[i1], MAX_AD_UZUNLUK);
    strncpy(soyad2, &ad2[i2], MAX_AD_UZUNLUK);

    return strcasecmp(soyad1, soyad2);
}


int karsilastir_2(const char* ad1, const char* ad2) {
    return strcasecmp(ad1, ad2);
}


void sortZoom_attendants(Zoom_attendant* Zoom_attendants, int num_of_Zoom_attendants) {
    int aa;
    aa= 0;
    while (aa < num_of_Zoom_attendants - 1) {
    int bb;
    bb= 0;
    while (bb < num_of_Zoom_attendants - aa - 1) {
        int soyadKars,ilkadKArs;
        soyadKars = karsilastir_(Zoom_attendants[bb].soyad, Zoom_attendants[bb + 1].soyad);
        ilkadKArs = karsilastir_2(Zoom_attendants[bb].ilkad, Zoom_attendants[bb + 1].ilkad);
        if (soyadKars > 0 || (soyadKars == 0 && ilkadKArs > 0)) {
            Zoom_attendant temp = Zoom_attendants[bb];
            Zoom_attendants[bb] = Zoom_attendants[bb + 1];
            Zoom_attendants[bb + 1] = temp;}
        bb++;
    }
    aa++;
  }
}


int main() {
    char file_ismi[222];
    printf("Enter the input file name: ");
    scanf("%s", file_ismi);

    FILE* dosya_ = fopen(file_ismi, "r");
    if (dosya_ == NULL) {
        printf("Unable to open the dosya_.\n");
        return 1;
    }

    char header[222];
    fgets(header, sizeof(header), dosya_);

    Zoom_attendantKayitlar Kayitlar[MAX_KAYITLAR];
    int number_of_kayitlar;
    number_of_kayitlar = 0;


   for (; fgets(header, sizeof(header), dosya_);) {
    char joining[20], leaving[20], drtnStr[10], ad[MAX_AD_UZUNLUK], mail[MAX_MAIL_UZUNLUK];
    sscanf(header, "%[^,],%[^,],%[^,],%[^,],%s", joining, leaving, drtnStr, ad, mail);

    strcpy(Kayitlar[number_of_kayitlar].joining, joining);
    strcpy(Kayitlar[number_of_kayitlar].leaving, leaving);
    Kayitlar[number_of_kayitlar].drtn = atof(drtnStr);
    strcpy(Kayitlar[number_of_kayitlar].ad, ad);
    strcpy(Kayitlar[number_of_kayitlar].mail, mail);

    number_of_kayitlar++;
  }
    fclose(dosya_);

    Zoom_attendant Zoom_attendants[MAX_KAYITLAR];
    int number_of_Zoom_attendants;
    number_of_Zoom_attendants= 0;

    for (int i = 0; i < number_of_kayitlar; i++) {
        char ilkad[MAX_AD_UZUNLUK];
        char soyad[MAX_AD_UZUNLUK];
        int indeks; 
        indeks= strlen(Kayitlar[i].ad) - 1;

        while (indeks >= 0 && !isspace(Kayitlar[i].ad[indeks])) {
    indeks--;
      } indeks++;

        strncpy(ilkad, Kayitlar[i].ad, indeks);
        ilkad[indeks] = '\0';
        strcpy(soyad, &Kayitlar[i].ad[indeks]);

int Zoom_attendant_index= 0;
int jj;
jj= 0;

while (jj < number_of_Zoom_attendants) {
    
    if (karsilastir_(Zoom_attendants[jj].soyad, soyad) == 0 && karsilastir_2(Zoom_attendants[jj].ilkad, ilkad) == 0) {
        Zoom_attendants[jj].toplamdrtn += Kayitlar[i].drtn;
        Zoom_attendants[jj].proc = 1;
        Zoom_attendant_index = 1;
        break;
    }  jj++;
}

if (Zoom_attendant_index == 0) {
    strcpy(Zoom_attendants[number_of_Zoom_attendants].ilkad, ilkad);
    strcpy(Zoom_attendants[number_of_Zoom_attendants].soyad, soyad);
    Zoom_attendants[number_of_Zoom_attendants].toplamdrtn = Kayitlar[i].drtn;
    Zoom_attendants[number_of_Zoom_attendants].proc = 0;
    number_of_Zoom_attendants++; } 
  }

    char sort_types[4];
    printf("\nSort the results? (yes/no): ");
    scanf("%s", sort_types);

    if (strcmp(sort_types, "yes") == 0) {
        sortZoom_attendants(Zoom_attendants, number_of_Zoom_attendants);  }

   int y = 0;
   while (y < number_of_Zoom_attendants) {
    printf("%s %s %.2f\n", Zoom_attendants[y].soyad, Zoom_attendants[y].ilkad, Zoom_attendants[y].toplamdrtn);
    y++; }


    return 0;
}