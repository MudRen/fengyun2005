/*************************************************

本游戏移动时，无须作任何改动，可直接放置任何目录内。

*************************************************/


/**********************************************************************
各物品详细说明：

_qxd_.c  玩家主判断物品，包括进入游戏、退出游戏、游戏内指令、
                   游戏内迷题及其他相关资讯，必不可少
hj_wiztools.c      巫师工具，功能有：可复制游戏内物件等（随时添加）


hj_box.c 宝箱，打开时随机发放人物或物品     标记为  "hj_game/obj","box"

hj_npc_kill.c  杀戮型NPC，亦被作为携带各族宝物之NPC使用
               标记为 "hj_game/npc","kill"
hj_npc_quest.c 迷题型NPC，其部分资料需要正常游戏途径获得的 _qxd_.c 支持
               标记为 "hj_game/npc","quest"
hj_npc_other.c 其他类型NPC，包括教授技能、恢复体力、提升最大HP、寻求宝物（有奖励）等
               标记为 "hj_game/npc","other"

hj_obj_weapon.c   兵器类物品，包括各式剑及魔法水晶（皆限用次数）
                  标记为 "hj_game/obj","sword" 或 "hj_game/obj","magic"
hj_obj_quest.c    领会技能型物品，文件名不合真实含义。可学懂游戏内技能。
                  标记为 "hj_game/obj","quest"
hj_obj_other.c    补给类物品，文件名不合真实含义。各类补充HP的物品。
                  标记为 "hj_game/obj","other"
hj_obj_tools.c    游戏工具型物品，例如定向水晶可获得较为准确的当前房间标记号等。
                  标记为 "hj_game/obj","tools"
hj_obj_gem.c      不记入obj_list.h，本物品作为玩家寻求宝物时的附加条件使用。
                  标记为 "hj_game/obj","the_gem"
hj_obj_gem_qz.c   同上，另一个任务的附加条件。


feng_npc.c yu_npc.c lei_npc.c dian_npc.c 及 fyld_npc.h
       四个国度的NPC，携带玩家需要寻求的宝物的最重要之组成部分
feng_obj.c yu_obj.c lei_obj.c dian_objc. 及 fyld_obj.h
       四个国度的OBJ,此物品将通过严格处理出现

以上国度的NPC或OBJ物件，都将执行判断隶属玩家情况而决定是否自毁的函数。


hj_npc_ashman.c    清道夫（小矮人），将负责清除各类玩家丢下的垃圾。
                   标记为 "hj_game/npc","ashman"


迷题型物品    奖励型物品   （游戏工具型物品）
*************************************************************************/


// HJ_DIR 在此定义。

#include "get_hj_dir.h"

string *obj_list_all=({

    HJ_DIR + "npc_obj/hj_box",
    HJ_DIR + "npc_obj/hj_box",        // 宝箱概率增加。
    HJ_DIR + "npc_obj/hj_npc_kill",
    HJ_DIR + "npc_obj/hj_npc_kill",   // 杀戮型怪物概率增加。
    HJ_DIR + "npc_obj/hj_npc_quest",
    HJ_DIR + "npc_obj/hj_npc_quest",  // 其他型NPC概率增加。
    HJ_DIR + "npc_obj/hj_npc_other",
    HJ_DIR + "npc_obj/hj_obj_tools",
    HJ_DIR + "npc_obj/hj_obj_quest",
    HJ_DIR + "npc_obj/hj_obj_other",
    HJ_DIR + "npc_obj/hj_obj_weapon",
});

string *obj_list_obj=({
    HJ_DIR + "npc_obj/hj_obj_tools",
    HJ_DIR + "npc_obj/hj_obj_quest",
    HJ_DIR + "npc_obj/hj_obj_other",
    HJ_DIR + "npc_obj/hj_obj_other",   // 补充HP类果品多加一个机会取得。
    HJ_DIR + "npc_obj/hj_obj_weapon",
});

string *obj_list_npc=({
    HJ_DIR + "npc_obj/hj_npc_kill",
    HJ_DIR + "npc_obj/hj_npc_quest",
    HJ_DIR + "npc_obj/hj_npc_other",
});

// 下面是各个国度的宝物组成部分。

string *obj_list_feng=({
    HJ_DIR + "npc_obj/feng_obj",
    HJ_DIR + "npc_obj/feng_npc",
});

string *obj_list_yu=({
    HJ_DIR + "npc_obj/yu_obj",
    HJ_DIR + "npc_obj/yu_npc",
});

string *obj_list_lei=({
    HJ_DIR + "npc_obj/lei_obj",
    HJ_DIR + "npc_obj/lei_npc",
});

string *obj_list_dian=({
    HJ_DIR + "npc_obj/dian_obj",
    HJ_DIR + "npc_obj/dian_npc",
});

