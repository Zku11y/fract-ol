/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:09:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/12 22:28:09 by mdakni           ###   ########.fr       */
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
    if (mlx->zoom < 0.1)
        mlx->zoom = 0.1;
    if (mlx->zoom > 10.0)
        mlx->zoom = 10.0;
    mandelbrot(mlx->image, mlx);
    mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}
// void key_hook(keys_t key, modifier_key_t modifier, action_t action, void *param)
// {
//     mlx_key_data_t key;

    
// }
void key_hook(mlx_key_data_t keydata, void *param)
{
    t_mlx *mlx = (t_mlx *)param;  // Cast the void* parameter to t_mlx*

    if (keydata.modifier)
    {
        ft_printf("no mods rn nigga\n");
    }
    if (keydata.action == MLX_PRESS)  // Only respond to key presses, not releases
    {  // Movement scales with zoom level

        if (keydata.key == MLX_KEY_LEFT)  // Move left
        {
            mlx->left_right -= 0.1;
        }
        else if (keydata.key == MLX_KEY_RIGHT)  // Move right
        {
            mlx->left_right += 0.1;
        }
        else if (keydata.key == MLX_KEY_UP)  // Move left
        {
            mlx->up_down += 0.1;
        }
        else if (keydata.key == MLX_KEY_DOWN)  // Move right
        {
            mlx->up_down -= 0.1;
        }

        // Redraw the fractal with the new position
        mandelbrot(mlx->image, mlx);
        mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
    }
}

int main(int ac, char **av)
{
    t_mlx mlx;

    if(parse(ac, av) == 1)
        mlx.mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", false);
    else if(parse(ac, av) == 2)
        mlx.mlx = mlx_init(WIDTH, HEIGHT, "Julia", false);
    else
        error_msg();
    mlx.image = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
    mlx.zoom = 1.0;
    mlx.left_right = 0;
    mlx.up_down = 0;
    mlx_scroll_hook(mlx.mlx, scroll_hook, &mlx);
    mlx_key_hook(mlx.mlx,key_hook, &mlx);
mandelbrot(mlx.image, &mlx);
    mlx_loop(mlx.mlx);
}
