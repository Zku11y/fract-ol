/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:09:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/11 00:01:37 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"
# include <time.h>

int main()
{
    void *init;
    void *window;
    int i;
    int j;

    i = (1920 / 2) - 200;
    j = (1080 / 2) - 200;
    init = mlx_init();
    window = mlx_new_window(init, 1920, 1080, "first window");
    if (window == NULL)
        printf("window was not created\n");
    // mlx_string_put(init, window, 200, 200, 83853312, "BOMBOCLAT");
    
    while(i++ < ((1920 / 2) + 200))
    {
        mlx_pixel_put(init, window, i, 1080 / 2, 83853312);
    }
    while(j++ < ((1080 / 2) + 200))
    {
        mlx_pixel_put(init, window, 1920 / 2, j, 83853312);
    }
    i = 1920 / 2;
    j = (1080 / 2) - 200;
    while(i++ < ((1920 / 2) + 200))
    {
        mlx_pixel_put(init, window, i, j, 83853312);
    }
    i = 1920 / 2;
    j = (1080 / 2) + 200;
    while(i-- > ((1920 / 2) - 200))
    {
        mlx_pixel_put(init, window, i, j, 83853312);
    }
    i = (1920 / 2) - 200;
    j = 1080 / 2;
    while(j-- > ((1080 / 2) - 200))
    {
        mlx_pixel_put(init, window, i, j, 83853312);
    }
    i = (1920 / 2) + 200;
    j = 1080 / 2;
    while(j++ < ((1080 / 2) + 200))
    {
        mlx_pixel_put(init, window, i, j, 83853312);
    }
    mlx_loop(init);
    // sleep(4);
}
