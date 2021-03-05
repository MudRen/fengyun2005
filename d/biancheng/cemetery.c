#include <ansi.h>
inherit ROOM;

void init(){
	add_action("do_leave","kneel");
}


int do_leave(string arg)
{
	object room, me;
	me = this_player();
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你现在正忙着呢。\n");
		
	room=find_object(__DIR__"cemetery0");
	if(!room) room=load_object(__DIR__"cemetery0");
	
	message_vision("$N绝望地跪在地上大叫：救苦救难观世音菩萨，我迷路了，救我出去吧！\n", me);
	message_vision(WHT"\n坟地里忽然起了一阵怪风，把$N卷了起来。\n"NOR,me);
	
	tell_object(room,me->name()+"扑通一声从半空中掉了下来，一脸茫然的样子。\n");
	me->move(room);
	return 1;
}


int valid_leave(object obj, string dir){
	object another;
	int num;
	
	seteuid(getuid());
	
	if (!present("zombie", this_object()) && random(10)>7) {
		switch (obj->query("quest/quest")) {
			case "老僵尸":	another = new(__DIR__"npc/zombie4");
							break;
			
			case "高僵尸":	another = new(__DIR__"npc/zombie3");
							break;
			
			case "瘦僵尸":	another = new(__DIR__"npc/zombie2");
							break;
			
			case "小僵尸":	another = new(__DIR__"npc/zombie1");
							break;
		}	
		
		if (!objectp(another)) {
			sscanf(file_name(this_object()),__DIR__"cemetery%d",num);
			switch (num) {
				case 1:
				case 2:
				case 3:
				case 4:	 another = new(__DIR__"npc/zombie1");
						 break;
				case 5:
				case 6:
				case 7:
				case 8:  another = new(__DIR__"npc/zombie2");
						 break;
				case 9:
				case 10:
				case 11:
				case 12: another = new(__DIR__"npc/zombie3");
						 break;
				default: another = new(__DIR__"npc/zombie4");
						 break;
			}
		}		
		another->move(environment(obj));
		message_vision(YEL"坟堆里慢慢站起一个人形向你扑来!\n"NOR, obj);	
		return notify_fail(another->name()+"张牙舞爪地挡在了你的面前。\n");
	}	
	return 1;
}