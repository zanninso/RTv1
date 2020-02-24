/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <anabaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 02:25:27 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/23 13:48:47 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	ft_vector_sub(t_vector u, t_vector v)
{
	t_vector vec;

	vec.x = u.x - v.x;
	vec.y = u.y - v.y;
	vec.z = u.z - v.z;
	return (vec);
}

t_vector	ft_vector_mult_nbr(t_vector u, double t)
{
	t_vector vec;

	vec.x = u.x * t;
	vec.y = u.y * t;
	vec.z = u.z * t;
	return (vec);
}

t_vector	ft_vector_div_nbr(t_vector u, double t)
{
	t_vector vec;

	vec.x = u.x / t;
	vec.y = u.y / t;
	vec.z = u.z / t;
	return (vec);
}

t_vector	ft_vector_add(t_vector u, t_vector v)
{
	t_vector vec;

	vec.x = u.x + v.x;
	vec.y = u.y + v.y;
	vec.z = u.z + v.z;
	return (vec);
}

t_vector	ft_vector_mult(t_vector u, t_vector v)
{
	t_vector vec;

	vec.x = u.x * v.x;
	vec.y = u.y * v.y;
	vec.z = u.z * v.z;
	return (vec);
}
