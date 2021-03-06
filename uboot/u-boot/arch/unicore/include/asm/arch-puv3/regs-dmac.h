/*
 * PKUnity Direct Memory Access Controller (DMAC)
 */
#define DMAC_ISR		__REG(PKUNITY_DMAC_BASE + 0x0020) /* Interrupt Status Reg. */
#define DMAC_ITCSR		__REG(PKUNITY_DMAC_BASE + 0x0050) /* Interrupt Transfer Complete Status Reg. */
#define DMAC_ITCCR		__REG(PKUNITY_DMAC_BASE + 0x0060) /* Interrupt Transfer Complete Clear Reg. */
#define DMAC_IESR		__REG(PKUNITY_DMAC_BASE + 0x0080) /* Interrupt Error Status Reg. */
#define DMAC_IECR		__REG(PKUNITY_DMAC_BASE + 0x0090) /* Interrupt Error Clear Reg. */
#define DMAC_ENCH		__REG(PKUNITY_DMAC_BASE + 0x00B0) /* Enable Channels Reg. */

#define DMASp                   0x00000100 /* DMA control reg. Space [byte] */

#define DMAC_SRCADDR(ch)	__REG(PKUNITY_DMAC_BASE + (ch)*DMASp + 0x00) /* Source Addr. */
#define DMAC_DESTADDR(ch)	__REG(PKUNITY_DMAC_BASE + (ch)*DMASp + 0x04) /* Destination Addr. */
#define DMAC_CONTROL(ch)	__REG(PKUNITY_DMAC_BASE + (ch)*DMASp + 0x0C) /* Control Reg. */
#define DMAC_CONFIG(ch)		__REG(PKUNITY_DMAC_BASE + (ch)*DMASp + 0x10) /* Configuration Reg. */

#define DMAC_IR_MASK            FMASK(6, 0)
#define DMAC_CHANNEL(ch)	FIELD(1, 1, (ch)) /* select channel (ch) */

#define DMAC_CONTROL_SIZE_BYTE(v)       (FIELD((v), 12, 14)      | FIELD(0, 3, 9) | FIELD(0, 3, 6))
#define DMAC_CONTROL_SIZE_HWORD(v)      (FIELD((v) >> 1, 12, 14) | FIELD(1, 3, 9) | FIELD(1, 3, 6))
#define DMAC_CONTROL_SIZE_WORD(v)       (FIELD((v) >> 2, 12, 14) | FIELD(2, 3, 9) | FIELD(2, 3, 6))
#define DMAC_CONTROL_DI                 FIELD(1, 1, 13)
#define DMAC_CONTROL_SI                 FIELD(1, 1, 12)
#define DMAC_CONTROL_BURST_1BYTE        (FIELD(0, 3, 3) | FIELD(0, 3, 0))
#define DMAC_CONTROL_BURST_4BYTE        (FIELD(3, 3, 3) | FIELD(3, 3, 0))
#define DMAC_CONTROL_BURST_8BYTE        (FIELD(5, 3, 3) | FIELD(5, 3, 0))
#define DMAC_CONTROL_BURST_16BYTE       (FIELD(7, 3, 3) | FIELD(7, 3, 0))

#define	DMAC_CONFIG_UART0_WR    (FIELD(2, 4, 11) | FIELD(1, 2, 1))
#define	DMAC_CONFIG_UART0_RD    (FIELD(2, 4, 7)  | FIELD(2, 2, 1))
#define	DMAC_CONFIG_UART1_WR    (FIELD(3, 4, 11) | FIELD(1, 2, 1))
#define	DMAC_CONFIG_UART1RD     (FIELD(3, 4, 7)  | FIELD(2, 2, 1))
#define	DMAC_CONFIG_AC97WR      (FIELD(4, 4, 11) | FIELD(1, 2, 1))
#define	DMAC_CONFIG_AC97RD      (FIELD(4, 4, 7)  | FIELD(2, 2, 1))
#define	DMAC_CONFIG_MMCWR       (FIELD(7, 4, 11) | FIELD(1, 2, 1))
#define	DMAC_CONFIG_MMCRD       (FIELD(7, 4, 7)  | FIELD(2, 2, 1))
#define DMAC_CONFIG_MASKITC     FIELD(1, 1, 4)
#define DMAC_CONFIG_MASKIE      FIELD(1, 1, 3)
#define DMAC_CONFIG_EN          FIELD(1, 1, 0)
