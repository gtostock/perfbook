/*
 * rcu_lock.c: simple user-level implementation of RCU based on locking.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Copyright (c) 2008 Paul E. McKenney, IBM Corporation.
 */

#include "../api.h"
#include "rcu_lock.h"

void synchronize_rcu(void)
{
	spin_lock(&rcu_gp_lock);
	spin_unlock(&rcu_gp_lock);
}

#ifdef TEST
#include "rcutorture.h"
#endif /* #ifdef TEST */
