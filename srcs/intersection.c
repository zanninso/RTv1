/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:40:01 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/24 17:48:35 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		objects_intersection(t_ray r, t_obj *obj)
{
	double inter;

	inter = 0;
	if (obj->id == 3)
		inter = sphere_intersection(r, obj);
	else if (obj->id == 4)
		inter = cylinder_intersection(r, obj);
	else if (obj->id == 2)
		inter = plane_intersection(r, obj);
	else if (obj->id == 1)
		inter = cone_intersection(r, obj);
	return (inter);
}

double		intersection_checker(t_var *v, t_ray r, t_point *point)
{
	t_obj	*head;
	double	inter;
	double	i;

	head = v->obj;
	i = 0;
	point->inter_min = MAX_NBR;
	while (head)
	{
		if ((inter = objects_intersection(r, head)))
		{
			i = 1;
			if (inter <= point->inter_min)
			{
				point->inter_min = inter;
				point->obj = head;
			}
		}
		head = head->next;
	}
	return (i);
}

void		objects_normal(t_ray r, t_point *point)
{
	point->p_inter = ft_vector_add(r.o,
				ft_vector_mult_nbr(r.dir, point->inter_min));
	point->p_color = point->obj->color;
	if (point->obj->id == 3)
		point->p_normal = ft_vector_sub(point->p_inter, point->obj->o);
	else if (point->obj->id == 4 || point->obj->id == 1)
	{
		point->p_normal = ft_vector_sub(ft_vector_sub(point->p_inter,
			point->obj->o), ft_vector_mult_nbr(point->obj->axis,
			ft_vector_dot(r.dir, point->obj->axis) * point->inter_min +
			ft_vector_dot(ft_vector_sub(r.o, point->obj->o),
			point->obj->axis)));
	}
	else if (point->obj->id == 2)
		point->p_normal = point->obj->axis;
	ft_vector_norm(&point->p_normal);
}
