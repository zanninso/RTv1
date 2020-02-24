/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:27:32 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/24 17:51:30 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	equation_solve(double a, double b, double c)
{
	double delta;
	double inter1;
	double inter2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	inter1 = (-b - sqrt(delta)) / (2 * a);
	inter2 = (-b + sqrt(delta)) / (2 * a);
	if ((inter2 < MIN_NBR && inter1 < MIN_NBR))
		return (0);
	if ((inter2 < MIN_NBR))
		return (inter1);
	if ((inter1 < MIN_NBR))
		return (inter2);
	return (fmin(inter1, inter2));
}

double	sphere_intersection(t_ray r, t_obj *obj)
{
	double		a;
	double		b;
	double		c;
	t_vector	obj_center;

	obj_center = ft_vector_sub(r.o, obj->o);
	a = ft_vector_dot(r.dir, r.dir);
	b = 2 * ft_vector_dot(r.dir, obj_center);
	c = ft_vector_dot(obj_center, obj_center) - obj->r * obj->r;
	return (equation_solve(a, b, c));
}

double	cylinder_intersection(t_ray r, t_obj *obj)
{
	double		a;
	double		b;
	double		c;
	t_vector	obj_center;

	obj_center = ft_vector_sub(r.o, obj->o);
	ft_vector_norm(&obj->axis);
	a = ft_vector_dot(r.dir, r.dir) - ft_vector_dot(r.dir, obj->axis)
		* ft_vector_dot(r.dir, obj->axis);
	b = 2 * (ft_vector_dot(r.dir, obj_center) - (ft_vector_dot(
		r.dir, obj->axis) * ft_vector_dot(obj_center, obj->axis)));
	c = ft_vector_dot(obj_center, obj_center) - ft_vector_dot(obj_center,
		obj->axis) * ft_vector_dot(obj_center, obj->axis) - obj->r * obj->r;
	return (equation_solve(a, b, c));
}

double	plane_intersection(t_ray r, t_obj *obj)
{
	t_vector	obj_center;
	double		inter;
	double		nor_dir;

	obj_center = ft_vector_sub(obj->o, r.o);
	if ((nor_dir = ft_vector_dot(r.dir, obj->axis)))
		inter = ft_vector_dot(obj_center, obj->axis) / nor_dir;
	else
		return (0);
	if (inter < MIN_NBR || inter > MAX_NBR)
		return (0);
	return (inter);
}

double	cone_intersection(t_ray r, t_obj *obj)
{
	double		a;
	double		b;
	double		c;
	t_vector	obj_center;

	obj_center = ft_vector_sub(r.o, obj->o);
	ft_vector_norm(&obj->axis);
	a = ft_vector_dot(r.dir, r.dir) - (1 + pow(tan(obj->r), 2)) *
			pow(ft_vector_dot(r.dir, obj->axis), 2);
	b = 2 * (ft_vector_dot(r.dir, obj_center) - (1 + pow(tan(obj->r), 2)) *
			ft_vector_dot(r.dir, obj->axis) *
			ft_vector_dot(obj_center, obj->axis));
	c = ft_vector_dot(obj_center, obj_center) - (1 + pow(tan(obj->r), 2)) *
			pow(ft_vector_dot(obj_center, obj->axis), 2);
	return (equation_solve(a, b, c));
}
