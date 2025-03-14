/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:45:51 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/13 20:39:39 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"


void burning_color(t_mlx *mlx, double iter)
{
    uint32_t r;
    uint32_t g;
    uint32_t b;
    double t;

    if (iter >= max_iter)
    {
        mlx->color = 0x000000FF;
        return;
    }
    t = iter / max_iter;
    r = (uint32_t)(10 * (1 - t) * t * t * t * 255);
    g = (uint32_t)(5 * (1 - t) * (1 - t) * t * t * 255);
    b = (uint32_t)(3 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    mlx->color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

void burning_equation(t_mlx *mlx)
{
    double iter;
    double temp;

    mlx->zi = 0;
    mlx->zr = 0;
    iter = 0;
    while(mlx->zr * mlx->zr + mlx->zi * mlx->zi < 5 && iter < max_iter)
    {
        mlx->zr = fabs(mlx->zr);
        mlx->zi = fabs(mlx->zi);
        temp = (mlx->zr * mlx->zr) - (mlx->zi * mlx->zi)+ mlx->cr;
        mlx->zi = (2 * mlx->zr * mlx->zi) + mlx->ci;
        mlx->zr = temp;
        iter = iter + 0.4;
    }
    // burning_color(mlx, (double)iter);
    color(mlx, (double)iter);
}

void burning_ship(mlx_image_t *image, t_mlx *mlx)
{
    int x;
    int y;

    y = 0;
    while(y < HEIGHT)
    {
        mlx->ci = (((y / (double)HEIGHT) * (img_max - img_min) + img_min) * mlx->zoom) + mlx->up_down; // multiply by value to zoom    
        x = 0;
        while(x < WIDTH)
        {
            mlx->cr = (((x / (double)WIDTH) * (real_max - real_min) + real_min) * mlx->zoom) + mlx->left_right; // multiply by value to zoom
            // printf("%.1lf%+.1lfi\n", mlx->cr, mlx->ci);
            burning_equation(mlx);
            mlx_put_pixel(image, x, y, mlx->color);
            x++;
        }
        y++;
    }
    mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}
