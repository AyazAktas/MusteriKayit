#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#define BOY 100

char ad[BOY][25];
char soyad[BOY][25];
char tel[BOY][25];
char adres[BOY][25];

int cnt=0;

int menu();
void kayit();
void kisiAra();
void listele();
void dosyayakaydet();
void dosyadanoku();
void girisAl(char *);

int main()
{
    setlocale(LC_ALL,"Turkish");

    int secim=menu();
    while(secim!=0)
    {
        switch (secim)
        {
        case 1: kayit();

            break;
        case 2: kisiAra();

            break;
        case 3: listele();

            break;

        case 4: dosyayakaydet();

            break;
        case 5: dosyadanoku();

            break;


        default:
            break;
        }
        secim=menu();
    }
    return 0;
}
int menu()
{
    int secim;
    printf("\nMüsteri kayit uygulamasi\n\n");
    printf("1 -Yeni Kayit\n");
    printf("2 -Kayit Ara\n");
    printf("3 -Kayitlari Listele\n");
    printf("4 -Kayıtları Dosyaya kaydet\n");
    printf("5 -Dosyadaki kayıtları  listeye yükle\n");
    printf("0 -Çıkış\n");


    do
    {
        printf("Yapmak istediğiniz işlemi tuşlayınız[0-5]:");
        secim=getche()-'0';
        printf("\n");

    } while (secim<0 || secim>5);
    return secim;

}


void kayit()
{

    system("cls");

    printf("Kayit ekrani aciliyor..\n");
    sleep(2);


    printf("***KAYIT EKRANI***\n");
    printf("Isim :");
    girisAl(ad[cnt]);
    printf("Soyisim:");
    girisAl(soyad[cnt]);
    printf("Telefon Numarasi:");
    girisAl(tel[cnt]);
    printf("Adres:");
    girisAl(adres[cnt]);
    cnt++;
    printf("Kayıt tamamlandı...\n");



}
void kisiAra()
{

    system("cls");
    char aranan[20];
    printf("Aradiginiz kisinin adi:");
    girisAl(aranan);
    int i=0;
    int sayac=0;
    while (i<cnt)
    {
        if(strcmp(aranan,ad[i])==0)
        {
            if(sayac==i)
            printf("%-20s%-20s%-20s%-20s\n","ISIM","SOYISIM","ADRES","TELEFON NUMARASI");

            printf("%-20s%-20s%-20s%-20s\n",ad[i],soyad[i],adres[i],tel[i]);

            sayac++;
        }
        i++;
    }
    if(sayac==0)
    {
        system("cls");
        printf("\n%s isimli kişi kayıt listesinde bulunamadi...",aranan);
    }

    else
    {
        printf("\n%s isimli kisiden %d adet var",aranan,sayac);
    }


}
void listele()
{
    system("cls");
    int i=0;
    int sayac=0;
    while (i < cnt)
    {

        if(sayac==i)
        {
            printf("%-20s%-20s%-20s%-20s\n","ISIM","SOYISIM","ADRES","TELEFON");

            printf("%-20s%-20s%-20s%-20s\n",ad[i],soyad[i],adres[i],tel[i]);;

            sayac++;

        }
    i++;
    }
    if(sayac==0)
    {
        printf("\n  kişi kayıt listesinde  bulunamadı... \n");
    }
    else
    {
        printf("\n %d kişi kaydı var",sayac);
    }



}
void dosyayakaydet()
{
    system("cls");
    FILE *ptr;
    if((ptr=fopen("musteriler.txt","w"))==NULL)
    {
        printf("Dosya oluþturulamadı...");
        exit(1);
    }
    int i=0;
    while(i<cnt)
    {
        fprintf(ptr,"%-20s%-20s%-20s%-20s\n",ad[i],soyad[i],tel[i],adres[i]);


        i++;
    }
    fclose(ptr);
    if(i==0)
        printf("\nKayıt olmadığı için dosyaya kaydedilemedi..\n");
    else
        printf("\n%d kişi kaydı dosyada oluşturuldu.\n",i);

}
void dosyadanoku()
{

    system("cls");
    FILE *ptr;
    if((ptr=fopen("musteriler.txt","r"))==NULL)
    {
        printf("Dosya bulunamadı...");
        exit(1);
    }
    int i=0;
    cnt=0;
    while(!feof(ptr))
    {
        fscanf(ptr,"%s%s%s%s",ad[cnt],soyad[cnt],tel[cnt],adres[cnt]);
        cnt++;
    }
    fclose(ptr);
    if(cnt==0)
        printf("\nDosyada kayıt olmadığı için dosya okuma işlemi başarısız..\n");
    else
        printf("\n%d kişi listeye aktarıldı.\n",i);






}
void girisAl(char *ptr )
{
    fgets(ptr,20,stdin);
    int n=strlen(ptr);
    ptr[n-1]='\0';
}
