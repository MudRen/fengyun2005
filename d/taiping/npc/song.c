#include <ansi.h>
inherit SMART_NPC;

int curse_me();

void create()
{
    	set_name("宋妈妈",({"mother song","song","mother"}));
    	set("title","老巫婆");
    	set("long","
嫣红的衣裳红如血。她虽然穿着得很年轻，无论怎样看来，她也只像个老太婆。她
面上的皱纹也实在够多，够深。灯光斜斜地照在她的面上，每一条皱纹都带着暗影，
就好像刀子一样。她那一头的头发却仍乌黑发亮，蚯蚓也似的依旧披散。\n");
    	set("gender","女性");
    	set("age",72);
    	set("no_arrest",1);
		
		set("combat_exp",2700000);
		set("attitude","friendly");
	
		set("reward_npc",3);
	
		set("death_msg",HIR"\n$N尖声叫道：“你也活不成了，走出门就死！！！” \n"NOR);
		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     		50: 	(: curse_me() :),
        ]) );    
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"宋妈妈嗝嗝嚅着道：“我这里没有什么值得参观的。”\n",	
		}) );
       	
       	auto_npc_setup("wang",200,150,0,"/obj/weapon/","fighter_w","nine-moon-claw",1);
		setup();
		carry_object(__DIR__"obj/witchcloth")->wear();
    	carry_object(AREA_TAIPING"obj/blackpie");
}


int curse_me() {
	object ob, *enemy;
	ob=this_object();
	enemy=query_enemy();
	switch (random(3)) {
		case 0: message_vision(HIG"\n$N忽然在黑盘上抓起了一块魔药，张口吞了下去。\n"NOR,ob);
			break;
		case 1: message_vision(HIW"\n$N脸都白了，嘶声狂呼道：“天咒你，咒你下地狱，上。。上刀山。。”\n"NOR,ob);
			break;
		case 2: message_vision(HIR"\n$N嘴里喃喃地不断诅咒——“这个人的嘴巴，一定会被割掉，这个人的双手，
一定会被斩下，这个人的心肝，一定会被挖出来喂狗。。”\n"NOR,ob);
			break;
	}	
	foreach (object x in enemy){
		tell_object(x,YEL"听着宋妈妈的诅咒，你觉得头痛的像要裂开来一样。。。。。\n"NOR);
		x->receive_wound("gin",200,ob);
	}
	return 1;
}