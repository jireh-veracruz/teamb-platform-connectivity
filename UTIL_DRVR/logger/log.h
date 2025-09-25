#ifndef __LOG_SERVICE_H__
#define __LOG_SERVICE_H__


#define LOG_LVL_EMERGNCY            0
#define LOG_LVL_ALERT               1
#define LOG_LVL_CRIT                2
#define LOG_LVL_ERR                 3
#define LOG_LVL_WARNING             4
#define LOG_LVL_NOTICE              5
#define LOG_LVL_INFO                6
#define LOG_LVL_DEBUG               7


void init_log(void);
int log_write(char* data);
int log_set_level(int level);
void log_service(void);


#endif //__LOG_SERVICE_H__