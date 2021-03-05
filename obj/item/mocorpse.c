// corpse.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

inherit ITEM;
#include <ansi.h>

void create() {
	set_name(HIB"恶魔"NOR, ({ "evil" }) );
	set("long", "这是一团人形的黑烟。\n");
	set("unit", "团" );
	set("no_reset",1); // Will destruct itself
	if( clonep(this_object()) ) {
		call_out("decay", 240, 1);
	}
}

int is_charater = 1;
int is_corpse() { return 1; }
int is_character() { return is_charater; }

string short() { 
	return name() + "(" + capitalize(query("id")) + ")"; 
}

void decay(int phase) {
	message_vision(HIB"黑烟无声无息地聚成一团潜入地下。\n"NOR, this_object());
	destruct(this_object());
}


object animate(object who, int level) {
	object zombie;
	string *names = ({ HIW"魑"NOR, HIW"魅"NOR, HIW"魍"NOR,HIW"魉"NOR, });
	int zskill;
	
	if(!environment()) {
		return 0;
	}
	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
	zombie->set_name(names[random(3)], ({ "demon" }) );
	zombie->move(environment());
	zombie->set("advanced_zombie",1);
	zombie->set("long",
                
"邪恶的化身，青面獠牙，还长着一只犄角。\n");
	zombie->animate(who, level);
	destruct(this_object());
	return zombie;
}
 
