#include "./mlx_42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
	mlx_t	*mlx;

	mlx = mlx_init(500, 500, "cube3d", true);
	

	mlx_texture_t *texture;
	mlx_image_t *background;
	mlx_image_t *background2;
	mlx_texture_t	*knight_t;
	mlx_image_t	*knight;

	mlx_delete_image(mlx, background2);
	knight_t = mlx_load_png("./FreeKnight_v1/Colour2/Outline/120x80_PNGSheets/_Crouch.png");
	texture = mlx_load_png("./black-weave-lg.png");

	knight = mlx_texture_to_image(mlx, knight_t);
	background = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(knight_t);
	mlx_delete_texture(texture);

	mlx_image_to_window(mlx, background, 0, 0);
	mlx_image_to_window(mlx, knight, 250, 250);


	mlx_loop(mlx);
}


// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

//
// #define WIDTH 512
// #define HEIGHT 512
//
// static mlx_image_t* image;
//
// // -----------------------------------------------------------------------------
//
// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }
//
// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }
//
// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;
//
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }
//
// // -----------------------------------------------------------------------------
//
// int32_t main(void)
// {
// 	mlx_t* mlx;
//
// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 		kkk
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
//
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);
//
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
