#include "../inc/libmx.h"

void mx_write_str_list(t_list *strlist, int str_sum_len, char **lineptr) {
    char *linep = mx_strnew(str_sum_len);

    if (!strlist || !lineptr || !*lineptr)
        return;
    if (malloc_size(*lineptr))
        free(*lineptr);
    *lineptr = linep;
    while (strlist) {
        mx_strcpy(linep, strlist->data);
        linep += mx_strlen(strlist->data);
        strlist = strlist->next;
    }
}

