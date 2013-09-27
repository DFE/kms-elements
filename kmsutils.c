/*
 * (C) Copyright 2013 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */
#include "kmsutils.h"

void
kms_utils_set_valve_drop (GstElement * valve, gboolean drop)
{
  GstPad *sink;
  gboolean old_drop;

  g_object_get (valve, "drop", &old_drop, NULL);
  if (drop == old_drop)
    return;

  sink = gst_element_get_static_pad (valve, "sink");

  GST_PAD_STREAM_LOCK (sink);
  g_object_set (valve, "drop", drop, NULL);
  GST_PAD_STREAM_UNLOCK (sink);

  g_object_unref (sink);
}

static gboolean
debug_graph (gpointer bin)
{
  GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS (GST_BIN (bin),
      GST_DEBUG_GRAPH_SHOW_ALL, GST_ELEMENT_NAME (bin));
  return FALSE;
}

void
kms_utils_debug_graph_delay (GstBin * bin, guint interval)
{
  g_timeout_add_seconds (interval, debug_graph, bin);
}
