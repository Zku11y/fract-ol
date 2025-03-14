/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:34:52 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/14 01:24:51 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
void get_color(t_mlx *mlx, int iter) {
    uint32_t r;
    uint32_t g;
    uint32_t b;

    if (iter == max_iter) {

        // Color for points that are in the set (e.g., black)

        mlx->color = 0x000000FF;
        return;
    } 
    else {

        // Normalize the number of iterations

        double t = (double)iter / (double)max_iter;


        // Create a color gradient

        r = (uint32_t)(9 * (1 - t) * t * t * t * 255); // Red

        g = (uint32_t)(15 * (1 - t) * (1 - t) * t * t * 255); // Green

        b = (uint32_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); // Blue
        mlx->color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
    }
}

void equation_julia(t_mlx *mlx)
{
    double iter;
    double temp;

    iter = 0;
    while(mlx->zr * mlx->zr + mlx->zi * mlx->zi < 5 && iter < max_iter)
    {
        temp = (mlx->zr * mlx->zr) - (mlx->zi * mlx->zi)+ mlx->cr;
        mlx->zi = (2 * mlx->zr * mlx->zi) + mlx->ci;
        mlx->zr = temp;
        iter = iter + 0.8;
    }
    get_color(mlx, (double)iter);
    // burning_color(mlx, (double)iter);
}
void julia(mlx_image_t *image, t_mlx *mlx)
{
    int x;
    int y;

    y = 0;
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {
            mlx->zi = ((((double)y / (double)HEIGHT) * (img_max - img_min)) * mlx->zoom) + img_min + mlx->up_down; // multiply by value to zoom    
            mlx->zr = ((((double)x / (double)WIDTH) * (real_max - real_min)) * mlx->zoom) + real_min + mlx->left_right; // multiply by value to zoom
            equation_julia(mlx);
            mlx_put_pixel(image, x, y, mlx->color);
            x++;
        }
        y++;
    }
    mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}

void color_2(t_mlx *mlx, double iter)
{
    if(iter == max_iter)
        mlx->color = 0x0000FF;
    else
        mlx->color = (iter / max_iter) * (0xFFFFFF);
}

// void equation_julia(t_mlx *mlx)
// {
//     double iter;
//     double temp;
//     double temp2;

//     iter = 0;
//     printf("zi = %.1lf zr = %.1lf cr = %.1lf ci = %.1lf\n", mlx->zi, mlx->zr, mlx->cr, mlx->ci);
//     while(mlx->zr * mlx->zr + mlx->zi * mlx->zi < 4 && iter < max_iter)
//     {
//         temp = (mlx->zr * mlx->zr) - (mlx->zi * mlx->zi)+ mlx->cr;
//         temp2 = (2 * mlx->zr * mlx->zi) + mlx->ci;
//     	// if (mlx->zr == temp && mlx->zi == temp2)
// 		// {
// 		// 	iter = max_iter;
// 		// 	break ;
// 		// }
//         mlx->zr = temp;
//         mlx->zi = temp2;
//         iter++;
//     }
//     burning_color(mlx, (double)iter);
// }

// void clear_image(mlx_image_t *image)
// {
//     int x, y;
//     for (y = 0; y < HEIGHT; y++)
//         for (x = 0; x < WIDTH; x++)
//             mlx_put_pixel(image, x, y, 0x000000FF);
// }

// void julia(mlx_image_t *image, t_mlx *mlx)
// {
//     int x, y;
    
//     clear_image(mlx->image); // Should create a perfect circle
    
//     y = 0;
//     while (y < HEIGHT)
//     {
//         x = 0;
//         while (x < WIDTH)
//         {
//             if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)
//                  printf("Boundary pixel at (%d, %d): zr=%f, zi=%f\n", x, y, mlx->zr, mlx->zi);

//             mlx->zi = (y - HEIGHT / 2) / (HEIGHT / 4.0);  // Normalize
//             mlx->zr = (x - WIDTH / 2) / (WIDTH / 4.0);  // Normalize

//             equation_julia(mlx);
//             mlx_put_pixel(image, x, y, mlx->color);
//             x++;
//         }
//         y++;
//     }
//     mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
// }
