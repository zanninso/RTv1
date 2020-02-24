/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:12:38 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/24 17:53:24 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	shadow_checker(t_var *v, t_light *light)
{
	t_point		point;
	t_ray		r;
	double		dist_light;
	double		dist_object;

	r.o = ft_vector_add(v->point.p_inter,
			(ft_vector_mult_nbr(v->point.p_normal, 0.5)));
	r.dir = ft_vector_sub(light->o, r.o);
	ft_vector_norm(&r.dir);
	if (intersection_checker(v, r, &point))
	{
		objects_normal(r, &point);
		dist_light = ft_vector_dist(v->point.p_inter, light->o);
		dist_object = ft_vector_dist(v->point.p_inter, point.p_inter);
		if (dist_object < dist_light)
			return (1);
	}
	return (0);
}

void	pixel_ambient(t_var *v, int i)
{
	v->point.p_light.amb = ft_vector_div_nbr(
		ft_vector_add_nbr(v->point.p_light.amb, 80), i);
}

void	pixel_diffuse(t_var *v, t_light *light)
{
	v->point.p_light.def = ft_vector_add_nbr(v->point.p_light.def,
	light->power * fmax(0, ft_vector_dot(v->point.p_dir, v->point.p_normal)));
}

void	pixel_specular(t_var *v, t_light *light)
{
	t_vector	view_dir;
	t_vector	reflect;
	double		str;

	view_dir = ft_vector_sub(v->cam->o, v->point.p_inter);
	ft_vector_norm(&view_dir);
	v->point.p_dir = ft_vector_mult_nbr(v->point.p_dir, -1);
	reflect = ft_vector_sub(v->point.p_dir, ft_vector_mult_nbr(
		v->point.p_normal, 2 * ft_vector_dot(
		v->point.p_normal, v->point.p_dir)));
	str = light->power * pow(fmax(ft_vector_dot(view_dir, reflect), 0.), 100);
	v->point.p_light.spc = ft_vector_add_nbr(v->point.p_light.spc, str);
}

void	calculate_pixel_color(t_var *v, t_light *light, int i)
{
	pixel_ambient(v, i);
	if (!shadow_checker(v, light))
	{
		v->point.p_dir = ft_vector_sub(light->o, v->point.p_inter);
		ft_vector_norm(&v->point.p_dir);
		pixel_diffuse(v, light);
		pixel_specular(v, light);
	}
}
