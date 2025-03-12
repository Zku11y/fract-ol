/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:48:29 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/12 22:44:25 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"
#include <stdio.h>

void color(t_mlx *mlx, double iter)
{
    // u_int32_t value;
    // u_int32_t r;
    // u_int32_t g;
    // u_int32_t b;

    // if(iter == (double)max_iter)
    // {
    //     mlx->color = 0x000000FF;
    //     return;
    // }
    // value = (iter / max_iter) * 0xFF;
    // r = (u_int32_t)value * 65280;
    // g = (u_int32_t)value * 60;
    // b = (u_int32_t)value * 0;
    // mlx->color = r + g + b + 255;
if (iter >= (double)max_iter)
    {
        mlx->color = 0x000000FF;
        return;
    }

    // double t = iter / (double)max_iter;
    u_int32_t r = (u_int32_t)(sin(0.8 * iter + 1) * 127 + 128);
    u_int32_t g = (u_int32_t)(sin(0.7 * iter + 3) * 127 + 128);
    u_int32_t b = (u_int32_t)(sin(0.6 * iter + 5) * 127 + 128);
    mlx->color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

void equation(t_mlx *mlx)
{
    double iter;
    double temp;

    mlx->zi = 0;
    mlx->zr = 0;
    iter = 0;
    while(mlx->zr * mlx->zr + mlx->zi * mlx->zi < 5 && iter < max_iter)
    {
        temp = (mlx->zr * mlx->zr) - (mlx->zi * mlx->zi)+ mlx->cr;
        mlx->zi = (2 * mlx->zr * mlx->zi) + mlx->ci;
        mlx->zr = temp;
        iter++;
    }
    color(mlx, (double)iter);
}

void mandelbrot(mlx_image_t *image, t_mlx *mlx)
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
            equation(mlx);
            mlx_put_pixel(image, x, y, mlx->color);
            x++;
        }
        y++;
    }
    mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}
