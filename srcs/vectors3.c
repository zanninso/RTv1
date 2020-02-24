/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <anabaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:48:53 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/23 13:49:23 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	ft_vector_add_nbr(t_vector u, double t)
{
	t_vector vec;

	vec.x = u.x + t;
	vec.y = u.y + t;
	vec.z = u.z + t;
	return (vec);
}

t_vector	ft_vector_rotate(t_vector v, t_vector r)
{
	t_vector res;

	res.x = v.x;
	res.y = v.y * cos(r.x) + v.z * sin(r.x);
	res.z = -v.y * sin(r.x) + v.z * cos(r.x);
	v = (t_vector) {res.x, res.y, res.z};
	res.x = v.x * cos(r.y) + v.z * sin(r.y);
	res.y = v.y;
	res.z = -v.x * sin(r.y) + v.z * cos(r.y);
	v = (t_vector) {res.x, res.y, res.z};
	res.x = v.x * cos(r.z) - v.y * sin(r.z);
	res.y = v.x * sin(r.z) + v.y * cos(r.z);
	res.z = v.z;
	return (res);
}
