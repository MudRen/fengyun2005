#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIW"风坛"NOR);
    set("long", 
"风坛乃金钱帮所建，巍峨壮观，坛中流光溢彩，供奉着风神，上官金虹建此风
坛所花费用远甚天地云三坛，然而这还不是西城最高的建筑，远远朝金钱帮的总坛
中望去，一座高耸入云的黄金塔在日光下金碧辉煌，宛如神筑，上官呼风唤雨，权
倾朝野的野心昭然若揭。风坛中匾额草书丈余大小二字："+HIW"

                      风          坛
                   
"NOR        );
        set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"wcloud1",
  		"east" : __DIR__"fysquare",
  		"north" : __DIR__"poemp",
  		"south" : __DIR__"mailst",
]));
        set("outdoors", "fengyun");
        set("objects", ([
//        __DIR__"npc/mei": 1,
                        ]) );

  	set("coor/x",-40);
  	set("coor/y",0);
	set("coor/z",0);
 	set("map","fywest");
	setup();

}

int valid_leave(object me, string dir)
{
//      object ob,room;
        int i;
        mapping condition;
        string *type;
        if( userp(me) && dir == "north")
		{
			condition = me->query_all_condition();
			if( mapp(condition) ) {
				type=keys(condition);
				for (i=0;i<sizeof(type);i++) {
					if (type[i]!="drunk" && type[i]!="buffed" && type[i]!="bandaged")
						return notify_fail("你身罹怪疾，不得进入探花诗台。\n");
				} 
	      	}	
	
			if(me->query("eff_sen")<me->query("max_sen")*95/100
				||me->query("eff_kee")<me->query("max_kee")*95/100
				||me->query("eff_gin")<me->query("max_gin")*95/100 )
				return notify_fail("你伤痕累累，探花诗台不是你的坟场。\n");
		
			tell_object(me,HIR"你进入了比武地区，在探花楼主楼内可自由叫杀，无死亡损失。\n\n"NOR);
		
		}	
		return 1;
}