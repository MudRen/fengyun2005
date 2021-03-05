// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
		object weapon;
        set_name("五十六", ({ "fiftysix" }) );
        set("title",MAG"大盗"NOR);
        set("gender", "男性" );
		set("class","baiyun");

		set("age",57);
		set("no_arrest",1);
		set("no_fly",1);
		set("no_shot",1);
        set("long","这个人正阴阴地盯着你。\n");

        set("combat_exp", 2500000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: ccommand("perform tianwaifeixian") :),
             }) );

		set_skill("feixian-sword",140);
		set_skill("feixian-steps",140);

		set_skill("dodge",200);
		set_skill("sword",200);
		set_skill("force",200);
		set_skill("parry",150);
		set_skill("chessism",200);
		set_skill("perception",150);
		
		map_skill("parry","feixian-sword");
		map_skill("force","chessism");
		map_skill("dodge","feixian-steps");
		map_skill("sword","feixian-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("盗剑青芒", ({ "sword" }) );
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("无形黑衫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->set("no_get",1);
		weapon->wear();
}



void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( HIR"\n五十六冷笑道：想来和我抢东西？就凭你？\n\n"NOR);
	kill_ob(ob);
}

void die()
{
	object env,*inv,he,room,ob,killer;
	int i;
	env=environment();
	inv = all_inventory(env);
	he=this_object();

	ob = query_temp("last_damage_from");
	if (ob){
		if (ob->query("possessed"))
			killer = ob->query("possessed");
		else 
			killer = ob;
		if (killer) {
		if (killer ->query("annie/gstone") == 1)
			killer->set("annie/gstone",2);
		}
	}
	room=find_object("/d/cyan/bottom7");
	if (!room)
		room=load_object("/d/cyan/bottom7");
	
	message_vision("周围的黑暗渐渐消散……\n",he);
	for (i=0;i<sizeof(inv) ; i++)
		inv[i]->move(room);
	::die();
}



