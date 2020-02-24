#include "rtv1.h"

t_light	*save_light(void)
{
	t_light	*elem;

	if (!(elem = malloc(sizeof(t_light))))
		return (0);	
	elem->o = 0;
	elem->color = 0;
	elem->power = 0;
	elem->next = 0;
	return (elem);
}

int	save_lights(t_light **l, char **t)
{
	int	i;
	t_light	*li;
	t_light	*tmp;

	i = 0;
	li = save_light();
	while (t[i])
	{
		if (!ft_strcmp("origin", t[i]))
		{
			i++;
			if ((li->o = check_vector(t[i])) == 0)
				return (1);
		}
		if (!ft_strcmp("power", t[i]))
		{
			i++;
			if ((li->power = ft_str_to_dbl(t[i])) < 0)
				return (1);
		}
		if (!ft_strcmp("color", t[i]))
		{
			i++;
			if ((li->color = check_vector(t[i])) == 0)
				return (1);
		}
		i++;
	}
	if (li->o == 0 || li->color == 0 || li->power < 0)
		return (1);
	if (*l)
	{
		tmp = *l;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = li;
	}
	else
		*l = li;
	return (0);
}

t_cam	*init_camera(void)
{
	t_cam	*elem;

	if (!(elem = malloc(sizeof(t_cam))))
		return (0);	
	elem->o = 0;
	elem->target = 0;
	elem->fov = 0;
	return (elem);
}

int	save_camera(t_cam **cam, char **t)
{
	int		i;

	i = 0;
	if (*cam)
		return (1);
	*cam = init_camera();
	while (t[i])
	{
		if (!ft_strcmp("origin", t[i]))
		{
			i++;
			if (((*cam)->o = check_vector(t[i])) == 0)
				return (1);
		}
		if (!ft_strcmp("fov", t[i]))
		{
			i++;
			if (((*cam)->fov = ft_str_to_dbl(t[i])) < 0)
				return (1);
		}
		if (!ft_strcmp("target", t[i]))
		{
			i++;
			if (((*cam)->target = check_vector(t[i])) == 0)
				return (1);
		}
		i++;
	}
	if ((*cam)->o == 0 || (*cam)->fov <= 20 || (*cam)->target == 0)
		return (1);
	return (0);
}

t_obj	*save_object(void)
{
	t_obj	*elem;

	if (!(elem = malloc(sizeof(t_obj))))
		return (0);	
	elem->o = 0;
	elem->r = 0;
	elem->rot = 0;
	elem->axis = 0;
	elem->trans = 0;
	elem->color = 0;
	elem->next = 0;
	return (elem);
}

int	save_objects(t_obj **objs, char **t, int id)
{
	int	i;
	t_obj	*obj;
	t_obj	*tmp;

	i = 0;
	obj = save_object();
	obj->id = id - 2;
	while (t[i])
	{
		if (!ft_strcmp("origin", t[i]))
		{
			i++;
			if ((obj->o = check_vector(t[i])) == 0)
				return (1);
		}
		if (!ft_strcmp("ray", t[i]))
		{
			i++;
			if ((obj->r = ft_str_to_dbl(t[i])) < 0)
				return (1);
		}
		if (!ft_strcmp("rotation", t[i]))
		{
			i++;
			if ((obj->rot = check_vector(t[i])) < 0)
				return (1);
			if (obj->axis)
			{
				*obj->rot = (t_vector){(obj->rot->x * M_PI) / 180,(obj->rot->y * M_PI) / 180,(obj->rot->z * M_PI) / 180};
				*obj->axis = ft_vector_rotate(*obj->axis, *obj->rot);
			}
			else
				return (1);
		}
		if (!ft_strcmp("axis", t[i]))
		{
			i++;
			if ((obj->axis = check_vector(t[i])) == 0)
				return (1);
		}
		if (!ft_strcmp("translation", t[i]))
		{
			i++;
			if ((obj->trans = check_vector(t[i])) == 0)
				return (1);
			if (obj->o)
				*obj->o = ft_vector_add(*obj->o, *obj->trans);
			else
				return (1);			
		}
		if (!ft_strcmp("color", t[i]))
		{
			i++;
			if ((obj->color = check_vector(t[i])) == 0)
				return (1);
		}
		i++;
	}
	if (obj->o == 0 || obj->color == 0 || (obj->r == 0 && obj->id != 2) || obj->axis == 0 || obj->trans == 0 || obj->rot == 0)
		return (1);
	if (*objs)
	{
		tmp = *objs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
	}
	else
		*objs = obj;
	return (0);
}
