// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   textures.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/02/06 15:56:46 by dwulfe            #+#    #+#             */
// /*   Updated: 2022/02/18 13:22:28 by dwulfe           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../render.h"

// void	sort_order(t_pair *orders, int amount)
// {
// 	t_pair	tmp;

// 	for (int i = 0; i < amount; i++)
// 	{
// 		for (int j = 0; j < amount - 1; j++)
// 		{
// 			if (orders[j].first > orders[j + 1].first)
// 			{
// 				tmp.first = orders[j].first;
// 				tmp.second = orders[j].second;
// 				orders[j].first = orders[j + 1].first;
// 				orders[j].second = orders[j + 1].second;
// 				orders[j + 1].first = tmp.first;
// 				orders[j + 1].second = tmp.second;
// 			}
// 		}
// 	}
// }

// void	sortSprites(int *order, double *dist, int amount)
// {
// 	t_pair	*sprites;

// 	//std::vector<std::pair<double, int>> sprites(amount);
// 	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
// 	for (int i = 0; i < amount; i++)
// 	{
// 		sprites[i].first = dist[i];
// 		sprites[i].second = order[i];
// 	}
// 	sort_order(sprites, amount);
// 	//std::sort(sprites.begin(), sprites.end());
// 	for (int i = 0; i < amount; i++)
// 	{
// 		dist[i] = sprites[amount - i - 1].first;
// 		order[i] = sprites[amount - i - 1].second;
// 	}
// 	free(sprites);
// }

// void	textures(t_data *d)
// {
// 	//SPRITE CASTING
// 	//sort sprites from far to close
// 	for(int i = 0; i < d->numSprites; i++)
// 	{
// 		spriteOrder[i] = i;
// 		spriteDistance[i] = ((info->posX - sprite[i].x) * (info->posX - sprite[i].x) + (info->posY - sprite[i].y) * (info->posY - sprite[i].y)); //sqrt not taken, unneeded
// 	}
// 	sortSprites(spriteOrder, spriteDistance, numSprites);
// 	//after sorting the sprites, do the projection and draw them
// 	for(int i = 0; i < numSprites; i++)
// }
