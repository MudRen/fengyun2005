// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "两界碑");
        set("long", @LONG
石梁上可容三人并肩而行，约有七丈长短，整块石头浑然一体，不知是神
工天成，或是奇工巧匠夺造化之功而出。(ｊｕｍｐ　ｄｏｗｎ)在石梁正
中立着一块塔状石碑，碑上的文字已经随着时间的流逝渐而模糊，石梁西
面是一片阴风惨雾，而东边却依然繁花似锦，拥翠环山。侧身望下，石梁
下方是一条山间峡谷，可以行人。
LONG
        );
	set("objects", ([
		__DIR__"obj/rock3" : 1,
	]));
	set("exits",([
  		"west" : __DIR__"wuzhang",
  		"east" : __DIR__"leidashi",
	]) );
	set("item_desc",([
		"石梁":	"一座石梁，看似有三人宽下，背上可以行人。\n",
		"石碑":	"石碑呈塔状，上面的文字已经随着时间的流逝渐而模糊。\n",
	]));
		
	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


void init()
{
	add_action("do_jump", ({"dash","jump" }));
}


int do_jump(string arg)
{
   
   	object me, room;
   	int m;

   	me = this_player();
   	m = me->query_skill("move",1);
      
      	if(!arg || (arg != "down" && arg != "下" && arg!= "bridge" && arg!="桥下" 
      		&& arg!="桥" && arg != "虎踞石"  && arg != "石梁"  && arg != "梁下"
      		&& arg!="ridge" )) {
      		write("你没法儿向那里跳。\n");
      		return 1;
      	}
      	
      	if (m >= 70 && me->query("force") >= me->query("max_force"))
		{
			message_vision(CYN"$N提一口气，纵身向石桥下跃去。\n"NOR,me);
			room = load_object(__DIR__"huju");
         	me->move(room);
         	message("vision", me->name()+"从石桥上跃了上来。\n", environment(me), me);
         	return 1;
      	}
      	else if (m <70)
		{
         	tell_object(me, "以你的轻身功夫，小心跌个头破血流。\n");
        	return 1;
		} 
		else
		{
			tell_object(me, "你的内力过弱，恐怕跳不过去。\n");
        	return 1;
			
		}			
      return 1;
}
