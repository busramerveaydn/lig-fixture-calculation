#include <stdio.h>
#include <stdlib.h>
int takimlarokuma();
int oynananmaclar();
int tablo();
int yenitakim();
int puanlandirma();
int takimsayisi();

char takmaisim[41];
char takim[13][13];
int takimMacSayisi[100];
int galibiyet[100], malubiyet[100], berabere[100], takimGolSayisi[100], yedigiGolSayisi[100],ayarlar[4], averaj,puan;
int cevap;
int hayir = 0;
int evet = 1;
int tkmsys = 0;
int mglbytpuani, glbytpuani, brbrlkpuani;

struct takimlarad
{
    char A[13], B[13], C[13], D[13], E[13], F[13], G[13], H[13], I[13], J[13] ;
} takimatama;

int main()
{
    takimlarokuma();
    yenitakim();
    takimsayisi();
    oynananmaclar();
    return 0;
}
int takimlarokuma()
{
    int i = 0;
    printf(" \n*******************LIG FIKSTURU *******************\n");
    FILE *dosya;

    if((dosya = fopen("takimlar.txt", "r"))!= NULL)
    {
        while(!feof(dosya))
        {
            fscanf(dosya, "%s", takim[i]);
            //printf("%s\n",takim[i]);
            i++;
        }
        for(i = 0; i < 12; i++)
        {
            takimatama.A [i] = takim[0][i];
            takimatama.B[i] = takim[1][i];
            takimatama.C[i] = takim[2][i];
            takimatama.D[i] = takim[3][i];
            takimatama.E[i] = takim[4][i];
            takimatama.F[i] = takim[5][i];
            takimatama.G[i] = takim[6][i];
            takimatama.H[i] = takim[7][i];
            takimatama.I[i] = takim[8][i];
            takimatama.J[i] = takim[9][i];
        }
        printf("A \t%s", takimatama.A);
        printf("\nB \t%s", takimatama.B);
        printf("\nC \t%s", takimatama.C);
        printf("\nD \t%s", takimatama.D);
        printf("\nE \t%s", takimatama.E);
        printf("\nF \t%s", takimatama.F);
        printf("\nG \t%s", takimatama.G);
        printf("\nH \t%s", takimatama.H);
        printf("\nI \t%s", takimatama.I);
        printf("\nJ \t%s", takimatama.J);
    }
}
int yenitakim()
{
    int sayi,i= 0;
    printf("\n\nYeni takim eklemek ister misiniz?");
    scanf("%d", &cevap);
    if(cevap == 1)
    {
        FILE *dosya;
        printf("kac takim giriceksiniz :",sayi);
        scanf(" %d",&sayi);
        printf("\nOnce takma ismi sonra takim ismini giriniz:");
        for(i = 0; i< sayi; i++)
        {
            scanf(" %c ",&takmaisim);
            scanf("%s", &takim[i]);
        }
        dosya = fopen("takimlar.txt", "a+");
        fprintf(dosya," \n %c\t%s", takmaisim, takim);
        fclose(dosya);
    }
    else
    {
        printf("\nMac girdilerini yazabilirsiniz.\n");
    }

}
int oynananmaclar()
{
    FILE *dosya;
    int i = 0;
    if((dosya = fopen("takimlar.txt", "r"))!= NULL)
    {
        while(!feof(dosya))
        {
            fscanf(dosya, "%s", takim[i]);
            //printf("%s\n",takim[i]);
            i++;
        }
        int a=0;
        int golsayisi[41];
        printf("\nMaclari klavyeden mi girmek ister misiniz? ");
        scanf(" %d", &cevap);
        int i=0;
        FILE *dosya;
        if((dosya = fopen("ayarlar.txt", "r"))!= NULL)
        {
            printf("\n\nTakim sayisi\tGalibiyet\tBeraberlik\tMaglubiyet\n");
            while(!feof(dosya))
            {
                for(i=0; i<4; i++)
                {
                    fscanf(dosya, "%d", &ayarlar[i]);
                    printf("     %d     \t",ayarlar[i]);
                }
                i++;
            }
            glbytpuani = ayarlar[1];
            brbrlkpuani = ayarlar[2];
            mglbytpuani = ayarlar[3];
            printf("\n\r*******************\n\r");
            fclose(dosya);
        }
        if(cevap == 0)
        {
            FILE *dosya;
            int j = 0, i = 0, k = 0;
            if((dosya = fopen("maclar.txt", "r"))!= NULL)
            {
                char readChar;
                char sonTakim = 0;
                while(!feof(dosya))
                {
                    fscanf(dosya, " %c %d", &readChar, &golsayisi[j]);
                    int bayrak = 0;

                    for(i = 0; i < tkmsys; i++)
                    {
                        if(readChar == takmaisim[i])
                        {
                            if(takimMacSayisi[i] == 0)
                            {
                                takimMacSayisi[i]++;
                            }
                            takimMacSayisi[i]++;
                            bayrak++;
                        }
                    }


                    if(bayrak == 0)
                    {
                        takmaisim[k++] = readChar;
                    }


                    if((j + 1) % 2 == 0)
                    {
                        if(j != 0)
                        {
                            int indis1 = abs(65 - readChar);
                            int indis2 = abs(65 - sonTakim);
                            takimGolSayisi[indis1] += golsayisi[j];
                            takimGolSayisi[indis2] += golsayisi[j - 1];

                            yedigiGolSayisi[indis1] += golsayisi[j - 1];
                            yedigiGolSayisi[indis2] += golsayisi[j];

                            if(golsayisi[j] > golsayisi[j - 1])
                            {
                                galibiyet[indis1]++;
                                malubiyet[indis2]++;
                            }
                            else if(golsayisi[j] < golsayisi[j - 1])
                            {
                                malubiyet[indis1]++;
                                galibiyet[indis2]++;
                            }
                            else
                            {
                                berabere[indis1]++;
                                berabere[indis2]++;
                            }
                        }
                        printf("%c %d\n",readChar, golsayisi[j]);
                    }
                    else
                    {
                        printf("%c %d ",readChar, golsayisi[j]);
                    }

                    sonTakim = readChar;
                    j++;
                }

                printf("\n\r*******************\n\r");
                printf("TKMTMI\t\tTKMI\tTKMCS\tGLB\tBRB\tMGB\tTKMGS\tYGS\tAVRJ\tPN\n\n");
                for(i = 0; i < tkmsys; i++)
                {
                    puan = (galibiyet[i]*glbytpuani) + (berabere[i]*brbrlkpuani) + (malubiyet[i]*mglbytpuani);
                    averaj = takimGolSayisi[i] - yedigiGolSayisi[i];
                    printf("%s   \t%c    \t%d    \t%d    \t%d    \t%d    \t%d    \t%d    \t%d    \t%d\n\r",takim[i], takmaisim[i], takimMacSayisi[i], galibiyet[i], berabere[i], malubiyet[i], takimGolSayisi[i], yedigiGolSayisi[i], averaj, puan);
                }


            }
        }

        else
        {

            printf("\nLutfen yapmak istediginiz maclari giriniz.\n");
            for(a=0; a<24; a++)
            {
                scanf(" %c %d", &takmaisim[a], &golsayisi[a]);

            }

            for(a=0; a<24; a++)
            {
                printf("\n%c %d", takmaisim[a], golsayisi[a]);
            }
        }

    }
}
int takimsayisi()
{
    FILE *dosya;
    int i = 0;
    if((dosya = fopen("takimlar.txt", "r"))!= NULL)
    {
        while(!feof(dosya))
        {
            fscanf(dosya, "%s", takim[i]);
            //printf("%s\n",takim[i]);
            i++;
            tkmsys++;
        }
        printf("\ntakim sayisi : %d\n",tkmsys);

    }
}
