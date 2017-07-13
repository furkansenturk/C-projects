#include <stdio.h>
#include <time.h>
int main(){
    time_t simdi;
    time(&simdi);
    struct tm d;
    struct tm *suan;
    suan = localtime(&simdi);
    int dgun,day,dyil,dsaat,ddakika,dsaniye,diff;
    dyil = 2000;
    day = dgun = 01;
    dsaat = ddakika = dsaniye = 00;
    printf("Doğum Tarihinizi Girin (Örnek : 30/12/1990 23:59:59)\n");
    scanf("%d/%d/%d %d:%d:%d", &dgun,&day,&dyil,&dsaat,&ddakika,&dsaniye);
    d.tm_year = dyil - 1900;
    d.tm_mon = day-1;
    d.tm_mday = dgun;
    d.tm_hour = dsaat;
    d.tm_min = ddakika;
    d.tm_sec = dsaniye;
    d.tm_isdst = -1;
    if( mktime(&d) != -1){
        diff = (int) difftime(simdi ,mktime(&d));
        printf("\n#########################\n\n");
        printf("Doğum Tarihin: %d/%d/%d %d:%d:%d", dgun, day, dyil,dsaat,ddakika,dsaniye);
        printf("\nŞuanki zaman: %d/%d/%d %d:%d:%d",suan->tm_mday,suan->tm_mon + 1,suan->tm_year + 1900,suan->tm_hour,suan->tm_min,suan->tm_sec);
        printf("\n\n#########################\n\n");
        printf("Şuan %d Yaşındasın",diff/(60*60*24*365) );
        printf("\n\n####################\n\n");
        printf("%d Gün önce doğdun\n",diff/(60*60*24));
        printf("%d Saat önce doğdun\n",diff/(60*60));
        printf("%d Dakika önce doğdun\n",diff/(60));
        printf("%d Saniye önce doğdun\n\n",diff);
    }
}
