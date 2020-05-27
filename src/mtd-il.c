/* SPDX-License-Identifier: LGPL-2.1 */

/*
 * mtd-il.c - Make Tax Digital - Individual Loses API
 *
 * Copyright (C) 2020		Andrew Clayton <andrew@digital-domain.net>
 */

#include <stddef.h>

#include "mtd-il.h"		/* for default (public) visibility */
#include "endpoints.h"

#define API_VER			"Accept: application/vnd.hmrc.1.0+json"

/*
 * [PUT ]
 * /individuals/losses/{nino}/loss-claims/order
 */
int mtd_il_lc_update_loss_order(const char *src_file, char **buf)
{
	return do_ep(IL_LC_UPDATE_LOSS_ORDER, API_VER,
		     src_file, NULL, buf, (char *)NULL);
}

/*
 * [POST]
 * /individuals/losses/{nino}/loss-claims/{claimId}/change-type-of-claim
 */
int mtd_il_lc_update_loss_type(const char *src_file, const char *cid,
			       char **buf)
{
	return do_ep(IL_LC_UPDATE_LOSS_TYPE, API_VER,
		     src_file, NULL, buf, cid, (char *)NULL);
}

/*
 * [DELETE]
 * /individuals/losses/{nino}/loss-claims/{claimId}
 */
int mtd_il_lc_delete_loss(const char *cid, char **buf)
{
	return do_ep(IL_LC_DELETE_LOSS, API_VER,
		     NULL, NULL, buf, cid, (char *)NULL);
}

/*
 * [GET ]
 * /individuals/losses/{nino}/loss-claims/{claimId}
 */
int mtd_il_lc_get_loss(const char *cid, char **buf)
{
	return do_ep(IL_LC_GET_LOSS, API_VER,
		     NULL, NULL, buf, cid, (char *)NULL);
}

/*
 * [POST]
 * /individuals/losses/{nino}/loss-claims
 */
int mtd_il_lc_create_loss(const char *src_file, char **buf)
{
	return do_ep(IL_LC_CREATE_LOSS, API_VER,
		     src_file, NULL, buf, (char *)NULL);
}

/*
 * [GET ]
 * /individuals/losses/{nino}/loss-claims
 *
 * Optional query string:
 *
 *	?selfEmploymentId=&taxYear=YYYY-YY&typeOfLoss=&claimType=carry-sideways
 *
 *	typeOfLoss={self-employment,uk-property-fhl,uk-property-non-fhl}
 */
int mtd_il_lc_list_loses(const char *query_string, char **buf)
{
	return do_ep(IL_LC_LIST_LOSES, API_VER,
		     NULL, NULL, buf, query_string, (char *)NULL);
}

/*
 * [POST]
 * /individuals/losses/{nino}/brought-forward-losses/{lossId}/change-loss-amount
 */
int mtd_il_bf_update_loss_amnt(const char *src_file, const char *lid,
			       char **buf)
{
	return do_ep(IL_BF_UPDATE_LOSS_AMNT, API_VER,
		     src_file, NULL, buf, lid, (char *)NULL);
}

/*
 * [DELETE]
 * /individuals/losses/{nino}/brought-forward-losses/{lossId}
 */
int mtd_il_bf_delete_loss(const char *lid, char **buf)
{
	return do_ep(IL_BF_DELETE_LOSS, API_VER,
		     NULL, NULL, buf, lid, (char *)NULL);
}

/*
 * [GET ]
 * /individuals/losses/{nino}/brought-forward-losses/{lossId}
 */
int mtd_il_bf_get_loss(const char *lid, char **buf)
{
	return do_ep(IL_BF_GET_LOSS, API_VER,
		     NULL, NULL, buf, lid, (char *)NULL);
}

/*
 * [POST]
 * /individuals/losses/{nino}/brought-forward-losses
 */
int mtd_il_bf_create_loss(const char *src_file, char **buf)
{
	return do_ep(IL_BF_CREATE_LOSS, API_VER,
		     src_file, NULL, buf, (char *)NULL);
}

/*
 * [GET ]
 * /individuals/losses/{nino}/brought-forward-losses
 *
 * Optional query string:
 *
 *	?selfEmploymentId=&taxYear=YYYY-YY&typeOfLoss=
 *
 *	typeOfLoss={self-employment,uk-property-fhl,uk-property-non-fhl}
 */
int mtd_il_bf_list_loses(const char *query_string, char **buf)
{
	return do_ep(IL_BF_LIST_LOSES, API_VER,
		     NULL, NULL, buf, query_string, (char *)NULL);
}
