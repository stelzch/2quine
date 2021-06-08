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

char *skipWhitespace(char *ptr) {
    while (*ptr == 0x20 || *ptr == 0x0a  || *ptr == 0x09 || *ptr == 0x0d) {
        ptr++;
    }
   
    return ptr;
}

const char *printEntryEscaped(const char *buf, const int *spaces, int offset) {
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
            if(*src == 0) return;
            src = skipWhitespace(src);
            char c = *src++;
            // Use pound sign instead of space
            putchar(c);
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
    putchar(0x22);
    putchar(0x0a);

    return src;
}

int main() {
    const char flag0[] = {99, 111, 110, 115, 116, 32, 105, 110, 116, 32, 102, 32, 61, 32, 48, 59, 92, 10, 0};
    const char flag1[] = {99, 111, 110, 115, 116, 32, 105, 110, 116, 32, 102, 32, 61, 32, 49, 59, 92, 10, 0};
    printf(f ? flag0 : flag1);

    const char preamble[] = {99, 111, 110, 115, 116, 32, 99, 104, 97, 114, 32, 42, 108, 32, 61, 32, 92, 10, 0};
    printf(preamble);
    char *escaped = l;
    escaped = printEntryEscaped(escaped, life, 0);
    escaped = printEntryEscaped(escaped, life, f ? 1 : 3);
    escaped = printEntryEscaped(escaped, life, 2);
    escaped = printEntryEscaped(escaped, life, f ? 3 : 1);
    escaped = printEntryEscaped(escaped, life, 4);
    putchar(0x22);putchar(0x3b);

    putchar(0x0a); putchar(0x0a);
    const char *ptr = l;
    while(*ptr != 0x00) {
        char c = *ptr++;
        // Decode pound sign to space
        if (c != 0x20) putchar((c == 0x23) ? 0x20 : c);
    }

}

