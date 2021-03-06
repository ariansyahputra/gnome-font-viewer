/* -*- mode: C; c-basic-offset: 4 -*-
 * gnome-font-viewer
 *
 * Copyright (C) 2012 Cosimo Cecchi <cosimoc@gnome.org>
 *
 * based on font-method.c code from
 *
 * fontilus - a collection of font utilities for GNOME
 * Copyright (C) 2002-2003  James Henstridge <james@daa.com.au>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __FONT_VIEW_MODEL_H__
#define __FONT_VIEW_MODEL_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef enum {
  COLUMN_NAME,
  COLUMN_PATH,
  COLUMN_FACE_INDEX,
  COLUMN_ICON,
  COLUMN_COLLATION_KEY,
  NUM_COLUMNS
} FontViewModelColumns;

#define FONT_VIEW_TYPE_MODEL (font_view_model_get_type ())

G_DECLARE_FINAL_TYPE (FontViewModel, font_view_model,
                      FONT_VIEW, MODEL,
                      GtkListStore)

GType font_view_model_get_type (void);

GtkTreeModel * font_view_model_new (void);

gboolean font_view_model_get_iter_for_face (FontViewModel *self,
                                            FT_Face        face,
                                            GtkTreeIter   *iter);

void     font_view_model_set_scale_factor  (FontViewModel *self,
                                            gint           scale_factor);

G_END_DECLS

#endif /* __FONT_VIEW_MODEL_H__ */
