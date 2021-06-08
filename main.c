

int life[]={99, -1,
99, -1,
99, -1,
99, -1,
99, -1,
99, -1,-2,
10, 79, 10, -1,
10, 25, 3, 4, 3, 2, 6, 1, 7, 28, 10, -1,
10, 25, 3, 4, 3, 2, 6, 1, 3, 32, 10, -1,
10, 25, 3, 4, 3, 2, 2, 5, 6, 29, 10, -1,
10, 25, 3, 4, 3, 2, 5, 2, 6, 29, 10, -1,
10, 25, 3, 4, 3, 2, 5, 2, 3, 32, 10, -1,
10, 25, 6, 1, 3, 2, 2, 5, 7, 28, 10, -1,
10, 25, 6, 1, 3, 2, 2, 5, 7, 28, 10, -1,
10, 79, 10, -1,-2,
10, 3, 3, 2, 3, 4, 3, 2, 3, 1, 11, 3, 5, 4, 11, 1, 7, 2, 8, 3, 10, -1,
10, 3, 3, 2, 3, 4, 3, 2, 3, 1, 11, 2, 3, 1, 3, 3, 11, 1, 3, 5, 9, 3, 10, -1,
10, 3, 3, 2, 4, 2, 4, 2, 3, 5, 3, 5, 3, 3, 3, 6, 3, 5, 6, 2, 2, 10, 10, -1,
10, 3, 3, 2, 3, 1, 2, 1, 3, 2, 3, 5, 3, 5, 9, 6, 3, 5, 6, 3, 7, 4, 10, -1,
10, 3, 3, 2, 3, 4, 3, 2, 3, 5, 3, 5, 9, 6, 3, 5, 3, 12, 2, 3, 10, -1,
10, 3, 3, 2, 3, 4, 3, 2, 3, 5, 3, 5, 3, 3, 3, 6, 3, 5, 7, 2, 8, 3, 10, -1,
10, 3, 3, 2, 3, 4, 3, 2, 3, 5, 3, 5, 3, 3, 3, 6, 3, 5, 7, 2, 7, 4, 10, -1, -2,
10, 79, 10, -1,
10, 25, 5, 3, 8, 2, 11, 25, 10, -1,
10, 24, 3, 1, 3, 2, 9, 1, 11, 25, 10, -1,
10, 23, 3, 3, 3, 1, 3, 3, 3, 5, 3, 29, 10, -1,
10, 23, 9, 1, 3, 2, 3, 6, 3, 29, 10, -1,
10, 23, 9, 1, 8, 6, 3, 29, 10, -1,
10, 23, 3, 3, 3, 1, 3, 3, 3, 5, 3, 29, 10, -1,
10, 23, 3, 3, 3, 1, 3, 4, 3, 4, 3, 29, 10, -1,
10, 79, 10, -1, -2,
99, -1,
99, -1,
99, -1,
99, -1,
99, -1,
99, -1,
99, -1,
-1, -2, -2};

int putchar(int);
int printf(const char*, ...);
char *skipWhitespace(char *ptr) {
    while (*ptr == 0x20 || *ptr == 0x0a  || *ptr == 0x09 || *ptr == 0x0d) {
        ptr++;
    }
   
    return ptr;
}

char *printEntry(char *buf, int *spaces, int offset) {
    // Seek to correct position
    while (offset != 0) {
        if (*spaces == -2) offset--;
        spaces++;
    }

    putchar(0x22);
    char *src = buf;
    while(src != 0 && spaces != 0) {
        int ncharacters = *spaces++;
        if (ncharacters == -2) break;

        int nspaces = *spaces++;
        
        for(int i=0; i < ncharacters; i++) {
            if(*src == 0) return 0;
            src = skipWhitespace(src);
            char c = *src++;
            // Use pound sign instead of space
            putchar(c);
        }

        if (nspaces == -1 && *spaces != -2) {
            putchar(0x22);
            putchar(0x0a);
            putchar(0x22);
            continue;
        }

        for(int i=0; i < nspaces; i++) {
            putchar(0x20);
        }
    }
    putchar(0x22);
    putchar(0x0a);

    return src;
}

int main() {
    char flag[] = {105, 110, 116, 32, 102, 32, 61, 32, 48, 59, 10, 0};
    flag[8] = (f ? 48 : 49);
    printf(flag);

    char preamble[] = {99, 104, 97, 114, 32, 42, 108, 32, 61, 32, 92, 10, 0};
    printf(preamble);
    char *p = l;
    p = printEntry(p, life, 0);
    p = printEntry(p, life, f ? 1 : 3);
    p = printEntry(p, life, 2);
    p = printEntry(p, life, f ? 3 : 1);
    p = printEntry(p, life, 4);
    putchar(0x22);putchar(0x3b);

    putchar(0x0a); putchar(0x0a);
    char *ptr = l;
    while(*ptr != 0x00) {
        char c = *ptr++;
        // Decode pound sign to space
        if (c != 0x20) putchar((c == 0x23) ? 0x20 : c);
    }
    /*................................-C_S_*/

}

