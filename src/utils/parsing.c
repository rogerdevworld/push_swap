#include "../../include/push_swap.h"

/* funcion princial que verifica si hay un error en cualquiera de las otras para luego llamar a la funcion de imprimir error */
int    ft_thera_are_error(int argc, char **argv)
{
    if (!ft_no_repeat(argv))
        return (0);
    if (!ft_error_params(argc, argv))
        return (0);
    if (!ft_2147483648(argv))
        return (0);
    return (1);
}

/* validadcion de los vallores introducidos */
int    ft_2147483648(char **argv)
{
    int i;
    long    value;

    i = 0;
    while (argv[i])
    {
        value = ft_atoi_long(argv[i]);
        if (value > 2147483647 || value < -2147483648)
            return (0);
        i++;
    }
    return (1);
}

/* verificacion de repetidos */
int ft_no_repeat(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_atoi_long(argv[i]) == ft_atoi_long(argv[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

/* verrificacion de errores por parametros */
int    ft_error_params(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc <= 2)
        return (0);
    while (argv[i])
    {
        j = 0;
        while(argv[i][j])
        {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '+')
                    return (0);
            j++;
        }
        i++;
    }
    return (1);
}

/* solo impresionde error + \n */
void    ft_print_errors()
{
    write(2,  "Error\n", 6);
    //exit(1);
}