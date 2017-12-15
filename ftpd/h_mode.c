/*
 * h_mode.c
 *
 * (C)2005-2011 by Marc Huber <Marc.Huber@web.de>
 * All rights reserved.
 *
 * $Id: h_mode.c,v 1.11 2015/03/14 06:11:25 marc Exp marc $
 *
 */

#include "headers.h"
#include <ctype.h>

static const char rcsid[] __attribute__ ((used)) = "$Id: h_mode.c,v 1.11 2015/03/14 06:11:25 marc Exp marc $";

void h_mode(struct context *ctx, char *arg)
{
    DebugIn(DEBUG_COMMAND);

#ifdef WITH_ZLIB
    if (ctx->allow_mode_z && tolower((int) *arg) == 'z') {
	ctx->mode = 'z';
	replyf(ctx, MSG_200_transfer_mode, "DEFLATE");
    } else
#endif
    if (tolower((int) *arg) == 's') {
	ctx->mode = 's';
	replyf(ctx, MSG_200_transfer_mode, "STREAM");
    } else
	reply(ctx, MSG_501_Unknown_transfer_mode);


    DebugOut(DEBUG_COMMAND);
}
