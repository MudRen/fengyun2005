#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  	set("short","铜亭铁塔");
  	set("long","岱庙后院的东西两侧，有两处惹人注目的古迹，东为铜亭，西为铁塔。铜亭又
名“金阙”，为明万历四十一年铸。亭为铜质，施以鎏金，内祀元君铜像。璀璨耀
目，端庄浑重。西侧的铁塔为明嘉靖年间铸，造型质朴雄伟，塔上刻有日月星云，
山水岩石，寓意光明普照，坚固永生，山海年长的意思。院中更有"YEL"古柏"NOR"数棵。
"
  );
  	set("exits",([
         	"north":__DIR__"houzai.c",
         	"south":__DIR__"houqing.c",
        ]));
        set("objects", ([
            	"/obj/specials/ding/ding_dm" : 1,
            	__DIR__"npc/xi" : 1,
       	]) );
       	set("item_desc", ([
        	"古柏":"
后花园的西墙下，也有一棵古柏，苍翠的树冠上，簇拥着茂密的枝叶，好似
一团团云朵，所以被称为『云列三台』，被列为岱庙八景之一。\n",
        	"柏":"
后花园的西墙下，也有一棵古柏，苍翠的树冠上，簇拥着茂密的枝叶，好似
一团团云朵，所以被称为『云列三台』，被列为岱庙八景之一。\n",
		"tree":"
后花园的西墙下，也有一棵古柏，苍翠的树冠上，簇拥着茂密的枝叶，好似
一团团云朵，所以被称为『云列三台』，被列为岱庙八景之一。\n",
        ]) );
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
  	
}

int valid_leave(object who, string dir) {
	object wei;
	
	if (who->query("class") == "demon")
		return 1;

	if (dir == "south") {
		if (wei = present("xi wei",this_object()))
		if (!userp(wei) && !who->query_temp("daimiao/passwd") ) {
			return notify_fail(wei->name()+"喝道：“口令！”（answer）\n");
		if (who->query("vendetta/demon"))
			return notify_fail(wei->name()+"喝道：小子，杀了人还敢来？\n");
		}
	}
	return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

