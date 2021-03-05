// message.h

#ifndef __MESSAGE_H__
#define __MESSAGE_H__


//
// Client 讯息类别定义
//
#define SYSMSG          "SYSMSG"                // 系统讯息
#define ENVMSG          "ENVMSG"                // 环境讯息
#define CMDMSG          "CMDMSG"                // 指令讯息
#define CHNMSG          "CHNMSG"                // 频道讯息
#define EMTMSG          "EMTMSG"                // 表情讯息
#define SAYMSG          "SAYMSG"                // 说话讯息
#define TELLMSG         "TELLMSG"               // 交谈讯息
#define ERRMSG          "ERRMSG"                // 错误讯息
#define ETCMSG          "ETCMSG"                // 其他讯息
#define GAMEMSG         "GAMEMSG"               // 游戏讯息

int  is_loging_now();
int  start_log();
void end_log();
void log_message(string msg);
void log_command(string cmd);
void receive_message(string msgclass, string msg);
void clear_written();
int  is_waiting_command();
void write_prompt();
void receive_snoop(string msg);

#endif
