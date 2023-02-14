/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[100];
    char *namafile;
    char line[200];
    int count;
    char *day;
    char *month;
    char *year;
    char *keterangan;

    printf("Masukkan file jadwal matakuliah: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Aduh Syauqiii, masa nama matakuliah aja sampe salah");
        return 0;
    }

    count = 0;
    namafile = strtok(filename, ".");
    while (fgets(line, sizeof(line), fp))
    {
        count++;
        year = strtok(line, "-");
        month = strtok(NULL, "-");
        day = strtok(NULL, " ");
        keterangan = strtok(NULL, "\n");
        printf("%s/%s/%s %s\n", day, month, year, keterangan);
    }
    if (count == 0)
    {
        printf("Syauqi mahasiswa teladan belum pernah cabut\n");
    }

    if (count < 3)
    {
        printf("\nSisa jatah absen %s sebanyak %d kali", namafile, 3 - count);
        printf("\nAman broo cabut aja");
    }
    else if (count == 3)
    {
        printf("\nSisa jatah absen %s habis", namafile);
        printf("\nUdah gila lu qi kalo masih mau cabut");
    }
    else
    {
        printf("\nAduh ngulang %s!!", namafile);
        printf("\nWaktunya minta maaf ke dosen hehe :)");
    }
    fclose(fp);
    return 0;
}
