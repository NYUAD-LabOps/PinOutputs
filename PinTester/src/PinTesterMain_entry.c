#include "PinTesterMain.h"
#include "PinTester.h"
#include <GPT_HAL_MG.h>

/* Helix Main entry function */
void PinTesterMain_entry(void)
{
    /* TODO: add your own code here */
    initialise_monitor_handles ();
    ssp_err_t err = init_timers ();

    printf ("\nPin Tester start...");

    initGlobalsBlock ();

//    initMotorBlocks ();
//    initMotors ();

    g_timer_gpt_4.p_api->start (g_timer_gpt_4.p_ctrl);

    err = g_timer_gpt_4.p_api->periodSet (g_timer_gpt_4.p_ctrl, (2 * 1), TIMER_UNIT_FREQUENCY_HZ);

    int i = 0;
    while (1)
    {
        if (DEBUG)
        {
            printf ("\nRunning %d...", i);
        }
        i++;
        tx_thread_sleep (3000);
    }
}

void ext_irq0_callback(external_irq_callback_args_t *p_args)
{
//    limitHit (motorBlockX);
}

void ext_irq1_callback(external_irq_callback_args_t *p_args)
{
//    limitHit (motorBlockY);
}
void ext_irq2_callback(external_irq_callback_args_t *p_args)
{
//    limitHit (motorBlockZ);
}

void gpt_4_callback(timer_callback_args_t *p_args)
{
    flipPins (motorBlockX);
}

void gpt_7_callback(timer_callback_args_t *p_args)
{
//    stepHandler (motorBlockY);
}

void gpt_3_callback(timer_callback_args_t *p_args)
{
//    stepHandler (motorBlockZ);

}

void gpt_10_callback(timer_callback_args_t *p_args)
{

}

//void motorInitX()
//{
//    ssp_err_t err;
//    err = g_external_irq0.p_api->open (g_external_irq0.p_ctrl, g_external_irq0.p_cfg);
//    motorBlockX->homing = 0;
//    motorBlockX->dirPin = IOPORT_PORT_04_PIN_12;
//    motorBlockX->start = g_timer_gpt_4.p_api->start;
//    motorBlockX->stop = g_timer_gpt_4.p_api->stop;
//    motorBlockX->dutyCycleSet = g_timer_gpt_4.p_api->dutyCycleSet;
//    motorBlockX->periodSet = g_timer_gpt_4.p_api->periodSet;
//    motorBlockX->g_timer_gpt_x = g_timer_gpt_4;
//    motorBlockX->stepSize = STEPX;
//    motorBlockX->stepPin = IOPORT_PORT_11_PIN_00;
//    motorBlockX->stepState = IOPORT_LEVEL_LOW;
//    motorBlockX->limit0Pin = IOPORT_PORT_04_PIN_08;
//    motorBlockX->defaultDir = IOPORT_LEVEL_LOW;
//    motorBlockX->targetDir = motorBlockX->defaultDir;
//    motorBlockX->targetJerkSpeed = DEFAULTJERKSPEEDX;
//    g_ioport.p_api->pinWrite (motorBlockX->dirPin, motorBlockX->defaultDir);
//    motorBlockX->dir = motorBlockX->defaultDir;
//    motorBlockX->fwdDir = IOPORT_LEVEL_LOW;
//    motorBlockX->homeSpeed = HOMEVX;
//    motorBlockX->rapidSpeed = HOMEVX;
//    motorBlockX->limit0State = IOPORT_LEVEL_HIGH;
//    motorBlockX->intervalSteps = 0;
//    motorBlockX->freqSet = 0;
//    motorBlockX->setPosSteps = 0;
//    motorBlockX->pos = 0;
//    motorBlockX->posSteps = 0;
//    motorBlockX->posAbs = 0;
//    motorBlockX->posStepsAbs = 0;
//    motorBlockX->offsetSteps = 0;
//    motorBlockX->targetSpeed = 0;
//    motorBlockX->targetFreq = 0;
//    motorBlockX->targetPosSteps = 0;
//    motorBlockX->speed = 0;
//    motorBlockX->frequency = 0;
//}
//
//void motorInitY()
//{
//    ssp_err_t err;
//    err = g_external_irq1.p_api->open (g_external_irq1.p_ctrl, g_external_irq1.p_cfg);
//    motorBlockY->homing = 0;
//    motorBlockY->dirPin = IOPORT_PORT_04_PIN_10;
//    motorBlockY->start = g_timer_gpt_7.p_api->start;
//    motorBlockY->stop = g_timer_gpt_7.p_api->stop;
//    motorBlockY->dutyCycleSet = g_timer_gpt_7.p_api->dutyCycleSet;
//    motorBlockY->periodSet = g_timer_gpt_7.p_api->periodSet;
//    motorBlockY->g_timer_gpt_x = g_timer_gpt_7;
//    motorBlockY->stepSize = STEPY;
//    motorBlockY->stepPin = IOPORT_PORT_04_PIN_15;
//    motorBlockY->stepState = IOPORT_LEVEL_LOW;
//    motorBlockY->limit0Pin = IOPORT_PORT_02_PIN_03;
//    motorBlockY->defaultDir = IOPORT_LEVEL_HIGH;
//    motorBlockY->targetDir = motorBlockY->defaultDir;
//    motorBlockY->targetJerkSpeed = DEFAULTJERKSPEEDY;
//    g_ioport.p_api->pinWrite (motorBlockY->dirPin, motorBlockY->defaultDir);
//    motorBlockY->dir = motorBlockY->defaultDir;
//    motorBlockY->fwdDir = IOPORT_LEVEL_HIGH;
//    motorBlockY->homeSpeed = HOMEVY;
//    motorBlockY->rapidSpeed = HOMEVY;
//    motorBlockY->limit0State = IOPORT_LEVEL_HIGH;
//    motorBlockY->intervalSteps = 0;
//    motorBlockY->freqSet = 0;
//    motorBlockY->setPosSteps = 0;
//    motorBlockY->pos = 0;
//    motorBlockY->posSteps = 0;
//    motorBlockY->posAbs = 0;
//    motorBlockY->posStepsAbs = 0;
//    motorBlockY->offsetSteps = 0;
//    motorBlockY->targetSpeed = 0;
//    motorBlockY->targetFreq = 0;
//    motorBlockY->targetPosSteps = 0;
//    motorBlockY->speed = 0;
//    motorBlockY->frequency = 0;
//}
//
//void motorInitZ()
//{
//    ssp_err_t err;
//    err = g_external_irq2.p_api->open (g_external_irq2.p_ctrl, g_external_irq2.p_cfg);
//    motorBlockZ->homing = 0;
//    motorBlockZ->dirPin = IOPORT_PORT_04_PIN_09;
//    motorBlockZ->start = g_timer_gpt_3.p_api->start;
//    motorBlockZ->stop = g_timer_gpt_3.p_api->stop;
//    motorBlockZ->dutyCycleSet = g_timer_gpt_3.p_api->dutyCycleSet;
//    motorBlockZ->periodSet = g_timer_gpt_3.p_api->periodSet;
//    motorBlockZ->g_timer_gpt_x = g_timer_gpt_3;
//    motorBlockZ->stepSize = STEPZ;
//    motorBlockZ->stepPin = IOPORT_PORT_04_PIN_14;
//    motorBlockZ->stepState = IOPORT_LEVEL_LOW;
//    motorBlockZ->limit0Pin = IOPORT_PORT_02_PIN_02;
//    motorBlockZ->defaultDir = IOPORT_LEVEL_LOW;
//    motorBlockZ->targetDir = motorBlockZ->defaultDir;
//    motorBlockZ->targetJerkSpeed = DEFAULTJERKSPEEDZ;
//    g_ioport.p_api->pinWrite (motorBlockZ->dirPin, motorBlockZ->defaultDir);
//    motorBlockZ->dir = motorBlockZ->defaultDir;
//    motorBlockZ->fwdDir = IOPORT_LEVEL_HIGH;
//    motorBlockZ->posSteps = 0;
//    motorBlockZ->targetPosSteps = 0;
//    motorBlockZ->offsetSteps = 0;
//    motorBlockZ->homeSpeed = HOMEVZ;
//    motorBlockZ->rapidSpeed = HOMEVZ;
//    motorBlockZ->limit0State = IOPORT_LEVEL_HIGH;
//    motorBlockZ->intervalSteps = 0;
//    motorBlockZ->freqSet = 0;
//    motorBlockZ->setPosSteps = 0;
//    motorBlockZ->pos = 0;
//    motorBlockZ->posSteps = 0;
//    motorBlockZ->posAbs = 0;
//    motorBlockZ->posStepsAbs = 0;
//    motorBlockZ->offsetSteps = 0;
//    motorBlockZ->targetSpeed = 0;
//    motorBlockZ->targetFreq = 0;
//    motorBlockZ->targetPosSteps = 0;
//    motorBlockZ->speed = 0;
//    motorBlockZ->frequency = 0;
//}

void flipPins()
{
    ssp_err_t err;

    if (machineGlobalsBlock->pinState == IOPORT_LEVEL_HIGH)
    {
        machineGlobalsBlock->pinState = IOPORT_LEVEL_LOW;
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_12, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_11, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_10, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_09, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_11_PIN_00, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_15, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_14, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_13, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_14, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_15, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_09_PIN_00, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_09_PIN_01, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_02_PIN_06, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_02_PIN_05, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_02_PIN_04, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_13, IOPORT_LEVEL_LOW);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_08_PIN_04, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_08_PIN_03, IOPORT_LEVEL_LOW);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_00_PIN_04, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_00_PIN_05, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_00_PIN_06, IOPORT_LEVEL_LOW);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_03, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_07, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_09, IOPORT_LEVEL_LOW);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_10, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_11, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_12, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_09_PIN_05, IOPORT_LEVEL_LOW);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_05_PIN_11, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_05_PIN_12, IOPORT_LEVEL_LOW);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_05_PIN_13, IOPORT_LEVEL_LOW);

    }
    else
    {
        machineGlobalsBlock->pinState = IOPORT_LEVEL_HIGH;
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_12, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_11, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_10, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_09, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_11_PIN_00, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_15, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_14, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_04_PIN_13, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_14, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_15, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_09_PIN_00, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_09_PIN_01, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_02_PIN_06, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_02_PIN_05, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_02_PIN_04, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_13, IOPORT_LEVEL_HIGH);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_08_PIN_04, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_08_PIN_03, IOPORT_LEVEL_HIGH);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_00_PIN_04, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_00_PIN_05, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_00_PIN_06, IOPORT_LEVEL_HIGH);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_03, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_07, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_09, IOPORT_LEVEL_HIGH);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_10, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_11, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_03_PIN_12, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_09_PIN_05, IOPORT_LEVEL_HIGH);

        err = g_ioport.p_api->pinWrite (IOPORT_PORT_05_PIN_11, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_05_PIN_12, IOPORT_LEVEL_HIGH);
        err = g_ioport.p_api->pinWrite (IOPORT_PORT_05_PIN_13, IOPORT_LEVEL_HIGH);
    }
}
