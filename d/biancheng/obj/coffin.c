inherit ITEM;
#include <ansi.h>


void create()
{
        set_name("棺材", ({ "coffin","棺材" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("value", 1);
	}
	set("closed",1);
	set("burnt",0);
	::init_item();
}

void init()
{
	add_action("do_open","open");
	add_action("do_look","look");
}


int do_look(string arg){
	object ob,me;
	me=this_player();
	ob=this_object();
	
	if (arg=="coffin" || arg=="棺材"){
		if (query("burnt")) tell_object(me,"一具烧得黑乎乎的棺材架子，什么也看不出来。\n");
		else if (query("burning")) tell_object(me,"火势熊熊，眼看就要把棺材烧毁了。\n");
		else if (!query("closed")) tell_object(me,"一具普普通通的棺材，里面躺着个死人。\n");
		else if (!me->query("marks/wanma/准备杀刺客_ma"))
			tell_object(me,"棺材本来是全新的，漆得很亮，现在却已被碰坏了很多地方。\n");
		else tell_object(me,"棺材本来是全新的，漆得很亮，现在却已被碰坏了很多地方。仔细端详一下，
有几个棺材里面好像有人，也许应该打开来看一下。\n");
		return 1;
	}
	return 0;
}
			

int do_open(string arg)
{
	object	me, ob,tuozi;
        seteuid(getuid());
        
        if( !arg || (arg != "coffin"&& arg != "棺材") ) 
        		return 0;
        
        me = this_player();
	ob = this_object();
	
	if (!me->query("marks/wanma/准备杀刺客_ma")) {
		tell_object(me,"棺材有什么好碰的，晦气！\n");
		return 1;
	}
	
	if (!query("closed")) {
		tell_object(me,"棺材已经是打开的了。\n");
		return 1;
	}
	
	if (tuozi=present("ding qiu",environment(ob))) {
		tell_object(me,tuozi->name()+"说：“怎么，急着想进棺材吗？要不要我送你一段？”\n");
		return 1;
	}
	
	if (!environment(ob)->query("tuozi_out")) {
		message_vision(HIB"呼啦一声，从屋檐上跳下个穿蓝衣的驼子挡在棺材前。\n"NOR,me);
		tuozi=new(AREA_BIANCHENG"npc/tuozi");
		if (tuozi) tuozi->move(environment(ob));
		environment(ob)->set("tuozi_out",1);
		return 1;
	}
		
	if (query("burnt")) {
		tell_object(me,"晚了，棺材已经烧得一团漆黑，什么也看不出来了。\n");
		return 1;
	}	
	
	message_vision("$N“嘎吱”一声，将棺材盖打开了。。。\n", me, ob);
	tell_object(me,YEL"打开棺盖，里面果然不是空的。棺村里有个死人，另外几具棺材也是一样。
棺材里有死人，本不是件奇怪的事。不过，这些死人竟然是镇上的张老实，
陈大倌、丁老四、宋老板和胡掌柜。这些人刚才明明都在镇上的，怎么会
忽然都死在这里？除非镇上的那些是。。。。。。\n"NOR);
	me->set("marks/wanma/棺材之谜",1);
	ob->set("long","棺材盖已经被打开，里面躺着个死人。\n");
	ob->set("closed",0);
        return 1;
}

int is_container() { return 1; }

