// corpse.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
//	10/24/2002 by silencer
//	---- removed wield(), equip() for corpse in both chard and here.

inherit ITEM;

int decayed;

void create() {
	set_name("无名尸体", ({ "corpse" }) );
	set("long", "这是一具无名尸体。\n");
	set("unit", "具" );
	set("no_reset",1); // Will destruct itself
	decayed = 0;
	if( clonep(this_object()) ) {
//		call_out("release_stuff",0); --- chard.c里本来就没必要给尸体穿戴。
		call_out("decay", 120, 1);
	}
}
int is_charater = 1;
int is_corpse() { return decayed < 2; }
int is_character() { return is_charater; }
int is_container() { return 1; }

string short() { 
	return name() + "(" + capitalize(query("id")) + ")"; 
}

void decay(int phase) {
	int time;
	decayed = phase;
	switch(phase) {
		case 1: 
			message_vision("$N开始腐烂了，发出一股难闻的恶臭。\n", this_object());
/*			switch(query("gender")) {
				case "男性": 
					set_name(name+"腐烂的男尸", ({ "corpse", "尸体" }) );
					break;	
				case "女性":
					set_name(name+"腐烂的女尸", ({ "corpse", "尸体" }) );
					break;				
				default:
					set_name(name+"腐烂的尸体", ({ "corpse", "尸体" }) );
					break;
			}*/
			
			set("long", "这具尸体显然已经躺在这里有一段时间了，正散发著一股腐尸的味道。\n");
			
			time = 600;
			
			if (environment())
			if (environment()->query("no_death_penalty"))
				time = 120;
					
			if (!query("player") && !query("boss"))
				call_out("decay", 120, phase + 1);
			else 
				call_out("decay", time, phase + 1);
			break;
		case 2:
			message_vision("$N被风吹乾了，变成一具骸骨。\n", this_object());
            set_name("枯乾的骸骨", ({ "skeleton", "骸骨" }));
			set("long", "这副骸骨已经躺在这里很久了。\n");
			is_charater = 0;
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			message_vision("一阵风吹过，把$N化成骨灰吹散了。\n", this_object());
			if(environment()) {
				object *inv;
				int i;
				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++) {
					if (!query("player")) destruct(inv[i]);
					else {
						if((int) inv[i]->query("no_get") 
								|| ((int) !inv[i]->value() && (int) !inv[i]->query("value"))) {
							inv[i]->move(VOID_OB);
							destruct(inv[i]);
						} else {
							inv[i]->move(environment());
						}
					}
				}
			}
			this_object()->move(VOID_OB);
			destruct(this_object());
			break;
	}
}

/*
void release_stuff(){
	int i;
	mixed *inv;
	object poorcorpse;
	
	poorcorpse = this_object();
	
	inv = all_inventory(poorcorpse);
	if(sizeof(inv)) {
		for(i=0; i<sizeof(inv); i++) {
			inv -= ({ 0 });
			if(sizeof(inv)) {
				if(inv[i]->query("equipped")) {
					inv[i]->unequip();
				}
			}
		}
	}
}*/

object animate(object who, int level) {
	object zombie;
	string name;
	int zskill;
	
	if(!environment()) {
		return 0;
	}
	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
	zombie->set_name( (string)query("victim_name") + "的僵尸", ({ "zombie" }) );
	zombie->move(environment());
	zombie->animate(who, level);
	destruct(this_object());
	return zombie;
}
 
