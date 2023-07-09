#include "../cpu.h"

static int	is_separator(char c, char sep)
{
    if (c == sep || c == '\0')
        return (1);
    return (0);
}

static int	count_words(const char *str, char sep)
{
    int	i;
    int	counter;

    i = 0;
    counter = 0;
    while (str[i])
    {
        if (!is_separator(str[i], sep) && is_separator(str[i + 1], sep))
            counter++;
        i++;
    }
    return (counter);
}

static void	copy_word(char *dest, const char *src, char sep)
{
    int	i;

    i = 0;
    while (src[i] && !is_separator(src[i], sep))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

static void	add_words(char **array, const char *str, char sep)
{
    int		i;
    int		j;
    int		count;
    char	*word;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (is_separator(str[i], sep))
            i++;
        else
        {
            j = 0;
            while (str[i + j] && !is_separator(str[i + j], sep))
                j++;
            word = malloc(sizeof(char) * (j + 1));
            copy_word(word, str + i, sep);
            array[count] = word;
            count++;
            i += j;
        }
    }
}

char	**ft_split(const char *str, char sep)
{
    int		words;
    char	**array;

    if (!str)
        return (NULL);
    words = count_words(str, sep);
    array = malloc(sizeof(char *) * (words + 1));
    if (!array)
        return (NULL);
    add_words(array, str, sep);
    array[words] = 0;
    return (array);
}
