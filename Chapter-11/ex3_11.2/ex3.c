/* 11.2: Solution Approach (main's job)
1) Read start address in hex.
2) Normalize it to the next lower 256-byte boundary.
3) Read format (b/w/l) and pass to dump().
--------------------------------------------
Bu örnekte kullanıcıdan bir bellek adresi ve bir gösterim formatı alındı, 
girilen adres düzenli dump yapılabilmesi için 256-byte sınırına hizalandı ve 
bu adres + format bilgisi dump fonksiyonuna iletildi. Program bu aşamada belleği okumadı veya yazmadı; 
sadece nereden ve nasıl dump yapılacağını belirledi.
Dump yapmak, belleğin (memory) içeriğini olduğu gibi ekrana yazdırmak demektir.
*/

#include <stdio.h>
#include <ctype.h>

typedef unsigned char  UBYTE;
typedef unsigned short WORD;
typedef unsigned long  ULONG;
typedef long           LONG;

static LONG xtol_hex(const char *s) { /* minimal hex -> long */
    ULONG v=0; int c;
    if (s[0]=='0' && (s[1]=='x'||s[1]=='X')) s+=2;
    while ((c=*s++)!=0) {
        if (c>='0'&&c<='9') v=(v<<4)+(c-'0');
        else if (c>='a'&&c<='f') v=(v<<4)+(c-'a'+10);
        else if (c>='A'&&c<='F') v=(v<<4)+(c-'A'+10);
        else break;
    }
    return (LONG)v;
}

/* stub: in the chapter, dump(start, fmt) is called */
static void dump_stub(const UBYTE *adr, WORD fmt) {
    printf("dump called with start=%08lX fmt=%u\n", (ULONG)adr, fmt);
}

int main(void) {
    char input[81];
    UBYTE *start;
    WORD fmt = 1;

    printf("Start address (in hex): ");
    if (!fgets(input, sizeof(input), stdin)) return 0;
    start = (UBYTE*)xtol_hex(input);

    /* normalize to lower 256-byte boundary */
    start = (UBYTE*)(((ULONG)start / 0x100UL) * 0x100UL);

    printf("Format (b/w/l): ");
    int ch = tolower(getchar());
    if (ch=='w') fmt=2;
    else if (ch=='l') fmt=4;

    dump_stub(start, fmt);
    return 0;
}
