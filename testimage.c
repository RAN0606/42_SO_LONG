#include "mlx.h"

int	main(void)
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	relative_path[] = "./cat.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 600, 300);	
//	mlx_mouse_get_pos(mlx, mlx_win, &img_width,&img_height);
	mlx_loop(mlx);
}
