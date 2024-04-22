/*
 *
 * FocalTech fts TouchScreen driver.
 *
 * Copyright (c) 2012-2020, Focaltech Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

/*****************************************************************************
*
* File Name: focaltech_upgrade_ft3418.c
*
* Author: Focaltech Driver Team
*
* Created: 2016-08-15
*
* Abstract:
*
* Reference:
*
*****************************************************************************/
/*****************************************************************************
* 1.Included header files
*****************************************************************************/
#include "focaltech_flash.h"

/*****************************************************************************
* Private constant and macro definitions using #define
*****************************************************************************/
/************************************************************************
* Name: fts_ft3418_upgrade
* Brief:
* Input:
* Output:
* Return: return 0 if success, otherwise return error code
***********************************************************************/
static int fts_ft3418_upgrade(u8 *buf, u32 len)
{
	int ret = 0;
	u32 start_addr = 0;
	u8 cmd[4] = { 0 };
	int ecc_in_host = 0;
	int ecc_in_tp = 0;
	int i = 0;
	u8 wbuf[7] = { 0 };
	u8 reg_val[4] = {0};

	if ((NULL == buf) || (len < FTS_MIN_LEN)) {
		FTS_ERROR("buffer/len(%x) is invalid", len);
		return -EINVAL;
	}

	/* enter into upgrade environment */
	ret = fts_fwupg_enter_into_boot();
	if (ret < 0) {
		FTS_ERROR("enter into pramboot/bootloader fail,ret=%d", ret);
		goto fw_reset;
	}

	cmd[0] = FTS_CMD_FLASH_MODE;
	cmd[1] = FLASH_MODE_UPGRADE_VALUE;
	ret = fts_write(cmd, 2);
	if (ret < 0) {
		FTS_ERROR("upgrade mode(09) cmd write fail");
		goto fw_reset;
	}

	cmd[0] = FTS_CMD_DATA_LEN;
	cmd[1] = BYTE_OFF_16(len);
	cmd[2] = BYTE_OFF_8(len);
	cmd[3] = BYTE_OFF_0(len);
	ret = fts_write(cmd, FTS_CMD_DATA_LEN_LEN);
	if (ret < 0) {
		FTS_ERROR("data len cmd write fail");
		goto fw_reset;
	}

	ret = fts_fwupg_erase(FTS_REASE_APP_DELAY);
	if (ret < 0) {
		FTS_ERROR("erase cmd write fail");
		goto fw_reset;
	}

	/* write app */
	start_addr = upgrade_func_ft3418.appoff;
	ecc_in_host = fts_flash_write_buf(start_addr, buf, len, 1);
	if (ecc_in_host < 0 ) {
		FTS_ERROR("flash write fail");
		goto fw_reset;
	}

	FTS_INFO( "**********read out checksum**********");

	/* check sum init */
	wbuf[0] = FTS_CMD_ECC_INIT;
	ret = fts_write(wbuf, 1);
	if (ret < 0) {
		FTS_ERROR("ecc init cmd write fail");
		return ret;
	}

	/* send commond to start checksum */
	wbuf[0] = FTS_CMD_ECC_CAL;
	wbuf[1] = BYTE_OFF_16(start_addr);
	wbuf[2] = BYTE_OFF_8(start_addr);
	wbuf[3] = BYTE_OFF_0(start_addr);

	wbuf[4] = BYTE_OFF_16(len);
	wbuf[5] = BYTE_OFF_8(len);
	wbuf[6] = BYTE_OFF_0(len);

	FTS_DEBUG("ecc calc startaddr:0x%04x, len:%d", start_addr, len);
	ret = fts_write(wbuf, 7);
	if (ret < 0) {
		FTS_ERROR("ecc calc cmd write fail");
		return ret;
	}

	sec_delay(len / 256);

	/* read status if check sum is finished */
	for (i = 0; i < FTS_RETRIES_ECC_CAL; i++) {
		wbuf[0] = FTS_CMD_FLASH_STATUS;
		reg_val[0] = reg_val[1] = 0x00;
		fts_read(wbuf, 1, reg_val, 2);
		FTS_DEBUG("[UPGRADE]: reg_val[0]=%02x reg_val[0]=%02x!!", reg_val[0], reg_val[1]);
		if ((0xF0 == reg_val[0]) && (0x55 == reg_val[1])) {
			break;
		}
		sec_delay(FTS_RETRIES_DELAY_ECC_CAL);
	}

	/* read out check sum */
	wbuf[0] = FTS_CMD_ECC_READ;
	ret = fts_read(wbuf, 1, reg_val, 1);
	if (ret < 0) {
		FTS_ERROR( "ecc read cmd write fail");
		return ret;
	}
	ecc_in_tp = reg_val[0];

	FTS_INFO("ecc in tp:%x, host:%x", ecc_in_tp, ecc_in_host);
	if (ecc_in_tp != ecc_in_host) {
		FTS_ERROR("ecc check fail");
		goto fw_reset;
	}

	FTS_INFO("upgrade success, reset to normal boot");
	ret = fts_fwupg_reset_in_boot();
	if (ret < 0) {
		FTS_ERROR("reset to normal boot fail");
	}

	sec_delay(200);
	return 0;

fw_reset:
	FTS_INFO("upgrade fail, reset to normal boot");
	ret = fts_fwupg_reset_in_boot();
	if (ret < 0) {
		FTS_ERROR("reset to normal boot fail");
	}
	return -EIO;
}

static int fts_upgrade_with_cmd62(u32 saddr, u8 *buf, u32 len)
{
	int ret;
	int ecc_in_host;
	int ecc_in_tp;
	int i;
	u8 wbuf[7] = { 0 };
	u8 reg_val[4] = {0};
	u32 erase_addr = 0x1e000;

	wbuf[0] = FTS_CMD_FLASH_MODE;
	wbuf[1] = FLASH_MODE_WRITE_FLASH_VALUE;
	ret = fts_write(wbuf, 2);
	if (ret < 0) {
		FTS_ERROR("upgrade mode(09) cmd write fail");
		return ret;
	}

	FTS_INFO("start address:%x", saddr);
	wbuf[0] = 0x62;
	wbuf[1] = BYTE_OFF_16(erase_addr);
	wbuf[2] = BYTE_OFF_8(erase_addr);
	wbuf[3] = BYTE_OFF_0(erase_addr);
	wbuf[4] = BYTE_OFF_16(len);
	wbuf[5] = BYTE_OFF_8(len);
	wbuf[6] = BYTE_OFF_0(len);
	ret = fts_write(&wbuf[0], 7);
	if (ret < 0) {
		FTS_ERROR("erase cmd fail");
		return ret;
	}
	sec_delay(100);

	for (i = 0; i < FTS_RETRIES_REASE; i++) {
		wbuf[0] = FTS_CMD_FLASH_STATUS;
		reg_val[0] = reg_val[1] = 0x00;
		fts_read(wbuf, 1, reg_val, 2);
		if ((0xF0 == reg_val[0]) && (0xAA == reg_val[1])) {
			break;
		} else {
			FTS_DEBUG("flash status fail,read:0x%02x%02x,ok:%04x,retries:%d", reg_val[0],
						reg_val[1], 0xF0AA, i);
		}
		sec_delay(FTS_RETRIES_DELAY_REASE);
	}

	/* write app */
	ecc_in_host = fts_flash_write_buf(saddr, buf, len, 1);
	if (ecc_in_host < 0) {
		FTS_ERROR("flash write fail");
		return -EIO;
	}

	FTS_INFO("**********read out checksum**********");

	/* check sum init */
	wbuf[0] = FTS_CMD_ECC_INIT;
	ret = fts_write(wbuf, 1);
	if (ret < 0) {
		FTS_ERROR("ecc init cmd write fail");
		return ret;
	}

	/* send commond to start checksum */
	wbuf[0] = FTS_CMD_ECC_CAL;
	wbuf[1] = BYTE_OFF_16(saddr);
	wbuf[2] = BYTE_OFF_8(saddr);
	wbuf[3] = BYTE_OFF_0(saddr);

	wbuf[4] = BYTE_OFF_16(len);
	wbuf[5] = BYTE_OFF_8(len);
	wbuf[6] = BYTE_OFF_0(len);

	FTS_DEBUG("ecc calc startaddr:0x%04x, len:%d", saddr, len);
	ret = fts_write(wbuf, 7);
	if (ret < 0) {
		FTS_ERROR("ecc calc cmd write fail");
		return ret;
	}

	sec_delay(len / 256);

	/* read status if check sum is finished */
	for (i = 0; i < FTS_RETRIES_ECC_CAL; i++) {
		wbuf[0] = FTS_CMD_FLASH_STATUS;
		reg_val[0] = reg_val[1] = 0x00;
		fts_read(wbuf, 1, reg_val, 2);
		FTS_DEBUG("[UPGRADE]: reg_val[0]=%02x reg_val[0]=%02x!!", reg_val[0], reg_val[1]);
		if ((0xF0 == reg_val[0]) && (0x55 == reg_val[1])) {
			break;
		}
		sec_delay(FTS_RETRIES_DELAY_ECC_CAL);
	}

	/* read out check sum */
	wbuf[0] = FTS_CMD_ECC_READ;
	ret = fts_read(wbuf, 1, reg_val, 1);
	if (ret < 0) {
		FTS_ERROR("ecc read cmd write fail");
		return ret;
	}
	ecc_in_tp = reg_val[0];

	FTS_INFO("ecc in tp:%x, host:%x", ecc_in_tp, ecc_in_host);
	if (ecc_in_tp != ecc_in_host) {
		FTS_ERROR("ecc check fail");
		return -EIO;
	}

	return 0;
}

int fts_write_cnt_info(u16 cnt)
{
	int ret = 0;
	u8 data[2] = {0};

	data[0] = (cnt >> 8) & 0xFF;
	data[1] = (u8)cnt;
	ret = fts_fwupg_enter_into_boot();
	if (ret < 0) {
		FTS_ERROR("enter into pramboot/bootloader fail,ret=%d", ret);
		goto fw_reset;
	}
	ret = fts_upgrade_with_cmd62(0x1E010, data, 2);
	if (ret < 0) {
		FTS_ERROR("fts_upgrade_lockdown fails");
		goto fw_reset;
	}
	ret = fts_fwupg_reset_in_boot();
	if (ret < 0) {
		FTS_ERROR("reset to normal boot fail");
	}

	sec_delay(200);
	return 0;

fw_reset:
	FTS_INFO("upgrade fail, reset to normal boot");
	ret = fts_fwupg_reset_in_boot();
	if (ret < 0) {
		FTS_ERROR("reset to normal boot fail");
	}
	return -EIO;
}

int fts_read_cnt_info(u16 *cnt)
{
	u8 data[2] = {0};

	fts_flash_read(0x1E010, data, 2);

	*cnt = (data[0] << 8) + data[1];

	return 0;
}

struct upgrade_func upgrade_func_ft3418 = {
	.ctype = {0x81},
	.fwveroff = 0x010E,
	.fwcfgoff = 0x1FFB0,
	.appoff = 0x0000,
	.pram_ecc_check_mode = ECC_CHECK_MODE_XOR,
	.pramboot_supported = false,
	.hid_supported = true,
	.upgrade = fts_ft3418_upgrade,
};