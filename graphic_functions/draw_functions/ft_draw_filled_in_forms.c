/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_filled_in_forms.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:55:07 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/08 17:23:34 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** Draws the specified square with the specified colour
*/

void	ft_draw_fsquare(t_square *square, t_image *img_ptr, int trgb)
{
	double	x;
	double	y;

	x = square->x;
	y = square->y;
	while (x < square->x + square->width)
	{
		y = square->y;
		while (y < square->y + square->height)
		{
			my_mlx_pixel_put(img_ptr, x, y, trgb);
			y++;
		}
		x++;
	}
}

/*
** Draws the specified circle with the specified colour
*/

void	ft_draw_fcircle(t_circle *circle, t_image *img_ptr, int trgb)
{
	double	radius;
	double	i;
	double	j;
	double	dist;

	radius = circle->radius;
	i = circle->x - circle->radius;
	j = circle->y - circle->radius;
	dist = 0;
	while (i <= circle->x + radius)
	{
		j = circle->y - circle->radius;
		while (j++ <= circle->y + radius)
		{
			dist = sqrt(((i - circle->x) * (i - circle->x))
					+ ((j - circle->y) * (j - circle->y)));
			if (dist >= 0 && dist < (radius))
				my_mlx_pixel_put(img_ptr, i, j, trgb);
		}
		i++;
	}
}
