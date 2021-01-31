#include "Arduino.h"

void GetSystemClock(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    uint32_t pFLatency;
    HAL_RCC_GetOscConfig(&RCC_OscInitStruct);
    HAL_RCC_GetClockConfig(&RCC_ClkInitStruct, &pFLatency);

    uint8_t FOUND=0;

    //System Clock Type
    Serial.println("System Clock Configuration ..");
    Serial.print("  > System Clock Type : ");
 
    uint8_t CLOCKTYPE_FOUND=0;
    
    if (RCC_ClkInitStruct.ClockType && RCC_CLOCKTYPE_SYSCLK)
    {
        Serial.print("RCC_CLOCKTYPE_SYSCLK");
        CLOCKTYPE_FOUND=1;
    }
    if (RCC_ClkInitStruct.ClockType && RCC_CLOCKTYPE_HCLK)
    {
        if (CLOCKTYPE_FOUND) Serial.print(" || ");
        Serial.print("RCC_CLOCKTYPE_HCLK");
        CLOCKTYPE_FOUND=1;
    }
    if (RCC_ClkInitStruct.ClockType && RCC_CLOCKTYPE_PCLK1)
    {
        if (CLOCKTYPE_FOUND) Serial.print(" || ");
        Serial.print("RCC_CLOCKTYPE_PCLK1");
        CLOCKTYPE_FOUND=1;
    }
    if (RCC_ClkInitStruct.ClockType && RCC_CLOCKTYPE_PCLK2)
    {
        if (CLOCKTYPE_FOUND) Serial.print(" || ");
        Serial.print("RCC_CLOCKTYPE_PCLK2");
        CLOCKTYPE_FOUND=1;
    }
    Serial.println("");

    Serial.print("  > System Clock Source : ");
    switch(RCC_ClkInitStruct.SYSCLKSource)
    {
      case RCC_SYSCLKSOURCE_HSI:
        Serial.println("RCC_SYSCLKSOURCE_HSI");
        break;
      case RCC_SYSCLKSOURCE_HSE:
        Serial.println("RCC_SYSCLKSOURCE_HSE");
        break;
      case RCC_SYSCLKSOURCE_PLLCLK:
        Serial.println("RCC_SYSCLKSOURCE_PLLCLK");
        break;
#if defined (RCC_SYSCLKSOURCE_PLLRCLK)
      case RCC_SYSCLKSOURCE_PLLRCLK:
        Serial.println("PLLRCLK");
        break;
#endif
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_ClkInitStruct.SYSCLKSource, HEX);
        break;
    }

    Serial.print("  > AHB Clock Divider : ");
    switch(RCC_ClkInitStruct.AHBCLKDivider)
    {
      case RCC_SYSCLK_DIV1:
        Serial.println("RCC_SYSCLK_DIV1");
        break;
      case RCC_SYSCLK_DIV2:
        Serial.println("RCC_SYSCLK_DIV2");
        break;
      case RCC_SYSCLK_DIV4:
        Serial.println("RCC_SYSCLK_DIV4");
        break;
      case RCC_SYSCLK_DIV8:
        Serial.println("RCC_SYSCLK_DIV8");
        break;
      case RCC_SYSCLK_DIV16:
        Serial.println("RCC_SYSCLK_DIV16");
        break;
      case RCC_SYSCLK_DIV64:
        Serial.println("RCC_SYSCLK_DIV64");
        break;
      case RCC_SYSCLK_DIV128:
        Serial.println("RCC_SYSCLK_DIV128");
        break;
      case RCC_SYSCLK_DIV256:
        Serial.println("RCC_SYSCLK_DIV256");
        break;
      case RCC_SYSCLK_DIV512:
        Serial.println("RCC_SYSCLK_DIV512");
        break;
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_ClkInitStruct.AHBCLKDivider, HEX);
        break;
    }

    Serial.print("  > APB1 Clock Devider : ");
    switch(RCC_ClkInitStruct.APB1CLKDivider)
    {
      case RCC_HCLK_DIV1:
        Serial.println("RCC_HCLK_DIV1");
        break;
      case RCC_HCLK_DIV2:
        Serial.println("RCC_HCLK_DIV2");
        break;
      case RCC_HCLK_DIV4:
        Serial.println("RCC_HCLK_DIV4");
        break;
      case RCC_HCLK_DIV8:
        Serial.println("RCC_HCLK_DIV8");
        break;
      case RCC_HCLK_DIV16:
        Serial.println("RCC_HCLK_DIV16");
        break;
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_ClkInitStruct.APB1CLKDivider, HEX);
        break;
    }

    Serial.print("  > APB2 Clock Devider : ");
    switch(RCC_ClkInitStruct.APB2CLKDivider)
    {
      case RCC_HCLK_DIV1:
        Serial.println("RCC_HCLK_DIV1");
        break;
      case RCC_HCLK_DIV2:
        Serial.println("RCC_HCLK_DIV2");
        break;
      case RCC_HCLK_DIV4:
        Serial.println("RCC_HCLK_DIV4");
        break;
      case RCC_HCLK_DIV8:
        Serial.println("RCC_HCLK_DIV8");
        break;
      case RCC_HCLK_DIV16:
        Serial.println("RCC_HCLK_DIV16");
        break;
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_ClkInitStruct.APB2CLKDivider, HEX);
        break;
    }

    //Oscillator Type
    Serial.println("Ocillator configuration ..");
    Serial.print("  > Oscillator Type : ");

    FOUND=0;
    
    if (RCC_OscInitStruct.OscillatorType & RCC_OSCILLATORTYPE_NONE)
    {
        Serial.print("RCC_OSCILLATORTYPE_NONE");
        FOUND=1;
    }
    if (RCC_OscInitStruct.OscillatorType & RCC_OSCILLATORTYPE_HSE)
    {
        if (FOUND) Serial.print(" || ");
        Serial.print("RCC_OSCILLATORTYPE_HSE");
        FOUND=1;
    }
    if (RCC_OscInitStruct.OscillatorType & RCC_OSCILLATORTYPE_HSI)
    {
        if (FOUND) Serial.print(" || ");
        Serial.print("RCC_OSCILLATORTYPE_HSI");
        FOUND=1;
    }
    if (RCC_OscInitStruct.OscillatorType & RCC_OSCILLATORTYPE_LSE)
    {
        if (FOUND) Serial.print(" || ");
        Serial.print("RCC_OSCILLATORTYPE_LSE");
        FOUND=1;
    }
    if (RCC_OscInitStruct.OscillatorType & RCC_OSCILLATORTYPE_LSI)
    {
        if (FOUND) Serial.print(" || ");
        Serial.print("RCC_OSCILLATORTYPE_LSI");
        FOUND=1;
    }
    if (RCC_OscInitStruct.OscillatorType & RCC_OSCILLATORTYPE_MSI)
    {
        if (FOUND) Serial.print(" || ");
        Serial.print("RCC_OSCILLATORTYPE_MSI");
        FOUND=1;
    }
#if defined(RCC_HSI48_SUPPORT)
    if (RCC_OscInitStruct.OscillatorType & RCC_OSCILLATORTYPE_HSI48)
    {
        if (FOUND) Serial.print(" || ");
        Serial.print("RCC_OSCILLATORTYPE_HSI48");
        FOUND=1;
    }
#endif /* RCC_HSI48_SUPPORT */
    Serial.println("");


    Serial.print("  > HSE State : ");
    switch(RCC_OscInitStruct.HSEState)
    {
      case RCC_HSE_OFF:
        Serial.println("RCC_HSE_OFF");
        break;
      case RCC_HSE_ON:
        Serial.println("RCC_HSE_ON");
        break;
      case RCC_HSE_BYPASS:
        Serial.println("RCC_HSE_BYPASS");
        break;
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_OscInitStruct.HSEState, HEX);
        break;
    }

    Serial.print("  > LSE State : ");
    switch(RCC_OscInitStruct.LSEState)
    {
      case RCC_LSE_OFF:
        Serial.println("RCC_LSE_OFF");
        break;
      case RCC_LSE_ON:
        Serial.println("RCC_LSE_ON");
        break;
      case RCC_LSE_BYPASS:
        Serial.println("RCC_LSE_BYPASS");
        break;
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_OscInitStruct.LSEState, HEX);
        break;
    }

    Serial.print("  > HSI State : ");
    switch(RCC_OscInitStruct.HSIState)
    {
      case RCC_HSI_OFF:
        Serial.println("RCC_HSI_OFF");
        break;
      case RCC_HSI_ON:
        Serial.println("RCC_HSI_ON");
        break;
      case RCC_HSICALIBRATION_DEFAULT:
        Serial.println("RCC_HSICALIBRATION_DEFAULT");
        break;
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_OscInitStruct.HSIState, HEX);
        break;
    }

    Serial.print("  > HSI HSICalibrationValue : ");
    Serial.println(RCC_OscInitStruct.HSICalibrationValue);

    Serial.print("  > LSI State : ");
    switch(RCC_OscInitStruct.LSIState)
    {
      case RCC_LSI_OFF:
        Serial.println("RCC_LSI_OFF");
        break;
      case RCC_LSI_ON:
        Serial.println("RCC_LSI_ON");
        break;
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_OscInitStruct.HSICalibrationValue, HEX);
        break;
    }

    Serial.print("  > MSI State : ");
    switch(RCC_OscInitStruct.MSIState)
    {
      case RCC_MSI_OFF:
        Serial.println("RCC_MSI_OFF");
        break;
      case RCC_MSI_ON:
        Serial.println("RCC_MSI_ON");
        break;
#if defined (RCC_MSICALIBRATION_DEFAULT)
/*      case RCC_MSICALIBRATION_DEFAULT:
        Serial.println("RCC_MSICALIBRATION_DEFAULT");
        break; */
#endif
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_OscInitStruct.HSICalibrationValue, HEX);
        break;
    }

    Serial.println("PLL configuration ..");
    Serial.print("  > PLL State : ");
    switch(RCC_OscInitStruct.PLL.PLLState)
    {
      case RCC_PLL_NONE:
        Serial.println("RCC_PLL_NONE");
        break;
      case RCC_PLL_OFF:
        Serial.println("RCC_PLL_OFF");
        break;
      case RCC_PLL_ON:
        Serial.println("RCC_PLL_ON");
        break;
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_OscInitStruct.PLL.PLLState, HEX);
        break;
    }
    
    Serial.print("  > PLL PLLSource : ");
    switch(RCC_OscInitStruct.PLL.PLLSource)
    {
      case RCC_PLLSOURCE_MSI:
        Serial.println("RCC_PLLSOURCE_MSI");
        break;
      case RCC_PLLSOURCE_HSI:
        Serial.println("RCC_PLLSOURCE_HSI");
        break;
      case RCC_PLLSOURCE_HSE:
        Serial.println("RCC_PLLSOURCE_HSE");
        break;
      default:
        Serial.print("UNKNOWN, value: 0x");
        Serial.println(RCC_OscInitStruct.PLL.PLLSource, HEX);
        break;
    }

    Serial.print("  > PLLM: Division factor for PLL VCO input clock : ");
    Serial.println(RCC_OscInitStruct.PLL.PLLM);

    Serial.print("  > PLLN: Multiplication factor for PLL VCO output clock : ");
    Serial.println(RCC_OscInitStruct.PLL.PLLN);

    Serial.print("  > PLLP: Division factor for main system clock (SYSCLK) : ");
    switch(RCC_OscInitStruct.PLL.PLLP)
    {
      case RCC_PLLP_DIV2:
        Serial.println("RCC_PLLP_DIV2");
        break;
      case RCC_PLLP_DIV3:
        Serial.println("RCC_PLLP_DIV3");
        break;
      case RCC_PLLP_DIV4:
        Serial.println("RCC_PLLP_DIV4");
        break;
      case RCC_PLLP_DIV5:
        Serial.println("RCC_PLLP_DIV5");
        break;
      case RCC_PLLP_DIV6:
        Serial.println("RCC_PLLP_DIV6");
        break;
      case RCC_PLLP_DIV7:
        Serial.println("RCC_PLLP_DIV7");
        break;
      case RCC_PLLP_DIV8:
        Serial.println("RCC_PLLP_DIV8");
        break;
      case RCC_PLLP_DIV9:
        Serial.println("RCC_PLLP_DIV9");
        break;
      case RCC_PLLP_DIV10:
        Serial.println("RCC_PLLP_DIV10");
        break;
      case RCC_PLLP_DIV11:
        Serial.println("RCC_PLLP_DIV11");
        break;
      case RCC_PLLP_DIV12:
        Serial.println("RCC_PLLP_DIV12");
        break;
      case RCC_PLLP_DIV13:
        Serial.println("RCC_PLLP_DIV13");
        break;
      case RCC_PLLP_DIV14:
        Serial.println("RCC_PLLP_DIV14");
        break;
      case RCC_PLLP_DIV15:
        Serial.println("RCC_PLLP_DIV15");
        break;
      case RCC_PLLP_DIV16:
        Serial.println("RCC_PLLP_DIV16");
        break;
      case RCC_PLLP_DIV17:
        Serial.println("RCC_PLLP_DIV17");
        break;
      case RCC_PLLP_DIV18:
        Serial.println("RCC_PLLP_DIV18");
        break;
      case RCC_PLLP_DIV19:
        Serial.println("RCC_PLLP_DIV19");
        break;
      case RCC_PLLP_DIV20:
        Serial.println("RCC_PLLP_DIV20");
        break;
      case RCC_PLLP_DIV21:
        Serial.println("RCC_PLLP_DIV21");
        break;
      case RCC_PLLP_DIV22:
        Serial.println("RCC_PLLP_DIV22");
        break;
      case RCC_PLLP_DIV23:
        Serial.println("RCC_PLLP_DIV23");
        break;
      case RCC_PLLP_DIV24:
        Serial.println("RCC_PLLP_DIV24");
        break;
      case RCC_PLLP_DIV25:
        Serial.println("RCC_PLLP_DIV25");
        break;
      case RCC_PLLP_DIV26:
        Serial.println("RCC_PLLP_DIV26");
        break;
      case RCC_PLLP_DIV27:
        Serial.println("RCC_PLLP_DIV27");
        break;
      case RCC_PLLP_DIV28:
        Serial.println("RCC_PLLP_DIV28");
        break;
      case RCC_PLLP_DIV29:
        Serial.println("RCC_PLLP_DIV29");
        break;
      case RCC_PLLP_DIV30:
        Serial.println("RCC_PLLP_DIV30");
        break;
      case RCC_PLLP_DIV31:
        Serial.println("RCC_PLLP_DIV31");
        break;
      default:
        Serial.print("UNKNOWN, value: ");
        Serial.println(RCC_OscInitStruct.PLL.PLLP);
        break;
    }

    Serial.print("  > PLLQ: Division factor for OTG FS, SDIO and RNG clocks : ");
    switch(RCC_OscInitStruct.PLL.PLLQ)
    {
      case RCC_PLLQ_DIV2:
        Serial.println("RCC_PLLQ_DIV2");
        break;
      case RCC_PLLQ_DIV4:
        Serial.println("RCC_PLLQ_DIV4");
        break;
      case RCC_PLLQ_DIV6:
        Serial.println("RCC_PLLQ_DIV6");
        break;
      case RCC_PLLQ_DIV8:
        Serial.println("RCC_PLLQ_DIV8");
        break;
      default:
        Serial.print("UNKNOWN, value: ");
        Serial.println(RCC_OscInitStruct.PLL.PLLQ);
        break;
    }

// Not all boards are supporting PLLR
#if defined(STM32F410xx) || defined(STM32F446xx ) || defined(STM32F469xx) || defined(STM32F479xx) || defined(STM32F412Zx) || \
    defined(STM32F412Vx) || defined(STM32F412Rx) || defined(STM32F412Cx) || defined(STM32F413xx) || defined(STM32F423xx) || \
    defined(STM32L452xx)
    Serial.print("  > PLLR: PLL division factor for I2S, SAI, SYSTEM, SPDIFRX clocks : ");
    switch(RCC_OscInitStruct.PLL.PLLR)
    {
      case RCC_PLLR_DIV2:
        Serial.println("RCC_PLLR_DIV2");
        break;
      case RCC_PLLR_DIV4:
        Serial.println("RCC_PLLR_DIV4");
        break;
      case RCC_PLLR_DIV6:
        Serial.println("RCC_PLLR_DIV6");
        break;
      case RCC_PLLR_DIV8:
        Serial.println("RCC_PLLR_DIV8");
        break;
      default:
        Serial.print("UNKNOWN, value: ");
        Serial.println(RCC_OscInitStruct.PLL.PLLR);
        break;
    }
#endif

}
