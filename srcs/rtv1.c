/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <anabaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:23:37 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/23 13:26:49 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_pixel_color(t_var *v, t_vector *light_color)
{
	t_light		*head;
	double		i;

	v->point.p_light.amb = (t_vector){0, 0, 0};
	v->point.p_light.def = (t_vector){0, 0, 0};
	v->point.p_light.spc = (t_vector){0, 0, 0};
	head = v->light;
	i = 1;
	while (head)
	{
		if (head->power)
		{
			calculate_pixel_color(v, head, i);
			i++;
		}
		head = head->next;
	}
	if (i == 1)
		v->point.p_light.amb = (t_vector){1, 1, 1};
	*light_color = ft_vector_mult(v->point.p_color, ft_vector_add(
		ft_vector_add(v->point.p_light.def, v->point.p_light.amb),
						v->point.p_light.spc));
}

t_vector	ray_trace(t_var *v, t_ray *ray)
{
	t_vector	color;

	color = (t_vector){0, 0, 0};
	if (intersection_checker(v, *ray, &v->point))
	{
		objects_normal(*ray, &v->point);
		get_pixel_color(v, &color);
	}
	return (color);
}

void		set_pixel_color(t_var *v, int i, int j, t_vector color)
{
	v->mlx.img_data[(j * IMG_W + i) * 4 + 0] =
							fmin(255, fmax(0, pow(color.z, 1 / 2.2)));
	v->mlx.img_data[(j * IMG_W + i) * 4 + 1] =
							fmin(255, fmax(0, pow(color.y, 1 / 2.2)));
	v->mlx.img_data[(j * IMG_W + i) * 4 + 2] =
							fmin(255, fmax(0, pow(color.x, 1 / 2.2)));
	v->mlx.img_data[(j * IMG_W + i) * 4 + 3] =
							0;
}

void		draw(t_var *v)
{
	t_ray		ray;
	t_vector	color;
	int			i;
	int			j;

	generate_camera(v);
	j = 0;
	while (j < IMG_H)
	{
		v->cam->j = 1. - 2. * (double)j / (double)IMG_H;
		i = 0;
		while (i < IMG_W)
		{
			v->cam->i = 2. * (double)i / (double)IMG_W - 1.;
			generate_camera_ray(v, &ray);
			color = ray_trace(v, &ray);
			set_pixel_color(v, i, j, color);
			i++;
		}
		j++;
	}
}

void		rtv1(t_var *v)
{
	v->mlx.mlx_ptr = mlx_init();
	v->mlx.win_ptr = mlx_new_window(v->mlx.mlx_ptr, IMG_W, IMG_H, "1337 RTV1");
	v->mlx.img_ptr = mlx_new_image(v->mlx.mlx_ptr, IMG_W, IMG_H);
	v->mlx.img_data = (unsigned char *)mlx_get_data_addr(
				v->mlx.img_ptr, &v->mlx.bpp, &v->mlx.size_l, &v->mlx.endian);
	draw(v);
	mlx_hook(v->mlx.win_ptr, 2, 0, ft_keys_hook, v);
	mlx_put_image_to_window(v->mlx.mlx_ptr, v->mlx.win_ptr, v->mlx.img_ptr,
				0, 0);
	mlx_loop(v->mlx.mlx_ptr);
}
