/* SPDX-License-Identifier: LGPL-2.1 */

/*
 * mtd-priv.h - Make Tax Digital
 *
 * Copyright (C) 2020	Andrew Clayton <andrew@digital-domain.net>
 */

#ifndef _MTD_PRIV_H_
#define _MTD_PRIV_H_

#define BASE_URL		"https://test-api.service.hmrc.gov.uk"

#define MTD_CONFIG_DIR_FMT	"%s/.config/libmtdac"
#define MTD_CONFIG_FMT		MTD_CONFIG_DIR_FMT "/%s"

enum app_conn_type {
	MTD_ACT_MOBILE_APP_DIRECT = 0,
	MTD_ACT_DESKTOP_APP_DIRECT,
	MTD_ACT_MOBILE_APP_VIA_SERVER,
	MTD_ACT_DESKTOP_APP_VIA_SERVER,
	MTD_ACT_WEB_APP_VIA_SERVER,
	MTD_ACT_BATCH_PROCESS_DIRECT,
	MTD_ACT_OTHER_DIRECT,
	MTD_ACT_OTHER_VIA_SERVER,
};


#endif /* _MTD_PRIV_H_ */
