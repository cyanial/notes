# FreeRTOS

- [FreeRTOS](#freertos)
  - [Memory Manage (heap)](#memory-manage-heap)
    - [heap_1.c](#heap_1c)
    - [heap_2.c](#heap_2c)
    - [heap_3.c](#heap_3c)
    - [heap_4.c](#heap_4c)
    - [heap_5.c](#heap_5c)
    - [Heap 相关 API](#heap-相关-api)
  - [Task Management](#task-management)
    - [创建任务](#创建任务)
    - [Example 1. Creating tasks](#example-1-creating-tasks)
    - [Example 2. Using the task parameter](#example-2-using-the-task-parameter)
    - [Task states](#task-states)
    - [Block task with delay](#block-task-with-delay)
  - [Queue Management](#queue-management)
    - [API](#api)
    - [Example. Blocking when receiving from a queue](#example-blocking-when-receiving-from-a-queue)
    - [Example. Send structures on a queue](#example-send-structures-on-a-queue)

## Memory Manage (heap)

FreeRTOS 五种内存分配策略 

`FreeRTOS/Source/portable/MemMang`

`heap_1.c, heap_2.c, heap_3.c, heap_4.c, heap_5.c`

堆(数组)大小的定义: `FreeRTOSConfig.h`

`#define configTOTAL_HEAP_SIZE xxx`

每个创建的任务会在堆上创建一个任务控制快(TCB)和一个调用堆栈.

![heap_show](images/heap_show.png)

### heap_1.c

堆大小: `configTOTAL_HEAP_SIZE`

实现了一个基础功能的`pvPortMalloc()`, 不实现`vPortFree()`.

(创建任务后不删除任务的项目)

### heap_2.c

兼容老项目, 新项目使用`heap_4.c`

### heap_3.c

使用标准库的`malloc()`和`free()`函数.

线程安全: 暂停调度器.

heap_size: 链接器决定(configTOTAL_HEAP_SIZE不起作用)

### heap_4.c

堆大小: `configTOTAL_HEAP_SIZE`

分配方法: First fit algorithm

![heap_4_schema](images/head_4_schema.png)

自定义堆地址(`configAPPLICATION_ALLOCATED_HEAP`)

`#define configAPPLICATION_ALLOCATED_HEAP 1`

gcc:
`uint8_t ucHeap[configTOTAL_HEAP_SIZE] __attribute__ ((section(".my_heap")));`

### heap_5.c

可以设置多个堆(与`heap_4.c`不同).

分配方法: First fit algorithm

设置堆地址 API:

```c
typedef struct HeapRegion
{
    /* The start address of a block memory that will be part of the heap.*/
    uint8_t *pucStartAddress;

    /* The size of the block of memory in bytes.*/
    size_t xSizeInBytes;
} HeapRegion_t;

void vPortDefineHeapRegions(const HeapRegion_t * const pxHeapRegions);
```

### Heap 相关 API

```c
size_t xPortGetFreeHeapSize( void );
size_t xPortGetMinimumEverFreeHeapSize( void );

#define configUSE_MALLOC_FAILED_HOOK 1
void vApplicationMallocFailedHook( void );
```

## Task Management

### 创建任务

```c
/*
 * pvTaskCode: Task Function pointer
 * 
 * #define configMAX_TASK_NAME_LEN xxx
 * pcName: A descriptive name for the task. (For debugging aid)
 * 
 * usStackDepth: e.g. 100, 32-bits cpu, ( = 100 * 4 bytes ) 
 *
 * pvParameters: pass to task
 *
 * #define configMAX_PRIORITIES xxx
 * uxPriority: 0 - configMAX_PRIORITIES-1 (low - high)
 * 
 * pxCreatedTask: task handle
 *
 * Returned value: 1. pdPASS 2. pdFAIL
 */
BaseType_t xTaskCreate( TaskFunction_t pvTaskCode,
                        const char * const pcName,
                        uint16_t ucStackDepth,
                        void *pvParameters,
                        UBaseType_T uxPriority,
                        TaskHandle_t *pxCreatedTask);
```

### Example 1. Creating tasks

```c
void vTask1( void *pvParameters )
{
    const char *pcTaskName = "Task 1 is running\r\n";
    volatile uint32_t ul;  // volatile to ensure ul is not optimized away.

    for ( ;; )
    {
        vPrintString( pcTaskName )

        // delay
        for ( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ ) 
        {

        }
    }
}

int main( void )
{
    xTaskCreate( vTask2, "Task 2", 1000, NULL, 1, NULL );

    vTaskStartScheduler();

    for ( ;; );
}
```

### Example 2. Using the task parameter

```c
void vTaskFunction( void *pvParameters )
{
    char *pcTaskName;
    volatile uint32_t ul;

    pcTaskName = ( char * ) pvParameters;

    for ( ;; )
    {
        vPrintString( pcTaskName );
        for (ul = 0; ul < mainDELAY_LOOP_COUNT; ul++)
        {

        }
    }
}

static const char *pcTextForTask1 = "Task1 is running\r\n";
static const char *pcTextForTask2 = "Task2 is running\r\n";

int main()
{
    xTaskCreate(vTaskFunction, "Task 1", 1000, (void*)pcTextForTask1, 1, NULL);
    xTaskCreate(vTaskFunction, "Task 2", 1000, (void*)pcTextForTask2, 1, NULL);

    vTaskStartScheduler();

    for (;;);
}
```

### Task states

![task_states](images/task_states.png)

### Block task with delay

```c
/*
 * xTicksToDelay: ticks (e.g. pdMS_TO_TICKS(100) - 100ms)
 */
void vTaskDelay( TickType_t xTicksToDelay );
```

## Queue Management

### API

```c
/*
 * uxQueueLength: The maximum number of items ...
 * uxItemSize: Data item size in bytes
 * return parameters: handle of queue
 */
QueueHandle_t xQueueCreate( UBaseType_t uxQueueLength, UBaseType_t uxItemSize );

BaseType_t xQueueSendToFront( QueueHandle_t xQueue, const void * pvItemToQueue, TickType_t xTicksToWait );
BaseType_t xQueueSendToBack( QueueHandle_t xQueue, const void * pvItemToQueue, TickTypt_t xTicksToWait );
// Interrupt-safe
// xQueueSendToFrontFromISR()
// xQueueSendToBackFromISR()

BaseType_t xQueueReceive( QueueHandle_t xQueue, void * const pvBuffer, TickType_t xTicksToWait );
// Interrupt-safe
// xQueueReceiveFromISR()

UBaseType_t uxQueueMessagesWaiting( QueueHandle_t xQueue );
// Interrupt-safe
// uxQueueMEssagesWaitingFromISR()

```

### Example. Blocking when receiving from a queue

```c
static void vSenderTask( void *pvParameters )
{
    int32_t lValueToSend;
    BaseType_t xStatus;

    lValueToSend = (int32_t) pvParameters;

    for (;;) 
    {
        xStatus = xQueueSendToBack(xQueue, &lValueToSend, 0);
        if (xStatus != pdPASS)
        {
            vPrintString("Could not send to the queue.\r\n");
        }
    }
}

static void vReceiverTask( void *pvParameters )
{
    int32_t lReceiverdValue;
    BaseType_t xStatus;
    const TickType_t xTicksToWait = pdMS_TO_TICKS( 100 );

    for (;;)
    {
        if ( uxQueueMessagesWaiting(xQueue) != 0)
        {
            vPrintString("Queue should have been empty!\r\n");
        }

        xStatus = xQueueReceive( xQueue, &lReceivedValue, xTicksToWait );
        if (xStatus == pdPASS)
        {
            vPrintStringAndNumber( "Received = ", lReceivedValue);
        } 
        else 
        {
            vPrintString("Could not receive from the queue.\r\n");
        }
    }
}

QueueHandle_t xQueue;

int main( void )
{
    xQueue = xQueueCreate( 5, sizeof( int32_t ));

    if (xQueue != NULL)
    {
        xTaskCreate(vSenderTask, "Sender1", 1000, (void *)100, 1, NULL);
        xTaskCreate(vSenderTask, "Sender2", 1000, (void *)200, 1, NULL);

        xTaskCreate(vReceiverTask, "Receiver", 1000, NULL, 2, NULL);

        vTaskStartScheduler();
    }
    else
    {

    }
    for (;;);
}
```

### Example. Send structures on a queue

```c
typdef enum
{
    eSender1,
    eSender2
} DataSource_t;

typedef struct
{
    uint8_t ucValue;
    DataSource_t eDataSource;
} Data_t;

static const Data_t xStructuresToSend[2] =
{
    {100, eSender1},
    {200, eSender2}
};

static void vSenderTask( void *pvParameters )
{
    BaseType_t xStatus;
    const TickType_t xTicksToWait = pdMS_TO_TICKS( 100 );
    for (;;)
    {
        xStatus = xQueueSendToBack( xQueue, pvParameters, xTicksToWait );
        if (xStatus != pdPASS)
        {
            vPrintString("Could not send to the queue.\r\n");
        }
    }
}

static void vReceiverTask( void *pvParameters )
{
    Data_t xReceivedStructure;
    BaseType_t xStatus;
    
    for (;;)
    {
        if (uxQueueMessagesWaiting(xQueue) != 3)
        {
            vPrintString("Queue should have been full!\r\n");
        }

        xStatus = xQueueReceive(xQueue, &xReceivedStructure, 0);

        if (xStatus == pdPASS)
        {
            if (xReceivedStructure.eDataSource == eSender1)
            {
                vPrintStringAndNumber("From Sender 1 = ", xReceivedStructure.ucValue);
            }
            else
            {
                vPrintStringAndNumber("From Sender 2 = ", xReceivedStructure.ucValue);
            }
        }
        else
        {
            vPrintString("Could not receive from the queue.\r\n");
        }
    }
}

QueueHandle_t xQueue;

int main()
{
    xQueue = xQueueCreate(3, sizeof(Data_t));
    if (xQueue != NULL)
    {
        xTaskCreate(vSenderTask, "Sender1", 1000, &(xStructsToSend[0]), 2, NULL);
        xTaskCreate(vSenderTask, "Sender2", 1000, &(xStructsToSend[1]), 2, NULL);

        xTaskCreate(vReceiverTask, "Receiver", 1000, NULL, 1, NULL);

        vTaskStartScheduler();
    }
    else
    {

    }
    for(;;);
}
```