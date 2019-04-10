#pragma once

#include "global.h"

#define NUM_TASKS 16

typedef void (*TaskFunc)(u8 taskId);

struct Task
{
    TaskFunc func;
    bool8 isActive;
    u8 prev;
    u8 next;
    u8 priority;
    s16 data[16];
};

#define gTasks ((struct Task*) 0x3005090) //extern struct Task gTasks[ACTIVE_SENTINEL];

void __attribute__((long_call)) ResetTasks(void);
u8 __attribute__((long_call)) CreateTask(TaskFunc func, u8 priority);
void __attribute__((long_call)) InsertTask(u8 newTaskId);
void __attribute__((long_call)) DestroyTask(u8 taskId);
void __attribute__((long_call)) RunTasks(void);
u8 __attribute__((long_call)) FindFirstActiveTask(void);
void __attribute__((long_call)) TaskDummy(u8 taskId);
void __attribute__((long_call)) SetTaskFuncWithFollowupFunc(u8 taskId, TaskFunc func, TaskFunc followupFunc);
void __attribute__((long_call)) SwitchTaskToFollowupFunc(u8 taskId);
bool8 __attribute__((long_call)) FuncIsActiveTask(TaskFunc func);
u8 __attribute__((long_call)) FindTaskIdByFunc(TaskFunc func);
u8 __attribute__((long_call)) GetTaskCount(void);

/*;
void SetWordTaskArg(u8 taskId, u8 dataElem, u32 value);
u32 GetWordTaskArg(u8 taskId, u8 dataElem);
*/