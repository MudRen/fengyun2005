// corpse.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 

inherit ITEM;
#include <ansi.h>

void create() {
	set_name(WHT"干枯的尸体"NOR, ({ "evil" }) );
	set("long", "这是一具已经死了很久的尸体，快成骨架了。\n");
	set("unit", "具" );
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
	message_vision("骨架烟飞灰灭，化入尘土。\n", this_object());
	destruct(this_object());
}


object animate(object who, int level) {
	object zombie;
	int zskill;
	
	if(!environment()) {
		return 0;
	}
	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
	zombie->set_name("骷髅精", ({ "demon" }) );
	zombie->move(environment());
	zombie->set("long", "几根白森森的骨头上顶着个骷髅头，原来是眼珠的地方两个大窟窿。\n");
	zombie->animate(who, level);
	destruct(this_object());
	return zombie;
}
 
