// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("骷髅土卒", ({ "skeletal fodder","fodder" }) );
        set("gender", "男性" );
		set("class","huashan");

		set("age",335);

        set("long","一具看起来十分骇人的骨骼。\n");

        set("combat_exp", 3000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
             }) );

		auto_npc_setup("waiter",200,200,0,"/obj/weapon/","fighter_w","xuezhan-spear",1);
		setup();

        weapon=carry_object("/obj/weapon/spear");
        weapon->set_name("霉木矛", ({ "spear" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("几块布片", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();
}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
	


		write("一具看起来十分骇人的骨骼。
它看起来约三百三十多岁。
它浑身上下所剩的仅仅是骨骼而已。
它身穿几块布片(Cloth)
  右手提着霉木矛(Spear)"NOR"\n");
		return 1;
	}
	return 0;
}