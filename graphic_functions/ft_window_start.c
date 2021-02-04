/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:20:43 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/04 15:34:00 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_graphics.h"

/*
** FT_DEFINE_HOOKS
** This function defines all the key mappings (escape / window closing etc.)
*/

static void	ft_define_hooks(t_graph *graph)
{
	mlx_hook(graph->win_ptr, KEY_PRESS_EVENT, KEY_PRESS_MASK,
			ft_keys_binding, graph);
	mlx_hook(graph->win_ptr, DESTROY_EVENT, STRUCTURE_NOTIFY_MASK,
			ft_window_closed, graph);
}

/*
** FT_DRAW_BACKGROUND
** This function will redraw the background colors when called
*/

void		ft_draw_background(t_graph *graph, t_frame *frame)
{
	ft_draw_fsquare(frame->ceiling, graph, graph->c_trgb);
	ft_draw_fsquare(frame->floor, graph, graph->f_trgb);
}

/*
** FT_NEXT_FRAME
** This function clears the screen and draws everything needed to be drawn
** on the next frame
** 1) Background
** 2) Minimap
*/

void		ft_next_frame(t_graph *graph)
{
	mlx_clear_window(graph->mlx_ptr, graph->win_ptr);
	ft_draw_background(graph, graph->frame);
	ft_draw_minimap(graph);
	ft_draw_fcircle(graph->circle, graph, PLAYER_COLOR);
	mlx_put_image_to_window(graph->mlx_ptr,
							graph->win_ptr, graph->img_ptr->img, 0, 0);
}

/*
** FT_WINDOW_START
** This is the central hub of everything which is drawn on the screen
** This function calls all the other functions to produce the images
*/

t_graph		*ft_window_start(t_map *map)
{
	t_graph		*graph;

	graph = ft_new_t_graph(map);
	ft_next_frame(graph);
	ft_define_hooks(graph);
	mlx_loop(graph->mlx_ptr);
	return (0);
}
