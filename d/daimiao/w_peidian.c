#include <room.h>
inherit ROOM;

void create()
{
  	set("short","西配殿");
  	set("long",@LONG
遥参亭正殿两侧是东西配殿各三间，前后步廊式，上覆黄琉璃瓦，供奉送生娘
娘和眼光奶奶。这里有两块碑：《宋天贶殿碑铭》和《宋封祀坛颂碑》，前碑记叙
天贶殿的修建事情，后碑叙述的是宋真宗登泰山祭拜答谢降“天书”的情况。然而
自西方神教占据岱庙以来，这里就成了他们临时关押可疑之人的地方。
LONG
  );
//  	set("exits",([
//        	 "east":__DIR__"yaocan",
         	
//        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-10);
	set("coor/y",-65);
	set("coor/z",0);
	set("no_fly",1);
	setup();
  	
}

void reset(){
	object room, *inv;
	int i, num;
	::reset();
	room = this_object();
	inv = all_inventory(room);
	i = sizeof (inv);
	while (i--) {
		if(userp(inv[i])) {
			tell_object(inv[i],"西配殿的大门轰地一声开了，你被一脚踢了出去。\n");
			tell_object(inv[i],"你听到背后一个声音说：“念你初犯，放你一条生路。”\n");
			inv[i]->delete_temp("daimiao/spy");
			inv[i]->move(__DIR__"yaocan");
		}
	}
}

