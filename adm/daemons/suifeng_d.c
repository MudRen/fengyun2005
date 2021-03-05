// /adm/daemons/action_d.c
// created by akuma@mud.com.cn
// on 2009-03-28
// 活动精灵，负责发起和关闭每日的活动
// 这个daemon我倾向于做成广播器和活动状态的容器
// 他本身什么也不做，其他系统从他这里获取某个活动是否开启的状态
// 应该被preload

#include <localtime.h>
#include <ansi.h>
#define DEFAULT_TIMES   900
#define HOLIDY_TIMES    900
void check_action_startend();

void create()
{
        check_action_startend();
}

void check_action_startend()
{
	mixed *ltime;
	int now_wday;
        int now_hour;
        int times;

	ltime = localtime(time());
	now_wday = ltime[LT_WDAY]; //当前分钟，这里要用localtime(获取本地时间)
        now_hour = ltime[LT_HOUR];
	
	//为了保险，先remove自己的call_out
	remove_call_out("check_action_startend");
	
        times = DEFAULT_TIMES;
        if (now_wday == 5) {
                if (now_hour >= 15) {
                        times = HOLIDY_TIMES;
                }
        } else if (now_wday == 1) {
                if (now_hour < 3) {
                        times = HOLIDY_TIMES;
                }
        } else if (now_wday == 6 || now_wday == 0) {
                        times = HOLIDY_TIMES;
        }
        "/adm/daemons/questd"->set_holiday(times);
	call_out("check_action_startend",60);
}

