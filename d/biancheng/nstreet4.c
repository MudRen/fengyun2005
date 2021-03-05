inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "北街尽头");
        set("long", @LONG
小镇的繁华很快就在此截然中止，向前望又是草原，无边无际。不时有几骑快
马驰过，骑士身穿白衣，当先一人手中黑铁长枪上三角大旗在风中猎猎作响。一辆
八马并驰的黑漆大车，就停在街正中，黑漆如镜，车上斜插着一面白绫三角旗：
“万马堂。”车旁一人肃立待客，一身白衣如雪。
LONG
        );
        set("exits", ([ 
		"north": __DIR__"grassland1",
		"south": __DIR__"nstreet3",
	]));
        set("objects", ([
        	__DIR__"npc/yunzaitian": 1,
//        	__DIR__"obj/mache":	1,
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",40);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

void init(){
//	add_action("do_enter","enter");		
}


int do_enter(string arg){
	object me,ob,cart,chefu;
	
	me=this_player();
	ob=this_object();	
	
	if (!arg || (arg!="mache" && arg!="马车")) {
		tell_object(me,"你要进入哪里？\n");
		return 1;
	}
	
	if (query("mark/rented")) {
		tell_object(me,"这儿的马车刚开走，等一会儿吧。\n");
		return 1;
	}
		
	if (!REWARD_D->check_m_success(me,"名扬边城")){
		message_vision("\n车夫向$N看了一眼说：想上万马堂的迎宾车，须得先问过花场主。\n",me);
		message_vision("$N从马车上被撵了下来。\n",me);
		return 1;
	}
	
	cart=new(__DIR__"npc/obj/carriage");
    cart->move(this_object());
	    	
    chefu=new(__DIR__"npc/chefu");
    chefu->move(ob);
    chefu->get_quest(AREA_BIANCHENG"carriageway");
    chefu->set_carriage(cart);
	message_vision(WHT"一身白衣的马车夫驾着一辆黑漆大车驶了过来。\n"NOR,chefu);

	set("mark/rented",1);
	set("long", @LONG
小镇的繁华很快就在此截然中止，向前望又是荒原，无边无际。不时有几骑快
马驰过，骑士身穿白衣，当先一人手中黑铁长枪上三角大旗在风中猎猎作响。一个
人肃立街心待客，却是一身白衣如雪。
LONG
        );
	message_vision("$N得意洋洋地走进黑漆大车。\n\n",me);
	me->move(cart);
	chefu->go_now();
	call_out("check_status",30,chefu);
	return 1;
}


int check_status(object ob)
{
	if (!ob)	{
		set("mark/rented",0);
	        set("long", @LONG
小镇的繁华很快就在此截然中止，向前望又是荒原，无边无际。不时有几骑快
马驰过，骑士身穿白衣，当先一人手中黑铁长枪上三角大旗在风中猎猎作响。一辆
八马并驰的黑漆大车，就停在街正中，黑漆如镜，车上斜插着一面白绫三角旗：
“关东万马堂。”一个人肃立待客，却是一身白衣如雪。
LONG
        	);
	}else	{
		call_out("check_status",30,ob);
	}
}

	