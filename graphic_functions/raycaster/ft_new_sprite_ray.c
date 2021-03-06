/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:18 by ysoroko           #+#    #+#             */
/*   Updated: 2021/02/26 13:51:06 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_graphics.h"

/*
** FT_SORT_SPRITES_TAB
** This function is used to sort the seen sprites based on the distance
** The furthest sprites are put first so that they are drawn first
** The array component of t_sprite_ray which is sorted is sprite_order
*/

void			ft_sort_sprites_tab(int *spr_order,
											double *spr_dist, int n_spr)
{
	int		i;
	int		j;
	double	d_temp;
	int		i_temp;

	i = -1;
	while (++i < n_spr)
	{
		j = -1;
		while (++j < (n_spr - 1))
		{
			if (spr_dist[j] < spr_dist[j + 1])
			{
				d_temp = spr_dist[j];
				spr_dist[j] = spr_dist[j + 1];
				spr_dist[j + 1] = d_temp;
				i_temp = spr_order[j];
				spr_order[j] = spr_order[j + 1];
				spr_order[j + 1] = i_temp;
			}
		}
	}
}

/*
** FT_NEW_SPRITE
** Used to create a new t_sprite structure
*/

static t_sprite	*ft_new_sprite(int x, int y, char texture_sprite)
{
	t_sprite *ret;

	if (!(ret = malloc(sizeof(t_sprite))))
		ft_malloc_fail();
	ret->x = (double)x + 0.5;
	ret->y = (double)y + 0.5;
	ret->texture_sprite = texture_sprite;
	return (ret);
}

/*
** FT_SPRITES_FROM_MAP_TO_ARRAY
** This function checks the map and stores sprites' positions
** and related sprites in an array
** Returns the created array
*/

static t_sprite	**ft_sprites_from_map_to_array(char **map, int n_sprites)
{
	int			i;
	int			j;
	int			k;
	t_sprite	**sprite_array;

	if (!(sprite_array = malloc(sizeof(t_sprite) * (n_sprites))))
		ft_malloc_fail();
	i = -1;
	k = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '2' || map[i][j] == '3' || map[i][j] == '5')
				sprite_array[++k] = ft_new_sprite(i, j, map[i][j]);
		}
	}
	return (sprite_array);
}

static int		ft_n_sprites(char **map)
{
	int n_sprites;

	n_sprites = ft_n_chars_in_str_tab(map, '2');
	if (BONUS == 1)
	{
		n_sprites += ft_n_chars_in_str_tab(map, '3');
		n_sprites += ft_n_chars_in_str_tab(map, '5');
	}
	return (n_sprites);
}

/*
** FT_NEW_SPRITE_RAY
** Used to initialize a bew t_ray data structure
*/

t_sprite_ray	*ft_new_sprite_ray(char **map, t_ray *ray)
{
	int				n_sprites;
	t_sprite_ray	*sprite_ray;

	n_sprites = ft_n_sprites(map);
	if (!(sprite_ray = malloc(sizeof(*sprite_ray))))
		ft_malloc_fail();
	sprite_ray->num_sprites = n_sprites;
	sprite_ray->sprite_array = ft_sprites_from_map_to_array(map, n_sprites);
	if (!(sprite_ray->z_buffer = malloc(sizeof(double) * ray->res->x)))
		ft_malloc_fail();
	if (!(sprite_ray->sprite_order = malloc(sizeof(int) * n_sprites)))
		ft_malloc_fail();
	if (!(sprite_ray->sprite_distance = malloc(sizeof(double) * n_sprites)))
		ft_malloc_fail();
	sprite_ray->spr = ft_new_point(0, 0);
	sprite_ray->inv_det = 0;
	sprite_ray->transform = ft_new_point(0, 0);
	sprite_ray->sprite_screen_x = 0;
	sprite_ray->draw_start = ft_new_point(0, 0);
	sprite_ray->draw_end = ft_new_point(0, 0);
	sprite_ray->sprite_width = 0;
	sprite_ray->sprite_height = 0;
	sprite_ray->tex = ft_new_point(0, 0);
	sprite_ray->texture_size = ft_new_point(SPRITE_W, SPRITE_H);
	return (sprite_ray);
}
