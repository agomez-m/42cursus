#include <stdio.h>
#include "libft.a"

int main() {
    // Test ft_isalpha
    printf("Is 'A' alpha? %d\n", ft_isalpha('A'));
    printf("Is '5' alpha? %d\n", ft_isalpha('5'));

    // Test ft_isdigit
    printf("Is '5' digit? %d\n", ft_isdigit('5'));
    printf("Is 'A' digit? %d\n", ft_isdigit('A'));

    // Test ft_isalnum
    printf("Is 'A' alnum? %d\n", ft_isalnum('A'));
    printf("Is '5' alnum? %d\n", ft_isalnum('5'));
    printf("Is '&' alnum? %d\n", ft_isalnum('&'));

    // Test ft_bzero
    char str[10] = "123456789";
    ft_bzero(str, 5);
    printf("After bzero: %s\n", str);

    // Test ft_memset
    char buffer[10];
    ft_memset(buffer, 'A', 5);
    printf("After memset: %s\n", buffer);

    // Test ft_toupper
    printf("Lowercase 'a' to uppercase: %c\n", ft_toupper('a'));

    // Test ft_putstr_fd
    ft_putstr_fd("Hello, world!\n", 1);

    // Test ft_putendl_fd
    ft_putendl_fd("This is a test.", 1);

    // Test ft_putchar_fd
    ft_putchar_fd('X', 1);

    // Test ft_putnbr_fd
    ft_putnbr_fd(12345, 1);

    // Test ft_isascii
    printf("Is '@' ASCII? %d\n", ft_isascii('@'));

    // Test ft_isprint
    printf("Is ' ' printable? %d\n", ft_isprint(' '));

    // Test ft_tolower
    printf("Uppercase 'A' to lowercase: %c\n", ft_tolower('A'));

    // Test ft_atoi
    int num = ft_atoi("12345");
    printf("String to int: %d\n", num);

    // Test ft_calloc
    int *arr = (int *)ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Test ft_strdup
    char *str_dup = ft_strdup("Hello, strdup!");
    printf("Duplicated string: %s\n", str_dup);

    // Test ft_strjoin
    char *joined = ft_strjoin("Hello, ", "world!");
    printf("Joined string: %s\n", joined);

    // Test ft_strtrim
    char *trimmed = ft_strtrim("   Hello, world!   ", " ");
    printf("Trimmed string: %s\n", trimmed);

    // Test ft_substr
    char *substr = ft_substr("Hello, world!", 3, 5);
    printf("Substring: %s\n", substr);

    // Test ft_strmapi
    char *str_mapi = ft_strmapi("Hello", ft_mapi_function);
    printf("Mapped string: %s\n", str_mapi);

    // Test ft_split
    char **str_array = ft_split("This,is,a,test", ',');
    for (int i = 0; str_array[i] != NULL; i++) {
        printf("%s\n", str_array[i]);
    }

    // Test ft_itoa
    char *itoa_str = ft_itoa(12345);
    printf("Integer to string: %s\n", itoa_str);

    // Test ft_strlcat
    char dest[10] = "Hello";
    size_t result = ft_strlcat(dest, " world", 10);
    printf("Concatenated string: %s, Length: %zu\n", dest, result);

    // Test ft_strlcpy
    char dest_lcp[10];
    size_t result_lcp = ft_strlcpy(dest_lcp, "Hello, world", 10);
    printf("Copied string: %s, Length: %zu\n", dest_lcp, result_lcp);

    // Test ft_strlen
    printf("Length of 'Hello, world!': %zu\n", ft_strlen("Hello, world!"));

    // Test ft_striteri
    char str_iteri[] = "Hello";
    ft_striteri(str_iteri, ft_iteri_function);
    printf("Modified string: %s\n", str_iteri);

    // Test ft_memcpy
    char dest_memcpy[10];
    ft_memcpy(dest_memcpy, "memcpy", 6);
    printf("Copied string: %s\n", dest_memcpy);

    // Test ft_memmove
    char dest_memmove[10];
    ft_memmove(dest_memmove, "memmove", 7);
    printf("Moved string: %s\n", dest_memmove);

    // Test ft_strchr
    char *str_chr = "Hello, world!";
    char *result_chr = ft_strchr(str_chr, 'o');
    printf("First 'o' found at: %s\n", result_chr);

    // Test ft_strrchr
    char *result_rchr = ft_strrchr(str_chr, 'o');
    printf("Last 'o' found at: %s\n", result_rchr);

    // Test ft_strncmp
    int cmp_result = ft_strncmp("abc", "abcd", 3);
    printf("Comparison result: %d\n", cmp_result);

    // Test ft_strnstr
    char *result_nstr = ft_strnstr("Hello, world!", "world", 13);
    printf("Substring found at: %s\n", result_nstr);

    // Test ft_memcmp
    int mem_cmp_result = ft_memcmp("abc", "abcd", 3);
    printf("Memory comparison result: %d\n", mem_cmp_result);

    // Test ft_memchr
    char *mem_chr_str = "Hello, world!";
    char *mem_chr_result = ft_memchr(mem_chr_str, 'w', 13);
    printf("Memory char found at: %s\n", mem_chr_result);

    // Test ft_calloc (repeated for demonstration)
    int *arr_calloc = (int *)ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr_calloc[i]);
    }
    printf("\n");

    // Test ft_strdup (repeated for demonstration)
    char *str_dup2 = ft_strdup("Hello, strdup!");
    printf("Duplicated string: %s\n", str_dup2);

    // Test ft_lstnew
    t_list *new_node = ft_lstnew("Hello, List Node");
    printf("List Node Content: %s\n", (char *)new_node->content);

    // Test ft_lstadd_front
    t_list *lst = NULL;
    ft_lstadd_front(&lst, new_node);
    printf("List Node Content (added front): %s\n", (char *)lst->content);

    // Test ft_lstsize
    int lst_size = ft_lstsize(lst);
    printf("List Size: %d\n", lst_size);

    // Test ft_lstlast
    t_list *last_node = ft_lstlast(lst);
    printf("Last List Node Content: %s\n", (char *)last_node->content);

    // Test ft_lstadd_back
    t_list *new_back_node = ft_lstnew("Back Node");
    ft_lstadd_back(&lst, new_back_node);
    printf("Back Node Content (added back): %s\n", (char *)new_back_node->content);

    // Test ft_lstdelone
    ft_lstdelone(new_back_node, free);
    printf("Back Node Content (after deleting): %s\n", (char *)new_back_node->content);

    // Test ft_lstclear
    ft_lstclear(&lst, free);
    printf("List Size (after clearing): %d\n", ft_lstsize(lst));

    // Test ft_lstmap
    t_list *new_list = ft_lstmap(lst, ft_map_function, free);
    printf("Mapped List Size: %d\n", ft_lstsize(new_list));

    return 0;
}
