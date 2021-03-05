// magic_armor.c	的特性示范 --- by Silencer
/* 
1. Defense: damage absoprtion -- combatd.c
2. Weight: affect dodge. -- need adjust equip.c
3. 15% phy dmg reduce (armor class only) -- need change damage.c
   15% jin dmg reduce (armor class only) 
   15% shen dmg reduce (armor class only) 
4. +enable dodge/parry.... 
5. add 150-300 hp (available for all classes) 
   add 100-300 jin (available for all classes) 
   add 100-300 shen (available for all classes) 
	--- that's hard to implement due to current query(kee), condition, ?what about let armor cast a spell? check with potion/buffup
6. 150-200 dmg transfer to hp, --- possible, need change combatd.c
7. add 5%-15% of overall attack rating (weapon,charm class) 
   add 5%-15% of overall defense (armor,charm class) 
   --- no need charm class, just ring/shoes etc enough.
12. npc drop物品的机率x2 (charm class) --- using apply/.... using luck to check drop ?

*/

#include <armor.h>
#include <ansi.h>

inherit CLOTH;



void create() {
	set_name("魔术盔甲", ({ "armor", "magic armor" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "leather");
		set("value", 10);
		set("armor_prop/armor", 10);
		set("long",(: MAGIC_D->look_armor(this_object()) :));
		set("spell/kee_resist",10);
		set("spell/kee_buffup",2000);
		set("spell/gin_buffup",3000);
		set("spell/kee_shield",1000);
		set("spell/gin_heal",2000);
		set("apply/parry",10);
		set("apply/dodge",17);
		
	}
	::init_cloth();
}

void init()
{
	if(environment()==this_player())
		add_action("do_empower", "empower");
}


int do_empower(string arg) {
	if (MAGIC_D->spell_effect(this_object(), arg))	return 1;
	return 0;
}



