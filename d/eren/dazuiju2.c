inherit ROOM;
#include <ansi.h>

int do_look(string arg);

void create()

{
        set("short", "大嘴居后院");
        set("long", @LONG
后院三面是低低的土墙，墙上爬满藤蔓，角落里放着几个花盆，几朵火红的杜
鹃花正开的绚烂。院子里有几个练功的木人和一个武器架，架上胡乱搁着刀剑。一
个十多岁的少女正在练剑，眉目间流露着淡淡的哀愁。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"dazuiju1",
	]));
        set("item_desc",([
        	"武器架":	"武器架上胡乱放着些刀剑。\n",
        	"木人":		"其中有个木人似乎有些奇怪，你看着他，他也看着你，眼珠似乎还转了几下。\n",
        	"woodman":	"其中有个木人似乎有些奇怪，你看着他，他也看着你，眼珠似乎还转了几下。\n",
        ]));
        
        set("objects", ([
        	__DIR__"npc/pinggu": 1,
	]) );
	
	set("coor/x",50);
    set("coor/y",100);
    set("coor/z",0);
	set("map","eren");
	set("thief",1);
	setup();
	
}


void init(){
	add_action("do_push","push");
}


int do_push(string arg){
		
	object me, pinggu, thief;
	
	me = this_player();
	if (arg == "武器架") {
		tell_object(me,"武器架晃了晃，又回到了原地。\n");
		return 1;
	}
	
	if (!arg || (arg!="木人" && arg!= "woodman")) {
		tell_object(me,"你想推什么？\n");
		return 1;
	}
	
	if (!query("thief")) {
		tell_object(me,"你推了推木人，结果什么也没有发生。\n");
		return 1;
	}
		
	tell_object(me,	"你伸手推了推那个奇怪的木人，木人似乎怕痒，哈哈地笑了起来，原来是个活人。\n");
	
	thief = new(__DIR__"npc/star_bunny");
	if (!thief)	return 1;
	thief->move(this_object());
	
	if (pinggu = present("tie pinggu")) {
		thief->ccommand("lovelook pinggu");
		pinggu->ccommand("kiss hu yaoshi");
	}
	
	set("thief",0);
	return 1;
}
	
	
void reset(){
	object sikong;
	
	sikong = present("hu yaoshi");
	if (sikong && !sikong->is_fighting()) {
		message_vision("胡药师说：哈哈，我们再来玩玩，说完又一动不动了。\n",sikong);
		destruct(sikong);			
	}
	set("thief",1);
	::reset();
}
	