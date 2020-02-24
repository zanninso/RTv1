/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <anabaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 02:26:28 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/23 13:50:16 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	ft_vector_cross(t_vector u, t_vector v)
{
	t_vector vec;

	vec.x = u.y * v.z - u.z * v.y;
	vec.y = u.z * v.x - u.x * v.z;
	vec.z = u.x * v.y - u.y * v.x;
	return (vec);
}

t_vector	ft_vector_norm(t_vector *vec)
{
	double	w;

	w = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	if (w)
	{
		vec->x /= w;
		vec->y /= w;
		vec->z /= w;
	}
	else
		*vec = (t_vector){0, 0, 0};
	return (*vec);
}

double		ft_vector_dot(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double		ft_vector_length(t_vector vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double		ft_vector_dist(t_vector u, t_vector v)
{
	return ((u.x - v.x) * (u.x - v.x) +
			(u.y - v.y) * (u.y - v.y) +
			(u.z - v.z) * (u.z - v.z));
}
