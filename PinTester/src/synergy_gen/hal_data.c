/* generated HAL source file - do not edit */
#include "hal_data.h"
#if (0) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_external_irq2) && !defined(SSP_SUPPRESS_ISR_ICU3)
SSP_VECTOR_DEFINE(icu_irq_isr, ICU, IRQ3);
#endif
#endif
static icu_instance_ctrl_t g_external_irq2_ctrl;
static const external_irq_cfg_t g_external_irq2_cfg =
{ .channel = 3,
  .trigger = EXTERNAL_IRQ_TRIG_BOTH_EDGE,
  .filter_enable = true,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .autostart = true,
  .p_callback = ext_irq2_callback,
  .p_context = &g_external_irq2,
  .p_extend = NULL,
  .irq_ipl = (0), };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq2 =
{ .p_ctrl = &g_external_irq2_ctrl, .p_cfg = &g_external_irq2_cfg, .p_api = &g_external_irq_on_icu };
#if (0) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_external_irq1) && !defined(SSP_SUPPRESS_ISR_ICU2)
SSP_VECTOR_DEFINE(icu_irq_isr, ICU, IRQ2);
#endif
#endif
static icu_instance_ctrl_t g_external_irq1_ctrl;
static const external_irq_cfg_t g_external_irq1_cfg =
{ .channel = 2,
  .trigger = EXTERNAL_IRQ_TRIG_BOTH_EDGE,
  .filter_enable = true,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .autostart = true,
  .p_callback = ext_irq1_callback,
  .p_context = &g_external_irq1,
  .p_extend = NULL,
  .irq_ipl = (0), };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq1 =
{ .p_ctrl = &g_external_irq1_ctrl, .p_cfg = &g_external_irq1_cfg, .p_api = &g_external_irq_on_icu };
#if (0) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_external_irq0) && !defined(SSP_SUPPRESS_ISR_ICU7)
SSP_VECTOR_DEFINE(icu_irq_isr, ICU, IRQ7);
#endif
#endif
static icu_instance_ctrl_t g_external_irq0_ctrl;
static const external_irq_cfg_t g_external_irq0_cfg =
{ .channel = 7,
  .trigger = EXTERNAL_IRQ_TRIG_BOTH_EDGE,
  .filter_enable = true,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .autostart = true,
  .p_callback = ext_irq0_callback,
  .p_context = &g_external_irq0,
  .p_extend = NULL,
  .irq_ipl = (0), };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq0 =
{ .p_ctrl = &g_external_irq0_ctrl, .p_cfg = &g_external_irq0_cfg, .p_api = &g_external_irq_on_icu };
#if (0) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer_gpt_4) && !defined(SSP_SUPPRESS_ISR_GPT4)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 4);
#endif
#endif
static gpt_instance_ctrl_t g_timer_gpt_4_ctrl;
static const timer_on_gpt_cfg_t g_timer_gpt_4_extend =
{ .gtioca =
{ .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_timer_gpt_4_cfg =
{ .mode = TIMER_MODE_PERIODIC, .period = 10, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_RAW_COUNTS,
  .channel = 4, .autostart = false, .p_callback = gpt_4_callback, .p_context = &g_timer_gpt_4, .p_extend =
          &g_timer_gpt_4_extend,
  .irq_ipl = (0), };
/* Instance structure to use this module. */
const timer_instance_t g_timer_gpt_4 =
{ .p_ctrl = &g_timer_gpt_4_ctrl, .p_cfg = &g_timer_gpt_4_cfg, .p_api = &g_timer_on_gpt };
#if (5) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer_gpt_7) && !defined(SSP_SUPPRESS_ISR_GPT7)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 7);
#endif
#endif
static gpt_instance_ctrl_t g_timer_gpt_7_ctrl;
static const timer_on_gpt_cfg_t g_timer_gpt_7_extend =
{ .gtioca =
{ .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_timer_gpt_7_cfg =
{ .mode = TIMER_MODE_PERIODIC, .period = 10, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_RAW_COUNTS,
  .channel = 7, .autostart = false, .p_callback = gpt_7_callback, .p_context = &g_timer_gpt_7, .p_extend =
          &g_timer_gpt_7_extend,
  .irq_ipl = (5), };
/* Instance structure to use this module. */
const timer_instance_t g_timer_gpt_7 =
{ .p_ctrl = &g_timer_gpt_7_ctrl, .p_cfg = &g_timer_gpt_7_cfg, .p_api = &g_timer_on_gpt };
#if (5) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer_gpt_3) && !defined(SSP_SUPPRESS_ISR_GPT3)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 3);
#endif
#endif
static gpt_instance_ctrl_t g_timer_gpt_3_ctrl;
static const timer_on_gpt_cfg_t g_timer_gpt_3_extend =
{ .gtioca =
{ .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_timer_gpt_3_cfg =
{ .mode = TIMER_MODE_PERIODIC, .period = 10, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_RAW_COUNTS,
  .channel = 3, .autostart = false, .p_callback = gpt_3_callback, .p_context = &g_timer_gpt_3, .p_extend =
          &g_timer_gpt_3_extend,
  .irq_ipl = (5), };
/* Instance structure to use this module. */
const timer_instance_t g_timer_gpt_3 =
{ .p_ctrl = &g_timer_gpt_3_ctrl, .p_cfg = &g_timer_gpt_3_cfg, .p_api = &g_timer_on_gpt };
void g_hal_init(void)
{
    g_common_init ();
}
