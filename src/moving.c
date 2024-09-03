/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:10:52 by clagarci          #+#    #+#             */
/*   Updated: 2024/09/03 13:14:52 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int key_handler(int keycode, t_vars *vars)
{
    if (keycode == D)
        vars->player.pos.x += 1;
    else if (keycode == A)
        vars->player.pos.x -= 1;
    else if (keycode == W)
        vars->player.pos.y -= 1;
    else if (keycode == S)
        vars->player.pos.y += 1;
    return (0);
}