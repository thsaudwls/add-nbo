#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fp1 = fopen(argv[1], "rb");
	FILE *fp2 = fopen(argv[2], "rb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Can't open files\n");
        return 1;
    }

    uint32_t n1;
    uint32_t n2;

	if (fread(&n1, sizeof(u_int32_t), 1, fp1) == 0)
    {   
        printf("fread Error");
        return 1;
    }

    if (fread(&n2, sizeof(u_int32_t), 1, fp2) == 0)
    {   
        printf("fread Error");
        return 1;
    }

    uint32_t new1 = ntohl(n1);
    uint32_t new2 = ntohl(n2);

    // output format
    // 1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", new1, new1, new2, new2, new1 + new2, new1 + new2);

    fclose(fp1);
    fclose(fp2);

	return (0);
}