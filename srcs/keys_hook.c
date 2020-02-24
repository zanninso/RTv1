/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <anabaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:37:06 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/20 05:28:30 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_clear_and_draw(t_var *v)
{
	mlx_destroy_image(v->mlx.mlx_ptr, v->mlx.img_ptr);
	v->mlx.img_ptr = mlx_new_image(v->mlx.mlx_ptr, IMG_W, IMG_H);
	mlx_clear_window(v->mlx.mlx_ptr, v->mlx.win_ptr);
	draw(v);
	mlx_put_image_to_window(v->mlx.mlx_ptr, v->mlx.win_ptr,
							v->mlx.img_ptr, 0, 0);
}

int		ft_keys_hook(int k, t_var *v)
{
	if (k == 53)
		exit(0);
	else if (k == 124)
		v->event.move_x += 1;
	else if (k == 123)
		v->event.move_x -= 1;
	else if (k == 126)
		v->event.move_y += 1;
	else if (k == 125)
		v->event.move_y -= 1;
	else if (k == 13)
		v->event.move_z += 1;
	else if (k == 12)
		v->event.move_z -= 1;
	ft_clear_and_draw(v);
	return (0);
}
