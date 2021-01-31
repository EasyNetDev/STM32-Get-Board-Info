#include "Arduino.h"
#include "SystemClock.h"

void setup()
{
    RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    uint32_t pFLatency;
    
    HAL_Init();
    Serial.begin(115200);
    Serial.println("Start PIN Mode OUTPUT test ..");
    Serial.println((String) "Board name: " + BOARD_NAME);
    //Serial.println(BOARD_NAME);
    Serial.println((String)"CPU Speed (F_CPU): " + (F_CPU / 1000) + "KHz");
    Serial.println((String)"CPU Speed (SystemCoreClock): " + (SystemCoreClock / 1000) + "KHz");
    Serial.println((String)"CPU Speed (HAL_RCC_GetSysClockFreq()): " + (HAL_RCC_GetSysClockFreq() / 1000) + "KHz");
    Serial.println((String)"MSI Speed: " + (MSI_VALUE / 1000) + "KHz (is divided by 2 before going to PLL)");
    Serial.println((String)"HSI Speed: " + (HSI_VALUE / 1000) + "KHz");
    Serial.println((String)"HSE Speed: " + (HSE_VALUE / 1000) + "KHz");
    Serial.println((String)"LSE Speed: " + LSE_VALUE + "Hz");
    Serial.println((String)"LSI Speed: " + LSI_VALUE + "Hz");


    GetSystemClock();

    pinMode(LED_GREEN, OUTPUT); 
    digitalWrite(LED_GREEN, LOW);
#if defined(LED_BLUE)
    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_BLUE, LOW);
#endif
#if defined(LED_RED)
    pinMode(LED_RED, OUTPUT); 
    digitalWrite(LED_RED, LOW);
#endif
}

void loop() {
    // put your main code here, to run repeatedly:
    Serial.println("Main loop ..");
    digitalWrite(LED_GREEN, HIGH);
    delay(1000);
#if defined(LED_BLUE)
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);
#endif
#if defined(LED_RED)
    digitalWrite(LED_RED, HIGH);
    delay(1000);
#endif
    digitalWrite(LED_GREEN, LOW);
    delay(1000);
#if defined(LED_BLUE)
    digitalWrite(LED_BLUE, LOW);
    delay(1000);
#endif
#if defined(LED_RED)
    digitalWrite(LED_RED, LOW);
    delay(1000);
#endif
    
}
