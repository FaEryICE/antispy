/* 
 * Copyright (c) [2010-2019] zhenfei.mzf@gmail.com rights reserved.
 * 
 * AntiSpy is licensed under the Mulan PSL v1.
 * You can use this software according to the terms and conditions of the Mulan PSL v1.
 * You may obtain a copy of Mulan PSL v1 at:
 *
 *     http://license.coscl.org.cn/MulanPSL
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR
 * FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v1 for more details.
*/
/*
 * attrlist.h - Exports for attribute list attribute handling.  
 * 		Originated from Linux-NTFS project.
 *
 * Copyright (c) 2004 Anton Altaparmakov
 * Copyright (c) 2004 Yura Pakhuchiy
 *
 * This program/include file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program/include file is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (in the main directory of the NTFS-3G
 * distribution in the file COPYING); if not, write to the Free Software
 * Foundation,Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _NTFS_ATTRLIST_H
#define _NTFS_ATTRLIST_H

#include "attrib.h"

extern int ntfs_attrlist_need(ntfs_inode *ni);

extern int ntfs_attrlist_entry_add(ntfs_inode *ni, ATTR_RECORD *attr);
extern int ntfs_attrlist_entry_rm(ntfs_attr_search_ctx *ctx);

/**
 * ntfs_attrlist_mark_dirty - set the attribute list dirty
 * @ni:		ntfs inode which base inode contain dirty attribute list
 *
 * Set the attribute list dirty so it is written out later (at the latest at
 * ntfs_inode_close() time).
 *
 * This function cannot fail.
 */
static void ntfs_attrlist_mark_dirty(ntfs_inode *ni)
{
	if (ni->nr_extents == -1)
		NInoAttrListSetDirty(ni->base_ni);
	else
		NInoAttrListSetDirty(ni);
}

#endif /* defined _NTFS_ATTRLIST_H */