inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "地狱谷密林");
        set("long", @LONG
念青贡嘎日松贡布就在眼前，但是你看不到，树枝像一把无边无际的伞，遮住
了阳光，遮住了天空，腐烂潮湿的落叶在脚下发出嘎吱的响声，密密的树枝，藤蔓
和野草不时挡住去路，几乎每走一段路就要停下来歇一歇，空气里有浓重的腥湿气
息在悄悄弥漫。
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"diyugu2",
	]));
        set("objects", ([
        	__DIR__"npc/wolf":	4,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1720);
        set("coor/y",620);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

int valid_leave(object obj, string dir){
                        
        message_vision( MAG "路行至此，林子里的腥湿之气熏的人昏昏欲睡。。。\n"NOR,obj);
        if (userp(obj))
        if(!obj->query_condition("mag_mushroom") 
        	&& random(obj->query_skill("perception",1))<50){
            obj->apply_condition("mag_mushroom",random(20)+5);
            message_vision(HIM"$N不由地深吸了一口气。\n"NOR,obj);
        } else  
        	message_vision( HIW"$N意随心动，急忙屏住呼吸。\n"NOR,obj);
        return 1;
}
