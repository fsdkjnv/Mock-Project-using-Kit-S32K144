#include <stdint.h>


typedef enum
{
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M4 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M4 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M4 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M4 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M4 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M4 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M4 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M4 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0u,               /**< DMA channel 0 transfer complete */
  DMA1_IRQn                    = 1u,               /**< DMA channel 1 transfer complete */
  DMA2_IRQn                    = 2u,               /**< DMA channel 2 transfer complete */
  DMA3_IRQn                    = 3u,               /**< DMA channel 3 transfer complete */
  DMA4_IRQn                    = 4u,               /**< DMA channel 4 transfer complete */
  DMA5_IRQn                    = 5u,               /**< DMA channel 5 transfer complete */
  DMA6_IRQn                    = 6u,               /**< DMA channel 6 transfer complete */
  DMA7_IRQn                    = 7u,               /**< DMA channel 7 transfer complete */
  DMA8_IRQn                    = 8u,               /**< DMA channel 8 transfer complete */
  DMA9_IRQn                    = 9u,               /**< DMA channel 9 transfer complete */
  DMA10_IRQn                   = 10u,              /**< DMA channel 10 transfer complete */
  DMA11_IRQn                   = 11u,              /**< DMA channel 11 transfer complete */
  DMA12_IRQn                   = 12u,              /**< DMA channel 12 transfer complete */
  DMA13_IRQn                   = 13u,              /**< DMA channel 13 transfer complete */
  DMA14_IRQn                   = 14u,              /**< DMA channel 14 transfer complete */
  DMA15_IRQn                   = 15u,              /**< DMA channel 15 transfer complete */
  DMA_Error_IRQn               = 16u,              /**< DMA error interrupt channels 0-15 */
  MCM_IRQn                     = 17u,              /**< FPU sources */
  FTFC_IRQn                    = 18u,              /**< FTFC Command complete */
  Read_Collision_IRQn          = 19u,              /**< FTFC Read collision */
  LVD_LVW_IRQn                 = 20u,              /**< PMC Low voltage detect interrupt */
  FTFC_Fault_IRQn              = 21u,              /**< FTFC Double bit fault detect */
  WDOG_EWM_IRQn                = 22u,              /**< Single interrupt vector for WDOG and EWM */
  RCM_IRQn                     = 23u,              /**< RCM Asynchronous Interrupt */
  LPI2C0_Master_IRQn           = 24u,              /**< LPI2C0 Master Interrupt */
  LPI2C0_Slave_IRQn            = 25u,              /**< LPI2C0 Slave Interrupt */
  LPSPI0_IRQn                  = 26u,              /**< LPSPI0 Interrupt */
  LPSPI1_IRQn                  = 27u,              /**< LPSPI1 Interrupt */
  LPSPI2_IRQn                  = 28u,              /**< LPSPI2 Interrupt */
  LPUART0_RxTx_IRQn            = 31u,              /**< LPUART0 Transmit / Receive Interrupt */
  LPUART1_RxTx_IRQn            = 33u,              /**< LPUART1 Transmit / Receive  Interrupt */
  LPUART2_RxTx_IRQn            = 35u,              /**< LPUART2 Transmit / Receive  Interrupt */
  ADC0_IRQn                    = 39u,              /**< ADC0 interrupt request. */
  ADC1_IRQn                    = 40u,              /**< ADC1 interrupt request. */
  CMP0_IRQn                    = 41u,              /**< CMP0 interrupt request */
  ERM_single_fault_IRQn        = 44u,              /**< ERM single bit error correction */
  ERM_double_fault_IRQn        = 45u,              /**< ERM double bit error non-correctable */
  RTC_IRQn                     = 46u,              /**< RTC alarm interrupt */
  RTC_Seconds_IRQn             = 47u,              /**< RTC seconds interrupt */
  LPIT0_Ch0_IRQn               = 48u,              /**< LPIT0 channel 0 overflow interrupt */
  LPIT0_Ch1_IRQn               = 49u,              /**< LPIT0 channel 1 overflow interrupt */
  LPIT0_Ch2_IRQn               = 50u,              /**< LPIT0 channel 2 overflow interrupt */
  LPIT0_Ch3_IRQn               = 51u,              /**< LPIT0 channel 3 overflow interrupt */
  PDB0_IRQn                    = 52u,              /**< PDB0 interrupt */
  SCG_IRQn                     = 57u,              /**< SCG bus interrupt request */
  LPTMR0_IRQn                  = 58u,              /**< LPTIMER interrupt request */
  PORTA_IRQn                   = 59u,              /**< Port A pin detect interrupt */
  PORTB_IRQn                   = 60u,              /**< Port B pin detect interrupt */
  PORTC_IRQn                   = 61u,              /**< Port C pin detect interrupt */
  PORTD_IRQn                   = 62u,              /**< Port D pin detect interrupt */
  PORTE_IRQn                   = 63u,              /**< Port E pin detect interrupt */
  SWI_IRQn                     = 64u,              /**< Software interrupt */
  PDB1_IRQn                    = 68u,              /**< PDB1 interrupt */
  FLEXIO_IRQn                  = 69u,              /**< FlexIO Interrupt */
  CAN0_ORed_IRQn               = 78u,              /**< CAN0 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
  CAN0_Error_IRQn              = 79u,              /**< CAN0 Interrupt indicating that errors were detected on the CAN bus */
  CAN0_Wake_Up_IRQn            = 80u,              /**< CAN0 Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode */
  CAN0_ORed_0_15_MB_IRQn       = 81u,              /**< CAN0 OR'ed Message buffer (0-15) */
  CAN0_ORed_16_31_MB_IRQn      = 82u,              /**< CAN0 OR'ed Message buffer (16-31) */
  CAN1_ORed_IRQn               = 85u,              /**< CAN1 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
  CAN1_Error_IRQn              = 86u,              /**< CAN1 Interrupt indicating that errors were detected on the CAN bus */
  CAN1_ORed_0_15_MB_IRQn       = 88u,              /**< CAN1 OR'ed Interrupt for Message buffer (0-15) */
  CAN2_ORed_IRQn               = 92u,              /**< CAN2 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
  CAN2_Error_IRQn              = 93u,              /**< CAN2 Interrupt indicating that errors were detected on the CAN bus */
  CAN2_ORed_0_15_MB_IRQn       = 95u,              /**< CAN2 OR'ed Message buffer (0-15) */
  FTM0_Ch0_Ch1_IRQn            = 99u,              /**< FTM0 Channel 0 and 1 interrupt */
  FTM0_Ch2_Ch3_IRQn            = 100u,             /**< FTM0 Channel 2 and 3 interrupt */
  FTM0_Ch4_Ch5_IRQn            = 101u,             /**< FTM0 Channel 4 and 5 interrupt */
  FTM0_Ch6_Ch7_IRQn            = 102u,             /**< FTM0 Channel 6 and 7 interrupt */
  FTM0_Fault_IRQn              = 103u,             /**< FTM0 Fault interrupt */
  FTM0_Ovf_Reload_IRQn         = 104u,             /**< FTM0 Counter overflow and Reload interrupt */
  FTM1_Ch0_Ch1_IRQn            = 105u,             /**< FTM1 Channel 0 and 1 interrupt */
  FTM1_Ch2_Ch3_IRQn            = 106u,             /**< FTM1 Channel 2 and 3 interrupt */
  FTM1_Ch4_Ch5_IRQn            = 107u,             /**< FTM1 Channel 4 and 5 interrupt */
  FTM1_Ch6_Ch7_IRQn            = 108u,             /**< FTM1 Channel 6 and 7 interrupt */
  FTM1_Fault_IRQn              = 109u,             /**< FTM1 Fault interrupt */
  FTM1_Ovf_Reload_IRQn         = 110u,             /**< FTM1 Counter overflow and Reload interrupt */
  FTM2_Ch0_Ch1_IRQn            = 111u,             /**< FTM2 Channel 0 and 1 interrupt */
  FTM2_Ch2_Ch3_IRQn            = 112u,             /**< FTM2 Channel 2 and 3 interrupt */
  FTM2_Ch4_Ch5_IRQn            = 113u,             /**< FTM2 Channel 4 and 5 interrupt */
  FTM2_Ch6_Ch7_IRQn            = 114u,             /**< FTM2 Channel 6 and 7 interrupt */
  FTM2_Fault_IRQn              = 115u,             /**< FTM2 Fault interrupt */
  FTM2_Ovf_Reload_IRQn         = 116u,             /**< FTM2 Counter overflow and Reload interrupt */
  FTM3_Ch0_Ch1_IRQn            = 117u,             /**< FTM3 Channel 0 and 1 interrupt */
  FTM3_Ch2_Ch3_IRQn            = 118u,             /**< FTM3 Channel 2 and 3 interrupt */
  FTM3_Ch4_Ch5_IRQn            = 119u,             /**< FTM3 Channel 4 and 5 interrupt */
  FTM3_Ch6_Ch7_IRQn            = 120u,             /**< FTM3 Channel 6 and 7 interrupt */
  FTM3_Fault_IRQn              = 121u,             /**< FTM3 Fault interrupt */
  FTM3_Ovf_Reload_IRQn         = 122u              /**< FTM3 Counter overflow and Reload interrupt */
} IRQn_Type;

/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */


/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                           32u

/** PORT - Register Layout Typedef */
typedef struct {
   uint32_t PCR[PORT_PCR_COUNT];               /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
   uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
   uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
  uint32_t GICLR;                             /**< Global Interrupt Control Low Register, offset: 0x88 */
  uint32_t GICHR;                             /**< Global Interrupt Control High Register, offset: 0x8C */
       uint8_t RESERVED_0[16];
  uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
       uint8_t RESERVED_1[28];
   uint32_t DFER;                              /**< Digital Filter Enable Register, offset: 0xC0 */
  uint32_t DFCR;                              /**< Digital Filter Clock Register, offset: 0xC4 */
 uint32_t DFWR;                              /**< Digital Filter Width Register, offset: 0xC8 */
} PORT_Type, *PORT_MemMapPtr;

 /** Number of instances of the PORT module. */
#define PORT_INSTANCE_COUNT                      (5u)


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x40049000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4004A000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4004B000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x4004C000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x4004D000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE }
 /** Number of interrupt vector arrays for the PORT module. */
#define PORT_IRQS_ARR_COUNT                      (1u)
 /** Number of interrupt channels for the PORT module. */
#define PORT_IRQS_CH_COUNT                       (1u)
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PORTA_IRQn, PORTB_IRQn, PORTC_IRQn, PORTD_IRQn, PORTE_IRQn }
/* ----------------------------------------------------------------------------
   -- PCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/* PCR Bit Fields */
#define PORT_PCR_PS_MASK                         0x1u
#define PORT_PCR_PS_SHIFT                        0u
#define PORT_PCR_PS_WIDTH                        1u
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PS_SHIFT))&PORT_PCR_PS_MASK)
#define PORT_PCR_PE_MASK                         0x2u
#define PORT_PCR_PE_SHIFT                        1u
#define PORT_PCR_PE_WIDTH                        1u
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PE_SHIFT))&PORT_PCR_PE_MASK)
#define PORT_PCR_PFE_MASK                        0x10u
#define PORT_PCR_PFE_SHIFT                       4u
#define PORT_PCR_PFE_WIDTH                       1u
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_PFE_SHIFT))&PORT_PCR_PFE_MASK)
#define PORT_PCR_DSE_MASK                        0x40u
#define PORT_PCR_DSE_SHIFT                       6u
#define PORT_PCR_DSE_WIDTH                       1u
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_DSE_SHIFT))&PORT_PCR_DSE_MASK)
#define PORT_PCR_MUX_MASK                        0x700u
#define PORT_PCR_MUX_SHIFT                       8u
#define PORT_PCR_MUX_WIDTH                       3u
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK)
#define PORT_PCR_LK_MASK                         0x8000u
#define PORT_PCR_LK_SHIFT                        15u
#define PORT_PCR_LK_WIDTH                        1u
#define PORT_PCR_LK(x)                           (((uint32_t)(((uint32_t)(x))<<PORT_PCR_LK_SHIFT))&PORT_PCR_LK_MASK)
#define PORT_PCR_IRQC_MASK                       0xF0000u
#define PORT_PCR_IRQC_SHIFT                      16u
#define PORT_PCR_IRQC_WIDTH                      4u
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        0x1000000u
#define PORT_PCR_ISF_SHIFT                       24u
#define PORT_PCR_ISF_WIDTH                       1u
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_PCR_ISF_SHIFT))&PORT_PCR_ISF_MASK)
/* GPCLR Bit Fields */
#define PORT_GPCLR_GPWD_MASK                     0xFFFFu
#define PORT_GPCLR_GPWD_SHIFT                    0u
#define PORT_GPCLR_GPWD_WIDTH                    16u
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCLR_GPWE_SHIFT                    16u
#define PORT_GPCLR_GPWE_WIDTH                    16u
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK)
/* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MASK                     0xFFFFu
#define PORT_GPCHR_GPWD_SHIFT                    0u
#define PORT_GPCHR_GPWD_WIDTH                    16u
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCHR_GPWE_SHIFT                    16u
#define PORT_GPCHR_GPWE_WIDTH                    16u
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK)
/* GICLR Bit Fields */
#define PORT_GICLR_GIWE_MASK                     0xFFFFu
#define PORT_GICLR_GIWE_SHIFT                    0u
#define PORT_GICLR_GIWE_WIDTH                    16u
#define PORT_GICLR_GIWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GICLR_GIWE_SHIFT))&PORT_GICLR_GIWE_MASK)
#define PORT_GICLR_GIWD_MASK                     0xFFFF0000u
#define PORT_GICLR_GIWD_SHIFT                    16u
#define PORT_GICLR_GIWD_WIDTH                    16u
#define PORT_GICLR_GIWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GICLR_GIWD_SHIFT))&PORT_GICLR_GIWD_MASK)
/* GICHR Bit Fields */
#define PORT_GICHR_GIWE_MASK                     0xFFFFu
#define PORT_GICHR_GIWE_SHIFT                    0u
#define PORT_GICHR_GIWE_WIDTH                    16u
#define PORT_GICHR_GIWE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GICHR_GIWE_SHIFT))&PORT_GICHR_GIWE_MASK)
#define PORT_GICHR_GIWD_MASK                     0xFFFF0000u
#define PORT_GICHR_GIWD_SHIFT                    16u
#define PORT_GICHR_GIWD_WIDTH                    16u
#define PORT_GICHR_GIWD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_GICHR_GIWD_SHIFT))&PORT_GICHR_GIWD_MASK)
/* ISFR Bit Fields */
#define PORT_ISFR_ISF_MASK                       0xFFFFFFFFu
#define PORT_ISFR_ISF_SHIFT                      0u
#define PORT_ISFR_ISF_WIDTH                      32u
#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_ISFR_ISF_SHIFT))&PORT_ISFR_ISF_MASK)
/* DFER Bit Fields */
#define PORT_DFER_DFE_MASK                       0xFFFFFFFFu
#define PORT_DFER_DFE_SHIFT                      0u
#define PORT_DFER_DFE_WIDTH                      32u
#define PORT_DFER_DFE(x)                         (((uint32_t)(((uint32_t)(x))<<PORT_DFER_DFE_SHIFT))&PORT_DFER_DFE_MASK)
/* DFCR Bit Fields */
#define PORT_DFCR_CS_MASK                        0x1u
#define PORT_DFCR_CS_SHIFT                       0u
#define PORT_DFCR_CS_WIDTH                       1u
#define PORT_DFCR_CS(x)                          (((uint32_t)(((uint32_t)(x))<<PORT_DFCR_CS_SHIFT))&PORT_DFCR_CS_MASK)
/* DFWR Bit Fields */
#define PORT_DFWR_FILT_MASK                      0x1Fu
#define PORT_DFWR_FILT_SHIFT                     0u
#define PORT_DFWR_FILT_WIDTH                     5u
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK)
/*!
 * @addtogroup PCC_Peripheral_Access_Layer PCC Peripheral Access Layer
 * @{
 */


/** PCC - Size of Registers Arrays */
#define PCC_PCCn_COUNT                           116u

/** PCC - Register Layout Typedef */
typedef struct {
  uint32_t PCCn[PCC_PCCn_COUNT];              /**< PCC Reserved Register 0..PCC CMP0 Register, array offset: 0x0, array step: 0x4 */
} PCC_Type, *PCC_MemMapPtr;

 /** Number of instances of the PCC module. */
#define PCC_INSTANCE_COUNT                       (1u)


/* PCC - Peripheral instance base addresses */
/** Peripheral PCC base address */
#define PCC_BASE                                 (0x40065000u)
/** Peripheral PCC base pointer */
#define PCC                                      ((PCC_Type *)PCC_BASE)
/** Array initializer of PCC peripheral base addresses */
#define PCC_BASE_ADDRS                           { PCC_BASE }
/** Array initializer of PCC peripheral base pointers */
#define PCC_BASE_PTRS                            { PCC }

/* PCC index offsets */
#define PCC_FTFC_INDEX                           32
#define PCC_DMAMUX_INDEX                         33
#define PCC_FlexCAN0_INDEX                       36
#define PCC_FlexCAN1_INDEX                       37
#define PCC_FTM3_INDEX                           38
#define PCC_ADC1_INDEX                           39
#define PCC_FlexCAN2_INDEX                       43
#define PCC_LPSPI0_INDEX                         44
#define PCC_LPSPI1_INDEX                         45
#define PCC_LPSPI2_INDEX                         46
#define PCC_PDB1_INDEX                           49
#define PCC_CRC_INDEX                            50
#define PCC_PDB0_INDEX                           54
#define PCC_LPIT_INDEX                           55
#define PCC_FTM0_INDEX                           56
#define PCC_FTM1_INDEX                           57
#define PCC_FTM2_INDEX                           58
#define PCC_ADC0_INDEX                           59
#define PCC_RTC_INDEX                            61
#define PCC_LPTMR0_INDEX                         64
#define PCC_PORTA_INDEX                          73
#define PCC_PORTB_INDEX                          74
#define PCC_PORTC_INDEX                          75
#define PCC_PORTD_INDEX                          76
#define PCC_PORTE_INDEX                          77
#define PCC_FlexIO_INDEX                         90
#define PCC_EWM_INDEX                            97
#define PCC_LPI2C0_INDEX                         102
#define PCC_LPUART0_INDEX                        106
#define PCC_LPUART1_INDEX                        107
#define PCC_LPUART2_INDEX                        108
#define PCC_CMP0_INDEX                           115

/* ----------------------------------------------------------------------------
   -- PCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Register_Masks PCC Register Masks
 * @{
 */

/* PCCn Bit Fields */
#define PCC_PCCn_PCD_MASK                        0x7u
#define PCC_PCCn_PCD_SHIFT                       0u
#define PCC_PCCn_PCD_WIDTH                       3u
#define PCC_PCCn_PCD(x)                          (((uint32_t)(((uint32_t)(x))<<PCC_PCCn_PCD_SHIFT))&PCC_PCCn_PCD_MASK)
#define PCC_PCCn_FRAC_MASK                       0x8u
#define PCC_PCCn_FRAC_SHIFT                      3u
#define PCC_PCCn_FRAC_WIDTH                      1u
#define PCC_PCCn_FRAC(x)                         (((uint32_t)(((uint32_t)(x))<<PCC_PCCn_FRAC_SHIFT))&PCC_PCCn_FRAC_MASK)
#define PCC_PCCn_PCS_MASK                        0x7000000u
#define PCC_PCCn_PCS_SHIFT                       24u
#define PCC_PCCn_PCS_WIDTH                       3u
#define PCC_PCCn_PCS(x)                          (((uint32_t)(((uint32_t)(x))<<PCC_PCCn_PCS_SHIFT))&PCC_PCCn_PCS_MASK)
#define PCC_PCCn_CGC_MASK                        0x40000000u
#define PCC_PCCn_CGC_SHIFT                       30u
#define PCC_PCCn_CGC_WIDTH                       1u
#define PCC_PCCn_CGC(x)                          (((uint32_t)(((uint32_t)(x))<<PCC_PCCn_CGC_SHIFT))&PCC_PCCn_CGC_MASK)
#define PCC_PCCn_PR_MASK                         0x80000000u
#define PCC_PCCn_PR_SHIFT                        31u
#define PCC_PCCn_PR_WIDTH                        1u
#define PCC_PCCn_PR(x)                           (((uint32_t)(((uint32_t)(x))<<PCC_PCCn_PR_SHIFT))&PCC_PCCn_PR_MASK)

/*!
 * @}
 */ /* end of group PCC_Register_Masks */


/*!
 * @}
 */ /* end of group PCC_Peripheral_Access_Layer */


typedef struct {
   uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
   uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
   uint32_t GLOBAL;                            /**< LPUART Global Register, offset: 0x8 */
   uint32_t PINCFG;                            /**< LPUART Pin Configuration Register, offset: 0xC */
   uint32_t BAUD;                              /**< LPUART Baud Rate Register, offset: 0x10 */
   uint32_t STAT;                              /**< LPUART Status Register, offset: 0x14 */
   uint32_t CTRL;                              /**< LPUART Control Register, offset: 0x18 */
   uint32_t DATA;                              /**< LPUART Data Register, offset: 0x1C */
   uint32_t MATCH;                             /**< LPUART Match Address Register, offset: 0x20 */
   uint32_t MODIR;                             /**< LPUART Modem IrDA Register, offset: 0x24 */
   uint32_t FIFO;                              /**< LPUART FIFO Register, offset: 0x28 */
   uint32_t WATER;                             /**< LPUART Watermark Register, offset: 0x2C */
} LPUART_Type, *LPUART_MemMapPtr;

 /** Number of instances of the LPUART module. */
#define LPUART_INSTANCE_COUNT                    (3u)


/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x4006A000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x4006B000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x4006C000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2 }
 /** Number of interrupt vector arrays for the LPUART module. */
#define LPUART_IRQS_ARR_COUNT                    (1u)
 /** Number of interrupt channels for the RX_TX type of LPUART module. */
#define LPUART_RX_TX_IRQS_CH_COUNT               (1u)
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_RxTx_IRQn, LPUART1_RxTx_IRQn, LPUART2_RxTx_IRQn }


/* ----------------------------------------------------------------------------
   -- LPIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Peripheral_Access_Layer LPIT Peripheral Access Layer
 * @{
 */


/** LPIT - Size of Registers Arrays */
#define LPIT_TMR_COUNT                           4u

/** LPIT - Register Layout Typedef */
typedef struct {
  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  uint32_t MCR;                               /**< Module Control Register, offset: 0x8 */
  uint32_t MSR;                               /**< Module Status Register, offset: 0xC */
  uint32_t MIER;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  uint32_t SETTEN;                            /**< Set Timer Enable Register, offset: 0x14 */
  uint32_t CLRTEN;                            /**< Clear Timer Enable Register, offset: 0x18 */
  uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    uint32_t TVAL;                              /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
    uint32_t CVAL;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
    uint32_t TCTRL;                             /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } TMR[LPIT_TMR_COUNT];
	
} LPIT_Type;

 /** Number of instances of the LPIT module. */
#define LPIT_INSTANCE_COUNT                      (1u)


/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0x40037000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0 }
 /** Number of interrupt vector arrays for the LPIT module. */
#define LPIT_IRQS_ARR_COUNT                      (1u)
 /** Number of interrupt channels for the LPIT module. */
#define LPIT_IRQS_CH_COUNT                       (4u)
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { LPIT0_Ch0_IRQn, LPIT0_Ch1_IRQn, LPIT0_Ch2_IRQn, LPIT0_Ch3_IRQn }

/* ----------------------------------------------------------------------------
   -- LPIT Register Masks
   ---------------------------------------------------------------------------- */

/* VERID Bit Fields */
#define LPIT_VERID_FEATURE_MASK                  0xFFFFu
#define LPIT_VERID_FEATURE_SHIFT                 0u
#define LPIT_VERID_FEATURE_WIDTH                 16u
#define LPIT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x))<<LPIT_VERID_FEATURE_SHIFT))&LPIT_VERID_FEATURE_MASK)
#define LPIT_VERID_MINOR_MASK                    0xFF0000u
#define LPIT_VERID_MINOR_SHIFT                   16u
#define LPIT_VERID_MINOR_WIDTH                   8u
#define LPIT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x))<<LPIT_VERID_MINOR_SHIFT))&LPIT_VERID_MINOR_MASK)
#define LPIT_VERID_MAJOR_MASK                    0xFF000000u
#define LPIT_VERID_MAJOR_SHIFT                   24u
#define LPIT_VERID_MAJOR_WIDTH                   8u
#define LPIT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x))<<LPIT_VERID_MAJOR_SHIFT))&LPIT_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPIT_PARAM_CHANNEL_MASK                  0xFFu
#define LPIT_PARAM_CHANNEL_SHIFT                 0u
#define LPIT_PARAM_CHANNEL_WIDTH                 8u
#define LPIT_PARAM_CHANNEL(x)                    (((uint32_t)(((uint32_t)(x))<<LPIT_PARAM_CHANNEL_SHIFT))&LPIT_PARAM_CHANNEL_MASK)
#define LPIT_PARAM_EXT_TRIG_MASK                 0xFF00u
#define LPIT_PARAM_EXT_TRIG_SHIFT                8u
#define LPIT_PARAM_EXT_TRIG_WIDTH                8u
#define LPIT_PARAM_EXT_TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<LPIT_PARAM_EXT_TRIG_SHIFT))&LPIT_PARAM_EXT_TRIG_MASK)
/* MCR Bit Fields */
#define LPIT_MCR_M_CEN_MASK                      0x1u
#define LPIT_MCR_M_CEN_SHIFT                     0u
#define LPIT_MCR_M_CEN_WIDTH                     1u
#define LPIT_MCR_M_CEN(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MCR_M_CEN_SHIFT))&LPIT_MCR_M_CEN_MASK)
#define LPIT_MCR_SW_RST_MASK                     0x2u
#define LPIT_MCR_SW_RST_SHIFT                    1u
#define LPIT_MCR_SW_RST_WIDTH                    1u
#define LPIT_MCR_SW_RST(x)                       (((uint32_t)(((uint32_t)(x))<<LPIT_MCR_SW_RST_SHIFT))&LPIT_MCR_SW_RST_MASK)
#define LPIT_MCR_DOZE_EN_MASK                    0x4u
#define LPIT_MCR_DOZE_EN_SHIFT                   2u
#define LPIT_MCR_DOZE_EN_WIDTH                   1u
#define LPIT_MCR_DOZE_EN(x)                      (((uint32_t)(((uint32_t)(x))<<LPIT_MCR_DOZE_EN_SHIFT))&LPIT_MCR_DOZE_EN_MASK)
#define LPIT_MCR_DBG_EN_MASK                     0x8u
#define LPIT_MCR_DBG_EN_SHIFT                    3u
#define LPIT_MCR_DBG_EN_WIDTH                    1u
#define LPIT_MCR_DBG_EN(x)                       (((uint32_t)(((uint32_t)(x))<<LPIT_MCR_DBG_EN_SHIFT))&LPIT_MCR_DBG_EN_MASK)
/* MSR Bit Fields */
#define LPIT_MSR_TIF0_MASK                       0x1u
#define LPIT_MSR_TIF0_SHIFT                      0u
#define LPIT_MSR_TIF0_WIDTH                      1u
#define LPIT_MSR_TIF0(x)                         (((uint32_t)(((uint32_t)(x))<<LPIT_MSR_TIF0_SHIFT))&LPIT_MSR_TIF0_MASK)
#define LPIT_MSR_TIF1_MASK                       0x2u
#define LPIT_MSR_TIF1_SHIFT                      1u
#define LPIT_MSR_TIF1_WIDTH                      1u
#define LPIT_MSR_TIF1(x)                         (((uint32_t)(((uint32_t)(x))<<LPIT_MSR_TIF1_SHIFT))&LPIT_MSR_TIF1_MASK)
#define LPIT_MSR_TIF2_MASK                       0x4u
#define LPIT_MSR_TIF2_SHIFT                      2u
#define LPIT_MSR_TIF2_WIDTH                      1u
#define LPIT_MSR_TIF2(x)                         (((uint32_t)(((uint32_t)(x))<<LPIT_MSR_TIF2_SHIFT))&LPIT_MSR_TIF2_MASK)
#define LPIT_MSR_TIF3_MASK                       0x8u
#define LPIT_MSR_TIF3_SHIFT                      3u
#define LPIT_MSR_TIF3_WIDTH                      1u
#define LPIT_MSR_TIF3(x)                         (((uint32_t)(((uint32_t)(x))<<LPIT_MSR_TIF3_SHIFT))&LPIT_MSR_TIF3_MASK)
/* MIER Bit Fields */
#define LPIT_MIER_TIE0_MASK                      0x1u
#define LPIT_MIER_TIE0_SHIFT                     0u
#define LPIT_MIER_TIE0_WIDTH                     1u
#define LPIT_MIER_TIE0(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MIER_TIE0_SHIFT))&LPIT_MIER_TIE0_MASK)
#define LPIT_MIER_TIE1_MASK                      0x2u
#define LPIT_MIER_TIE1_SHIFT                     1u
#define LPIT_MIER_TIE1_WIDTH                     1u
#define LPIT_MIER_TIE1(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MIER_TIE1_SHIFT))&LPIT_MIER_TIE1_MASK)
#define LPIT_MIER_TIE2_MASK                      0x4u
#define LPIT_MIER_TIE2_SHIFT                     2u
#define LPIT_MIER_TIE2_WIDTH                     1u
#define LPIT_MIER_TIE2(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MIER_TIE2_SHIFT))&LPIT_MIER_TIE2_MASK)
#define LPIT_MIER_TIE3_MASK                      0x8u
#define LPIT_MIER_TIE3_SHIFT                     3u
#define LPIT_MIER_TIE3_WIDTH                     1u
#define LPIT_MIER_TIE3(x)                        (((uint32_t)(((uint32_t)(x))<<LPIT_MIER_TIE3_SHIFT))&LPIT_MIER_TIE3_MASK)
/* SETTEN Bit Fields */
#define LPIT_SETTEN_SET_T_EN_0_MASK              0x1u
#define LPIT_SETTEN_SET_T_EN_0_SHIFT             0u
#define LPIT_SETTEN_SET_T_EN_0_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_0(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_SETTEN_SET_T_EN_0_SHIFT))&LPIT_SETTEN_SET_T_EN_0_MASK)
#define LPIT_SETTEN_SET_T_EN_1_MASK              0x2u
#define LPIT_SETTEN_SET_T_EN_1_SHIFT             1u
#define LPIT_SETTEN_SET_T_EN_1_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_1(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_SETTEN_SET_T_EN_1_SHIFT))&LPIT_SETTEN_SET_T_EN_1_MASK)
#define LPIT_SETTEN_SET_T_EN_2_MASK              0x4u
#define LPIT_SETTEN_SET_T_EN_2_SHIFT             2u
#define LPIT_SETTEN_SET_T_EN_2_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_2(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_SETTEN_SET_T_EN_2_SHIFT))&LPIT_SETTEN_SET_T_EN_2_MASK)
#define LPIT_SETTEN_SET_T_EN_3_MASK              0x8u
#define LPIT_SETTEN_SET_T_EN_3_SHIFT             3u
#define LPIT_SETTEN_SET_T_EN_3_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_3(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_SETTEN_SET_T_EN_3_SHIFT))&LPIT_SETTEN_SET_T_EN_3_MASK)
/* CLRTEN Bit Fields */
#define LPIT_CLRTEN_CLR_T_EN_0_MASK              0x1u
#define LPIT_CLRTEN_CLR_T_EN_0_SHIFT             0u
#define LPIT_CLRTEN_CLR_T_EN_0_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_0(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_CLRTEN_CLR_T_EN_0_SHIFT))&LPIT_CLRTEN_CLR_T_EN_0_MASK)
#define LPIT_CLRTEN_CLR_T_EN_1_MASK              0x2u
#define LPIT_CLRTEN_CLR_T_EN_1_SHIFT             1u
#define LPIT_CLRTEN_CLR_T_EN_1_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_1(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_CLRTEN_CLR_T_EN_1_SHIFT))&LPIT_CLRTEN_CLR_T_EN_1_MASK)
#define LPIT_CLRTEN_CLR_T_EN_2_MASK              0x4u
#define LPIT_CLRTEN_CLR_T_EN_2_SHIFT             2u
#define LPIT_CLRTEN_CLR_T_EN_2_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_2(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_CLRTEN_CLR_T_EN_2_SHIFT))&LPIT_CLRTEN_CLR_T_EN_2_MASK)
#define LPIT_CLRTEN_CLR_T_EN_3_MASK              0x8u
#define LPIT_CLRTEN_CLR_T_EN_3_SHIFT             3u
#define LPIT_CLRTEN_CLR_T_EN_3_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_3(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_CLRTEN_CLR_T_EN_3_SHIFT))&LPIT_CLRTEN_CLR_T_EN_3_MASK)
/* TMR_TVAL Bit Fields */
#define LPIT_TMR_TVAL_TMR_VAL_MASK               0xFFFFFFFFu
#define LPIT_TMR_TVAL_TMR_VAL_SHIFT              0u
#define LPIT_TMR_TVAL_TMR_VAL_WIDTH              32u
#define LPIT_TMR_TVAL_TMR_VAL(x)                 (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_TVAL_TMR_VAL_SHIFT))&LPIT_TMR_TVAL_TMR_VAL_MASK)
/* TMR_CVAL Bit Fields */
#define LPIT_TMR_CVAL_TMR_CUR_VAL_MASK           0xFFFFFFFFu
#define LPIT_TMR_CVAL_TMR_CUR_VAL_SHIFT          0u
#define LPIT_TMR_CVAL_TMR_CUR_VAL_WIDTH          32u
#define LPIT_TMR_CVAL_TMR_CUR_VAL(x)             (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_CVAL_TMR_CUR_VAL_SHIFT))&LPIT_TMR_CVAL_TMR_CUR_VAL_MASK)
/* TMR_TCTRL Bit Fields */
#define LPIT_TMR_TCTRL_T_EN_MASK                 0x1u
#define LPIT_TMR_TCTRL_T_EN_SHIFT                0u
#define LPIT_TMR_TCTRL_T_EN_WIDTH                1u
#define LPIT_TMR_TCTRL_T_EN(x)                   (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_TCTRL_T_EN_SHIFT))&LPIT_TMR_TCTRL_T_EN_MASK)
#define LPIT_TMR_TCTRL_CHAIN_MASK                0x2u
#define LPIT_TMR_TCTRL_CHAIN_SHIFT               1u
#define LPIT_TMR_TCTRL_CHAIN_WIDTH               1u
#define LPIT_TMR_TCTRL_CHAIN(x)                  (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_TCTRL_CHAIN_SHIFT))&LPIT_TMR_TCTRL_CHAIN_MASK)
#define LPIT_TMR_TCTRL_MODE_MASK                 0xCu
#define LPIT_TMR_TCTRL_MODE_SHIFT                2u
#define LPIT_TMR_TCTRL_MODE_WIDTH                2u
#define LPIT_TMR_TCTRL_MODE(x)                   (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_TCTRL_MODE_SHIFT))&LPIT_TMR_TCTRL_MODE_MASK)
#define LPIT_TMR_TCTRL_TSOT_MASK                 0x10000u
#define LPIT_TMR_TCTRL_TSOT_SHIFT                16u
#define LPIT_TMR_TCTRL_TSOT_WIDTH                1u
#define LPIT_TMR_TCTRL_TSOT(x)                   (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_TCTRL_TSOT_SHIFT))&LPIT_TMR_TCTRL_TSOT_MASK)
#define LPIT_TMR_TCTRL_TSOI_MASK                 0x20000u
#define LPIT_TMR_TCTRL_TSOI_SHIFT                17u
#define LPIT_TMR_TCTRL_TSOI_WIDTH                1u
#define LPIT_TMR_TCTRL_TSOI(x)                   (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_TCTRL_TSOI_SHIFT))&LPIT_TMR_TCTRL_TSOI_MASK)
#define LPIT_TMR_TCTRL_TROT_MASK                 0x40000u
#define LPIT_TMR_TCTRL_TROT_SHIFT                18u
#define LPIT_TMR_TCTRL_TROT_WIDTH                1u
#define LPIT_TMR_TCTRL_TROT(x)                   (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_TCTRL_TROT_SHIFT))&LPIT_TMR_TCTRL_TROT_MASK)
#define LPIT_TMR_TCTRL_TRG_SRC_MASK              0x800000u
#define LPIT_TMR_TCTRL_TRG_SRC_SHIFT             23u
#define LPIT_TMR_TCTRL_TRG_SRC_WIDTH             1u
#define LPIT_TMR_TCTRL_TRG_SRC(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_TCTRL_TRG_SRC_SHIFT))&LPIT_TMR_TCTRL_TRG_SRC_MASK)
#define LPIT_TMR_TCTRL_TRG_SEL_MASK              0xF000000u
#define LPIT_TMR_TCTRL_TRG_SEL_SHIFT             24u
#define LPIT_TMR_TCTRL_TRG_SEL_WIDTH             4u
#define LPIT_TMR_TCTRL_TRG_SEL(x)                (((uint32_t)(((uint32_t)(x))<<LPIT_TMR_TCTRL_TRG_SEL_SHIFT))&LPIT_TMR_TCTRL_TRG_SEL_MASK)

/* ----------------------------------------------------------------------------
   -- LPSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Peripheral_Access_Layer LPSPI Peripheral Access Layer
 * @{
 */


/** LPSPI - Size of Registers Arrays */

/** LPSPI - Register Layout Typedef */
typedef struct {
  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  uint8_t RESERVED_0[8];
  uint32_t CR;                                /**< Control Register, offset: 0x10 */
  uint32_t SR;                                /**< Status Register, offset: 0x14 */
  uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x18 */
  uint32_t DER;                               /**< DMA Enable Register, offset: 0x1C */
  uint32_t CFGR0;                             /**< Configuration Register 0, offset: 0x20 */
  uint32_t CFGR1;                             /**< Configuration Register 1, offset: 0x24 */
  uint8_t RESERVED_1[8];
  uint32_t DMR0;                              /**< Data Match Register 0, offset: 0x30 */
  uint32_t DMR1;                              /**< Data Match Register 1, offset: 0x34 */
  uint8_t RESERVED_2[8];
  uint32_t CCR;                               /**< Clock Configuration Register, offset: 0x40 */
  uint8_t RESERVED_3[20];
  uint32_t FCR;                               /**< FIFO Control Register, offset: 0x58 */
  uint32_t FSR;                               /**< FIFO Status Register, offset: 0x5C */
  uint32_t TCR;                               /**< Transmit Command Register, offset: 0x60 */
  uint32_t TDR;                               /**< Transmit Data Register, offset: 0x64 */
  uint8_t RESERVED_4[8];
  uint32_t RSR;                               /**< Receive Status Register, offset: 0x70 */
  uint32_t RDR;                               /**< Receive Data Register, offset: 0x74 */
} LPSPI_Type, *LPSPI_MemMapPtr;

 /** Number of instances of the LPSPI module. */
#define LPSPI_INSTANCE_COUNT                     (3u)

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x4002C000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x4002D000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x4002E000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2 }
 /** Number of interrupt vector arrays for the LPSPI module. */
#define LPSPI_IRQS_ARR_COUNT                     (1u)
 /** Number of interrupt channels for the LPSPI module. */
#define LPSPI_IRQS_CH_COUNT                      (1u)
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, LPSPI2_IRQn }

