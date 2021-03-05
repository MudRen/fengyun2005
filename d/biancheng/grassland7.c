inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "草场深处");
        set("long", @LONG
再往前走，人迹渐稀，此地虽然仍属于万马堂，却很少有人来放牧。半人多高
的蒿草连绵起伏，风呼啸着，在草原上奔跑，掀起层层波浪。正应了那首古诗，敕
勒川，阴山下，天似穹庐，笼盖四野，天苍苍，野茫茫，风吹草低现牛羊。只是这
里没有牛，也没有羊，只有野兽的嚣吼声和风声。
LONG
        );
        set("exits", ([ 
		"west":		__DIR__"grassland5",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
                "grass": "这里的蒿草(grass)很密，但你似乎可以拨开(pushaside)它们。\n",
                "蒿草": "这里的蒿草(grass)很密，但你似乎可以拨开(pushaside)它们。\n"

        ]) );
	set("outdoors", "biancheng");
        set("coor/x",120);
        set("coor/y",90);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


void init()
{
        add_action("do_push", "pushaside");
}


int do_push(string arg)
{
        object me,room;
        
        if( arg == "grass" || arg == "蒿草" || arg == "草") {
        	me = this_player();
        	if (me->query("marks/wanma/寻地洞")) {
        		tell_object(me,"你照着沈三娘的话向东走二十步，再向西南走十二步，用力将蒿草拨开。\n");
        		tell_object(me,"你只觉得脚下的土地一松，轰隆一声掉进了一个地洞。\n");
        		room=find_object(AREA_BIANCHENG"hole");
        		if (!room) room=load_object(AREA_BIANCHENG"hole");
        		message("vision",me->name()+"在蒿草中转了几转，忽然一下子就消失了。\n", environment(me),me);
			me->move(room);
        	} else 
        		message_vision("$N胡乱将身边的蒿草拨开，可是什么也没有发现。\n",me);
        	return 1;
        }   else    {
                write("你要拨开什么？\n");
 	       return 1;
        }
}