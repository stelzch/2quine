const int f = 1;
const char *l = \
"const int life[]={72, -1,"
"72, -1,"
"72, -1,"
"72,-1,"
"3, 4, 3, 2, 6, 1, 7, -1,"
"3, 4, 3, 2, 6, 1, 3, -1,"
"3, 4, 3, 2, 2, 5, 6, -1,"
"3, 4, 3, 2, 5, 2, 6, -1,"
"3, 4, 3, 2, 5, 2, 3, -1,"
"6, 1, 3, 2, 2, 5, 7, -1,"
"6, 1, 3, 2, 2, 5, 7, -1,"
"0,-1,"
"3, 2, 3, 4, 3, 1, 3, 1, 11, 3, 5, 4, 11, 1, 7, 2, 8, -1,"
"3, 2, 3, 4, 3, 1, 3, 1, 11, 2, 3, 1, 3, 3, 11, 1, 3, 5, 9, -1,"
"3, 2, 4, 2, 4, 1, 3, 5, 3, 5, 3, 3, 3, 6, 3, 5, 6, 2, 2, -1,"
"3, 2, 3, 1, 2, 1, 3, 1, 3, 5, 3, 5, 9, 6, 3, 5, 6, 3, 7, -1,"
"3, 2, 3, 4, 3, 1, 3, 5, 3, 5, 9, 6, 3, 5, 3, 12, 2, -1,"
"3, 2, 3, 4, 3, 1, 3, 5, 3, 5, 3, 3, 3, 6, 3, 5, 7, 2, 8, -1,"
"3, 2, 3, 4, 3, 1, 3, 5, 3, 5, 3, 3, 3, 6, 3, 5, 7, 2, 7, -1,"
"0,-1,"
"2, 5, 3, 8, 2, 11, -1,"
"1, 3, 1, 3, 2, 9, 1, 11, -1,"
"3, 3, 3, 1, 3, 3, 3, 5, 3, 4, -1,"
"9, 1, 3, 2, 3, 6, 3, 4, -1,"
"9, 1, 8, 6, 3, 4, -1,"
"3, 3, 3, 1, 3, 3, 3, 5, 3, 4, -1,"
"3, 3, 3, 1, 3, 4, 3, 4, 3, 4, -1,"
"72,-1,"
"72, -1,"
"72, -1,"
"72, -1,"
"18000, -1, -2, -2};"
""
"void printEntryEscaped(const char *src, const int *spaces) {"
"    putchar(0x22);"
"    while(src != 0 && spaces != 0) {"
"        int ncharacters = *spaces++;"
"        if (ncharacters == -2) break;"
""
"        int nspaces = *spaces++;"
"        "
"        for(int i=0; i < ncharacters; i++) {"
"            if(*src == 0) return;"
"            putchar(*src++);"
"        }"
""
"        if (nspaces == -1) {"
"            putchar(0x22);"
"            putchar(0x0a);"
"            putchar(0x22);"
"            continue;"
"        }"
""
"        for(int i=0; i < nspaces; i++) {"
"            putchar(0x20);"
"        }"
"    }"
"}"
""
"char *escape(const char *buf) {"
"    char *dest = (char *) malloc(1 * 1024 * 1024);"
"    char *dptr = dest;"
"    char *ptr = buf;"
"    while (*ptr != 0) {"
"        if (*ptr == 0x0a) {"
"            *dptr++ = 0x5c;"
"            *dptr++ = 0x6e;"
"            ptr++;"
"        } else if (*ptr == 0x20) {"
"            *dptr++ = 0x23;"
"            ptr++;"
"        } else if (*ptr == 0x5c || *ptr == 0x22) {"
"            *dptr++ = 0x5c;"
"            *dptr++ = *ptr++;"
"        } else {"
"            *dptr++ = *ptr++;"
"        }"
"    }"
""
"    return dest;"
"}"
""
"void printEscaped(char c, int wrapped) {"
"    if (wrapped & (c == 0x22 || c == 0x5c))"
"        putchar(0x5c);"
"    putchar(c);"
"}"
""
"void printLine(const char *line, int wrapped) {"
"    const char *ptr = line;"
""
"    while(*ptr != 0) {"
"        printEscaped(*ptr, wrapped);"
"        ptr++;"
"    }"
"}"
""
"void printAll(int wrapped) {"
"    const char **ptr = l;"
"    do {"
"        if (wrapped) putchar(0x22);"
""
"        printLine(*ptr++, wrapped);"
""
"        if (wrapped) {"
"            putchar(0x22);"
"            putchar(0x2c);"
"        }"
"        putchar(0x0a);"
"    }"
"    while(*ptr != 0);"
"}"
""
""
"int main() {"
"    char *escaped = escape(l);"
"    printEntryEscaped(escaped, life);"
"    free(escaped);"
"}"
"";

////////////////////////////////


const int life[]={150, -1,
150, -1,
150, -1,
150,-1,
150,-1,
150,-1,
0,-1,-2,
3, 4, 3, 2, 6, 1, 7, -1,
3, 4, 3, 2, 6, 1, 3, -1,
3, 4, 3, 2, 2, 5, 6, -1,
3, 4, 3, 2, 5, 2, 6, -1,
3, 4, 3, 2, 5, 2, 3, -1,
6, 1, 3, 2, 2, 5, 7, -1,
6, 1, 3, 2, 2, 5, 7, -1,
0,-1,-2,
3, 2, 3, 4, 3, 1, 3, 1, 11, 3, 5, 4, 11, 1, 7, 2, 8, -1,
3, 2, 3, 4, 3, 1, 3, 1, 11, 2, 3, 1, 3, 3, 11, 1, 3, 5, 9, -1,
3, 2, 4, 2, 4, 1, 3, 5, 3, 5, 3, 3, 3, 6, 3, 5, 6, 2, 2, -1,
3, 2, 3, 1, 2, 1, 3, 1, 3, 5, 3, 5, 9, 6, 3, 5, 6, 3, 7, -1,
3, 2, 3, 4, 3, 1, 3, 5, 3, 5, 9, 6, 3, 5, 3, 12, 2, -1,
3, 2, 3, 4, 3, 1, 3, 5, 3, 5, 3, 3, 3, 6, 3, 5, 7, 2, 8, -1,
3, 2, 3, 4, 3, 1, 3, 5, 3, 5, 3, 3, 3, 6, 3, 5, 7, 2, 7, -1,
0,-1,-2,
0, 2, 5, 3, 8, 2, 11, -1,
0, 1, 3, 1, 3, 2, 9, 1, 11, -1,
3, 3, 3, 1, 3, 3, 3, 5, 3, -1,
9, 1, 3, 2, 3, 6, 3, -1,
9, 1, 8, 6, 3, -1,
3, 3, 3, 1, 3, 3, 3, 5, 3, -1,
3, 3, 3, 1, 3, 4, 3, 4, 3, -1, 
0,-1,-2,
150,-1,150,-1,150,-1,150,-1,150,-1,150,-1,150,-1,150,-1,150,-1,150,-1,-2, };

const char *printEntryEscaped(const char *src, const int *spaces, int offset) {
    // Seek to correct position
    while (offset != 0) {
        if (*spaces == -2) offset--;
        spaces++;
    }

    putchar(0x22);
    while(src != 0 && spaces != 0) {
        int ncharacters = *spaces++;
        if (ncharacters == -2) break;

        int nspaces = *spaces++;
        
        for(int i=0; i < ncharacters; i++) {
            if(*src == 0) return;
            putchar(*src++);
        }

        if (nspaces == -1) {
            putchar(0x22);
            putchar(0x0a);
            putchar(0x22);
            continue;
        }

        for(int i=0; i < nspaces; i++) {
            putchar(0x20);
        }
    }

    return src;
}

char *escape(const char *buf) {
    char *dest = (char *) malloc(8 * 1024 * 1024);
    char *dptr = dest;
    char *ptr = buf;
    while (*ptr != 0) {
        // Compress spaces
        if (*ptr == 0x20 && *(ptr+1) == 0x20) {
            ptr++; continue;
        }

        if (*ptr == 0x0a) {
            *dptr++ = 0x5c;
            *dptr++ = 0x6e;
            ptr++;
        } else if (*ptr == 0x20) {
            *dptr++ = 0x23;
            ptr++;
        } else if (*ptr == 0x5c || *ptr == 0x22) {
            *dptr++ = 0x5c;
            *dptr++ = *ptr++;
        } else {
            *dptr++ = *ptr++;
        }
    }

    return dest;
}


int main() {
    const char flag0[] = {99, 111, 110, 115, 116, 32, 105, 110, 116, 32, 102, 32, 61, 32, 48, 59, 92, 10, 0};
    const char flag1[] = {99, 111, 110, 115, 116, 32, 105, 110, 116, 32, 102, 32, 61, 32, 49, 59, 92, 10, 0};
    printf(f ? flag0 : flag1);

    const char preamble[] = {99, 111, 110, 115, 116, 32, 99, 104, 97, 114, 32, 42, 108, 32, 61, 32, 92, 10, 0};
    printf(preamble);
    char *escaped = escape(l);
    escaped = printEntryEscaped(escaped, life, 0);
    escaped = printEntryEscaped(escaped, life, f ? 1 : 3);
    escaped = printEntryEscaped(escaped, life, 2);
    escaped = printEntryEscaped(escaped, life, f ? 3 : 1);
    escaped = printEntryEscaped(escaped, life, 4);
    free(escaped);

    putchar(0x0a); putchar(0x0a);
    const char *ptr = l;
    while(*ptr != 0x00) {
        putchar(*ptr++);
    }

}

