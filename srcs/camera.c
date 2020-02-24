/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:24:16 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/24 17:43:58 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	generate_camera(t_var *v)
{
	t_vector	up;
	double		fov;

	fov = v->cam->fov * M_PI / 180;
	up = (t_vector){0, 1, 0};
	v->cam->z = ft_vector_sub(v->cam->target, v->cam->o);
	ft_vector_norm(&v->cam->z);
	v->cam->x = ft_vector_cross(v->cam->z, up);
	ft_vector_norm(&v->cam->x);
	v->cam->y = ft_vector_cross(v->cam->x, v->cam->z);
	v->cam->height = tan(fov / 2) * 2;
	v->cam->width = v->cam->height * (IMG_W / IMG_H);
}

void	generate_camera_ray(t_var *v, t_ray *r)
{
	r->o = v->cam->o;
	r->dir = ft_vector_add(
		v->cam->z,
		ft_vector_add(
			ft_vector_mult_nbr(v->cam->x, (v->cam->i * v->cam->width)),
			ft_vector_mult_nbr(v->cam->y, (v->cam->j * v->cam->height))));
	ft_vector_norm(&r->dir);
}
