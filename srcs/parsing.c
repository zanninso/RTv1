// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parsing.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: anabaoui <anabaoui@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/02/06 03:34:49 by anabaoui          #+#    #+#             */
// /*   Updated: 2020/02/06 04:45:56 by anabaoui         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "rtv1.h"

int	free_tab(char **t)
{
	int	i;

	if (!t)
		return (0);
	i = -1;
	while (t[++i])
		ft_memdel((void **)&t[i]);
	ft_memdel((void **)t);
	return (0);
}

t_vector	*check_vector(char *str)
{
	t_vector		*v;
	char			**t;

	if (!str || (str[0] != '(') || (str[ft_strlen(str) - 1] != ')'))
		return (0);
	str++;
	str[ft_strlen(str) - 1] = '\0';

	v = malloc(sizeof(t_vector));
	if (!(t = ft_strsplit(str, ',')))
		return (0);
	if (t[0] && !ft_is_number(t[0]))
	{
		v->x = ft_atof(t[0]);

		if (t[1] && !ft_is_number(t[1]))
		{
			v->y = ft_atof(t[1]);
			if (t[2] && !ft_is_number(t[2]))
			{
				v->z = ft_atof(t[2]);
				if (t[3])
					return (0);
				return (v);
			}
		}
	}
	return (0);
}

int	check_object(char *str)
{
	if (!str || str[0] != '(' || str[ft_strlen(str) - 1] != ')')
		return (-1);
	str++;
	str[ft_strlen(str) - 1] = '\0';
	if (!ft_strcmp(str, "camera"))
		return (1);
	if (!ft_strcmp(str, "light"))
		return (2);
	if (!ft_strcmp(str, "cone"))
		return (3);
	if (!ft_strcmp(str, "plane"))
		return (4);
	if (!ft_strcmp(str, "sphere"))
		return (5);
	if (!ft_strcmp(str, "cylinder"))
		return (6);
	return (-1);
}

int	check_parse(t_var *v, char *line)
{
	int		i;
	int		id;
	char	**t;

	i = 0;
	if (!(t = ft_strsplit(line, ' ')))
		return (1);
	while (t[i])
	{
		if (!ft_strcmp("object", t[i]))
		{
			i++;
			if ((id = check_object(t[i])) == -1)
				return (1);
			if (id == 1)
			{
				if (save_camera(&(v->cam), t))
					return (1);
			}
			else if (id == 2)
			{
				if (save_lights(&(v->light), t))
					return (1);
			}
			else if (save_objects(&(v->obj), t, id))
				return (1);
		}
		i++;
	}
	return (0);
}

int	parse(char *file, t_var *v)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	v->cam = 0;
	v->obj = 0;
	v->light = 0;
	while (get_next_line(fd, &line))
		if ((check_parse(v, line)))
			return (1);
	if (v->cam == 0 || v->obj == 0 || v->light == 0)
		return (1);
	return (0);
}