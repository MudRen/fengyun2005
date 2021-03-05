// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "帝释天殿");
	set("long", @LONG
帝释天乃众神首领，但佛经中言：一切皆无常。帝释天也会寿尽而亡，所谓天 
人五衰即为：衣裳垢腻、头上花萎、身体臭秽、腋下汗出、不乐本座。帝释天殿乃 
少林一百零八堂的主殿，只有佛法高深的少林弟子方有机会至此求道宣法。而现在 
一个硕大的铁笼放在正中，两个年愈百岁的老僧盘膝两旁。笼中一个倔强的少年枪 
一般傲然挺立着。 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("afei_cage",1);
	set("exits",([
		"west" : __DIR__"sl-exit",

	]));
        set("objects", ([
                __DIR__"npc/sl-afei": 1,
 		__DIR__"npc/sl-jailer1": 1,
 		__DIR__"npc/sl-jailer2": 1,
             
        ]) );
        
        set("item_desc", ([
		"铁笼": "
一个大铁笼，每根铁条都有拳头粗细，加着巨大的铜锁，看来除了找到钥匙外 
是别无开笼之法的了。。\n",
		"cage": "
一个大铁笼，每根铁条都有拳头粗细，加着巨大的铜锁，看来除了找到钥匙外 
是别无开笼之法的了。。\n",
	]) );
	setup();
	
}

int	valid_leave(object who, string dir){
	
	object room;
	if (who->query_temp("maze/sl_2")) {
		message_vision(YEL"
$N刚准备迈步离开帝释天殿，忽然殿顶疾风猛至，一个硕大无朋的大铁笼兜头
盖脸把$N罩了起来。一根粗粗的铁棍当头砸在$N的后脑勺上。 "+HIR"


$N顿时失去了知觉。。。 

\n"NOR,who);
		who->delete_temp("maze/sl_2");
		who->unconcious();
		who->set_temp("maze/see_li",2);
		room = find_object(AREA_FY"fysecret");
		if (!room) room = load_object(AREA_FY"fysecret");
		who->move(room);
		return notify_fail("");
	}
	return 1;
}


void reset(){
	set("door_open",0);
	::reset();
}