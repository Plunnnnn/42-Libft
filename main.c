#include "libft.h"

int main() {
    // Test ft_atoi
    char *atoi_test = "1234";
    printf("ft_atoi: %d, atoi: %d\n", ft_atoi(atoi_test), atoi(atoi_test));

    // Test ft_bzero
    char bzero_s1[10] = "Hello";
    char bzero_s2[10] = "Hello";
    ft_bzero(bzero_s1, 5);
    bzero(bzero_s2, 5);
    printf("ft_bzero: %s, bzero: %s\n", bzero_s1, bzero_s2);

    // Test ft_calloc
    int *calloc_arr1 = (int *) ft_calloc(4, sizeof(int));
    int *calloc_arr2 = (int *) calloc(4, sizeof(int));
    for (int i = 0; i < 5; i++) {
        printf("ft_calloc: %d, calloc: %d\n", calloc_arr1[i], calloc_arr2[i]);
    }
    free(calloc_arr1);
    free(calloc_arr2);

    // Test ft_isalpha
    char isalpha_test = 'P';
    printf("ft_isalpha: %d, isalpha: %d\n", ft_isalpha(isalpha_test), isalpha(isalpha_test));

    // Test ft_isalnum
    char isalnum_test = '9';
    printf("ft_isalnum: %d, isalnum: %d\n", ft_isalnum(isalnum_test), isalnum(isalnum_test));

    // Test ft_isascii
    int isascii_test = 111;
    printf("ft_isascii: %d, isascii: %d\n", ft_isascii(isascii_test), isascii(isascii_test));

    // Test ft_isdigit
    char isdigit_test = '5';
    printf("ft_isdigit: %d, isdigit: %d\n", ft_isdigit(isdigit_test), isdigit(isdigit_test));

    // Test ft_isprint
    char isprint_test = ' ';
    printf("ft_isprint: %d, isprint: %d\n", ft_isprint(isprint_test), isprint(isprint_test));

    // Test ft_memchr
    char memchr_s[] = "Hello, world";
    int memchr_c = 'w';
    printf("ft_memchr: %s, memchr: %s\n", (char *)ft_memchr(memchr_s, memchr_c, strlen(memchr_s)), (char *)memchr(memchr_s, memchr_c, strlen(memchr_s)));

    // Test ft_memcmp
    char memcmp_s1[] = "abcdef";
    char memcmp_s2[] = "abcdeg";
    printf("ft_memcmp: %d, memcmp: %d\n", ft_memcmp(memcmp_s1, memcmp_s2, 6), memcmp(memcmp_s1, memcmp_s2, 6));

    // Test ft_memcpy
    char memcpy_dest1[10];
    char memcpy_dest2[10];
    char memcpy_src[] = "Hello";
    ft_memcpy(memcpy_dest1, memcpy_src, 6);
    memcpy(memcpy_dest2, memcpy_src, 6);
    printf("ft_memcpy: %s, memcpy: %s\n", memcpy_dest1, memcpy_dest2);

    // Test ft_memset
    char memset_s1[10] = "Hello";
    char memset_s2[10] = "Hello";
    ft_memset(memset_s1, 'a', 5);
    memset(memset_s2, 'a', 5);
    printf("ft_memset: %s, memset: %s\n", memset_s1, memset_s2);

    // Test ft_strchr
    char strchr_s[] = "Hello, world";
    int strchr_c = 'o';
    printf("ft_strchr: %s, strchr: %s\n", ft_strchr(strchr_s, strchr_c), strchr(strchr_s, strchr_c));

    // Test ft_strdup
    char strdup_s[] = "Hello";
    char *ft_strdup_res = ft_strdup(strdup_s);
    char *strdup_res = strdup(strdup_s);
    printf("ft_strdup: %s, strdup: %s\n", ft_strdup_res, strdup_res);
    free(ft_strdup_res);
    free(strdup_res);

    // Test ft_strlcat
    char strlcat_dst1[20] = "Hello";
    char strlcat_dst2[20] = "Hello";
    char strlcat_src[] = " world";
    printf("ft_strlcat: %lu, strlcat: %lu\n", ft_strlcat(strlcat_dst1, strlcat_src, 20), strlcat(strlcat_dst2, strlcat_src, 20));
    printf("ft_strlcat result: %s, strlcat result: %s\n", strlcat_dst1, strlcat_dst2);

    // Test ft_strlcpy
    char strlcpy_dst1[20];
    char strlcpy_dst2[20];
    char strlcpy_src[] = "Hello";
    printf("ft_strlcpy: %lu, strlcpy: %lu\n", ft_strlcpy(strlcpy_dst1, strlcpy_src, 20), strlcpy(strlcpy_dst2, strlcpy_src, 20));
    printf("ft_strlcpy result: %s, strlcpy result: %s\n", strlcpy_dst1, strlcpy_dst2);

    // Test ft_strlen
    char strlen_s[] = "Hello";
    printf("ft_strlen: %lu, strlen: %lu\n", ft_strlen(strlen_s), strlen(strlen_s));

    // Test ft_strncmp
    char strncmp_s1[] = "abcdef";
    char strncmp_s2[] = "abcdeg";
    printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(strncmp_s1, strncmp_s2, 6), strncmp(strncmp_s1, strncmp_s2, 6));

    // Test ft_strnstr
    char strnstr_big[] = "Hello, world";
    char strnstr_little[] = "world";
    printf("ft_strnstr: %s, strnstr: %s\n", ft_strnstr(strnstr_big, strnstr_little, 12), strnstr(strnstr_big, strnstr_little, 12));

    // Test ft_strrchr
    char strrchr_s[] = "Hello, world";
    int strrchr_c = 'o';
    printf("ft_strrchr: %s, strrchr: %s\n", ft_strrchr(strrchr_s, strrchr_c), strrchr(strrchr_s, strrchr_c));

    // Test ft_tolower
    char tolower_test = 'A';
    printf("ft_tolower: %c, tolower: %c\n", ft_tolower(tolower_test), tolower(tolower_test));

    // Test ft_toupper
    char toupper_test = 'a';
    printf("ft_toupper: %c, toupper: %c\n", ft_toupper(toupper_test), toupper(toupper_test));

    return 0;
}
