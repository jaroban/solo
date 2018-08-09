//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library includes]
#include "em_system.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_assert.h"
#include "em_adc.h"
#include "em_cryotimer.h"
#include "em_crypto.h"
#include "em_gpio.h"
#include "em_timer.h"
#include "em_usart.h"
// [Library includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	CHIP_Init();

	EMU_enter_DefaultMode_from_RESET();
	CMU_enter_DefaultMode_from_RESET();
	ADC0_enter_DefaultMode_from_RESET();
	USART0_enter_DefaultMode_from_RESET();
	USART1_enter_DefaultMode_from_RESET();
	TIMER0_enter_DefaultMode_from_RESET();
	CRYOTIMER_enter_DefaultMode_from_RESET();
	PORTIO_enter_DefaultMode_from_RESET();
	// [Config Calls]$

}

//================================================================================
// EMU_enter_DefaultMode_from_RESET
//================================================================================
extern void EMU_enter_DefaultMode_from_RESET(void) {

	// $[EMU Initialization]
	/* External power circuit not wired for DCDC; shut down regulator */
	EMU_DCDCPowerOff();
	/* Initialize EM2/EM3 mode */
	EMU_EM23Init_TypeDef em23Init = EMU_EM23INIT_DEFAULT;

	em23Init.em23VregFullEn = 0;

	EMU_EM23Init(&em23Init);
	/* Initialize EM4H/S mode */
	EMU_EM4Init_TypeDef em4Init = EMU_EM4INIT_DEFAULT;

	em4Init.retainLfrco = 0;
	em4Init.retainLfxo = 0;
	em4Init.retainUlfrco = 0;
	em4Init.em4State = emuEM4Shutoff;
	em4Init.pinRetentionMode = emuPinRetentionDisable;

	EMU_EM4Init(&em4Init);
	// [EMU Initialization]$

}

//================================================================================
// LFXO_enter_DefaultMode_from_RESET
//================================================================================
extern void LFXO_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// CMU_enter_DefaultMode_from_RESET
//================================================================================
extern void CMU_enter_DefaultMode_from_RESET(void) {

	// $[High Frequency Clock Setup]
	/* Initializing HFXO */
	CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;

	CMU_HFXOInit(&hfxoInit);

	/* Setting system HFRCO frequency */
	CMU_HFRCOFreqSet (cmuHFRCOFreq_38M0Hz);

	/* Using HFRCO as high frequency clock, HFCLK */
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO);
	// [High Frequency Clock Setup]$

	// $[LE clocks enable]
	/* Enable ULFRCO oscillator, and wait for it to be stable */
	CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);

	// [LE clocks enable]$

	// $[LFACLK Setup]
	/* LFACLK is disabled */
	// [LFACLK Setup]$
	// $[LFBCLK Setup]
	/* LFBCLK is disabled */
	// [LFBCLK Setup]$
	// $[LFECLK Setup]
	/* LFECLK is disabled */
	// [LFECLK Setup]$
	// $[Peripheral Clock enables]
	/* Enable clock for HF peripherals */
	CMU_ClockEnable(cmuClock_HFPER, true);

	/* Enable clock for ADC0 */
	CMU_ClockEnable(cmuClock_ADC0, true);

	/* Enable clock for CRYOTIMER */
	CMU_ClockEnable(cmuClock_CRYOTIMER, true);

	/* Enable clock for TIMER0 */
	CMU_ClockEnable(cmuClock_TIMER0, true);

	/* Enable clock for USART0 */
	CMU_ClockEnable(cmuClock_USART0, true);

	/* Enable clock for USART1 */
	CMU_ClockEnable(cmuClock_USART1, true);

	/* Enable clock for GPIO by default */
	CMU_ClockEnable(cmuClock_GPIO, true);

	// [Peripheral Clock enables]$

	// $[Clock output]
	/* Disable CLKOUT0 output */
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_CLKOUTSEL0_MASK)
			| CMU_CTRL_CLKOUTSEL0_DISABLED;
	/* Disable CLKOUT1 output */
	CMU->CTRL = (CMU->CTRL & ~_CMU_CTRL_CLKOUTSEL1_MASK)
			| CMU_CTRL_CLKOUTSEL1_DISABLED;

	// [Clock output]$

	// $[CMU_IO]
	/* Disable CLKOUT0 pin */
	CMU->ROUTEPEN &= ~CMU_ROUTEPEN_CLKOUT0PEN;

	/* Disable CLKOUT1 pin */
	CMU->ROUTEPEN &= ~CMU_ROUTEPEN_CLKOUT1PEN;

	// [CMU_IO]$

}

//================================================================================
// ADC0_enter_DefaultMode_from_RESET
//================================================================================
extern void ADC0_enter_DefaultMode_from_RESET(void) {

	// $[ADC0_Init]
	ADC_Init_TypeDef ADC0_init = ADC_INIT_DEFAULT;

	ADC0_init.ovsRateSel = adcOvsRateSel2;
	ADC0_init.warmUpMode = adcWarmupNormal;
	ADC0_init.timebase = ADC_TimebaseCalc(0);
	ADC0_init.prescale = ADC_PrescaleCalc(7000000, 0);
	ADC0_init.tailgate = 0;
	ADC0_init.em2ClockConfig = adcEm2Disabled;

	ADC_Init(ADC0, &ADC0_init);
	// [ADC0_Init]$

	// $[ADC0_InputConfiguration]
	// [ADC0_InputConfiguration]$

}

//================================================================================
// ACMP0_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP0_enter_DefaultMode_from_RESET(void) {

	// $[ACMP0_Init]
	// [ACMP0_Init]$

	// $[ACMP0_IO]
	// [ACMP0_IO]$

}

//================================================================================
// ACMP1_enter_DefaultMode_from_RESET
//================================================================================
extern void ACMP1_enter_DefaultMode_from_RESET(void) {

	// $[ACMP1_Init]
	// [ACMP1_Init]$

	// $[ACMP1_IO]
	// [ACMP1_IO]$

}

//================================================================================
// IDAC0_enter_DefaultMode_from_RESET
//================================================================================
extern void IDAC0_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// RTCC_enter_DefaultMode_from_RESET
//================================================================================
extern void RTCC_enter_DefaultMode_from_RESET(void) {

	// $[Compare/Capture Channel 0 init]
	// [Compare/Capture Channel 0 init]$

	// $[Compare/Capture Channel 1 init]
	// [Compare/Capture Channel 1 init]$

	// $[Compare/Capture Channel 2 init]
	// [Compare/Capture Channel 2 init]$

	// $[RTCC init]
	// [RTCC init]$

}

//================================================================================
// USART0_enter_DefaultMode_from_RESET
//================================================================================
extern void USART0_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	USART_InitAsync_TypeDef initasync = USART_INITASYNC_DEFAULT;

	initasync.enable = usartDisable;
	initasync.baudrate = 115200;
	initasync.databits = usartDatabits8;
	initasync.parity = usartNoParity;
	initasync.stopbits = usartStopbits1;
	initasync.oversampling = usartOVS16;
#if defined( USART_INPUT_RXPRS ) && defined( USART_CTRL_MVDIS )
	initasync.mvdis = 0;
	initasync.prsRxEnable = 0;
	initasync.prsRxCh = 0;
#endif

	USART_InitAsync(USART0, &initasync);
	// [USART_InitAsync]$

	// $[USART_InitSync]
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART0, &initprs);
	// [USART_InitPrsTrigger]$

	// $[USART_InitIO]
	/* Disable CLK pin */
	USART0->ROUTELOC0 = (USART0->ROUTELOC0 & (~_USART_ROUTELOC0_CLKLOC_MASK))
			| USART_ROUTELOC0_CLKLOC_LOC4;
	USART0->ROUTEPEN = USART0->ROUTEPEN & (~USART_ROUTEPEN_CLKPEN);

	/* Disable CS pin */
	USART0->ROUTELOC0 = (USART0->ROUTELOC0 & (~_USART_ROUTELOC0_CSLOC_MASK))
			| USART_ROUTELOC0_CSLOC_LOC3;
	USART0->ROUTEPEN = USART0->ROUTEPEN & (~USART_ROUTEPEN_CSPEN);

	/* Disable CTS pin */
	USART0->ROUTELOC1 = (USART0->ROUTELOC1 & (~_USART_ROUTELOC1_CTSLOC_MASK))
			| USART_ROUTELOC1_CTSLOC_LOC2;
	USART0->ROUTEPEN = USART0->ROUTEPEN & (~USART_ROUTEPEN_CTSPEN);

	/* Disable RTS pin */
	USART0->ROUTELOC1 = (USART0->ROUTELOC1 & (~_USART_ROUTELOC1_RTSLOC_MASK))
			| USART_ROUTELOC1_RTSLOC_LOC1;
	USART0->ROUTEPEN = USART0->ROUTEPEN & (~USART_ROUTEPEN_RTSPEN);

	/* Set up RX pin */
	USART0->ROUTELOC0 = (USART0->ROUTELOC0 & (~_USART_ROUTELOC0_RXLOC_MASK))
			| USART_ROUTELOC0_RXLOC_LOC0;
	USART0->ROUTEPEN = USART0->ROUTEPEN | USART_ROUTEPEN_RXPEN;

	/* Set up TX pin */
	USART0->ROUTELOC0 = (USART0->ROUTELOC0 & (~_USART_ROUTELOC0_TXLOC_MASK))
			| USART_ROUTELOC0_TXLOC_LOC20;
	USART0->ROUTEPEN = USART0->ROUTEPEN | USART_ROUTEPEN_TXPEN;

	// [USART_InitIO]$

	// $[USART_Misc]
	/* Disable CTS */
	USART0->CTRLX = USART0->CTRLX & (~USART_CTRLX_CTSEN);
	/* Set CTS active low */
	USART0->CTRLX = USART0->CTRLX & (~USART_CTRLX_CTSINV);
	/* Set RTS active low */
	USART0->CTRLX = USART0->CTRLX & (~USART_CTRLX_RTSINV);
	/* Set CS active low */
	USART0->CTRL = USART0->CTRL & (~USART_CTRL_CSINV);
	/* Set TX active high */
	USART0->CTRL = USART0->CTRL & (~USART_CTRL_TXINV);
	/* Set RX active high */
	USART0->CTRL = USART0->CTRL & (~USART_CTRL_RXINV);
	// [USART_Misc]$

	// $[USART_Enable]

	/* Enable USART if opted by user */
	USART_Enable(USART0, usartEnable);
	// [USART_Enable]$

}

//================================================================================
// USART1_enter_DefaultMode_from_RESET
//================================================================================
extern void USART1_enter_DefaultMode_from_RESET(void) {

	// $[USART_InitAsync]
	// [USART_InitAsync]$

	// $[USART_InitSync]
	USART_InitSync_TypeDef initsync = USART_INITSYNC_DEFAULT;

	initsync.enable = usartDisable;
	initsync.baudrate = 130000;
	initsync.databits = usartDatabits8;
	initsync.master = 1;
	initsync.msbf = 1;
	initsync.clockMode = usartClockMode0;
#if defined( USART_INPUT_RXPRS ) && defined( USART_TRIGCTRL_AUTOTXTEN )
	initsync.prsRxEnable = 0;
	initsync.prsRxCh = 0;
	initsync.autoTx = 0;
#endif

	USART_InitSync(USART1, &initsync);
	// [USART_InitSync]$

	// $[USART_InitPrsTrigger]
	USART_PrsTriggerInit_TypeDef initprs = USART_INITPRSTRIGGER_DEFAULT;

	initprs.rxTriggerEnable = 0;
	initprs.txTriggerEnable = 0;
	initprs.prsTriggerChannel = usartPrsTriggerCh0;

	USART_InitPrsTrigger(USART1, &initprs);
	// [USART_InitPrsTrigger]$

	// $[USART_InitIO]
	/* Set up CLK pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_CLKLOC_MASK))
			| USART_ROUTELOC0_CLKLOC_LOC4;
	USART1->ROUTEPEN = USART1->ROUTEPEN | USART_ROUTEPEN_CLKPEN;

	/* Disable CS pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_CSLOC_MASK))
			| USART_ROUTELOC0_CSLOC_LOC3;
	USART1->ROUTEPEN = USART1->ROUTEPEN & (~USART_ROUTEPEN_CSPEN);

	/* Disable CTS pin */
	USART1->ROUTELOC1 = (USART1->ROUTELOC1 & (~_USART_ROUTELOC1_CTSLOC_MASK))
			| USART_ROUTELOC1_CTSLOC_LOC2;
	USART1->ROUTEPEN = USART1->ROUTEPEN & (~USART_ROUTEPEN_CTSPEN);

	/* Disable RTS pin */
	USART1->ROUTELOC1 = (USART1->ROUTELOC1 & (~_USART_ROUTELOC1_RTSLOC_MASK))
			| USART_ROUTELOC1_RTSLOC_LOC1;
	USART1->ROUTEPEN = USART1->ROUTEPEN & (~USART_ROUTEPEN_RTSPEN);

	/* Set up RX pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_RXLOC_MASK))
			| USART_ROUTELOC0_RXLOC_LOC6;
	USART1->ROUTEPEN = USART1->ROUTEPEN | USART_ROUTEPEN_RXPEN;

	/* Set up TX pin */
	USART1->ROUTELOC0 = (USART1->ROUTELOC0 & (~_USART_ROUTELOC0_TXLOC_MASK))
			| USART_ROUTELOC0_TXLOC_LOC8;
	USART1->ROUTEPEN = USART1->ROUTEPEN | USART_ROUTEPEN_TXPEN;

	// [USART_InitIO]$

	// $[USART_Misc]
	/* Disable CTS */
	USART1->CTRLX = USART1->CTRLX & (~USART_CTRLX_CTSEN);
	/* Set CTS active low */
	USART1->CTRLX = USART1->CTRLX & (~USART_CTRLX_CTSINV);
	/* Set RTS active low */
	USART1->CTRLX = USART1->CTRLX & (~USART_CTRLX_RTSINV);
	/* Set CS active low */
	USART1->CTRL = USART1->CTRL & (~USART_CTRL_CSINV);
	/* Set TX active high */
	USART1->CTRL = USART1->CTRL & (~USART_CTRL_TXINV);
	/* Set RX active high */
	USART1->CTRL = USART1->CTRL & (~USART_CTRL_RXINV);
	// [USART_Misc]$

	// $[USART_Enable]

	/* Enable USART if opted by user */
	USART_Enable(USART1, usartEnable);
	// [USART_Enable]$

}

//================================================================================
// LEUART0_enter_DefaultMode_from_RESET
//================================================================================
extern void LEUART0_enter_DefaultMode_from_RESET(void) {

	// $[LEUART0 initialization]
	// [LEUART0 initialization]$

}

//================================================================================
// WDOG0_enter_DefaultMode_from_RESET
//================================================================================
extern void WDOG0_enter_DefaultMode_from_RESET(void) {

	// $[WDOG Initialization]
	// [WDOG Initialization]$

}

//================================================================================
// I2C0_enter_DefaultMode_from_RESET
//================================================================================
extern void I2C0_enter_DefaultMode_from_RESET(void) {

	// $[I2C0 I/O setup]
	// [I2C0 I/O setup]$

	// $[I2C0 initialization]
	// [I2C0 initialization]$

}

//================================================================================
// GPCRC_enter_DefaultMode_from_RESET
//================================================================================
extern void GPCRC_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// LDMA_enter_DefaultMode_from_RESET
//================================================================================
extern void LDMA_enter_DefaultMode_from_RESET(void) {

}

//================================================================================
// TIMER0_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER0_enter_DefaultMode_from_RESET(void) {

	// $[TIMER0 I/O setup]
	/* Set up CC0 */
	TIMER0->ROUTELOC0 = (TIMER0->ROUTELOC0 & (~_TIMER_ROUTELOC0_CC0LOC_MASK))
			| TIMER_ROUTELOC0_CC0LOC_LOC18;
	TIMER0->ROUTEPEN = TIMER0->ROUTEPEN | TIMER_ROUTEPEN_CC0PEN;
	/* Set up CC1 */
	TIMER0->ROUTELOC0 = (TIMER0->ROUTELOC0 & (~_TIMER_ROUTELOC0_CC1LOC_MASK))
			| TIMER_ROUTELOC0_CC1LOC_LOC16;
	TIMER0->ROUTEPEN = TIMER0->ROUTEPEN | TIMER_ROUTEPEN_CC1PEN;
	/* Set up CC2 */
	TIMER0->ROUTELOC0 = (TIMER0->ROUTELOC0 & (~_TIMER_ROUTELOC0_CC2LOC_MASK))
			| TIMER_ROUTELOC0_CC2LOC_LOC20;
	TIMER0->ROUTEPEN = TIMER0->ROUTEPEN | TIMER_ROUTEPEN_CC2PEN;
	/* Set up CDTI0 */
	TIMER0->ROUTELOC2 = (TIMER0->ROUTELOC2 & (~_TIMER_ROUTELOC2_CDTI0LOC_MASK))
			| TIMER_ROUTELOC2_CDTI0LOC_LOC3;
	TIMER0->ROUTEPEN = TIMER0->ROUTEPEN & (~TIMER_ROUTEPEN_CDTI0PEN);
	/* Set up CDTI1 */
	TIMER0->ROUTELOC2 = (TIMER0->ROUTELOC2 & (~_TIMER_ROUTELOC2_CDTI1LOC_MASK))
			| TIMER_ROUTELOC2_CDTI1LOC_LOC2;
	TIMER0->ROUTEPEN = TIMER0->ROUTEPEN & (~TIMER_ROUTEPEN_CDTI1PEN);
	/* Set up CDTI2 */
	TIMER0->ROUTELOC2 = (TIMER0->ROUTELOC2 & (~_TIMER_ROUTELOC2_CDTI2LOC_MASK))
			| TIMER_ROUTELOC2_CDTI2LOC_LOC1;
	TIMER0->ROUTEPEN = TIMER0->ROUTEPEN & (~TIMER_ROUTEPEN_CDTI2PEN);
	// [TIMER0 I/O setup]$

	// $[TIMER0 initialization]
	TIMER_Init_TypeDef init = TIMER_INIT_DEFAULT;

	init.enable = 1;
	init.debugRun = 0;
	init.dmaClrAct = 0;
	init.sync = 0;
	init.clkSel = timerClkSelHFPerClk;
	init.prescale = timerPrescale512;
	init.fallAction = timerInputActionNone;
	init.riseAction = timerInputActionNone;
	init.mode = timerModeUp;
	init.quadModeX4 = 0;
	init.oneShot = 0;
	init.count2x = 0;
	init.ati = 0;
	TIMER_Init(TIMER0, &init);
	// [TIMER0 initialization]$

	// $[TIMER0 CC0 init]
	TIMER_InitCC_TypeDef initCC0 = TIMER_INITCC_DEFAULT;

	initCC0.prsInput = false;
	initCC0.prsSel = timerPRSSELCh0;
	initCC0.edge = timerEdgeRising;
	initCC0.mode = timerCCModePWM;
	initCC0.eventCtrl = timerEventEveryEdge;
	initCC0.filter = 0;
	initCC0.cofoa = timerOutputActionNone;
	initCC0.cufoa = timerOutputActionNone;
	initCC0.cmoa = timerOutputActionToggle;
	initCC0.coist = 0;
	initCC0.outInvert = 0;
	TIMER_InitCC(TIMER0, 0, &initCC0);
	// [TIMER0 CC0 init]$

	// $[TIMER0 CC1 init]
	TIMER_InitCC_TypeDef initCC1 = TIMER_INITCC_DEFAULT;

	initCC1.prsInput = false;
	initCC1.prsSel = timerPRSSELCh0;
	initCC1.edge = timerEdgeRising;
	initCC1.mode = timerCCModePWM;
	initCC1.eventCtrl = timerEventEveryEdge;
	initCC1.filter = 0;
	initCC1.cofoa = timerOutputActionNone;
	initCC1.cufoa = timerOutputActionNone;
	initCC1.cmoa = timerOutputActionToggle;
	initCC1.coist = 0;
	initCC1.outInvert = 0;
	TIMER_InitCC(TIMER0, 1, &initCC1);
	// [TIMER0 CC1 init]$

	// $[TIMER0 CC2 init]
	TIMER_InitCC_TypeDef initCC2 = TIMER_INITCC_DEFAULT;

	initCC2.prsInput = false;
	initCC2.prsSel = timerPRSSELCh0;
	initCC2.edge = timerEdgeRising;
	initCC2.mode = timerCCModePWM;
	initCC2.eventCtrl = timerEventEveryEdge;
	initCC2.filter = 0;
	initCC2.cofoa = timerOutputActionNone;
	initCC2.cufoa = timerOutputActionNone;
	initCC2.cmoa = timerOutputActionToggle;
	initCC2.coist = 0;
	initCC2.outInvert = 0;
	TIMER_InitCC(TIMER0, 2, &initCC2);
	// [TIMER0 CC2 init]$

	// $[TIMER0 DTI init]
	TIMER_InitDTI_TypeDef initDTI = TIMER_INITDTI_DEFAULT;

	initDTI.enable = 0;
	initDTI.activeLowOut = 0;
	initDTI.invertComplementaryOut = 0;
	initDTI.autoRestart = 0;
	initDTI.enablePrsSource = 0;
	initDTI.prsSel = timerPRSSELCh0;
	initDTI.prescale = timerPrescale1;
	initDTI.riseTime = 1;
	initDTI.fallTime = 1;
	initDTI.enableFaultSourceCoreLockup = 1;
	initDTI.enableFaultSourceDebugger = 1;
	initDTI.faultSourcePrsSel0 = 0;
	initDTI.faultSourcePrsSel0 = timerPRSSELCh0;
	initDTI.faultSourcePrsSel1 = 0;
	initDTI.faultSourcePrsSel1 = timerPRSSELCh0;
	initDTI.faultAction = timerDtiFaultActionInactive;
	initDTI.outputsEnableMask = 0 | TIMER_DTOGEN_DTOGCC0EN
			| TIMER_DTOGEN_DTOGCC1EN | TIMER_DTOGEN_DTOGCC2EN;
	TIMER_InitDTI(TIMER0, &initDTI);
	// [TIMER0 DTI init]$

}

//================================================================================
// TIMER1_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER1_enter_DefaultMode_from_RESET(void) {

	// $[TIMER1 I/O setup]
	// [TIMER1 I/O setup]$

	// $[TIMER1 initialization]
	// [TIMER1 initialization]$

	// $[TIMER1 CC0 init]
	// [TIMER1 CC0 init]$

	// $[TIMER1 CC1 init]
	// [TIMER1 CC1 init]$

	// $[TIMER1 CC2 init]
	// [TIMER1 CC2 init]$

	// $[TIMER1 CC3 init]
	// [TIMER1 CC3 init]$

}

//================================================================================
// LETIMER0_enter_DefaultMode_from_RESET
//================================================================================
extern void LETIMER0_enter_DefaultMode_from_RESET(void) {

	// $[LETIMER0 Compare Values]
	// [LETIMER0 Compare Values]$

	// $[LETIMER0 Repeat Values]
	// [LETIMER0 Repeat Values]$

	// $[LETIMER0 Initialization]
	// [LETIMER0 Initialization]$

	// $[LETIMER0 PRS Input Triggers]
	// [LETIMER0 PRS Input Triggers]$

	// $[LETIMER0 I/O setup]
	// [LETIMER0 I/O setup]$

}

//================================================================================
// CRYOTIMER_enter_DefaultMode_from_RESET
//================================================================================
extern void CRYOTIMER_enter_DefaultMode_from_RESET(void) {

	// $[CRYOTIMER_Init]
	CRYOTIMER_Init_TypeDef cryoInit = CRYOTIMER_INIT_DEFAULT;

	/* General settings */
	cryoInit.enable = 1;
	cryoInit.debugRun = 0;
	cryoInit.em4Wakeup = 0;

	/* Clocking settings */
	/* With a frequency of 1000Hz on ULFRCO, this will result in a 1.00 ms timeout */
	cryoInit.osc = cryotimerOscULFRCO;
	cryoInit.presc = cryotimerPresc_1;
	cryoInit.period = cryotimerPeriod_1;
	CRYOTIMER_Init(&cryoInit);
	// [CRYOTIMER_Init]$

}

//================================================================================
// PCNT0_enter_DefaultMode_from_RESET
//================================================================================
extern void PCNT0_enter_DefaultMode_from_RESET(void) {

	// $[PCNT0 I/O setup]
	// [PCNT0 I/O setup]$

	// $[PCNT0 initialization]
	// [PCNT0 initialization]$

}

//================================================================================
// PRS_enter_DefaultMode_from_RESET
//================================================================================
extern void PRS_enter_DefaultMode_from_RESET(void) {

	// $[PRS initialization]
	// [PRS initialization]$

}

//================================================================================
// PORTIO_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTIO_enter_DefaultMode_from_RESET(void) {

	// $[Port A Configuration]

	/* Pin PA0 is configured to Input enabled */
	GPIO_PinModeSet(gpioPortA, 0, gpioModeInput, 0);

	/* Pin PA1 is configured to Input enabled */
	GPIO_PinModeSet(gpioPortA, 1, gpioModeInput, 0);
	// [Port A Configuration]$

	// $[Port B Configuration]

	/* Pin PB11 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortB, 11, gpioModePushPull, 1);

	/* Pin PB12 is configured to Input enabled with pull-up */
	GPIO_PinModeSet(gpioPortB, 12, gpioModeInputPull, 1);

	/* Pin PB13 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortB, 13, gpioModePushPull, 1);

	/* Pin PB15 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortB, 15, gpioModePushPull, 1);
	// [Port B Configuration]$

	// $[Port C Configuration]
	// [Port C Configuration]$

	// $[Port D Configuration]

	/* Pin PD9 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortD, 9, gpioModePushPull, 1);

	/* Pin PD10 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortD, 10, gpioModePushPull, 1);

	/* Pin PD11 is configured to Input enabled with pull-up */
	GPIO_PinModeSet(gpioPortD, 11, gpioModeInputPull, 1);

	/* Pin PD12 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortD, 12, gpioModePushPull, 1);

	/* Pin PD13 is configured to Input enabled with pull-up */
	GPIO_PinModeSet(gpioPortD, 13, gpioModeInputPull, 1);

	/* Pin PD14 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortD, 14, gpioModePushPull, 1);

	/* Pin PD15 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortD, 15, gpioModePushPull, 1);
	// [Port D Configuration]$

	// $[Port E Configuration]
	// [Port E Configuration]$

	// $[Port F Configuration]
	// [Port F Configuration]$

}

