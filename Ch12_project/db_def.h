#ifndef DB_DEF_H
#define DB_DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned long  LONG;

#define NEIN 0
#define JA   1
#define NULLP ((void*)0)

#define OPEN_ERR  1
#define READ_ERR  2
#define WRITE_ERR 3
#define MEMORY_ERR 4

/* menu codes */
#define ANZEIGEN    1
#define AUFNEHMEN   2
#define LOESCHEN    3
#define SPEICHERN   4
#define LESEN       5
#define SORTIEREN   6
#define QUIT        9

#define INPUT_MAX 256

typedef struct {
    char vorname[32];
    char nachname[32];
    char wohnort[32];
    char strasse[32];
    char telefon[16];   /* max 13 in book, keep 15 incl. \0 */
    char plz_lc[4];     /* country code 3 + \0 */
    LONG plz_num;       /* numeric postal code */
    WORD geb_tag;
    WORD geb_monat;
    WORD geb_jahr;
} PDAT;

typedef struct node {
    struct node *prev;
    struct node *next;
    void *data;         /* points to PDAT */
} NODE, *PNODE;

/* break loop on EOF or error */
#define break_oneof(fp) (feof((fp)) || ferror((fp)))

#endif
