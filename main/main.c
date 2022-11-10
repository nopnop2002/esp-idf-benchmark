#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "rom/ets_sys.h"

void dhrystone(void *pvParameters);
void whetstone(void *pvParameters);

void app_main()
{
	TaskHandle_t taskHandle = xTaskGetCurrentTaskHandle();
	char * my_name = pcTaskGetName(NULL);
	UBaseType_t my_prio = uxTaskPriorityGet(NULL);
	ESP_LOGD(my_name, "my_prio=%d", my_prio);

#if CONFIG_IDF_TARGET_ESP8266
	printf("Target is ESP8266\n");
#elif CONFIG_IDF_TARGET_ESP32
	printf("Target is ESP32@%"PRIu32"Mhz\n", ets_get_cpu_frequency());
#elif CONFIG_IDF_TARGET_ESP32S2
	printf("Target is ESP32S2@%"PRIu32"Mhz\n", ets_get_cpu_frequency());
#elif CONFIG_IDF_TARGET_ESP32S3
	printf("Target is ESP32S3@%"PRIu32"Mhz\n", ets_get_cpu_frequency());
#elif CONFIG_IDF_TARGET_ESP32C2
	printf("Target is ESP32C2@%"PRIu32"Mhz\n", ets_get_cpu_frequency());
#elif CONFIG_IDF_TARGET_ESP32C3
	printf("Target is ESP32C3@%"PRIu32"Mhz\n", ets_get_cpu_frequency());
#endif

	xTaskCreate(&dhrystone, "DHRY", 1024*4, (void *)taskHandle, my_prio+1, NULL);
	ulTaskNotifyTake( pdTRUE, portMAX_DELAY );
	ESP_LOGD(my_name, "ulTaskNotifyTake");

	xTaskCreate(&whetstone, "WHET", 1024*4, (void *)taskHandle, my_prio+1, NULL);
	ulTaskNotifyTake( pdTRUE, portMAX_DELAY );
	ESP_LOGD(my_name, "ulTaskNotifyTake");
}
