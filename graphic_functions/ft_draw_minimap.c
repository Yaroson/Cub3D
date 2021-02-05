/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:57:30 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/05 14:31:48 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_DRAW_MINIMAP_BACKGROUND
** This function will draw the background of the minimap as a square
*/

void		ft_draw_minimap_background(t_graph *graph)
{
	double x;
	double y;
	double width;
	double height;

	x = graph->frame->minimap_background->x;
	y = graph->frame->minimap_background->y;
	width = graph->frame->minimap_background->width;
	height = graph->frame->minimap_background->height;
	ft_draw_fsquare(&(t_square){x, y, width, height},
					graph->img_ptr, MAP_BACKGROUND_COLOR);
}

/*
** FT_DRAW_WALLS
** This function is used to draw the walls of the minimap
*/

static void	ft_draw_minimap_walls(t_graph *graph, char **str_tab, double width)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	j = -1;
	x = 0;
	y = -graph->frame->units;
	while (str_tab[++i])
	{
		j = -1;
		x = 0;
		y += graph->frame->units;
		while (str_tab[i][++j])
		{
			if (str_tab[i][j] == '1')
				ft_draw_fsquare(&(t_square){x, y, width, width},
											graph->img_ptr, WALL_COLOR);
			else if (str_tab[i][j] == '2')
				ft_draw_fsquare(&(t_square){x, y, width, width},
											graph->img_ptr, SPRITE_COLOR);
			x += graph->frame->units;
		}
	}
}

/*
** FT_DRAW_MINIMAP
** This function is the central hub of drawing the minimap
** and determining the needed size
** Draws the background first as a rectangle, then the walls
*/

void		ft_draw_minimap(t_graph *graph)
{
	ft_draw_minimap_background(graph);
	ft_draw_minimap_walls(graph, graph->map->map_str_tab,
							graph->frame->minimap_wall->width);
	if (!graph->circle)
	{
		graph->circle = ft_new_circle((graph->map->player_x *
										graph->frame->units)
								+ graph->frame->units / 2,
					(graph->map->player_y * graph->frame->units)
			+ graph->frame->units / 2, graph->frame->units / 2, 0);
	}
}
