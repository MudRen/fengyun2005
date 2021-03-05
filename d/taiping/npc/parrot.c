inherit NPC;
#include <ansi.h>

void create()
{
    set_name(HIR"血鹦鹉"NOR,({"bloody parrot","parrot"}));
//    set("title","斩草除根");
    set("long","血红色的鹦鹉！血红色的羽毛，血红色的嘴爪，眼睛竟也是血红的颜色。九万八千
六百八十七滴魔血，滴成了这一只血鹦鹉。烈火中乍现，血鹦鹉亦是一团烈火也似。\n");
    set("race","野兽");
    set("age",32);
    set("no_arrest",1);
    set("int",220);
    set("cor",300);
    set("per",100);
    set("cps",200);
    set("str",200);
    set("limbs", ({ "头部", "身体", "尾巴", "翅膀" }) );
    set("verbs", ({ "bite" }) );
    set("max_kee",100000);
    set("max_sen",100000);
    set("max_gin",100000);
    set("resistance/kee",100);
    set("resistance/gin",100);
    set("resistance/sen",100);
    set("combat_exp",99000000);  
    set("attitude", "friendly");
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     
        }) );
    set("chat_chance",1);
    set("chat_msg",({
	name()+"正在笑，就像人一样在笑。笑声中充满了一种说不出的邪恶妖异。\n",
    }) );
    setup();        
}


void init() {
	
	object ob;
	::init();
//	add_action("do_answer","answer");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
	tell_object(ob,HIR"血鹦鹉的嘴，仍然张开着，嘴里吐出了人声：“"+ob->name()+"！”\n"NOR);
	tell_object(ob,HIR"   血鹦鹉淡淡地道：“你的愿望是什么？”\n"NOR);
	tell_object(ob,WHT" force/spells/magic/parry/dodge/move/ + 10 level \n"NOR);
	return;
}