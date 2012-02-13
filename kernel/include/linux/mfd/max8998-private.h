/*
 * max8998.h - Voltage regulator driver for the Maxim 8998
 *
 *  Copyright (C) 2009-2010 Samsung Electrnoics
 *  Kyungmin Park <kyungmin.park@samsung.com>
 *  Marek Szyprowski <m.szyprowski@samsung.com>
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LINUX_MFD_MAX8998_PRIV_H
#define __LINUX_MFD_MAX8998_PRIV_H

#define MAX8998_NUM_IRQ_REGS	4

/* MAX 8998 registers */
enum {
	MAX8998_REG_IRQ1,
	MAX8998_REG_IRQ2,
	MAX8998_REG_IRQ3,
	MAX8998_REG_IRQ4,
	MAX8998_REG_IRQM1,
	MAX8998_REG_IRQM2,
	MAX8998_REG_IRQM3,
	MAX8998_REG_IRQM4,
	MAX8998_REG_STATUS1,
	MAX8998_REG_STATUS2,
	MAX8998_REG_STATUSM1,
	MAX8998_REG_STATUSM2,
	MAX8998_REG_CHGR1,
	MAX8998_REG_CHGR2,
	MAX8998_REG_LDO_ACTIVE_DISCHARGE1,
	MAX8998_REG_LDO_ACTIVE_DISCHARGE2,
	MAX8998_REG_BUCK_ACTIVE_DISCHARGE3,
	MAX8998_REG_ONOFF1,
	MAX8998_REG_ONOFF2,
	MAX8998_REG_ONOFF3,
	MAX8998_REG_ONOFF4,
	MAX8998_REG_BUCK1_VOLTAGE1,
	MAX8998_REG_BUCK1_VOLTAGE2,
	MAX8998_REG_BUCK1_VOLTAGE3,
	MAX8998_REG_BUCK1_VOLTAGE4,
	MAX8998_REG_BUCK2_VOLTAGE1,
	MAX8998_REG_BUCK2_VOLTAGE2,
	MAX8998_REG_BUCK3,
	MAX8998_REG_BUCK4,
	MAX8998_REG_LDO2_LDO3,
	MAX8998_REG_LDO4,
	MAX8998_REG_LDO5,
	MAX8998_REG_LDO6,
	MAX8998_REG_LDO7,
	MAX8998_REG_LDO8_LDO9,
	MAX8998_REG_LDO10_LDO11,
	MAX8998_REG_LDO12,
	MAX8998_REG_LDO13,
	MAX8998_REG_LDO14,
	MAX8998_REG_LDO15,
	MAX8998_REG_LDO16,
	MAX8998_REG_LDO17,
	MAX8998_REG_BKCHR,
	MAX8998_REG_LBCNFG1,
	MAX8998_REG_LBCNFG2,
};

/* IRQ definitions */
enum {
	MAX8998_IRQ_DCINF,
	MAX8998_IRQ_DCINR,
	MAX8998_IRQ_JIGF,
	MAX8998_IRQ_JIGR,
	MAX8998_IRQ_PWRONF,
	MAX8998_IRQ_PWRONR,

	MAX8998_IRQ_WTSREVNT,
	MAX8998_IRQ_SMPLEVNT,
	MAX8998_IRQ_ALARM1,
	MAX8998_IRQ_ALARM0,

	MAX8998_IRQ_ONKEY1S,
	MAX8998_IRQ_TOPOFFR,
	MAX8998_IRQ_DCINOVPR,
	MAX8998_IRQ_CHGRSTF,
	MAX8998_IRQ_DONER,
	MAX8998_IRQ_CHGFAULT,

	MAX8998_IRQ_LOBAT1,
	MAX8998_IRQ_LOBAT2,

	MAX8998_IRQ_NR,
};

/* MAX8998 various variants */
enum {
	TYPE_MAX8998 = 0, /* Default */
	TYPE_LP3974,	/* National version of MAX8998 */
	TYPE_LP3979,	/* Added AVS */
};

#define MAX8998_IRQ_DCINF_MASK		(1 << 2)
#define MAX8998_IRQ_DCINR_MASK		(1 << 3)
#define MAX8998_IRQ_JIGF_MASK		(1 << 4)
#define MAX8998_IRQ_JIGR_MASK		(1 << 5)
#define MAX8998_IRQ_PWRONF_MASK		(1 << 6)
#define MAX8998_IRQ_PWRONR_MASK		(1 << 7)

#define MAX8998_IRQ_WTSREVNT_MASK	(1 << 0)
#define MAX8998_IRQ_SMPLEVNT_MASK	(1 << 1)
#define MAX8998_IRQ_ALARM1_MASK		(1 << 2)
#define MAX8998_IRQ_ALARM0_MASK		(1 << 3)

#define MAX8998_IRQ_ONKEY1S_MASK	(1 << 0)
#define MAX8998_IRQ_TOPOFFR_MASK	(1 << 2)
#define MAX8998_IRQ_DCINOVPR_MASK	(1 << 3)
#define MAX8998_IRQ_CHGRSTF_MASK	(1 << 4)
#define MAX8998_IRQ_DONER_MASK		(1 << 5)
#define MAX8998_IRQ_CHGFAULT_MASK	(1 << 7)

#define MAX8998_IRQ_LOBAT1_MASK		(1 << 0)
#define MAX8998_IRQ_LOBAT2_MASK		(1 << 1)

#define MAX8998_ENRAMP                  (1 << 4)

/* IRQ1 */
#define MAX8998_SHIFT_PWRONR	7
#define MAX8998_SHIFT_PWRONF	6
#define MAX8998_SHIFT_JIGR	5
#define MAX8998_SHIFT_JIGF	4
#define MAX8998_SHIFT_DCINR	3
#define MAX8998_SHIFT_DCINF	2

#define MAX8998_MASK_PWRONR	(0x1 << MAX8998_SHIFT_PWRONR)
#define MAX8998_MASK_PWRONF	(0x1 << MAX8998_SHIFT_PWRONF)
#define MAX8998_MASK_JIGR	(0x1 << MAX8998_SHIFT_JIGR)
#define MAX8998_MASK_JIGF	(0x1 << MAX8998_SHIFT_JIGF)
#define MAX8998_MASK_DCINR	(0x1 << MAX8998_SHIFT_DCINR)
#define MAX8998_MASK_DCINF	(0x1 << MAX8998_SHIFT_DCINF)

/* STATUS1 */
#define MAX8998_SHIFT_ENDKEY	7
#define MAX8998_SHIFT_JIGON	6
#define MAX8998_SHIFT_ALARM0	5
#define MAX8998_SHIFT_ALARM1	4
#define MAX8998_SHIFT_SMPL	3
#define MAX8998_SHIFT_WTSR	2
#define MAX8998_SHIFT_LOWBAT2	1
#define MAX8998_SHIFT_LOWBAT1	0

#define MAX8998_MASK_ENDKEY	(0x1 << MAX8998_SHIFT_ENDKEY)
#define MAX8998_MASK_JIGON	(0x1 << MAX8998_SHIFT_JIGON)
#define MAX8998_MASK_ALARM0	(0x1 << MAX8998_SHIFT_ALARM0)
#define MAX8998_MASK_ALARM1	(0x1 << MAX8998_SHIFT_ALARM1)
#define MAX8998_MASK_SMPL	(0x1 << MAX8998_SHIFT_SMPL)
#define MAX8998_MASK_WTSR	(0x1 << MAX8998_SHIFT_WTSR)
#define MAX8998_MASK_LOWBAT2	(0x1 << MAX8998_SHIFT_LOWBAT2)
#define MAX8998_MASK_LOWBAT1	(0x1 << MAX8998_SHIFT_LOWBAT1)

/* STATUS2 */
#define MAX8998_SHIFT_CHGDONE	6
#define MAX8998_SHIFT_VDCIN	5
#define MAX8998_SHIFT_DETBAT	4
#define MAX8998_SHIFT_CHGON	3
#define MAX8998_SHIFT_FCHG	2
#define MAX8998_SHIFT_PQL	1

#define MAX8998_MASK_CHGDONE	(0x1 << MAX8998_SHIFT_CHGDONE)
#define MAX8998_MASK_VDCIN	(0x1 << MAX8998_SHIFT_VDCIN)
#define MAX8998_MASK_DETBAT	(0x1 << MAX8998_SHIFT_DETBAT)
#define MAX8998_MASK_CHGON	(0x1 << MAX8998_SHIFT_CHGON)
#define MAX8998_MASK_FCHG	(0x1 << MAX8998_SHIFT_FCHG)
#define MAX8998_MASK_PQL	(0x1 << MAX8998_SHIFT_PQL)

/* CHGR1 */
#define MAX8998_SHIFT_TOPOFF	5
#define MAX8998_SHIFT_RSTR	3
#define MAX8998_SHIFT_ICHG	0

#define MAX8998_MASK_TOPOFF	(0x7 << MAX8998_SHIFT_TOPOFF)
#define MAX8998_MASK_RSTR	(0x3 << MAX8998_SHIFT_RSTR)
#define MAX8998_MASK_ICHG	(0x7 << MAX8998_SHIFT_ICHG)

#define MAX8998_TOPOFF_10	0
#define MAX8998_TOPOFF_15	1
#define MAX8998_TOPOFF_20	2
#define MAX8998_TOPOFF_25	3
#define MAX8998_TOPOFF_30	4
#define MAX8998_TOPOFF_35	5
#define MAX8998_TOPOFF_40	6
#define MAX8998_TOPOFF_45	7

#define MAX8998_RSTR_150	0
#define MAX8998_RSTR_100	1
#define MAX8998_RSTR_200	2
#define MAX8998_RSTR_DISABLE	3

#define MAX8998_ICHG_90		0
#define MAX8998_ICHG_380	1
#define MAX8998_ICHG_475	2
#define MAX8998_ICHG_550	3
#define MAX8998_ICHG_570	4
#define MAX8998_ICHG_600	5
#define MAX8998_ICHG_700	6
#define MAX8998_ICHG_800	7

/* CHGR2 */
#define MAX8998_SHIFT_ESAFEOUT	6
#define MAX8998_SHIFT_FT	4
#define MAX8998_SHIFT_BATTSL	3
#define MAX8998_SHIFT_TMP	1
#define MAX8998_SHIFT_CHGEN	0

#define MAX8998_MASK_ESAFEOUT	(0x3 << MAX8998_SHIFT_ESAFEOUT)
#define MAX8998_MASK_FT		(0x3 << MAX8998_SHIFT_FT)
#define MAX8998_MASK_BATTSL	(0x1 << MAX8998_SHIFT_BATTSL)
#define MAX8998_MASK_TMP	(0x3 << MAX8998_SHIFT_TMP)
#define MAX8998_MASK_CHGEN	(0x1 << MAX8998_SHIFT_CHGEN)

#define MAX8998_ESAFE_ALLOFF	0
#define MAX8998_ESAFE_2ON	1
#define MAX8998_ESAFE_1ON	2
#define MAX8998_ESAFE_ALLON	3
#define MAX8998_USB_VBUS_CP_ON	MAX8998_ESAFE_2ON
#define MAX8998_USB_VBUS_AP_ON	MAX8998_ESAFE_1ON

#define MAX8998_CHGTIME_5HR	0
#define MAX8998_CHGTIME_6HR	1
#define MAX8998_CHGTIME_7HR	2
#define MAX8998_CHGTIME_DISABLE	3

#define MAX8998_BATSEL_4_2V	0
#define MAX8998_BATSEL_4_35V	1

#define MAX8998_TEMPER_105	0
#define MAX8998_TEMPER_160	1
#define MAX8998_TEMPER_115	2
#define MAX8998_TEMPER_135	3

#define MAX8998_CHGEN_ENABLE	0
#define MAX8998_CHGEN_DISABLE	1

/* ONOFF1 */
#define MAX8998_SHIFT_EN1	7
#define MAX8998_SHIFT_EN2	6
#define MAX8998_SHIFT_EN3	5
#define MAX8998_SHIFT_EN4	4
#define MAX8998_SHIFT_ELDO2	3
#define MAX8998_SHIFT_ELDO3	2
#define MAX8998_SHIFT_ELDO4	1
#define MAX8998_SHIFT_ELDO5	0

#define MAX8998_MASK_EN1	(0x1 << MAX8998_SHIFT_EN1)
#define MAX8998_MASK_EN2	(0x1 << MAX8998_SHIFT_EN2)
#define MAX8998_MASK_EN3	(0x1 << MAX8998_SHIFT_EN3)
#define MAX8998_MASK_EN4	(0x1 << MAX8998_SHIFT_EN4)
#define MAX8998_MASK_ELDO2	(0x1 << MAX8998_SHIFT_ELDO2)
#define MAX8998_MASK_ELDO3	(0x1 << MAX8998_SHIFT_ELDO3)
#define MAX8998_MASK_ELDO4	(0x1 << MAX8998_SHIFT_ELDO4)
#define MAX8998_MASK_ELDO5	(0x1 << MAX8998_SHIFT_ELDO5)

/* ONOFF2 */
#define MAX8998_SHIFT_ELDO6	7
#define MAX8998_SHIFT_ELDO7	6
#define MAX8998_SHIFT_ELDO8	5
#define MAX8998_SHIFT_ELDO9	4
#define MAX8998_SHIFT_ELDO10	3
#define MAX8998_SHIFT_ELDO11	2
#define MAX8998_SHIFT_ELDO12	1
#define MAX8998_SHIFT_ELDO13	0

#define MAX8998_MASK_ELDO6	(0x1 << MAX8998_SHIFT_ELDO6)
#define MAX8998_MASK_ELDO7	(0x1 << MAX8998_SHIFT_ELDO7)
#define MAX8998_MASK_ELDO8	(0x1 << MAX8998_SHIFT_ELDO8)
#define MAX8998_MASK_ELDO9	(0x1 << MAX8998_SHIFT_ELDO9)
#define MAX8998_MASK_ELDO10	(0x1 << MAX8998_SHIFT_ELDO10)
#define MAX8998_MASK_ELDO11	(0x1 << MAX8998_SHIFT_ELDO11)
#define MAX8998_MASK_ELDO12	(0x1 << MAX8998_SHIFT_ELDO12)
#define MAX8998_MASK_ELDO13	(0x1 << MAX8998_SHIFT_ELDO13)

/* ONOFF3 */
#define MAX8998_SHIFT_ELDO14	7
#define MAX8998_SHIFT_ELDO15	6
#define MAX8998_SHIFT_ELDO16	5
#define MAX8998_SHIFT_ELDO17	4
#define MAX8998_SHIFT_EPWRHOLD	3
#define MAX8998_SHIFT_ENBATTMON	2
#define MAX8998_SHIFT_ELBCNFG2	1
#define MAX8998_SHIFT_ELBCNFG1	0

#define MAX8998_MASK_ELDO14	(0x1 << MAX8998_SHIFT_ELDO14)
#define MAX8998_MASK_ELDO15	(0x1 << MAX8998_SHIFT_ELDO15)
#define MAX8998_MASK_ELDO16	(0x1 << MAX8998_SHIFT_ELDO16)
#define MAX8998_MASK_ELDO17	(0x1 << MAX8998_SHIFT_ELDO17)
#define MAX8998_MASK_EPWRHOLD	(0x1 << MAX8998_SHIFT_EPWRHOLD)
#define MAX8998_MASK_ENBATTMON	(0x1 << MAX8998_SHIFT_ENBATTMON)
#define MAX8998_MASK_ELBCNFG2	(0x1 << MAX8998_SHIFT_ELBCNFG2)
#define MAX8998_MASK_ELBCNFG1	(0x1 << MAX8998_SHIFT_ELBCNFG1)

/* ONOFF4 */
#define MAX8998_SHIFT_EN32KHZAP	7
#define MAX8998_SHIFT_EN32KHZCP	6
#define MAX8998_SHIFT_ENVICHG	5
#define MAX8998_SHIFT_ENRAMP	4
#define MAX8998_SHIFT_RAMP	0

#define MAX8998_MASK_EN32KHZAP	(0x1 << MAX8998_SHIFT_EN32KHZAP)
#define MAX8998_MASK_EN32KHZCP	(0x1 << MAX8998_SHIFT_EN32KHZCP)
#define MAX8998_MASK_ENVICHG	(0x1 << MAX8998_SHIFT_ENVICHG)
#define MAX8998_MASK_ENRAMP	(0x1 << MAX8998_SHIFT_ENRAMP)
#define MAX8998_MASK_RAMP	(0xF << MAX8998_SHIFT_RAMP)

/**
 * struct max8998_dev - max8998 master device for sub-drivers
 * @dev: master device of the chip (can be used to access platform data)
 * @i2c: i2c client private data for regulator
 * @rtc: i2c client private data for rtc
 * @iolock: mutex for serializing io access
 * @irqlock: mutex for buslock
 * @irq_base: base IRQ number for max8998, required for IRQs
 * @irq: generic IRQ number for max8998
 * @ono: power onoff IRQ number for max8998
 * @irq_masks_cur: currently active value
 * @irq_masks_cache: cached hardware value
 * @type: indicate which max8998 "variant" is used
 */
struct max8998_dev {
	struct device *dev;
	struct i2c_client *i2c;
	struct i2c_client *rtc;
	struct mutex iolock;
	struct mutex irqlock;

	int irq_base;
	int irq;
	int ono;
	u8 irq_masks_cur[MAX8998_NUM_IRQ_REGS];
	u8 irq_masks_cache[MAX8998_NUM_IRQ_REGS];
	int type;
};

int max8998_irq_init(struct max8998_dev *max8998);
void max8998_irq_exit(struct max8998_dev *max8998);

extern int max8998_read_reg(struct i2c_client *i2c, u8 reg, u8 *dest);
extern int max8998_bulk_read(struct i2c_client *i2c, u8 reg, int count,
		u8 *buf);
extern int max8998_write_reg(struct i2c_client *i2c, u8 reg, u8 value);
extern int max8998_bulk_write(struct i2c_client *i2c, u8 reg, int count,
		u8 *buf);
extern int max8998_update_reg(struct i2c_client *i2c, u8 reg, u8 val, u8 mask);

#endif /*  __LINUX_MFD_MAX8998_PRIV_H */