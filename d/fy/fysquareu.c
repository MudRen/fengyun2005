#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short", HIR"天机阁"NOR);
    set("long", @LONG
从蟠龙摩天石柱往上一步，便是风云城内最热闹、也是最令人向往的地方，这
里原来只是一个普普通通的小楼阁，自从那一天来了一个普普通通的老头儿，一切
便全变了，就连名震天下的小李探花，雄霸四方的上官金虹，见了他也是恭恭敬敬，
因为，他便是百晓生兵器谱上排名第一的天机老人！在天机老人身边，熙熙攘攘地
围满各色武林人士，敢情都在向他请教[0;37m（quest）[0;32m来着。

  	闲云野鹤 [0;1;33m天机老人[0;32m(Tian ji)

LONG
    );
    set("exits", ([ /* sizeof() == 4 */
		"down" : __DIR__"fysquare",
      ]));
		set("tianji_square",1);
	
    set("objects", ([
			__DIR__"npc/half_god" : 1,
                        __DIR__"npc/liu" : 1,
//			__DIR__"npc/center_soldier" : 1,
      ]) );

    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",10);
    set("no_fly",1);
    set("no_dazuo",1);
    set("no_study",1);
    set("no_fight",1);
    set("no_magic",1);
    set("brief_objects",0);
    setup();
}

int valid_leave(object who, string dir) {
	if (dir == "down") {
		if (who->query("env/checkbrief") == 0) { 
			who->set("env/brief",0);
		}
	}
	return ::valid_leave(who,dir);
}