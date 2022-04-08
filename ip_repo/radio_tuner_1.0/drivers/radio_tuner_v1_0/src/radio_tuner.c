

/***************************** Include Files *******************************/
#include "radio_tuner.h"
#include "xil_types.h"
#include "xstatus.h"
#include <stdio.h>
/************************** Function Definitions ***************************/

/**
radioTuner_tuneRadio function tunes the radio to the desired frequency
**/
void radioTuner_tuneRadio(u32 BaseAddress, float tune_frequency)
{
	float fsamp=125000000;
	float phaseinc;
	phaseinc= tune_frequency *(134217728/fsamp);
	RADIO_TUNER_mWriteReg(BaseAddress, RADIO_TUNER_S00_AXI_SLV_REG1_OFFSET, phaseinc);

}

/** radioTuner_controlReset resets the DDS set to 1 for reset **/
void radioTuner_controlReset(u32 BaseAddress, u8 resetval)
{
	RADIO_TUNER_mWriteReg(BaseAddress, RADIO_TUNER_S00_AXI_SLV_REG2_OFFSET,resetval);
}
/** radioTuner_setAdcFreq set frequencies near the tuned frequency **/
void radioTuner_setAdcFreq(u32 BaseAddress, float freq)
{
	float fsamp=125000000;
	float phaseinc;
	phaseinc= freq *(134217728/fsamp);
	RADIO_TUNER_mWriteReg(BaseAddress, RADIO_TUNER_S00_AXI_SLV_REG0_OFFSET,phaseinc);
}