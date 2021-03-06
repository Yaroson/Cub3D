/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:07:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/10 10:09:23 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** FT_TWO_POINTS_DISTANCE
** This function returns a distance between two points
*/

double	ft_two_points_distance(double a_x, double a_y, double b_x, double b_y)
{
	return (sqrt(((b_x - a_x) * (b_x - a_x)) + ((b_y - a_y) * (b_y - a_y))));
}
