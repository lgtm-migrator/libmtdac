/* SPDX-License-Identifier: LGPL-2.1 */

/*
 * mtd-saac.c - Make Tax Digital - Self Assessment Accounts API
 *
 * Copyright (C) 2020		Andrew Clayton <andrew@digital-domain.net>
 */

#include <stdio.h>

#include "mtd-saac.h"
#include "endpoints.h"
#include "mtd-curl.h"

#define API_VER			"Accept: application/vnd.hmrc.1.0+json"

/*
 * [GET ]
 * /accounts/self-assessment/{nino}/payments/{paymentId}
 */
int mtd_saac_get_payment(const char *pyid, char **buf)
{
	struct curl_ctx ctx = { 0 };
	const char *params[1] = { pyid };

	ctx.mtd_api_ver = API_VER;
	ctx.endpoint = SAAC_GET_PAYMENT;
	ctx.params = params;

	return do_get(&ctx, buf);
}

/*
 * [GET ]
 * /accounts/self-assessment/{nino}/payments?from=YYYY-MM-DD&to=YYYY-MM_DD
 */
int mtd_saac_list_payments(const char *from, const char *to, char **buf)
{
	struct curl_ctx ctx = { 0 };
	const char *params[1];
	char query_string[64];

	ctx.mtd_api_ver = API_VER;
	ctx.endpoint = SAAC_LIST_PAYMENTS;

	snprintf(query_string, sizeof(query_string), "?from=%s&to=%s",
		 from, to);
	params[0] = query_string;
	ctx.params = params;

	return do_get(&ctx, buf);
}

/*
 * [GET ]
 * /accounts/self-assessment/{nino}/charges/{transactionId}
 */
int mtd_saac_get_charge(const char *trid, char **buf)
{
	struct curl_ctx ctx = { 0 };
	const char *params[1] = { trid };

	ctx.mtd_api_ver = API_VER;
	ctx.endpoint = SAAC_GET_CHARGE;
	ctx.params = params;

	return do_get(&ctx, buf);
}

/*
 * [GET ]
 * /accounts/self-assessment/{nino}/charges?from=YYYY-MM-DD&to=YYYY-MM_DD
 */
int mtd_saac_list_charges(const char *from, const char *to, char **buf)
{
	struct curl_ctx ctx = { 0 };
	const char *params[1];
	char query_string[64];

	ctx.mtd_api_ver = API_VER;
	ctx.endpoint = SAAC_LIST_CHARGES;

	snprintf(query_string, sizeof(query_string), "?from=%s&to=%s",
		 from, to);
	params[0] = query_string;
	ctx.params = params;

	return do_get(&ctx, buf);
}

/*
 * [GET ]
 * /accounts/self-assessment/{nino}/transactions/{transactionId}
 */
int mtd_saac_get_transaction(const char *trid, char **buf)
{
	struct curl_ctx ctx = { 0 };
	const char *params[1] = { trid };

	ctx.mtd_api_ver = API_VER;
	ctx.endpoint = SAAC_GET_TRANSACTION;
	ctx.params = params;

	return do_get(&ctx, buf);
}

/*
 * [GET ]
 * /accounts/self-assessment/{nino}/transactions?from=YYYY-MM-DD&to=YYYY-MM_DD
 */
int mtd_saac_list_transactions(const char *from, const char *to, char **buf)
{
	struct curl_ctx ctx = { 0 };
	const char *params[1];
	char query_string[64];

	ctx.mtd_api_ver = API_VER;
	ctx.endpoint = SAAC_LIST_TRANSACTIONS;

	snprintf(query_string, sizeof(query_string), "?from=%s&to=%s",
		 from, to);
	params[0] = query_string;
	ctx.params = params;

	return do_get(&ctx, buf);
}

/*
 * [GET ]
 * /accounts/self-assessment/{nino}/balance
 */
int mtd_saac_get_balance(char **buf)
{
	struct curl_ctx ctx = { 0 };

	ctx.mtd_api_ver = API_VER;
	ctx.endpoint = SAAC_GET_BALANCE;

	return do_get(&ctx, buf);
}
