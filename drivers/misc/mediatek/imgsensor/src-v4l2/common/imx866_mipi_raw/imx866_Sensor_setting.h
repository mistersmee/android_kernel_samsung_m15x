/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */
/*****************************************************************************
 *
 * Filename:
 * ---------
 *	 imx866_Sensor_setting.h
 *
 * Project:
 * --------
 * Description:
 * ------------
 *	 CMOS sensor header file
 *
 ****************************************************************************/
#ifndef _IMX866_SENSOR_SETTING_H
#define _IMX866_SENSOR_SETTING_H

#include "kd_camera_typedef.h"

// NOTE:
// for 2 exp setting,  VCID of LE/SE should be 0x00 and 0x02
// which align 3 exp setting LE/NE/SE 0x00,  0x01,  0x02
// to seamless switch,  VC ID of SE should remain the same
// SONY sensor: VCID of 2nd frame at 0x3070; VCID of 3rd frame at 0x3080
// must be two different value

static kal_uint16 imx866_init_setting[] = {
	0x0136, 0x18,
	0x0137, 0x00,
	0x3304, 0x00,
	0x33F0, 0x01,
	0x33F1, 0x05,
	0x0111, 0x03,
	0x309E, 0x02,
	0x30B0, 0x03,
	0x3379, 0x00,
	0x86A9, 0x60,
	0xB669, 0x40,
	0xBCAF, 0x01,
};

static kal_uint16 imx866_preview_setting[] = {
	0x0114, 0x02,
	0x0342, 0x2D,
	0x0343, 0x10,
	0x0340, 0x10,
	0x0341, 0x40,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x00,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x17,
	0x034B, 0xFF,
	0x0900, 0x01,
	0x0901, 0x12,
	0x0902, 0x08,
	0x31D0, 0x40,
	0x31D1, 0x41,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x10,
	0x040D, 0x00,
	0x040E, 0x0C,
	0x040F, 0x00,
	0x034C, 0x10,
	0x034D, 0x00,
	0x034E, 0x0C,
	0x034F, 0x00,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x00,
	0x0307, 0xB4,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x00,
	0x31A9, 0x01,
	0x3212, 0x01,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x10,
	0x0203, 0x10,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x01,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x00,
	0x3082, 0x03,
	0x3083, 0x2B,
};

static kal_uint16 imx866_capture_setting[] = {
	0x0114, 0x02,
	0x0342, 0x2D,
	0x0343, 0x10,
	0x0340, 0x10,
	0x0341, 0x40,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x00,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x17,
	0x034B, 0xFF,
	0x0900, 0x01,
	0x0901, 0x12,
	0x0902, 0x08,
	0x31D0, 0x40,
	0x31D1, 0x41,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x10,
	0x040D, 0x00,
	0x040E, 0x0C,
	0x040F, 0x00,
	0x034C, 0x10,
	0x034D, 0x00,
	0x034E, 0x0C,
	0x034F, 0x00,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x00,
	0x0307, 0xB4,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x00,
	0x31A9, 0x01,
	0x3212, 0x01,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x10,
	0x0203, 0x10,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x01,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x00,
	0x3082, 0x03,
	0x3083, 0x2B,
};

static kal_uint16 imx866_normal_video_setting[] = {
	0x0114, 0x02,
	0x0342, 0x2D,
	0x0343, 0x10,
	0x0340, 0x12,
	0x0341, 0x99,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x03,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x14,
	0x034B, 0xFF,
	0x0900, 0x01,
	0x0901, 0x12,
	0x0902, 0x08,
	0x31D0, 0x40,
	0x31D1, 0x41,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x10,
	0x040D, 0x00,
	0x040E, 0x09,
	0x040F, 0x00,
	0x034C, 0x10,
	0x034D, 0x00,
	0x034E, 0x09,
	0x034F, 0x00,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x00,
	0x0307, 0xCE,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x00,
	0x31A9, 0x01,
	0x3212, 0x01,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x12,
	0x0203, 0x69,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x01,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x00,
	0x3082, 0x03,
	0x3083, 0x2B,
};

static kal_uint16 imx866_hs_video_setting[] = {
	0x0114, 0x02,
	0x0342, 0x1B,
	0x0343, 0x60,
	0x0340, 0x06,
	0x0341, 0xB0,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x03,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x14,
	0x034B, 0xFF,
	0x0900, 0x01,
	0x0901, 0x24,
	0x0902, 0x08,
	0x31D0, 0x42,
	0x31D1, 0x43,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x08,
	0x040D, 0x00,
	0x040E, 0x04,
	0x040F, 0x80,
	0x034C, 0x08,
	0x034D, 0x00,
	0x034E, 0x04,
	0x034F, 0x80,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x00,
	0x0307, 0xB4,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x00,
	0x31A9, 0x00,
	0x3212, 0x01,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x06,
	0x0203, 0x80,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x01,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x00,
	0x3082, 0x03,
	0x3083, 0x2B,
};

static kal_uint16 imx866_slim_video_setting[] = {
	0x0114, 0x02,
	0x0342, 0x2D,
	0x0343, 0x10,
	0x0340, 0x10,
	0x0341, 0x40,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x00,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x17,
	0x034B, 0xFF,
	0x0900, 0x01,
	0x0901, 0x12,
	0x0902, 0x08,
	0x31D0, 0x40,
	0x31D1, 0x41,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x10,
	0x040D, 0x00,
	0x040E, 0x0C,
	0x040F, 0x00,
	0x034C, 0x10,
	0x034D, 0x00,
	0x034E, 0x0C,
	0x034F, 0x00,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x00,
	0x0307, 0xB4,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x00,
	0x31A9, 0x01,
	0x3212, 0x01,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x10,
	0x0203, 0x10,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x01,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x00,
	0x3082, 0x03,
	0x3083, 0x2B,
};

static kal_uint16 imx866_custom1_setting[] = {
	0x0114, 0x02,
	0x0342, 0x2D,
	0x0343, 0x10,
	0x0340, 0x10,
	0x0341, 0x40,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x00,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x17,
	0x034B, 0xFF,
	0x0900, 0x01,
	0x0901, 0x12,
	0x0902, 0x08,
	0x31D0, 0x40,
	0x31D1, 0x41,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x10,
	0x040D, 0x00,
	0x040E, 0x0C,
	0x040F, 0x00,
	0x034C, 0x10,
	0x034D, 0x00,
	0x034E, 0x0C,
	0x034F, 0x00,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x00,
	0x0307, 0xB4,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x01,
	0x31A9, 0x01,
	0x3212, 0x00,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x10,
	0x0203, 0x10,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x01,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x00,
	0x3082, 0x03,
	0x3083, 0x2B,
	0x309E,	0x01,
	0x309F,	0x2B,
};

static kal_uint16 imx866_custom2_setting[] = {
	0x0114, 0x02,
	0x0342, 0x2D,
	0x0343, 0x10,
	0x0340, 0x12,
	0x0341, 0x99,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x03,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x14,
	0x034B, 0xFF,
	0x0900, 0x01,
	0x0901, 0x12,
	0x0902, 0x08,
	0x31D0, 0x40,
	0x31D1, 0x41,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x10,
	0x040D, 0x00,
	0x040E, 0x09,
	0x040F, 0x00,
	0x034C, 0x10,
	0x034D, 0x00,
	0x034E, 0x09,
	0x034F, 0x00,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x00,
	0x0307, 0xCE,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x01,
	0x31A9, 0x01,
	0x3212, 0x00,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x12,
	0x0203, 0x69,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x01,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x00,
	0x3082, 0x03,
	0x3083, 0x2B,
	0x309E,	0x05,
	0x309F,	0x2B,
};

// NOTE:
// for 2 exp setting,  VCID of LE/SE should be 0x00 and 0x02
// which align 3 exp setting LE/NE/SE 0x00,  0x01,  0x02
// to seamless switch,  VC ID of SE should remain the same
// SONY sensor: VCID of 2nd frame at 0x3070; VCID of 3rd frame at 0x3080
// must be two different value

static kal_uint16 imx866_custom3_setting[] = {
	0x0114, 0x02,
	0x0342, 0x2D,
	0x0343, 0x10,
	0x0340, 0x09,
	0x0341, 0x4C,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x03,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x14,
	0x034B, 0xFF,
	0x0900, 0x01,
	0x0901, 0x12,
	0x0902, 0x08,
	0x31D0, 0x40,
	0x31D1, 0x41,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x10,
	0x040D, 0x00,
	0x040E, 0x09,
	0x040F, 0x00,
	0x034C, 0x10,
	0x034D, 0x00,
	0x034E, 0x09,
	0x034F, 0x00,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x00,
	0x0307, 0xCE,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x01,
	0x31A9, 0x01,
	0x3212, 0x00,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x07,
	0x0203, 0xE0,
	0x0224, 0x00,
	0x0225, 0xFC,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x03,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x01,
	0x3082, 0x03,
	0x3083, 0x2B,
	0x30A0, 0x01,
	0x30A4, 0x04,
	0x30A5, 0x2B,
	0x309E,	0x05,
	0x309F,	0x2B,
	0x30B0,	0x06,
	0x30B1,	0x2B,
};

static kal_uint16 imx866_custom4_setting[] = {
	0x0114, 0x02,
	0x0342, 0x2D,
	0x0343, 0x10,
	0x0340, 0x09,
	0x0341, 0x4C,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x03,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x14,
	0x034B, 0xFF,
	0x0900, 0x01,
	0x0901, 0x12,
	0x0902, 0x08,
	0x31D0, 0x40,
	0x31D1, 0x41,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x10,
	0x040D, 0x00,
	0x040E, 0x09,
	0x040F, 0x00,
	0x034C, 0x10,
	0x034D, 0x00,
	0x034E, 0x09,
	0x034F, 0x00,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x00,
	0x0307, 0xCE,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x00,
	0x31A9, 0x01,
	0x3212, 0x01,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x07,
	0x0203, 0xE0,
	0x0224, 0x00,
	0x0225, 0xFC,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x03,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x01,
	0x3082, 0x03,
	0x3083, 0x2B,
	0x30A0, 0x01,
	0x30A4, 0x04,
	0x30A5, 0x2B,
};

static kal_uint16 imx866_custom5_setting[] = {
	0x0114,	0x02,
	0x0342,	0x2D,
	0x0343,	0x10,
	0x0340,	0x11,
	0x0341,	0x6D,
	0x0344,	0x00,
	0x0345,	0x00,
	0x0346,	0x03,
	0x0347,	0x90,
	0x0348,	0x22,
	0x0349,	0x3F,
	0x034A,	0x14,
	0x034B,	0x6F,
	0x0900,	0x00,
	0x0901,	0x11,
	0x0902,	0x0A,
	0x31D0,	0x00,
	0x31D1,	0x00,
	0x0408,	0x02,
	0x0409,	0x20,
	0x040A,	0x00,
	0x040B,	0x00,
	0x040C,	0x1E,
	0x040D,	0x00,
	0x040E,	0x10,
	0x040F,	0xE0,
	0x034C,	0x1E,
	0x034D,	0x00,
	0x034E,	0x10,
	0x034F,	0xE0,
	0x0303,	0x02,
	0x0305,	0x03,
	0x0306,	0x00,
	0x0307,	0xC1,
	0x030B,	0x01,
	0x030D,	0x02,
	0x030E,	0x01,
	0x030F,	0x77,
	0x310F,	0x00,
	0x31A9,	0x01,
	0x3212,	0x01,
	0x3874,	0x00,
	0x3890,	0x00,
	0x3891,	0x00,
	0x3894,	0x00,
	0x3895,	0x00,
	0x3896,	0x00,
	0x3897,	0x00,
	0x389A,	0x00,
	0x389B,	0x00,
	0x389C,	0x00,
	0x389D,	0x00,
	0x389E,	0x00,
	0x389F,	0x00,
	0x38A0,	0x00,
	0x38A1,	0x00,
	0x38A2,	0x00,
	0x38A3,	0x00,
	0x38A4,	0x00,
	0x38A5,	0x00,
	0x38A6,	0x00,
	0x38A7,	0x00,
	0x38B8,	0x00,
	0x38B9,	0x00,
	0x38BA,	0x00,
	0x38BB,	0x00,
	0x38D0,	0x00,
	0x38D1,	0x00,
	0x38D2,	0x00,
	0x38D3,	0x00,
	0x38D6,	0x00,
	0x38D7,	0x00,
	0x38D8,	0x00,
	0x38D9,	0x00,
	0x38DA,	0x00,
	0x38DB,	0x00,
	0x38DC,	0x00,
	0x38DD,	0x00,
	0x0202,	0x11,
	0x0203,	0x3D,
	0x0224,	0x01,
	0x0225,	0xF4,
	0x0204,	0x00,
	0x0205,	0x00,
	0x020E,	0x01,
	0x020F,	0x00,
	0x0216,	0x00,
	0x0217,	0x00,
	0x0218,	0x01,
	0x0219,	0x00,
	0x3103,	0x01,
	0x3474,	0x03,
	0x3475,	0xC0,
	0x3170,	0x00,
	0x3082, 0x03,
	0x3083, 0x2B,
};

static kal_uint16 imx866_custom6_setting[] = {
	0x0114, 0x02,
	0x0342, 0x2D,
	0x0343, 0x10,
	0x0340, 0x18,
	0x0341, 0xA6,
	0x0344, 0x01,
	0x0345, 0x20,
	0x0346, 0x00,
	0x0347, 0x00,
	0x0348, 0x21,
	0x0349, 0x1F,
	0x034A, 0x17,
	0x034B, 0xFF,
	0x0900, 0x00,
	0x0901, 0x11,
	0x0902, 0x0A,
	0x31D0, 0x00,
	0x31D1, 0x00,
	0x0408, 0x00,
	0x0409, 0x00,
	0x040A, 0x00,
	0x040B, 0x00,
	0x040C, 0x20,
	0x040D, 0x00,
	0x040E, 0x18,
	0x040F, 0x00,
	0x034C, 0x20,
	0x034D, 0x00,
	0x034E, 0x18,
	0x034F, 0x00,
	0x0303, 0x02,
	0x0305, 0x03,
	0x0306, 0x01,
	0x0307, 0x11,
	0x030B, 0x01,
	0x030D, 0x02,
	0x030E, 0x01,
	0x030F, 0x77,
	0x310F, 0x00,
	0x31A9, 0x01,
	0x3212, 0x01,
	0x3874, 0x00,
	0x3890, 0x00,
	0x3891, 0x00,
	0x3894, 0x00,
	0x3895, 0x00,
	0x3896, 0x00,
	0x3897, 0x00,
	0x389A, 0x00,
	0x389B, 0x00,
	0x389C, 0x00,
	0x389D, 0x00,
	0x389E, 0x00,
	0x389F, 0x00,
	0x38A0, 0x00,
	0x38A1, 0x00,
	0x38A2, 0x00,
	0x38A3, 0x00,
	0x38A4, 0x00,
	0x38A5, 0x00,
	0x38A6, 0x00,
	0x38A7, 0x00,
	0x38B8, 0x00,
	0x38B9, 0x00,
	0x38BA, 0x00,
	0x38BB, 0x00,
	0x38D0, 0x00,
	0x38D1, 0x00,
	0x38D2, 0x00,
	0x38D3, 0x00,
	0x38D6, 0x00,
	0x38D7, 0x00,
	0x38D8, 0x00,
	0x38D9, 0x00,
	0x38DA, 0x00,
	0x38DB, 0x00,
	0x38DC, 0x00,
	0x38DD, 0x00,
	0x0202, 0x18,
	0x0203, 0x76,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x01,
	0x3474, 0x04,
	0x3475, 0x00,
	0x3170, 0x00,
	0x3082, 0x03,
	0x3083, 0x2B,
};

/* seamless_switch */
#define PHASE_PIX_OUT_EN            0x30B4
#define LINE_LEN_UPPER              0x0342
#define LINE_LEN_LOWER              0x0343
#define FRAME_LEN_UPPER             0x0340
#define FRAME_LEN_LOWER             0x0341
#define DOL_EN                      0x33D0
#define DOL_MODE                    0x33D1
#define BINNING_TYPE                0x0901
#define BINNING_PRIORITY_H          0x3200
#define BINNING_PRIORITY_V          0x3201
#define X_ADD_STA_UPPER             0x0344
#define X_ADD_STA_LOWER             0x0345
#define Y_ADD_STA_UPPER             0x0346
#define Y_ADD_STA_LOWER             0x0347
#define X_ADD_END_UPPER             0x0348
#define X_ADD_END_LOWER             0x0349
#define Y_ADD_END_UPPER             0x034A
#define Y_ADD_END_LOWER             0x034B
#define DIG_CROP_X_OFFSET_UPPER     0x0408
#define DIG_CROP_X_OFFSET_LOWER     0x0409
#define DIG_CROP_Y_OFFSET_UPPER     0x040A
#define DIG_CROP_Y_OFFSET_LOWER     0x040B
#define DIG_CROP_IMAGE_WIDTH_UPPER  0x040C
#define DIG_CROP_IMAGE_WIDTH_LOWER  0x040D
#define DIG_CROP_IMAGE_HEIGHT_UPPER 0x040E
#define DIG_CROP_IMAGE_HEIGHT_LOWER 0x040F
#define X_OUT_SIZE_UPPER            0x034C
#define X_OUT_SIZE_LOWER            0x034D
#define Y_OUT_SIZE_UPPER            0x034E
#define Y_OUT_SIZE_LOWER            0x034F

// video stagger seamless switch (1exp-2exp)
static kal_uint16 imx866_seamless_normal_video[] = {
	0x0340, 0x12,
	0x0341, 0x99,
	0x0202, 0x12,
	0x0203, 0x69,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x0204, 0x00,
	0x0205, 0x00,
	0x020E, 0x01,
	0x020F, 0x00,
	0x0216, 0x00,
	0x0217, 0x00,
	0x0218, 0x01,
	0x0219, 0x00,
	0x3103, 0x01,
	0x3170, 0x00,
};
static kal_uint16 imx866_seamless_custom4[] = {
	0x0340, 0x09,
	0x0341, 0x4C,
	0x0202, 0x07,
	0x0203, 0xE0,
	0x0224, 0x00,
	0x0225, 0xFC,
	0x3103, 0x03,
	0x3170, 0x01,
	0x30A0, 0x01,
	0x30A4, 0x04,
	0x30A5, 0x2B,
};

// RGBW seamless switch (1exp-2exp)
static kal_uint16 imx866_seamless_custom2[] = {
	0x0340, 0x12,
	0x0341, 0x99,
	0x0202, 0x12,
	0x0203, 0x69,
	0x0224, 0x01,
	0x0225, 0xF4,
	0x3103, 0x01,
	0x3170, 0x00,
};
static kal_uint16 imx866_seamless_custom3[] = {
	0x0340, 0x09,
	0x0341, 0x4C,
	0x0202, 0x07,
	0x0203, 0xE0,
	0x0224, 0x00,
	0x0225, 0xFC,
	0x3103, 0x03,
	0x3170, 0x01,
	0x30A0, 0x01,
	0x30A4, 0x04,
	0x30A5, 0x2B,
	0x30B0,	0x06,
	0x30B1,	0x2B,
};

#endif