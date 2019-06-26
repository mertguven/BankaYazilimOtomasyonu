#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
 int sayac;
 int Musteri1;
 int Musteri2;
 int Bakiye;
}islem7;

typedef struct
{

int Hesap_No;
int bakiye;

}Hesap_islem;

typedef struct
{

int Musteri_No;
char isim[10];
char soyisim[10];
Hesap_islem Ulasim2[5];

}Musteri_Bilgi;


int main()
{
FILE *Dekont;
FILE *TMusteri_Eklep;
FILE *BMusteri_Eklep;
FILE *raporp;
Musteri_Bilgi Ulasim1[2][1000];
int secim2,secim1,sayac1=-1,sayac2=-1;
int Tdizi[1000]={0},Bdizi[1000]={0};
int Gelir=0,Gider=0;
islem7 Ulasim7;
time_t t;

do{
printf("--------------------------ANA MENU--------------------------");
printf("\n\n\n");
printf("0-Cikis\n1-Musteri Ekle\n2-Hesap Actirma\n3-Para Cekme\n4-Para Yatirma\n5-Hesap Havale\n6-Banka Gelir-Gider raporu\n7-Hesap Ozeti\n8-Hesap Kapama\n");
printf("------------------------------------------------------------\n");
printf("Lutfen islem yapmak istediginiz secenegi giriniz:");
scanf("%d",&secim1);

if(secim1==1)
{
printf("Lutfen (Ticari musteri icin(1))  (Bireysel musteri icin(2)) basiniz:");
scanf("%d",&secim2);

if(secim2==1)
{
TMusteri_Eklep=fopen("Ticari.txt","ab+");

sayac1++;

printf("Lutfen isminizi giriniz:");
scanf("%s",Ulasim1[0][sayac1].isim);


printf("Lutfen soyisim giriniz:");
scanf("%s",Ulasim1[0][sayac1].soyisim);

printf("Lutfen Bakiyenizi giriniz:");
scanf("%d",&Ulasim1[0][sayac1].Ulasim2[0].bakiye);

srand(time(NULL));
Ulasim1[0][sayac1].Musteri_No=10000+rand()%100000;

srand(time(NULL));
Ulasim1[0][sayac1].Ulasim2[0].Hesap_No=1000+rand()%10000;

raporp=fopen("rapor.txt","ab+");

Ulasim7.sayac=1;
Ulasim7.Musteri1=Ulasim1[0][sayac1].Musteri_No;
Ulasim7.Bakiye=Ulasim1[0][sayac1].Ulasim2[0].bakiye;

fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);

fclose(raporp);

fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayac1])*sayac1,SEEK_SET);

fwrite(&Ulasim1[0][sayac1],sizeof(Ulasim1[0][sayac1]),1,TMusteri_Eklep);

fclose(TMusteri_Eklep);

printf("Musteri No:%d\n",Ulasim1[0][sayac1].Musteri_No);
printf("Hesap No:%d\n",Ulasim1[0][sayac1].Ulasim2[0].Hesap_No);



}
else
{
sayac2++;

BMusteri_Eklep=fopen("Bireysel.txt","ab+");

printf("Lutfen isminizi giriniz:");
scanf("%s",Ulasim1[1][sayac2].isim);

printf("Lutfen soyisim giriniz:");
scanf("%s",Ulasim1[1][sayac2].soyisim);

printf("Lutfen Bakiyenizi giriniz:");
scanf("%d",&Ulasim1[1][sayac2].Ulasim2[0].bakiye);

srand(time(NULL));
Ulasim1[1][sayac2].Musteri_No=10000+rand()%100000;

srand(time(NULL));
Ulasim1[1][sayac2].Ulasim2[0].Hesap_No=1000+rand()%10000;

raporp=fopen("rapor.txt","a+");

Ulasim7.sayac=1;

Ulasim7.Musteri1=Ulasim1[1][sayac2].Musteri_No;
Ulasim7.Bakiye=Ulasim1[1][sayac2].Ulasim2[0].bakiye;

fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);

fclose(raporp);

fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayac2])*sayac2,SEEK_SET);

fwrite(&Ulasim1[1][sayac2],sizeof(Ulasim1[1][sayac2]),1,BMusteri_Eklep);

printf("Musteri No'nuz:%d\n",Ulasim1[1][sayac2].Musteri_No);
printf("Hesap No:%d\n",Ulasim1[1][sayac2].Ulasim2[0].Hesap_No);

fclose(BMusteri_Eklep);

}
}
if(secim1==2)
{
 int Musteri_No,i,sayacB=0,sayacT=0;

 printf("Lutfen Musteri'No giriniz:");
 scanf("%d",&Musteri_No);

 for(i=0;sayac1>=i;i++) //MUSTERI NO ICIN DONGU OLUSTURDUK.
 {
  if(Musteri_No==Ulasim1[0][sayacT].Musteri_No)
  {
   int x,y;

   Tdizi[sayacT]++;
   x=Tdizi[sayacT];

   printf("Lutfen Bakiyenizi giriniz:");
   scanf("%d",&Ulasim1[0][sayacT].Ulasim2[x].bakiye);

   raporp=fopen("rapor.txt","ab+");

   Ulasim7.sayac=1;
   Ulasim7.Musteri1=Ulasim1[0][sayacT].Musteri_No;
   Ulasim7.Bakiye=Ulasim1[0][sayacT].Ulasim2[x].bakiye;

   fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);

   fclose(raporp);

   srand(time(NULL));
   Ulasim1[0][sayacT].Ulasim2[x].Hesap_No=1000+rand()%10000;

   TMusteri_Eklep=fopen("Ticari.txt","rb+");

   fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

   fwrite(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

   fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

   fread(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

   fclose(TMusteri_Eklep);

   printf("isim:%s\n",Ulasim1[0][sayacT].isim);
   printf("soyisim:%s\n",Ulasim1[0][sayacT].soyisim);
   printf("Musteri No:%d\n",Ulasim1[0][sayacT].Musteri_No);


  for(y=0;y<=x;y++)
  {
   printf("%d.Hesap No:%d\n",y+1,Ulasim1[0][sayacT].Ulasim2[y].Hesap_No);
   printf("%d.Bakiye:%d\n",y+1,Ulasim1[0][sayacT].Ulasim2[y].bakiye);

  }


   break;
  }
  sayacT++;
 }
 int y;

 for(y=0;y<=sayac2;y++) // MUSTERY SAYYSY KADAR ARAMA YAPAR
 {
  if(Musteri_No==Ulasim1[1][sayacB].Musteri_No) //TYCARY MUSTERYLERDE HESAP_No KAR?ILAYTIRMASI YAPAR
  {
   int x;

   Bdizi[sayacB]++; // DISARIDAN ATADIGIMIZ DYZY YCYN ARTIRMA Y?LEMY
   x=Bdizi[sayacB];

   printf("Lutfen Bakiyenizi giriniz:");
   scanf("%d",&Ulasim1[1][sayacB].Ulasim2[x].bakiye);

   raporp=fopen("rapor.txt","ab+");

   Ulasim7.sayac=1;
   Ulasim7.Musteri1=Ulasim1[1][sayacB].Musteri_No;
   Ulasim7.Bakiye=Ulasim1[1][sayacB].Ulasim2[x].bakiye;

   fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);

   fclose(raporp);

   srand(time(NULL));
   Ulasim1[1][sayacB].Ulasim2[x].Hesap_No=1000+rand()%10000;

   BMusteri_Eklep=fopen("Bireysel.txt","rb+");

   fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

   fwrite(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

   fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

   fread(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

   fclose(BMusteri_Eklep);

   printf("isim:%s\n",Ulasim1[1][sayacB].isim);
   printf("soyisim:%s\n",Ulasim1[1][sayacB].soyisim);
   printf("Musteri No:%d\n",Ulasim1[1][sayacB].Musteri_No);


  for(y=0;y<=x;y++)
  {
   printf("%d.Hesap No:%d\n",y+1,Ulasim1[1][sayacB].Ulasim2[y].Hesap_No);
   printf("%d.Bakiye:%d\n",y+1,Ulasim1[1][sayacB].Ulasim2[y].bakiye);

  }

   break;
  }
  sayacB++;  //UYGUN MU?TERY BULAMAZSA SAYAÇ ARTIRIR
 }
}

if(secim1==3)
{

int Musteri_No,Hesap_No,i;
int sayacT=0,sayacB=0;

printf("Lutfen Musteri'No nuzu giriniz:");
scanf("%d",&Musteri_No);


for(i=0;i<=sayac1;i++)
{


if(Musteri_No==Ulasim1[0][sayacT].Musteri_No)
{
int a;

printf("Lutfen Hesap_No giriniz:");
scanf("%d",&Hesap_No);

for(a=0;a<=Tdizi[sayac1];a++) //HESAP NO ARAMAK IÇÝN DÖNGÜ AÇTIK.
{

if(Hesap_No==Ulasim1[0][sayacT].Ulasim2[a].Hesap_No) //HESAP NO EÞLENÝRSE.
{
int Cekilen_Tutar;

do{

printf("Lutfen Cekeceginiz tuturi giriniz:");
scanf("%d",&Cekilen_Tutar);

}while(Cekilen_Tutar>1500);

raporp=fopen("rapor.txt","ab+");

Ulasim7.sayac=-1;
Ulasim7.Musteri1=Ulasim1[0][sayacT].Musteri_No;
Ulasim7.Bakiye=-Cekilen_Tutar;

fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
fclose(raporp);

if(Cekilen_Tutar>Ulasim1[0][sayacT].Ulasim2[a].bakiye) //HESAPTA PARA YOKSA.
{

int y,Kalan_Tutar;
int Hesap_No2;

Kalan_Tutar=Cekilen_Tutar-Ulasim1[0][sayacT].Ulasim2[a].bakiye; //KALAN PARAYI BULUYORUZ.


  printf("Bakiyeniz yeterli degildir Lutfen diger hesap no sunu giriniz:"); //BURADA MUSTERÝNÝN DÝGER HESABINDA YETECEK KADAR PARA OLDUGU VAR SAYIYORUZ.
  scanf("%d",&Hesap_No2);

  for(y=0;y<=Tdizi[sayacT];y++) //HESAP NO YU ARIYORUZ.
 {

    if(Hesap_No2==Ulasim1[0][sayacT].Ulasim2[y].Hesap_No) //HESAP NO EÞÝTSE.
    {
     Ulasim1[0][sayacT].Ulasim2[a].bakiye=0;
     Ulasim1[0][sayacT].Ulasim2[y].bakiye=Ulasim1[0][sayacT].Ulasim2[y].bakiye-Kalan_Tutar;

     printf("%d Hesap No'lu hasabinizdaki bakiye:%d---%d Hesap No'lu hesabinizdaki bakiye:%d\n",Ulasim1[0][sayacT].Ulasim2[a].Hesap_No,Ulasim1[0][sayacT].Ulasim2[a].bakiye,Ulasim1[0][sayacT].Ulasim2[y].Hesap_No,Ulasim1[0][sayacT].Ulasim2[y].bakiye);
     sayacT=0;

     TMusteri_Eklep=fopen("Ticari.txt","rb+");

     fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

     fwrite(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

     fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

     fread(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

     fclose(TMusteri_Eklep);

     break;
    }


 }

}
else
{
    Ulasim1[0][sayacT].Ulasim2[a].bakiye=Ulasim1[0][sayacT].Ulasim2[a].bakiye-Cekilen_Tutar;

     printf("%d Musteri No'lu hesabinizdaki bakiye:%d\n",Ulasim1[0][sayacT].Musteri_No,Ulasim1[0][sayacT].Ulasim2[a].bakiye);

     TMusteri_Eklep=fopen("Ticari.txt","rb+");

     fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

     fwrite(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

     fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

     fread(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

     fclose(TMusteri_Eklep);

}
}

}

}
sayacT++;
}

for(i=0;i<=sayac2;i++)
{
 if(Musteri_No==Ulasim1[1][sayacB].Musteri_No)
 {
  int a;
  printf("Lutfen Hesap_No giriniz:");
  scanf("%d",&Hesap_No);

  for(a=0;a<=Tdizi[sayac2];a++) //HESAP NO ARAMAK IÇÝN DÖNGÜ AÇTIK.                   !!!!!!!SIKINTILI!!!!!!!!!!!
  {
   if(Hesap_No==Ulasim1[1][sayacB].Ulasim2[a].Hesap_No) //HESAP NO EÞLENÝRSE.
   {
    int Cekilen_Tutar;
    do
    {
     printf("Lutfen Cekeceginiz tuturi giriniz:");
     scanf("%d",&Cekilen_Tutar);
    }while(Cekilen_Tutar>750);

     raporp=fopen("rapor.txt","ab+");

     Ulasim7.sayac=-1;
     Ulasim7.Musteri1=Ulasim1[1][sayacB].Musteri_No;
     Ulasim7.Bakiye=-Cekilen_Tutar;

     fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
     fclose(raporp);

    if(Cekilen_Tutar>Ulasim1[1][sayacB].Ulasim2[a].bakiye) //HESAPTA PARA YOKSA.
    {
     int y,Kalan_Tutar;
     int Hesap_No2;

     Kalan_Tutar=Cekilen_Tutar-Ulasim1[1][sayacB].Ulasim2[a].bakiye; //KALAN PARAYI BULUYORUZ.

     printf("Bakiyeniz yeterli degildir Lutfen diger hesap no sunu giriniz:"); //BURADA MUSTERÝNÝN DÝGER HESABINDA YETECEK KADAR PARA OLDUGU VAR SAYIYORUZ.
     scanf("%d",&Hesap_No2);

     for(y=0;y<=Bdizi[sayacB];y++) //HESAP NO YU ARIYORUZ.
     {
      if(Hesap_No2==Ulasim1[1][sayacB].Ulasim2[y].Hesap_No) //HESAP NO EÞÝTSE.
      {
       Ulasim1[1][sayacB].Ulasim2[a].bakiye=0;
       Ulasim1[1][sayacB].Ulasim2[y].bakiye=Ulasim1[1][sayacB].Ulasim2[y].bakiye-Kalan_Tutar;

       printf("%d Hesap No'lu hesabinizdaki bakiye:%d--%d Hesap No'lu hesabinizdaki bakiye:%d\n",Ulasim1[1][sayacB].Ulasim2[a].Hesap_No,Ulasim1[1][sayacB].Ulasim2[a].bakiye,Ulasim1[1][sayacB].Ulasim2[y].Hesap_No,Ulasim1[1][sayacB].Ulasim2[y].bakiye);

      BMusteri_Eklep=fopen("Bireysel.txt","rb+");

      fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

      fwrite(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

      fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

      fread(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

      fclose(BMusteri_Eklep);


       break;
      }
     }
    }
    else
    {
    Ulasim1[1][sayacB].Ulasim2[a].bakiye=Ulasim1[1][sayacB].Ulasim2[a].bakiye-Cekilen_Tutar;

    printf("%d Musteri No'lu hesabinizdaki bakiye:%d\n",Ulasim1[1][sayacB].Musteri_No,Ulasim1[1][sayacB].Ulasim2[a].bakiye);

    BMusteri_Eklep=fopen("Bireysel.txt","rb+");

    fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

    fwrite(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

    fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

    fread(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

    fclose(BMusteri_Eklep);

   }
  }
 }
 }
sayacB++;
}
}

if(secim1==4)
{

 int Musteri_No,i,sayacT=0,sayacB=0;

  printf("Lutfen Musteri No giriniz:");
  scanf("%d",&Musteri_No);

 for(i=0;i<=sayac1;i++)
 {
  if(Musteri_No==Ulasim1[0][sayacT].Musteri_No)
  {
   int Hesap_No,y;

   printf("Lutfen Hesap'No giriniz:");
   scanf("%d",&Hesap_No);

   for(y=0;y<=Tdizi[sayacT];y++)
   {
    if(Hesap_No==Ulasim1[0][sayacT].Ulasim2[y].Hesap_No)
    {
     int Yatirilicak_tutar;

      printf("Lutfen yatiracaginiz tutari giriniz:");
      scanf("%d",&Yatirilicak_tutar);

      Ulasim1[0][sayacT].Ulasim2[y].bakiye+=Yatirilicak_tutar;
      printf("%d Musteri No'lu hesabinizda suan:%d kadar par bulunmaktadir\n",Ulasim1[0][sayacT].Ulasim2[y].Hesap_No,Ulasim1[0][sayacT].Ulasim2[y].bakiye);

      TMusteri_Eklep=fopen("Ticari.txt","rb+");

      fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

      fwrite(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

      fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

      fread(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

      fclose(TMusteri_Eklep);

     raporp=fopen("rapor.txt","ab+");

     Ulasim7.sayac=1;
     Ulasim7.Musteri1=Ulasim1[0][sayacT].Musteri_No;
     Ulasim7.Bakiye=Yatirilicak_tutar;

     fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
     fclose(raporp);
     }
    }
   }
  sayacT++;
 }

 for(i=0;i<=sayac2;i++)
 {
   if(Musteri_No==Ulasim1[1][sayacB].Musteri_No);
   {
    int Hesap_No,y;

    printf("Lutfen Hesap'No giriniz:");
    scanf("%d",&Hesap_No);

    for(y=0;y<=Bdizi[sayacB];y++)
    {
     if(Hesap_No==Ulasim1[1][sayacB].Ulasim2[y].Hesap_No)
     {
      int Yatirilicak_tutar;

      printf("Lutfen yatiracaginiz tutari giriniz:");
      scanf("%d",&Yatirilicak_tutar);

      BMusteri_Eklep=fopen("Bireysel.txt","rb+");

      fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

      fwrite(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

      fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

      fread(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

      fclose(BMusteri_Eklep);

      raporp=fopen("rapor.txt","ab+");

      Ulasim7.sayac=1;
      Ulasim7.Musteri1=Ulasim1[1][sayacB].Musteri_No;
      Ulasim7.Bakiye=Yatirilicak_tutar;

      fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
      fclose(raporp);

      Ulasim1[1][sayacB].Ulasim2[y].bakiye+=Yatirilicak_tutar;
      printf("%d Musteri No'lu Hesabinizda suan %d kadar par bulunmaktadir.\n",Ulasim1[1][sayacB].Musteri_No,Ulasim1[1][sayacB].Ulasim2[y].bakiye);

     }
    }
   }
   sayacB++;
 }
}

if(secim1==5)
{

int Musteri_No,i,sayacT=0,sayacB=0;
int Musteri_Havale_No;

printf("Lutfen Musteri'No giriniz:");
scanf("%d",&Musteri_No);

 for(i=0;i<=sayac1;i++)
 {
    if(Musteri_No==Ulasim1[0][sayacT].Musteri_No) //MUSTERİ NO ESLESTİMEK
     {
      int z;

      printf("Lutfen Havale yapacaginiz musteri No giriniz:");
      scanf("%d",&Musteri_Havale_No);

         for(z=0;z<=sayac1;z++)
          {
            if(Musteri_Havale_No==Ulasim1[0][z].Musteri_No)
              {
                int Havale_tutar;

                printf("Lutfen Havale yapacaginiz tutari giriniz:");
                scanf("%d",&Havale_tutar);

                Ulasim1[0][sayacT].Ulasim2[0].bakiye-=Havale_tutar;
                Ulasim1[0][z].Ulasim2[0].bakiye+=Havale_tutar;

                raporp=fopen("rapor.txt","ab+");

                Ulasim7.sayac=0;
                Ulasim7.Musteri1=Ulasim1[0][sayacT].Musteri_No;
                Ulasim7.Musteri2=Ulasim1[0][z].Musteri_No;
                Ulasim7.Bakiye=-Havale_tutar;

                fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
                fclose(raporp);

                raporp=fopen("rapor.txt","ab+");

                Ulasim7.sayac=0;
                Ulasim7.Musteri1=Ulasim1[0][z].Musteri_No;
                Ulasim7.Musteri2=Ulasim1[0][sayacT].Musteri_No;
                Ulasim7.Bakiye=+Havale_tutar;

                fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
                fclose(raporp);

                TMusteri_Eklep=fopen("Ticari.txt","rb+");

                fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

                fwrite(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

                fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

                fread(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

                fclose(TMusteri_Eklep);

                TMusteri_Eklep=fopen("Ticari.txt","rb+");

                fseek(TMusteri_Eklep,sizeof(Ulasim1[0][z])*z,SEEK_SET);

                fwrite(&Ulasim1[0][z],sizeof(Ulasim1[0][z]),1,TMusteri_Eklep);

                fseek(TMusteri_Eklep,sizeof(Ulasim1[0][z])*z,SEEK_SET);

                fread(&Ulasim1[0][z],sizeof(Ulasim1[0][z]),1,TMusteri_Eklep);

                fclose(TMusteri_Eklep);

                printf("%d No'lu Musterini bakiyesi:%d---%d Musteri No'lu Musterinin bakiyesi:%d\n",Ulasim1[0][sayacT].Musteri_No,Ulasim1[0][sayacT].Ulasim2[0].bakiye,Ulasim1[0][z].Musteri_No,Ulasim1[0][z].Ulasim2[0].bakiye);

              }
          }
        for(z=0;z<=sayac2;z++)
         {
          if(Musteri_Havale_No==Ulasim1[1][z].Musteri_No)
           {
             int Havale_Tutar;

             printf("Lutfen Havale yapacaginiz tutari giriniz:");
             scanf("%d",&Havale_Tutar);

             Ulasim1[0][sayacT].Ulasim2[0].bakiye-=Havale_Tutar;
             Ulasim1[1][z].Ulasim2[0].bakiye+=Havale_Tutar;

             raporp=fopen("rapor.txt","ab+");

             Ulasim7.sayac=0;
             Ulasim7.Musteri1=Ulasim1[0][sayacT].Musteri_No;
             Ulasim7.Musteri2=Ulasim1[1][z].Musteri_No;
             Ulasim7.Bakiye=-Havale_Tutar;

             fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
             fclose(raporp);

             raporp=fopen("rapor.txt","a+");

             Ulasim7.sayac=0;
             Ulasim7.Musteri1=Ulasim1[1][z].Musteri_No;
             Ulasim7.Musteri2=Ulasim1[0][sayacT].Musteri_No;
             Ulasim7.Bakiye=+Havale_Tutar;

             fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
             fclose(raporp);

             TMusteri_Eklep=fopen("Ticari.txt","rb+");

             fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

             fwrite(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

             fseek(TMusteri_Eklep,sizeof(Ulasim1[0][sayacT])*sayacT,SEEK_SET);

             fread(&Ulasim1[0][sayacT],sizeof(Ulasim1[0][sayacT]),1,TMusteri_Eklep);

             fclose(TMusteri_Eklep);

             BMusteri_Eklep=fopen("Bireysel.txt","rb+");

             fseek(BMusteri_Eklep,sizeof(Ulasim1[1][z])*z,SEEK_SET);

             fwrite(&Ulasim1[1][z],sizeof(Ulasim1[1][z]),1,BMusteri_Eklep);

             fseek(BMusteri_Eklep,sizeof(Ulasim1[1][z])*z,SEEK_SET);

             fread(&Ulasim1[1][z],sizeof(Ulasim1[1][z]),1,BMusteri_Eklep);

             fclose(BMusteri_Eklep);

             printf("%d No'lu Musterini bakiyesi:%d---%d Musteri No'lu Musterinin bakiyesi:%d\n",Ulasim1[0][sayacT].Musteri_No,Ulasim1[0][sayacT].Ulasim2[0].bakiye,Ulasim1[1][z].Musteri_No,Ulasim1[1][z].Ulasim2[0].bakiye);
           }

         }
        }
  sayacT++;
 }
for(i=0;i<=sayac2;i++)
 {
    if(Musteri_No==Ulasim1[1][sayacB].Musteri_No) //MUSTERİ NO ESLESTİMEK
     {
      int z;

      printf("Lutfen Havale yapacaginiz musteri No giriniz:");
      scanf("%d",&Musteri_Havale_No);

         for(z=0;z<=sayac1;z++)
          {
            if(Musteri_Havale_No==Ulasim1[0][z].Musteri_No)
              {
                int Havale_Tutar,Havale_Kesinti;

                printf("Lutfen Havale yapacaginiz tutari giriniz:");
                scanf("%d",&Havale_Tutar);

                Ulasim1[1][sayacB].Ulasim2[0].bakiye-=Havale_Tutar;
                Havale_Kesinti=(Havale_Tutar-(Havale_Tutar/50));
                Ulasim1[0][z].Ulasim2[0].bakiye+=Havale_Kesinti;

                raporp=fopen("rapor.txt","ab+");

                Ulasim7.sayac=0;
                Ulasim7.Musteri1=Ulasim1[1][sayacB].Musteri_No;
                Ulasim7.Musteri2=Ulasim1[0][z].Musteri_No;
                Ulasim7.Bakiye=-Havale_Tutar;

                fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
                fclose(raporp);

                raporp=fopen("rapor.txt","ab+");

                Ulasim7.sayac=0;
                Ulasim7.Musteri1=Ulasim1[1][z].Musteri_No;
                Ulasim7.Musteri2=Ulasim1[1][sayacB].Musteri_No;
                Ulasim7.Bakiye=Havale_Kesinti;


                fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
                fclose(raporp);

                BMusteri_Eklep=fopen("Bireysel.txt","rb+");

                fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

                fwrite(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

                fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

                fread(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

                fclose(BMusteri_Eklep);

                TMusteri_Eklep=fopen("Ticari.txt","rb+");

                fseek(TMusteri_Eklep,sizeof(Ulasim1[0][z])*z,SEEK_SET);

                fwrite(&Ulasim1[0][z],sizeof(Ulasim1[0][z]),1,TMusteri_Eklep);

                fseek(TMusteri_Eklep,sizeof(Ulasim1[0][z])*z,SEEK_SET);

                fread(&Ulasim1[0][z],sizeof(Ulasim1[0][z]),1,TMusteri_Eklep);

                fclose(TMusteri_Eklep);

                printf("%d No'lu Musterini bakiyesi:%d---%d No'lu Musterinin bakiyesi:%d\n",Ulasim1[1][sayacB].Musteri_No,Ulasim1[1][sayacB].Ulasim2[0].bakiye,Ulasim1[0][z].Musteri_No,Ulasim1[0][z].Ulasim2[0].bakiye);

              }
          }
        for(z=0;z<=sayac2;z++)
         {
          if(Musteri_Havale_No==Ulasim1[1][z].Musteri_No)
           {
             int Havale_Tutar,Havale_Kesinti;

             printf("Lutfen Havale yapacaginiz tutari giriniz:");
             scanf("%d",&Havale_Tutar);

             Ulasim1[1][sayacB].Ulasim2[0].bakiye-=Havale_Tutar;
             Havale_Kesinti=(Havale_Tutar-(Havale_Tutar/50));
             Ulasim1[1][z].Ulasim2[0].bakiye+=Havale_Kesinti;

             raporp=fopen("rapor.txt","ab+");

             Ulasim7.sayac=0;
             Ulasim7.Musteri1=Ulasim1[1][sayacB].Musteri_No;
             Ulasim7.Musteri2=Ulasim1[1][z].Musteri_No;
             Ulasim7.Bakiye=-Havale_Tutar;

             fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
             fclose(raporp);

             raporp=fopen("rapor.txt","ab+");

             Ulasim7.sayac=0;
             Ulasim7.Musteri1=Ulasim1[1][z].Musteri_No;
             Ulasim7.Musteri2=Ulasim1[1][sayacB].Musteri_No;
             Ulasim7.Bakiye=Havale_Kesinti;


             fwrite(&Ulasim7,sizeof(Ulasim7),1,raporp);
             fclose(raporp);

             fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

             fwrite(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

             fseek(BMusteri_Eklep,sizeof(Ulasim1[1][sayacB])*sayacB,SEEK_SET);

             fread(&Ulasim1[1][sayacB],sizeof(Ulasim1[1][sayacB]),1,BMusteri_Eklep);

             fclose(BMusteri_Eklep);

             BMusteri_Eklep=fopen("Bireysel.txt","rb+");

             fseek(BMusteri_Eklep,sizeof(Ulasim1[1][z])*z,SEEK_SET);

             fwrite(&Ulasim1[1][z],sizeof(Ulasim1[1][z]),1,BMusteri_Eklep);

             fseek(BMusteri_Eklep,sizeof(Ulasim1[1][z])*z,SEEK_SET);

             fread(&Ulasim1[1][z],sizeof(Ulasim1[1][z]),1,BMusteri_Eklep);

             fclose(BMusteri_Eklep);

             printf("%d No'lu Musterini bakiyesi:%d---%d No'lu Musterinin bakiyesi:%d\n",Ulasim1[1][sayacB].Musteri_No,Ulasim1[1][sayacB].Ulasim2[0].bakiye,Ulasim1[1][z].Musteri_No,Ulasim1[1][z].Ulasim2[0].bakiye);
           }

         }
         sayacB++;
        }
 }
}

 if(secim1==6)
 {
  int i;

  raporp=fopen("rapor.txt","rb+");

  for(i=0;fgetc(raporp)!= EOF;i++)
  {
   fseek(raporp,sizeof(Ulasim7)*i,SEEK_SET);

   fread(&Ulasim7,sizeof(Ulasim7),1,raporp);

   if(Ulasim7.sayac == 1)
   {
      Gelir+=Ulasim7.Bakiye;
   }
   if(Ulasim7.sayac==-1)
   {
      Gider+=Ulasim7.Bakiye;
   }
  }
  fclose(raporp);

  printf("Gelir:%d----Gider:%d----Toplam para:%d\n",Gelir,Gider,(Gelir+Gider));

  Gelir=0;
  Gider=0;

}

 if(secim1==7)
 {
  time_t t;
  int i;
  t=time(NULL);
  int Musteri_No;

  printf("Lutfen Musteri No giriniz:");
  scanf("%d",&Musteri_No);

  remove("Dekont.txt");

  raporp=fopen("rapor.txt","rb+");

  for(i=0;fgetc(raporp)!=EOF;i++)
  {
   fseek(raporp,sizeof(Ulasim7)*i,SEEK_SET);

   fread(&Ulasim7,sizeof(Ulasim7),1,raporp);

   if(Ulasim7.Musteri1==Musteri_No)
    {
     Dekont=fopen("Dekont.txt","a+");

     if(Ulasim7.sayac==1)
     {
      fprintf(Dekont,"%s%d Musteri No'lu Hesaba %d kadar para yuklenmistir.\n",ctime(&t),Ulasim7.Musteri1,Ulasim7.Bakiye);
      fclose(Dekont);
     }
     if(Ulasim7.sayac==-1)
     {
       fprintf(Dekont,"%s%d Musteri No'lu Hesaptan %d kadar para cekilmistir.\n",ctime(&t),Ulasim7.Musteri1,Ulasim7.Bakiye);
       fclose(Dekont);
     }
     if(Ulasim7.sayac==0)
     {
       fprintf(Dekont,"%s%d No'lu Musteriden %d No'lu Musteriye %d kadar para havala islemi gerceklesmistir.\n",ctime(&t),Ulasim7.Musteri1,Ulasim7.Musteri2,Ulasim7.Bakiye);
       fclose(Dekont);
     }
    }


  }
 fclose(raporp);

}

if(secim1==8)
{

int Musteri_No,i,cikis=0,cikis2=0;

printf("Lutfen Musteri No giriniz:");
scanf("%d",&Musteri_No);

 for(i=0;i<=sayac1;i++)
 {
   if(Musteri_No==Ulasim1[0][i].Musteri_No)
   {

    int x,y;

    for(y=0;y<=Tdizi[i];y++)
    {
     if(Ulasim1[0][i].Ulasim2[y].bakiye != 0)
     {
        cikis=1;
        printf("%d Hesap No'lu bakiyenizde suan %d kadar para bulunmaktadir lutfen hesabi kapatmak icin once hesabinizdaki parayi cekin.\n",Ulasim1[0][i].Ulasim2[y].Hesap_No,Ulasim1[0][i].Ulasim2[y].bakiye);
        break;
     }

    }
     if(cikis==1)
     {
      break;
     }

     Ulasim1[0][i].Musteri_No=0;
     strcpy(Ulasim1[0][i].isim,"        ");
     strcpy(Ulasim1[0][i].soyisim,"        ");

     for(x=0;x<5;x++)
     {
      Ulasim1[0][i].Ulasim2[x].Hesap_No=0;
      Ulasim1[0][i].Ulasim2[x].bakiye=0;
     }

      TMusteri_Eklep=fopen("Ticari.txt","rb+");

      fseek(TMusteri_Eklep,sizeof(Ulasim1[0][i])*i,SEEK_SET);

      fwrite(&Ulasim1[0][i],sizeof(Ulasim1[0][i]),1,TMusteri_Eklep);

      fclose(TMusteri_Eklep);
   }
 }

 for(i=0;i<=sayac2;i++)
 {
   if(Musteri_No==Ulasim1[1][i].Musteri_No)
   {
     printf("ife girdi\n");

     int x,y;

    for(y=0;y<=Tdizi[i];y++)
    {
     if(Ulasim1[1][i].Ulasim2[y].bakiye != 0)
     {
        cikis2=1;
        printf("%d Hesap No'lu bakiyenizde suan %d kadar para bulunmaktadir lutfen hesabi kapatmak icin once hesabinizdaki parayi cekin.\n",Ulasim1[1][i].Ulasim2[y].Hesap_No,Ulasim1[1][i].Ulasim2[y].bakiye);
        break;
     }

    }
     if(cikis2==1)
     {
      break;
     }

     Ulasim1[1][i].Musteri_No=0;
     strcpy(Ulasim1[1][i].isim,"        ");
     strcpy(Ulasim1[1][i].soyisim,"        ");

     for(x=0;x<5;x++)
     {
      Ulasim1[1][i].Ulasim2[x].Hesap_No=0;
      Ulasim1[1][i].Ulasim2[x].bakiye=0;
     }

      BMusteri_Eklep=fopen("Bireysel.txt","rb+");

      fseek(BMusteri_Eklep,sizeof(Ulasim1[1][i])*i,SEEK_SET);

      fwrite(&Ulasim1[0][i],sizeof(Ulasim1[1][i]),1,BMusteri_Eklep);

      fclose(BMusteri_Eklep);
   }
 }

}

}while(secim1!=0);

    return 0;
}
