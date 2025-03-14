/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:09:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/14 01:27:07 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fractol.h"
# include <time.h>

void scroll_hook(double xdelta, double ydelta, void *param)
{
    t_mlx *mlx = (t_mlx *)param;  // Cast the void* parameter to t_mlx*

    // ydelta > 0 means scroll up, ydelta < 0 means scroll down
    if(xdelta > 0)
    {
        ft_printf("bomboclat\n");
    }
    if (ydelta > 0)
    {
        mlx->zoom *= 1.1;  // Zoom in
    }
    else if (ydelta < 0)
    {
        mlx->zoom *= 0.9;  // Zoom out
    }

    // Clamp zoom to reasonable bounds
    if (mlx->zoom > 1.3)
        mlx->zoom = 1.3;
    if (mlx->flag == 1)
        mandelbrot(mlx->image, mlx);
    else if (mlx->flag == 2)
        julia(mlx->image, mlx);
    else
        burning_ship(mlx->image, mlx);
    mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}
void key_hook(mlx_key_data_t keydata, void *param)
{
    t_mlx *mlx = (t_mlx *)param;  // Cast the void* parameter to t_mlx*

    if (keydata.action == MLX_PRESS)  // Only respond to key presses, not releases
    {  // Movement scales with zoom level
        if (keydata.key == MLX_KEY_ESCAPE)  // Move left
            mlx_close_window(mlx->mlx);
        if (keydata.key == MLX_KEY_KP_SUBTRACT)  // Move left
        {
            mlx->zoom *= 1.1;
        }
        else if (keydata.key == MLX_KEY_KP_ADD)  // Move left
        {
            mlx->zoom *= 0.9;
        }
        else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)  // Move left
        {
            mlx->left_right -= 0.1 * mlx->zoom;
        }
        else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)  // Move right
        {
            mlx->left_right += 0.1 * mlx->zoom;
        }
        else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)  // Move left
        {
            mlx->up_down += 0.1 * mlx->zoom;
        }
        else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)  // Move right
        {
            mlx->up_down -= 0.1 * mlx->zoom;
        }
    }
    if (mlx->zoom > 1.3)
        mlx->zoom = 1.3;
    if (mlx->zoom > 1.3)
        mlx->zoom = 1.3;
    if (mlx->flag == 1)
        mandelbrot(mlx->image, mlx);
    else if (mlx->flag == 2)
        julia(mlx->image, mlx);
    else
        burning_ship(mlx->image, mlx);
    mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}
void fractol(t_mlx *mlx)
{
    mlx->zoom = 1.0;
    mlx->left_right = 0;
    mlx->up_down = 0;
    mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
    mlx_scroll_hook(mlx->mlx, scroll_hook, mlx);
    mlx_key_hook(mlx->mlx,key_hook, mlx);
    if (mlx->flag == 1)
        mandelbrot(mlx->image, mlx);
    else if (mlx->flag == 2)
        julia(mlx->image, mlx);
    else
        burning_ship(mlx->image, mlx);
}
int main(int ac, char **av)
{
    t_mlx mlx;

    mlx.flag = 0;
    if(parse(ac, av) == 1)
    {
        mlx.mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", false);
        mlx.flag = 1;
    }
    else if(parse(ac, av) == 2)
    {
        mlx.cr = atof(av[2]);
        mlx.ci = atof(av[3]);
        mlx.mlx = mlx_init(WIDTH, HEIGHT, "Julia", false);
        mlx.flag = 2;
    }
    else if (parse(ac, av) == 3)
    {
        mlx.mlx = mlx_init(WIDTH, HEIGHT, "Burning_ship", false);
        mlx.flag = 3;
    }
    fractol(&mlx);
    mlx_loop(mlx.mlx);
}

