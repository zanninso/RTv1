/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_property.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:10:12 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/02/24 02:18:15 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void *get_obj_property(t_obj *obj, char *property, int *p_type)
{
    if (ft_strequ(property, "origin") && (*p_type = 1))
        return(&obj->o);
    else  if (ft_strequ(property, "color") && (*p_type = 1))
        return(&obj->color);
    if (ft_strequ(property, "axis") && (*p_type = 1))
        return(&obj->axis);
    else  if (ft_strequ(property, "translation") && (*p_type = 1))
        return(&obj->trans);
    if (ft_strequ(property, "rotation") && (*p_type = 1))
        return(&obj->rot);
    else  if (ft_strequ(property, "ray") && (*p_type = 2))
        return(&obj->r);
    return(NULL);
}

static void *get_light_property(t_light *light, char *property, int *p_type)
{
    if (ft_strequ(property, "origin") && (*p_type = 1))
        return(&light->o);
    else  if (ft_strequ(property, "color") && (*p_type = 1))
        return(&light->color);
    else  if (ft_strequ(property, "power") && (*p_type = 2))
        return(&light->power);
    return(NULL);
}

static void *get_cam_property(t_cam *cam, char *property, int *p_type)
{
    if (ft_strequ(property, "origin") && (*p_type = 1))
        return(&cam->o);
    else  if (ft_strequ(property, "target") && (*p_type = 1))
        return(&cam->target);
    else  if (ft_strequ(property, "fov") && (*p_type = 2))
        return(&cam->fov);
    return(NULL);
}

static char *parse_vector(t_vector *vec, char *line)
{
    vec->x = ft_atoi(line);
    if (!(line = ft_strchr(line, ',')))
        return(NULL);
    vec->y = ft_atoi(line + 1);
    if (!(line = ft_strchr(line + 1, ',')))
        return (NULL);
    line++;
    vec->z = ft_atoi(line);
    ft_strchr("+-", *line) ? line++ : 0;
    return (ft_skip_chars(line, "0123456789", NULL));
}

char *parse_property(void *obj, char *line, int o_type)
{
    int p_type;
    void *prop;

    o_type == 0 ? (prop = get_cam_property(obj, line, &p_type)) : 0;
    o_type == 1 ? (prop = get_light_property(obj, line, &p_type)) : 0;
    o_type == 2 ? (prop = get_obj_property(obj, line, &p_type)) : 0;
    line  = ft_skip_chars(line + ft_strlen(line) + 1, " ", NULL);
    if (!prop)
        return (NULL);
    if (p_type == 1)
        return(parse_vector(prop, line));
    *((double *)prop) = ft_atoi(line);
    ft_strchr("+-", *line) ? line++ : 0;
    return (ft_skip_chars(line, "0123456789", NULL));
}