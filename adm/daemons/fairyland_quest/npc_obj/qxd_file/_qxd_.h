// qxd 主文件，由上级目录  _qxd_.c 以 #include 调用。
// naihe 3:15 03-10-19
// 各项顺序不得调乱，各项不得缺少。


#define    HJ_OUT_ROOM    HJ_DIR + "room_gameover_hj"

#include "1_vars_qxd.h"         // 文件头的变量设定

#include "2_preload_qxd.h"      // 预装函数，全局各处要用

#include "3_file_qxd.h"         // create() 及其他主要功能

#include "4_cmds_qxd.h"         // 支持玩家基本指令

#include "4-1_cmds_qxd.h"       // 越写越多，写不下了，放到这里

//#include "5_help_qxd.h"         // help 函数   help 函数取消了。

#include "6_combat_qxd.h"       // 战斗相关指令

#include "7_pfm_qxd.h"          // 绝招支持


