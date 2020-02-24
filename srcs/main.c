/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:37:58 by anabaoui          #+#    #+#             */
/*   Updated: 2020/02/24 19:07:07 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void print_object(t_var *v)
{
	t_cam *cam  = v->cam;
	t_light *light = v->light;
	t_obj *obj = v->obj;
	if (cam)
	{
		printf("cam : origin %.0f,%.0f,%.0f target %.0f,%.0f,%.0f fov %.0f\n",
		cam->o.x,cam->o.y,cam->o.z,
		cam->target.x,cam->target.y,cam->target.z, cam->fov);
	}
	printf("\n");
	while (light)
	{
		printf("light : origin %.0f,%.0f,%.0f color %.0f,%.0f,%.0f power %.0f\n",
		light->o.x,light->o.y,light->o.z,
		light->color.x,light->color.y,light->color.z, light->power);
		light  = light->next;
	}
	printf("\n");
	while (obj)
	{
		printf("light : origin %.0f,%.0f,%.0f color %.0f,%.0f,%.0f axis %.0f,%.0f,%.0f translation %.0f,%.0f,%.0f rotation %.0f,%.0f,%.0f ray %.0f\n",
		obj->o.x,obj->o.y,obj->o.z,
		obj->color.x,obj->color.y,obj->color.z, 
		obj->axis.x,obj->axis.y,obj->axis.z, 
		obj->trans.x,obj->trans.y,obj->trans.z, 
		obj->rot.x,obj->rot.y,obj->rot.z, 
		obj->r);
		obj  = obj->next;
	}
}

int	main(int argc, char **argv)
{
	t_var	v;

	ft_bzero(&v, sizeof(t_var));
	if (argc == 2)
	{
		if (!argv[1] || !parse_file(argv[1], &v))
		{
			//free var
			return (1);
		}
		print_object(&v);
		rtv1(&v);
	}
	else
		ft_putendl("Usage : ./rtv1 [Scene Path]");
	return (0);
}
