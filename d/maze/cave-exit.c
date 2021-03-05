// silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "黑屋");
	set("long", @LONG
难以想象在这样一个地方居然还有一间小屋，与其说是屋子，倒不如说是石壁 
上一个天然凹进的地方，约有三丈见方。潮湿的地上尽是蠕动的鲜血，残缺的尸骨 
和不知名的草药，空气中弥漫着一种令人作呕的恶臭。屋子后方通向一个一丈见方
的池子，尽是绿色的液体，滚滚冒着血腥之气。 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"north" : __DIR__"cave-maze/exit",
		"south" : __DIR__"cave-end",

	]));
        set("item_desc", ([
        	"池子":	"远远望去，池子里尽是绿色的液体，滚滚冒着血腥之气。 \n",
        	"pond":	"远远望去，池子里尽是绿色的液体，滚滚冒着血腥之气。 \n",
		"south":"远远望去，池子里尽是绿色的液体，滚滚冒着血腥之气。 \n",
	]) );
	setup();
	
}


int	valid_leave(object who, string dir){
	object room, y1, y2, y3, y4;
	
	if (dir == "south") {
		if (REWARD_D->riddle_check(who,"智毁血池")!=2)
			return notify_fail(BLU"你只觉得阴风扑面，隐隐鬼哭之声，不由停住了脚步。\n"NOR);
		room = find_object(__DIR__"cave-end");
		if (room->usr_in()) 
			return notify_fail("洞穴狭小，似乎已经有人在里面了。\n");		
		message_vision(BLU"
突然，四周升起四股浓烟，幻化成四个狰狞的夜叉。 \n\n"
HIR"夜叉四大将一齐厉声喊道：大胆狂徒，私闯神洞，拿命来吧！ \n\n"NOR,who);
		room->reset();		
	}
		
	return 1;
}	