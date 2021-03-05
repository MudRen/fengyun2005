// street4.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","问礼碑");
  set("long",@LONG
这里便是一品钦差殷大人贬谪济南后，重新修建的问礼碑。《论语》有言：子
入大庙，每事问。后人据此在这儿建了问礼碑。此处本已破败不堪，鲜有游人。而
殷正廉来此后，但觉齐鲁子弟淳厚的风气已一日不如一日，惋惜恼怒之余，便差人
在此重修问礼碑，凡是行人至此必得恭敬而行，一律不得佩带兵刃。往南不远便是
新建的衙门府邸。
LONG
  );
  set("exits",([
         "northup":__DIR__"street3",
         "south":__DIR__"street5",
//         "west":__DIR__"mjgate",
         "east":__DIR__"firstbrook",
               ]));
	set("objects", ([
		__DIR__"npc/doorguard" : 1,
	]));
    set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	setup();

}

int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me)) 
        {
            if( dir == "south"  && ob=present("yinxian", this_object())) 
             {
                	inv = all_inventory(me);
                    for(i=0; i<sizeof(inv); i++) 
               {
                        	if((inv[i]->query("weapon_prop")) && (inv[i]->query("equipped")))
                              return notify_fail(ob->name()+"抱拳道：不可佩带兵刃进府！\n");
             		}
        	}
    }
        return 1;
}


