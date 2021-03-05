inherit ROOM;
#include <ansi.h>

void create()

{
    set("short", HIM"观武台"NOR);
    set("long", @LONG
南面不远处就是风云城的探花楼，一年一度的武林大会就在那儿举行。许多江
湖人在这里为各自所支持的门派加油助威，也有不少人挤在墙边明眸女子的身边下
着注。东边墙上贴了一块告示（ｓｉｇｎ），上面写着投注规则以及上届武林大会
的门派座次。
LONG
    );
    set("exits", ([ 
	"east": __DIR__"tiandoor",
      ]));
    set("objects", ([
	"/d/bashan/npc/so":1,
	"/d/fy/npc/tatoo.c":1,
	/*		"/d/wiz/obj/betabag":5,
			"/obj/wiz_toy/taskstone": 1,
			"obj/book/class/iceheart_buffup_2":	1,
			"obj/book/class/iceheart_buffup_3":	1,
			"obj/book/class/iceheart_buffup_4":	1,
			"/obj/book/class/qidaoforce_juxue_2":	1,
			"/obj/book/class/qidaoforce_juxue_3":	1,
			"/obj/book/class/essencemagic_team_drift_1":1,
			"/obj/book/class/cloud-dance_yegui_1":	1,		
			"/obj/book/class/cloud-dance_yegui_2":	1,
			"/obj/book/class/cloud-dance_yegui_3":	1,
			"/obj/book/class/dragonstrike_zjbl_2":  1,
			"/obj/book/class/dragonstrike_zjbl_3":  1,
			"/obj/book/class/dragonstrike_zjbl_4":  1,
			"/obj/book/class/xueyeqianzong_feline_2": 1,
			"/obj/book/class/xueyeqianzong_feline_3": 1,
			"/obj/book/class/xueyeqianzong_wolverine_3": 1,
			"/obj/book/class/xuezhan-spear_liguang_1":1,
			"/obj/book/class/xuezhan-spear_liguang_2":1,
			"/obj/book/class/xuezhan-spear_liguang_3":1,
			"/obj/book/class/yijinjing_shield_2": 1,
			"/obj/book/class/yijinjing_shield_3": 1,*/


      ]) );
    set("item_desc", ([
	"sign": @TEXT
==========================================================
投注规则：

lottolist    查询你已经购买的彩券，查询下次开奖时间
purchase <数目>   一次支付一笔钱，让我为你乱数抽取一些彩券
checkout     结算上一期的彩金

彩券每注一两黄金，每三小时自动开奖一次，请及时将所中奖项结算。

==========================================================
TEXT
      ]) );
    set("coor/x",-20);
    set("coor/y",40);
    set("coor/z",0);
    set("NONPC",1);
    setup();
}


