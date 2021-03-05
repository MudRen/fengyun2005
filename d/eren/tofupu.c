inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "欧阳豆腐铺");
        set("long", @LONG
欧阳豆腐铺的豆腐白如纯玉，细若凝脂，其味清淡中藏着鲜美，吃起来适口清
爽，久食不腻。其汤呈乳白色，人称“奶汤”，豆腐块漂在汤上，又称漂汤，汤味
甚鲜，也称鲜汤。名播遐尔，求食者趋之若鹜，颇有盖过哈哈酒楼的架势。
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"vroad4",
	]));
        set("objects", ([
		__DIR__"npc/ouyang1":1,
		__DIR__"npc/ouyang2":1,
	]) );
	set("coor/x",80);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
